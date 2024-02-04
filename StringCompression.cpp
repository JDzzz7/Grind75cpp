#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int i = 0;

        while (i < chars.size()){
            int count = 0;
            char letter = chars[i];
            
            while (i < chars.size() && letter == chars[i]){
                count++;
                i++;
            }
            chars[ans] = letter;
            ans++;

            if (count > 1){
                string num = to_string(count);
                for (const auto& n : num){
                    chars[ans] = n;
                    ans++;
                }
            }
        }
        return ans;
    }
};