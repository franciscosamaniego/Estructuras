//Realizar un programa que pida datos de 8 personas: nombre, día de nacimiento, mes de nacimiento, y 
//año de nacimiento (que se deben almacenar en una tabla de structs). 
//Después deberá repetir lo siguiente: preguntar un número de mes y 
//mostrar en pantalla los datos de las personas que cumplan los años durante ese mes. 
//Terminará de repetirse cuando se teclee 0 como número de mes.

#include <iostream>

using namespace std;

struct Cumples {
    string nombre;
    int dia;
    int mes;
    int year;
};

void initialize(Cumples nuevoCumple[8]) {
    string nombre;
    int dia,mes,year;
    char n = 164;
    for(int i = 0; i < 8; i++) {
        cout << "Ingrese su nombre" << endl;
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
            cout << "\tDia: " << nuevoCumple[i].dia << endl;
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
    initialize(nuevoCumple);
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