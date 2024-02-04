#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0;
        int count = 0;
        int slow = 0;
        int curr = 0;

        for (auto it = nums.begin(); it != nums.end(); it++){
            if (*it == 0){
                count++;
            }
            else {
                curr++;
            }
            if (count > 1){
                if (nums[slow] == 1){
                    curr--;
                }
                if (nums[slow] == 0){
                    count--;
                }
                slow++; 
            }
            mx = max(curr, mx);
        }
        if (mx == nums.size())
            return mx-1;
        return mx;
    }
};