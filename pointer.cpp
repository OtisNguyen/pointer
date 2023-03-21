#include <iostream>

using namespace std;

int** transposeMatrix(int** a, int length, int width) {
    // create a new 2D array for the transpose matrix
    int** transposed = new int*[width];
    for (int i = 0; i < width; i++) {
        transposed[i] = new int[length];
    }

    // calculate the transpose matrix
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            transposed[j][i] = a[i][j];
        }
    }

    return transposed;
}

int main() {
    int length, width;

    // get the size of the matrix from the user
    cout << "Enter the number of rows: ";
    cin >> length;
    cout << "Enter the number of columns: ";
    cin >> width;

    // create the matrix
    int** a = new int*[length];
    for (int i = 0; i < length; i++) {
        a[i] = new int[width];
    }

    // get the values of the matrix from the user
    cout << "Enter the values of the matrix:\n";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cin >> a[i][j];
        }
    }

    // calculate the transpose matrix
    int** transposed = transposeMatrix(a, length, width);

    // print the transpose matrix
    cout << "The transpose matrix is:\n";
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    // free the memory allocated for the matrices
    for (int i = 0; i < length; i++) {
        delete[] a[i];
    }
    delete[] a;
    for (int i = 0; i < width; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}