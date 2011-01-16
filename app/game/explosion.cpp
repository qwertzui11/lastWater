#include "explosion.hpp"
#include "useful.hpp"
#include "sounds.hpp"

explosion::explosion(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw)
    : m_sprite(*img)
    , m_rw(rw)
    , m_lifeTime(0.f)
    , m_pos(pos)
    , m_sndExplosion(*sounds::g_explosion)
{
    m_sprite.SetPosition(pos);
    m_explosion = sf::IntRect(0,0,35,50);
    m_sprite.SetSubRect(m_explosion);

    m_sndExplosion.SetVolume(0.5f);
    m_sndExplosion.Play();
}

void explosion::update(float time)
{
    m_lifeTime+=time;
    if(m_lifeTime>0.15)
    {
        m_explosion = sf::IntRect(0,0,35,50);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>0.3)
    {
        m_explosion = sf::IntRect(35,0,71,50);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>0.45)
    {
        m_explosion = sf::IntRect(71,0,106,50);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>0.6)
    {
        m_explosion = sf::IntRect(106,0,142,50);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>0.75)
    {
        m_explosion = sf::IntRect(142,0,177,50);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>0.9)
    {
        m_explosion = sf::IntRect(177,0,213,50);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.05)
    {
        m_explosion = sf::IntRect(0,50,35,100);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.2)
    {
        m_explosion = sf::IntRect(35,50,71,100);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.35)
    {
        m_explosion = sf::IntRect(71,50,106,100);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.5)
    {
        m_explosion = sf::IntRect(106,50,142,100);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.65)
    {
        m_explosion = sf::IntRect(142,50,177,100);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.8)
    {
        m_explosion = sf::IntRect(177,50,213,100);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>1.95)
    {
        m_explosion = sf::IntRect(0,100,35,150);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>2.1)
    {
        m_explosion = sf::IntRect(35,100,71,150);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>2.25)
    {
        m_explosion = sf::IntRect(71,100,106,150);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>2.4)
    {
        m_explosion = sf::IntRect(106,100,142,150);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>2.55)
    {
        m_explosion = sf::IntRect(142,100,177,150);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>2.7)
    {
        m_explosion = sf::IntRect(177,100,213,150);
        m_sprite.SetSubRect(m_explosion);
    }
    if(m_lifeTime>2.85)
    {
       m_lifeTime = 0.f;
    }
    m_lifeTime += time;
}

void explosion::render()
{
    m_sprite.SetPosition(m_pos);
    m_rw->Draw(m_sprite);
}

sf::Vector2f explosion::pos()
{
    return m_sprite.GetPosition();
}

float explosion::lifeTime()
{
    return m_lifeTime;
}



