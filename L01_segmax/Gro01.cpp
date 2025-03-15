//Gro01
//segmento di somma massima: baseline


#include "iostream"
 
int segmax1(int * a, int n){
    int max = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            // il doppio for per i e j serve per fare due sommatorie diverse
            //defnisco i da 0 a n, e j da i a n, quindi ho 0<i<j<n 
            // e avendo definito due for separati j varia da i a n
            // contemporaneamente i(cioè k) da 0 a j
            //ottengo tutte le combinazioni possibili di somme tra i e j
            // calcola sum(i,j)
            int somma = 0;
            for (int k = i; k <= j; k++)
                somma += a[k];
            if (max < somma)
                max = somma;
        }
    }
    return max;
}
 
int main(){
    int n = 13;
    int a[13] = {2, -4, 1, 3, -7, -2, -1, 2, -1, 3, -2, -1, 5};
    std::cout << segmax1(a, n) << std::endl;
    return 0;
}
 