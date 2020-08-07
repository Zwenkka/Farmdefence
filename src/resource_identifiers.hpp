#pragma once
#include "resource_holder.hpp"

namespace sf {
    class Texture;
    class Font;
}


namespace Textures {
    enum ID {
        Fire,
        Leaf,
        Water,
        IceBullet,
        FireBullet,
        WoodBullet,
        Grass,
        FireTower,
        WaterTower,
        LeafTower,
        Path,
        TitleScreen,
        TitleBackground,
        logo,
        ButtonNormal,
        ButtonSelected,
        ButtonPressed,
        PlankNormal,
        PlankSelected,
        PlankPressed,
        PlankNormal2,
        PlankSelected2,
    };
}

namespace Fonts {
	enum ID {
		Main,
        Title
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;