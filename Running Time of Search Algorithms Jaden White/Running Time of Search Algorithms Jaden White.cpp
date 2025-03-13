// Running Time of Search Algorithms Jaden White.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Search {
private:
    int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
        if (low <= high) {
            int mid = low + ((high - low) / 2);
            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                return recursiveBinarySearch(arr, target, mid + 1, high);
            }
            else {
                return recursiveBinarySearch(arr, target, low, mid - 1);
            }
        }
        else {
            return -1;
        }
    }

    int iterativeBinarySearch(const vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int sequentialSearch(const vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

public:
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int target = 6;

    void recursivesearch() {
        int recursiveresult = recursiveBinarySearch(arr, target, 0, (arr.size() - 1));
        if (recursiveresult == -1) {
            cout << "Recusive result not found." << endl;
        }
        else {
            cout << "Recursive result found at index " << recursiveresult << "." << endl;
        }
    }

    void iterbinsearch() {
        int iterbinresult = iterativeBinarySearch(arr, target);
        if (iterbinresult == -1) {
            cout << "Iterative result not found." << endl;
        }
        else {
            cout << "Iterative result found at index " << iterbinresult << "." << endl;
        }
    }

    void seqsearch() {
        int sequentialresult = sequentialSearch(arr, target);
        if (sequentialresult == -1) {
            cout << "Sequential result not found." << endl;
        }
        else {
            cout << "Sequential result found at index " << sequentialresult << "." << endl;
        }
    }
};



int main()
{
    Search searchtype;
    searchtype.recursivesearch();
    searchtype.iterbinsearch();
    searchtype.seqsearch();
};

