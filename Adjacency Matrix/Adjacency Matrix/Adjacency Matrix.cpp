

#include <iostream>
using namespace std;

class Graph {
    int noVertices;
    int** matrix;

public:
    Graph(int nodes) {
        noVertices = nodes;
        matrix = new int*[nodes];
        for (int i = 0; i < nodes; i++) {
            matrix[i] = new int[nodes];
            for (int j = 0; j < nodes; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    int getNoVertices() {
        return noVertices;
    }

    void addNodes(int node1, int node2) {
        if (!(node1 >= 0 && node2 >= 0 && node1 < noVertices && node2 < noVertices)) {
            cout << "Invalide nodes" << endl;
            return;
        }
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
    }

    void displayNodeEdges() {
        for (int i = 0; i < noVertices; i++) {
            for (int j = 0; j < noVertices; j++) {
                /*if (matrix[i][j] == 0) continue;*/
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void removeNode(int node1, int node2) {
        if (!(node1 >= 0 && node2 >= 0 && node1 < noVertices && node2 < noVertices)) {
            cout << "Invalide nodes" << endl;
            return;
        }
        matrix[node1][node2] = 0;
        matrix[node2][node1] = 0;
    }

};

int main()
{
    std::cout << "------------- Graph -----------------"<<endl<<endl;

    Graph graph(4);
    graph.displayNodeEdges();
    graph.addNodes(0, 3);
    graph.addNodes(1, 2);
    graph.addNodes(4, 0);
    graph.addNodes(2, 3);
    graph.removeNode(0, 3);
    graph.displayNodeEdges();
}
