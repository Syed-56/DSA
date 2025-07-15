#include <iostream>
#include <vector>
using namespace std;

int sumOfDiagonals(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    if(row != col)  return -1;

    int sumDiagonalPrimary=0, sumDiagonalReverse=0;
    for(int i=0; i<row; i++) {
        sumDiagonalPrimary += matrix[i][i];
    }
    for (int i=row-1; i >= 0; i--) {
        sumDiagonalReverse += matrix[i][i];
    }
    cout << sumDiagonalPrimary << "\t" << sumDiagonalReverse << endl;
    return sumDiagonalPrimary + sumDiagonalReverse;    
}

int main() {
    vector<vector<int>> matrix(3, vector<int>(3));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = i+1+j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }   
    int sum = sumOfDiagonals(matrix);
    cout << "Sum = " << sum;
}