// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.
TEST(image_init_parameters_basic) {
  Image* img = new Image;
  int width = 5;
  int height = 5;
  Image_init(img, width, height);
  ASSERT_EQUAL(Image_width(img), width);
  ASSERT_EQUAL(Image_height(img), height);
  delete img;
}
TEST(image_init_1_by_1) {
  Image* img = new Image;
  int width = 1;
  int height = 1;
  Image_init(img, width, height);
  ASSERT_EQUAL(Image_width(img), width);
  ASSERT_EQUAL(Image_height(img), height);
  delete img;
}
TEST(image_init_max_by_max) {
  Image* img = new Image;
  int width = MAX_MATRIX_WIDTH;
  int height = MAX_MATRIX_HEIGHT;
  Image_init(img, width, height);
  ASSERT_EQUAL(Image_width(img), width);
  ASSERT_EQUAL(Image_height(img), height);
  delete img;
}
TEST(image_init_max_by_1) {
  Image* img = new Image;
  int width = MAX_MATRIX_WIDTH;
  int height = 1;
  Image_init(img, width, height);
  ASSERT_EQUAL(Image_width(img), width);
  ASSERT_EQUAL(Image_height(img), height);
  delete img;
}
TEST(image_init_1_by_max) {
  Image* img = new Image;
  int width = 1;
  int height = MAX_MATRIX_HEIGHT;
  Image_init(img, width, height);
  ASSERT_EQUAL(Image_width(img), width);
  ASSERT_EQUAL(Image_height(img), height);
  delete img;
}
TEST(image_init_file) {
  Image *img = new Image;
  string input = "P3\n2 2\n255\n";
  input += "255 0 0 0 255 0 \n";
  input += "0 0 255 255 255 255 \n";
  istringstream ss_input(input);
  Image_init(img, ss_input);
  ASSERT_EQUAL(Image_width(img), 2);
  ASSERT_EQUAL(Image_height(img), 2);
  assert(Pixel_equal(Image_get_pixel(img, 0, 0), {255, 0, 0}));
  assert(Pixel_equal(Image_get_pixel(img, 0, 1), {0, 255, 0}));
  assert(Pixel_equal(Image_get_pixel(img, 1, 0), {0, 0, 255}));
  assert(Pixel_equal(Image_get_pixel(img, 1, 1), {255, 255, 255}));
  delete img;
}
TEST(image_width_height_basic) {
  Image* img = new Image;
  int width = 5;
  int height = 5;
  Image_init(img, width, height);
  ASSERT_EQUAL(Image_width(img), width);
  ASSERT_EQUAL(Image_height(img), height);
  delete img;
}
TEST(image_get_pixel_basic) {
  Image* img = new Image;
  Pixel* pix = new Pixel;
  Image_init(img, 5, 5);
  pix->r = 60;
  pix->g = 20;
  pix->b = 40;
  Image_set_pixel(img, 2, 2, *pix);
  Pixel* pix2 = new Pixel;
  *pix2 = Image_get_pixel(img, 2, 2);
  assert(Pixel_equal(*pix2, {60, 20, 40}));
  delete img;
  delete pix;
  delete pix2;
}
TEST(image_get_pixel_top_left) {
  Image* img = new Image;
  Pixel* pix = new Pixel;
  Image_init(img, 5, 5);
  pix->r = 60;
  pix->g = 20;
  pix->b = 40;
  Image_set_pixel(img, 0, 0, *pix);
  Pixel* pix2 = new Pixel;
  *pix2 = Image_get_pixel(img, 0, 0);
  assert(Pixel_equal(*pix2, {60, 20, 40}));
  delete img;
  delete pix;
  delete pix2;
}
TEST(image_get_pixel_top_right) {
  Image* img = new Image;
  Pixel* pix = new Pixel;
  Image_init(img, 5, 5);
  pix->r = 60;
  pix->g = 20;
  pix->b = 40;
  Image_set_pixel(img, 0, 4, *pix);
  Pixel* pix2 = new Pixel;
  *pix2 = Image_get_pixel(img, 0, 4);
  assert(Pixel_equal(*pix2, {60, 20, 40}));
  delete img;
  delete pix;
  delete pix2;
}
TEST(image_get_pixel_bottom_left) {
  Image* img = new Image;
  Pixel* pix = new Pixel;
  Image_init(img, 5, 5);
  pix->r = 60;
  pix->g = 20;
  pix->b = 40;
  Image_set_pixel(img, 4, 0, *pix);
  Pixel* pix2 = new Pixel;
  *pix2 = Image_get_pixel(img, 4, 0);
  assert(Pixel_equal(*pix2, {60, 20, 40}));
  delete img;
  delete pix;
  delete pix2;
}
TEST(image_get_pixel_bottom_right) {
  Image* img = new Image;
  Pixel* pix = new Pixel;
  Image_init(img, 5, 5);
  pix->r = 60;
  pix->g = 20;
  pix->b = 40;
  Image_set_pixel(img, 4, 4, *pix);
  Pixel* pix2 = new Pixel;
  *pix2 = Image_get_pixel(img, 4, 4);
  assert(Pixel_equal(*pix2, {60, 20, 40}));
  delete img;
  delete pix;
  delete pix2;
}
TEST(image_fill_basic) {
  Image* img = new Image;
  int width = 5;
  int height = 5;
  Image_init(img, width, height);
  Image_fill(img, {50, 50, 50});
  for(int i = 0; i < Image_height(img); i++) {
    for(int j = 0; j < Image_width(img); j++) {
      assert(Pixel_equal(Image_get_pixel(img, i, j), {50, 50, 50}));
    }
  }
  delete img;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
