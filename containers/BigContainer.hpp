#pragma once
#include "Container.hpp"

class BigContainer : public Container
{
    unsigned capacity = 40;
    unsigned itemsCount = 0;

public:
    BigContainer(bool, bool);
    double calculatePrice() const override;
    void addItem(Item) override;
    unsigned getCapacity();
    ~BigContainer(){};
};