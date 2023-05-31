#include <iostream>

using namespace std;

void swap(int a[], int i, int j, int min) {
  int temp = a[i];
  a[i] = min;
  a[j] = temp;
}

void print(int a[7]) {
    for(int i = 0; i < 7; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void bubble(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n-1; j++) {
        print(a);
      if(a[j] > a[j+1]) {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}


void sort(int a[], int aux[], int lo, int hi) {
  if(hi - lo <= 1) return;
  int mid = lo + (hi - lo) / 2;
  sort(a,aux,lo,mid);
  sort(a,aux,mid,hi);
  int i = lo;
  int j = mid;
  print(aux);
  for(int k = lo; k < hi; k++) {
    if(i == mid)         aux[k] = a[j++];
    else if(j == hi)     aux[k] = a[i++];
    else if(a[j] < a[i]) aux[k] = a[j++];
    else                 aux[k] = a[i++];
  }
  //copy back
  for(int k = lo; k < hi; k++){
    a[k] = aux[k];
  }
}

void selec(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    int min = INT_MAX;
    int cont;
    for(int j = i; j < n; j++ ) {
        print(a);
      if(a[j] < min) {
        min = a[j];
        cont = j;
      }
    }
    swap(a,i,cont,min);
  }
}

void initialize(int a[7], int aux[7]) {
    for(int i = 0; i < 7; i++) {
        aux[i] = a[i];
    }
}

int main(void) {
    int a[7], aux[7], auxi[7], choice;
    for (int i = 0; i < 7; i++) {
        cout << "Ingrese un numero" << endl;
        cin >> a[i];
    }
    while(1) {
        cout << "Elija una opcion de ordenamiento" << endl;
        cout << "1)Merge" << endl;
        cout << "2)Selection" << endl;
        cout << "3) Bubble" << endl;
        cout << "4)Salir" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
            initialize(a,aux);
            sort(aux,auxi,0,7);
            cout << endl;
            print(aux);
            break;
            case 2:
            initialize(a,aux);
            selec(aux,7);
            cout << endl;
            print(aux);
            break;
            case 3:
            initialize(a,aux);
            bubble(aux,7);
            cout << endl;
            print(aux);
            break;
            case 4:
            return 1;
            default:
            cout << "Esa no es una opcion" << endl;
            break;
        }
    }
    return 0;
}