
#include <iostream>

using namespace std;

struct Cumples {
    string nombre;
    int dia;
    int mes; //estructura para las personas
    int year;
};

void initialize(Cumples nuevoCumple[8]) {
    string nombre;
    int dia,mes,year;
    char n = 164;
    for(int i = 0; i < 8; i++) {
        cout << "Ingrese su nombre" << endl;  //esta funcion se encarga de pedirle al ususario que ingrese su nombre y su fecha de cumpleaños
        //y, si algo no esta coherente se le avisa respecto a ese problema 
        getline(cin,nombre);
        while(1) {
            cout << "Ingrese su dia de cumplea" << n << "os" << endl;
            cin >> dia;
            if(dia < 1 || dia > 31) {cout << "Elija un dia existente" << endl; continue;}
            cout << "Ingrese su mes de cumplea" << n << "os" << endl;
            cin >> mes;
            if(mes < 1 || mes > 12) {cout << "Elija un mes existente" << endl; continue;}
            cout << "Ingrese su a" << n << "o de cumplea" << n << "os" << endl;
            cin >> year;
            cin.ignore();
            if(year < 1923 || year > 2023) {cout << "Elija un a" << n << "o coherente" << endl; continue;}
            break;
        }
        Cumples cumples = {nombre,dia,mes,year};
        nuevoCumple[i] = cumples;
    }
}

void find(Cumples nuevoCumple[8], int mes) {
    char n = 164;
    int cont = 0;
    cout << "Personas que cumplen en el mes elejido: " << endl;
    for(int i = 0; i < 8; i++) {
        if(nuevoCumple[i].mes == mes) {
            cout << "\tNombre: " << nuevoCumple[i].nombre << endl;
            cout << "\tDia: " << nuevoCumple[i].dia << endl; //se le pide al usuario ingresar un mes de los existentes y si encuentra alguna de 
            //las personas ingresadas con el mismo mes que el ingresado, lo imprime
            cout << "\tMes: " << nuevoCumple[i].mes << endl;
            cout << "\tA"<< n << "o: " << nuevoCumple[i].year << endl;
            cont++;
        }
    }
    if(cont == 0) cout << "Nadie cumple en este mes" << endl;
}

int main(void) {
    Cumples nuevoCumple[8];
    char n = 164;
    int choice;
    initialize(nuevoCumple); //se le pide al usuario ingresar datos de 8 personas y luego se le pide ingresar un mes para mostrarle las personas que nacieron
    //en dicho mes
    while(1) {
        cout << "Ingrese un mes de cumplea" << n << "os (o 0 para terminar)" << endl;
        cin >> choice;
        if(choice > 0 && choice <= 12) {
            find(nuevoCumple,choice);
        }
        else if(choice == 0) {cout << "Chau" << endl; break;}
        else cout << "Elija una opcion correcta" << endl;
    }
    return 0;
}
