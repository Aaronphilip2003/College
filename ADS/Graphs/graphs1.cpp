#include <iostream>
#include <string.h>
using namespace std;
class Gnode
{
    int id;
    char name[100];
    Gnode *next;
    friend class Graph;
};

class Graph
{
private:
    Gnode *head[20];
    int n;

public:
    Graph()
    {
        n = 0;
        cout << "Enter total people on the network initially:" << endl;
        cin >> n;
        for (int id = 0; id < n; id++)
        {
            head[id] = new Gnode;
            head[id]->id = id;
            head[id]->next = NULL;
        }
    }
    void create();
    void display();
    void dfs();
    void dfs(int visited[], int v);
    void prims();
};

void Graph::create()
{
    Gnode *temp, *curr;
    char ch;
    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        do
        {
            int v;
            char name[20];
            cout << "Enter adjacency ID:" << endl;
            cin >> v;
            cout << "Enter name of friend: " << endl;
            cin >> name;
            if (v == i)
            {
                cout << "ID is already present(Self-Loops are not allowed)!" << endl;
            }
            else
            {
                curr = new Gnode;
                curr->id = v;
                strcpy(curr->name, name);
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Do you want to continue (y/n):";
            cin >> ch;
        } while (ch == 'y');
    }
}

void Graph::display()
{
    Gnode *temp;
    int id;
    for (id = 0; id < n; id++)
    {
        temp = head[id]->next;
        // cout << head[id]->id << endl;
        while (temp != NULL)
        {
            // cout << temp->id << ":" << temp->name << "--->";
            if (temp->next != NULL)
            {
                cout << temp->name << "--->";
                temp = temp->next;
            }
            else
            {
                cout << temp->name << endl;
                temp = temp->next;
            }
        }
        cout << endl;
    }
}

void Graph::dfs()
{
    int v;
    int visited[10];
    for (int id = 0; id < n; id++)
    {
        visited[id] = 0;
    }
    cout << "Enter the starting id:" << endl;
    cin >> v;
    cout << "Traversal:" << endl;
    dfs(visited, v);
}

void Graph::dfs(int visited[], int v)
{
    Gnode *temp;
    temp = head[v]->next;
    visited[v] = 1;
    cout << head[v]->id << " "; // print the name of the current node
    while (temp != NULL)
    {
        if (!visited[temp->id])
        {
            dfs(visited, temp->id);
        }
        temp = temp->next;
    }
}

void Graph::prims()
{
    int mstSet[n];
    int key[n];
    for (int i = 0; i < n; i++)
    {
        mstSet[i] = 0;
        key[i] = 1000;
    }

    key[0] = 0;
    int parent[n];
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int minKey = 1000, minIndex;
        for (int i = 0; i < n; i++)
        {
            if (mstSet[i] == 0 && key[i] < minKey)
            {
                minKey = key[i];
                minIndex = i;
            }
        }

        mstSet[minIndex] = 1;

        Gnode *temp;
        temp = head[minIndex]->next;
        while (temp != NULL)
        {
            int adjNode = temp->id;
            int weight = 1;
            if (mstSet[adjNode] == 0 && weight < key[adjNode])
            {
                parent[adjNode] = minIndex;
                key[adjNode] = weight;
            }
            temp = temp->next;
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    Graph g;
    g.create();
    cout << "The graph is:" << endl;
    g.display();
    cout << "DFS traversal:" << endl;
    g.dfs();
    return 0;
}
