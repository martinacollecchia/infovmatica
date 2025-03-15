// provo a riscrivere Gro01 per esercizio

//#include<iostream>
#include "iostream"


//definisco funzione segmax che calcola segmento massimo


/*******************************************************************
Perché nella definizione degli argomenti di segmax1 devo usare un puntatore per a?


Nella definizione degli argomenti di segmax1, si utilizza un puntatore 
per a (int * a) per diverse ragioni:

Passaggio di Array: In C++, quando si passa un array a una funzione, 
si passa effettivamente un puntatore al primo elemento dell'array. 
Questo è il modo standard per passare array alle funzioni in C++.

Efficienza: Passare un puntatore è più efficiente rispetto a passare
 l'intero array per valore. Se si passasse l'intero array per valore,
  verrebbe creata una copia dell'array, il che richiederebbe tempo e
   memoria aggiuntivi. Passando un puntatore, si evita questa copia 
   e si lavora direttamente con l'array originale.

Accesso Diretto agli Elementi: Utilizzando un puntatore, la funzione
 può accedere direttamente agli elementi dell'array originale.
  Questo permette di manipolare i dati dell'array senza dover creare copie.




********************************************************************/
int segmax(int * a, int n){
    int max = 0;
    for (int i = 0; i < n; i++){
        for(int j = i; j<n; j++){
            int somma = 0;
            for(int k=i; k<=j; k++){
                somma += a[k];
            }
            if(somma > max){
                max = somma;
            }   
        }
    }
    return max;
}

int main(){
    int n = 13;
    int a[13] = {2, -4, 1, 3, -7, -2, -1, 2, -1, 3, -2, -1, 5};
    std::cout << segmax(a, n) << std::endl;
    return 0;
}
