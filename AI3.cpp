#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
} 

void merge(int arr[], int l, int m, int r) 
{
    	int n1 = m - l + 1;
    	int n2 = r - m;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++) 
    	{
        	L[i] = arr[l + i];
    	}
    	for (int j = 0; j < n2; j++) 
    	{
        	R[j] = arr[m + 1 + j];
    	}
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) 
    	{
        	if (L[i] <= R[j]) 
       	 	{	
            		arr[k] = L[i];
            		i++;
        	} 
        	else 
        	{
            		arr[k] = R[j];
            		j++;
        	}
        	k++;
    	}
	while (i < n1) 
	{
        	arr[k] = L[i];
        	i++;
        	k++;
    	}
	while (j < n2) 
	{
        	arr[k] = R[j];
        	j++;
        	k++;
   	 }
}
void mergeSort(int arr[], int l, int r) 
{
    	if (l < r) 
    	{
        	int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
        	mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
    	}
}
int partition(int arr[], int low, int high) 
{
    	int pivot = arr[high];
    	int i = (low - 1);
    	for (int j = low; j <= high - 1; j++) 
    	{
        	if (arr[j] < pivot) 
        	{
            		i++;
            		swap(arr[i], arr[j]);
        	}
    	}
    	swap(arr[i + 1], arr[high]);
    	return (i + 1);
}
void quickSort(int arr[], int low, int high) 
{
    	if (low < high) 
    	{
        	int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
        	quickSort(arr, pi + 1, high);
    	}
}
int main() 
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    cout << "Bubble Sorted array is:";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << arr[i];
    }
    cout << endl;

    selectionSort(arr, n);
    cout << "Selection Sorted array is:";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << arr[i];
    }
    cout << endl;

    insertionSort(arr, n);
    cout << "Insertion Sorted array is:";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << arr[i];
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);
    cout << "Merge Sorted array is:";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << arr[i];
    }
    cout << endl;

    quickSort(arr, 0, n - 1);
    cout << "Quick Sorted array is:";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}

