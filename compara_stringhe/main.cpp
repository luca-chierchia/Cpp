#include <iostream>
#include <cstring>
using namespace std;

int main () {
    int const max_l=100;
    char str1[max_l];
    char str2[max_l];



    int l1,l2=0;

    do{
        bool equal=true;
        bool prefisso = true;
        bool suffisso = true;
        cout<<"Inserire due parole da confrontare:"<<endl;
        cout<<"Parola 1:"<<endl;
        cin.getline(str1,max_l);
        if(!cin){
            cin.ignore(200,'\0');
            cin.clear();
        }

        cout<<"Parola 2:"<<endl;
        cin.getline(str2,max_l);
        if(!cin){
            cin.ignore(200,'\0');
            cin.clear();
        }


        l1= strlen(str1);
        l2= strlen(str2);

        if(l1==l2){
            int i = 0;
            int j = 0;
            while (equal && str1[i] != '\0') {
                if (str1[i] == str2[j]) {
                    equal = true;
                    i++;
                    j++;
                } else {
                    equal = false;
                }
            }
            if(equal){
                int k=l1;
                cout<<str1<<" è uguale a "<<str2<<endl;
                cout<<"Reverse string: ";
                for(int i =l1-1;i>-1;i--){
                    cout<<str1[i];
                }
                cout<<endl;
            }

            else
                cout<<"le parole sono differenti";
        }
        else if (l1 < l2){
            int i = 0;
            int j = 0;
            while (prefisso && str1[i] != '\0') {
                if (str1[i] == str2[j]) {
                    prefisso = true;
                    i++;
                    j++;
                } else {
                    prefisso = false;
                }

            }
            i = 0;
            j = l2 - l1;
            while (suffisso && str1[i] != '\0') {
                if (str1[i] == str2[j]) {
                    suffisso = true;
                    i++;
                    j++;
                } else
                    suffisso = false;

            }
            if (suffisso) {
                cout << str1 << " è suffisso di " << str2 << endl;
            } else if (prefisso) {
                cout << str1 << " è prefisso di " << str2 << endl;
            }else
                cout <<str1 << " non è ne prefisso ne suffiso"<<endl;
        }
        else if (l1 > l2){
            int i = 0;
            int j = 0;
            while (prefisso && str2[i] != '\0') {
                if (str2[i] == str1[j]) {
                    prefisso = true;
                    i++;
                    j++;
                } else {
                    prefisso = false;
                }

            }
            i = 0;
            j = l1 - l2;
            while (suffisso && str2[i] != '\0') {
                if (str2[i] == str1[j]) {
                    suffisso = true;
                    i++;
                    j++;
                } else
                    suffisso = false;

            }
            if (suffisso) {
                cout << str2 << " è suffisso di " << str1 << endl;
            } else if (prefisso) {
                cout << str2 << " è prefisso di " << str1 << endl;
            } else
                cout<<str2 << " non è ne prefisso ne suffisso"<< endl;
        }
    }while(str1[0]!='$' && str2[0]!='$');
    cout<<"Addio"<<endl;
    return 0;
}
