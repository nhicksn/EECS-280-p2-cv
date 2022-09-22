// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
using namespace std;
#include "Matrix.h"

int main() {
    Matrix* m = new Matrix; // allocate storage in dynamic memory
    
    Matrix_init(m, 6, 6); // initialize it as a 100x100 matrix
    
    Matrix_fill(m, 0); // fill with zeros
    
    Matrix_print(m, cout); // print matrix to cout
    
    Matrix_fill_border(m, 5);

    Matrix_print(m, cout);
    *Matrix_at(m, 2, 5) = -1;
    Matrix_print(m, cout);
    cout << Matrix_max(m) << endl;
    cout << Matrix_column_of_min_value_in_row(m, 3, 2, 5) << endl;
    cout << Matrix_min_value_in_row(m, 3, 2, 4) << endl;
    int *ptr = Matrix_at(m, 0, 4);
    int column = Matrix_column(m, ptr);
    cout << column << endl;
    delete m;
}