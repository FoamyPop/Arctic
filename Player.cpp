#include "Player.h"

Player::Player(Spawn& spawn)
{
	src = new IMAGE("Files\\Player.png", spawn.getPosition().x, spawn.getPosition().y);
	prevPos = src->GetPosition();
}

bool Player::contains(Ice& ice)
{
	if(ice.src->x == src->x &&
	   ice.src->y == src->y)
	   return true;
	else
		return false;
}

bool Player::containsGoal(Goal& goal)
{
	if(goal.src->x == src->x &&
	   goal.src->y == src->y)
	   return true;
	else
		return false;
}

void Player::Update(sf::RenderWindow &window, std::vector<Ice*>& ice)
{
	if(prevPos != src->GetPosition())
	{
		for(int i = 0; i < ice.size(); i++)
		{
			if(contains(*ice[i]))
			{
				if(ice[i]->state == Ice::IceState::Reg || ice[i]->state == Ice::IceState::Cracked)
				{
						prevPos = src->GetPosition();
						ice[i]->ChangeState();
				}
				else if(ice[i]->state == Ice::IceState::Reg)
				{				
					src->x = prevPos.x;
					src->y = prevPos.y;
				}
			}
		}
	}
	src->draw(window);
}

void Player::MoveUp(std::vector<Ice*>& ice)
{
	prevPos = src->GetPosition();
	src->SetPosition(src->x, src->y - 50);
	for(int i = 0; i < ice.size(); i++)
	{
		if(ice[i]->state == Ice::IceState::Rock)
		{
			if(contains(*ice[i]))
			{
				src->SetPosition(prevPos.x, prevPos.y);
			}
		}
	}
}

void Player::MoveLeft(std::vector<Ice*>& ice)
{
	prevPos = src->GetPosition();
	src->SetPosition(src->x - 50, src->y);
	for(int i = 0; i < ice.size(); i++)
	{
		if(ice[i]->state == Ice::IceState::Rock)
		{
			if(contains(*ice[i]))
			{
				src->SetPosition(prevPos.x, prevPos.y);
			}
		}
	}
}

void Player::MoveDown(std::vector<Ice*>& ice)
{
	prevPos = src->GetPosition();
	src->SetPosition(src->x, src->y + 50);
	for(int i = 0; i < ice.size(); i++)
	{
		if(ice[i]->state == Ice::IceState::Rock)
		{
			if(contains(*ice[i]))
			{
				src->SetPosition(prevPos.x, prevPos.y);
			}
		}
	}
}

void Player::MoveRight(std::vector<Ice*>& ice)
{
	prevPos = src->GetPosition();
	src->SetPosition(src->x + 50, src->y);
	for(int i = 0; i < ice.size(); i++)
	{
		if(ice[i]->state == Ice::IceState::Rock)
		{
			if(contains(*ice[i]))
			{
				src->SetPosition(prevPos.x, prevPos.y);
			}
		}
	}
}