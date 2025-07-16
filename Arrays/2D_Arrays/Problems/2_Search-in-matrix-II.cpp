#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(matrix[i][j]==target)    return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix{
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    bool target =  search(matrix,5);
    cout << "Found:" << target;
}