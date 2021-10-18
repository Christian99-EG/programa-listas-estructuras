
// Listas Enlazadas Simples Lineales en C++

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct nodo
{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *Tlista; //tipo lista = Tlista

void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}

void insertarFinal(Tlista &lista, int valor)
{
    Tlista t, q = new(struct nodo);

    q->nro  = valor;
    q->sgte = NULL;

    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }

}

int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;

    cout<<"\n\t Opcion : "; cin>> _op;

    if(_op==1)
        band = -1;
    else
        band = 0;

    return band;
}

void insertarElemento(Tlista &lista, int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;

    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;

        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}

void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

/*    if(q == NULL){
      //system("cls"); //borra la pantalla clear - screen
      cout<<"Actualmente su lista se encuentra vacia...ERROR \n";
    } */

    while(q!=NULL){
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0){
        cout<<"\n\n Numero no encontrado..!"<< endl;
    //system("pause");
  }
}

void reportarLista(Tlista lista) //mostrar lista
{
     int i = 0;
     if (lista !=NULL)
     while(lista != NULL)
     {
          cout <<' '<< (i+1) <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
     else
       cout<<"Lista vacia"<<endl;
}


void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
}

void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }

    }// fin del while

    cout<<"\n\n Valor repetido "<< valor << "fue eliminado..! \n"<<endl;
    //system("pause");
}

void borrar_lista(Tlista &lista,int valor){
  Tlista p; //crear un nodo auxiliar
  p = lista;
  valor = p -> nro;
  lista = p -> sgte;
  delete(p);
}

Ordenar_lista(Tlista &lista,int valor){
  Tlista act,sig;
  act = lista;
  int t;

  while(act -> sgte != NULL){
    sig = act -> sgte;
     while(sig != NULL){
       if(act -> nro < sig -> nro){
         t = sig -> nro;
         sig -> nro = act -> nro;
         act -> nro = t;
       }
       sig =  sig -> sgte;
     }
     act = act -> sgte;
      sig = act -> sgte;
  }
  cout<<"lista ordenada \n";
}

Busqueda_posicion(Tlista &lista, int pos){

   Tlista q;
   q = lista;
   int i = 1, band = 0, num; //band = bandera de posicion

   while(q != NULL){
     if(pos == i){
           cout<<"En la posicion "<<pos<<" esta el dato "<<q -> nro<<endl;
           band = 1;
        }

     q = q -> sgte;
     i++;
   }
    if(band == 0){ cout<<"numero no encontrado \n";}
}
void menu1()
{
    system("cls");
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION (DIFERENTE A LA POSICION 1)"<<endl;
    cout<<" 4. MOSTRAR LISTA                   "<<endl;
    cout<<" 5. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 6. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 7. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 8. ELIMINAR LISTA COMPLETA          "<<endl;
    cout<<" 9. COMPROBAR SI LA LISTA ESTA VACIA "<<endl;
    cout<<"10. Ordenar lista                    "<<endl;
    cout<<"11. Buscar por posicion              "<<endl;
    cout<<"12. SALIR                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}


/*                        Funcion Principal
---------------------------------------------------------------------*/

int main(void){

    Tlista lista = NULL;
    int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar


    //system("color 0b");

    do{
        menu1();  cin>> op;

        switch(op){

            case 1:

                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarInicio(lista, _dato);
            break;


            case 2:

                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarFinal(lista, _dato );
            break;


            case 3:

                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                 cout<< " Posicion : ";       cin>> pos;
                 insertarElemento(lista, _dato, pos);
            break;


            case 4:
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 reportarLista(lista);
            break;


            case 5:
                 if(lista == NULL){
                 cout<<"Actualmente no tiene datos en su lista...ERROR \n";
               }else{
                 cout<<"\n Valor a buscar: "; cin>> _dato;
                 buscarElemento(lista, _dato);
               }
            break;

            case 6:
                 if(lista == NULL){
                   cout<<"actualmente la lista esta vacia... \n";
                 }else{
                cout<<"\n Valor a eliminar: "; cin>> _dato;
                eliminarElemento(lista, _dato);
              }
            break;

            case 7:

                if(lista == NULL){
                 cout<<"Actualmente su lista se encuentra vacia... ERROR \n";
              }else{
                cout<<"\n Valor repetido a eliminar: "; cin>> _dato;
                eliminaRepetidos(lista, _dato);
              }
            break;

            case 8:
             cout<<"ELIMINACION DE LISTA \n";
            	if(lista == NULL){
            		cout<<"actualmente su lista se encuentra vacia \n";
            		cout<<"imposible eliminar lista...ERROR! \n";
       			}else{
              while(lista != NULL){
       			borrar_lista(lista,_dato);
           }
           cout<<"se ha vaciado la lista... \n";
          }
            break;
            case 9:
            if(lista == NULL){
              cout<<"la lista esta actualmente vacia...\n";
            }else{
              cout<<"la lista no esta vacia... actualmente tiene los siguientes elementos:"<<endl;

              reportarLista(lista);
            }
            break;

            case 10:
             cout<<"ORDENAR LISTA \n";
             if(lista == NULL){
               cout<<"Actualmente la lista se encuentra vacia... \n";
             }else{
               cout<<"ordenando lista \n";
               Ordenar_lista(lista,_dato);
             }
            break;

            case 11:
            cout<<"BUSQUEDA DE DATOS POR POSICION \n";
            if(lista == NULL){
              cout<<"Actualmente su lista esta vacia...busqueda imposible \n";
            }else{
              cout<<"posicion a buscar: "; cin>>pos;
              Busqueda_posicion(lista, pos);
            }
            break;


        }
        cout<<"\n";
        system("pause");
      }while(op != 11);
        //return 0;
    }

