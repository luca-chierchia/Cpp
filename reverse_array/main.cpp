#include <iostream>
using namespace std;
/*
 * Scrivi un programma in C++ che legga un numero n da tastiera e memorizzi n numeri interi in un array a.
 * Successivamente, il programma deve invertire l'ordine degli elementi dell'array a senza utilizzare altri array di supporto.
 * In altre parole, l'array a deve essere invertito direttamente nello stesso array (e.g., se a = [1, 2, 3, 4, 5],
 * dopo l'esecuzione, a sarà [5, 4, 3, 2, 1]).
 */
int main() {
    int n=0;
    int valori=0;
    int t=0;
    int t1=0;
    int j=0;


    cout<<"Inserisci un valore intero, che corrisponde alla grandezza dell'array"<<endl;
    cin>>n;
    int array[n]={};
    int k=n-1;



        for(int i=0;i<n;i++){
                cout << "Inserisci i valori interi all'interno dell'array:" << endl;
                cin >> valori;
                array[i] = valori;
        };

        while(k-j!=0 &&k-j!=1){
            t=array[j];
            t1=array[k];
            array[k]=t;
            array[j]=t1;
            k--;
            j++;
        }
        t=array[j];
        t1=array[k];
        array[k]=t;
        array[j]=t1;

        cout<<"Array Reverse:"<<endl;
        for(int i=0;i<n;i++){
            cout<<'['<<i<<']'<<array[i]<<endl;

        }

    return 0;
}
