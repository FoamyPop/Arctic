#pragma once

#include <SFML/Window.hpp>
#include "Ice.h"
#include "Spawn.h"
#include "Goal.h"
#include "Level.h"
#include <vector>

using std::vector;

class Levels
{
public:
	Levels(void);
	~Levels(void);
	void draw(int LEVEL_NUMBER, sf::RenderWindow& window);
	void setLevels();
	vector<Level*> levels;	
};

