#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> matrix) {

}

int main() {
    vector<vector<int>> matrix {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> spiralArray = spiralMatrix(matrix);
    for(int val:spiralArray)    cout << val << " ";
}