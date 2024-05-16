#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Colisionable.h"

class Hacker : public sf::Drawable, public sf::Transformable, public Colisionable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _nombre;

	int _seniority;
	int _tipoAtaque;
	float _salud;
	float _cantidadDanio;
	float _velocidadMovimiento;
	float _dropOro;
	bool _isABoss;

	//DESARROOLLO
	sf::Vector2f _posicion;

public:

	//DESARROLLO
	void moverse();
	sf::Sprite getSprite();

	//Getters
	int getTipoAtaque();
	float getCantidadDanio();
	float getVelocidadMovimiento();
	float getDropOro();
	float& getSalud();
	bool getBoss();

	sf::FloatRect getBounds() const override;

	//Setters
	void setSalud(float);
	void setTipoAtaque(int);
	void setCantidadDanio(float);
	void setVelocidadMovimiento(float);
	void setBoos(bool);
	void setDrop(float);

	//Comportamiento
	void update();
	void atacar(float*);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



};

