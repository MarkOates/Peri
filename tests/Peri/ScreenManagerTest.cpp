
#include <gtest/gtest.h>

#include <Peri/ScreenManager.hpp>

TEST(Peri_ScreenManagerTest, can_be_created_without_blowing_up)
{
   Peri::ScreenManager screen_manager;
}

TEST(Peri_ScreenManagerTest, run__returns_the_expected_response)
{
   Peri::ScreenManager screen_manager;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, screen_manager.run());
}
