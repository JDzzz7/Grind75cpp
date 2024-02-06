#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> anagrams;

        for (int i = 0; i < strs.size(); i++){
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(i);
        }

        for (const auto& pair : anagrams){
            vector<string> group;
            for (const auto& index : pair.second){
                group.push_back(strs[index]);
            }
            result.push_back(group);
        }
        return result;
    }
};