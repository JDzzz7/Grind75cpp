#include <iostream> 
#include <vector> 
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> astStack;

        for (const auto& ast : asteroids){
            bool destroy = false;
            if (ast > 0){
                astStack.push(ast);
            }
            else {
                if (astStack.empty() || astStack.top() < 0){
                    astStack.push(ast);
                }
                else {
                    while (!astStack.empty() && astStack.top() > 0){
                        if (abs(ast) == astStack.top()){
                            destroy = true;
                            astStack.pop();
                            break;
                        }
                        else if (abs(ast) > astStack.top())
                            astStack.pop();
                        else {
                            destroy = true;
                            break;
                        }
                    }
                    if (!destroy)
                        astStack.push(ast);
                }
            }
        }
        vector<int> reverse;
        while (!astStack.empty()){
            reverse.push_back(astStack.top());
            astStack.pop();
        }
        vector<int> result;
        for (int i = reverse.size()-1; i >= 0; i--)
            result.push_back(reverse[i]);
        return result;
    }
};