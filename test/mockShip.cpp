#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../item/Item.hpp"
#include "../containers/BigContainer.hpp"
#include "../containers/SmallContainer.hpp"
#include "../ship/Ship.hpp"

class MockContainer : public Container
{
public:
    MockContainer(bool explosives, bool toxins) : Container(explosives, toxins){};
    MOCK_METHOD(double, calculatePrice, (), (const, override));
    MOCK_METHOD(void, addItem, (Item), (override));
};

TEST(ShipTest, deload)
{
    Ship ship;
    std::unique_ptr<MockContainer> container1 = std::make_unique<MockContainer>(true, true);
    std::unique_ptr<MockContainer> container2 = std::make_unique<MockContainer>(true, true);

    EXPECT_CALL(*container1, calculatePrice())
        .Times(1);
    EXPECT_CALL(*container2, calculatePrice())
        .Times(1);

    ship.addContainer(std::move(container1));
    ship.addContainer(std::move(container2));

    ship.deload();
}
