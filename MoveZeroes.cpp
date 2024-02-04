#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int anchor = 0;

        for (int move = 0; move < nums.size(); move++){
            if (nums[move] != 0){
                swap(nums[move], nums[anchor]);
                anchor++;
            }
        }
    }
};