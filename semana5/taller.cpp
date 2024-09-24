#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int codigo;
    int nota;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

bool Codigo_repedido(int codigo) { // valida si el codigo ya se encuentra en la lista retornando un fals o un true
    aux = cab;
    while (aux != nullptr) {
        if (aux->codigo == codigo) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}
void registrar(){ // funcion para agregar un nuevo estudiante a la lista 
    int codigo;
    cout << "Codigo: ";
    cin >> codigo;
    if (Codigo_repedido(codigo)) {// llama a la funcion para ver si el codigo ya esta en la lista
        cout << "El codigo ya existe" << endl;
        return;  
    }
    aux = new nodo;
    aux->codigo = codigo;
    cout<<"primer nombre del estudiante: ";
    cin>>aux->nombre;
    cout<<"nota: ";
    cin>>aux->nota;
    aux->sig = nullptr;
    if(!cab){
        cab = aux;
    } else {
        aux2=cab;
        while(aux2->sig!=nullptr){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
    
}
void mostrar(){ // recorre la lista para mostrar los estudiantes codigos y notas
    aux=cab;
    cout<<"--------- "<<endl;
    while(aux!=nullptr){
        cout<<"nombre: "<<aux->nombre<<endl;
        cout<<"codigo: "<<aux->codigo<<endl;
        cout<<"nota: "<<aux->nota<<endl;
        cout<<"--------- "<<endl;
        aux = aux->sig;
    }
}
void ordenar(){
    int temporal;
    aux2 = cab;
    while(aux2->sig!=nullptr){
        aux = cab;
        while(aux->sig!=nullptr){
            if(aux->codigo>aux->sig->codigo){
                temporal = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temporal;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}

void ordenarDoc(){
    int temporal;
    aux2 = cab;
    while(aux2->sig!=nullptr){
        aux = cab;
        while(aux->sig!=nullptr){
            if(aux->nota<aux->sig->nota){
                temporal = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporal;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}

void calcularmayorymenor() {     aux = cab;
    int mayor = aux->nota;
    int menor = aux->nota;
    string nombreMayor = aux->nombre;
    string nombreMenor = aux->nombre;
    int codigoMayor = aux->codigo;
    int codigoMenor = aux->codigo;
    aux = aux->sig; 
    while (aux != nullptr) {
        if (aux->nota > mayor) {
            mayor = aux->nota;
            nombreMayor = aux->nombre; 
            codigoMayor = aux->codigo; 
        }
        if (aux->nota < menor) {
            menor = aux->nota;
            nombreMenor = aux->nombre;
            codigoMenor = aux->codigo; 
        }
        aux = aux->sig;
    }
    cout << "La nota mayor es: "<< mayor <<" Estudiante: "<< nombreMayor << ", Codigo: "<< codigoMayor << endl;
    cout << "La nota menor es: "<< menor <<" Estudiante: "<< nombreMenor << ", Codigo: "<< codigoMenor << endl;
}

int main(){
    int opcion;
    char respuesta;
    do {
        cout << "Menu" << endl
            << "1. Registrar estudiante" << endl
            << "2. Mostrar estudiantes" << endl
            << "3. Ordenar en base a codigos" << endl
            << "4. Ordenar en base a notas" << endl
            << "5. clacular mayor y menor" << endl
            << "6. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                do {
                    registrar();
                    cout << "Desea agregar otro estudiante? (s/n): ";
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
            case 5:
                calcularmayorymenor();
                break;
        }
    } while(opcion != 6);

    return 0;
}