#include <iostream>
using namespace  std;

// Raccolta di funzioni su stringhe

// Funzione per definire lunghezza di una stringa
int length(char* s){
    int i = 0;
    int l = 0;
    while( s[i] != '\0'){
        l += 1;
        i++;
    }
    return l;
}

// Funzione void che inverte stringa
void revert(char* s){
    int i = 0;
    int l = length(s);
    char str_rev[l];

    while( *(s+i) != '\0'){
        *(str_rev + i ) = s[(l-1)-i];
        i++;
    }
    i = 0;
    while( *(s+i) != '\0'){
        *(s + i ) = *(str_rev + i);
        i++;
    }
    *(s + i) = '\0';

}

// versione alternativa
void revert2(char s[]){
    int i = 0;
    int l = length(s);
    char str_rev[l];

    while( s[i] != '\0'){
        str_rev[i] = s[(l-1) -i];
        i++;
    }
    i = 0;
    while( s[i] != '\0'){
        s[i] = str_rev[i];
        i++;
    }
    s[i] = '\0';

}

// Funzione di trim
char* trim(char s[], char c){
    int i = 0;
    int j = 0;
    int l = length(s);
    char* t_str = new char[l];

    while(s[i] != '\0'){
        if( s[i] != c){
            t_str[j] = s[i];
            j++;
        }
        i++;
    }

    t_str[j] = '\0';
    return  t_str;
}

// Funzione per definire se due stringhe sono anagrammi
bool anagramma(char s1[], char s2[] ){
    int l1 = length(s1);
    int l2 = length(s2);

    if( l1 != l2)
        return 0;
    else {
        int i = 0;
        int somma1 = 0;
        int somma2 = 0;

        while( s1[i] != '\0'){
            int val1 = s1[i];
            int val2 = s2[i];
            somma1 += val1;
            somma2 += val2;
            i++;
        }
        if( somma1 == somma2)
            return 1;
        else
            return 0;
    }

}

//Funzione per verfiicare se una stringa è palindroma
bool palindroma(char s[]){
    int i = 0;
    int l = length(s);
    char strR[l];
    bool pal = 0;
    while( s[i] != '\0' ){
        strR[i] = s[(l-1)-i];
        i++;
    }
    i = 0;
    while( s[i] != '\0' ){
        if( s[i] == strR[i] )
            pal = 1;
        else
            pal = 0;
        i++;
    }

    if(pal)
        return 1;
    else
        return 0;
}

// funzione che rileva se un carattere è una vocale
bool isVowels(char s){
    if( s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return 1;
    else
        return 0;

}

// funzione che elimina vocali da una stringa
char* strNoVowels(char s[]){
    int i = 0;
    int l = length(s);
    char* strNoVowels = new char[l+1];
    int j = 0;

    while( s[i] != '\0' ){
        if(isVowels(s[i])){
            i++;
            continue;
        }
        else{
            strNoVowels[j] = s[i];
            j++;
        }
        i++;
    }
    strNoVowels[j] = '\0';
    return  strNoVowels;

}
// funzione per contare caratteri unici in una stringa
int countUnique( char s[]){
    int i = 0;
    int countU = 0;

    while( s[i] != '\0' ){
      int c = 0;
      int j = 0;
        while( s[j] != '\0' ){
            if( s[i] == s[j] )
                c += 1;
            j++;
        }
        if( c == 1)
            countU += 1;
        i++;
    }
    return countU;
}

// funzione per rimuovere i duplicati da una stringa
char* removeDuplicate(char s[]){
    int i = 0;

    int h = 0;
    int l = length(s);
    char* nstr = new char[l+1];

    while( s[i] != '\0' ){
        int c = 0;
        int j = 0;
        while( s[j] != '\0' ){
            if( s[i] == s[j] )
                c += 1;
            j++;
        }

        if( c == 1 ){
            nstr[h] = s[i];
            h++;
        }

        i++;
    }

    nstr[h] = '\0';
    return nstr;
}

int main() {
    char str[] = "hello";
    cout << str << endl;
    revert2(str);
    cout << str << endl;
    revert(str);
    cout << str << endl;
    char* str_t = trim(str,'l');
    cout << str_t << endl;

    if(anagramma("ciao", "oiac"))
        cout << "Anagramma" << endl;
    else
        cout << "Non anagramma" << endl;

    if(palindroma("tgtgt"))
        cout << "Palidroma" << endl;
    else
        cout << "Non palidroma" << endl;

    char str2[] = "giardiniere";
    char* str2NoVowels = strNoVowels(str2);
    cout << str2 << endl;
    cout << str2NoVowels << endl;
    int cu = countUnique(str2);
    cout << cu << endl;

    char* nstr = removeDuplicate(str2);
    cout << nstr << endl;

    return 0;
}
