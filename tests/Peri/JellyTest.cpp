
#include <gtest/gtest.h>

#include <Peri/Jelly.hpp>

TEST(Peri_JellyTest, can_be_created_without_blowing_up)
{
   Peri::Jelly jelly;
}

TEST(Peri_JellyTest, run__returns_the_expected_response)
{
   Peri::Jelly jelly;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, jelly.run());
}
