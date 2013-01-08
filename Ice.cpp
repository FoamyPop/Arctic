#include "Ice.h"

Ice::Ice(int x, int y, int State)
{
	src = new IMAGE("Files\\Ice.png", x * 50, y * 50);

	switch(State)
	{
	case 0:
		X = 0;
		state = Reg;
		break;
	case 1:
		state = Cracked;
		X = 50;
		break;
	case 2:
		state = Broken;
		X = 100;
		break;
	case 3:
		state = Rock;
		X = 150;
		break;
	default:
		state = Reg;
		X = 0;
	}

	//sf::IntRect(left, top, right, bottom);
	subRect.Left = X;
	subRect.Right = X + 50;
	subRect.Top = 0;
	subRect.Bottom = 50;
	src->setSubRect(subRect);
}

void Ice::ChangeState()
{
	if(state == Reg)
		state = Cracked;
	else if(state == Cracked)
		state = Broken;
}

void Ice::Update(sf::RenderWindow &window)
{
		 if(state == Reg)
		X = 0;
	else if(state == Cracked)
		X = 50;
	else if(state == Broken)
		X = 100;
	else if(state == Rock)
		X = 150;
	
	subRect.Left = X;
	subRect.Right = X + 50;
	subRect.Top = 0;
	subRect.Bottom = 50;

	src->setSubRect(subRect);
	src->draw(window);
}

Ice::~Ice(void)
{

}
