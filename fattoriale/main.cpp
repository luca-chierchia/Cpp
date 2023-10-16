#include <iostream>
using namespace std;

//Si scriva un programma in C++ che preso in input un numero intero positivo n
// (si supponga che l'utente possa inserire solamente numeri interi positivi), calcola il fattoriale di n.

int main() {
    int fattoriale= 1;
    int num;

    do{
        cout<<"Inserire un numero positivo per il calcolo del fattoriale:"<<endl;
        cin>> num;
    }while(num < 0);

    while(1 < num){
        fattoriale = fattoriale * num;
        num--;
        cout<<fattoriale<<endl;
    }

    return 0;
}
