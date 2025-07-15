#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int index=-1, finalIndex=-1;;

    for(int i=0; i<rows; i++) {
        if(matrix[i][0] > target && i != 0) {
            index = i-1;
            break;
        }
    }
    if (index == -1) index = rows - 1;
    cout << "Row: " << index;

    bool found=false;
    for(int i=0; i<cols; i++) {
        if(matrix[index][i]==target) {
            finalIndex = i;
            found=true;
            break;
        }
    }
    cout << "\nColumn: " << finalIndex << "\t" << matrix[index][finalIndex] << endl;

    return found;
}

int main() {
    vector<vector<int>> matrix{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    bool target =  search(matrix,34);
    cout << "Found:" << target;
}