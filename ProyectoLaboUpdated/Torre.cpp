#include <iostream>
#include "Torre.h"
#include "Proyectil.h"

//Getters
std::string Torre::getNombre()
{
    return _nombre;
}

float Torre::getCosto()
{
    return _costo;
}

float Torre::getCostoUpgrade()
{
    return _costoUpgrade;
}

float Torre::getValorVenta()
{
    return _valorVenta;
}

sf::CircleShape Torre::getRango()
{
    return _rango;
}

sf::Sprite Torre::getSprite()
{
    return _sprite;
}

float Torre::getDanioCausante()
{
    return _danioCausante;
}

int Torre::getAlcance()
{
    return _alcance;
}

int Torre::getVelocidadAtaque()
{
    return _velocidadAtaque;
}

int Torre::getTipoAtaque()
{
    return _tipoAtaque;
}

int Torre::getCantidadUpgrades()
{
    return _cantidadUpgrades;
}

//Setters

void Torre::setNombre(std::string nombre)
{
    if (nombre.length() > 15)
    {
        _nombre = "Nombre muy largo.";
        return;
    }

    _nombre = nombre;
}

void Torre::setCosto(float costo)
{
    _costo = costo;
}

void Torre::setValorVenta(float valor)
{
    _valorVenta = valor;
}

void Torre::setDanioCausante(float danio)
{
    _danioCausante = danio;
}

void Torre::setAlcance(int alcance)
{
    _alcance = alcance;
}

void Torre::setCostoUpgrade(float costo)
{
    _costoUpgrade = costo;
}

//Comportamiento

void Torre::dispararObjetivo(Hacker& target)
{
    /*
    Proyectil bala({6,6}, 10);
    bala.getSprite().setPosition(bala.getSprite().getPosition().x+1,0);
    */

    //Esto es aparte
    target.getSalud() -= getDanioCausante();
}
void Torre::verificarEnemigo(Hacker& target)
{
    // Obtiene la posición del centro de la torre
    sf::Vector2f posicionTorre = _rango.getPosition();

    // Obtiene los límites globales del sprite del objetivo
    sf::FloatRect limitesObjetivo = target.getSprite().getGlobalBounds();

    // Calcula la posición del centro del sprite del objetivo
    sf::Vector2f centroObjetivo(limitesObjetivo.left + limitesObjetivo.width / 2, limitesObjetivo.top + limitesObjetivo.height / 2);

    // Calcula la distancia entre los centros de la torre y el objetivo
    float distancia = std::sqrt(std::pow(centroObjetivo.x - posicionTorre.x, 2) + std::pow(centroObjetivo.y - posicionTorre.y, 2));

    // Obtiene el radio de la torre
    float radioTorre = _rango.getRadius(); // Suponiendo que _sprite es un sf::CircleShape

    // Comprueba si la distancia entre los centros es menor o igual al radio de la torre
    if (distancia <= radioTorre)
    {
        dispararObjetivo(target);
    }

}

void Torre::update(Hacker& target)
{
    verificarEnemigo(target);

}

void Torre::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //Acpa dibujamos el "rango"
    target.draw(_rango, states);
    //Acá dibujamos la "torrecita"
    target.draw(_sprite, states);

}
//DESARROLLO
void Torre::setPosition(float x, float y)
{
    _rango.setPosition(sf::Vector2f(x, y));
    _sprite.setPosition(sf::Vector2f(x, y));
}