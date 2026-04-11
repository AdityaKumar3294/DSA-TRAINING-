#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (k <= 0 || k > q.size()) return q;

        stack<int> s;

        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        int t = q.size() - k;
        while (t--) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
