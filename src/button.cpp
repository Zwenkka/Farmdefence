#include "button.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cmath>
#include <iostream>


namespace GUI
{

Button::Button(const FontHolder& fonts, const TextureHolder& textures):
  callback_()
, texture_(textures.Get(Textures::Buttons))
, normalTextureRect_(sf::IntRect(0,286,200,88))
, selectedTextureRect_(sf::IntRect(0,462,200,88))
, pressedTextureRect_(sf::IntRect(0,462,200,88))
, sprite_()
, text_("", fonts.Get(Fonts::ID::Main), 16)
, isToggle_(false)
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(normalTextureRect_);
	sf::FloatRect bounds = sprite_.getLocalBounds();
	text_.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

Button::Button(const FontHolder& fonts, const TextureHolder& textures, sf::IntRect normalTextureRect, sf::IntRect selectedTextureRect) :
  callback_()
, texture_(textures.Get(Textures::Buttons))
, normalTextureRect_(normalTextureRect)
, selectedTextureRect_(selectedTextureRect)
, pressedTextureRect_(selectedTextureRect)
, sprite_()
, text_("", fonts.Get(Fonts::ID::Main), 16)
, isToggle_(false)
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(normalTextureRect_);
	sf::FloatRect bounds = sprite_.getLocalBounds();
	text_.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void Button::Update(sf::Time)
{
	// Do nothing
}


void Button::SetCallback(Callback callback)
{
	callback_ = std::move(callback);
}

void Button::SetText(const std::string& text)
{
	text_.setString(text);
	sf::FloatRect bounds = text_.getLocalBounds();
	text_.setOrigin(::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void Button::SetToggle(bool flag)
{
	isToggle_ = flag;
}

sf::FloatRect Button::GetGlobalBounds() const{
	return GetWorldTransform().transformRect(sprite_.getGlobalBounds());
}

bool Button::IsSelectable() const
{
    return true;
}

void Button::Select()
{
	Component::Select();

	sprite_.setTextureRect(selectedTextureRect_);
	//sprite_.setTexture(selectedTexture_);
}

void Button::Deselect()
{
	Component::Deselect();

	sprite_.setTextureRect(normalTextureRect_);
}

void Button::Activate()
{
	Component::Activate();

    // If we are toggle then we should show that the button is pressed and thus "toggled".
	if (isToggle_)
		sprite_.setTextureRect(pressedTextureRect_);

	if (callback_)
		callback_();

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
	if (!isToggle_)
		Deactivate();
}

void Button::Deactivate()
{
	Component::Deactivate();

	if (isToggle_)
	{
        // Reset texture to right one depending on if we are selected or not.
		if (IsSelected())
			sprite_.setTextureRect(selectedTextureRect_);
		else
			sprite_.setTextureRect(normalTextureRect_);
	}
}

bool Button::HandleEvent(const sf::Event& event)
{
	if(event.type == sf::Event::MouseButtonPressed)
	{
		//std::cout << "Jiihaa" << std::endl;
		clickPosition_ = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
	}
	return false; // Don't propagate events
}

void Button::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
	target.draw(text_, states);
	//DrawBoundingRect(target, states);
}

}