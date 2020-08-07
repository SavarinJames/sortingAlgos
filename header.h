// 19125076
// Nguyen Phu Van
// 19APCS1

#ifndef _SORTING_H_
#define _SORTING_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int sizes[7] = { 0, 3000, 10000, 30000, 100000, 300000 };
const string inputTypes[5] = { "RANDOMIZED INPUT", "SORTED INPUT", "NEARLY-SORTED INPUT", "REVERSED INPUT" };
const string sortingTypes[15] = { "Selection Sort", "Insertion Sort", "Binary-Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort" };

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void binaryInsertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void shakerSort(int arr[], int n);
void shellSort(int arr[], int n);

void sift(int arr[], int left, int right);
void heapSort(int arr[], int n);

void merge(int arr[], int left, int right);
void mergeSort(int arr[], int left, int right);

int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);
int median3(int& a, int& b, int& c);

void countingSort(int arr[], int n);

int digitCnt(int x);
int digit(int x, int pos);
int pow10(int k);
void LSDRadixSort(int arr[], int n);
void digitSort(int arr[], int n, int pos);

void flashSort(int arr[], int n);

void prog();

#endif // !_SORTING_H_
