/*
 * Programmieren fuer Physiker: C++
 * SS 2014
 *
 * Aufgabe 22
 * Quicksort
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

template <typename T>
void swapValues(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
int choosePivot(T array[], int s, int t) {
    return s;
}

template <typename T>
int partition(T array[], int s, int t) {
    int pivotIndex = choosePivot(array, s, t);
    T pivotValue = array[pivotIndex];
    int l = s;

    for(int i = s; i<= t; i++) {
        if(array[i] < pivotValue) {
            l++;
            swapValues(array[i], array[l]);
        }
    }
    swapValues(array[pivotIndex], array[l]);

    return l;
}

template <typename T>
void quicksort(T array[], int s, int t) {

    // nothing to do for less than 2 elements
    if(s>=t) return;
    
    // find pivot and sort left and right parts
    int pivot = partition(array, s, t);
    quicksort(array, s, pivot-1);
    quicksort(array, pivot+1, t);
}

template <typename T>
void printArray(T array[], int size, int columns) {
    cout << "n = " << size << endl;
    for(int i=0; i<size; i++) {
        cout << left << setw(10) << array[i] << " ";
        if((i+1) % columns == 0 && i+1 != size) cout << endl;
    }
    cout << endl;
}

int main() {
    // read in array size to be sorted
    int size = 0;
    cout << "Bitte Größe des zu sortierenden Arrays eingeben: ";
    cin >> size;
    
    // initialize PRNG with time stamp
    srand((unsigned int)time(0));

    // fill array with random elements
    double array[size];
    for(int i=0; i<size; i++) {
        array[i] = double(rand())/RAND_MAX;
    }

    // print unsorted array, sort and print again
    cout << "Array vor Sortierung:" << endl;
    printArray(array, size, 6);

    quicksort(array, 0, size-1);

    cout << endl << "Sortiertes Array:" << endl;
    printArray(array, size, 6);
}
