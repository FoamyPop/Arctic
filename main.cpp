////////////////////////////////////////////////////////////////
//															  //
//	OneGameAMonth (OGAM) - Month 1 ( January 1st, 2013 )	  //
//	Titter: @PotatoSoftware									  //
//	Tumblr: PotatoSoftware http://potatosoftware.tumblr.com/  //
//	Reddit: FoamyPop http://reddit.com/user/foamypop		  //
//															  //
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "IMAGE.h"
#include "RECTANGLE.h"
#include "BUTTON.h"
#include "STRING.h"
#include "Player.h"
#include "Spawn.h"
#include "Goal.h"
#include "Levels.h"
#include "Ice.h"

////////////////////////////////////////////////
// Extras
////////////////////////////////////////////////

enum GameState
{
	Menu,
	Options,
	Ingame,
	Paused
};
GameState state;
GameState prevState;

std::vector<Ice*> ice;
int currentLevel = 1;

////////////////////////////////////////////////
// Entry Point
////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	sf::RenderWindow WINDOW(sf::VideoMode(1280, 720, 32), "Arctic", sf::Style::Close);
	WINDOW.SetFramerateLimit(60);

	Levels* levels;
	levels->setLevels();
	sf::Clock clock;
	float time = clock.GetElapsedTime();
	state = Ingame;
	prevState = Menu;

	/* Main Menu Buttons */
	BUTTON play(440, 200, "PLAY");
	BUTTON options(440, 320, "OPTIONS");
	BUTTON quit(440, 440, "QUIT");

	/* Pause Buttons */
	BUTTON resume(440, 200, "RESUME");
	BUTTON pauseOptions(440, 320, "OPTIONS");
	BUTTON quitToMenu(440, 440, "QUIT TO MENU");	

	/* Strings */
	STRING str("Arctic - Sprite Testing", 5, 2, sf::Color(255, 255, 255));

	while(WINDOW.IsOpened())
	{
		sf::Event event;
		sf::Vector2i mouse(WINDOW.GetInput().GetMouseX(), WINDOW.GetInput().GetMouseY());
		time = clock.GetElapsedTime();

		while(WINDOW.GetEvent(event))
		{
			switch(event.Type)
			{
			case sf::Event::Closed:
				WINDOW.Close();
				break;
			case sf::Event::KeyPressed:
				if(event.Key.Code == sf::Key::Escape)
				{
					if(state == Menu)
					{					
						WINDOW.Close();		
					}
					else if(state == Ingame)
					{
						state = Paused;
						prevState = Ingame;
					}
					else if(state == Options)
					{
						state = prevState;
						prevState = Options;
					}
					else if(state == Paused)
					{
						state = prevState;
						prevState = Paused;
					}
				}
				if(event.Key.Code == sf::Key::Space)
				{
					for(int i = 0; i < ice.size(); i++)
					{
						if(ice[i]->state != Ice::IceState::Rock)
						{
							ice[i]->state = Ice::IceState::Reg;
						}
					}
				}
				break;
				case sf::Event::MouseButtonReleased:
				if(event.MouseButton.Button == sf::Mouse::Button::Left)
				{
					if(state == Menu)
					{
						if(play.contains(mouse))
						{
							state = Ingame;
						}
						else if(options.contains(mouse))
						{
							state = Options;
							prevState = Menu;
						}
						else if(quit.contains(mouse))
						{
							WINDOW.Close();
						}
					}
					else if(state == Paused)
					{
						if(resume.contains(mouse))
						{
							state = Ingame;
						}
						else if(pauseOptions.contains(mouse))
						{
							state = Options;
							prevState = Paused;
						}
						else if(quitToMenu.contains(mouse))
						{
							state = Menu;
							prevState = Paused;
						}
					}
				}
				break;
			}
		}
		WINDOW.Clear(sf::Color(80, 80, 80, 0));
		/* DRAWING CODE */
		if(state == Ingame)
		{
			/* Tiles */
			levels->draw(currentLevel, WINDOW);			

			/* HUD Elements */
			str.Draw(WINDOW);
		}
		else if(state == Menu)
		{
			play.Draw(WINDOW);
			options.Draw(WINDOW);
			quit.Draw(WINDOW);
			play.Update(mouse);
			options.Update(mouse);
			quit.Update(mouse);
		}
		else if(state == Options)
		{

		}
		else if(state == Paused)
		{
			resume.Draw(WINDOW);
			pauseOptions.Draw(WINDOW);
			quitToMenu.Draw(WINDOW);
			resume.Update(mouse);
			pauseOptions.Update(mouse);
			quitToMenu.Update(mouse);
		}

		/* END OF DRAWING */
		WINDOW.Display();
	}
	return EXIT_SUCCESS;
}