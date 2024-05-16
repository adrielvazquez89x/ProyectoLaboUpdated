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
	_hacker.setPosition(100, 100);
	_torre.setPosition(400, 300);
	_torre.update(_hacker);

	/*
	auto it = _proyectiles.begin();
	while (it != _proyectiles.end())
	{
		Proyectil& proyectil = *it;
		proyectil.update();
		if(proyectil.getPosition().x )

	}
	*/
}


void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_torre, states);
	target.draw(_hacker, states);

	for (const Proyectil& bullet : _proyectiles)
	{
		target.draw(bullet, states);
	}
}

void GamePlay::shoot(sf::Vector2f position, Proyectil::Direction direction)
{
	_proyectiles.push_back(Proyectil(position, direction, 10));
}
