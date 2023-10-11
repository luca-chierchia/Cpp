#include <iostream>
using namespace std;

int main() {
    int x,y,z;
    cout<<"Inserire 3 valori interi:"<<endl;
    cin>>x>>y>>z;
    if(x>y && x>z)
        cout<<"Il maggiore è: "<<x;
    else if ( y>z)
        cout<<"Il maggiiore è: "<<y;
    else
        cout<<"Il maggiore è: "<<z;

    return 0;
}
