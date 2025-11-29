#include <iostream>
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
    int** adjMatrix;
    Student* nodes;

    public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix = new int*[V];
        nodes = new Student[V];
        for(int i=0; i<V; i++) {
            adjMatrix[i] = new int[V];
            for(int j=0; j<V; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void setStudent(int idx, string name, int id) {
        nodes[idx] = Student(name, id);
    }

    void insertEdge(int src, int dest) {
        //for directed use only one
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void deleteEdge(int src, int dest) {
        //for directed use only one
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
    }

    void printAdjanceyMatrix() {
        cout << "Adjancey Matrix:-\n";
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Graph G(5);

    G.setStudent(0,"Syed Sultan Ahmed", 240585);
    G.setStudent(1,"Ali Kashif", 240802);
    G.setStudent(2,"Hammad Abdul Rahim", 240581);
    G.setStudent(3,"Ammar Mufti", 240586);
    G.setStudent(4,"Syed Ali Hussain", 240578);

    G.insertEdge(0, 1);
    G.insertEdge(0, 2);
    G.insertEdge(1, 3);
    G.insertEdge(1, 4);
    G.insertEdge(2, 4);
    G.printAdjanceyMatrix();
    G.deleteEdge(0,1);
    G.printAdjanceyMatrix();
}