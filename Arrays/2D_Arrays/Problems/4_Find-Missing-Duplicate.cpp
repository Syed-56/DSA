#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingandDuplicate(vector<vector<int>> matrix) {
    vector<int> nums;
    int rows = matrix.size(), cols = matrix[0].size();
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            nums.push_back(matrix[i][j]);
        }
    }

    int repeat, missing;
    int n = nums.size();
    unordered_set<int> s;

    for(int i=0; i<n; i++) {
        if(s.find(nums[i]) != s.end()) {
            repeat = nums[i];
            break;
        }
        s.insert(nums[i]);
    }
    cout << "Repeat: " << repeat << endl;

    int actualSum=0, gotSum = -repeat;
    for(int i=0; i<n; i++) {
        actualSum += i+1;
        gotSum += nums[i];
    }
    cout << "Actual Sum: " << actualSum << "\tGot Sum: " << gotSum << endl;
    missing = actualSum - gotSum;
    cout << "\nMissing = " << missing << endl;

    for(int i=0; i<n; i++)  nums.pop_back();
    nums.push_back(repeat);
    nums.push_back(missing);
    return nums;
}

int main() {
    vector<vector<int>> matrix = {
        {1,3},
        {2,2}
    };
    vector<int> missAndDouble = findMissingandDuplicate(matrix);
    for(int val:missAndDouble)   cout << val << " ";
}