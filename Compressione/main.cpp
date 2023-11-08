#include <iostream>
using namespace std;

int main(){
    int k=0;
    int const max_l=100;
    char str[max_l];
    char str_compr[max_l];

    cout<<"Inserisci una stringa di caratteri:"<<endl;
    cin>>str;

    for(int i=0;str[i]!='\0';i++) {

        int conta=0;
        int j = i;
        if(str[i]==str[j])
             conta+=1;
        while(conta==1){
            j++;
            if(str[i]==str[j])
                conta+=1;
            if(str[j]=='\0')
                break;
        }
        if(conta==1){
            str_compr[k]=str[i];
            k++;
        }


    }
    cout<<str<<endl;
    cout<<str_compr<<endl;
    return 0;

}

