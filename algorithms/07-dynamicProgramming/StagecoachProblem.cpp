#include "../main.h"


int StagecoachProblem() {
    int cost, minCost;
    int matrix[10][10];
    int n = 10;
    char firstChar = 'A';
    char lastChar = 'J';
    StageCoach totalCostMemoization[10]; 
    char lables [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 
    for (int j = 0; j < 10; j++)
    {
        totalCostMemoization[j] = StageCoach(0);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    matrix[0][1] = 2;
    matrix[0][2] = 4;
    matrix[0][3] = 3;
    matrix[1][4] = 7;
    matrix[1][5] = 4;
    matrix[1][6] = 6;
    matrix[2][4] = 3;
    matrix[2][5] = 2;
    matrix[2][6] = 4;
    matrix[3][4] = 4;
    matrix[3][5] = 1;
    matrix[3][6] = 5;
    matrix[4][7] = 1;
    matrix[4][8] = 4;
    matrix[5][7] = 6;
    matrix[5][8] = 3;
    matrix[6][7] = 3;
    matrix[6][8] = 3;
    matrix[7][9] = 3;
    matrix[8][9] = 4;

    for (int i = n - 2; i >= 0; i--)
    {
        totalCostMemoization[i].cost = INT_MAX;
        totalCostMemoization[i].from = lables[i];
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                continue;
            }
            cost = (matrix[i][j]) + totalCostMemoization[j].cost;
            if (cost < totalCostMemoization[i].cost)
            {
                totalCostMemoization[i].to = lables[j];
                totalCostMemoization[i].cost = cost;
            }
        }
    }
    
    // for (int j = 0; j < n; j++)
    // {
    //     cout << "from : " << totalCostMemoization[j].from << " to : " << totalCostMemoization[j].to << " cost : " << totalCostMemoization[j].cost << endl ;
    // }
    
    for (int j = 0; j < n; j++)
    {
        if (totalCostMemoization[j].from == firstChar)
        {
            cout << firstChar << " -> ";
            firstChar = totalCostMemoization[j].to;
        }
    }
    cout << lastChar  << " total cost to travel is : " << totalCostMemoization[0].cost << endl;
    return totalCostMemoization[0].cost;
}
