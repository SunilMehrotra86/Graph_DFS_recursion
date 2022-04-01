#include<iostream>
#include<map>
#include<list>
using namespace std;

template <typename T>
class Graph {
    map<T, list<T>> adjMatrix;

        void doTraverse(T srcNode,map<T, bool>& visited) {
        cout << "" << srcNode;
        visited[srcNode] = true;
        for (auto Iter : adjMatrix[srcNode]) {
            if(!visited[Iter])
                doTraverse(Iter,visited);
        }

    }
public:
    void InsertEdge(T arg1, T arg2) {
        adjMatrix[arg1].push_back(arg2);
        adjMatrix[arg2].push_back(arg1);
    }


       
    void DFS(T srcNode) {
        map<T, bool> visited;
        for (auto Iter : adjMatrix) {
            visited[Iter.first] = false;
        }
        doTraverse(srcNode, visited);


    }
};

int main()
{
    Graph<int> gf;
    gf.InsertEdge(1,2);
    gf.InsertEdge(2,4);
    gf.InsertEdge(1,3);
    gf.InsertEdge(3,5);
    gf.InsertEdge(4,5);
    gf.InsertEdge(5,7);
    gf.InsertEdge(5,6);
    gf.InsertEdge(1,4);
    gf.DFS(1);
    return 0;
}
