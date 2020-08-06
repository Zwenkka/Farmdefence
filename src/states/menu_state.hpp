#include "state.hpp"
#include "../container.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
	public:
		MenuState(StateStack& stack, Context context);

		virtual void			Draw();
		virtual bool			Update(sf::Time dt);
		virtual bool			HandleEvent(const sf::Event& event);


	private:
		sf::Sprite		backgroundSprite_,logoSprite_;
		GUI::Container  GUIContainer_;
};
