#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frequency;
        string result;

        for (const auto& c : s){
            if (frequency.find(c) == frequency.end())
                frequency.insert({c, 1});
            else
                frequency[c] += 1;
        }
        vector<pair<char, int>> sortedMap(frequency.begin(), frequency.end());

        auto compare = [](const auto& pair1, const auto& pair2){
            return pair1.second > pair2.second;
        };
        sort(sortedMap.begin(), sortedMap.end(), compare);

        for (const auto& pair : sortedMap){
            for (int i = 0; i < pair.second; i++){
                result += pair.first;
            }
        }
        return result;
    }
};