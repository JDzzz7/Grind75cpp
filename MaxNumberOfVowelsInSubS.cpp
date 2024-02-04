#include <iostream> 
#include <vector> 
#include <set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowels = 0;
        int currVowels = 0;
        set<char>vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < k; i++){
            if (vowels.find(s[i]) != vowels.end()){
                currVowels++;
            }
        }
        maxVowels = currVowels;
        for (int i = k; i < s.size(); i++){
            if (vowels.find(s[i]) != vowels.end()){
                currVowels++;
            }
            if (vowels.find(s[i-k]) != vowels.end()){
                currVowels--;
            }
            maxVowels = max(currVowels, maxVowels);
        }
        return maxVowels;
    }
};