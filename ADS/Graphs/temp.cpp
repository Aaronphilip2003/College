#include <iostream>
using namespace std;
class gnode
{
    int id;
    char name[20];          
    gnode *next;
    friend class graph;
};
class graph
{
private:
    gnode *head[20];
    int n;

public:
    graph()
    {
        n = 0;
        cout << "Enter number of friends: ";
        cin >> n;
        for (int id = 0; id < n; id++)
        {
            head[id] = new gnode;
            head[id]->id = id;
            head[id]->next = NULL;
        }
    }
    void create();
    void display();
    void dfs();
    void dfs(int visited[], int v);
};
void graph::create()
{
    gnode *temp, *curr;
    char choice;
    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        do
        {
            int v;
            cout << "Enter adjacent ID: " << i << endl;
            cin >> v;
            if (v == i)
            {
                cout << "Self loops are not allowed" << endl;
            }
            else
            {
                curr = new gnode;
                curr->id = v;
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Do you want to continue (y/n)?";
            cin >> choice;
        } while (choice == 'y');
    }
}
void graph::display()
{
    gnode *temp;
    int id;
    for (int id = 0; id < n; id++)
    {
        temp = head[id]->next;
        cout << head[id]->id << "->";
        while (temp != NULL)
        {
            cout << temp->id;
            cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
}
void graph::dfs()
{
    int v;
    int visited[10];
    for (int id = 0; id < n; id++)
    {
        visited[id] = 0;
    }
    cout << "Enter the starting ID: " << endl;
    cin >> v;
    dfs(visited, v);
}
void graph::dfs(int visited[], int v)
{
    gnode *temp;
    temp = head[v]->next;
    cout << v;
    visited[v] = 1;
    while (temp != NULL)
    {
        if (!visited[temp->id])
        {
        }
    }
}
int main()
{
    graph g;
    g.create();
    g.display();
}
    