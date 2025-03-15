#include <iostream>  //comando per compilatore
#include <vector>

using namespace std;

/*namespace Wislon{} definisce insieme di funzioni
Wislon:: nomefunzione la rinomino
using namespace Wislon; la chiamo nel main

*/

int f(int x = 1){  // definizione di funzione
    return x+6;
}

int fib (int n){
    int x[n]; //definisce dieci variabili numerate da 0 a n-1
    x[0] = x[1] = 1;
    for(int i = 2; i<n; i++){  //prende numeri tra2 e n-1
        x[i] = x[i-1]+x[i-2];
    }
    return x[n-1];
}

int fibo(int n){
    int f0 = 1;
    int f1 = 1;
    while(n--){
        auto fib = f0+f1;
    }
    return fib
}

//if
int f(int n){
    if (n==1) return 1;
    else return fib(n-1)+fib(n-2);
}


int main() {
    /*
    int x=10;
    int y=25;
    int z=x+y;

    cout<<"Sum of x+y = " << z; //cout stampa, std sono funzioni standard,
    */
    
    int x = 1; // dichiarazione di variabile con tipo e valore inziale //la variabile può essere a 32 o 64 bit
    
    x = x+3;
    
    /*
    auto y = f(); dichiara variabile di tipo auto che viene dedotto dal tipo restiruito dalla funzione f,
                che non avendo argomento usa quello di default
    
    z = f(y);
    */
    
    // se voglio trovare succesione di Fibonacci
    
    vector<int> a = (1,2,3); //vector ecome arrayma supporta più operazioni
    

    
    cout << "valore di x = " << x <<endl;
    cout << "Succesione di Fibonacci per x = " << fib(x) <<endl;
    
}


/*interprete(python) e compilatore (c++): interprete prima esegue e poi traduce in bi,
compilatore prima traduce in bit e poi esegue*/