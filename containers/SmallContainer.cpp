#include <iostream>
#include "SmallContainer.hpp"

SmallContainer::SmallContainer(bool explosivs, bool toxins) : Container::Container(explosivs, toxins)
{
    std::cout << "Creating new small container for: " << (explosivs ? " explosives " : "") << (toxins ? " toxins " : "") << "\n";
}
double SmallContainer::calculatePrice() const
{
    double price = 0;
    for (const Item &item : items)
    {
        price += item.getPrice() * 1.2;
    }
    return price;
}
void SmallContainer::addItem(Item item)
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
unsigned SmallContainer::getCapacity()
{
    return capacity;
}
