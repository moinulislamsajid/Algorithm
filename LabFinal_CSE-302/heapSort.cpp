#include <iostream>
using namespace std;

void heapify(int number[], int len, int prtIndx)
{
    int hi = prtIndx;
    int left = 2 * prtIndx + 1;
    int right = 2 * prtIndx + 2;

    if (left < len && number[left] < number[hi])
    {
        hi = left;
    }

    if (right < len && number[right] < number[hi])
    {
        hi = right;
    }

    // If the smallest is not the parent
    if (hi != prtIndx)
    {
        swap(number[prtIndx], number[hi]);
        heapify(number, len, hi);
    }
}

// Heap Sort function
void heapSort(int number[], int len)
{
    // Build the heap
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(number, len, i);
    }

    for (int i = len - 1; i >= 0; i--)
    {
        swap(number[0], number[i]);

        heapify(number, i, 0);
    }
}

void printSortedArray(int number[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int number[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> number[i];
    }

    // Perform heap sort
    heapSort(number, size);

    // Print the sorted array
    cout << "Sorted array: ";
    printSortedArray(number, size);

    return 0;
}
