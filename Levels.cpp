#include "Levels.h"

Levels::Levels(void)
{

}

void Levels::draw(int LEVEL_NUMBER, sf::RenderWindow& window)
{
	const int LEVEL_NUM = LEVEL_NUMBER -= 1;
	levels[LEVEL_NUM]->Update(window, levels[LEVEL_NUM]->ice);
}

void Levels::setLevels()
{
	Level* LEVEL_ONE = new Level();
	LEVEL_ONE->setSpawn(2, 2);
	LEVEL_ONE->setExit(9, 9);
	for(int i = 1; i < 11; i++)
	{
		LEVEL_ONE->push(new Ice(4, i, 1));
	}
	for(int i = 1; i < 11; i++)
	{
		LEVEL_ONE->push(new Ice(4, i, 10));
	}
	for(int i = 2; i < 10; i++)
	{
		LEVEL_ONE->push(new Ice(4, 1, i));	
	}
	for(int i = 2; i < 10; i++)
	{
		LEVEL_ONE->push(new Ice(4, 10, i));	
	}
	for(int i = 3; i < 10; i++)
	{
		LEVEL_ONE->push(new Ice(1, i, 2));	
	}
	for(int i = 2; i < 9; i++)
	{
		LEVEL_ONE->push(new Ice(1, i, 9));	
	}
	for(int i = 2; i < 10; i++)
	{
		for(int j = 3; j < 9; j++)
		{
			LEVEL_ONE->push(new Ice(1, i, j));
		}
	}
	levels.push_back(LEVEL_ONE);
}

Levels::~Levels(void)
{

}
