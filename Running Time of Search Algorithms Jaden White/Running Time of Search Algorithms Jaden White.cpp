// Running Time of Search Algorithms Jaden White.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

class Search {
private:

    int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
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
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> distribution(1, 100);
    int random_number = distribution(rng);
    int Vectorend = 0;
    int N = 1000000;
    int SumRBS = 0;
    int SumIBS = 0;
    int SumSeqS = 0;
    int TotalRBS = 0;
    int TotalIBS = 0;
    int TotalSeqS = 0;
    
    for (int i = 0; i < 10; i++) {
        cout << "Trial: " << i+1 << endl;
        for (int i = 0; i < N-1; i++) {
            Vectorend++;
            searchtype.arr.push_back(random_number);
            random_number = distribution(rng);
        }

        random_number = distribution(rng);
        searchtype.arr.push_back(random_number);
        random_number = distribution(rng);
        searchtype.target = random_number;
        cout << "Target: " << searchtype.target << endl;
    
        auto start_time = chrono::high_resolution_clock::now();
        searchtype.recursivesearch();
        auto end_time = chrono::high_resolution_clock::now();
        SumRBS = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        cout << "Recursive binary search time: " << SumRBS << " microseconds." << endl;
    
        start_time = chrono::high_resolution_clock::now();
        searchtype.iterbinsearch();
        end_time = chrono::high_resolution_clock::now();
        SumIBS = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        cout << "Iterative binary search time: " << SumIBS << " microseconds." << endl;

        start_time = chrono::high_resolution_clock::now();
        searchtype.seqsearch();
        end_time = chrono::high_resolution_clock::now();
        SumSeqS = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        cout << "Sequential binary search time: " << SumIBS << " microseconds." << endl;
        cout << endl;

        TotalRBS = TotalRBS + SumRBS;
        TotalIBS = TotalIBS + SumIBS;
        TotalSeqS = TotalSeqS + SumSeqS;
    }

    TotalRBS = TotalRBS / 10;
    TotalIBS = TotalIBS / 10;
    TotalSeqS = TotalSeqS / 10;
    cout << "Average recursive binary search time: " << TotalRBS << endl;
    cout << "Average iterative binary search time: " << TotalIBS << endl;
    cout << "Average sequential binary search time: " << TotalSeqS << endl;
};

