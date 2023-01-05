#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *arr;
    int size, length;

public:
    Array(int sz)
    {
        size = sz;
        length = 0;
        arr = new int[size];
    }
    ~Array()
    {
        delete[] arr;
    }
    void display()
    {
        cout << "Array:\n";
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void append(int x)
    {
        if (length < size)
        {
            arr[length] = x;
            length++;
            cout << x << " appended in array!!\n";
            display();
        }
        else
        {
            cout << "Sorry! No more space in array...";
        }
    }
    void insert(int index, int x)
    {
        if (length < size && index >= 0 && index < length)
        {
            for (int i = length; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = x;
            length++;
            cout << x << " inserted at index " << index << " in array!!\n";
            display();
        }
        else
        {
            cout << "Sorry! There is an error...";
        }
    }
    int deleteElement(int index)
    {
        if (length > 0 && index >= 0 && index < length)
        {
            int i, x = arr[index];
            for (i = index; i < length - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
            cout << x << " deleted from index " << index << " in array!!\n";
            display();
            return x;
        }
        else
        {
            cout << "Sorry! There is an error...";
            return 0;
        }
    }
    int linearSearch(int x)
    {
        display();
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == x)
            {
                swap(arr[i], arr[0]);
                return i;
            }
        }
        return -1;
    }
    int binarySearch(int x)
    {
        sort(arr + 0, arr + length);
        display();
        int l = 0, mid, h = length - 1;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (arr[mid] == x)
            {
                return mid;
            }
            else if (arr[mid] > x)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return -1;
    }
    int get(int index)
    {
        if (index < length && index >= 0)
        {
            return arr[index];
        }
        else
        {
            return -1;
        }
    }
    void set(int index, int x)
    {
        if (index < length && index >= 0)
        {
            arr[index] = x;
            cout << "Element at index " << index << " set to " << x << endl;
            display();
        }
        else
        {
            cout << "Sorry! There is an error...";
        }
    }
    int max()
    {
        int max_element = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (arr[i] > max_element)
            {
                max_element = arr[i];
            }
        }
        return max_element;
    }
    int min()
    {
        int min_element = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (arr[i] < min_element)
            {
                min_element = arr[i];
            }
        }
        return min_element;
    }
    int sum()
    {
        int total = 0;
        for (int i = 0; i < length; i++)
        {
            total += arr[i];
        }
        return total;
    }
    float avg()
    {
        int total = 0;
        for (int i = 0; i < length; i++)
        {
            total += arr[i];
        }
        return total / length;
    }
    void reverse()
    {
        int i, j;
        for (i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(arr[i], arr[j]);
        }
        cout << "Array Reversed...\n";
        display();
    }
    void leftShift()
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = 0;
        cout << "Left shift successful..\n";
        display();
    }
    void leftRotate()
    {
        int i;
        int ele = arr[0];
        for (i = 0; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = ele;
        cout << "Left rotate successful..\n";
        display();
    }
    void rightShift()
    {
        int i;
        for (i = length - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = 0;
        cout << "Right shift successful..\n";
        display();
    }
    void rightRotate()
    {
        int i;
        int ele = arr[length - 1];
        for (i = length - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = ele;
        cout << "Right rotate successful..\n";
        display();
    }
    void insertInSortedArray(int x)
    {
        sort(arr + 0, arr + length);
        int i = length - 1;
        if (length < size)
        {
            while (i >= 0 && x < arr[i])
            {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = x;
            length++;
            cout << x << " inserted in array \n";
            display();
        }
        else
        {
            cout << "Sorry! There is an error...";
        }
    }
    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                return false;
            }
        }
        return true;
    }
    void rearrangeNegativeLeft()
    {
        int i = 0, j = length - 1;
        while (i < j)
        {
            while (arr[i] < 0)
            {
                i++;
            }
            while (arr[j] > 0)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        cout << "Rearrangement Successful!\n";
        display();
    }
    void rearrangeNegativeRight()
    {
        int i = 0, j = length - 1;
        while (i < j)
        {
            while (arr[i] > 0)
            {
                i++;
            }
            while (arr[j] < 0)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        cout << "Rearrangement Successful!\n";
        display();
    }
    Array *mergeArrays(Array *arr2)
    {
        int i = 0, j = 0, k = 0;
        // sort(arr + 0, arr + length);
        // sort(arr2->arrs + 0, arr2->arr + arr2->length);
        Array *arr3 = new Array(length + arr2->length);
        while (i < length && j < arr2->length)
        {
            if (arr[i] < arr2->arr[j])
            {
                arr3->arr[k++] = arr[i++];
            }
            else
            {
                arr3->arr[k++] = arr2->arr[j++];
            }
        }
        for (; i < length; i++)
        {
            arr3->arr[k++] = arr[i];
        }
        for (; j < arr2->length; j++)
        {
            arr3->arr[k++] = arr2->arr[j];
        }
        arr3->length = length + arr2->length;
        cout << "Merged ";
        arr3->display();
        return arr3;
    }
    Array *unionArrays(Array *arr2)
    {
        int i = 0, j = 0, k = 0;
        // sort(arr+0,arr+length);
        // sort(arr2->arr+0,arr2->arr+arr2->length);
        Array *arr3 = new Array(length + arr2->length);
        while (i < length && j < arr2->length)
        {
            if (arr[i] < arr2->arr[j])
            {
                arr3->arr[k++] = arr[i++];
            }
            else if (arr[i] > arr2->arr[j])
            {
                arr3->arr[k++] = arr2->arr[j++];
            }
            else
            {
                arr3->arr[k++] = arr[i++];
                j++;
            }
        }
        for (; i < length; i++)
        {
            arr3->arr[k++] = arr[i];
        }
        for (; j < arr2->length; j++)
        {
            arr3->arr[k++] = arr2->arr[j];
        }
        arr3->length = k;
        cout << "Union of ";
        arr3->display();
        return arr3;
    }
    Array *intersectionArrays(Array *arr2)
    {
        int i = 0, j = 0, k = 0;
        // sort(arr+0,arr+length);
        // sort(arr2->arr+0,arr2->arr+arr2->length);
        Array *arr3 = new Array(length + arr2->length);
        while (i < length && j < arr2->length)
        {
            if (arr[i] < arr2->arr[j])
            {
                i++;
            }
            else if (arr[i] > arr2->arr[j])
            {
                j++;
            }
            else
            {
                arr3->arr[k++] = arr[i++];
                j++;
            }
        }
        arr3->length = k;
        cout << "Intersection of ";
        arr3->display();
        return arr3;
    }
    Array *differenceArrays(Array *arr2)
    {
        int i = 0, j = 0, k = 0;
        // sort(arr+0,arr+length);
        // sort(arr2->arr+0,arr2->arr+arr2->length);
        Array *arr3 = new Array(length + arr2->length);
        while (i < length && j < arr2->length)
        {
            if (arr[i] < arr2->arr[j])
            {
                arr3->arr[k++] = arr[i++];
            }
            else if (arr[i] > arr2->arr[j])
            {
                arr3->arr[k++] = arr2->arr[j++];
            }
            else
            {
                i++;
                j++;
            }
        }
        arr3->length = k;
        cout << "Union of ";
        arr3->display();
        return arr3;
    }
};

int main()
{
    Array *arr;
    int n, ch;
    int x, index;
    float ele;
    // cout << "Enter array size: ";
    // cin >> n;
    arr = new Array(10);
    Array *arr2 = new Array(10);
    Array *arr3;
    cout << "Array of size " << n << " created!!";
    arr->append(-1);
    arr->append(3);
    arr->append(-5);
    arr->append(4);
    arr->append(7);
    arr->append(-1);
    arr->append(7);
    arr->append(-57);
    arr->append(70);

    cout << endl;

    arr2->append(-1);
    arr2->append(3);
    arr2->append(-5);
    arr2->append(70);
    arr2->append(80);
    arr2->append(90);
    arr2->append(100);
    // arr->reverse();
    // arr->leftShift();
    // arr->leftRotate();
    // arr->rightShift();
    // arr->rightRotate();

    // arr->insertInSortedArray(-1);

    // if (arr->isSorted())
    // {
    //     cout << "Array is sorted!";
    // }
    // else
    // {
    //     cout << "Array is not sorted!";
    // }

    // arr->rearrangeNegativeLeft();
    // arr->rearrangeNegativeRight();

    // arr3 = arr->mergeArrays(arr2);
    // arr3->display();

    // arr3 = arr->unionArrays(arr2);
    // arr3->display();

    // arr3 = arr->intersectionArrays(arr2);
    // arr3->display();

    arr3 = arr->differenceArrays(arr2);
    // arr3->display();

    // -----------MENU---------------------------------

    // do
    // {
    //     cout << "\n\nMenu\n";
    //     cout << "1. Display\n";
    //     cout << "2. Append\n";
    //     cout << "3. Insert\n";
    //     cout << "4. Delete\n";
    //     cout << "5. Linear Search\n";
    //     cout << "6. Binary Search\n";
    //     cout << "7. Get\n";
    //     cout << "8. Set\n";
    //     cout << "9. Maximum Element\n";
    //     cout << "10. Minimum Element\n";
    //     cout << "11. Sum of Elements\n";
    //     cout << "12. Average of Elements\n";
    //     // cout << "13. Average of Elements\n";
    //     // cout << "14. Average of Elements\n";
    //     // cout << "15. Average of Elements\n";
    //     // cout << "16. Average of Elements\n";
    //     // cout << "17. Average of Elements\n";
    //     // cout << "18. Average of Elements\n";
    //     // cout << "19. Average of Elements\n";
    //     cout << "-1. Exit\n";
    //     cout << "Enter you choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         arr->display();
    //         break;

    //     case 2:
    //         cout << "Enter element to be appended: ";
    //         cin >> x;
    //         arr->append(x);
    //         break;

    //     case 3:
    //         cout << "Enter index: ";
    //         cin >> index;
    //         cout << "Enter element to be appended: ";
    //         cin >> x;
    //         arr->insert(index, x);
    //         break;

    //     case 4:
    //         cout << "Enter index to be deleted: ";
    //         cin >> index;
    //         ele = arr->deleteElement(index);
    //         cout << "Deleted element is: " << ele;
    //         break;

    //     case 5:
    //         cout << "Enter element to be searched: ";
    //         cin >> x;
    //         ele = arr->linearSearch(x);
    //         if (ele != -1)
    //         {
    //             cout << "Element found at index " << ele;
    //         }
    //         else
    //         {
    //             cout << "Element not found..";
    //         }
    //         break;

    //     case 6:
    //         cout << "Enter element to be searched: ";
    //         cin >> x;
    //         ele = arr->binarySearch(x);
    //         if (ele != -1)
    //         {
    //             cout << "Element found at index " << ele;
    //         }
    //         else
    //         {
    //             cout << "Element not found..";
    //         }
    //         break;

    //     case 7:
    //         cout << "Enter index: ";
    //         cin >> index;
    //         ele = arr->get(index);
    //         if (ele != -1)
    //         {
    //             cout << "Element at index " << index << " is " << ele;
    //         }
    //         else
    //         {
    //             cout << "Index does not exist..";
    //         }
    //         break;

    //     case 8:
    //         cout << "Enter index: ";
    //         cin >> index;
    //         cout << "Enter element to be appended: ";
    //         cin >> x;
    //         arr->set(index, x);
    //         break;

    //     case 9:
    //         ele = arr->max();
    //         cout << "Max element in array: " << ele;
    //         break;

    //     case 10:
    //         ele = arr->min();
    //         cout << "Min element in array: " << ele;
    //         break;

    //     case 11:
    //         ele = arr->sum();
    //         cout << "Sum of elements of array: " << ele;
    //         break;

    //     case 12:
    //         ele = arr->avg();
    //         cout << "Average of elements of array: " << ele;
    //         break;

    //     default:
    //         cout << "Wrong Choice...Try Again!";
    //         break;
    //     }
    // } while (ch != -1);

    return 0;
}