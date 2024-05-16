#include "Colisionable.h"

bool Colisionable::estaColisionando(Colisionable& target) const
{
    return getBounds().intersects(target.getBounds());
}
