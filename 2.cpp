#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>av[4];
    av[0].push_back(1);
    av[0].push_back(2);
    av[0].push_back(3);
    av[1].push_back(4);
    av[1].push_back(5);
    av[1].push_back(6);
    av[1].push_back(7);
    av[1].push_back(8);
    av[2].push_back(9);
    av[2].push_back(10);
    av[3].push_back(11);
    av[3].push_back(12);
    av[3].push_back(13);
    av[3].push_back(14);

    for(int i=0; i<4; i++){
        for(int j=0; j<av[i].size(); j++){
            cout<<av[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}