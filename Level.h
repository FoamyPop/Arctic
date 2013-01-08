#pragma once
#include "SDL.h"
#include <vector>

#include <SFML/Window.hpp>

#include "Ice.h"
#include "Spawn.h"
#include "Goal.h"
#include "Player.h"

using std::vector;

class Level
{
public:
	Level(void);
	~Level(void);
	void push(Ice* i);
	void Update(sf::RenderWindow &window, std::vector<Ice*> ice);
	void setSpawn(int x, int y);
	void setExit(int x, int y);
	Spawn* returnSpawn();
	vector<Ice*> ice;
private:	
	Spawn* spawn;
	Goal* goal;
	Player* player;
	bool spawnSet;
	bool exitSet;
};
