#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        
        // Find max candies
        int maxCandies = 0;
        for (const auto& element : candies){
            maxCandies = max(maxCandies, element);
        }
        for (auto it = candies.begin(); it != candies.end(); it++){
            if ((*it + extraCandies) >= maxCandies){
                result.push_back(true);
            }
            else
                result.push_back(false);
        }
        return result;
    }
};