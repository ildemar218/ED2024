#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int codigo_estudiante;
    float nota;
    nodo *sig;
};

nodo *cab, *aux, *aux2;
void registrar(){
    aux = (struct nodo *) malloc (sizeof(nodo));

    cout<<"codigo del estudiante: ";
    cin>>aux->codigo_estudiante;
    cout<<"nota: ";
    cin>>aux->nota;
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
        cout<<"nombre del estudiante: "<<aux->nombre<<endl;
        cout<<"codigo_estudiante: "<<aux->codigo_estudiante<<endl;
        cout<<"nota: "<<aux->nota<<endl;
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
            if(aux->codigo_estudiante>aux->sig->codigo_estudiante){
                temporal = aux->codigo_estudiante;
                aux->codigo_estudiante = aux->sig->codigo_estudiante;
                aux->sig->codigo_estudiante = temporal;
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
            if(aux->nota>aux->sig->nota){
                temporal = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporal;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}

int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Insertar Contacto"<<endl<<"2. Mostrar Contactos"<<endl<<"3. Ordenar en base a telefonos"<<endl<<"4. Ordenar en base a documentos"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrar();
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