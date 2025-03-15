
	#include "iostream"

int segmax1(int = *a, int n){
	int max = 0;
	for(i = 0;i<n-1; i++){
		for(int j = i; j<n; j++){
			\\calcola sum(i,j)
			int somma = 0;
			for (int k = i; k <=j; k++){
				somma + = a[k];
				if (max<= somma){
				max = somma;
				}
			}
		}
	}
	return max;

	int main(){
	int n = 11;
	int a[11] = {,}
	cout<< segmax1[a,n]
	return = 0;
	}
}