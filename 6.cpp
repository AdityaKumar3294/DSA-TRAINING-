#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    queue<pair<int,int>> q;
    q.push({1,2});
    q.push({3,4});
    q.push({5,6});
    q.push({7,8});
    q.push({9,10});
    q.push({11,12});
    q.push({13,14});
    while(!q.empty()){
        pair<int,int> p;
        p = q.front();
        cout<<p.first<<" "<<p.second<<endl;
        q.pop();
    }
    return 0;
}
