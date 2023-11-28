#include <iostream>
#include <cstring>
using namespace std;

/*
 * Task 6
Separa
Deadline: 28/11/2023 ore 23.59
a) Scrivere una funzione di nome separa che, presi in input una stringa s e due array di caratteri alpha e
num, memorizza in alpha i caratteri alfabetici della stringa s e in num i caratteri numerici della stringa s.
Tutti gli altri caratteri vengono scartati. La funzione deve restituire il numero di elementi memorizzati in
alpha e il numero di elementi memorizzati in num.
b) Scrivere una funzione main che legge da standard input una stringa str di massimo 100 caratteri e,
utilizzando obbligatoriamente la funzione separa, suddivide i caratteri presenti in str in due array
SAlpha e SNum, rispettivamente di caratteri alfabetici e numerici. Infine, stampare i due array a video.
NB:
- La funzione separa non deve contenere comandi di stampa
- Non è consentito usare variabili globali
- La funzione può avere altri parametri oltre a quelli indicati nel testo
- È consentito utilizzare la libreria cctype (https://www.cplusplus.com/reference/cctype/)
- Qualsiasi altra scelta implementativa è lasciata allo/alla studente/studentessa
Esempio di esecuzione (in grassetto gli input inseriti dall’utente)
Inserisci una stringa: 2h3lloWorld 645e1{s}
Caratteri alfabetici
h l l o W o r l d e s
Caratteri numerici
2 3 6 4 5 1
 */

char separa(char str[],char SAlpha[],char SNum[]){
    int i=0;
    int j=0;
    int k=0;
    while(str[i]!='\0'){
        if((str[i]>=0 && str[i]<=47) || (str[i]>=123 && str[i]<=255) ){
            i++;
            continue;
        }
        else if(isalpha(str[i])) {
            SAlpha[j] = str[i];
            j++;
        }
        else if(isdigit(str[i])){
            SNum[k]=str[i];
            k++;
        }

        i++;
    }
    return 0;
}

void stampa(char str[] ,char SAlpha[], char SNum[]){
    cout<<"Caratteri Alfabetici:"<<endl;
    for(int i=0;i< strlen(SAlpha);i++){
            cout<<SAlpha[i];
    }
    cout<<endl;
    cout<<"Caratteri Numerici:"<<endl;
    for(int i=0;i< strlen(SNum);i++){
            cout<<SNum[i];
    }
    cout<<endl;
}

int main() {
    char str[100];
    char a[100];
    char b[100];
    bool failed=0;

       cout<<"Inserisci una stringa contenente diversi tipi di carattere:"<<endl;
       cin.getline(str,100,'\n');
        failed=cin.fail();
       if(failed){
           cin.clear();
           cin.ignore(5000,'\n');
       }
       separa(str,a,b);
       stampa(str,a,b);



    return 0;
}
