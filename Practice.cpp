#include<iostream>
using namespace std;
#define M 20

class Tree{
    int cost[M][M];
    int parent[M];
    int n;
    public:
        void create();
        int find(int v);
        void unite(int u,int v);
        void krushkal();
};

void Tree :: create(){
    cout<<"Enter the number of cities: ";
    cin>>n;
    cout<<"\nEnter the adjecency matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(i!=j&&cost[i][j]==0){
                cost[i][j] = 99;
            }
        }
    }
}

int Tree::find(int v){
    while(parent[v]!=v){
        v = parent[v];
    }
    return v;
}

void Tree::unite(int u,int v){
    parent[u] = v;
}

void Tree::krushkal(){
    int minCost = 0;
    int edges = 0;
    int u,v,min;

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    cout<<"\nMinimum Cost Calculation";
    cout<<"\nRoad1 - Road2 : Cost"<<endl;

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
        cout<<"Graph Does not exist"<<endl;
        return;
    }else{
        cout<<"Total Cost = "<<minCost<<endl;
    }
}

int main(){
    Tree T;
    T.create();
    T.krushkal();
    return 0;
}