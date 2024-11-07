#include "main.h"

int main() {
    int start[] = {9, 10, 11, 12, 13, 15};
    int end[] = {11, 11, 12, 14, 15, 16};

    int *arr = activityselectionAlgo(start, end, 6);
    printArr(arr, 6);
    return (0);
}
