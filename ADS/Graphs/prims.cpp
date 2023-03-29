#include <iostream>
using namespace std;

class Graph
{
private:
    int num;
    int cost[10][10];
    int nearest[10];
    int minimumSpanningTree[10][2];

public:
    void createGraph();
    void displayCostMatrix();
};

void Graph::createGraph()
{
    cout << "Enter the number of vertices:";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            char choice;
            if (i == j)
            {
                cost[i][j] = 0;
                continue;
            }
            cout << "Is " << i << " and " << j << " connected (y, n): ";
            cin >> choice;
            if (choice == 'n')
            {
                cost[i][j] = 999;
                continue;
            }
            cout << "Enter the cost between " << i << " and " << j << ":";
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }
}

void Graph::displayCostMatrix()
{
    cout << "The entered cost matrix is:\n";
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Graph g;
    g.createGraph();
    g.displayCostMatrix();
    return 0;
}