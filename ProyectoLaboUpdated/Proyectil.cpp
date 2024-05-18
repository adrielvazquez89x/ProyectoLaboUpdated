#include "Proyectil.h"
#include <iostream>
#include <cmath>

sf::Texture Proyectil::_texture;

Proyectil::Proyectil(sf::Vector2f posicionInicial, sf::Vector2f objetivo, float danio)
{
    if (!_texture.loadFromFile("Flame_D.png")) {
        std::cout << "NO CARGO" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setScale(0.2, 0.2);
    
    setPosition(posicionInicial);

    _objetivo = objetivo;

    _velocidad = {3,3};
    _danio = danio;
}

sf::Sprite Proyectil::getSprite()
{
    return _sprite;
}

sf::FloatRect Proyectil::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Proyectil::moverse(sf::Vector2f torre, sf::Vector2f objetivo)
{
    // Calcular el vector de dirección entre la torre y el objetivo
    sf::Vector2f direccion = objetivo - torre;

    // Lo del teorema del mago ese griego viejo
    direccion /= sqrt(direccion.x * direccion.x + direccion.y + direccion.y);

    //rotacion

    float angulo = atan2(direccion.y, direccion.x);

    setRotation(angulo * 180 / 3.14);

    // Normalizar el vector de dirección para mantener una velocidad constante
    direccion = direccion / sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    // Mover el proyectil en la dirección calculada
    move(direccion.x * _velocidad.x, direccion.y * _velocidad.y);
}

void Proyectil::update()
{
    moverse(getPosition(), _objetivo);
    //move({ 10,10 });
    
}

void Proyectil::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_sprite, states);
}
