#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int>m;
        for (auto c:s) {
            m[c]++; //mappinng of string
        }
        for (auto c1:t) {
            if (m[c1] == 0) return false;
            m[c1]--;
        }
        return true;
    }
};