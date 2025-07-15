#include <iostream>
#include <vector>
using namespace std;

vector<int> maxRow(vector<vector <int>> matrix) {

}

int main() {
    vector<vector <int>> matrix(3,vector<int>(3));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = i+j+1;
        }
    }
    vector<int> bigRow = maxRow(matrix);
    for(int val:bigRow)   cout << val << " ";
}