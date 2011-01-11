#include "bullet.hpp"
#include "useful.hpp"

bullet::bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : m_sprite(*img)
    , m_rw(rw)
    , m_lifeTime(0.f)
{
    m_sprite.SetPosition(pos);
    m_sprite.SetColor(col);
    m_dir = normalize(dir);
    float rot = acos(m_dir.x);
    if (-m_dir.y < 0.0)
    {
        rot = 2.f*3.1415926f - rot;
    }
    float res = (rot/(2.f*3.1415926f))*360.f+90.f;

    m_sprite.SetRotation(res);
}

void bullet::update(float time)
{
    m_lifeTime += time;
    m_sprite.Move(m_dir.x*500.f*time, m_dir.y*500.f*time);
}

void bullet::render()
{
    m_rw->Draw(m_sprite);
}

sf::Vector2f bullet::pos()
{
    return m_sprite.GetPosition();
}

float bullet::lifeTime()
{
    return m_lifeTime;
}


