#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0;

        for (auto it = nums.begin(); it != nums.end(); it++){
            if (*it == 0){
                k--;
            }
            if (k < 0){
                if (nums[j] == 0){
                    k++;
                }
                j++;
            }
        }
        return nums.size()-j;
    }
};