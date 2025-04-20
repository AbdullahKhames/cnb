#ifndef MAIN_H
#define MAIN_H
#include <climits>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace std;

typedef struct SampleData{
    float *data;
    float average;
    int size;
}SampleData;

typedef struct StringNode{
    string data;
    StringNode *next;
}StringNode;

template <typename T>
struct Node {
    T data;
    Node* next;
};

const long int ARRAY_SIZE = 1024;

struct StringHashtableItem {
    const char* key;
    const char* value;
};
struct StringHashtable {
    Node<StringHashtableItem*> **array;
    long int size;
    int count;
};

template <typename KeyType, typename ValueType>
struct HashtableItem {
    KeyType key;
    ValueType value;
};

template <typename KeyType, typename ValueType>
struct Hashtable {
    Node<HashtableItem<KeyType, ValueType>*> **array;
    long int size;
    int count;
};
class StageCoach {
    public:
        char from;
        char to;
        int cost;
    
        StageCoach() : from(0), to(0), cost(0) {}
    
        StageCoach(int cost) : from(0), to(0), cost(cost) {}
    };

class Item {
    public:
        float price;
        float weight;
        float ratio;
        int index;
    
        Item() : price(0), weight(0), ratio(0), index(0) {}
        Item(int index, float weight, float price) : price(price), weight(weight), ratio(0), index(index) {}
        Item(float price, float weight, float ratio, int index) : price(price), weight(weight), ratio(ratio), index(index) {}
    };
    
StringNode* createStringLinkedList(string data);
StringNode* addToStringLinkedList(StringNode* head, string data);
StringNode* getFromStringLinkedList(StringNode* head, int index);
StringNode* deleteFromStringLinkedList(StringNode* head, int index);
void printStringLinkedList(StringNode* head);

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
void mergeTwoDimension(int **arr, int start, int mid, int end);
void mergeSortTwoDimension(int **arr, int size);
void mergeSortTwoDimension(int **arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void mergeSort(int *arr, int size);
void mergeSort(int *arr, int start, int end);
int binarySearch(int arr[], int n, int target);
void swap(int *arr, int x, int y );
void segregate1(int *arr, int n);
void segregateWithMerge(int *arr, int start, int mid, int end);
void segregate(int *arr, int start, int end);
int* activityselectionAlgo(int *start, int *end, int size);

unsigned long hash_djb2(const char *str);
unsigned long hashString(const char* key, long int size);
StringHashtable* createStringHashTable();
void putStringHashTable(StringHashtable *table, const char* key, const char* value);
const char* getStringHashTable(StringHashtable *table, const char* key);
void printStringHashtable(StringHashtable *table);
void deleteFromStringHashTable(StringHashtable *table, const char * key);
Hashtable<char, int>* charFreqTable(string message);
void sortedCharacterFrequencies();
int StagecoachProblem();
float fractionalKnapSackProblem(int *prices, int *weights, int size, int maxWeight);
void sortItems(Item **arr, int size);
int longestCommonSubsequence(string text1, string text2);
void playWithFractionalKnapSack();
void playWithKnapSack();
void primsMST();
void breadthFirstSearch();
#include "utils/linkedList.h"
#include "utils/hashtable.h"
#endif
