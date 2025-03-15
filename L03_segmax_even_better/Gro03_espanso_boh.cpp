#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int segmax1(vector<int> & A){ // n^3 dove n = A.size()
    int max = 0;
    for (auto i = 0; i < A.size(); i++){
        for (auto j = i; j < A.size(); j++){
            int somma = 0;
            // sum(i,j)
            for (auto k = i; k <= j; k++){
                somma += A[k]; // somma = somma + A[k]
            }
            if (max < somma) max = somma;
        }
    }
    return max;
}

// sum(i,j) = sum(i,j-1) + A[j]
int segmax2(vector<int> & A){ // n^2 dove n = A.size()
    int max = 0;
    for (auto i = 0; i < A.size(); i++){
        int somma = 0;
        for (auto j = i; j < A.size(); j++){
            somma += A[j];  // sum(i,j)
            if (max < somma) max = somma;
        }
    }
    return max;
}

int segmax3(vector<int> & A){ // n dove n = A.size()
    int max = 0;
    int somma = 0;
    for (auto j = 0; j < A.size(); j++){
        if (somma > 0)
            somma += A[j];  // sum(i,j) per il segmento attuale
        else
            somma = A[j];  // inizia un nuovo segmento dove i = j
        if (max < somma) max = somma;
    }
    return max;
}

// numero pseudo casuale nell'intervallo [-maxrand .. +maxrand]
int randomInt(unsigned maxrand){ 
    return rand() % (2 * maxrand + 1) - maxrand; // biased :(
}

// esercizio: perche' invece questo e' unbiased? Migliore di randomInt()
int randomInt2(unsigned maxrand){
    unsigned x, r, range;
    range = (2 * maxrand + 1);
    do {
        x = rand();
        r = x % range;
    } while (x - r > (-range));
    return r - maxrand;
}


// B e' un vettore di N interi causali in [-M .. M]
void randVector(vector<int> & A, int len, int range){
    A.clear(); // fa reset di A
    for (auto i = 0; i < len; i++)
        A.push_back(randomInt(range)); // aggiunge un interno in [-range .. range] 
}

void printVector(vector<int> & A){
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

int main() {
    constexpr auto N = 5000;
    constexpr auto M = 16;
    vector<int> B;
    srand(time(NULL)); // usa un seed per rand basato sull'orario attuale
    randVector(B, N, M); // B e' un vettore di N interi causali in [-M .. M]

    // cout << "B = ";
    // printVector(B);

    cout << "inizio" << endl;
    cout << "segmento di somma_massima_3 = " << segmax3(B) << endl;
    cout << "segmento di somma_massima_2 = " << segmax2(B) << endl;
    cout << "segmento di somma_massima_1 = " << segmax1(B)  << endl;
    cout << "fine" << endl;
    return 0;
}