#include <iostream>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int length = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L')
                count++;
            else
                count--;

            if (count == 0) {
                length++;
            }
        }
        return length;
    }
};