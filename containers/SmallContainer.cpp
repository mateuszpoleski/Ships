#include "SmallContainer.hpp"

SmallContainer::SmallContainer(bool explosivs, bool toxins) : Container::Container(explosivs, toxins) {}
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
    if (itemsCount < capacity)
    {
        items.push_back(item);
        itemsCount++;
    }
}
unsigned SmallContainer::getCapacity()
{
    return capacity;
}
