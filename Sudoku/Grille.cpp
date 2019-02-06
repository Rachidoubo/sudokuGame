/*
*	Created on Thu Mar 24 19:22:01 2016
*	@author: OUBOUHOU Rachid
*/


#include "Grille.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>

#pragma Variable_glo
int numberOfrect, dimX, dimY, index;
char valeur;
bool repeatedNumber ;
bool incrimenter ;
bool goTo = false;
int compteur = 0;
int valueOf();
std::vector <char> tab_dyannmique;
#pragma Variable_glo

 

std::string str;
Grille::Grille()
{
	srand((unsigned)time(NULL));
	if(!m_font.loadFromFile("COUR.ttf"))
		std::cout<<">>> There are an error during loading the file \"COUT.TTF\""<<std::endl;
	if(!m_texture.loadFromFile("tile/GR.png"))
		std::cout<<">>> There are an error during loading the file \"grille.png"<<std::endl;
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	/// rect
	m_rect.setSize(sf::Vector2f (38, 38));
	m_rect.setFillColor(sf::Color::Color(255,0,0,100));
	m_rect.setPosition(0, 0);
	// initialisation des nombres aleatoire
	
	for(int i = 0; i<9; i++){
		for (int j=0; j<9; j++){
			m_tab[i][j]='0';
		}
	}
			}
		
void Grille::initialiser ()
{
	
	numberOfrect = dimX = dimY = index = 0;
	
	while (numberOfrect <=10 ){
	     numberOfrect = rand() % 30;
     }
	// m_toDraw =20, numberOfrect = 30;
	 std::cout<< "##"<<numberOfrect<<std::endl;
 while ( compteur <= numberOfrect && index < numberOfrect){
	 dimX = rand() % 9;
	 dimY = rand() % 9;
     
	//					   // les comparison dans les rigions 3*3
     if(dimX<3){
		 if (dimY < 3 ) {
		   for (int k = 0; k<3;k++) {
			   for (int l = 0; l<3;l++) {
				   tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
		   }
		        }
	         
		  if ( dimY >=3 && dimY < 6 ){
			  for (int k = 0; k<3;k++) {
			   for (int l = 3; l<6;l++) {
				     tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
				  
		         }
	           }
		  if (dimY >= 6 && dimY < 9  ) {
			   for (int k = 0; k<3;k++) {
			      for (int l = 6; l<9;l++) {
				      tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		      valeur = valeur_exact(tab_dyannmique);
		      for (int i = 0 ; i<tab_dyannmique.size();i++){
			      tab_dyannmique.pop_back();
		      }
	      }
	 }
	 if(dimX >= 3 && dimX < 6 ) {
	   if (dimY < 3 ) {
		   for (int k = 3; k<6;k++) {
			   for (int l = 0; l<3;l++) {
				   tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
	        }
	   }
	 

		 if ( dimY >=3 && dimY < 6 ){
			  for (int k = 3; k<6;k++) {
			   for (int l = 3; l<6;l++) {
				      tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
	       }
		 }

		  if (dimY >= 6 && dimY < 9 ) {
			   for (int k = 3; k<6;k++) {
			    for (int l = 6; l<9;l++) {
				    tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
           }
	     }
	 }
	  if ( dimX >= 6 && dimX < 9){
		 if (dimY < 3 ) {
		   for (int k = 6; k<9;k++) {
			   for (int l = 0; l<3;l++) {
				     tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
	         }
		 }
	  
		  if ( dimY >=3 && dimY < 6 ){
			  for (int k = 6; k<9;k++) {
			   for (int l = 3; l<6;l++) {
				     tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
	           }
		  }
		   if (dimY >= 6 && dimY < 9 ) {
			   for (int k = 6; k<9;k++) {
			     for (int l = 6; l<9;l++) {
				      tab_dyannmique.push_back(m_tab[k][l]);
				      }
			       }
		   valeur = valeur_exact(tab_dyannmique);
		   for (int i = 0 ; i<tab_dyannmique.size();i++){
			   tab_dyannmique.pop_back();
		   }
	  }
	 }
	
	//if ( repeatedNumber == false && incrimenter == true ){
		if(m_tab[dimX][dimY] == '0' ){
            m_tab[dimX][dimY] = valeur;
            m_rectBack[index].setFillColor(sf::Color (0,0,0,100));
		    m_rectBack[index].setSize(sf::Vector2f(38, 38));
    	    m_rectBack[index].setPosition(dimX*38, dimY*38);
		    m_textArray[dimX][dimY].setString(m_tab[dimX][dimY]);
		    m_textArray[dimX][dimY].setCharacterSize(20);
		    m_textArray[dimX][dimY].setColor(sf::Color::White);
		    m_textArray[dimX][dimY].setPosition(m_rectBack[index].getPosition().x+10, m_rectBack[index].getPosition().y+5);
	        m_textArray[dimX][dimY].setFont(m_font);
		    m_textArray[dimX][dimY].setStyle(sf::Text::Bold);
			std::cout<< "#> "<<index+1<< " m_tab["<<dimX<<"]"<<"["<<dimY<<"]"<<"->"<<valeur<<std::endl;
		    compteur ++;
			index++;
	
		}
	}
}

void Grille::moving()
{
	/*les bordures*/
	if(m_rect.getPosition().x<=0 )
		m_rect.setPosition(0,m_rect.getPosition().y);
    if(m_rect.getPosition().x+m_rect.getSize().x >=m_texture.getSize().x)
		m_rect.setPosition(m_texture.getSize().x-m_rect.getSize().x,m_rect.getPosition().y);
	if(m_rect.getPosition().y<=0)
		m_rect.setPosition(m_rect.getPosition().x,0);
	if(m_rect.getPosition().y+m_rect.getSize().y>=m_texture.getSize().y)
		m_rect.setPosition(m_rect.getPosition().x, (m_texture.getSize().y-m_rect.getSize().y));

		/* controlle du mvt du rectangle */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_rect.setPosition(m_rect.getPosition().x+m_rect.getSize().x,m_rect.getPosition().y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_rect.setPosition(m_rect.getPosition().x-m_rect.getSize().x,m_rect.getPosition().y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_rect.setPosition(m_rect.getPosition().x,m_rect.getPosition().y-m_rect.getSize().y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_rect.setPosition(m_rect.getPosition().x,m_rect.getPosition().y+m_rect.getSize().y);

}

bool Grille::write () const {
	for (int i=0;i<numberOfrect; i++){
		if (m_rect.getPosition().x == m_rectBack[i].getPosition().x && m_rect.getPosition().y == m_rectBack[i].getPosition().y){
			return false;
	   }
	}
 return true;
}
void Grille::getIntredNumber (sf::Event & event)
{ 
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)){
				int i = m_rect.getPosition().x / 38;
				int j = m_rect.getPosition().y / 38;
				if (write() == true){
				m_textArray[i][j].setString(' ');
				m_tab[i][j] = '0';
				}
			}
	if (event.type == sf::Event::TextEntered ){
		   
			if(event.text.unicode >= 49 && event.text.unicode <= 57){
			    int i = m_rect.getPosition().x / 38;
				int j = m_rect.getPosition().y / 38;
				
				if (write() == true){
						   m_tab[i][j] = (char)event.text.unicode;
						   m_textArray[i][j].setString(m_tab[i][j]);
						   m_textArray[i][j].setCharacterSize(20);
						   m_textArray[i][j].setColor(sf::Color::Black);
						   }
						   for (int k=0; k<9; k++){                    // les comparaison 
							   if (m_tab[i][j] == m_tab [i][k] && k!=j ){
								   m_textArray[i][j].setColor(sf::Color::Red);
								   break;
							   }
							   if (m_tab[i][j] == m_tab[k][j] && k!=i ){
								    m_textArray[i][j].setColor(sf::Color::Red);
									break;
							   }
						   }
						   // les comparison dans les rigions 3*3
					if (i<3 ){ 
						 if (j < 3){
							  for (int k=0; k<3; k++){ 
								  for (int l=0; l<3; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								    }
							     }
							 }

						 if ( j >= 3 && j < 6 ){
							  for (int k=0; k<3; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								    }
							     }
						  }
						 if ( j >= 6 && j < 9 ){
							  for (int k=0; k<3; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								    }
							     }
						  }

						}
					if (i>=3 && i<6 ){
						if ( j < 3 ){
							   for (int k=3; k<6; k++){ 
								  for (int l=0; l<3; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								  }
							   }
						  }

						if (j >= 3 && j < 6){
							for (int k=3; k<6; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								  }
							}
						}

						if (j >= 6 && j < 9){
							for (int k=3; k<6; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								  }
							}
						}
					}

					if (i >= 6 && i < 9){
						if (j < 3){
							for (int k=6; k<9; k++){ 
								  for (int l=0; l<3; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								  }
							}
						}

						if ( j >= 3 && j < 6){
							for (int k=6; k<9; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }
								  }
							}
						}

						if (j >= 6 && j < 9){
							for (int k=6; k<9; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && l!=i && k != j ){
										  m_textArray[i][j].setColor(sf::Color::Red);
										  break;
									  }

								  }
							}
						}
					}
						   m_textArray[i][j].setPosition(m_rect.getPosition().x+10,m_rect.getPosition().y+5);
						   m_textArray[i][j].setFont(m_font);
						   m_textArray[i][j].setStyle(sf::Text::Bold);
						  // std::cout<<(char)event.text.unicode<<std::endl;
						   str = m_textArray[i][j].getString();
						   std::cout<<"["<<i<<"]"<<"["<<j<<"]: "<<str<<std::endl;
					  }
				}
		    }
	     
char Grille::valeur_exact(std::vector <char> tab){
	int valeur;
	bool test_valeur=false;
	do {
		valeur = valueOf();
	for (int i=0; i < tab.size(); i++){
		if ((char)valeur == tab[i] || (((char)valeur == m_tab [dimX][i] && i!=dimY ) || ( (char)valeur == m_tab[i][dimY] && i!=dimX) )){
			test_valeur = false ;
			break ;
		}
		else {
			test_valeur = true;
		}
	}
}while (test_valeur != true);
	return (char)valeur;
}
int valueOf() {
  int value;
  do {
      value = rand() % 58;
  }while (value < 49 || value > 57 );
  return  value;
}
 bool Grille::test () {
	 repeatedNumber = false;
   for (int i=0; i<9; i++){
	 for (int j=0; j<9; j++){
		for (int k=0; k<9; k++){                    // les comparaison 
			if (m_tab[i][j] == m_tab [i][k] && m_tab[i][j] != '0' && k!=j )
				return true;
			if (m_tab[i][j] == m_tab[k][j] && m_tab[i][j] != '0' && k!=i)
			    return true;
			}
						   // les comparison dans les rigions 3*3
						  if (i<3 && j < 3 ){  
							  for (int k=0; k<3; k++){ 
								  for (int l=0; l<3; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && m_tab[i][j] != '0' && l!=i )
										 return true;
								  }
							  }
						  }
						  if (i>=3 && i<6 && j < 3){
							   for (int k=0; k<3; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && m_tab[i][j] != '0' && l!=i )
										  return true;
								  }
							   }
						  }
						  if (i>=6 && j < 3){
							   for (int k=0; k<3; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [l][k] && m_tab[i][j] != '0' && l!=i )
										  return true;
								  }
							   }
						  }
						  // pour l'axe Y
						 
						  if (i < 3 && j>=3 && j<6 ){
							   for (int k=0; k<3; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [k][l] && m_tab[i][j] != '0' && l!=j )
										   return true;
								  }
							   }
						  }
						  if (i>=3 && i < 6 && j >= 3 && j < 6 ){ 
							   for (int k=3; k<6; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [k][l] && m_tab[i][j] != '0' && l!=j && k == i)
										  return true;
								  }
							   }
						  }
						  if (i>=6 && j>=3 && j <6 ){ 
							   for (int k=6; k<9; k++){ 
								  for (int l=3; l<6; l++){ 
									  if (m_tab[i][j] == m_tab [k][l] && m_tab[i][j] != '0' && l!=j && k == i )
										  return true;
								  }
							   }
						  }
						  if (i< 3 && j>=6){ /// dimX < 3 && dimY > 6
							   for (int k=0; k<3; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [k][l] && m_tab[i][j] != '0' && l!=j && k == i )
										  return true;
								  }
							   }
						  }
						  if (i>=3 && i<6 && j >= 6){ // dimX >= 3 && dimX < 6 ) && dimY >= 6
							   for (int k=3; k<6; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [k][l] && m_tab[i][j] != '0' && l!=j && k == i )
										  return true;
								  }
							   }
						  }
						  if (i>=6 && j>=6){ // dimX >= 6 && dimY >= 6
							   for (int k=6; k<9; k++){ 
								  for (int l=6; l<9; l++){ 
									  if (m_tab[i][j] == m_tab [k][l] && m_tab[i][j] != '0'  && l!=j && k == i ){
										 return true;
									  }

								  }
							   }
						  }
	}
   }
   return repeatedNumber ;
  }
sf::Text Grille::getText(int i, int j)
{ 
	return m_textArray[i][j];
}


sf::Sprite Grille::getSprite()
{
	return m_sprite;
}
sf::RectangleShape Grille::getRect()
{
   return m_rect;
}
int Grille::getIndexToDraw()
{
	return m_toDraw; 
}
sf::RectangleShape Grille::getRectBack(int i)
{
	return m_rectBack[i];
}