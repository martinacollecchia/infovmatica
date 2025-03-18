#include <iostream>
#include <vector>
#include <ctime>
#include <sys/time.h>

using namespace std;

constexpr auto maxval = 158;

int random(int a, int b)
{
    return a + rand() % (b - a + 1); // unbiased
}

void randomVector(vector<int> & R, int len){
    R.clear();
    for (auto i = 0; i < len; i++){
        R.push_back(random(1, maxval));
    }
}

vector<int> randomVector2(int len){
    vector<int> R;
    for (auto i = 0; i < len; i++){
        R.push_back(random(1, maxval));
    }
    return R;
}

void print(const vector<int> & R){
    for (auto x : R){
            cout << x << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &A)
{
    for (auto i = 0; i < A.size() - 1; i++){
        auto indiceMinimo = i;
        for (auto j = i + 1; j < A.size(); j++){
            if (A[j] < A[indiceMinimo]){
                indiceMinimo = j;
            }
        }
        auto minimo = A[indiceMinimo];
        A[indiceMinimo] = A[i];
        A[i] = minimo;
    }
}

void insertionSort(vector<int> &A){
    for (auto i = 1; i < A.size(); i++){
        auto prossimo = A[i];
        auto j = i;
        while (j > 0 && A[j-1] > prossimo){
            A[j] = A[j - 1];
            j--;
        }
        A[j] = prossimo;
    }
}


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