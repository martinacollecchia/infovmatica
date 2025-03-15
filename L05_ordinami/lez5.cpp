/******************************************************************************

algoritmi di ordinamento

input :array/vector A di n elementi (come  input int ad esempio)
      ha relazione d ordine <=
output: riorganizzare gli elementi di  A in ordine decrescente(Ad esemio)
       A[0]<=A[1]<=.....<=A[n]
      esempio A = 15, 7, 8, 3, 19, 10, 5, int16
          ---> 3, 5, 7, 8, 10, 15, 16, 19

modo piu naturale per farlo è individuare il piu piccolo nell array, selezionalro
e metterlo fuori dal gioco, poi iterare (estraggo il minimo ad ogni passaggio)

 altro approccio con insertion sort
 i primi i-1 elemehti sono gia ordinati, (non necessariamente sono minimi)
approccio simile a quando si pesca una carta e si inserisce con un ordine in mezzo alla carte in mano
(non vedo il futuro, ordino in base a passato + carta i)
questo codice è piu furbo dell altro, usa transitività della relazione >/<
      esempio: 1, 2, 3, 4, 5
      --->    confronto 2 con 1, rimangono uguali
  al passaggio dopo confronto 3 con 2, rimangono uguali, no need to confrontare anche con 1


*******************************************************************************/




#include<iostream>
#include<vector>

using namespace std;


constexpr auto maxval = 158;



int random(int a, int b){
    return a + rand() % (b - a + 1); //unbiased
    // % prende il modulo (algebra style) della divisione tra rand() e (b - a + 1)
}



void randomVector(vector<int> & R, int len){
    R.clear();
    for (auto i = 0; i < len; i++){
        R.push_back(random(1, maxval));
    }
}


void print(const vector<int> & R){
    for (auto x : R){
        cout << x << " ";
    }
    cout << endl;
}



void selectionSort(vector<int> & A){
    for (auto i = 0; i < A.size(); i++){
        auto minimo = A[i];   //A irrilevante per compliatore, potrei chiamarlo Marco
        auto indiceMinimo = i;// serve solo a compilatore perché e la stessa variabile, ed esiste dentro alla sua scatolina
        for (auto j = i + 1; j < A.size(); j++){
            if (A[j] < minimo){
                minimo = A[j];
                indiceMinimo = j;
            }
        }
        A[indiceMinimo] = A[i];
        A[i] = minimo;   //la variabile minimo non è necessaria sopra a questa riga
    }                   // basta usarla qui come variabile temporanea
}                       // sopra si può benissimo usare al suo posto A[i](codice di Grossi)




void insertionSort(vector<int> & A){
    for (auto i = 0; i < A.size(); i++){
        auto prossimo = A[i];
        auto j = i;
        while (j > 0 && A[j - 1] > prossimo){
            A[j] = A[j-1];
            j--;
        }
        A[j] = prossimo;
    }   
}




//manca l ultima parte dove faceva magie con i secondi per vedere quale alg era più veloce
// copiare dal Grossi







int main(){
    vector<int> A;
    randomVector(A, 16);
    //auto A = randomVector2(16);
    print(A);
    selectionSort(A);
    print(A);
    return 0;
}







