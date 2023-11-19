#include <iostream>
#include <cstring>
using namespace std;

/*
 * Scrivere un programma che legge da input una sequenza di dati che rappresentano il nome, il cognome e il
numero di telefono di una persona. I contatti devono essere memorizzati in un array di massimo 100 elementi. Il
programma deve chiedere ripetutamente di scegliere fra una di queste operazioni:
1 – Inserire un nuovo contatto
2 – Eliminare un contatto (dato il nome e cognome del contatto)
3 – Stampare rubrica
4 – Uscire dal programma
NB:
- Il numero di telefono di una persona deve essere memorizzato come stringa
- Modellare un contatto della rubrica usando le struct
- Qualsiasi altra scelta implementativa è lasciata allo/alla studente/studentessa
 */

struct contatto{
    char nome[32];
    char cognome[32];
    char numero[10];


};

int main() {

    contatto rubrica[100];
    contatto r;
    int contattiInRubrica=0;
    bool contattiCancellati=false;
    bool equal=0;
    char noContatto[32]={'*'};

    int i=0;
    int failed;
    int op=0;

    do{
        contatto p;
        bool isNmb=1;
        cout<<"***Rubrica***"<<endl;
        cout<<"\t 1 - Inserisci contatto"<<endl;
        cout<<"\t 2 - Cancella contatto:"<<endl;
        cout<<"\t 3 - Visualizza Rubrica:"<<endl;
        cout<<"\t 4 - Esci:"<<endl;


        cin>>op;
        cout<<endl;
        failed=cin.fail();
        if(failed){
            cin.clear();
            cin.ignore(5000,'\n');
        }

        if(op==3){
            if(i<=0 || contattiInRubrica==0){
                cout<<"Rubrica vuota!\n"<<endl;
            }else
                for(int j=0;j<i;j++){
                    if(rubrica[j].nome[0]=='*')
                        continue;
                    cout<<"["<<j<<"]"<<"Nome: "<<rubrica[j].nome<<", Cognome: "<<rubrica[j].cognome<<", Numero di telefono: "<<rubrica[j].numero<<endl;
                }

        }else if(op==1){
            cin.ignore(5000,'\n');
            do{
                do{
                    cout<<"Inserisci nome:"<<endl;
                    cin.getline(r.nome,32,'\n');
                    failed=cin.fail();
                    if(failed){
                        cin.clear();
                        cin.ignore(5000,'\n');
                    }
                }while(failed);
                do{
                    cout<<"Inserisci cognome:"<<endl;
                    cin.getline(r.cognome,32,'\n');
                    failed=cin.fail();
                    if(failed){
                        cin.clear();
                        cin.ignore(5000,'\n');
                    }
                }while(failed);
            int eq1=1;
            int eq2=1;
            for(int j=0;j<i;j++){
                eq1= strcmp(r.nome,rubrica[j].nome);
                eq2= strcmp(r.cognome,rubrica[j].cognome);
                if(eq1==0 && eq2==0)
                    equal=true;
                else
                    equal=false;
            }
            if(equal){
                cout<<"Il contatto esiste già in rubrica."<<endl;
                cout<<"Inserisci un altro nome o cognome."<<endl;
                }
            }while(equal!=0);
            do{
                isNmb=1;
                cout<<"Inserisci numero:"<<endl;
                cin.getline(r.numero,10,'\n');
                failed=cin.fail();
                if(failed){
                    cin.clear();
                    cin.ignore(5000,'\n');
                }else
                    for(int i=0; r.numero[i]!='\0';i++){
                        int val=r.numero[i];
                        if(val<48 || val>57)
                            isNmb=0;

                    }


            }while(failed || isNmb==0 );
            if(contattiCancellati){
                for(int h=0;h<i;h++){
                    if(rubrica[h].nome[0]=='*'){
                        rubrica[h]=r;
                        contattiInRubrica+=1;
                        contattiCancellati = false;
                    }
                }
            }else if(!contattiCancellati) {
                contattiInRubrica += 1;
                rubrica[i] = r;
                i++;

            }

        }else if(op==2){
            cout<<"Per cancellare un contatto devi inserire il nome ed il cognome del contatto che vuoi cancellare"<<endl;
            cin.ignore(5000,'\n');
            do{
                int op=3;
                char nc[32];
                char cc[32];
                cout<<"Inserisci il nome da cercare:"<<endl;
                cin.getline(nc,32,'\n');

                failed=cin.fail();
                if (failed){
                    cin.clear();
                    cin.ignore(5000,'\n');
                }

                cout<<"Inserisci il cognome da cercare:"<<endl;
                cin.getline(cc,32,'\n');
                failed=cin.fail();
                if (failed){
                    cin.clear();
                    cin.ignore(5000,'\n');
                }
                int cerca_nome=1;
                int cerca_cognome=1;
                int posizione=0;
                for(int k=0;k<i;k++){
                    cerca_nome= strcmp(rubrica[k].nome,nc);
                    cerca_cognome= strcmp(rubrica[k].cognome,cc);
                    if(cerca_nome==0 && cerca_cognome==0)
                        break;
                    posizione++;
                }
                if(cerca_nome==0 && cerca_cognome==0){

                    cout<<"Trovato il contatto da cancellare:"<<rubrica[posizione].nome<<" "<<rubrica[posizione].cognome<<endl;
                   do{
                       cout<<"Per cancellare il contatto scrivi 1 , per tornare indietro scrivi 0"<<endl;
                       cin>>op;
                       cin.ignore(5000,'\n');
                   }while(op!=0 && op!=1);
                   if(op==1){
                       strcpy(rubrica[posizione].nome,noContatto);
                       strcpy(rubrica[posizione].cognome,noContatto);
                       strcpy(rubrica[posizione].numero,noContatto);
                       contattiInRubrica-=1;
                       contattiCancellati=true;

                   }

                }else
                    cout<<"Non è stato trovato nessun contatto in rubrica"<<endl;
            }while(failed && op!=0 );
        }
    failed=cin.fail();
    if(failed){
        cin.clear();
        cin.ignore(5000,'\n');
    }

    }while(op!=4);


    return 0;
}
