#include <iostream>
#include <gtest/gtest.h>
#include "../item/Item.hpp"

struct testItem : public ::testing::Test
{
    Item item;

    void SetUp()
    {
        bool isExplosive = true;
        bool isToxic = false;

        item = Item(3, isExplosive, isToxic);
    }
};

TEST_F(testItem, getPrice)
{
    ASSERT_EQ(3, item.getPrice());
}

TEST_F(testItem, isExplosive)
{
    ASSERT_TRUE(item.isExplosive());
}

TEST_F(testItem, isToxic)
{
    ASSERT_FALSE(item.isToxic());
}

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}