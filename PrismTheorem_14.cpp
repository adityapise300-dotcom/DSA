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

