#include <iostream>
using namespace std;

struct Cancion {
    string artista;
    string titulo;
    int duracion;
    double size;
};

void imprimirCancion(Cancion nuevaCancion[100], int cantC) {
    char n = 164;
    for(int i = 0; i < cantC; i++) {
        cout << "Cancion numero " << i+1 << endl;
        cout << "\tArtista: " << nuevaCancion[i].artista << endl;
        cout << "\tTitulo: " << nuevaCancion[i].titulo << endl;
        cout << "\tDuracion: " << nuevaCancion[i].duracion << endl;
        cout << "\tTama" << n << "o: "<< nuevaCancion[i].size << endl;
    }
}

int ingresarCancion(Cancion nuevaCancion[100], int cont) {
    char musico[100];
    char nombreC[100];
    int duracion, duracionTotal;
    double size;
    char n = 164;
    cout << "Ingrese el nombre del artista" << endl;
    cin.ignore();
    fgets(musico,100,stdin);
    cout << "Ingrese el nombre de la cancion" << endl;
    cin.ignore();
    fgets(nombreC,100,stdin);
    cout << "Ingrese la duracion de la cancion(en segundos)" << endl;
    cin >> duracion;
    duracionTotal = duracion / 60;
    cout << "Ingrese el tama"<< n << "o de la cancion(en Kb)" << endl;
    cin >> size;
    Cancion cancion = {musico,nombreC,duracion,size};
    nuevaCancion[cont] = cancion;
    cont++;

    return cont;
}

void buscarcancion(Cancion nuevaCancion[100], int cantC) {
    string choice;
    bool encontrado = 0;
    char n = 164;
    cout << "Que cancion quiere buscar?" << endl;
    cin >> choice;
    for(int i = 0; i < cantC; i++) {
        if(nuevaCancion[i].artista.find(choice) != string::npos || nuevaCancion[i].titulo.find(choice) != string::npos) {
            cout << "Cancion encontrada. Es la numero " << i+1 << endl;
            cout << "Artista: " << nuevaCancion[i].artista << endl;
            cout << "Titulo: " << nuevaCancion[i].titulo << endl;
            cout << "Duracion: " << nuevaCancion[i].duracion << endl;
            cout << "Tama" << n << "o: " << nuevaCancion[i].size << endl;
            encontrado = 1;
        }
    }
    if(!encontrado) cout << "No encontramos a ese artista o cancion" << endl;
}

int main(void) {
    Cancion nuevaCancion[100];
    int cantC = 0, choice;
    while(1) {
    cout << "Bienvenido a Spotify, que quiere hacer?" << endl;
    cout << "1)Ver las canciones" << endl;
    cout << "2)Agregar una cancion" << endl;
    cout << "3)Buscar una cancion" << endl;
    cout << "4)Salir" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
        imprimirCancion(nuevaCancion,cantC);
        break;
        case 2:
        if(cantC == 700) {
            cout << "Llego al maximo de canciones que puede almacenar" << endl;
            break;
        }
        cantC = ingresarCancion(nuevaCancion,cantC);
        break;
        case 3:
        buscarcancion(nuevaCancion,cantC);
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
