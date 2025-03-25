#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;



int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int x = low - 1;
    for (int i = low; i < high; i++) {
        if (arr[i] > pivot) {
            x++;
            swap(arr[x], arr[i]);
        }
    }
    swap(arr[x + 1], arr[high]);
    return x + 1;

}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}
int main() {
    //'list1000' text name
    /*ifstream inputfile("list1000.txt");
    if (!inputfile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<int> arr;
    int num;
    while (inputfile >> num) {
        arr.push_back(num);
    }
    inputfile.close();*/
    srand(time(0));

    int totalValue = 0;

    for (int i = 0; i < 16; i++) {
        const int ARRAY_SIZE = 100000;
        vector<int> numArray;

        for (int j = 0; j < ARRAY_SIZE; j++) {
            int randValue = (rand() % 2000) + 1;
            numArray.push_back(randValue);
        }

        auto start = high_resolution_clock::now();
        // Quicksort
        quickSort(numArray, 0, numArray.size() - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        
        auto rawValue = duration.count();

        totalValue += rawValue;
    }

    int avgValue = totalValue / 16;

    cout << "Avg time in microseconds: " << avgValue;

   

    // Output
    //cout << "Sorted array: ";
    //for (int i = numArray.size() - 1;i  >= 0; i--) {
    //    cout << numArray[i] << " ";
    //}
    //cout << endl;
    //cout << "Time taken by function: "
    //    << duration.count() << " microseconds" << endl;//
    return 0;

}

