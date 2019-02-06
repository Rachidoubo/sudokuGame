/*
*	Created on Thu Mar 24 20:23:56 2016
*	@author: OUBOUHOU Rachid
*/



#ifndef  DEF_C_BOUTON 
#define DEF_C_BOUTON 
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
class Bouton
{
  public :
	  Bouton (std::string filepath, sf::Vector2f position);
	  sf::Sprite getSprite () const;
	  bool enCollision (sf::RenderWindow & window);	
  private:
	  sf::Texture m_texture;
	  sf::Sprite m_sprite;


};

#endif 
