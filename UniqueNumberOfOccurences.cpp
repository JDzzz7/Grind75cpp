#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> unique;
        unordered_set<int> uniqueS;

        for (const auto& i : arr){
            if (unique.find(i) == unique.end()){
                unique.insert({i, 1});
            }
            else {
                unique[i]++;
            }
        }
        for (const auto& pair : unique){
            if (uniqueS.find(pair.second) == uniqueS.end())
                uniqueS.insert(pair.second);
            else
                return false;
        }
        return true;
    }
};