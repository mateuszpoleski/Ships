#pragma once
#include <stdint.h>
#include <string>

class Item
{
    unsigned price;
    bool explosive;
    bool toxic;

public:
    Item();
    Item(unsigned, bool, bool);
    unsigned getPrice() const;
    bool isExplosive() const;
    bool isToxic() const;
};