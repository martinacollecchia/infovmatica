#include <iostream>
#include <vector>

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

// numero pseudo casuale nell'intervallo [-maxrand .. +maxrand]
int randomint(int maxrand){
    return rand() % (2 * maxrand + 1) - maxrand;
}

int main() {
    constexpr auto N = 2000;
    constexpr auto M = 16;
    vector<int> B;
    for (auto i = 0; i < N; i++)
        B.push_back(randomint(M));
    // B e' un vettore di N interi causali in [-M .. M]

    // cout << "B = ";
    // for (auto x : B)
    //     cout << x << " ";
    // cout << endl;

    cout << "inizio" << endl;
    cout << "segmento di somma massima 2 = " << segmax2(B) << endl;
    cout << "segmento di somma massima 1 = " << segmax1(B)  << endl;
    cout << "fine" << endl;
    return 0;
}