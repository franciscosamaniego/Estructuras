#include <iostream>
using namespace std;

struct Imagen {
    string nombre;
    int ancho;
    int alto;
    double size;
};

void imprimirImagen(Imagen nuevaImagen[100], int cantI) {
    char n = 164;
    for(int i = 0; i < cantI; i++) {
        cout << "Imagen numero " << i+1 << endl;
        cout << "\tNombre: " << nuevaImagen[i].nombre << endl;
    }
}

int ingresarImagen(Imagen nuevaImagen[100], int cont) {
    char nombre[100];
    int alto, ancho;
    double size;
    char n = 164;
    cout << "Ingrese el nombre de la imagen" << endl;
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

void buscarImagen(Imagen nuevaImagen[100], int cantC) {
    string choice;
    bool encontrado = 0;
    char n = 164;
    cout << "Que imagen quiere buscar?" << endl;
    cin >> choice;
    for(int i = 0; i < cantC; i++) {
        if(nuevaImagen[i].nombre.find(choice) != string::npos) {
            cout << "Imagen encontrada. Es la numero " << i+1 << endl;
            cout << "Nombre: " << nuevaImagen[i].nombre << endl;
            cout << "ancho: " << nuevaImagen[i].ancho << endl;
            cout << "alto: " << nuevaImagen[i].alto << endl;
            cout << "Tama" << n << "o: " << nuevaImagen[i].size << endl;
            encontrado = 1;
        }
    }
    if(!encontrado) cout << "No encontramos esa imagen" << endl;
}

int main(void) {
    Imagen nuevaImagen[100];
    int cantC = 0, choice;
    while(1) {
    cout << "Bienvenido a tu galeria, que quiere hacer?" << endl;
    cout << "1)Ver las imagenes" << endl;
    cout << "2)Agregar una imagen" << endl;
    cout << "3)Buscar una imagen" << endl;
    cout << "4)Salir" << endl;
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