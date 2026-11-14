#include<iostream>
using namespace std;
#define MAX 20

class Graph{
    int cost[MAX][MAX];
    int parent[MAX];
    int n;
    public:
        void create();
        int find(int v);
        void unite(int u, int v);
        void krushkal();
};

void Graph::create(){
    cout<<"Enter the number of cites: "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(i!=j&&cost[i][j]==0){
                cost[i][j]=99;
            }
        }
    }
}

int Graph::find(int v){
    while(parent[v]!=v){
        v = parent[v];
    }
    return v;
}

void Graph::unite(int u,int v){
    parent[u] = v;
}

