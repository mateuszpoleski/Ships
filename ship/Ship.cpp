#include <iostream>
#include "Ship.hpp"

double Ship::deload() const
{
    double paycheck = 0;
    for (const std::unique_ptr<Container> &container : containers)
    {
        paycheck += container->calculatePrice();
    }
}
void Ship::addContainer(std::unique_ptr<Container> container)
{
    containers.push_back(std::move(container));
    std::cout << "Loading a new container on the ship.\n";
}

size_t Ship::size() const
{
    return containers.size();
}