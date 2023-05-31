#include <iostream>
using namespace std;

struct Imagen {
    string nombre;
    int ancho;
    int alto; //estructura de las imagenes
    double size;
};

void imprimirImagen(Imagen nuevaImagen[700], int cantI) {
    char n = 164;
    for(int i = 0; i < cantI; i++) { //funcion que imprime todas las imagenes ingresadas
        cout << "Imagen numero " << i+1 << endl;
        cout << "\tNombre: " << nuevaImagen[i].nombre << endl;
    }
}

int ingresarImagen(Imagen nuevaImagen[700], int cont) {
    char nombre[100];
    int alto, ancho;
    double size;
    char n = 164;
    cout << "Ingrese el nombre de la imagen" << endl; //funcion para ingresar la imagen. Se le pide al usuario el nombre de la imagen
    //su altura y su ancho y su tamaño
    cin.ignore();
    fgets(nombre,100,stdin);
    cout << "Ingrese el ancho de la imagen(en pixeles)" << endl;
    cin >> ancho;
    cout << "Ingrese en alto de la imagen(en pixeles)" << endl;
    cin >> alto;
    cout << "Ingrese el tama"<< n << "o de la imagen(en Kb)" << endl;
    cin >> size;
    Imagen imagen = {nombre,ancho,alto,size};
    nuevaImagen[cont] = imagen;
    cont++;

    return cont;
}

void buscarImagen(Imagen nuevaImagen[700], int cantC) {
    string choice;
    bool encontrado = 0;
    char n = 164;
    cout << "Que imagen quiere buscar?" << endl; //esta funcion se encarga de buscar una imagen que su nombre tenga la palabra ingresada
    //por el usuario, si ocurre eso, lo imprime
    cin >> choice;
    for(int i = 0; i < cantC; i++) {
        if(nuevaImagen[i].nombre.find(choice) != string::npos) {
            cout << "Imagen encontrada. Es la numero " << i+1 << endl;
            cout << "Nombre: " << nuevaImagen[i].nombre << endl;
            cout << "ancho: " << nuevaImagen[i].ancho << "Px" << endl;
            cout << "alto: " << nuevaImagen[i].alto << "Px" << endl;
            cout << "Tama" << n << "o: " << nuevaImagen[i].size << "Kb" << endl;
            encontrado = 1;
        }
    }
    if(!encontrado) cout << "No encontramos esa imagen" << endl;
}

int main(void) {
    Imagen nuevaImagen[700];
    int cantC = 0, choice;
    while(1) {
    cout << "Bienvenido a tu galeria, que quiere hacer?" << endl;
    cout << "1)Ver las imagenes" << endl;
    cout << "2)Agregar una imagen" << endl;
    cout << "3)Buscar una imagen" << endl;
    cout << "4)Salir" << endl; //esta parte se encarga de mostrale al usuario distintas opciones para hacer cosas con las imagenes
        //Si decide ingresar imagenes despues de llegar a las 700, se le avisara que llego al maximo
    cin >> choice;
    switch(choice) {
        case 1:
        imprimirImagen(nuevaImagen,cantC);
        break;
        case 2:
        if(cantC == 700) {
            cout << "Llego al maximo de Imagenes que puede almacenar" << endl;
            break;
        }
        cantC = ingresarImagen(nuevaImagen,cantC);
        break;
        case 3:
        buscarImagen(nuevaImagen,cantC);
        break;
        case 4:
        cout << "Chau" << endl;
        return 1;
        default:
        cout << "Elija una opcion correcta" << endl;
        break;
        }
    }
    return 0;
}
