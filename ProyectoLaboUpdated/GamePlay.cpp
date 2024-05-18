#include "GamePlay.h"
#include <iostream>

GamePlay* GamePlay::_currentInstance = nullptr;

GamePlay::GamePlay()
{

}

GamePlay& GamePlay::getInstance()
{
	if (GamePlay::_currentInstance == nullptr)
	{       
		GamePlay::_currentInstance = new GamePlay();
	}
	return *GamePlay::_currentInstance;
}

void GamePlay::update()
{
	_hacker.update();
	_torre.update(_hacker);
	//_prueba.update();
	
	for (Proyectil& proyectil : _proyectiles)
	{
		proyectil.update();
	}

	/*
	auto it = _proyectiles.begin();
	while (it != _proyectiles.end())
	{
		Proyectil& proyectil = *it;
		proyectil.update();
		
		if (proyectil.estaColisionando(_hacker))
		{
			it = _proyectiles.erase(it);
		}
		else
		{
			++it;
		}

	}
	*/

}


void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_hacker, states);
	target.draw(_torre, states);
	target.draw(_prueba, states);

	for (const Proyectil& bullet : _proyectiles)
	{
		target.draw(bullet, states);
	}
	
}

void GamePlay::shoot(sf::Vector2f position)
{
	//LO hardcodeamos de mientrras para ver si funca
	_proyectiles.push_back(Proyectil(position, _hacker.getPosition(), 10));
}
