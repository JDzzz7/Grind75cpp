#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int stand = 0;
        int num = s.size();

        if (s.size() == 0)
            return true;

        for (int run = 0; run < t.size(); run++){
            if (t[run] == s[stand]){
                num--;
                stand++;
            }
            if (num == 0)
                return true;
        }
        return false;
    }
};