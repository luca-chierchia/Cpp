#include <iostream>
#include <cmath>
//Non mi fa utilizzare la libreria ...

using namespace std;

int main() {
    int bit=0;
    int operatore=0;
    int decimale=0;
    int array_di_bit[4]={};
    int array_sottrattivo[4]={0,0,0,1};


    cout<<"Inserisci il numero in complemento a 2."<<endl;
    for(int i=0;i<4;i++){
        do{
            cout<<"Inserisci il valore del bit:"<<endl;
            cin>>bit;

        }while(bit<0||bit>1);
        array_di_bit[i]=bit;
    };
    do{
        cout<<"Sceglie un operazione da effettuare:"<<endl;
        cout<<"0: stampa binario"<<endl;
        cout<<"1: Converti in decimale"<<endl;
        cout<<"2: Calcola opposto    "<<endl;
        cin>>operatore;

    }while(operatore<0 || operatore>2);

switch(operatore){
    case 0:{
        //stampa il numero inserito
        for(int i=0;i<4;i++){
            cout<<array_di_bit[i];
        }
        break;
    }
    case 1:{
        //stampa del decimale
        if(array_di_bit[0]==1) {
            decimale = array_di_bit[0] * 8 -( array_di_bit[1] * 4 + array_di_bit[2] * 2 + array_di_bit[3] * 1);
            cout << decimale*-1;
        }
        else {
            decimale = array_di_bit[0] * 8 +( array_di_bit[1] * 4 + array_di_bit[2] * 2 + array_di_bit[3] * 1);
            cout << decimale;
        }

        break;
    }
    case 2: {
        if(array_di_bit[0]==1&&array_di_bit[1]==0&&array_di_bit[2]==0&&array_di_bit[3]==0)
            cout<<"Overflow!"<<endl;
        if(array_di_bit[0]==1){
        for(int i=4;i>0;i--){
            if(array_di_bit[i]-array_sottrattivo[i]==-1){
                array_di_bit[i]=1;
                array_sottrattivo[i-1]=1;
            }
            else if(array_di_bit[i]-array_sottrattivo[i]==-0){
                array_di_bit[i]=0;
                array_sottrattivo[i-1]=0;
            }
            else if(array_di_bit[i]-array_sottrattivo[i]==1){
                array_di_bit[i]=1;
                array_sottrattivo[i-1]=0;
            }

        }
            for(int i =0; i<4;i++){
                if(array_di_bit[i]==1)
                    array_di_bit[i]=0;
                else
                    array_di_bit[i]=1;
            }}
        else if(array_di_bit[0]==0){

            for(int i =0; i<4;i++){
                if(array_di_bit[i]==1)
                    array_di_bit[i]=0;
                else
                    array_di_bit[i]=1;
            }
            for(int i=4;i>0;i--){
                if(array_di_bit[i]+array_sottrattivo[i]==2){
                    array_di_bit[i]=0;
                    array_sottrattivo[i-1]=1;
                }
                else if(array_di_bit[i]+array_sottrattivo[i]==-0){
                    array_di_bit[i]=0;
                    array_sottrattivo[i-1]=0;
                }
                else if(array_di_bit[i]+array_sottrattivo[i]==1){
                    array_di_bit[i]=1;
                    array_sottrattivo[i-1]=0;
                }
            }
        }


        for(int i=0;i<4;i++){
            cout<<array_di_bit[i];
        }

    }
}

    return 0;
}

// 0100  dec 4 , c1= 1011 , c2= 1100
