

#include <iostream>
using namespace std;

class GraphNode {

public:
    int val;
    GraphNode* next;

    GraphNode(int node) {
        val = node;
        next = nullptr;
    }
};

class Graph {
    GraphNode** graph;
    int nodes;
public:
    Graph(int num) {
        nodes = num;
        graph = new GraphNode * [num];
        for (int i = 0; i < num; i++) {
            graph[i] = new GraphNode(i);
        }
    }

    void addNode(int node1, int node2) {
        if (!(node1 >= 0 && node1 < nodes && node2 >= 0 && node2 < nodes && node1 != node2)) {
            cout << "Invalide Node "<<node1<<" "<<node2 << endl;
            return;
        }
        GraphNode* temp = graph[node1];
        while (temp->next != nullptr && temp->next->val != node2 && temp->next->val < node2) {
            temp = temp->next;
        }
        if (temp->next != nullptr && (temp->next->val == node2)) {
            cout << node2 << " is already add in list" << endl;
            return;
        }
        GraphNode* node = temp->next;
        temp->next = new GraphNode(node2);
        temp->next->next = node;
    }

    void removeNode(int node1, int node2) {

        if (node1 < 0 && node1 >= nodes && node2 < 0 && node2 >= nodes) {
            cout << "Invalide Node " << endl;
        }
        GraphNode* temp = graph[node1];
        while (temp != nullptr) {
            if (temp->next->val == node2)break;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "The node " << node1 << " is not connected to the " << node2 << endl;
            return;
        }
        GraphNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

    }

    void display() {

        for (int i = 0; i < nodes; i++) {
            GraphNode* temp = graph[i];
            while (temp != nullptr) {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout << "null" << endl;
        }
    }
};

int main()
{
    std::cout <<"------------ directed graph adjecency list --------------"<<endl<<endl;

    Graph graph(4);
    graph.display();
    cout << " After Addition Of Value" << endl;
    graph.addNode(0, 3);
    graph.addNode(1, 3);
    graph.addNode(0, 2);
    graph.addNode(2, 1);
    graph.addNode(2, 0);
    graph.addNode(0, 5);
    graph.addNode(3, 3);
    graph.addNode(3, 1);
    graph.addNode(3, 1);
    graph.display();

}

