#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingandDuplicate(vector<vector<int>> matrix) {

}

int main() {
    vector<vector<int>> matrix = {
        {1,3},
        {2,2}
    };
    vector<int> missAndDouble = findMissingandDuplicate(matrix);
    for(int val:missAndDouble)   cout << val << " ";
}