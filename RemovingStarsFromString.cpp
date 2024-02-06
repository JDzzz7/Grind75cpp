#include <iostream> 
#include <vector> 
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        // Stack - FIFO
        stack<char> stackChar;

        for (auto it = s.begin(); it != s.end(); it++){
            if (*it == '*'){
                stackChar.pop();
            }
            else
                stackChar.push(*it);
        }
        vector<char> temp;
        while (!stackChar.empty()){
            temp.push_back(stackChar.top());
            stackChar.pop();
        }

        string result;
        for (int i = temp.size()-1; i >= 0; i--){
            result += temp[i];
        }
        return result;
    }
};