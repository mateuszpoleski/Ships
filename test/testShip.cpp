#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../item/Item.hpp"
#include "../containers/BigContainer.hpp"
#include "../containers/SmallContainer.hpp"
#include "../ship/Ship.hpp"
// Can be also "Ship.hpp" etc.

struct testShip : public ::testing::Test
{
    Ship ship;

    void SetUp()
    {
        bool withToxins = true;
        bool withExplosives = true;

        Item item("testName", 100, not withToxins, not withExplosives);
        std::unique_ptr<Container> bigContainer = std::make_unique<BigContainer>(not withToxins, withExplosives);
        std::unique_ptr<Container> smallContainer = std::make_unique<SmallContainer>(withToxins, not withExplosives);

        bigContainer->addItem(item);
        smallContainer->addItem(item);
        ship.addContainer(std::move(smallContainer));
        ship.addContainer(std::move(bigContainer));
    }

    void TearDown()
    {
    }
};

TEST_F(testShip, size)
{
    ASSERT_EQ(2, ship.size());
}

TEST_F(testShip, deload)
{
    ASSERT_EQ(210, ship.deload());
}

TEST_F(testShip, addNewContainer)
{
    int size = ship.size();
    std::unique_ptr<Container> bigContainer = std::make_unique<BigContainer>(true, true);

    ship.addContainer(std::move(bigContainer));

    ASSERT_EQ(size + 1, ship.size());
}

TEST_F(testShip, deloadAfterAddingNewContainer)
{
    Item item("testName", 100, true, true);
    std::unique_ptr<Container> bigContainer = std::make_unique<BigContainer>(true, true);

    bigContainer->addItem(item);
    ship.addContainer(std::move(bigContainer));

    ASSERT_EQ(300, ship.deload());
}
