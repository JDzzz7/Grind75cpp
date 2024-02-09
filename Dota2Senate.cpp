#include <iostream> 
#include <vector> 
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int n = senate.size();

        for (int i = 0; i < n; i++){
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()){
            n++;
            if (radiant.front() < dire.front()){
                radiant.pop();
                dire.pop();
                radiant.push(n);
            }
            else {
                dire.pop();
                radiant.pop();
                dire.push(n);
            }
        }
        if (radiant.empty()){
            return "Dire";
        }
        return "Radiant";
    }
};