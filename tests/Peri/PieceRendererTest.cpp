
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, expected_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { ASSERT_EQ(std::string(expected_exception_message), err.what()); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Testing/WithAllegroRenderingFixture.hpp>

class Peri_PieceRendererTestWithEmptyFixture : public ::testing::Test
{};

class Peri_PieceRendererTestWithAllegroRenderingFixture
   : public Testing::WithAllegroRenderingFixture
{};


#include <Peri/PieceRenderer.hpp>


TEST_F(Peri_PieceRendererTestWithEmptyFixture, can_be_created_without_blowing_up)
{
   Peri::PieceRenderer piece_renderer;
}

TEST_F(Peri_PieceRendererTestWithAllegroRenderingFixture, render__renders_the_piee)
{
   Peri::Piece piece;
   Peri::PieceRenderer piece_renderer(&piece);

   piece_renderer.render();

   al_flip_display();
   sleep(1);
}

