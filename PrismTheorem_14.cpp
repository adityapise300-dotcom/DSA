#include<iostream>
using namespace std;
#define M 20
#define INF 999

class Tree{
    int cost[M][M];
    int n;
    public:
        void create();
        void Prims();
};

void Tree :: create(){
    cout<<"Enter the number of cities: ";
    cin>>n;
    cout<<"\nEnter the adjecency matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(i!=j&&cost[i][j]==0){
                cost[i][j] = INF;
            }
        }
    }
}

void Tree::Prims(){
    int minCost = 0;
    int edges = 0;
    int visited[M] = {0};

    visited[0] = 1;

    cout<<"\nMinimum Cost Calculation";
    cout<<"\nRoad1 - Road2 : Cost"<<endl;

    while(edges<n-1){
        int min = INF;
        int u=-1;
        int v=-1;

        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=i+1;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min = cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        if(u==-1){
            cout<<"Graph is disconnected"<<endl;
            break;
        }

        cout<<u+1<<" - "<<v+1<<" : "<<min<<endl;
        minCost += min;
        visited[v] = 1;
        edges++;
    }
     cout<<"Total Cost = "<<minCost<<endl;
}

int main(){
    Tree T;
    T.create();
    T.Prims();
    return 0;
}