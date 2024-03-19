#include <iostream>
using namespace std;

template<class type>
class multiSet{

private:
    type* pType;
    int c = 0; // cardinalià dell'insieme, non corrisponde alla dimensione dell'array
    int dim = 10; // dimensione dell'array puntanto da pType , non corrisponde alla cardinalià dell'insieme.

    void extend(){
        type* tmp = new type[this->dim *2];
        for(int i = 0 ; i < this->c ; i++){
            tmp[i] = this->pType[i];
        }
        delete [] this->pType;
        this->pType = tmp;
        this->dim*=2;
    }


public:

    // costruttore per instaziare un set senza elementi.
    multiSet<type>(){
        this->pType = new type[this->dim];
    }

    // costruttore per istanziare un set con un singolo elemento.
    multiSet<type>(type x){
        this->c = 1;
        this->pType = new type[this->dim];
        this->pType[0] = x;

    }

    multiSet<type>(type arr[],int n){        
    }

    bool contains(type x )const{
        for(int i = 0; i < this->c; i++){
            if( this->pType[i] == x){
                return true;
            }      
        }
        return false;
    }

    void addElement(type element){
        if(this->c < this->dim){
            this->pType[c] = element;
            this->c++; 
        }

        if(this->c == this->dim){
            extend();
            this->pType[c] = element;
            this->c++; 
        }

    }

    void removeElement(type element){
        type* p_tmp = new type[this->c];
        int trace = 0;
        for(int i = 0; i < this->c; i ++){
            if(this->pType[i] != element){
                p_tmp[trace] = this->pType[i];
                trace++;
            }
            else 
                continue;
        }
        delete [] this->pType;
        this->pType = p_tmp;
        this->c = trace;
    }

    int getC()const{
        return this->c;
    }

    int getDim()const{
        return this->dim;
    }

        void printElementSet(ostream& out)const{
         out << "[" ;
        for(int i = 0; i < this->c ; i ++){
            if( i != this->c)
            out << this->pType[i] << ","  ;
        }
        out << "]";
    }

    type operator[](int index)const{
        return this->pType[index];
    }

  multiSet<type> operator+(const multiSet<type>& otherSet) const {
    multiSet<type> new_Set;

    // Aggiungi gli elementi del primo set al nuovo set
    for (int i = 0; i < this->c; i++) {
        new_Set.addElement(this->pType[i]);
    }

    // Aggiungi gli elementi del secondo set al nuovo set (evitando duplicati)
    for (int i = 0; i < otherSet.c; i++) {
        new_Set.addElement(otherSet.pType[i]);
    }

    return new_Set;
    }

    int multiplicity(type x)const{
        int f = 0;
        for(int i = 0; i < this->c ; i ++){
            if(this->pType[i] == x)
                f++;
        }
        return f;

    }

};

template<class T>
ostream& operator<<(ostream& out , const multiSet<T>& set){
     set.printElementSet(out);
     return out;
    

};

int main(){
    multiSet<int> s1(1);
    
    multiSet<char> c1('L');
    c1.addElement('u');
    multiSet<char> c2('c');
    c2.addElement('a');
    c2.addElement('a');
    c2.addElement('a');
    s1.addElement(12);
    s1.addElement(112);
    s1.addElement(2);
    s1.addElement(3);
    multiSet<float> s2(12.33);
    s2.addElement(0.003);
    s2.addElement(-4.006);
    cout << s1[3] << endl;
    multiSet<char> c3 = c1 +c2;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    int frequ = c3.multiplicity('b');
    cout << frequ << endl;
    frequ = c3.multiplicity('a');
    cout << frequ << endl;
    c3.removeElement('a');
    frequ = c3.multiplicity('c');
    cout << frequ << endl;
    cout << c3 << endl;

    return 0;
}
