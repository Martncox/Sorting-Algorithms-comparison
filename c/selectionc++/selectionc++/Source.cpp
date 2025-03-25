#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

// Function for Selection sort 
void selectionSort(vector<int>& arr, int n)
{
    int i, j, min_idx;

    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in 
        // unsorted array 
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element 
        // with the first element 
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array 
void printArray(vector<int>& arr, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Driver program 
int main()
{
    /*ifstream inputFile("list1000.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }*/
    ///*int num;
    //while (inputFile >> num) {
    //    arr.push_back(num);
    //}
    //inputFile.close();*/

    srand(time(0));

    int totalValue = 0;

    for (int i = 0; i < 16; i++) {
        const int ARRAY_SIZE = 1000;
        vector<int> numArray;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            int randValue = (rand() % 2000) + 1;
            numArray.push_back(randValue);
        }
        auto start = high_resolution_clock::now();
        selectionSort(numArray, ARRAY_SIZE);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        auto rawValue = duration.count();

        totalValue += rawValue;
    }
    
    int avgValue = totalValue / 16;

    cout << "Avg time in microseconds: " << avgValue;
    //cout << "Sorted array:" << endl;
    //printArray(arr, n);

    //cout << endl << "Completion time: " << duration.count() << " microseconds" << endl;
    return 0;
}// aaabbbbsda
/// ratio
// code