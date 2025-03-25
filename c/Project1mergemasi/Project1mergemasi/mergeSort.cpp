#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>

#include <chrono>

using namespace std;
using namespace std::chrono;

void printArray(int arr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int leftIdx, int midIdx, int rightIdx) {

    vector<int> tempLeftArr;
    vector<int> tempRightArr;

    tempLeftArr.resize(midIdx - leftIdx + 1);
    tempRightArr.resize(rightIdx - midIdx);

    for (int i = 0; i < tempLeftArr.size(); i++) {
        tempLeftArr.at(i) = arr[leftIdx + i];
    }
    for (int j = 0; j < tempRightArr.size(); j++) {
        tempRightArr.at(j) = arr[midIdx + 1 + j];
    }

    int mergedArrayIdx = leftIdx;
    int l = 0; // index variable to iterate through left subarray
    int r = 0; // index variable to iterate through right subarray

    while (l < tempLeftArr.size() && r < tempRightArr.size()) {
        if (tempLeftArr[l] <= tempRightArr[r]) {
            arr[mergedArrayIdx] = tempLeftArr[l];
            l++;
        }
        else {
            arr[mergedArrayIdx] = tempRightArr[r];
            r++;
        }
        mergedArrayIdx++;
    }

    while (l < tempLeftArr.size()) {
        arr[mergedArrayIdx] = tempLeftArr[l];
        l++;
        mergedArrayIdx++;
    }

    while (r < tempRightArr.size()) {
        arr[mergedArrayIdx] = tempRightArr[r];
        r++;
        mergedArrayIdx++;
    }
}

void mergeSort(int arr[], const int startIdx, const int endIdx) {
    
    if (startIdx >= endIdx) return;
    
    int partition = floor(startIdx + (endIdx - startIdx) / 2);
    mergeSort(arr, startIdx, partition);
    mergeSort(arr, partition + 1, endIdx);
    merge(arr, startIdx, partition, endIdx);

}

int main() {

    //fstream list1000file;

    //list1000file.open("list1000.txt");

    //const int ARRAY_SIZE = 1000;
    //int numArray[ARRAY_SIZE] = {};
    //int i = 0;
    //string currLine = "";

    //if (list1000file.is_open()) {
    //    while (getline(list1000file, currLine)) {
    //        //cout << currLine << endl;
    //        numArray[i] = stoi(currLine);
    //        //cout << numArray[i] << endl;
    //        i++;
    //    }
    //}
    //
    //list1000file.close();

    ///////////////

    srand(time(0));

    int totalValue = 0;

    for (int i = 0; i < 16; i++) {
        const int ARRAY_SIZE = 100000;
        int numArray[ARRAY_SIZE];

        for (int j = 0; j < ARRAY_SIZE; j++) {
            numArray[j] = (rand() % 2000) + 1;
        }

        auto start = high_resolution_clock::now();

        mergeSort(numArray, 0, ARRAY_SIZE - 1);

        auto stop = high_resolution_clock::now();

        // printArray(numArray, ARRAY_SIZE);

        auto duration = duration_cast<microseconds>(stop - start);

        auto rawValue = duration.count();

        totalValue += rawValue;
    }

    int avgValue = totalValue / 16;

    cout << "Avg time in microseconds: " << avgValue;

    return 0;
}