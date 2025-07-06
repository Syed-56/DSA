#include <iostream>
#include <vector>
using namespace std;

int containerWithMostWater(vector<int> height) {
    //container = diff b/w indexes * index with samller value
    int n = height.size();
    int left=0, right=n-1;
    int maxContainer=0, container;
    while(left<right) {
        container=0;
        int h = min(height[left],height[right]);
        int width = right-left;
        container = width * h;
        maxContainer = max(container,maxContainer);
        if(height[right] < height[left]) right--;
        else    left++;
    }
    return maxContainer;
}

int main() {
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << "Container with most Water = " << containerWithMostWater(arr);
}