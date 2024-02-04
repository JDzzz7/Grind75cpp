#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sumLeft(nums.size());
        vector<int> sumRight(nums.size());

        // Sum of all integers to the right
        for (int i = nums.size()-1; i >= 0; i--){
            if (i == nums.size()-1)
                sumRight[i] = 0;
            else {
                sumRight[i] = sumRight[i+1] + nums[i+1];
            }
        }

        // Sum of all integers to the left
        for (int i = 0; i < nums.size(); i++){
            if (i == 0)
                sumLeft[i] = 0;
            else {
                sumLeft[i] = sumLeft[i-1] + nums[i-1];
            }
        }

        // Check if sumLeft[i] = sumRight[i] if not return -1
        for (int i = 0; i < nums.size(); i++){
            if (sumLeft[i] == sumRight[i])
                return i;
        }
        return -1;

    }
};

int main(){
    Solution result;
    vector<int> nums = {1,7,3,6,5,6};
    int answer = result.pivotIndex(nums);
    cout << "Solution: " << answer << endl;
    return 0;
}