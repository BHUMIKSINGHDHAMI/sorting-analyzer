#include <iostream>
#include <vector>
#include <iomanip>

#include "analyzer.h"
#include "metrics.h"
#include "timer.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "count_sort.h"

using namespace std;

void printHeader(const string& name) {
    cout << "\n====================================\n";
    cout << "        " << name << "\n";
    cout << "====================================\n";
}

void printMetrics(double t, const Metrics& m) {
    cout << left << setw(15) << "Time (ms)"    << ": " << t << "\n";
    cout << left << setw(15) << "Comparisons"  << ": " << m.comparisons << "\n";
    cout << left << setw(15) << "Swaps"        << ": " << m.swaps << "\n";
    cout << "------------------------------------\n";
}

void runAnalysis(const vector<int>& arr,
                 const vector<int>& algos) {

    cout << "\n\n========== SORTING ANALYSIS ==========\n";

    for (int id : algos) {
        vector<int> temp = arr;
        Metrics m;
        double t = 0;

        switch (id) {
            case 1:
                printHeader("Bubble Sort");
                t = measureTime(bubbleSort, temp, m);
                break;

            case 2:
                printHeader("Selection Sort");
                t = measureTime(selectionSort, temp, m);
                break;

            case 3:
                printHeader("Insertion Sort");
                t = measureTime(insertionSort, temp, m);
                break;

            case 4:
                printHeader("Merge Sort");
                t = measureTime(mergeSort, temp, m);
                break;

            case 5:
                printHeader("Quick Sort");
                t = measureTime(quickSort, temp, m);
                break;

            case 6:
                printHeader("Count Sort");
                t = measureTime(countSort, temp, m);
                break;

            default:
                continue;
        }

        printMetrics(t, m);
    }

    cout << "======================================\n";
}