#include <iostream>
using namespace std;

// Prima versione
// funzione reverse su un array di interi
void reverse(int arr[],int length){
    int arr_cpy[length];
    for(int i = 0; i< length; i++)
        arr_cpy[i] = arr[length-(i+1)];
    for(int j = 0; j < length; j++)
        arr[j] = arr_cpy[j];

}

// stampa array di interi
void printArr( int a[], int l){
    for( int i = 0; i < l ; i++){
        if ( i != l-1)
            cout << a[i] << "-";
        else
            cout << a[i] << endl;
    }

}

// incrementa di 1 la posizione degli elementi di un array di interi
void ruotaArr(int a[], int l){
    int ultimo = a[l-1];
    int n_arr[l];
    int i = 0;
    int j = 0;
    while( i != l){
        n_arr[j+1] = a[i];
        i++;
        j++;
    }

    n_arr[0] = ultimo;

    for(int i = 0; i < l ; i++)
        a[i] = n_arr[i];

}


// funzione per stabilire la lunghezza di una stringa
int length(char str[]){
   int i = 0;
   int l = 0;
   while( str[i] != '\0'){
       l += 1;
       i++;
   }
   return l;
}

char* trim( char str[], char c){
    char* n_str = new char[length(n_str)+1];
    int i = 0;
    int j = 0;
    while( str[i] != '\0' ){
        if( str[i] != c ){
            n_str[j] = str[i];
            j++;
        }
        i++;
    }
    n_str[j]='\0';
    return n_str;
}



// funzione che conta gli elementi coincidenti per valore ed indice di due array.
int coincide(int a1[],int a2[], int d1, int d2){
    int index_count = 0;
    if( d1 > d2 ){
        for( int i = 0; i < d2 ; i++ ){
            if ( a1[i] == a2[i] )
                index_count +=1;
        }
        return index_count;
    }
    else if ( d2 > d1 ){
        for( int i = 0; i < d1 ; i++ ){
            if ( a1[i] == a2[i] ){
                index_count +=1;
            }

        }
        return index_count;
    }
    else
        return -1;

}



int main() {

  /*
   *   char str[100];
    bool failbit= 0;
    char* n_str = nullptr;


    do{
        cout<<"inserisci stringa max 100 char:" << endl;
        cin.getline(str,100,'\n');
        failbit = cin.fail();
        if (failbit){
            cin.clear();
            cin.ignore(5000,'\n');
        }
    }while(failbit);
    n_str = trim(str,'b');
    cout << " str: " << str << endl;
    cout << " n_str: " << n_str << endl;
   */

   /*
    *  int a[]={2,5,7,43,2234,1,0,11,24};
    printArr(a,9);
    ruotaArr(a,9);
    printArr(a,9);
    */
    return 0;
}
