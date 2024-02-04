#include <iostream> 
#include <vector> 
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        while (ss >> s){
            words.push_back(s);
        }
        int start = 0;
        int end = words.size()-1;

        while (start < end){
            swap(words[start], words[end]);
            start++;
            end--;
        }

        string result = "";

        for (int i = 0; i < words.size(); i++){
            result += words[i];
            if (i < words.size()-1)
                result += " ";
        }
        return result;
    }
};