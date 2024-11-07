#include "../main.h"

int* activityselectionAlgo(int *start, int *end, int size) {
    int i = 1;
    int j = 0;
    int k = 0;
    int *arr = new int[size]{0};
    arr[k++] = 0;

    while (i < size)
    {
        if (start[i] >= end[j])
        {
            arr[k++] = i;
            j = i;
        }
        i++;
    }
    
    return arr;
}
// int main() {
//     int start[] = {9, 10, 11, 12, 13, 15};
//     int end[] = {11, 11, 12, 14, 15, 16};

//     int *arr = activityselectionAlgo(start, end, 6);
//     printArr(arr, 6);
//     return (0);
// }
