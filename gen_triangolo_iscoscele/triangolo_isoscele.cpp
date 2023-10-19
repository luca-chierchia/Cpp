#include <iostream>
using namespace  std;

int main() {

    int h;
    int i=0;
    int k=0;
    do{
        cout<<"Inserisci altezza >0:"<<endl;
        cin>>h;
    }while(h<=0);

    while(h>i) {

        for (int j = 0; j < h; j++) {
            if (i + j >= h - 1)
                cout << '*';
            else
                cout << " ";
        }
        cout<<endl;
        i++;

        if(i==h-1)
            break;
    }
    while(h>k) {
    if(h==1)
        break;
        for (int j = 0; j < h; j++) {
            if (k - j <=0)
                cout << '*';
            else
                cout << " ";
        }
        cout<<endl;
        k++;
    }


    return 0;
    }



