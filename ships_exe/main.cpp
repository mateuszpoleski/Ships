#include <iostream>
#include <memory>
#include "Item.hpp"
#include "BigContainer.hpp"
#include "SmallContainer.hpp"
#include "Ship.hpp"

int main()
{
    bool withToxins = true;
    bool withExplosives = true;

    Item item1("someExplossiveItem", 100, withExplosives, withToxins);
    Item item2("someExplosiveAndToxicItem", 200, not withExplosives, withToxins);
    std::unique_ptr<Container> bigContainer = std::make_unique<BigContainer>(not withExplosives, withToxins);
    std::unique_ptr<Container> smallContainer = std::make_unique<SmallContainer>(withExplosives, withToxins);
    bigContainer->addItem(item1);
    bigContainer->addItem(item2);
    smallContainer->addItem(item1);
    smallContainer->addItem(item2);
    std::cout << "Price of items in first container: (price depends on the type of containers) " << bigContainer->calculatePrice() << '\n';
    std::cout << "Price of items in second container: (price depends on the type of containers) " << smallContainer->calculatePrice() << '\n';
    Ship ship;
    ship.addContainer(std::move(bigContainer));
    ship.addContainer(std::move(smallContainer));
    std::cout << "Price of all items on the ship: " << ship.deload() << '\n';

    return 0;
}