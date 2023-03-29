#include <iostream>
using namespace std;

class Graph
{
private:
    int num;
    int cost[10][10];

public:
    void createGraph();
    void displayCostMatrix();
};
void Graph::createGraph()
{
    cout << "Enter the number of vertices:";
    cin >> num;

    int i, j, costVal;
    cout << "Enter i, j and cost for each edge (separated by spaces):" << endl;
    cout << "(enter -1 -1 -1 to exit)" << endl;

    for (int x = 0; x < num; x++)
    {
        for (int y = 0; y < num; y++)
        {
            cost[x][y] = 999;
        }
    }

    while (true)
    {
        cin >> i >> j >> costVal;
        if (i == -1 && j == -1 && costVal == -1)
        {
            break;
        }

        cost[i][j] = costVal;
        cost[j][i] = costVal;
    }
}

void Graph::displayCostMatrix()
{
    cout << "The entered cost matrix is:\n";
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                cout << "0 ";
            }
            else if (cost[i][j] != 999)
            {
                cout << cost[i][j] << " ";
            }
            else
            {
                cout << "999 ";
            }
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