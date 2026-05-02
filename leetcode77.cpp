#include <iostream>
#include <vector>
using namespace std;
class Solution {
private :
    vector<vector<int>> ans;
    void backTrack(int idx, int k, vector<int>&curr, int n) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i=idx; i<=n; i++) {
            curr.push_back(i);
            backTrack(i+1, k, curr, n);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backTrack(1, k, curr, n);
        return ans;
    }
};