#include <iostream>

using namespace std;
//estructura con los datos de las personas
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
    for(int i = 0; i < cant; i++) { //en esta parte busca en todos los datos ingresados y con la edad ingresada por el ususario si hay coincidencias
    //y si las hay imprime quienes son y si no le avisa al usuario que no hay nadie con esa edad
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
    if(choice >= 'a' && choice <= 'z') choice-=32; //en esta parte si el caracter que ingreso es minuscula lo pase a mayuscula
    //Luego, si la inicial de los nombres ingresados es igual al caracter ingresado por el usario, se imprime este mismo y si no hay ninguno 
    //se le avisa al ususario
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
    for(int i = 0; i < cant; i++) { //funcion para imprimir todos los datos ingresados
        cout << "\tNombre: " << nuevoingreso[i].nombre << endl;
        cout << "\tDireccion: " << nuevoingreso[i].direccion << endl;
        cout << "\tTelefono: " << nuevoingreso[i].telefono << endl;
        cout << "\tEdad: " << nuevoingreso[i].edad << endl;
    }
}

int ingresarDatos(Datos nuevoingreso[50]){
    string nombre, direccion;
    int telefono,edad, cant = 0;
    while(cant < 50) { //en esta parte se le pide al usuario ingresar 50 personas con su nombre, sin que este este vacio, su direccion, que tampoco
        //este vacio, su telefono, que tenga 8 numeros, y su edad, qe tenga coherencia
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
        nuevoingreso[cant] = datos; //con este parte se guarda los datos ingresados en la estructura
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
        cout << "3)Mostrar los nombres segun su inicial" << endl; //en esta parte se le ofrece al usuario diversas opciones que apareceran luego de ingresar
        //las 50 personas
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
