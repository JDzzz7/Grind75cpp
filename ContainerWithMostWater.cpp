#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int currWater = 0;
        int start = 0;
        int end = height.size() - 1;

        while (start < end){
            int lowerBound = min(height[start], height[end]);
            maxWater = max(maxWater, lowerBound * (end-start));

            if (height[start] < height[end]){
                start++;
            }
            else
                end--;
        }
        return maxWater;
    }
};