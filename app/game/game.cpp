#include "game.hpp"
#include "guiSinglePlayerSettings.hpp"

#include <iostream>

game::game(int numComputer, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_world(m_rw)
    , m_nextAsteroid(0.f)
    , m_numPlayer(numComputer+1)
    , m_worldSize((1000.f / sin(((2.f*3.1415926535897932384626433f) / (((float)numComputer+1.f)))/2.f))*2.f+800.f)
    , m_afterSingle(m_worldSize, m_rw)
{
    m_afterSingle.setListener(this);

    m_world.initialise(m_worldSize);

    if (!m_imgCollector.LoadFromFile("../data/img/1p_collector.tga"))
    {
        std::cout << "m_imgShip.LoadFromFile";
    }
    if (!m_imgAttacker.LoadFromFile("../data/img/1p_fighter.tga"))
    {
        std::cout << "m_imgShip.LoadFromFile";
    }
    if (!m_imgBullet.LoadFromFile("../data/img/shot.tga"))
    {
        std::cout << "m_imgShip.LoadFromFile";
    }
    if (!m_imgAsteroid.LoadFromFile("../data/img/asteroid.tga"))
    {
        std::cout << "m_imgAsteroid.LoadFromFile";
    }
    if (!m_img1p.LoadFromFile("../data/img/1p_planet.tga"))
    {
        std::cout << "m_img1p.LoadFromFile";
    }
    if (!m_imgWater.LoadFromFile("../data/img/water.tga"))
    {
        std::cout << "m_imgWater.LoadFromFile";
    }
    if (!m_font.LoadFromFile("../data/font/pirulen.ttf", 30))
    {
         std::cout << "m_font.LoadFromFile";
    }
    if (!m_imgBubble.LoadFromFile("../data/img/bubble.tga"))
    {
        std::cout << "m_imgBubble.LoadFromFile";
    }
    if (!m_explosion.LoadFromFile("../data/img/explosion.tga"))
    {
        std::cout << "m_explosion.LoadFromFile";
    }

    float radius = (m_worldSize-800.f)/2.f;

    m_planetWater = new planet(&m_imgWater, &m_img1p, &m_font, m_rw, sf::Vector2f(400.f+radius, 400.f+radius), sf::Color(230,185,117), 1000, -1);

    sf::Color cols[] = {
        sf::Color::Blue,
        sf::Color::Cyan,
        sf::Color::Green,
        sf::Color::Magenta,
        sf::Color::Red,
        sf::Color::White,
        sf::Color::Yellow,
        sf::Color::Black
    };

    for (int ind = 0; ind < numComputer+1; ++ind)
    {
        float degree = ((float)ind)*((2.f*3.15159f)/((float)numComputer+1.f))+1.f;
        sf::Vector2f pos(cos(degree), sin(degree));
        pos*=radius;
        pos+=sf::Vector2f(400.f+radius, 400.f+radius);
        if (ind == numComputer)
        {
            m_player = new human(m_worldSize, pos, &m_imgWater, &m_img1p, &m_font, &m_imgCollector, &m_imgAttacker, &m_imgBullet, 0, &m_imgBubble, m_rw, cols[ind],&m_explosion);
            break;
        }
        computer *newComp = new computer(pos, &m_imgWater, &m_img1p, &m_font, &m_imgCollector, &m_imgAttacker, &m_imgBullet, 0, &m_imgBubble, m_rw, cols[ind],&m_explosion);
        m_computers.push_back(newComp);
    }

    m_viewPos = m_player->getPlanet()->pos();
}

game::~game()
{
    clear();
}

void game::clear()
{
    delete m_player;
    delete m_planetWater;
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        delete (*it);
    }
    m_computers.clear();
    for (std::vector<asteroid *>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        delete (*it);
    }
    asteroid::g_asteroids.clear();
    for (std::vector<bubble *>::iterator it = bubble::g_bubbles.begin(); it < bubble::g_bubbles.end(); ++it)
    {
        delete (*it);
    }
    bubble::g_bubbles.clear();
}

bool game::event(sf::Event *event)
{
    if (event->Type == sf::Event::KeyReleased)
    {
        if (event->Key.Code == 256)
        {
            resetCamera();
            m_afterSingle.activate(!m_afterSingle.active());
        }
    }
    if (m_afterSingle.active())
        m_afterSingle.event(event);
    else
    {
        bool proccedEvent = m_player->event(event);
        if (proccedEvent)
        {
            if (event->Type == sf::Event::MouseWheelMoved)
            {
                if (event->MouseWheel.Delta < 0)
                    zoom (m_rw->GetFrameTime());
                else
                    zoom (-m_rw->GetFrameTime());
            }
        }
    }
    return true;
}

void game::update(float timeLastFrame)
{
    if (m_afterSingle.active())
    {
        m_afterSingle.update(timeLastFrame);
        return;
    }
    updateScroll(timeLastFrame);
    m_player->update(timeLastFrame);
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        (*it)->update(timeLastFrame);
    }

    m_nextAsteroid+=timeLastFrame;
    if (m_nextAsteroid > 1.f/((float)m_numPlayer))
    {
        m_nextAsteroid = 0.f;
        new asteroid(m_worldSize, &m_imgAsteroid, m_rw);
    }

    m_planetWater->update(timeLastFrame);
    m_world.update(timeLastFrame);

    for (std::vector<asteroid *>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        (*it)->update(timeLastFrame);
        sf::Vector2f pos = (*it)->pos();
        if (pos.x > m_worldSize || pos.y > m_worldSize || pos.x + m_imgAsteroid.GetWidth() < 0.f || pos.y + m_imgAsteroid.GetHeight() < 0.f)
        {
            delete (*it);
            break;
        }
        bool cancel(false);
        for (std::vector<planet *>::iterator it2 = planet::g_planets.begin(); it2 < planet::g_planets.end(); ++it2)
        {
            if (length(pos - (*it2)->pos()) < planet::size())
            {
                (*it2)->addIron(5);
                delete (*it);
                cancel = true;
                break;
            }
        }
        if (cancel)
            break;
    }
    for (std::vector<bubble *>::iterator it = bubble::g_bubbles.begin(); it < bubble::g_bubbles.end(); ++it)
    {
        (*it)->update(timeLastFrame);
    }
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        if ((*it)->getPlanet()->water() == 1000)
        {
            resetCamera();
            m_afterSingle.setStatus(guiAfterSinglePlayer::lost);
            m_afterSingle.activate(true);
        }
    }
    if (m_player->getPlanet()->water() == 1000)
    {
        resetCamera();
        m_afterSingle.setStatus(guiAfterSinglePlayer::won);
        m_afterSingle.activate(true);
    }
}

void game::render()
{
    m_world.render(m_worldSize);
    for (std::vector<asteroid *>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        (*it)->render();
    }
    for (std::vector<bubble *>::iterator it = bubble::g_bubbles.begin(); it < bubble::g_bubbles.end(); ++it)
    {
        (*it)->render();
    }
    m_planetWater->render();
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        (*it)->render();
    }
    m_player->render();

    m_afterSingle.render();
}

void game::updateScroll(float time)
{
    if (m_rw->GetInput().GetMouseX() < 20 || m_rw->GetInput().IsKeyDown(sf::Key::Left))
    {
        m_viewPos.x-=g_scrollSpeed*time;
    }
    if (m_rw->GetInput().GetMouseX() > (signed)m_rw->GetWidth()-20 || m_rw->GetInput().IsKeyDown(sf::Key::Right))
    {
        m_viewPos.x+=g_scrollSpeed*time;
    }
    if (m_rw->GetInput().GetMouseY() < 20 || m_rw->GetInput().IsKeyDown(sf::Key::Up))
    {
        m_viewPos.y-=g_scrollSpeed*time;
    }
    if (m_rw->GetInput().GetMouseY() > (signed)m_rw->GetHeight()-10 || m_rw->GetInput().IsKeyDown(sf::Key::Down))
    {
        m_viewPos.y+=g_scrollSpeed*time;
    }
    if (m_viewPos.x - m_rw->GetDefaultView().GetHalfSize().x < 0)
        m_viewPos.x = m_rw->GetDefaultView().GetHalfSize().x;
    if (m_viewPos.y - m_rw->GetDefaultView().GetHalfSize().y < 0)
        m_viewPos.y = m_rw->GetDefaultView().GetHalfSize().y;

    if (m_viewPos.x + m_rw->GetDefaultView().GetHalfSize().x > m_worldSize)
        m_viewPos.x = m_worldSize-m_rw->GetDefaultView().GetHalfSize().x;
    if (m_viewPos.y + m_rw->GetDefaultView().GetHalfSize().y > m_worldSize)
        m_viewPos.y = m_worldSize-m_rw->GetDefaultView().GetHalfSize().y;
    m_rw->GetDefaultView().SetCenter(m_viewPos);
    zoom(0.f);
}

void game::zoom(float time)
{
    sf::View * view = &m_rw->GetDefaultView();
    sf::FloatRect rect = view->GetRect();
    float aspect = ((float)m_rw->GetHeight())/((float)m_rw->GetWidth());
    float width = rect.Right - rect.Left;
    float height = rect.Bottom - rect.Top;
    width*=1.f+time*g_zoomSpeed;
    if (width>m_worldSize)
        width=m_worldSize;
    if (width<400.f)
        width=400.f;
    height=width*aspect;
    rect.Right=rect.Left+width;
    rect.Bottom=rect.Top+height;
    view->SetFromRect(rect);
    /*view->Zoom(1.f + time*g_zoomSpeed);
    if (view->GetHalfSize().x*2.f > m_rw->GetWidth())*/
}


void game::resetCamera()
{
    sf::View * view = &m_rw->GetDefaultView();
    sf::FloatRect rect = view->GetRect();
    float width = m_rw->GetWidth();
    float height = m_rw->GetHeight();

    rect.Left = m_worldSize/2.f - width/2.f;
    rect.Top = m_worldSize/2.f - height/2.f;
    rect.Right=rect.Left+width;
    rect.Bottom=rect.Top+height;
    view->SetFromRect(rect);
}

void game::done (state *from, state *next)
{
    (void)from;
    (void)next;
    if (m_afterSingle.exit())
    {
        state::done(new guiSinglePlayerSettings(m_rw));
        return;
    }
    if (m_afterSingle.restart())
    {
        clear();
        state::done(new game(m_numPlayer-1, m_rw));
        return;
    }
}
