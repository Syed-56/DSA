#include <iostream>
#include <vector>
using namespace std;

vector<int> maxRow(vector<vector <int>> matrix) {
    int sum=0, maxSum = INT16_MIN, maxRowIndex=-1;
    for(int i=0; i<matrix.size(); i++) {
        sum=0;
        for(int j=0; j<matrix[0].size(); j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRowIndex = i;
        }
    }
    return matrix[maxRowIndex];
}

int main() {
    vector<vector <int>> matrix(3,vector<int>(3));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = i+j+1;
            cout << matrix[i][j];
        }
        cout << endl;
    }
    vector<int> bigRow = maxRow(matrix);
    for(int val:bigRow)   cout << val << " ";
}