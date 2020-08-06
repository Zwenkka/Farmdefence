#include "sprite_node.hpp"

SpriteNode::SpriteNode(const sf::Texture& texture)
        : sprite_(texture) { }

SpriteNode::SpriteNode(const sf::Texture& texture, sf::IntRect &textureRect)
                : sprite_(texture, textureRect) { }

void SpriteNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite_, states);
}


sf::FloatRect SpriteNode::GetBounds() const {
    return sprite_.getGlobalBounds();
}