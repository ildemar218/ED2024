void obtenerNotaMayor(){
    if(!cab){
        cout<<"El estudiante no esta registrado"<<endl;
    }
    nota=cab;
    double notaMayor=cab->notaEstudiante;
    while(nota!= NULL)
    if(nota->notaEstudiante > notaMayor ){
        notaMayor=nota->notaEstudiante;
    }
    nota=nota->sig;    
}