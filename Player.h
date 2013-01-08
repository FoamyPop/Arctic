#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "IMAGE.h"
#include "RECTANGLE.h"

#include "Spawn.h"
#include "Goal.h"
#include "Ice.h"
#include <vector>

class Player
{
public:
	Player(Spawn& spawn);
	~Player(void);
	IMAGE* src;
	sf::Vector2f prevPos;
	void Update(sf::RenderWindow &window, std::vector<Ice*>& ice);
	bool contains(Ice& ice);
	bool containsGoal(Goal& goal);
	void MoveUp(std::vector<Ice*>& ice);
	void MoveDown(std::vector<Ice*>& ice);
	void MoveLeft(std::vector<Ice*>& ice);
	void MoveRight(std::vector<Ice*>& ice);
	float speed;
};

