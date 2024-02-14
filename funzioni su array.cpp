#include <iostream>
using namespace std;

// Elenco funzioni su array


//funzione per incrementare array dinamico
void incrementaArr(int* &a, int &dim){
    int* arr_cpy = new int[dim * 2];
    for( int i = 0; i < dim; i++ )
        arr_cpy[i] = a[i];
    delete [] a;
    a = arr_cpy;
    dim *= 2;
}

// Funzione booleana per trovare sottosequenze nell'array , ritorna true se presenti altrimenti false.
bool hasZeroSum(int a[], int l){

    for( int i = 0; i < l ; i++ ){
        int sommaParziale = 0;

        for( int j = 0; j < l ; j++ ){
            sommaParziale = a[i] + a[j];

            if( sommaParziale == 0 )
                return 1;
        }
    }
    return 0;
}

// Funzione di ricerca max/min in un array
int maxOfArr(int a[], int l){
    int max = 0;

    for( int i = 0; i < l ; i++){

        if( max < a[i])
            max = a[i];
    }

    return max;
}

int minOfArr(int a[], int l){
    int min = a[0];

    for( int i = 0; i < l ; i++){

        if( min > a[i])
            min = a[i];
    }

    return min;
}

// funzione che copia elementi in un array senza duplicati
int compact2(int a[], int b[], int n) {
    if( n <= 0)
        return 0;

    int cursore = 1;
    b[0] = a[0];

    for( int i = 0; i < n ; i++){
        bool doppio = 0;

        for( int j = 0; j < cursore ; j++){
            if(a[i] == b[j]){
                doppio = 1;
                break;
            }
        }
        if(!doppio){
            b[cursore] = a[i];
            cursore++;
        }

    }
    return cursore;
}

// funzione per contare il numero delle sottosequenze delle somme pari a 0 in un array
int getZeroSubSequ( int a[], int l){
    int subSequ = 0;

    for( int i = 0; i < l ; i++){
        int sommaParziale = 0;

        for( int j = 0; j < l ; j++ ){
            sommaParziale = a[i] + a[j];

            if(sommaParziale == 0)
                subSequ += 1;

        }
    }
    return subSequ/2;
}

// Funzione che cerca se i valori e gli indici di un array sono coincidenti
int coincide(int a1[], int a2[], int dim1, int dim2){
     int coincide = 0;

     if( dim1 > dim2){

         for( int i = 0; i < dim2 ; i++){

             if( a1[i] == a2[i])
                 coincide += 1;
         }
     }
     else{

         for( int j = 0; j < dim1 ; j++ ){

             if( a1[j] == a2[j] )
                 coincide += 1;
         }
     }
     return coincide;
}

// funzione per ruotare di una poszione gli elementi di un array
void ruotaArr(int a[], int dim){
    int arr_cpy[dim];
    arr_cpy[0] = a[dim-1];

    for( int i = 0; i < dim ; i++ )
        arr_cpy[i + 1] = a[i];

    for( int j = 0; j < dim ; j++ )
        a[j] = arr_cpy[j];

}

// Funzione per determinare la frequenza di massima di un valore all'interno di un array
int mostFrrequent(int a[], int dim){
    int frequMax = 0;
    int mostFrequ = 0;

    for( int i = 0; i < dim ; i++){
        int frequ = 0;

        for( int j = 0; j < dim ; j++){
            if( a[j] == a[i] )
                frequ++;

        }

        if( frequ > frequMax ){
            frequMax = frequ;
            mostFrequ = a[i];
        }
    }
    return mostFrequ;

}

// funzione che copia da un array a i valori che hanno una media strettamente maggiore degli elementi di a in un array b
int compact( int a[], int b[], int n){
    int cursor = 0;
    float media = 0;
    int somma = 0;

    for( int i = 0; i < n ; i++)
         somma += a[i];

    media = somma/n;

    for( int j = 0; j < n; j++ ){
        if( a[j] > media ){
            b[cursor] = a[j];
            cursor++;
        }
    }
    return cursor;
}

// funzione reverse su array
void reverse(int a[], int dim){
    int a_cpy[dim];

    for( int i = 0; i < dim ; i++)
        a_cpy[i] = a[(dim-1)-i];

    for( int j = 0 ; j < dim ; j++)
        a[j] = a_cpy[j];

}

//funzione che ritorna il numero di sottosequenze all'interno di un array di valore k
int subSequ(int a[], int dim, int k){
    int countSubS = 0;

    for( int i = 0; i < dim; i++){
        int sommaParziale = 0;

        for(int j = 0; j < dim ; j++){
            sommaParziale = a[i] + a[j];

            if(sommaParziale == k)
                countSubS++;

        }

    }
    return countSubS;
}

int main() {

    int c[] = {1,2,3,4,5};
    int b[] = {2,34,-1,5,3,111,3,56,3};
    int a[] = {-11,55,-3,8,3,11};
    int d[5];
    int f[9];
    int massimo = maxOfArr(a,6);
    int minimo = minOfArr(a,6);
    cout << "Max: " << massimo << ", " << "Min: " << minimo << endl;

    if(hasZeroSum(a,6))
        cout << "Ci sono somme pari a 0" << endl;
    else
        cout << "Non ci sono somme pari a 0" << endl;


    int sottoSeq = getZeroSubSequ(a,6);
    cout << sottoSeq << endl;

    int concidenze = coincide(a,b,6,9);
    cout << concidenze << endl;

    ruotaArr(c,5);
    for( int i = 0; i < 5 ; i++)
        cout << c[i] << " ";
    cout << endl;

    int mf = mostFrrequent(a,5);
    cout << "L'elemento più frequente dell'array è: " << mf << endl;

    int cur = compact(a,d,6);
    cout << cur << endl;
    for( int i = 0; i < cur ; i++)
        cout << d[i] << " ";
    cout << endl;

    for( int i = 0; i < 5; i++)
        cout << c[i] << " ";
    cout << endl;

    reverse(c,5);

    for( int i = 0; i < 5; i++)
        cout << c[i] << " ";
    cout << endl;

    int subS = subSequ(a,5,5);
    cout << subS << endl;

    int compact = compact2(b,f,9);
    cout << compact << endl;
    for( int i = 0; i < compact; i++)
        cout << f[i] << " ";
    cout << endl;




    return 0;
}
