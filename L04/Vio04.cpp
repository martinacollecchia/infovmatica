#include <iostream>
#include <vector>

using namespace std;

int segmax1(vector<int> & A){

    int max = 0;
    for(auto i =0; i<A.size();i++){
        for(auto j = i; j<A.size();j++){
            int somma = 0;
            //sum(i,j)
            for(auto k=i; k <=j; k++){
                somma += A[k];
            }
            if(max<somma) max = somma;
        }
    }
    return max;
} //passaggio per riferimento & tutte le modifiche rimangono salvate

int segmax2(vector<int> & A){

    int max = 0;
    for(auto i =0; i<A.size();i++){
        int somma = 0;
        for(auto j = i; j<A.size();j++){
                somma += A[j];
                if(max<somma) max = somma;
            }
    }
    return max;
}

//Produce numero pseudo casuale di numeri nell'intervallo [-maxrand...+maxrand]
int rand(int maxrand){
    return rand()%(2*maxrand + 1)-maxrand;
}

int main(){
    constexpr auto N = 1000;
    constexpr auto M = 8;
    vector<int> C;
    for(auto i=0; i<N;i++){
        C.push_back(M);
        // C è un vettore di N interi casuali tra [-M,M]

    }
    vector<int> B={-3,-2,-1,0,1,2,92,3};
    cout<<"\nsomma massima:"<< segmax1(B)<<endl;
    cout<<"somma massima:"<< segmax2(B)<<endl;
    return 0;
}