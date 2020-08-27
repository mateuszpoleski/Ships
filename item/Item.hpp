#pragma once
#include <stdint.h>
#include <string>

class Item
{
    std::string name;
    unsigned price;
    bool explosive;
    bool toxic;

public:
    Item();
    Item(std::string, unsigned, bool, bool);
    unsigned getPrice() const;
    bool isExplosive() const;
    bool isToxic() const;
};