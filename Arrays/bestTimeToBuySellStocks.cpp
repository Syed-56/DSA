#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int profit(vector<int> prices) {
    int n = prices.size();
    int maxProfit=0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int diff = prices[j]-prices[i];
            if(diff > maxProfit)  maxProfit = diff;
        }
    }
    return maxProfit;
}

int main() {
    vector<int> nums = {5,4,3,2,1};
    cout << "Profit: " << profit(nums);
}