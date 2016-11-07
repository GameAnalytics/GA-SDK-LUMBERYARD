
#include "StdAfx.h"

#include <AzTest/AzTest.h>

class GameAnalyticsTest
    : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }

    void TearDown() override
    {

    }
};

TEST_F(GameAnalyticsTest, ExampleTest)
{
    ASSERT_TRUE(true);
}

AZ_UNIT_TEST_HOOK();
