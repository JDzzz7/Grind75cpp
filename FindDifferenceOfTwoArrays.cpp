#include <iostream> 
#include <vector> 
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Map;
        unordered_map<int, int> nums2Map;
        vector<vector<int>> answers(2);

        for (int i = 0; i < nums1.size(); i++){
            if (nums1Map.find(nums1[i]) == nums1Map.end())
                nums1Map.insert({nums1[i], 1});
            else 
                nums1Map[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++){
            if (nums2Map.find(nums2[i]) == nums2Map.end())
                nums2Map.insert({nums2[i], 1});
            else 
                nums2Map[nums2[i]]++;
        }

        for (int i = 0; i < nums1.size(); i++){
            if (nums2Map.find(nums1[i]) == nums2Map.end()){
                auto it = find(answers[0].begin(), answers[0].end(), nums1[i]);
                if (it == answers[0].end())
                    answers[0].push_back(nums1[i]);
            }
        }

        for (int i = 0; i < nums2.size(); i++){
            if (nums1Map.find(nums2[i]) == nums1Map.end()){
                auto ito = find(answers[1].begin(), answers[1].end(), nums2[i]);
                if (ito == answers[1].end())
                    answers[1].push_back(nums2[i]);
            }
        }
        return answers;
    }
};