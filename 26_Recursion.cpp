#include <bits/stdc++.h>
using namespace std;

void printVectorofvector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

void printVectorStrings(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    cout << endl;
}

void printArray(int A[], int s, int e)
{
    cout << "\nprinting:";
    for (int i = s; i <= e; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int power(int n, int x)
{
    cout << x << " " << n << endl;
    if (x == 0)
    {
        return 1;
    }
    return n * power(n, x - 1);
}

void reversePrintCount(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    reversePrintCount(n - 1);
    // Tail Recursion
}

void printCount(int n)
{
    if (n == 0)
    {
        return;
    }
    printCount(n - 1);
    cout << n << " ";
    // Head Recursion
}

int fibo(int n)
{
    if (n == 0)
    {
        return -1;
    }
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int countStairs(int n)
{
    // You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the oth step to Nth step.

    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return countStairs(n - 1) + countStairs(n - 2);
}

void sayDigits(int n)
{
    if (n == 0)
    {
        return;
    }
    vector<string> dig{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int digit = n % 10;
    n = n / 10;
    sayDigits(n);
    cout << dig[digit] << " ";
}

bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return isSorted(arr + 1, n - 1);
}

int sumofArray(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    int sum = arr[0] + sumofArray(arr + 1, n - 1);
    return sum;
}

bool linearSearch(int arr[], int n, int key)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    return linearSearch(arr + 1, n - 1, key);
}

bool binarySearch(int arr[], int low, int high, int key)
{
    printArray(arr, low, high);
    if (low > high)
    {
        return false;
    }
    int mid = low + (high - low) / 2;
    if (key == arr[mid])
    {
        return true;
    }
    else if (key < arr[mid])
    {
        return binarySearch(arr, low, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, high, key);
    }
}

void revString(string &str, int i)
{
    int n = str.length() - 1;
    int j = n - i;
    cout << str << endl;
    if (i > j)
    {
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    return revString(str, i);
}

bool checkPalindromeString(string &str, int i)
{
    int n = str.length() - 1;
    int j = n - i;
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        return checkPalindromeString(str, i);
    }
}

int optimizedPower(int x, int n)
{
    cout << x << " " << n << endl;
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    int ans = optimizedPower(x, n / 2);
    if (n % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return x * ans * ans;
    }
}

void recursiveBubbleSort(int arr[], int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return;
//     }
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             swap(arr[i], arr[i + 1]);
//         }
//     }
//     return recursiveBubbleSort(arr, n - 1);
// }

void solve(string str, int index, string output, vector<string> &ans)
{
    if (index >= str.length())
    {
        // remove empty string
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    solve(str, index + 1, output, ans);
    output.push_back(str[index]);
    solve(str, index + 1, output, ans);
}

vector<string> subsequenceOfString(string str)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(str, index, output, ans);
    sort(ans.begin(), ans.end());
    printVectorStrings(ans);
    return ans;
}

int main()
{
    // cout << factorial(5) << endl;
    // cout << power(5, 5) << endl;
    // printCount(15);
    // cout << endl;
    // reversePrintCount(15);
    // cout << endl;

    // cout << fibo(8) << endl;
    // for (int i = 1; i < 10; i++)
    // {
    //     cout << fibo(i) << " ";
    // }

    // cout << countStairs(5) << endl;
    // sayDigits(382345);

    // int arr[] = {3, 2, 5, 1, 6};
    // // int arr[] = {2, 4, 6, 10, 14, 18};
    // int n = sizeof(arr) / sizeof(int);
    // printArray(arr, 0, n - 1);

    // cout << isSorted(arr, n);
    // cout << sumofArray(arr, n);
    // cout << linearSearch(arr, n, 15);

    // cout << binarySearch(arr, 0, n - 1, 16);

    // string str = "Divyam";
    // string str = "aabbcbbaa";

    // cout << str << endl
    //      << endl;
    // revString(str, 0);
    // cout << endl
    //      << str << endl;

    // cout << checkPalindromeString(str, 0);
    // cout << power(3, 10) << "\n\n";
    // cout << optimizedPower(3, 10) << endl;

    // recursiveBubbleSort(arr, n);
    // printArray(arr, 0, n - 1);

    subsequenceOfString("abc");

    return 0;
}