#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> matrix, int target) {

}

int main() {
    vector<vector<int>> matrix{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = i+1;
        }
    }  
    bool target =  search(matrix,34);
    cout << "Found:" << target;
}