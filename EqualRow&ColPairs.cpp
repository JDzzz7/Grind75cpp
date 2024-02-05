#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> cmp(grid.size());
        int j = 0;

        while (j < grid.size()){
            for (int i = 0; i < grid.size(); i++){
                cmp[j].push_back(grid[i][j]);
            }
            j++;
        }

        int counter = 0;
        for (int i = 0; i < cmp.size(); i++){
            for (int j = 0; j < cmp.size(); j++){
                if (cmp[i] == grid[j])
                    counter++;
            }
        }
        return counter;
    }
};