#include "Proyectil.h"

Proyectil::Proyectil(sf::Vector2f velocidad, Direction direction, float danio)
{
    _texture.loadFromFile("Flame_D.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(0.2, 0.2);

    _velocidad = velocidad;
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

    // Ajustar la magnitud del vector de dirección para aumentar la velocidad
    float factorVelocidad = 7.0f;
    direccion *= factorVelocidad;

    // Normalizar el vector de dirección para mantener una velocidad constante
    direccion = direccion / sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    // Mover el proyectil en la dirección calculada
    _sprite.move(direccion);
}

void Proyectil::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
