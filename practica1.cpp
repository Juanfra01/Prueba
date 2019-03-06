#include <iostream>
#include <stdlib.h>
#include <time.h>



using namespace std;

// Definicion de funciones
int pedirValorBuscar();
int pedirDimensionVector();

int *generarVmejor(int,int);
int *generarVpeor(int,int);
int *generarVcualquiera(int,int);
void mostrarDatos(int*, int,string);
int Contar(int*, int, int);

//Funcion principal
int main()
{
    int x;
    int n;
    int *vmejor,*vpeor,*vcualquiera;
    string vm = "vmejor";
    string vp = "vpeor";
    string vc  = "vcualquiera";


    int nvecesMejor;
    int nvecesPeor;
    int nvecesCualquiera;

    x = pedirValorBuscar();
    n = pedirDimensionVector();


    vmejor = generarVmejor(x,n);
    vpeor = generarVpeor(x,n);
    vcualquiera = generarVcualquiera(x,n);

//    Mostramos los vectores
    mostrarDatos(vpeor, n, vp);
    mostrarDatos(vmejor, n, vm);
    mostrarDatos(vcualquiera, n, vc);

    nvecesMejor = Contar(vmejor,x,n);
    nvecesPeor = Contar(vpeor,x,n);
    nvecesCualquiera = Contar(vcualquiera,x,n);

    cout<<endl;
    cout<<"\nCASO PEOR\n"<<"Numero veces: " <<nvecesPeor<<endl;
    cout<<"CASO MEJOR\n"<<"Numero veces: "<<nvecesMejor<<endl;
    cout<<"OTRO CASO\n"<<"Numero veces: "<<nvecesCualquiera;

    delete[] vmejor;//liberamos espacio en memoria utilizado anteriormente
    delete[] vpeor;
    delete[] vcualquiera;
    return 0;
}
//FIN MAIN


int pedirValorBuscar(){
    int x;
    cout<<"Introduce valor a buscar (x):"<<endl;
    cin>>x;
    return x;
}

int pedirDimensionVector(){
    int n;
    cout<<"Introduce n.elementos del vector (n):"<<endl;
    cin>>n;

    return n;
}


int *generarVmejor(int x,int n){
    srand(time(NULL));// Inicializar los número aleatorios
    int *vec;
    vec = new int[n+1];

    for(int i=1;i<=n;i++){
        vec[i] = rand()%(11-1);

        if(vec[i] == x){
        vec[i]-=1;
      }
    }
    return vec;
}

int *generarVpeor(int x, int n){
    int *vec;
    vec = new int[n+1];
    for(int i=1;i<=n;i++){
        vec[i]=x;
    }
    return vec;
}

//Función generar vector cualquiera

int *generarVcualquiera(int x, int n){
    int *vec;
    vec = new int[n+1];
    for(int i=1;i<=n;i++){
        if(i%2 == 0){
            vec[i]=x;
        }else{
            vec[i]= rand()%(11-1);
        }
    }
    return vec;
}

//función muestra
void mostrarDatos(int *vec, int n , string vnombre){
    cout<<"\nVector "<<vnombre<<":"<<endl;
    for(int i=1;i<=n;i++){
        cout<<vec[i];
        if(i!= n){
            cout<<" ";
        }
    }
 }

//fundicon contar
 int Contar(int *vec, int x, int n){
    int nveces,i;

    nveces = 0;
    for(i=1;i<=n;i++){
        if(vec[i] == x){
            nveces++;
        }
    }
    return nveces;
 }
