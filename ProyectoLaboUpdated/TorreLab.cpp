#include "TorreLab.h"

TorreLab::TorreLab()
{
	//Carga de textura desde archivo local
	_texture.loadFromFile("torrecita.png");
	//Seteamos textura al sprite
	_sprite.setTexture(_texture);
	// Nombre, por si hay que mostrarlo.
	_nombre = "torrecita";
	//Seteamos el eje para que sea el centro del sprite.
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);

	setPosition(400, 300);
	
	//Rango de ataque:
	//Seteo del radio del rango.
	_rango.setRadius(150);
	//Seteo del color del rango.
	_rango.setFillColor(sf::Color(0, 255, 0, 120));
	//Setamos el eje para que sea el centro del circulo.
	_rango.setOrigin(_rango.getLocalBounds().width / 2, _rango.getLocalBounds().height / 2);


	//Propiedades.
	_costo = 10;
	_costoUpgrade = 9;
	_valorVenta = 5;

	_danioCausante = 10;
	_alcance = 9;
	_velocidadAtaque = 3;
	_tipoAtaque = 1;
	_cantidadUpgrades = 2;
	_cooldown = 0;

}

void TorreLab::actualizarLabo2()
{
	_costoUpgrade = 9;
	_valorVenta = 7;
	_danioCausante = 12;
	_velocidadAtaque = 2;
	_cantidadUpgrades = 1;

}
