#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int bestBuy=0, maxProfit=0;
    int profit;
    for(int i=1; i<n; i++) {
       if(prices[i] > bestBuy)  maxProfit = max(profit,maxProfit);
       bestBuy = min(bestBuy,prices[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> nums = {5,4,3,2,1};
    cout << "Profit: " << maxProfit(nums);
}