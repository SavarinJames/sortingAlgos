// 19125076
// Nguyen Phu Van
// 19APCS1

#include "sorting.h"

using namespace std;
//-------------------------------------------------

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 1; i <= n; i++)
	{
		a[i] = rand() % n + 1;
	}
}

void GenerateSortedData(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}

void GenerateReverseData(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = n + 1 - i;
	}
}

void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n + 1;
		int r2 = rand() % n + 1;
		swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:
		GenerateRandomData(a, n);
		break;
	case 1:
		GenerateSortedData(a, n);
		break;
	case 2:
		GenerateReverseData(a, n);
		break;
	case 3:
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void selectionSort(int arr[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		int minPos = i;
		int minVal = arr[i];
		for (int j = i + 1; j <= n; j++)
			if (minVal > arr[j])
			{
				minPos = j;
				minVal = arr[j];
			}
		arr[minPos] = arr[i];
		arr[i] = minVal;
	}
}

void insertionSort(int arr[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		int val = arr[i];
		int j = i - 1;
		while (j >= 1 && arr[j] > val)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
	}
}

void binaryInsertionSort(int arr[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		int left = 1, right = i - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (arr[mid] <= arr[i])
				left = mid + 1;
			else right = mid - 1;
		}
		int val = arr[i];
		for (int j = i - 1; j >= left; j--)
			arr[j + 1] = arr[j];

		arr[left] = val;
	}
}

void bubbleSort(int arr[], int n)
{
	for (int i = 2; i <= n; i++)
		for (int j = n; j >= i; j--)
			if (arr[j - 1] > arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
}

void shakerSort(int a[], int n)
{
	bool swapped = true;
	int start = 1;
	int end = n;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

void shellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i <= n; i++)
		{
			int val = arr[i];
			int j;
			for (j = i; j > gap && arr[j - gap] > val; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = val;
		}
	}
}

void sift(int arr[], int left, int right)
{
	int i = left, j = i * 2;
	int val = arr[i];
	while (j <= right)
	{
		if (j < right && arr[j] < arr[j + 1])
			j++;
		if (val >= arr[j]) break;
		arr[i] = arr[j];
		i = j; j = i * 2;
	}
	arr[i] = val;
}

void heapSort(int arr[], int n)
{
	int left, right;
	left = n / 2;
	while (left > 0)
	{
		sift(arr, left, n);
		left--;
	}

	right = n;
	while (right > 1)
	{
		swap(arr[1], arr[right]);
		right--;
		sift(arr, 1, right);
	}
}

void merge(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	int sz1 = mid - left + 1;
	int sz2 = right - mid;

	int* arr1 = new int[sz1 + 5], * arr2 = new int[sz2 + 5];

	for (int i = 1; i <= sz1; i++)
		arr1[i] = arr[left + i - 1];
	for (int i = 1; i <= sz2; i++)
		arr2[i] = arr[mid + i];

	int id1 = 1, id2 = 1;
	int mainID = left;
	while (id1 <= sz1 && id2 <= sz2)
	{
		if (arr1[id1] <= arr2[id2])
		{
			arr[mainID] = arr1[id1];
			id1++;
		}
		else
		{
			arr[mainID] = arr2[id2];
			id2++;
		}
		mainID++;
	}
	while (id1 <= sz1)
	{
		arr[mainID] = arr1[id1];
		++id1;
		++mainID;
	}

	while (id2 <= sz2)
	{
		arr[mainID] = arr2[id2];
		++id2;
		++mainID;
	}

	delete[] arr1;
	delete[] arr2;
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, right);
	}
}

int partition(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	int pivot = median3(arr[mid], arr[left], arr[right]);
	//int pivot = arr[left];
	int idL = left;
	int idR = right + 1;
	do
	{
		do idL++; while (arr[idL] < pivot);
		do idR--; while (arr[idR] > pivot);
		swap(arr[idL], arr[idR]);
	} while (idL < idR);
	swap(arr[idL], arr[idR]);
	swap(arr[left], arr[idR]);
	return idR;
}

void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivotID = partition(arr, left, right);
		quickSort(arr, left, pivotID - 1);
		quickSort(arr, pivotID + 1, right);
	}
}

int median3(int& a, int& b, int& c)
{
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	return b;
}

void countingSort(int arr[], int n)
{
	int lo = arr[1], up = arr[1];
	for (int i = 2; i <= n; i++)
	{
		lo = min(lo, arr[i]);
		up = max(up, arr[i]);
	}

	int* b = new int[n + 5];
	int* f = new int[up - lo + 5];

	for (int i = 0; i <= (up - lo); i++)
		f[i] = 0;

	for (int i = 1; i <= n; i++)
		f[arr[i] - lo]++;
	for (int i = 1; i <= (up - lo); i++)
		f[i] += f[i - 1];

	for (int i = n; i >= 1; i--)
	{
		b[f[arr[i] - lo]] = arr[i];
		f[arr[i] - lo]--;
	}

	for (int i = 1; i <= n; i++)
		arr[i] = b[i];

	delete[] b;
	delete[] f;
}

int pow10(int k)
{
	if (k == 0) return 1;
	if (k == 1) return 10;
	int tmp = pow10(k / 2);
	if (k % 2 == 1)
		return tmp * tmp * 10;
	return tmp * tmp;
}

int digit(int x, int pos)
{
	int rs = x % pow10(pos);
	return rs / pow10(pos - 1);
}

int digitCnt(int x)
{
	int rs = 1;
	int ten = 10;
	while (x / ten > 0)
	{
		rs++;
		ten *= 10;
	}
	return rs;
}

void digitSort(int arr[], int n, int pos)
{
	int f[15];
	int* b = new int[n + 5];
	for (int i = 0; i <= 9; i++)
		f[i] = 0;
	for (int i = 1; i <= n; i++)
		f[digit(arr[i], pos)]++;
	for (int i = 1; i <= 9; i++)
		f[i] += f[i - 1];
	for (int i = n; i >= 1; i--)
	{
		int dig = digit(arr[i], pos);
		b[f[dig]] = arr[i];
		f[dig]--;
	}

	for (int i = 1; i <= n; i++)
		arr[i] = b[i];

	delete[] b;
}

void LSDRadixSort(int arr[], int n)
{
	int maxDigit;
	int maxx = arr[1];
	for (int i = 2; i <= n; i++)
		maxx = max(maxx, arr[i]);
	maxDigit = digitCnt(maxx);

	for (int pos = 1; pos <= maxDigit; pos++)
		digitSort(arr, n, pos);
}

int getMax(int arr[], int n)
{
	int rs = arr[1];
	for (int i = 2; i <= n; i++)
		rs = max(rs, arr[i]);
	return rs;
}

int getMin(int arr[], int n)
{
	int rs = arr[1];
	for (int i = 2; i <= n; i++)
		rs = min(rs, arr[i]);
	return rs;
}

void flashSort(int arr[], int n)
{
	int maxx = getMax(arr, n);
	int minn = getMin(arr, n);
	const int classSize = 100;
	int classNum = (int)(n / classSize);

	if (classNum <= 1)
	{
		insertionSort(arr, n);
		return;
	}

	int** f = new int* [classNum + 5];
	int* sz = new int[classNum + 5];

	for (int i = 1; i <= classNum; i++) // initialize the sub-classes and it's size
	{
		f[i] = new int[150];
		sz[i] = 0;
	}

	for (int i = 1; i <= n; i++) // put the elements in their classes
	{
		int classId = 1 + (int)(((classNum - 1) * (arr[i] - minn)) / (maxx - minn));
		++sz[classId];
		f[classId][sz[classId]] = arr[i];
	}

	/*for (int i = 1; i <= classNum; i++)
		insertionSort(f[i], sz[i]); // done sorting the sub-classes

	int id = 0;
	for (int i = 1; i <= classNum; i++)
		for (int j = 1; j <= sz[i]; j++)
			arr[++id] = f[i][j];	*/

	for (int i = 1; i <= classNum; i++)
		delete[] f[i];
	delete[] f;
	delete[] sz;
}

bool checkSorted(int* arr, int n)
{
	for (int i = 2; i <= n; i++)
		if (arr[i - 1] > arr[i])
			return false;
	return true;
}

void letItSort(int*& arr, int n, int algoID)
{
	switch (algoID)
	{
	case 0:
		//selectionSort(arr, n);
		break;
	case 1:
		//insertionSort(arr, n);
		break;
	case 2:
		//binaryInsertionSort(arr, n);
		break;
	case 3:
		//bubbleSort(arr, n);
		break;
	case 4:
		//shakerSort(arr, n);
		break;
	case 5:
		//shellSort(arr, n);
		break;
	case 6:
		//heapSort(arr, n);
		break;
	case 7:
		//mergeSort(arr, 1, n);
		break;
	case 8:
		//quickSort(arr, 1, n);
		break;
	case 9:
		//countingSort(arr, n);
		break;
	case 10:
		//LSDRadixSort(arr, n);
		break;
	case 11:
		flashSort(arr, n);
		break;
	default: break;
	}
}

void prog()
{
	int* arr = nullptr;
	int n;
	for (int dataTypes = 0; dataTypes < 4; dataTypes++)
	{
		cout << setw(107) << setfill('_') << inputTypes[dataTypes];
		cout << '\n';
		cout << left;
		cout << setw(25) << setfill(' ') << "Input sizes";
		cout << setw(2) << setfill(' ') << "|";

		cout << right;
		for (int sz = 1; sz <= 5; sz++)
			cout << setw(16) << setfill(' ') << sizes[sz];
		cout << '\n';
		cout << setw(107) << setfill('-') << '-';
		cout << '\n';

		for (int algoID = 0; algoID < 12; algoID++)
		{
			cout << left;
			cout << setw(25) << setfill(' ') << sortingTypes[algoID];
			cout << setw(2) << setfill(' ') << "|";
			for (int sz = 1; sz <= 5; sz++)
			{
				n = sizes[sz];
				arr = new int[n + 2];
				GenerateData(arr, n, dataTypes);

				clock_t start, end;
				start = clock();

				letItSort(arr, n, algoID);

				end = clock();

				double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
				cout << right;
				if (checkSorted(arr, n))
					cout << setw(16) << setfill(' ') << setprecision(4) << fixed << timeTaken;
				else  cout << setw(16) << setfill(' ') << "WA";

				delete[] arr;
			}
			cout << '\n';
		}
		cout << setw(107) << setfill('_') << '_';
		cout << "\n\n\n";
	}
}