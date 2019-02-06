/*
*	Created on Thu Mar 24 18:36:33 2016
*	@author: OUBOUHOU Rachid
*/



#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Grille.h"
#include "C_Bouton.h"
using namespace std;
int main ()
{
	//srand(time(0));
	bool gameBegin = false ;
	sf::RenderWindow window (sf::VideoMode(342,342), "SUDOKU v1.1",sf::Style::Close);
	window.setFramerateLimit(10);
	window.setKeyRepeatEnabled(false);
	Bouton start("tile/start1.png",sf::Vector2f (100,200));
	Bouton aboutGame("tile/aboutGame.png",sf::Vector2f (98,250));

	sf::Sprite backGround;
	sf::Texture backGroundTexture;
	if (!backGroundTexture.loadFromFile("tile/startBackground.png"))
		cout<<"failed to load the background image"<<endl;
	backGround.setTexture(backGroundTexture);
	
	Grille sudoku;
	sudoku.initialiser();
	while (window.isOpen())
	{
		sf::Event event ;
		if (window.pollEvent(event))
		  {
			if (event.type == sf::Event::Closed)
				window.close();
		  }
		if (gameBegin == false ){
			if(start.enCollision(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				gameBegin = true;
			}
			if(aboutGame.enCollision(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				cout<<"==============================================================="<<endl;
				cout<<"                     SUDOKU GAME v1.1                          "<<endl;
				cout<<"               written with C++ and SFML 2.1                   "<<endl;
				cout<<"                Coded by : RACHID OUBOUHOU                     "<<endl;
				cout<<"==============================================================="<<endl;

			}
			window.draw(backGround);
			window.draw(start.getSprite());
			window.draw(aboutGame.getSprite());
			window.display();
			window.clear();
	
	}
		if (gameBegin == true){
		sudoku.moving();
		sudoku.getIntredNumber(event);
		if(sudoku.test() != false)
			cout<<"il ya une repitition d'un nombre dans la grille"<<endl;
		window.draw(sudoku.getSprite());
		window.draw(sudoku.getRect());
		for (int i=0; i<=30; i++){
			window.draw(sudoku.getRectBack(i));
		}
		for (int i=0; i<9; i++){
			for (int j= 0; j < 9; j++)
			{
				window.draw(sudoku.getText(i,j));
			}
		}
		
		window.display();
		window.clear();
	}
	}
	return 0;
}