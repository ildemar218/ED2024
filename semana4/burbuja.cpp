#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int telefono;
    int documento;
    nodo *sig;
};

nodo *cab, *aux, *aux2;
void registrar(){
    aux = (struct nodo *) malloc (sizeof(nodo));
    cout<<"primer nombre del estudiante: ";
    cin>>aux->nombre;
    cout<<"telefono: ";
    cin>>aux->telefono;
    cout<<"documento: ";
    cin>>aux->documento;
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
    cout<<"--------- "<<endl;
    while(aux!=NULL){
        cout<<"nombre: "<<aux->nombre<<endl;
        cout<<"telefono: "<<aux->telefono<<endl;
        cout<<"documento: "<<aux->documento<<endl;
        cout<<"--------- "<<endl;
        aux = aux->sig;
    }
}
void ordenar(){
    int temporal;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux = cab;
        while(aux->sig!=NULL){
            if(aux->telefono>aux->sig->telefono){
                temporal = aux->telefono;
                aux->telefono = aux->sig->telefono;
                aux->sig->telefono = temporal;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}

void ordenarDoc(){
    int temporal;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux = cab;
        while(aux->sig!=NULL){
            if(aux->documento>aux->sig->documento){
                temporal = aux->documento;
                aux->documento = aux->sig->documento;
                aux->sig->documento = temporal;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}
int main(){
    int opcion;
    char respuesta;
    do {
        cout<<"Menu"<<endl<<"1. Insertar Contacto"<<endl<<"2. Mostrar Contactos"<<endl<<"3. Ordenar en base a telefonos"<<endl<<"4. Ordenar en base a documentos"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
        do{
            registrar();
            cout<<"desea agregar otro estudiante? (s/n)";
            cin>>respuesta;
            }while (respuesta == 's' || respuesta == 'S');
        break;
        case 2:
            mostrar();
        break;
        case 3:
            ordenar();
        break;
        case 4:
            ordenarDoc();
        break;
        }
    }while(opcion!=5);
}