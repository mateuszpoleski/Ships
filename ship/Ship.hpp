#pragma once

#include <vector>
#include <memory>
#include "../containers/Container.hpp"

class Ship
{
    std::vector<std::unique_ptr<Container>> containers;

public:
    double deload() const;
    void addContainer(std::unique_ptr<Container>);
    size_t size() const;
};