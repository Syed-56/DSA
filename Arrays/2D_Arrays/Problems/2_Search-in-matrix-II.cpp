#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int start=0, end=cols-1;
    while(start<rows & end>=0) {
        int mid = matrix[start][end];
        if(mid > target)    end--;
        else if(mid < target)   start++;
        else    return true;
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