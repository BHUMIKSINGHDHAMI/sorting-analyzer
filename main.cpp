#include <iostream>
#include <vector>

#include "input_handler.h"
#include "data_generator.h"
#include "analyzer.h"

using namespace std;

void printTitle() {
    cout << "============================================\n";
    cout << "        SORTING PERFORMANCE ANALYZER\n";
    cout << "============================================\n";
}

int main() {
    printTitle();

    vector<int> arr;
    int method = getInputMethod();

    cout << "\n--------------------------------------------\n";

    if (method == 1) {
        cout << " Data Generation Mode Selected\n";
        int n = getArraySize();
        int type = getDataType();
        arr = generateData(n, type);
        cout << " Data generated successfully.\n";
        cout << "\nGenerated Values:\n";
         cout<<"[";
        for (int x : arr) {
        if(x==0) continue;
        cout << x << " ";
        }
        cout<<"]";
        cout << "\n";
    }
    else if (method == 2) {
        cout << " Manual Input Mode Selected\n";
        arr = getManualArray();
        cout << " Array captured successfully.\n";
        cout<<"[";
        for (int x : arr) {
        if(x==0) continue;
        cout << x << " ";
        }
        cout<<"]";
        cout << "\n";
    }
    else {
        cout << " Invalid choice. Exiting...\n";
        return 0;
    }

    cout << "--------------------------------------------\n";

    vector<int> algos = getAlgorithmChoices();
    runAnalysis(arr, algos);

    cout << "\n============================================\n";
    cout << "               ANALYSIS COMPLETE\n";
    cout << "============================================\n";

    return 0;
}