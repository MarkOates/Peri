
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, expected_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { ASSERT_EQ(std::string(expected_exception_message), err.what()); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Testing/WithAllegroRenderingFixture.hpp>

class Peri_BoardRendererTestWithEmptyFixture : public ::testing::Test
{};

class Peri_BoardRendererTestWithAllegroRenderingFixture
   : public Testing::WithAllegroRenderingFixture
{};


#include <Peri/BoardRenderer.hpp>


TEST_F(Peri_BoardRendererTestWithEmptyFixture, can_be_created_without_blowing_up)
{
   Peri::BoardRenderer board_renderer;
}

TEST_F(Peri_BoardRendererTestWithEmptyFixture, cell_size__defaults_to_100)
{
   Peri::BoardRenderer board_renderer;
   EXPECT_EQ(100.0f, board_renderer.get_cell_size());
}

TEST_F(Peri_BoardRendererTestWithEmptyFixture, render__without_a_board__raises_an_exception)
{
   Peri::BoardRenderer board_renderer;
   std::string expected_error_message = "BoardRenderer::render: error: guard \"board\" not met";
   ASSERT_THROW_WITH_MESSAGE(board_renderer.render(), std::runtime_error, expected_error_message);
}

TEST_F(Peri_BoardRendererTestWithAllegroRenderingFixture, render__renders_the_board)
{
   Peri::Board board;
   Peri::BoardRenderer board_renderer(&board);
   board_renderer.render();
   al_flip_display();
}

TEST_F(Peri_BoardRendererTestWithAllegroRenderingFixture, render__with_jellies__renders_the_board_as_expected)
{
   Peri::Board board;
   Peri::Jelly jelly1(1), jelly2(2);
   board.place_jelly(2, 3, &jelly1);
   board.place_jelly(5, 9, &jelly2);
   allegro_flare::placement2d centered_place = build_centered_placement2d(0, 0);

   Peri::BoardRenderer board_renderer(&board);
   board_renderer.set_position(centered_place.x, centered_place.y);
   board_renderer.render();
   al_flip_display();
   //sleep(1);
}

TEST_F(Peri_BoardRendererTestWithAllegroRenderingFixture, render__respects_x_and_y_placement)
{
   Peri::Board board;
   Peri::Jelly jelly1(1), jelly2(2);
   board.place_jelly(2, 3, &jelly1);
   board.place_jelly(5, 9, &jelly2);
   allegro_flare::placement2d centered_place = build_centered_placement2d(0, 0);

   Peri::BoardRenderer board_renderer(&board);
   board_renderer.set_position(centered_place.x - 300, centered_place.y - 100);
   board_renderer.render();
   al_flip_display();
   //sleep(1);
}

TEST_F(Peri_BoardRendererTestWithAllegroRenderingFixture, render__with_a_player_piece__renders_the_player_piece)
{
   Peri::Board board;
   Peri::Piece player_piece(4, 5, Peri::Jelly(2), Peri::Jelly(3));
   allegro_flare::placement2d centered_place = build_centered_placement2d(0, 0);

   Peri::BoardRenderer board_renderer(&board, &player_piece);
   board_renderer.set_position(centered_place.x, centered_place.y);

   board_renderer.render();

   al_flip_display();
   sleep(2);
}

