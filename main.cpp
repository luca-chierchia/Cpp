#include <iostream>
using namespace std;

int main() {
    float op1,op2;
    int operatore;
    float somma,differenza;

    cout<<"Ciao sono una calcolatrice."<<endl;
    cout<<"Inserisci i primi due operandi :"<<endl;
    cin>>op1>>op2;
    cout<<"Inserisci l'operando 1 per sommare o 2 per la differenza"<<endl;
    cin>>operatore;

    if( operatore == 1 || operatore == 2 ){
        if ( operatore == 1 ){
            somma= op1 + op2;
            cout<<somma;
        }
        else if (operatore == 2){
            differenza= op1 - op2;
            cout<<differenza;
        }
    }
    else
        cout<<"operazione non valida!";

    return 0;
}
