
#include <gtest/gtest.h>

#include <Testing/WithAllegroFlareFrameworkFixture.hpp>


class TestClass : public Testing::WithAllegroFlareFrameworkFixture
{
   virtual void TestBody() {}
};



TEST(Testing_WithAllegroFlareFrameworkFixture, can_be_created_without_blowing_up)
{
   TestClass test_class;
}

TEST(Testing_WithAllegroFlareFrameworkFixture, SetUp__initializes_the_framework)
{
   TestClass test_class;
   AllegroFlare::Framework &framework = test_class.get_framework_ref();

   test_class.SetUp();

   EXPECT_EQ(true, framework.is_initialized());
}

TEST(Testing_WithAllegroFlareFrameworkFixture, SetUp__creates_a_display)
{
   TestClass test_class;
   EXPECT_EQ(nullptr, test_class.get_display());

   test_class.SetUp();
   EXPECT_NE(nullptr, test_class.get_display());

   test_class.TearDown();
}

TEST(Testing_WithAllegroFlareFrameworkFixture, TearDown__uninitializes_the_framework)
{
   TestClass test_class;
   AllegroFlare::Framework &framework = test_class.get_framework_ref();

   test_class.SetUp();
   EXPECT_EQ(true, framework.is_initialized());

   test_class.TearDown();
   EXPECT_EQ(false, framework.is_initialized());
}

TEST(Testing_WithAllegroFlareFrameworkFixture, TearDown__sets_the_display_to_nullptr)
{
   TestClass test_class;
   EXPECT_EQ(nullptr, test_class.get_display());

   test_class.SetUp();
   test_class.TearDown();
   EXPECT_EQ(nullptr, test_class.get_display());
}

