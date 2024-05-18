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
	sf::Vector2f _velocidadMovimiento;

	int _seniority;
	int _tipoAtaque;
	float _salud;
	float _cantidadDanio;
	float _dropOro;
	bool _isABoss;


public:

	//Getters
	int getTipoAtaque();
	float getCantidadDanio();
	sf::Vector2f getVelocidadMovimiento();
	float getDropOro();
	float& getSalud();
	bool getBoss();

	sf::FloatRect getBounds() const override;
	sf::Sprite getSprite();

	//Setters
	void setSalud(float);
	void setTipoAtaque(int);
	void setCantidadDanio(float);
	void setVelocidadMovimiento(sf::Vector2f);
	void setBoos(bool);
	void setDrop(float);

	//Comportamiento
	void update();
	void atacar(float*);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



};

