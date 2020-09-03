#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void lectura();
void escritura();
int mitad (int arr[], int pinicial, int pfinal);
void ordenar(int arr[], int pinicial, int pfinal);

int main() {
escritura();
lectura();

system("pause");
return 0;
}

void lectura(){
        ifstream archivo;
        string texto, lect;
        int op2;
        do{
        cout<<"Menu\n1.- Leer Registro\n2.- Salir   → ";
        cin >>op2;
        cin.ignore();
        if(op2==1){
        /*cout<<"\nQue texto desea ver: ";
        getline(cin, lect);*/

        archivo.open("QUICKSORT.txt", ios::in);
        if(archivo.fail()){
                cout<<"No se logro encontrar el archivo...";
                exit(1);
        }

        while(!archivo.eof()){    //leyendo todo
                getline(archivo, texto);
                cout<<texto<<endl;
        }cin.ignore();
archivo.close();
        }
        }while(op2!=2);
cout <<"Gracias por utilizar el programa..";
}

void escritura(){
        ofstream archivo2;
        string lectura, texto1,nombre,apellido,telefono;
        int op, x, a[x];
        cout<< "Ingrese el tamaño del arreglo: ";
        cin>>x;
        for(int i=0; i<x; i++){
                cout<<"Posicion["<<i<<"]: ";
                cin>>a[i];
        }
        archivo2.open("QUICKSORT.txt", ios::app);

        if(archivo2.fail()){
                cout << "No se pudo crear...";
                exit(1);
        }

        cout<<"1.- Guardar registro\n2.- salir: ";
        cin>>op;
        if(op == 1){
                archivo2<<"\nOriginal: ";
                for(int i=0; i<x;i++)
    {
        archivo2<<"|"<<a[i]<<"|";
    }
        
        ordenar(a,0,x);
        archivo2<<"\nOrdenado: ";
                for(int i=0; i<x;i++)
    {
        archivo2<<"|"<<a[i]<<"|";
    }
                cin.ignore();
                system ("cls");
                  cout << "Guardado con exito...\n";
                  /*system ("pause");
                  system ("cls");*/
        }
        archivo2.close();
}
int mitad (int arr[], int pinicial,  int pfinal)
{
    return arr[(pinicial+pfinal)/2];
}






void ordenar(int arr[], int pinicial, int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(arr,pinicial,pfinal);

    do
    {
        while(arr[i]<piv)
        {
            i++;
        }
        while(arr[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }

    }
    while(i<=j);

    if(pinicial<j)
        ordenar(arr,pinicial,j);
    if(i<pfinal)
        ordenar(arr,i,pfinal);
}