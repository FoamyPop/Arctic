#include "Level.h"

using std::vector;


Level::Level()
{

}

void Level::push(Ice* i)
{
	ice.push_back(i);
}

void Level::setSpawn(int x, int y)
{
	spawn = new Spawn(x, y);
}

void Level::setExit(int x, int y)
{
	goal = new Goal(x, y);
}

Level::~Level(void)
{
	
}

Spawn* Level::returnSpawn()
{
	return spawn;
}

void Level::Update(sf::RenderWindow &window, std::vector<Ice*> ice)
{
	for(int i = 0; i < ice.size(); i++)
	{
		ice[i]->Update(window);
	}
	goal->Update(window);
	spawn->Update(window);
	player->Update(window, ice);
}