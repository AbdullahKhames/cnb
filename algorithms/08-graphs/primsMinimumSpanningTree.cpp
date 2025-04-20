#include "../main.h"

void primsMST() {
    int size = 6;
    char labels[] = {'1', '2', '3', '4', '5', '6'};
    double graph[][size] = {
        {0, 6.7, 5.2, 2.8, 5.6, 3.6},
        {6.7, 0, 5.7, 7.3, 5.1, 3.2},
        {5.2, 5.7, 0, 3.4, 8.5, 4.0},
        {2.8, 7.3, 3.4, 0, 8, 4.4},
        {5.6, 5.1, 8.5, 8, 0, 4.6},  
        {3.6, 3.2, 4, 4.4, 4.6, 0}
    };
  
    int selected_edges_count = 0;
    bool selected[size] = {false};
    selected[0] = true;
    while (selected_edges_count < size - 1)
    {
        double min = INT_MAX;
        int from = -1;
        int to = -1;
        for (int i = 0; i < size; i++)
        {
            if (selected[i] == true)
            {
                for (int j = 0; j < size; j++)
                {
                    if (selected[j] == false &&
                        graph[i][j] < min &&
                        graph[i][j] > 0)
                    {
                        min = graph[i][j];
                        from = i;
                        to = j;
                    }
                    
                }
            }
        }
        selected_edges_count++;
        selected[to] = true;

        cout << labels[from] << " - " << labels[to] << " : "
        << graph[from][to] << endl;
    }
    
  
}
