#pragma once
#include "Anime.h"
#include <vector>


void QuickSort(vector<Anime>& arr, int low, int high);
int Partition(vector<Anime>& arr, int low, int high);

int GetMax(vector<Anime>& arr, int n);
void Count(vector<Anime>& arr, int x);
void RadixSort(vector<Anime>& arr);

// based off lecture slides (Sorting, slide 122)
void QuickSort(vector<Anime>& arr, int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

// based off lecture slides (Sorting, slide 122)
int Partition(vector<Anime>& arr, int low, int high) {
    // Select the pivot element
    Anime pivot = arr[low];
    int up = low, down = high;

    while(up < down) {

        for (int j = up; j < high; j++) {

            if(arr[up].GetPopularity() > pivot.GetPopularity())
                break;

            up++;
        }

        for (int j = high; j > low; j--) {

            if(arr[down].GetPopularity() < pivot.GetPopularity())
                break;

            down--;
        }

        if(up < down)
            swap(arr[up], arr[down]);
    }

    swap(arr[low], arr[down]);

    return down;
}

// based off geeksforgeeks (in references)
int GetMax(vector<Anime>& arr, int n) {
    int Max = arr[0].GetPopularity();

    for (int i = 1; i < n; i++) {

        if (arr[i].GetPopularity() > Max) {
            Max = arr[i].GetPopularity();
        }
    }

    return Max;
}

// based off geeksforgeeks (in references)
void Count(vector<Anime>& arr, int x) {
    vector<Anime> result(arr.size());
    vector<int> count(10, 0);

    for (auto i : arr) {
        int num = (i.GetPopularity() / x) % 10;
        count[num]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        int num = (arr[i].GetPopularity() / x) % 10;

        result[count[num] - 1] = arr[i];
        count[num]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = result[i];
    }
}

// based off geeksforgeeks (in references)
void RadixSort(vector<Anime>& arr) {
    int max = GetMax(arr, arr.size());

    for (int i = 1; max / i > 0; i *= 10) {
        // calls count sort function
        Count(arr, i);
    }
}
