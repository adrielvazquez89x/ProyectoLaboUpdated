#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Proyectil : public sf::Drawable, public sf::Transformable, public Colisionable
{

protected:
	sf::Sprite _sprite;
	static sf::Texture _texture;
	sf::Vector2f _velocidad;
	sf::Vector2f _objetivo;

	float _danio;
	

public:

	Proyectil(sf::Vector2f posicionInicial = { 100,100 }, sf::Vector2f target = {300,300}, float danio = 10);

	sf::Sprite getSprite();
	sf::FloatRect getBounds() const override;

	void moverse(sf::Vector2f, sf::Vector2f);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

