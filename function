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
    int arr1[] = {489,4,3,43,5};
    int arr2[]= {2,443,54,3,5};
    int arr3[]= {2,443,34,22,5,8};
    int x = coincide(arr2,arr3,5,6);
    cout << x << endl;
    return 0;
}
