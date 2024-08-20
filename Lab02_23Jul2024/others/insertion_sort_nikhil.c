#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> generateArray(int size, int option)
{
    vector<int> arr(size);
    srand(time(0));
    if (option == 0)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        }
    }
    else if (option == 1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            arr[size - i - 1] = i;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 101;
        }
    }
    return arr;
}

void insertionSort(vector<int> &arr, long int *step, long int *count)
{
    for (int j = 1; j < arr.size(); j++)
    {
        (*step)++;
        int i = j - 1;
        (*step)++;
        int key = arr[j];
        (*step)++;
        while (i >= 0 && arr[i] > key)
        {
            (*step)++;
            arr[i + 1] = arr[i];
            (*step)++;
            i--;
            (*step)++;
            (*count)++;
        }
        (*step)++;
        arr[i + 1] = key;
        (*step)++;
    }
}

int main()
{

    vector<int> arr = generateArray(10000, 1);

    long int step = 0, count = 0;
    insertionSort(arr, &step, &count);

    cout << "Steps: " << step << endl;
    cout << "Count: " << count << endl;
    return 0;
}