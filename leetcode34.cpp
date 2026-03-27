#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int findfirst(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                ans = mid;
                right = mid - 1; // go left and check 
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
           
        }

        return ans;
    };

    int findlast(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                ans = mid;
                left = mid + 1; // go right and check 
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
         }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return{findfirst(nums,target) , findlast(nums,target)};
    }
};