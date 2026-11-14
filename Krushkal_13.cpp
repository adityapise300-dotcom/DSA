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

