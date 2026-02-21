#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1,v2,v3,v4;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v3.push_back(9);
    v3.push_back(10);
    v4.push_back(11);
    v4.push_back(12);
    v4.push_back(13);
    v4.push_back(14);

    vector<vector<int>>vv;

    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    
    for(int i=0; i<4; i++){
        for(int j=0; j<vv[i].size(); j++){
            cout<<vv[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}