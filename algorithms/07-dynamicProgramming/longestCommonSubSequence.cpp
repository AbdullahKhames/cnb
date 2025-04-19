#include "../main.h"

int longestCommonSubsequence(string text1, string text2) {
    // text 2 is the rows and text 1 is the columns!
    int i,j;
    int rows = text2.length() + 1;
    int cols = text1.length() + 1;
    int table[rows][cols];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            table[i][j] = 0;
        }
    }
    for (i = 1; i < rows; i++)
    {
        for (j = 1; j < cols; j++)
        {
            if (text2[i - 1] != text1[j - 1])
            {
                // if not match set to the max of top and left nodes
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            } else {
                // if match add  to the top left node
                table[i][j] = 1 + table[i - 1][j - 1];
            }
        }
    }

    // for (i = 0; i < rows; i++)
    // {
    //     for (j = 0; j < cols; j++)
    //     {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    string result = "";

    i = rows - 1;
    j = cols - 1;
    while (i > 0 && j > 0 )
    {
        if (table[i][j] > table[i][j - 1])
        {
            // if current value is more than its left value
            if (table[i][j] == table[i - 1][j])
            {
                // if current value is equal to its top vale that means it is inherited form it
                i--;
            } else {
                // if flow control comes here that means it is the origin of matching!
                result = text2[i - 1] + result;
                i--;
                j--;
            }
            
        } else {
            // if current value is not bigger than its left value
            j--;
        }
    }

    cout << "result is " << result << endl; 
    return result.length();
    
}
