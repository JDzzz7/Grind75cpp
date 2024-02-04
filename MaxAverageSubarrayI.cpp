#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // So window size would be k-1 in this case
        double currSum = 0;
        double maxSum = 0;
        for (int i = 0; i < k; i++){
            currSum += nums[i];
        }
        maxSum = currSum;

        for (int i = k; i < nums.size(); i++){
            currSum += (nums[i] - nums[i-k]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum/k;
    }
};