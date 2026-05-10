#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 0;
        vector<int> ans(n,0);
        for(int i = n-1; i>=0; i--){
            if(nums[i]%2){
                odd++;
                ans[i]=even;
            }else{
                even++;
                ans[i] = odd;
            }
        }
        return ans;
    }
};