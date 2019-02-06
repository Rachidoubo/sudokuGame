/*
*	Created on Thu Mar 24 19:21:45 2016
*	@author: OUBOUHOU Rachid
*/



#ifndef DEF_GRILLE
#define DEF_GRILLE
#include <SFML\Graphics.hpp>
class Grille
{
public:
	Grille();
	sf::Sprite getSprite();
	sf::RectangleShape getRect();
	int getIndexToDraw();
	sf::RectangleShape getRectBack(int index);
	void getIntredNumber(sf::Event & event );
	sf::Text getText(int i, int j);
	void moving();
	void initialiser();
	bool test();
	char valeur_exact(std::vector <char> tab);
	bool write() const;
	
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::RectangleShape m_rect;
	sf::RectangleShape m_rectBack[30];
	char m_tab[9][9];
	sf::Text m_textArray [9][9];
	sf::Font m_font;
	int m_toDraw;
	
	


};

#endif