#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        
        vector<char> w1(word1.begin(), word1.end());
        vector<char> w2(word2.begin(), word2.end());
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        vector<int> sorted1;
        vector<int> sorted2;

        for (int i  = 0; i < word2.size(); i++){
            auto it = find(w1.begin(), w1.end(), word2[i]);
            if (it == w1.end())
                return false;
            if (m2.find(word2[i]) == m2.end())
                m2.insert({word2[i], 1});
            else
                m2[word2[i]]++;
        }
        for (int i  = 0; i < word1.size(); i++){
            auto it = find(w2.begin(), w2.end(), word1[i]);
            if (it == w2.end())
                return false;
            if (m1.find(word1[i]) == m1.end())
                m1.insert({word1[i], 1});
            else
                m1[word1[i]]++;
        }

        for (const auto& pair: m1){
            sorted1.push_back(pair.second);
        }
        for (const auto& pair: m2){
            sorted2.push_back(pair.second);
        }

        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());

        if (sorted1 == sorted2)
            return true;
        return false;
    }
};