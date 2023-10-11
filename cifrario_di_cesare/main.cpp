#include <iostream>
using namespace std;
int main() {
    int add3 = 3;
    int x ;
    cout<<"Inserisce tre caratteri minuscoli."<<endl;
    char c1,c2,c3;
    cin>>c1>>c2>>c3;
    int nc1 = c1, nc2 = c2, nc3 = c3;

    // Utilizzo di operatori ternari in serie e concatenati per verificare il valore numerico dei char

    /*
     * Se i valori sono compresi tra 97 e 122 estremi inclusi allora c1 verrà sottoposta ad ulteriore verifica
     *  con un'altro opeatore ternario che valuterà se il valore e >= 120  prima di un assegnamento,
     *  in questo caso verrà sottratto un valore di 23 per poter rispettare la codifica del cifrario di cesare.
    */

    // Le seguenti espressioni sono tutti uguali ma trattano valori diversi

    (nc1 >= 97 && nc1 <=122)?c1 = (nc1>=120)?nc1 - 23: nc1 + add3: c1 = 42;
    (nc2 >= 97 && nc2 <=122)?c2 = (nc2>=120)?nc2 - 23: nc2 + add3 : c2 = 42;
    (nc3 >= 97 && nc3 <=122)?c3 = (nc3>=120)?nc3 - 23: nc3 + add3 : c3 = 42;

    cout<<c1<<c2<<c3;
    return 0;
}


// condizione che soddisfa i caratteri
// x <= 97 && x >=122 (nc2 >= 97 && nc2 <=122)  (nc3 >= 97 && nc3 <=122)  c2 = nc2 + x , c3 = nc3 +x;
//