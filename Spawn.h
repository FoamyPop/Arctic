#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "IMAGE.h"

class Spawn
{
public:
	Spawn(int x, int y);
	~Spawn(void);
	IMAGE* src;
	sf::Vector2f getPosition();
	void Update(sf::RenderWindow &window);
	int rectNum;
	sf::IntRect subRect;
	sf::IntRect rects[10];
	sf::Clock* clock;
};

