#include "Hacker.h"

//Getters
float& Hacker::getSalud()
{
	return _salud;
}

int Hacker::getTipoAtaque()
{
	return _tipoAtaque;
}

float Hacker::getCantidadDanio()
{
	return _cantidadDanio;
}

sf::Vector2f Hacker::getVelocidadMovimiento()
{
	return _velocidadMovimiento;
}

bool Hacker::getBoss()
{
	return _isABoss;
}

sf::FloatRect Hacker::getBounds() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite Hacker::getSprite()
{
	return _sprite;
}

float Hacker::getDropOro()
{
	return _dropOro;
}

//SETTERS
void Hacker::setSalud(float salud)
{
	_salud = salud;
}

void Hacker::setTipoAtaque(int tipo)
{
	_tipoAtaque = tipo;
}

void Hacker::setCantidadDanio(float danio)
{
	_cantidadDanio = danio;
}

void Hacker::setVelocidadMovimiento(sf::Vector2f velocidad)
{
	_velocidadMovimiento = velocidad;
}

void Hacker::setBoos(bool boss = false)
{
	_isABoss = boss;
}

void Hacker::setDrop(float drop)
{
	_dropOro = drop;
}

void Hacker::atacar(float* objetivo)
{
	*objetivo -= getCantidadDanio();

}

//Comportamiento

void Hacker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/*
		Este transform, ahora hay que ponerlo siempre, porque sino todo lo que hagas 
		no se va a aplicar al draw. Es tan necesario como target.draw
	*/
	states.transform *= getTransform();
	target.draw(_sprite, states);
}

void Hacker::update()
{
	move(getVelocidadMovimiento());
	/*
	//Limite izquierdo
	if (getPosition().x < 0)
		setPosition({ -getPosition().x,getPosition().y });
	//Limite superior
	if (getPosition().y < 0)
		setPosition({ getPosition().x,-getPosition().y });
	//Limite derecho
	if (getPosition().x + getBounds().width > 800)
		setPosition({-getPosition().x, getPosition().y});
	//Limite inferior
	if (getPosition().y + getBounds().height > 600)
		setPosition({ getPosition().x, -getPosition().y });

	*/

	//Limite izquierdo y derecho
	if (getPosition().x < 0 || getPosition().x + getBounds().width > 800)
	{
		// Invertir la velocidad horizontal
		setVelocidadMovimiento(sf::Vector2f(-getVelocidadMovimiento().x, getVelocidadMovimiento().y));
	}

	//Limite superior e inferior
	if (getPosition().y < 0 || getPosition().y + getBounds().height > 600)
	{
		// Invertir la velocidad vertical
		setVelocidadMovimiento(sf::Vector2f(getVelocidadMovimiento().x, -getVelocidadMovimiento().y));
	}
}