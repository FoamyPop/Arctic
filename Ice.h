#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "IMAGE.h"

class Ice
{
public:
	Ice(int x, int y, int State);
	~Ice(void);
	void Update(sf::RenderWindow &window);
	void ChangeState();
	IMAGE* src;
	sf::IntRect subRect;
	int X;
	enum IceState
	{
		Reg, Cracked, Broken, Rock
	};
	IceState state;
};

