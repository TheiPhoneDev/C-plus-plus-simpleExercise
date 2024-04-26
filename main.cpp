#include <iostream>
#include <string>

using namespace std;


const int dimensioneMax=100;

//prototipi
void caricaVettore(char v[], int &n);
void stampaInversa(char v[], int n);
void stampaNparole(char v[], int n);
void stampaVocali(char v[], int n, int &pos);
int Menu();


int main() {

  int scelta;
  int N=0;
  char frase[dimensioneMax];
  int pos;
  char vettoreVocali[5] = {'A', 'E', 'I', 'O', 'U'};


  do{
    scelta=Menu();
    switch(scelta) {
      case 1:
        caricaVettore(frase,N);
      break;
      case 2:
        stampaInversa(frase,N);
      break;
      case 3:
        stampaNparole(frase,N);
      break;
      case 4:
        stampaVocali(frase,N,pos);
        cout<<"La vocale usata maggiormente e' "<<vettoreVocali[pos]<<endl;
      break;
      case 0:
        cout<<"Esci"<<endl;
      break;
      default:
        cout<<"Attenzione, scelta sbagliata!"<<endl;
      break;
    }
  }while(scelta!=0);

}

int Menu() {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Inserisci la frase"<<endl;
  cout<<"2-Stampa la frase al contrario"<<endl;
  cout<<"3-Stampa il numero di parole"<<endl;
  cout<<"4-Stampa uso delle vocali e quella usata maggiormente"<<endl;
  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}




void caricaVettore(char v[], int &n) {

  int i=0;
  char risp;

  do{
    cout<<"Inserisci il carattere: ";
    cin.ignore();
    cin.get(v[i]);
    i++;
    n++;
    cout<<"Vuoi inserire un altro carattere? (s/n): ";
    cin>>risp;
  }while(risp=='s' || risp=='S');


}


void stampaInversa(char v[], int n) {

  string stringaOriginale="";
  string stringaInversa="";
  cout<<endl;

  for(int i=0;i<n;i++) {
    stringaOriginale=stringaOriginale+v[i];
  }

  for(int i=n-1;i>=0;i--) {
    stringaInversa=stringaInversa+v[i];
  }

  cout<<"La stringa originale e' "<<stringaOriginale<<endl;
  cout<<"La stringa invertita e' "<<stringaInversa<<endl;

  cout<<endl;

}




void stampaNparole(char v[], int n) {
  int spazi=1;

  cout<<endl;

  for(int i=0; i<=n; i++) {
    if(v[i]==' ') {
      spazi++;
    }
  }

  cout<<endl;

  cout<<"Il numero di parole utilizzato e' "<<spazi<<endl;

  cout<<endl;

}



void stampaVocali(char v[], int n, int &pos) {

  int contaA=0;
  int contaE=0;
  int contaI=0;
  int contaO=0;
  int contaU=0;
  int valMax=0;


  cout<<endl;

  for(int i=0;i<n;i++) {

    if(v[i]=='a' || v[i]=='A') {
      contaA++;
    } else if(v[i]=='e' || v[i]=='E') {
      contaE++;
    } else if(v[i]=='i' || v[i]=='I') {
      contaI++;
    } else if(v[i]=='o' || v[i]=='O') {
      contaO++;
    } else if(v[i]=='u' || v[i]=='U') {
      contaU++;
    }

  }

  cout<<"La 'A' compare: "<<contaA<<" volte"<<endl;
  cout<<"La 'E' compare: "<<contaE<<" volte"<<endl;
  cout<<"La 'I' compare: "<<contaI<<" volte"<<endl;
  cout<<"La 'O' compare: "<<contaO<<" volte"<<endl;
  cout<<"La 'U' compare: "<<contaU<<" volte"<<endl;

  int vettoreContatori[5];

  vettoreContatori[0]=contaA;
  vettoreContatori[1]=contaE;
  vettoreContatori[2]=contaI;
  vettoreContatori[3]=contaO;
  vettoreContatori[4]=contaU;




  for(int i=0; i<5; i++) {
    if(vettoreContatori[i]>valMax) {
      pos=i;
    }
  }


  cout<<endl;




}
