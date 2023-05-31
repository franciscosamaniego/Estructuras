#include <iostream>
#include <limits.h>

using namespace std;

void swap(int a[], int i, int j, int min) {
  int temp = a[i]; //funcion para cambiar las posiciones del array en el selection sort
  a[i] = min;
  a[j] = temp;
}


void print(int a[7]) {
    for(int i = 0; i < 7; i++) {
        cout << a[i] << " "; //funcion para imprimir el array
    }
    cout << endl;
}

void order(int a[7], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = i; j > 0; j--) {
    if(a[j] < a[j-1]) { //esta es el metodo de ordenamiento mas comun, consiste en comparar desde el espacio en el que se posicione
      //el for comparar con el anterior y, si es mas chico en el que esta posicionado, se intercambian y asi hasta estar acomodados
    int temp = a[j];
    a[j] = a[j-1];
    a[j-1] = temp;
      }
    }
    print(a);
  }
}

void bubble(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n-1; j++) {
      if(a[j] > a[j+1]) {
        print(a);
        int temp = a[j]; //el bubble sort consiste en comparar el numero en el que esta posicionado y el siguiente, si el primero es
        //mas grande que el segundo, se cambia y si no se queda asi y esto se hace hasta llegar al anteultimo para poder hacer la comparacion
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
    
  }
}


void sort(int a[], int aux[], int lo, int hi) {
  if(hi - lo <= 1) return;
  int mid = lo + (hi - lo) / 2;
  print(aux);
  sort(a,aux,lo,mid);
  sort(a,aux,mid,hi);
  int i = lo;
  int j = mid;
  for(int k = lo; k < hi; k++) {
    if(i == mid)         aux[k] = a[j++]; //el merge sort consiste en la frase "Divide y venceras" por lo que divide el array lo mas chico
    //posible hasta que sea muy facil ordenarlo y luego vuelve a juntar todo el array como estaba antes pero ahora ordenado
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
    for(int j = i; j < n; j++ ) { //el selection sort consiste en encontrar el numero mas chico del array para luego ser acomodado
      //en su lugar correspondiente y asi hasta que este ordenado
      if(a[j] < min) {
        min = a[j];
        cont = j;
      }
    }
    print(a);
    swap(a,i,cont,min);
  }
}

void initialize(int a[7], int aux[7]) {
    for(int i = 0; i < 7; i++) {
        aux[i] = a[i]; //esta funcion devuelve el array auxiliar con los valores originales para ser usado de vuelta en cualquiera
      //de los metodos de ordenamiento
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
        cout << "3)Bubble" << endl;
        cout << "4)Original" << endl; //esta parte consiste en pedirle al usuario ingresar 7 numeros y luego de eso se le pide
      //elegir alguna de las opciones de ordenamiento y la que elija le mostrara el proceso que tuvo el array y el resultado final
        cout << "5)Salir" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
            initialize(a,aux);
            sort(aux,auxi,0,7);
            cout << endl;
            print(aux);
            cout << endl;
            break;
            case 2:
            initialize(a,aux);
            selec(aux,7);
            cout << endl;
            print(aux);
            cout << endl;
            break;
            case 3:
            initialize(a,aux);
            bubble(aux,7);
            cout << endl;
            print(aux);
            cout << endl;
            break;
            case 4:
            initialize(a,aux);
            order(aux,7);
            cout << endl;
            print(aux);
            cout << endl;
            break;
            case 5:
            return 1;
            default:
            cout << "Esa no es una opcion" << endl;
            break;
        }
    }
    return 0;
}
