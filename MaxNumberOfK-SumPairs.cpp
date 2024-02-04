#include <iostream> 
#include <vector> 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int totalOp = 0;

        sort(nums.begin(), nums.end());

        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum == k){
                totalOp++;
                left++;
                right--;
                continue;
            }
            if (sum < k){
                left++;
                continue;
            }
            if (sum > k){
                right--;
                continue;
            }   
        }
        return totalOp;
    }
};
