#include <iostream>
#include <queue>
using namespace std;

class Student {
    public:
    string name;
    int id;
    Student() { name = ""; id = 0; }
    Student(string n, int i) { name = n; id = i; }
};

class Graph {
    int V;
    int** weightedMatrix;
    Student* nodes;

    public:
    Graph(int vertices) {
        V = vertices;
        weightedMatrix = new int*[V];
        nodes = new Student[V];
        for(int i=0; i<V; i++) {
            weightedMatrix[i] = new int[V];
            for(int j=0; j<V; j++) {
                weightedMatrix[i][j] = 0;
            }
        }
    }

    void setStudent(int idx, string name, int id) {
        nodes[idx] = Student(name, id);
    }

    void insertEdge(int src, int dest, int weight) {
        //for directed use only one
        weightedMatrix[src][dest] = weight;
        weightedMatrix[dest][src] = weight;
    }

    void deleteEdge(int src, int dest) {
        //for directed use only one
        weightedMatrix[src][dest] = 0;
        weightedMatrix[dest][src] = 0;
    }

    int minDistance(int dist[], bool visited[]) {
        int min = -1, minDist = INT_MAX;
        for(int i=0; i<V; i++) {
            if(!visited[i] && dist[i]<=minDist) {
                minDist = dist[i];
                min = i;
            }
        }
        return min;
    }  
    void dijkstra(int start) {
        int dist[V];
        bool visited[V] = {false};
        for(int i=0; i<V; i++)  dist[i] = INT_MAX;
        dist[start] = 0;

        for(int count=0; count<V-1; count++) {
            int u = minDistance(dist,visited);
            if(u==-1)   break;  //unreachable
            visited[u] = true;

            for(int v=0; v<V; v++) {
                int tempDist = dist[u] + weightedMatrix[u][v];
                if(!visited[v] && weightedMatrix[u][v] && tempDist < dist[v]) {
                    dist[v] = tempDist;
                }
            }
        }

        cout << "Shortest Distances from (" << nodes[start].name << "," << nodes[start].id << "):-\n";
        for(int i=0; i<V; i++) {
            cout << "(" << nodes[start].name << "," << nodes[start].id << ") = ";
            if(dist[i]==INT_MAX)    cout << "Infinity";
            else    cout << dist[i];
            cout << endl;
        }
    }  
};

int main() {
    Graph G(5);

    G.setStudent(0,"Syed Sultan Ahmed", 240585);
    G.setStudent(1,"Ali Kashif", 240802);
    G.setStudent(2,"Hammad Abdul Rahim", 240581);
    G.setStudent(3,"Ammar Mufti", 240586);
    G.setStudent(4,"Syed Ali Hussain", 240578);

    G.insertEdge(0,1,5);
    G.insertEdge(0,2,3);
    G.insertEdge(1,3,1);
    G.insertEdge(1,4,3);
    G.insertEdge(2,4,4);
    G.dijkstra(0);
}