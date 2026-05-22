#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string rec(string &s, int n){
        if(n==0) return s;
        string temp="";
        int z=s.size();
        int low=0,high=0;
        int cnt=0;
        while(high<z){
            if(s[high]!=s[low]){
                string s2=to_string(cnt);
                temp+=s2;
                temp.push_back(s[low]);
                cnt=0;
                low=high;
            }
            else{
                cnt++;
                high++;
            }
        }
        string s2=to_string(cnt);
        temp+=s2;
        temp.push_back(s[low]);
        return rec(temp,n-1);
    }
    string countAndSay(int n) {
        string base="1";
        return rec(base,n-1);
    }
};