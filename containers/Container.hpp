#pragma once
#include <vector>
#include "../item/Item.hpp"

class Container
{
protected:
    std::vector<Item> items;
    bool explosives;
    bool toxins;

public:
    Container(bool, bool);
    virtual double calculatePrice() const = 0;
    virtual void addItem(Item) = 0;
    virtual ~Container(){};
};