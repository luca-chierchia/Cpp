#include <iostream>
using namespace std;

int main() {
    int i= 0;
    int j= 1;
    cout<<"Inserisci un valore intero :"<<endl;
    int num;
    cin>>num;

    while( j < num){
        i=0;
        while( i < j ){
            cout<<"*";
            i++;
        }
        j++;
        cout<<endl;

    }
    return 0;
}
