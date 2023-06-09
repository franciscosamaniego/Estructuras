#include <iostream>
using namespace std;

struct Duracion {
    int minutos; //estructura para la duracion de la cancion
    int segundos;
};
struct Cancion {
    string artista; //estructura para los datos de la cancion
    string titulo;
    Duracion duracion;
    double size;
};

void ordenar(Cancion nuevaCancion[100], int cantC) {
    for(int i = 0; i < cantC; i++) {
        for(int j = 0; j < cantC-1; j++) { //esta funcion se encarga de ordenar las canciones segun su nommbre. Basicamente compara todas
            //las canciones y si la inicial de una es menor que la otra, se ordena
            if(nuevaCancion[j].titulo > nuevaCancion[j+1].titulo) {
                Cancion temp = nuevaCancion[j];
                nuevaCancion[j] = nuevaCancion[j+1];
                nuevaCancion[j+1] = temp;
            }
        }
    }
}

void modificarCancion(Cancion nuevaCancion[100], int cantC) {
    string musico;
    string nombreC;
    int minutos, segundos, choice;
    double size;
    char n = 164;
    cout << "De las "<< cantC << " canciones,cual modificar?" << endl;
    cin >> choice;
    if(choice > 0 && choice <= cantC) {
        cout << "Ingrese el nuevo nombre del artista(o enter para no modificarlo)" << endl; //esta funcion se encarga de poder modificar
        //las canciones existentes. Se le pedira al usuario ingresar los nuevos valores y, si no quiere cambiar ni el nombre de la cancion
        //o del artista puede dejar un espacio en blanco y en el caso de la duracion y del tamanño solo tiene que ingresar -1. Luego al final
        //se ingresan los nuevos datos a la cancion elegida
        cin.ignore();
        getline(cin,musico);
        if(musico.empty()) musico = nuevaCancion[choice-1].artista;

        cout << "Ingrese el nuevo nombre de la cancion(o enter para no modificarlo)" << endl;
        getline(cin,nombreC);
        if(nombreC.empty()) nombreC = nuevaCancion[choice-1].titulo;
        
        cout << "Ingrese la nueva duracion de la cancion(los minutos) o -1 para no modificarlo" << endl;
        cin >> minutos;
        if(minutos == -1) minutos = nuevaCancion[choice-1].duracion.minutos;
        
        cout << "Ingrese la nueva duracion de la cancion(los segundos) o -1 para no modificarlo" << endl;
        cin >> segundos;
        if(segundos == -1) segundos = nuevaCancion[choice-1].duracion.segundos;

        cout << "Ingrese el nuevo tama" << n << "o o -1 para no modificarlo" << endl;
        cin >> size;
        if(size == -1) size = nuevaCancion[choice-1].size;
        Duracion duracion = {minutos,segundos};
        Cancion cancion = {musico,nombreC,duracion,size};
        nuevaCancion[choice-1] = cancion;
    }
    else cout << "No hay esa cantidad de canciones" << endl;
}

int borrarcancion(Cancion nuevaCancion[100], int cantC) {
    int choice;
    cout << "De las "<< cantC << " canciones,cual quiere borrar?" << endl;
    cin >> choice;
    if(choice > 0 && choice-1 < cantC) {
        for(int i = choice-1; i < cantC; i++) {
            nuevaCancion[i] = nuevaCancion[i+1]; 
        }
        cout << "Borrado con exito" << endl;
        cantC--; //esta funcion se encarga de borrar la cancion que elija el usuario. Para poder borrar la cancion, se le asigna a la posicion
        //de la cancion elegida los valores de la siguiente y asi hasta que no queden mas canciones que acomodar. Por ultimo el total de canciones
        //disminuye un espacio
    }
    else cout << "Elija una cancion existente" << endl;
    return cantC;
}

void imprimirCancion(Cancion nuevaCancion[100], int cantC) {
    char n = 164;
    for(int i = 0; i < cantC; i++) {
        cout << "Cancion numero " << i+1 << endl;
        cout << "\tArtista: " << nuevaCancion[i].artista << endl;
        cout << "\tTitulo: " << nuevaCancion[i].titulo << endl; //funcion para imprimir la estructura de las canciones ingresadas
        if(nuevaCancion[i].duracion.segundos >= 0 && nuevaCancion[i].duracion.segundos < 10) {
            cout << "\tDuracion: " << nuevaCancion[i].duracion.minutos << ":0" << nuevaCancion[i].duracion.segundos << endl;
        }
        else cout << "\tDuracion: " << nuevaCancion[i].duracion.minutos << ":" << nuevaCancion[i].duracion.segundos << endl;
        cout << "\tTama" << n << "o: "<< nuevaCancion[i].size << "Kb" <<endl;
    }
}

int ingresarCancion(Cancion nuevaCancion[100], int cont, Duracion nuevaDuracion[100]) {
    string musico;
    string nombreC;
    int minutos, segundos;
    double size;
    char n = 164;
    while(1) {
    cout << "Ingrese el nombre del artista" << endl; //esta funcion se encarga de pedirle al usuario ingresar una cancion. Le pide el artista y el nombre de 
        //la cancion, que si los deja en blanco es avisado de ello, y luego la duracion en minutos y segundos y su tamaño
    cin.ignore();
    getline(cin,musico);
    if(musico.empty()) {
        cout << "Tiene que ingresar un nombre" << endl;
        continue;
    }
    cout << "Ingrese el nombre de la cancion" << endl;
    getline(cin,nombreC);
    if(nombreC.empty()) {
        cout << "Tiene que ingresar un nombre" << endl;
        continue;
    }
    else break;
    }
    while(1) {
    int correcto = 0;
    cout << "Ingrese los minutos de duracion de la cancion" << endl;
    cin >> minutos;
    if(minutos < 0 || minutos > 60) {
        cout << "Ingrese un numero valido" << endl;
        continue;
    }
    else correcto++;
    cout << "Ingrese los segundos de duracion de la cancion" << endl;
    cin >> segundos;
    if(segundos < 0 || segundos > 60) {
        cout << "Ingrese un numero valido" << endl;
        continue;
    }
    else correcto++;
    cout << "Ingrese el tama"<< n << "o de la cancion(en Kb)" << endl;
    cin >> size;
    if(size < 0) {cout << "Ingrese un numero valido" << endl; continue;}
    else correcto++;
    if(correcto == 3) break;
    }



    Duracion duracion = {minutos,segundos};

    Cancion cancion = {musico,nombreC,duracion,size};
    nuevaCancion[cont] = cancion;
    cont++;
    cin.ignore(); //esta parte guarda los valores ingresados en la estructura de canciones
    return cont;
}

void buscarcancion(Cancion nuevaCancion[100], int cantC) {
    string choice;
    bool encontrado = 0;
    char n = 164;
    cout << "Que cancion quiere buscar?" << endl; //esta funcion se encarga de buscar una cancion que su titulo o artista tenga una palabra
    //ingresada por el usuario. Se encarga de usar la funcion find() que significa que si encuentra la palabra en el artista o en el titulo
    //se muestra dicha cancion
    cin >> choice;
    for(int i = 0; i < cantC; i++) {
        if(nuevaCancion[i].artista.find(choice) != string::npos || nuevaCancion[i].titulo.find(choice) != string::npos) {
            cout << "Cancion encontrada. Es la numero " << i+1 << endl;
            cout << "Artista: " << nuevaCancion[i].artista << endl;
            cout << "Titulo: " << nuevaCancion[i].titulo << endl;
            cout << "Duracion: " << nuevaCancion[i].duracion.minutos << ":" << nuevaCancion[i].duracion.segundos << endl;
            cout << "Tama" << n << "o: " << nuevaCancion[i].size << endl;
            encontrado = 1;
        }
    }
    if(!encontrado) cout << "No encontramos a ese artista o cancion" << endl;
}

int main(void) {
    Cancion nuevaCancion[100];
    Duracion nuevaDuracion[100];
    int cantC = 0, choice;
    while(1) {
    cout << "Bienvenido a Spotify, que quiere hacer?" << endl;
    cout << "1)Ver las canciones" << endl;
    cout << "2)Agregar una cancion" << endl;
    cout << "3)Buscar una cancion" << endl; //esta parte se encarga de mostrarle al usuario opciones para hacer distintas cosas con las canciones
    cout << "4)Borrar una cancion" << endl;
    cout << "5)Modificar una cancion" << endl;
    cout << "6)Salir" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
        ordenar(nuevaCancion,cantC);
        imprimirCancion(nuevaCancion,cantC);
        break;
        case 2:
        if(cantC == 700) {
            cout << "Llego al maximo de canciones que puede almacenar" << endl;
            break;
        }
        cantC = ingresarCancion(nuevaCancion,cantC,nuevaDuracion);
        break;
        case 3:
        buscarcancion(nuevaCancion,cantC);
        break;
        case 4:
        if(cantC == 0) {cout << "No hay canciones para borrar" << endl;break;}
        cantC = borrarcancion(nuevaCancion,cantC);
        break;
        case 5:
        if(cantC == 0) {cout << "No hay canciones para modificar" << endl;break;}
        modificarCancion(nuevaCancion,cantC);
        break;
        case 6:
        cout << "Chau" << endl;
        return 1;
        default:
        cout << "Elija una opcion correcta" << endl;
        break;
        }
    }
    return 0;
}
