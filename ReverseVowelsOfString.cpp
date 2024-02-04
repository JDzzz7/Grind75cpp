#include <iostream> 
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> str(s.begin(), s.end());
        int start = 0;
        int end = s.size()-1;

        while (start < end){
            while (start < end && vowels.find(s[start]) == vowels.end()){
                start++;
            }
            while (start < end && vowels.find(s[end]) == vowels.end()){
                end--;
            }
            str[start] = s[end];
            str[end] = s[start];
            start++;
            end--;
        }
        string result(str.begin(), str.end());
        return result;
    }
};