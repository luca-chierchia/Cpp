#include <iostream>
using namespace std;

int main() {
    cout<<"Inserire un valore:"<<endl;
    int val;
    cin>>val;
    int p_o_d = (val%2==0)? val*val: val*val*val;
    cout<<"il valore è:"<<p_o_d<<endl;
    return 0;
}
