#include <iostream>

using namespace std;

struct Datos {
    string nombre;
    string direccion;
    int telefono;
    int edad;
};

void buscarEdad(Datos nuevoingreso[50], int cant) {
    int choice;
    cout << "Ingrese la edad que quiere buscar" << endl;
    cin >> choice;
    int cont = 0;
    for(int i = 0; i < cant; i++) {
        if(nuevoingreso[i].edad == choice) {
        cout << "\tNombre: " << nuevoingreso[i].nombre << endl;
        cout << "\tDireccion: " << nuevoingreso[i].direccion << endl;
        cout << "\tTelefono: " << nuevoingreso[i].telefono << endl;
        cout << "\tEdad: " << nuevoingreso[i].edad << endl;
        cont++;
        }
    }
    if(cont == 0) cout << "No se encontro a nadie" << endl;
}

void buscarinicial(Datos nuevoingreso[50], int cant) {
    char choice;
    cout << "Ingrese la inicial que quiere buscar" << endl;
    cin >> choice;
    int cont = 0;
    if(choice >= 'a' && choice <= 'z') choice-=32;
    for(int i = 0; i < cant; i++) {
        if(nuevoingreso[i].nombre[0] == choice) {
        cout << "\tNombre: " << nuevoingreso[i].nombre << endl;
        cout << "\tDireccion: " << nuevoingreso[i].direccion << endl;
        cout << "\tTelefono: " << nuevoingreso[i].telefono << endl;
        cout << "\tEdad: " << nuevoingreso[i].edad << endl;
        cont++;
        }
    }
    if(cont == 0) cout << "No se encontro a nadie" << endl;
}

void imprimirDatos(Datos nuevoingreso[50], int cant) {
    for(int i = 0; i < cant; i++) {
        cout << "\tNombre: " << nuevoingreso[i].nombre << endl;
        cout << "\tDireccion: " << nuevoingreso[i].direccion << endl;
        cout << "\tTelefono: " << nuevoingreso[i].telefono << endl;
        cout << "\tEdad: " << nuevoingreso[i].edad << endl;
    }
}

int ingresarDatos(Datos nuevoingreso[50]){
    string nombre, direccion;
    int telefono,edad, cant = 0;
    while(cant < 50) {
        cout << "Ingrese su nombre" << endl;
        getline(cin,nombre);
        if(nombre.empty()) break;

        cout << "Ingrese su direccion" << endl;
        getline(cin,direccion);

        while(1) {
        cout << "Ingrese su telefono (sin agregar el codigo de area)" << endl;
        cin >> telefono;
        if(telefono < 11111111 || telefono > 99999999) {cout << "Elija un numero existente" << endl; continue;}
        int check = 0;
        for(int i = 0; i < cant; i++) {
          if(nuevoingreso[i].telefono == telefono) {cout << "Ese numero ya fue ingresado" << endl;check = 1;}
        }
        if(check) continue;

        cout << "Ingrese su edad" << endl;
        cin >> edad;
        if(edad < 1 || edad > 100) {cout << "Ingrese una edad coherente" << endl;continue;}
        break;
        }


        Datos datos = {nombre,direccion,telefono,edad};
        nuevoingreso[cant] = datos;
        cant++;
        cin.ignore();
    }
    return cant;
}
int main(void) {
    Datos nuevoingreso[50];
    int choice, cant;
    cant = ingresarDatos(nuevoingreso);
    cout << "Bienvenido al registro civil, elija una opcion" << endl;
    while(1) {
        cout << "1)Mostrar todos los nombres" << endl;
        cout << "2)Mostrar los nombres segun la edad" << endl;
        cout << "3)Mostrar los nombres segun su inicial" << endl;
        cout << "4)Salir" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        imprimirDatos(nuevoingreso,cant);
            break;
        case 2:
            buscarEdad(nuevoingreso,cant);
            break;
        case 3:
            buscarinicial(nuevoingreso,cant);
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
