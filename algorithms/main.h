#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct SampleData{
    float *data;
    float average;
    int size;
}SampleData;

// typedef struct StringNode{
//     string data;
//     StringNode *next;
// }StringNode;

// StringNode* createStringLinkedList(string data);
// StringNode* addToStringLinkedList(StringNode* head, string data);
// StringNode* getFromStringLinkedList(StringNode* head, int index);
// StringNode* deleteFromStringLinkedList(StringNode* head, int index);
// void printStringLinkedList(StringNode* head);

float calculateTrapezoidArea();
float calculateParllelogramArea();
float calculateCircleArea();
SampleData* createSampleData(int size);
SampleData** createSampleDataArr(int size);
float calculateCoefficient(SampleData *firstSample, SampleData *secondSample);
float calculateCorrelationCoefficient();
float* createArr(int arrSize);
float calculateMean(float *arr, int arrSize);
float calculateNextIter(float x, float mean);
float calculateTopTerm(float *arr, int arrSize, float mean);
float standardDeviation();
void printArr(int *arr, int n);
int* createIntArr(int n);
void insertionSort(int *arr, int n);
void merge(int *arr, int start, int mid, int end);
void mergeSort(int *arr, int start, int end);
int binarySearch(int arr[], int n, int target);
void swap(int *arr, int x, int y );
void segregate1(int *arr, int n);
void segregateWithMerge(int *arr, int start, int mid, int end);
void segregate(int *arr, int start, int end);
int* activityselectionAlgo(int *start, int *end, int size);
#include "utils/linkedList.h"
#endif
