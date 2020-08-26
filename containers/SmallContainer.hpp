#pragma once
#include "Container.hpp"

class SmallContainer : public Container
{
    unsigned capacity = 20;
    unsigned itemsCount = 0;

public:
    SmallContainer(bool, bool);
    double calculatePrice() const override;
    void addItem(Item) override;
    unsigned getCapacity();
    ~SmallContainer(){};
};