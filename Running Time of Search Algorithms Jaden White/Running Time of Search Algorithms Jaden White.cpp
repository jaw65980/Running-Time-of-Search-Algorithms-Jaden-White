// Running Time of Search Algorithms Jaden White.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
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
    int target;
    int randomvector;
    vector<int> arr = {};

    void recursivesearch() {
        int recursiveresult = recursiveBinarySearch(arr, target, 0, arr.size());
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
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> distribution(1, 100);
    int random_number = distribution(rng);
    int Vectorend = 0;

    cout << "Vector: {";
    for (int i = 0; i < 100; i++) {
        Vectorend++;
        searchtype.arr.push_back(random_number);
        cout << searchtype.arr[i] << ", ";
        random_number = distribution(rng);
    }

    random_number = distribution(rng);
    searchtype.arr.push_back(random_number);
    cout << searchtype.arr[Vectorend] << "}" << endl;

    random_number = distribution(rng);
    searchtype.target = random_number;
    cout << "Target: " << searchtype.target << endl;
    searchtype.recursivesearch();
    searchtype.iterbinsearch();
    searchtype.seqsearch();
};

