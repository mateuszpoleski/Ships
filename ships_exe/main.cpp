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

    Item item(100, not withToxins, withExplosives);
    std::unique_ptr<Container> bigContainer = std::make_unique<BigContainer>(not withToxins, withExplosives);
    std::unique_ptr<Container> smallContainer = std::make_unique<SmallContainer>(not withToxins, not withExplosives);
    bigContainer->addItem(item);
    smallContainer->addItem(item);
    std::cout << bigContainer->calculatePrice() << '\n';
    std::cout << smallContainer->calculatePrice() << '\n';
    Ship ship;
    ship.addContainer(std::move(bigContainer));
    ship.addContainer(std::move(smallContainer));
    std::cout << ship.deload() << '\n';

    return 0;
}