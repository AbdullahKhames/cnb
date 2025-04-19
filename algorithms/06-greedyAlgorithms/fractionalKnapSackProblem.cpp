#include "../main.h"
void merge(Item **arr, int start, int mid, int end) {
    int i, j, k;
    int leftArrsize = mid + 1 - start;
    int rightArrsize = end - mid;
    Item **leftArr = (Item **)malloc(leftArrsize * sizeof(Item*));
    Item **rightArr = (Item **)malloc(rightArrsize * sizeof(Item*));
    // cout << "sorting array" << endl;
    for (i = 0; i < leftArrsize; i++)
    {
        leftArr[i] = arr[i + start];
    }
    for (j = 0; j < rightArrsize; j++)
    {
        rightArr[j] = arr[j + mid + 1];
    }
    i = j = 0;
    k = start;
    while (i < leftArrsize && j < rightArrsize) 
    {
        if (leftArr[i]->ratio >= rightArr[j]->ratio )
        {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
        
    }
    while (i < leftArrsize) 
    {
        arr[k++] = leftArr[i++];  
    }
    while (j < rightArrsize) 
    {
        arr[k++] = rightArr[j++];  
    }
    free(leftArr);
    free(rightArr);

}
void sortItems(Item **arr, int start, int end) {
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        // cout << "mid == " << mid << endl;
        sortItems(arr, start, mid);
        sortItems(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    
}
void sortItems(Item **arr, int size) {
    sortItems(arr, 0, size - 1);
}
float fractionalKnapSackProblem(int *prices, int *weights, int size, int maxWeight) {
    float maxProfit = 0;
    float currentWeight = 0, allowedWeight;
    int i;
    Item **arr = (Item **) malloc(size * sizeof(Item *));
    for (i = 0; i < size; i++)
    {
        // cout << "initalizing pointer i == " << i  << endl;
        arr[i] = (Item *) malloc(sizeof(Item));
        arr[i]->index = i;
        arr[i]->price = prices[i];
        arr[i]->weight = weights[i];
        arr[i]->ratio = arr[i]->price / arr[i]->weight;
    }
    // for (i = 0; i < size; i++)
    // {
    //     cout << "prices before sorting " << arr[i]->price << endl;
    // }
    sortItems(arr, size);

    // for (i = 0; i < size; i++)
    // {
    //     cout << "sorted prices " << arr[i]->price << endl;
    // }
    
    i = 0;
    while (currentWeight < maxWeight)
    {
        if (arr[i]->weight > maxWeight - currentWeight) {
            allowedWeight = maxWeight - currentWeight;
            arr[i]->weight = allowedWeight;
            arr[i]->price = arr[i]->ratio * allowedWeight;
        }
        currentWeight += arr[i]->weight;
        maxProfit += arr[i]->price;
        i++;
    }
    for (i = 0; i < size; i++)
    {
        cout << arr[i]->index << " " << arr[i]->price << " " << arr[i]->weight << " " << arr[i]->ratio << endl;
    }

    for (i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
    cout << "maxProfit == " << maxProfit << endl; 
    return maxProfit;
}

void playWithFractionalKnapSack() {
    int prices[] = {4, 9, 12, 11, 6, 5};
    int weights[] = {1, 2, 10, 4, 3, 5};
    fractionalKnapSackProblem(prices, weights, 6, 12);
}
