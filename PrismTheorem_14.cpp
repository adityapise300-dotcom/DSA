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

