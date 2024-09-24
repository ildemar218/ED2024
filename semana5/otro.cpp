#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int codigo;
    int nota;
    nodo *sig;
};

nodo *cab = nullptr, *aux, *aux2;

bool Codigo_repedido(int codigo) {
    aux = cab;
    while (aux != nullptr) {
        if (aux->codigo == codigo) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}
void registrar(){
    int codigo;
    cout << "Código: ";
    cin >> codigo;

    if (Codigo_repedido(codigo)) {
        cout << "El código ya existe. No se puede registrar el estudiante." << endl;
        return;  // Salir de la función sin registrar
    }
    aux = new nodo;
    cout << "Primer nombre del estudiante: ";
    cin >> aux->nombre;
    cout << "Codigo: ";
    cin >> aux->codigo;
    cout << "Nota: ";
    cin >> aux->nota;
    aux->sig = nullptr;

    if (!cab) {
        cab = aux;
    } else {
        aux2 = cab;
        while (aux2->sig != nullptr) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}

void mostrar() {
    aux = cab;
    cout << "--------- " << endl;
    while (aux != nullptr) { 
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Codigo: " << aux->codigo << endl;
        cout << "Nota: " << aux->nota << endl;
        cout << "--------- " << endl;
        aux = aux->sig;
    }
}

void ordenar() {
    int temporal;
    aux2 = cab;
    while (aux2->sig != nullptr) {
        aux = cab;
        while (aux->sig != nullptr) {
            if (aux->codigo > aux->sig->codigo) {
                temporal = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temporal;
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

void ordenarDoc() {
    int temporal;
    aux2 = cab;
    while (aux2->sig != nullptr) {
        aux = cab;
        while (aux->sig != nullptr) {
            if (aux->nota < aux->sig->nota) {
                temporal = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporal;
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

void promedio(){
    int suma;
    aux2 = cab;
    while(aux2->sig != nullptr){
        aux = aux2 + aux2->sig;
    }
    cout << "Nota: " << aux2 << endl;
    

}

int main() {
    int opcion;
    char respuesta;
    do {
        cout << "Menu" << endl
            << "1. Registrar estudiante" << endl
            << "2. Mostrar estudiantes" << endl
            << "3. Ordenar en base a codigos" << endl
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
                cout << "Ordenado por codigos." << endl;
                mostrar();
                break;
            case 4:
                ordenarDoc();
                cout << "Ordenado por notas." << endl;
                mostrar();
                break;
        }
    } while (opcion != 5);
    return 0;
}
