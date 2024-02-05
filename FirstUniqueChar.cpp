#include <iostream> 
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> exist;

        for (int i  = 0; i < s.size(); i++){
            if (exist.find(s[i]) == exist.end()){
                exist.insert({s[i], 1});
            }
            else
                exist[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++){
            if (exist[s[i]] == 1)
                return i;
        }
        return -1;
    }
};