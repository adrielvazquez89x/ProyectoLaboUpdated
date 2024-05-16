#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Proyectil : public sf::Drawable, public sf::Transformable, public Colisionable
{
public:
	enum class Direction
	{
		Left = 0,
		Right = 1,
		Up = 2,
		Down = 3
	};

protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocidad;
	sf::Vector2f _objetivo;

	float _danio;
	Direction _direction;

public:

	Proyectil(sf::Vector2f, Direction, float);

	sf::Sprite getSprite();
	sf::FloatRect getBounds() const override;
	void moverse(sf::Vector2f, sf::Vector2f);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

