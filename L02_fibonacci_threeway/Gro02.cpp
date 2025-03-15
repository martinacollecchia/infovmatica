#include <iostream>
#include <vector>

using namespace std;

int foo(int x = -3){ // se x non e' specificato, prende il valore di default -3
    return x + 4;
}


// array / vettore
// esempio Fibonacci  1, 1, 2, 3, 5, 8, 13, 21, ...
int Fib3(int n){
    int x[n]; // dichiarare n=10 variabili numerate da 0 a n-1
          // x[0], x[1], ..., x[n-1]
    x[0] = x[1] = 1;
    // ciclo for
    for(auto i = 2; i < n; i++){  // i = 2, 3,..., n-1
        x[i] = x[i-1] + x[i-2];
    }
    return x[n-1];
}

int Fib3v(int n){
    vector<int> x; // dichiarare n=10 variabili numerate da 0 a n-1
                   // x[0], x[1], ..., x[n-1]
    x.resize(n);
    x[0] = x[1] = 1;
    // ciclo for
    for(auto i = 2; i < n; i++){  // i = 2, 3,..., n-1
        x[i] = x[i-1] + x[i-2];
    }
    return x[n-1];
}


int Fib2(int n){ // n > 0
    int fib0 = 1;
    int fib1 = 1;
    n = n -2;
    // ciclo while
    while(n--){
        auto fib = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib;
    }
    return fib1;  // non compila con fib
}

// costrutto if.. + ricorsione
int Fib(int n){
    if (n-1 <= 1) { return 1;}                // condizione if vera
    else { return Fib(n-1) + Fib(n-2); }    // condizione if falsa
}




int main() {
    // tipo, variabile, costante, inizializzazione
    // int x = 1; // dichiara una variabile di tipo intero 
    //           //che viene inizializzata alla costante 1
    // x = x + 4; // usare x e aggiornarla

    auto x = foo(); // dichiara una variabile di tipo auto
                   //che viene dedotto dal tipo restituito dalla
                   // funzione foo, che non avendo un argomento, usa
                   // quello di default (x=-3)

    x = foo(x) + 1;

    x = 64;

    cout << "valore x e' " << x << endl;
    cout << "il corrispondente Fibonacci e' " << Fib2(x) << " " << Fib2(x) << endl;
}