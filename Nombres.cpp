#include <iostream>

using namespace std;

struct Datos {
    string nombre;
    string apellido; //estructura para guardar los datos
    int edad;
};

void imprimirDatos(Datos nuevosDatos[100], int cantD) {
    for(int i = 0; i < cantD; i++) {
        cout << "Persona " << i+1 << endl;
        cout << "Nombre: " << nuevosDatos[i].nombre << ", ";
        cout << "Apellido/s: " << nuevosDatos[i].apellido << ", "; //funcion que imprime todas las personas ingresadas con sus datos
        //uno al lado del otro separado por una ,
        cout << "Edad: " << nuevosDatos[i].edad << endl;
    }
}

int ingresarDatos(Datos nuevosDatos[100], int cantD) {
    string nombre, apellido;
    int edad;
    cout << "Ingrese su nombre" << endl;
    getline(cin,nombre);

    cout << "Ingrese su apellido" << endl; //esta funcion le pide al usuario ingresar los datos de la persona, el nombre, el apellido y la edad
    getline(cin,apellido);

    cout << "Ingrese su edad" << endl;
    cin >> edad;

    cin.ignore();

    Datos datos = {nombre,apellido,edad};
    nuevosDatos[cantD] = datos;
    cantD++;

    return cantD;
}

int main(void) {
    Datos nuevosDatos[100];
    int choice, cantD = 0;
    cout << "Bienvenido. Que desea hacer?" << endl;
    while(1) {
        cout << "1)Ingresar datos" << endl;
        cout << "2)Ver datos" << endl; //esta parte se encarga de mostrarle al usuario opciones para ingresar los datos y para ver los datos
        cout << "3)Salir" << endl;
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1:
            cantD = ingresarDatos(nuevosDatos,cantD);
            break;
            case 2:
            imprimirDatos(nuevosDatos,cantD);
            break;
            case 3:
            return 1;
            default:
            cout << "Esa no es una opcion" << endl;
            break;
        }
    }
    return 0;
}
