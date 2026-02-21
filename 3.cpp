#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,E;
    cout<<"Enter the number of vertices: ";
    cin>>N;
    cout<<"Enter the number of edges: ";
    cin>>E;
    vector<vector<int>> AdjList(N);

    for(int i=1; i<=E; i++){
        int a,b;
        cout<<"Enter the end points of edges: "<<i;
        cin>>a>>b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    for (int i=0; i<N; i++){
        cout<<i<<": ";
        for(int j=0; j<AdjList[i].size(); j++){
            cout<<AdjList[i][j]<<", ";
        }
        cout<<"\n"; 
    }
    
}