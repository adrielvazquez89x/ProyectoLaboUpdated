#include "HackerTrainee.h"

HackerTrainee::HackerTrainee()
{
	_texture.loadFromFile("kaker.png");
	_sprite.setTexture(_texture);
	_nombre = "Kakercito";
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);

	setPosition(sf::Vector2f(200,200));

	_seniority = 0;
	_salud = 100;
	_tipoAtaque = 0;
	_cantidadDanio = 1;
	_velocidadMovimiento = { 2,2 };
	_dropOro = 10;

}
