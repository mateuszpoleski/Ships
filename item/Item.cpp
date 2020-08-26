#include "Item.hpp"

Item::Item() : price(0), explosive(false), toxic(false){};
Item::Item(unsigned price, bool explosive, bool toxic) : price(price), explosive(explosive), toxic(toxic){};
unsigned Item::getPrice() const
{
    return price;
}
bool Item::isExplosive() const
{
    return explosive;
}
bool Item::isToxic() const
{
    return toxic;
}