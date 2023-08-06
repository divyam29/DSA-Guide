#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &A, int n)
{
    int i;
    for (i = 1; i <= n - 1; i++)
    // No. of passes = n-1
    {
        for (int j = 0; j < n - 1 - i; j++)
        // No od comparisons per pass = n-1-i
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
        printArray(A, n);
    }
    cout << "No.of passes: " << i << endl;
    printArray(A, n);
}

void bubbleSortAdaptive(vector<int> &A, int n)
// Takes o(n) time for sorted array
{
    int isSorted = 0;
    int i;
    for (i = 1; i <= n - 1; i++)
    // No. of passes = n-1
    {
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        // No od comparisons per pass = n-1-i
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
    cout << "No.of passes: " << i << endl;
    printArray(A, n);
}

void insertionSort(vector<int> &A, int n)
// Takes o(n) time for sorted array
{
    int i;
    int key, j;
    for (i = 1; i <= n - 1; i++)
    // No. of passes = n-1
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        printArray(A, n);
    }
    cout << "No.of passes: " << i << endl;
}

void selectionSort(vector<int> &A, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        swap(A[i], A[minIndex]);
        printArray(A, n);
    }
    cout << "No.of passes: " << i << endl;
    printArray(A, n);
}

int partition(vector<int> &A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);

    swap(A[low], A[j]);
    return j;
}

void quickSort(vector<int> &A, int low, int high)
{
    int n = A.size();
    int partitionIndex;
    // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        // sort left subarray
        quickSort(A, partitionIndex + 1, high);
        // sort right subarray
    }
    printArray(A, n);
}

void merge(vector<int> &A, int low, int mid, int high)
{
    int i, j, k;
    int sz = high - low + 1;
    vector<int> B(sz);
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(vector<int> &A, int low, int high)
{
    int mid;
    int n = A.size();
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
        printArray(A, n);
    }
}

void countSort(vector<int> &A, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > maxi)
        {
            maxi = A[i];
        }
    }
    cout << maxi << endl;
    vector<int> B(maxi + 1, 0);
    printArray(B, maxi + 1);
    for (int i = 0; i < n; i++)
    {
        B[A[i]]++;
    }
    printArray(B, maxi + 1);
    int i = 0, j = 0;
    while (i <= maxi)
    {
        if (B[i] > 0)
        {
            A[j] = i;
            B[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    printArray(A, n);
}

int main()
{
    vector<int> A = {54, 12, 65, 7, 23, 9};
    // vector<int> A = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // vector<int> A = {7, 9, 12, 23, 54, 65};
    int n = A.size();
    printArray(A, n);
    cout << endl;
    // bubbleSort(A, n);
    // bubbleSortAdaptive(A, n);
    // insertionSort(A, n);
    // selectionSort(A, n);
    // quickSort(A, 0, n - 1);
    // mergeSort(A, 0, n - 1);
    countSort(A, n);
    // printArray(A, n);

    return 0;
}