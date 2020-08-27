#include <iostream>
#include "BigContainer.hpp"

BigContainer::BigContainer(bool explosivs, bool toxins) : Container::Container(explosivs, toxins)
{
    std::cout << "Creating new big container for: " << (explosivs ? " explosives " : "") << (toxins ? " toxins " : "") << "\n";
}
double BigContainer::calculatePrice() const
{
    double price = 0;
    for (const Item &item : items)
    {
        price += item.getPrice() * 0.9;
    }
    return price;
}
void BigContainer::addItem(Item item)
{
    if ((itemsCount < capacity) and ((not item.isToxic()) or toxins) and ((not item.isExplosive()) or explosives))
    {
        items.push_back(item);
        itemsCount++;
        std::cout << "Item is added to container. \n";
    }
    else
    {
        std::cout << "The container does not meet the requirements, item is not added. \n";
    }
}
unsigned BigContainer::getCapacity()
{
    return capacity;
}