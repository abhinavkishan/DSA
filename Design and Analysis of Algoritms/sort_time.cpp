#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

void swap(long int &a, long int &b) {
    long int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<long int>a) {
    for(int i = 0; i < a.size() - 1; i++) {
        for(int j = 0; j < a.size() - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

void insertion_sort(vector<long int>a) {
    long int i, j, key;
    for(i = 1; i < a.size(); i++) {
        key = a[i];
        j = i-1;
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selection_sort(vector<long int>a) {
    int i, j, min;
    int n = a.size();
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(a[j] < a[min]) min = j;
        }
        swap(a[min], a[i]);
    }
}

int main() {
    long int n = 10000;
    int it = 0;
    vector<double> t1, t2, t3;

    cout << "Asize_\t BS\t IS\t SS\n";
    while(it++ < 10) {
        vector<long int> a, b, c;
        for(int i = 0; i < n; i++) {
            long int num = rand() % n + 1;
            a.push_back(num);
            b.push_back(num);
            c.push_back(num);
        }

        clock_t start, end;

        //Bubble Sort:
        start = clock();
        bubble_sort(a);
        end = clock();
        t1.push_back((double) (end - start));

        //Insertion Sort:
        start = clock();
        insertion_sort(a);
        end = clock();
        t2.push_back((double) (end - start));

        //Selection Sort:
        start = clock();
        selection_sort(a);
        end = clock();
        t3.push_back((double) (end - start));

        cout << n << "\t" << (long int) t1[it-1] << "\t" << (long int ) t2[it-1] << "\t" << (long int) t3[it-1] << endl;

        n+= 10000;
    }
    // cout << "Time 1\n";
    // for(long int j : t1) {
    //     cout << j << " ";
    // }
    // cout << "\nTime 2\n";
    // for(long int j : t2) {
    //     cout << j << " ";
    // }
    // cout << "Time 3\n";
    // for(long int j : t3) {
    //     cout << j << " ";
    // }
}