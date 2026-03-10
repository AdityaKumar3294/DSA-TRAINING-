#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int p = 0;
        int length = arr.size();

        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k < length; ++k) {
                        if (abs(arr[j] - arr[k]) <= b &&
                            abs(arr[i] - arr[k]) <= c) {
                            p++;
                        }
                    }
                }
            }
        }

        return p;
    }
};