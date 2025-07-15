#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }    
    cout << "\n\n";
}

int main() {
    vector<vector<int>> matrix(2, vector<int>(3));
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = i+1;
        }
    }    
    printMatrix(matrix);
    
    vector<vector<int>> matrix1(2, vector<int>(3,0));
    printMatrix(matrix1);

    int rows, cols;
    cout << "Enter row and col: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix2;

    for (int i = 0; i < rows; ++i) {
        cout << "Enter Row " << i+1 << ": ";
        vector<int> row;
        for (int j = 0; j < cols; ++j) {
            int val;
            cin >> val;
            row.push_back(val); // fill current row
        }
        matrix2.push_back(row); // add row to matrix
    }
    printMatrix(matrix2);
}