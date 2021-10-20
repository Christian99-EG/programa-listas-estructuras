// Listas Enlazadas Simples Lineales en C++

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct nodo *Tlista; //tipo lista = Tlista

class nodo
{
public:
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
       nodo();
       ~nodo();

       void insertarInicio(Tlista &lista, int valor);
       void insertarFinal(Tlista &lista, int valor);
       int insertarAntesDespues();
       void insertarElemento(Tlista &lista, int valor, int pos);
       void buscarElemento(Tlista &lista,int valor);
       void reportarLista(Tlista &lista);
       void eliminarElemento(Tlista &lista,int valor);
       void eliminaRepetidos(Tlista &lista, int valor);
       void borrar_lista(Tlista &lista, int valor);
       void Ordenar_lista(Tlista &lista,int valor);
       void Busqueda_posicion(Tlista &lista,int pos);
       void Remplazar_posicion(Tlista &lista,int valor,int pos);
       void insertar_posicion(Tlista &lista,int valor,int pos);
};

nodo::nodo(){}
nodo::~nodo(){}

void nodo::insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}
void nodo::insertarFinal(Tlista &lista, int valor)
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
int nodo::insertarAntesDespues()
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
void nodo::insertarElemento(Tlista &lista, int valor, int pos)
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
void nodo::buscarElemento(Tlista &lista, int valor)
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
void nodo::reportarLista(Tlista &lista) //mostrar lista
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
void nodo::eliminarElemento(Tlista &lista, int valor)
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
void nodo::eliminaRepetidos(Tlista &lista, int valor)
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
void nodo:: borrar_lista(Tlista &lista,int valor)
{
  Tlista p; //crear un nodo auxiliar
  p = lista;
  valor = p -> nro;
  lista = p -> sgte;
  delete(p);
}
void nodo::Ordenar_lista(Tlista &lista,int valor)
{
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
void nodo::Busqueda_posicion(Tlista &lista, int pos)
{

   Tlista q;
   q = lista;
   int i = 1, band = 0,num; //band = bandera de posicion
   while(q != NULL){
     if(pos == i){
           cout<<"En la posicion "<<pos<<" esta el dato "<<q->nro<<endl;
           band = 1;
        }

     q = q -> sgte;
     i++;
   }
    if(band == 0){ cout<<"numero no encontrado \n";}
}
void nodo::Remplazar_posicion(Tlista &lista,int valor,int pos)
{
  Tlista q,dq;
  q = lista;
  int i =1, band = 0;
  dq -> nro;
 while(q != NULL){
   if(pos == i){
     cout<<"En la posicion "<<pos<<" esta el dato "<<q-> nro<<endl;
     //delete(dq);
     q -> nro = valor;
     cout<<"el valor fue cambiado por: "<<q -> nro<<endl;
     band = 1;
   }
   q = q -> sgte;
   i++;
 }
}
 void nodo::insertar_posicion(Tlista &lista,int valor, int pos)
 {
   Tlista q,t;
   q = new (nodo);
   int i, band = 0;
  q -> nro = valor;

  if (pos == 1){
    q-> sgte = lista;
    lista = q;
  }else{
    t = lista;
     for(i = 1;t != NULL;i++){
       if(i == pos-1){
         q -> sgte = t -> sgte;
         t -> sgte = q;
         cout<<"numero insertado \n"<<endl;
         return;
       }
       t = t -> sgte;
     }
  }
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
    cout<<"12. Remplazar valor                  "<<endl;
    cout<<"13. Insertar por posicion            "<<endl;
    cout<<"14. SALIR                            "<<endl;
    cout<<"\n INGRESE OPCION: ";
}
//funcion proceso LISTA
void procesoLista()
{
  nodo ObjNodos;

  Tlista lista = NULL;
  int op;     // opcion del menu
  int _dato;  // elemenento a ingresar
  int pos;    // posicion a insertar

  do{
      menu1();  cin>> op;

      switch(op)
      {

          case 1:

               cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
               ObjNodos.insertarInicio(lista, _dato);
          break;


          case 2:

               cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
               ObjNodos.insertarFinal(lista, _dato );
          break;


          case 3:
               if(lista == NULL){
         cout<<"Actualmente su lista esta vacia... \n";
       }else{
          cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
               cout<< " Posicion : ";       cin>> pos;
               ObjNodos.insertarElemento(lista, _dato, pos);
       }
          break;


          case 4:
               cout << "\n\n MOSTRANDO LISTA\n\n";
               ObjNodos.reportarLista(lista);
          break;


          case 5:
               if(lista == NULL){
               cout<<"Actualmente no tiene datos en su lista...\n";
             }else{
               cout<<"\n Valor a buscar: "; cin>> _dato;
               ObjNodos.buscarElemento(lista, _dato);
             }
          break;

          case 6:
               if(lista == NULL){
                 cout<<"actualmente la lista esta vacia... \n";
               }else{
              cout<<"\n Valor a eliminar: "; cin>> _dato;
              ObjNodos.eliminarElemento(lista, _dato);
            }
          break;

          case 7:

              if(lista == NULL){
               cout<<"Actualmente su lista se encuentra vacia...\n";
            }else{
              cout<<"\n Valor repetido a eliminar: "; cin>> _dato;
              ObjNodos.eliminaRepetidos(lista, _dato);
            }
          break;

          case 8:
           cout<<"ELIMINACION DE LISTA \n";
            if(lista == NULL){
              cout<<"actualmente su lista se encuentra vacia \n";
              cout<<"imposible eliminar lista...\n";
          }else{
            while(lista != NULL){
          ObjNodos.borrar_lista(lista,_dato);
         }
         cout<<"se ha vaciado la lista... \n";
        }
          break;
          case 9:
          if(lista == NULL){
            cout<<"la lista esta actualmente vacia...\n";
          }else{
            cout<<"la lista no esta vacia... actualmente tiene los siguientes elementos:"<<endl;

            ObjNodos.reportarLista(lista);
          }
          break;

          case 10:
           cout<<"ORDENAR LISTA \n";
           if(lista == NULL){
             cout<<"Actualmente la lista se encuentra vacia... \n";
           }else{
             cout<<"ordenando lista \n";
             ObjNodos.Ordenar_lista(lista,_dato);
           }
          break;

          case 11:
          cout<<"BUSQUEDA DE DATOS POR POSICION \n";
          if(lista == NULL){
            cout<<"Actualmente su lista esta vacia...busqueda imposible \n";
          }else{
            cout<<"posicion a buscar: "; cin>>pos;
            ObjNodos.Busqueda_posicion(lista, pos);
          }
          break;

          case 12:
          cout<<"REMPLAZAR VALORES\n";
          if(lista == NULL){

          	cout<<"no se puede modificar un valor de una posicion debido a que su lista esta vacia... \n";

	        }else{

          cout<<"posicion a insertar un nuevo valor: "; cin>>pos;
          cout<<"nuevo valor: "; cin>> _dato;
          ObjNodos.Remplazar_posicion(lista,_dato,pos);
		      }
          break;

          case 13:
          cout<<"INSERTAR POR POSICION \n";
          if(lista == NULL){
            cout<<"lista actualmente vacia \n";
          }else{
            cout<<"dato a insertar: "; cin>>_dato;
            cout<<"posicion: ";cin>>pos;
            ObjNodos.insertar_posicion(lista,_dato,pos);
          }
          break;
      }
      cout<<"\n";
      system("pause");
    }while(op != 14);
      //return 0;
}
int main(void){
	nodo objprincipal;

 procesoLista();
}

