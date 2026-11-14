#include<iostream>
using namespace std;
#define MAX 20
#define INF 99

class Graph{
    int cost[MAX][MAX];
    int n;
    public:
        void Create();
        void Prims();
};

void Graph::Create(){
    cout<<"Enter the number of cities: ";
    cin>>n;

    cout<<"Enter the adjecency matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(i!=j&&cost[i][j]==0){
                cost[i][j] = INF;
            }
        }
    }
}

void Graph::Prims(){
    int minCost = 0;
    int edges = 0;
    int visited[MAX] = {0};

    visited[0] = 1;

    while(edges<n-1){
        int min = INF;
        int u = -1;
        int v = -1;

        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u==-1){
            cout<<"Graph is disconnected"<<endl;
            return;
        }

        cout<<u+1<<" - "<<v+1<<" : "<<min<<endl;
        minCost += min;
        visited[v] = 1;
        edges++;
    }

    cout<<"Total cost is : "<<minCost<<endl;
}

int main(){
    Graph g;
    g.Create();
    g.Prims();
    return 0;
}