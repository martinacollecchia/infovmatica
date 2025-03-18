/* QUICK SORT

codice per ordinare array(o vettore?) di 1 e 0 randomici
tc 0 a sinistra e 1 a destra

Algoritmo di Partizione/Distribuzione
uso pivot(Valeria e Giacomo) per dividere in 2(al primo passo) l array
NB a seconda di scelta dei pivot dimensinoe dei due gruppi può variare

nel codice sotto fare attenzione a non scambiare indici i e j perché se si incrociano(?) sono cazzi


NB && non è commutativo
a && b diverso da b && a 

disastro colossale, non ho capito nulla di quelo che ha spiegato Grossi da quando
si è messo a fare bricolage con i codici delle lezioni vecchie,
tocca recuper

*/




#include <iostream>
#include <vector>
#include <ctime>
#include <sys/time.h>

using namespace std;

constexpr auto maxval = 158;


int main(){
    struct timeval start_time;
    struct timeval end_time;

    constexpr auto N = 50000;
    // srand(time(NULL));
    vector<int> A;
    //randomVector(A, N);
    for (auto i = 0; i < N; i++)
        A.push_back(N-i);
    // auto A = randomVector2(16);
    // print(A);
    gettimeofday(&start_time, NULL);
    //selectionSort(A);
    insertionSort(A);
    //print(A);
    gettimeofday(&end_time, NULL);
    cout << "running time (sec): " <<  end_time.tv_sec - start_time.tv_sec << endl;
    return 0;
}