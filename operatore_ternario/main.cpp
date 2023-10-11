#include <iostream>
using namespace std;

int main() {
    cout<<"Inserire un valore:"<<endl;
    int x;
    cin>>x;
    int abs = (x>0)? x : -x;
    cout<<"il numero inserito è:"<<x<<" "<<"il suo valore assoluto è:"<<abs<<endl;
    return 0;
}
