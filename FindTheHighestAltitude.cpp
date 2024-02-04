#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int sum = 0;
        
        for (auto it = gain.begin(); it != gain.end(); it++){
            sum += *it;
            mx = max(sum, mx);
        }
        if (mx < 0)
            return 0;
        return mx;
    }
};