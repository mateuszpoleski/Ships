#include <iostream>
#include "Item.hpp"

Item::Item() : price(0), explosive(false), toxic(false){};
Item::Item(std::string name, unsigned price, bool explosive, bool toxic) : name(name), price(price), explosive(explosive), toxic(toxic)
{
    std::cout << "Creating new item : "
              << "                                  \n"
              << "             name : " << name << "\n"
              << "       properties : " << (explosive ? "explosive " : "") << (toxic ? "toxic " : "") << "\n"
              << "             cost : " << price << "\n";
};
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