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
            cout << "Enter adjacency ID:" << i << endl;
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
    dfs(visited, v);
}

void Graph::dfs(int visited[], int v)
{
    Gnode *temp;
    temp = head[v]->next;
    cout << v;
    visited[v] = 1;
    while (temp != NULL)
    {
        if (!visited[temp->id])
        {
            cout << "--->";
            dfs(visited, temp->id);
        }
        temp = temp->next;
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
