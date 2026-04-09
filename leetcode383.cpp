//lrrtvofe383
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);

        // Count letters in magazine
        for (char c : magazine) {
            count[c - 'a']++;
        }

        // Check ransomNote
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};