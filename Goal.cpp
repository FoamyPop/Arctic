#include "Goal.h"

Goal::Goal(int x, int y)
{
	clock = new sf::Clock();
	src = new IMAGE("Files\\GoalAnim.png", x * 50, y * 50);
	rectNum = 0;
	for(int i = 0; i < 10; i++)
	{
		rects[i].Left = i * 50;
		rects[i].Top = 0;
		rects[i].Right = rects[i].Left + 50;
		rects[i].Bottom = 50;
	}
	subRect = rects[rectNum];
}

void Goal::Update(sf::RenderWindow &window)
{
	if(clock->GetElapsedTime() > 0.05f)
	{
		clock->Reset();
		rectNum++;

		if(rectNum > 9)
			rectNum = 0;		

		subRect = rects[rectNum];
	}	
	
	src->setSubRect(subRect);
	src->draw(window);
}

sf::Vector2f Goal::getPosition()
{
	return sf::Vector2f(src->x, src->h);
}

Goal::~Goal(void)
{

}
