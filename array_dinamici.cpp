#include <iostream>
using namespace  std;

void incrementaDim(int* &a,int &dim){
    int* n_arr = new int[dim*2];
    for(int i = 0; i < dim ; i++){
        n_arr[i] = a[i];
    }
    delete [] a;
    a = n_arr;
    dim *= 2;
}

int* arrWithRange(int* a, int dim, int max, int min){
    int* arr_din = new int [dim*2];
    for( int i = 0 ; i < dim ; i++ ){
        if( a[i] < max && a[i] > min )
            arr_din[i] = a[i];
    }
    
    dim *= 2;
    return arr_din;

}

int maxOfArr(int* a, int cursore){
    int max = 0;
    for( int i = 0; i < cursore ; i++){
        if ( a[i] > max )
            max = a[i];
    }
    return max;
}

int minOfArr(int* a, int cursore){
    int min = 10000000;
    for( int i = 0; i < cursore ; i++){
        if ( a[i] < min )
            min = a[i];
    }
    return min;
}

int main() {
    int cursore = 0;
    int dim = 2;
    int dim1 = 2;
    int x = 0;
    int max = 0;
    int min = 0;
    bool failbit = 0;
    int* arr_b = new int[dim1];
    int* arr = new int[dim];

    do{
        cout << "Inserisci valori interi maggiori di 0:" << endl;
        cin >> x;
        failbit = cin.fail();
        if (failbit){
            cin.clear();
            cin.ignore(5000,'\n');
        }
        if( x >= 0 ){
            if( cursore >= dim){
                incrementaDim(arr,dim);
            }
            arr[cursore] = x;
            cursore++;

        }
    }while(x>=0 || failbit);

    for(int j = 0; j < cursore; j++){
        if ( j == cursore-1 )
            cout << arr[j] ;
        else
            cout << arr[j] << "-" ;
    }
    cout << endl;
    max = maxOfArr(arr,cursore);
    min = minOfArr(arr,cursore);
    cout << max << endl;
    cout<< min << endl;
    arr_b = arrWithRange(arr,dim,max,min);

    for(int j = 0; j < cursore; j++){
        if ( j == cursore-1 )
            cout << arr_b[j] ;
        else if (arr_b[j] == 0)
            continue;
        else
            cout << arr_b[j] << "-" ;
    }
    cout << endl;

    for(int j = 0; j < cursore; j++){
        if ( j == cursore-1 )
            cout << arr[j] ;
        else
            cout << arr[j] << "-" ;
    }
    cout << endl;
    return 0;
}
