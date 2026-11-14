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

    cout<<"Enter the adjecency matrix: ";
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

void Graph::krushkal(){
    int minCost = 0;
    int edges = 0;
    int v,u,min;

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    cout<<"Road 1 - Road 2 : Cost."<<endl;
    while(edges<n-1){
        min = 999;
        u=-1;
        v=-1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }

        if(u==-1){
            cout<<"Graph is disconnected"<<endl;
            break;
        }

        int SetU = find(u);
        int SetV = find(v);

        if(SetU!=SetV){
            cout<<u+1<<" - "<<v+1<<" : "<<min<<endl;
            minCost += min;
            unite(SetU,SetV);
            edges++;
        }

        cost[u][v] = cost[v][u] = 999;
    }
    if(edges!=n-1){
        cout<<"Graph does not exist"<<endl;
    }else{
        cout<<"Total Cost : "<<minCost;
    }
}

int main(){
    Graph g;
    g.create();
    g.krushkal();
    return 0;
}