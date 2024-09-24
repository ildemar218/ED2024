#include <iostream>
using namespace std;

struct nodo {
    int value;
    nodo *sig;
};

nodo *cab, *aux, *aux2;
void registrar(){
    aux = (struct nodo *) malloc (sizeof(nodo));
    cout<<"Documento: ";
    cin>>aux->value;
    aux->sig = NULL;
    if(!cab){
        cab = aux;
    } else {
        aux2=cab;
        while(aux2->sig!=NULL){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}
void mostrar(){
    aux=cab;
    while(aux!=NULL){
        cout<<"Documento: "<<aux->value<<endl;
        aux = aux->sig;
    }
}
int main(){
    int opcion;
    do {
        cout<<"Menu"<<"1. Insertar Datos"<<"2. Mostrar Datos"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrar();
        break;
        case 2:
            mostrar();
        break;
        }
    }while(opcion!=5);
}