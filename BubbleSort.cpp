#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

void swap(int a[], int b, int c) {
  int temp = a[b];
  a[b] = a[c];
  a[c] = temp;
}


void bubble(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n-1; j++) {
      if(a[j] > a[j+1]) {
        swap(a,j,j+1);
      }
    }
  }
}


int main (void) {
    int n[5];
    for(int i = 0; i < 5; i++) {
        cout << "Ingrese un numero" << endl;
        cin >> n[i];
    }
    bubble(n,5);
    for(int i = 0; i < 5; i++) {
        cout << n[i] << " ";
    }
    cout << endl;
    return 0;
}
