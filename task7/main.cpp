#include <iostream>
using namespace std;

/*
 * Task 7
Array con elementi condivisi
Deadline: 05/12/2023 ore 23.59
Scrivere una funzione main che legge da tastiera una sequenza di numeri interi positivi, fino ad incontrare un
numero negativo, e li memorizza uno alla volta in un array A di puntatori a interi (dimensione massima: 1000
elementi) nel seguente modo:
- per ogni intero x letto, se x non è presente in A, alloca una variabile dinamica in cui memorizza x e
aggiunge in fondo all’array A il puntatore alla nuova variabile;
- se x è già presente in A, aggiunge ad A il puntatore alla variabile contenente x (senza allocare una nuova
variabile dinamica).
Dopodiché, la funzione deve stampare il numero di variabili allocate e la sequenza dei valori memorizzati in A
Esempio di esecuzione (1)
Inserire un numero: 4
Inserire un numero: 5
Inserire un numero: 4
Inserire un numero: 4
Inserire un numero: 3
Inserire un numero: 2
Inserire un numero: 2
Inserire un numero: 4
Inserire un numero: 6
Inserire un numero: 7
Inserire un numero: -1
Allocate 6 variabili.
4 5 4 4 3 2 2 4 6 7
 */

//funzione puntatore , che ritorna come risultato l'indirizzo del puntatore che punta al valore x , va a vedere dove si trova e lo recupera,
// altrimenti setta il puntatore come nullptr per poter allocare una nuova variabile.
int* cercaValore( int* arr[],int index,int x){
    for(int y = 0;y < index; y++){
        if(*(arr[y]) == x) //valore trovato
            return arr[y];
    }
    //se non trovo nulla setto il ptr a nullptr
    return nullptr;
}

// funzione che rileva se ci sono indirizzi doppi in fase di deallocazione

bool doppio(int* ptr,int* arr[],int len,int index){
    ptr=arr[index];
    int conta=0;
    for(index;index<len;index++){
        if(ptr==arr[index])
            conta+=1;
    }
    if(conta>1)
        return 1;
    else
        return 0;
}


int main() {

    int* ptr[1000];
    int x=0;
    int variabiliDeallocate=0;
    int variabiliAllocate=0;
    int input_valori=0; //variabile utilizzata per capire quanti input di x avevo dato xD.
    int cursore=0;

    do{
        cout<<"Inserire dei numeri interi maggiori o uguali a 0:"<<endl;
        cin>>x;
        input_valori++;
        if(x<0)
            break;
        else if(cursore==0 ) {//vuol dire che iniziamo ad inserire il primo elemento
            ptr[cursore]=new int;
            *(ptr[cursore])=x;
            variabiliAllocate++;
        }
        else if(cursore>0){
            int* ptr_a= cercaValore(ptr,cursore,x);
            //cerco prima se è presento un valore uguale a cui puntano i puntatori
            if(!ptr_a){
                ptr[cursore]=new int;
                *ptr[cursore]=x;
                variabiliAllocate++;
            }
            else
                ptr[cursore]=ptr_a;
        }
        cursore++;
    }while(x>=0);
    cout<<"Hai inserito :"<<input_valori-1<<" valori"<<endl;
    cout<<"Hai allocato :"<<variabiliAllocate<<" variabili"<<endl;
    for(int i=0;i<cursore;i++)
        cout<<"["<<i<<"]"<<*(*(ptr+i))<<" ";
    cout<<endl;
    for(int i=0;i<cursore;i++){
        cout<<"ptr: "<<ptr[i]<<", value: "<<*(ptr[i])<<endl;
    }
    cout<<endl;


    for(int i=0; i<cursore;i++){

        int* ptr_b;
        if(doppio(ptr_b,ptr,cursore,i))
            continue;
        else{
            variabiliDeallocate+=1;
            delete ptr[i];
        }
    }

    cout<<"Dopo deallocazione dei puntatori nell 'array di puntatori:"<<endl;
    cout<<"Hai deallocato: "<<variabiliDeallocate<<" variabili"<<endl;
    for(int i=0;i<cursore;i++){
        cout<<"ptr: "<<ptr[i]<<", value: "<<*(ptr[i])<<endl;
    }
    return 0;
}
