#include "game.hpp"
#include <iostream>

game::game()
    : m_window(sf::VideoMode(1920, 1020, 32), "lastWater")
    , m_world(&m_window)
    , m_nextAsteroid(0.f)
{
}

game::~game()
{
}


void game::initialise()
{
    m_world.initialise();

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

    m_player = new human(sf::Vector2f(400.f, 400.f), &m_imgWater, &m_img1p, &m_font, &m_imgCollector, &m_imgAttacker, &m_imgBullet, 0, &m_imgBubble, &m_window, sf::Color::Blue);
    m_planetWater = new planet(&m_imgWater, &m_img1p, &m_font, &m_window, sf::Vector2f(1000.f, 1000.f), sf::Color(230,185,117), 1000, -1);

    computer *newComp = new computer(sf::Vector2f(1610.f, 410.f), &m_imgWater, &m_img1p, &m_font, &m_imgCollector, &m_imgAttacker, &m_imgBullet, 0, &m_imgBubble, &m_window, sf::Color::Cyan);
    m_computers.push_back(newComp);
    newComp = new computer(sf::Vector2f(410.f, 1600.f), &m_imgWater, &m_img1p, &m_font, &m_imgCollector, &m_imgAttacker, &m_imgBullet, 0, &m_imgBubble, &m_window, sf::Color::Red);
    m_computers.push_back(newComp);
    newComp = new computer(sf::Vector2f(1610.f, 1610.f), &m_imgWater, &m_img1p, &m_font, &m_imgCollector, &m_imgAttacker, &m_imgBullet, 0, &m_imgBubble, &m_window, sf::Color::Green);
    m_computers.push_back(newComp);
}

int game::run()
{
    while (m_window.IsOpened())
    {
        sf::Event Event;
        while (m_window.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                m_window.Close();
            if (Event.Type == sf::Event::MouseWheelMoved)
            {
                if (Event.MouseWheel.Delta < 0)
                    zoom (m_window.GetFrameTime());
                else
                    zoom (-m_window.GetFrameTime());
            }
            if (Event.Type == sf::Event::Resized)
                m_window.GetDefaultView().SetHalfSize((float)Event.Size.Width, (float)Event.Size.Height);
            m_player->event(&Event);
        }
        m_window.Clear();
        float frameTime = m_window.GetFrameTime();
        if (frameTime > 1.f/60.f)
            frameTime = 1.f/60.f;
        update(frameTime);
        render();
        m_window.Display();
    }
    return EXIT_SUCCESS;
}

void game::update(float timeLastFrame)
{
    updateScroll(timeLastFrame);
    m_player->update(timeLastFrame);
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        (*it)->update(timeLastFrame);
    }

    m_nextAsteroid+=timeLastFrame;
    if (m_nextAsteroid > 0.25f)
    {
        m_nextAsteroid = 0.f;
        new asteroid(&m_imgAsteroid, &m_window);
    }

    m_planetWater->update(timeLastFrame);
    m_world.update(timeLastFrame);

    for (std::vector<asteroid *>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        (*it)->update(timeLastFrame);
        sf::Vector2f pos = (*it)->pos();
        if (pos.x > 2000.f || pos.y > 2000.f || pos.x + m_imgAsteroid.GetWidth() < 0.f || pos.y + m_imgAsteroid.GetHeight() < 0.f)
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
}

void game::render()
{
    m_world.render();
    for (std::vector<asteroid *>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        (*it)->render();
    }
    m_planetWater->render();
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        (*it)->render();
    }
    for (std::vector<bubble *>::iterator it = bubble::g_bubbles.begin(); it < bubble::g_bubbles.end(); ++it)
    {
        (*it)->render();
    }
    m_player->render();
}

void game::updateScroll(float time)
{
    if (m_window.GetInput().GetMouseX() < 20 || m_window.GetInput().IsKeyDown(sf::Key::Left))
    {
        m_viewPos.x-=g_scrollSpeed*time;
    }
    if (m_window.GetInput().GetMouseX() > m_window.GetWidth()-20 || m_window.GetInput().IsKeyDown(sf::Key::Right))
    {
        m_viewPos.x+=g_scrollSpeed*time;
    }
    if (m_window.GetInput().GetMouseY() < 20 || m_window.GetInput().IsKeyDown(sf::Key::Up))
    {
        m_viewPos.y-=g_scrollSpeed*time;
    }
    if (m_window.GetInput().GetMouseY() > m_window.GetHeight()-10 || m_window.GetInput().IsKeyDown(sf::Key::Down))
    {
        m_viewPos.y+=g_scrollSpeed*time;
    }
    if (m_viewPos.x - m_window.GetDefaultView().GetHalfSize().x < 0)
        m_viewPos.x = m_window.GetDefaultView().GetHalfSize().x;
    if (m_viewPos.y - m_window.GetDefaultView().GetHalfSize().y < 0)
        m_viewPos.y = m_window.GetDefaultView().GetHalfSize().y;

    if (m_viewPos.x + m_window.GetDefaultView().GetHalfSize().x > 2000)
        m_viewPos.x = 2000-m_window.GetDefaultView().GetHalfSize().x;
    if (m_viewPos.y + m_window.GetDefaultView().GetHalfSize().y > 2000)
        m_viewPos.y = 2000-m_window.GetDefaultView().GetHalfSize().y;
    m_window.GetDefaultView().SetCenter(m_viewPos);
    zoom(0.f);
}

void game::zoom(float time)
{
    sf::View * view = &m_window.GetDefaultView();
    sf::FloatRect rect = view->GetRect();
    float aspect = ((float)m_window.GetHeight())/((float)m_window.GetWidth());
    float width = rect.Right - rect.Left;
    float height = rect.Bottom - rect.Top;
    width*=1.f+time*g_zoomSpeed;
    if (width>2000.f)
        width=2000.f;
    if (width<400.f)
        width=400.f;
    height=width*aspect;
    rect.Right=rect.Left+width;
    rect.Bottom=rect.Top+height;
    view->SetFromRect(rect);
    /*view->Zoom(1.f + time*g_zoomSpeed);
    if (view->GetHalfSize().x*2.f > m_window.GetWidth())*/
}


