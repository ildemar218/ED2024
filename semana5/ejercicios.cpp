#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int codigo;
    int nota;
    nodo *sig;
};

nodo *cab = nullptr, *aux, *aux2;


void registrar(){
    aux = new nodo(); // Usamos new en lugar de malloc
    cout << "Primer nombre del estudiante: ";
    cin >> aux->nombre;
    cout << "Código: ";
    cin >> aux->codigo;
    cout << "Nota: ";
    cin >> aux->nota;
    aux->sig = nullptr;

    if(!cab){
        cab = aux;
    } else {
        aux2 = cab;
        while(aux2->sig != nullptr){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}

void mostrar(){
    aux = cab;
    cout << "--------- " << endl;
    while(aux != nullptr){
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Código: " << aux->codigo << endl;
        cout << "Nota: " << aux->nota << endl;
        cout << "--------- " << endl;
        aux = aux->sig;
    }
}

void ordenar(){
    aux2 = cab;
    while(aux2 != nullptr){
        aux = cab;
        while(aux->sig != nullptr){
            if(aux->codigo > aux->sig->codigo){
                swap(aux->codigo, aux->sig->codigo);
                swap(aux->nombre, aux->sig->nombre);
                swap(aux->nota, aux->sig->nota);
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

void ordenarDoc(){
    aux2 = cab;
    while(aux2 != nullptr){
        aux = cab;
        while(aux->sig != nullptr){
            if(aux->nota < aux->sig->nota){
                swap(aux->nota, aux->sig->nota);
                swap(aux->codigo, aux->sig->codigo);
                swap(aux->nombre, aux->sig->nombre);
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

int main(){
    int opcion;
    char respuesta;
    do {
        cout << "Menú" << endl
             << "1. Registrar estudiante" << endl
             << "2. Mostrar estudiantes" << endl
             << "3. Ordenar en base a códigos" << endl
             << "4. Ordenar en base a notas" << endl
             << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                do {
                    registrar();
                    cout << "¿Desea agregar otro estudiante? (s/n): ";
                    cin >> respuesta;
                } while (respuesta == 's' || respuesta == 'S');
                break;

            case 2:
                mostrar();
                break;

            case 3:
                ordenar();
                cout << "Ordenado por códigos." << endl;
                mostrar();
                break;

            case 4:
                ordenarDoc();
                cout << "Ordenado por notas." << endl;
                mostrar();
                break;
        }
    } while(opcion != 5);

    return 0;
}
