/*
*	Created on Thu Mar 24 20:23:55 2016
*	@author: OUBOUHOU Rachid
*/


#include "C_Bouton.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>

Bouton::Bouton (std::string filePath,sf::Vector2f position)
{
	if(!m_texture.loadFromFile(filePath))
		std::cout<<"erreur pendant le chargement du "<<"'"<<filePath<<"'"<<std::endl;
	else
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(position);
	}
}
sf::Sprite Bouton::getSprite () const
{
	return m_sprite;
}
bool Bouton::enCollision(sf::RenderWindow &window)
{
	if(sf::Mouse::getPosition(window).x >= m_sprite.getPosition().x && sf::Mouse::getPosition(window).x <= m_sprite.getPosition().x +(m_texture.getSize().x/2)
		&& sf::Mouse::getPosition(window).y >=m_sprite.getPosition().y && sf::Mouse::getPosition(window).y <= m_sprite.getPosition().y +m_texture.getSize().y )
	{
		m_sprite.setTextureRect(sf::IntRect (m_texture.getSize().x/2, 0, m_texture.getSize().x, m_texture.getSize().y));
		return true;
	}
	else
	{
		m_sprite.setTextureRect(sf::IntRect (0, 0, m_texture.getSize().x/2, m_texture.getSize().y));
	}
}