#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Torre.h"
#include "TorreLab.h"
#include "Hacker.h"
#include "HackerTrainee.h"
#include "Proyectil.h"

class GamePlay : public sf::Drawable
{
private:
	GamePlay();
	static GamePlay* _currentInstance;
	TorreLab _torre;
	HackerTrainee _hacker;
	Proyectil _prueba;
	std::list<Proyectil> _proyectiles;

public:
	static GamePlay& getInstance();

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void shoot(sf::Vector2f position);
};

