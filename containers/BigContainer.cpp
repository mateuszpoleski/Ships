#include "BigContainer.hpp"

BigContainer::BigContainer(bool explosivs, bool toxins) : Container::Container(explosivs, toxins) {}
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
    if (itemsCount < capacity)
    {
        items.push_back(item);
        itemsCount++;
    }
}
unsigned BigContainer::getCapacity()
{
    return capacity;
}