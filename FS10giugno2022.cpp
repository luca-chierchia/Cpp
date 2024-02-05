#include <iostream>
using namespace  std;

/*
 * Esercizio 1 (5pt). Scrivere una funzione di tipo int chiamata compact che, presi come parametri un array di numeri
reali a, il numero n di elementi in a ed un array di numeri reali b, copia nell’array b tutti e soli gli elementi di a che sono
strettamente maggiori della media degli elementi di a. La funzione ritorna il numero di elementi inseriti nell’array b.

Esercizio 2 (12pt). Scrivere una funzione main che legge da tastiera due stringhe s1 e s2 di lunghezza massima 100
caratteri. La funzione deve:
I stampare a video la stringhe s1 e s2;
I stampare a video un messaggio che indica se s1 `e l’anagramma di s2 (per esempio, la stringa "casata" `e anagramma
di "aaacst").
Utilizzare solamente stringhe C-style.

Esercizio 3 (13pt). Scrivere una funzione di tipo int di nome sum che, preso come parametro una lista concatenata
semplice l i cui elementi hanno campo informazione di tipo int, e un intero m, restituisce la somma dei soli valori della
lista che sono multipli di m. Se la lista `e vuota, la funzione ritorna il valore 0. (+2pt se la funzione `e ricorsiva)
 */

//Esercizio 1
int compact(int a[],int b[], int l){
}

//Esercizio 2
int sumArr(int a[], int dim){
    int sum = 0;
    for (int i = 0; i < dim ; i++){
        sum += a[i];
    }
    return sum;
}
int length(char s[]){
    int i = 0;
    int l = 0;
    while ( s[i] != '\0' ){
        l += 1;
        i++;
    }
    return l;
}

bool anagramma(char a[], char b[]){
    int l1 = length(a);
    int l2 = length(b);

    if (l1 != l2)
        return 0;
    else{
        int val_char = 0;
        int a_s1[l1];
        int b_s2[l2];
        int val_str_a = 0;
        int val_str_b = 0;
        int i = 0;
        while( a[i] != '\0' ){
            val_char = a[i] ;
            a_s1[i] = val_char;
            i++;
        }
        i = 0;
        while( b[i] != '\0' ){
            val_char = b[i];
            b_s2[i] = val_char;
            i++;
        }
        val_str_a = sumArr(a_s1,l1);
        val_str_b = sumArr(b_s2, l2);
        if (val_str_b == val_str_a)
            return 1;
        else
            return 0;
    }
}

// Esercizo 3
struct node{
    int data;
    node* succ;
};

void addAtBeggining(node* &l , int n){
    node* elem = new node;
    elem->data = n;
    elem->succ = l;
    l = elem;
}


void printList(node* l){
    if ( l == nullptr)
        cout << "Lista vuota" << endl;
    else{
        while(l->succ != nullptr){
            cout << l->data << " ";
            l = l->succ;
        }
    }
}

int sumIt(node* l , int m){
    int sum = 0;
    if ( l == nullptr )
        return 0;
    else if ( l->succ == nullptr){
        if( l->data%m == 0)
            return l->data;
    }

    else{
            while( l->succ != nullptr){
                if (l->data%m == 0)
                    sum += l->data;
                l = l->succ;
            }
            return sum;
        }
}



int main() {
    //Esercizio 1
    int a[] = {2,4,1,2,5};

    //Esercizio 2
    char str_a[101];
    char str_b[101];
    int l1 = 0;
    int l2 = 0;
    bool failbit = 0;


    do{
        cout << "Inserisci  la stringa a:" << endl;
        cin.getline(str_a,101,'\n');
        failbit = cin.fail();
        if (failbit){
            cin.clear();
            cin.ignore(5000,'\n');
        }
    }while(failbit);
    do{
        cout << "Inserisci  la stringa b:" << endl;
        cin.getline(str_b,101,'\n');
        failbit = cin.fail();
        if (failbit){
            cin.clear();
            cin.ignore(5000,'\n');
        }
    }while(failbit);

    l1 = length(str_a);
    l2 = length(str_b);
    cout << str_a << endl;
    cout << str_b << endl;

    if(anagramma(str_a,str_b))
        cout << "Le due stringhe sono anagrammi " << endl;
    else
        cout << "Le due stringhe non sonno anagrammi" << endl;

// Esercizio 3
    node* l = new node;
    int somma = 0;
    addAtBeggining(l,1);
    addAtBeggining(l, 4);
    addAtBeggining( l,6);
    somma = sumIt(l,3);
    cout << somma << endl;



    return 0;
}
