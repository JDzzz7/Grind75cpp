#include <iostream> 
#include <vector> 
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> letterStack;
        string result;
        int num = 0;

        for (const auto& c : s){
            if (isalpha(c)){
                result += c;
            }
            if (isdigit(c)){
                num = num * 10 + (c - '0');
            }
            if (c == '['){
                numStack.push(num);
                letterStack.push(result);
                num = 0;
                result = "";
            }
            if (c == ']'){
                int prev_int = numStack.top();
                numStack.pop();
                string prev_s = letterStack.top();
                letterStack.pop();
                for (int i = 0; i < prev_int; i++){
                    prev_s += result;
                }
                result = prev_s;
            }
        }
        return result;
    }
};