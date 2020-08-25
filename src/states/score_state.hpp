#pragma once

#include "state.hpp"
#include "../container.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <list>


class ScoreState : public State
{
	public:
		ScoreState(StateStack& stack, Context context);

		virtual void			Draw();
		virtual bool			Update(sf::Time dt);
		virtual bool			HandleEvent(const sf::Event& event);


	private:
		sf::Sprite		    backgroundSprite_;
		GUI::Container      GUIContainer_;
        std::list<sf::Text> textList_;
		//sf::Font			font_;
};