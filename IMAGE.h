#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "RECTANGLE.h"

class IMAGE
{
public:
	IMAGE(std::string filename, float X, float Y);
	~IMAGE(void);
	void SetPosition(float X, float Y);
	sf::Vector2f GetPosition();
	void draw(sf::RenderWindow& window);
	void setScale(float scale);
	void setSubRect(sf::IntRect &rect);
	float x, y, w, h;
private:
	sf::Image image;
	sf::Sprite sprite;
	RECTANGLE* rect;	
};

