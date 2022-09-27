// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(matrix_init_1_by_1) {
  Matrix* m = new Matrix;
  Matrix_init(m, 1, 1);
  ASSERT_EQUAL(Matrix_width(m), 1);
  ASSERT_EQUAL(Matrix_height(m), 1);
  delete m;
}
TEST(matrix_init_max_by_max) {
  Matrix* m = new Matrix;
  Matrix_init(m, MAX_MATRIX_WIDTH, MAX_MATRIX_HEIGHT);
  ASSERT_EQUAL(Matrix_width(m), MAX_MATRIX_WIDTH);
  ASSERT_EQUAL(Matrix_height(m), MAX_MATRIX_HEIGHT);
  delete m;
}
TEST(matrix_init_1_by_max) {
  Matrix* m = new Matrix;
  Matrix_init(m, 1, MAX_MATRIX_HEIGHT);
  ASSERT_EQUAL(Matrix_width(m), 1);
  ASSERT_EQUAL(Matrix_height(m), MAX_MATRIX_HEIGHT);
  delete m;
}
TEST(matrix_init_max_by_1) {
  Matrix* m = new Matrix;
  Matrix_init(m, MAX_MATRIX_WIDTH, 1);
  ASSERT_EQUAL(Matrix_width(m), MAX_MATRIX_WIDTH);
  ASSERT_EQUAL(Matrix_height(m), 1);
  delete m;
}
TEST(matrix_print_basic) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  *Matrix_at(m, 0, 0) = 1;
  *Matrix_at(m, 1, 0) = 2;
  *Matrix_at(m, 0, 1) = 3;
  *Matrix_at(m, 1, 1) = 4;
  ostringstream s;
  Matrix_print(m, s);

  ostringstream correct;
  correct << "2 2\n1 3 \n2 4 \n";
  ASSERT_EQUAL(s.str(), correct.str());
  delete m;
}
TEST(matrix_print_1_by_1) {
  Matrix* m = new Matrix;
  Matrix_init(m, 1, 1);
  *Matrix_at(m, 0, 0) = 1;
  ostringstream s;
  Matrix_print(m, s);

  ostringstream correct;
  correct << "1 1\n1 \n";
  ASSERT_EQUAL(s.str(), correct.str());
  delete m;
}
TEST(matrix_width_height_basic) {
  Matrix* m = new Matrix;
  int width = 5;
  int height = 5;
  Matrix_init(m, width, height);
  ASSERT_EQUAL(Matrix_width(m), width);
  ASSERT_EQUAL(Matrix_height(m), height);
  delete m;
}
TEST(matrix_row_first) {
  Matrix* m = new Matrix;
  Matrix_init(m, 5, 5);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 2);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 0);
  delete m;
}
TEST(matrix_row_last) {
  Matrix* m = new Matrix;
  Matrix_init(m, 5, 5);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 4, 2);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 4);
  delete m;
}
TEST(matrix_row_top_left) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 0);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 0);
  delete m;
}
TEST(matrix_row_top_right) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 1);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 0);
  delete m;
}
TEST(matrix_row_bottom_left) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 1, 0);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 1);
  delete m;
}
TEST(matrix_row_bottom_right) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 1, 1);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 1);
  delete m;
}
TEST(matrix_row_1_by_1) {
  Matrix* m = new Matrix;
  Matrix_init(m, 1, 1);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 0);
  int row = Matrix_row(m, ptr);
  ASSERT_EQUAL(row, 0);
  delete m;
}
TEST(matrix_column_first) {
  Matrix* m = new Matrix;
  Matrix_init(m, 5, 5);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 2, 0);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 0);
  delete m;
}
TEST(matrix_column_last) {
  Matrix* m = new Matrix;
  Matrix_init(m, 5, 5);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 2, 4);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 4);
  delete m;
}
TEST(matrix_column_top_left) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 0);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 0);
  delete m;
}
TEST(matrix_column_top_right) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 1);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 1);
  delete m;
}
TEST(matrix_column_bottom_left) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 1, 0);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 0);
  delete m;
}
TEST(matrix_column_bottom_right) {
  Matrix* m = new Matrix;
  Matrix_init(m, 2, 2);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 1, 1);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 1);
  delete m;
}
TEST(matrix_column_1_by_1) {
  Matrix* m = new Matrix;
  Matrix_init(m, 1, 1);
  Matrix_fill(m, 10);
  int *ptr = Matrix_at(m, 0, 0);
  int column = Matrix_column(m, ptr);
  ASSERT_EQUAL(column, 0);
  delete m;
}
TEST(matrix_fill_border_square) {
  Matrix *m = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 3;
  const int value = 42;
  const int value_2 = -1;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  Matrix_fill_border(m, value_2);

  for(int r = 1; r < height - 1; ++r){
    for(int c = 1; c < width - 1; ++c){
      ASSERT_EQUAL(*Matrix_at(m, r, c), value);
    }
  }
  for(int i = 0; i < height; i++) {
    ASSERT_EQUAL(*Matrix_at(m, i, 0), value_2);
  }
  for(int i = 0; i < height; i++) {
    ASSERT_EQUAL(*Matrix_at(m, i, width - 1), value_2);
  }
  for(int i = 0; i < width; i++) {
    ASSERT_EQUAL(*Matrix_at(m, 0, i), value_2);
  }
  for(int i = 0; i < width; i++) {
    ASSERT_EQUAL(*Matrix_at(m, height - 1, i), value_2);
  }

  delete m; // delete the Matrix
}
TEST(matrix_fill_border_rectangle) {
  Matrix *m = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  const int value_2 = -1;
  Matrix_init(m, 3, 5);
  Matrix_fill(m, value);
  Matrix_fill_border(m, value_2);

  for(int r = 1; r < height - 1; ++r){
    for(int c = 1; c < width - 1; ++c){
      ASSERT_EQUAL(*Matrix_at(m, r, c), value);
    }
  }
  for(int i = 0; i < height; i++) {
    ASSERT_EQUAL(*Matrix_at(m, i, 0), value_2);
  }
  for(int i = 0; i < height; i++) {
    ASSERT_EQUAL(*Matrix_at(m, i, width - 1), value_2);
  }
  for(int i = 0; i < width; i++) {
    ASSERT_EQUAL(*Matrix_at(m, 0, i), value_2);
  }
  for(int i = 0; i < width; i++) {
    ASSERT_EQUAL(*Matrix_at(m, height - 1, i), value_2);
  }

  delete m; // delete the Matrix
}
TEST(matrix_fill_border_2_by_2) {
  Matrix* m = new Matrix;
  int width = 2;
  int height = 2;
  int value = 2;
  int value_2 = 4;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  Matrix_fill_border(m, value_2);
  for(int i = 0; i < height - 1; i++) {
    for(int j = 0; j < height - 1; j++) {
      ASSERT_EQUAL(*Matrix_at(m, i, j), value_2);
    }
  }
  delete m;
}
TEST(matrix_fill_border_1_by_1) {
  Matrix* m = new Matrix;
  int width = 1;
  int height = 1;
  int value = 2;
  int value_2 = 4;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  Matrix_fill_border(m, value_2);
  ASSERT_EQUAL(*Matrix_at(m, 0, 0), value_2);
  delete m;
}
TEST(matrix_max_basic) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 3;
  int max = 10;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 2, 2) = max;
  ASSERT_EQUAL(Matrix_max(m), max);
  delete m;
}
TEST(matrix_max_top_left) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 3;
  int max = 10;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 0, 0) = max;
  ASSERT_EQUAL(Matrix_max(m), max);
  delete m;
}
TEST(matrix_max_top_right) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 3;
  int max = 10;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 0, 3) = max;
  ASSERT_EQUAL(Matrix_max(m), max);
  delete m;
}
TEST(matrix_max_bottom_left) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 3;
  int max = 10;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, 0) = max;
  ASSERT_EQUAL(Matrix_max(m), max);
  delete m;
}
TEST(matrix_max_bottom_right) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 3;
  int max = 10;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, 3) = max;
  ASSERT_EQUAL(Matrix_max(m), max);
  delete m;
}
TEST(matrix_max_negative) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = -10;
  int max = -3;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 2, 2) = max;
  ASSERT_EQUAL(Matrix_max(m), max);
  delete m;
}
TEST(matrix_column_of_min) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 2;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 2, column) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 2, 0, 4), column);
  delete m;
}
TEST(matrix_column_of_min_top_left) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 0;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 0, column) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 0, 0, 4), column);
  delete m;
}
TEST(matrix_column_of_min_top_right) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 3;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 0, column) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 0, 0, 4), column);
  delete m;
}
TEST(matrix_column_of_min_bottom_left) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 0;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, column) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 3, 0, 4), column);
  delete m;
}
TEST(matrix_column_of_min_bottom_right) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 3;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, column) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 3, 0, 4), column);
  delete m;
}
TEST(matrix_column_of_min_negative) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = -3;
  int min = -10;
  int column = 3;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, column) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 3, 0, 4), column);
  delete m;
}
TEST(matrix_column_of_min_tie) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 2;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, column) = min;
  *Matrix_at(m, 3, column + 1) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(m, 3, 0, 4), column);
  delete m;
}
TEST(matrix_min) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 2;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 2, column) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(m, 2, 0, 4), min);
  delete m;
}
TEST(matrix_min_top_left) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 0;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 0, column) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(m, 0, 0, 4), min);
  delete m;
}
TEST(matrix_min_top_right) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 3;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 0, column) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(m, 0, 0, 4), min);
  delete m;
}
TEST(matrix_min_bottom_left) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 0;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, column) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(m, 3, 0, 4), min);
  delete m;
}
TEST(matrix_min_bottom_right) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = 10;
  int min = 3;
  int column = 3;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 3, column) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(m, 3, 0, 4), min);
  delete m;
}
TEST(matrix_min_negative) {
  Matrix* m = new Matrix;
  int width = 4;
  int height = 4;
  int value = -3;
  int min = -10;
  int column = 2;
  Matrix_init(m, width, height);
  Matrix_fill(m, value);
  *Matrix_at(m, 2, column) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(m, 2, 0, 4), min);
  delete m;
}



// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
