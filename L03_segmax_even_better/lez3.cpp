#include <iostream>
 #include <vector>
 
 using namespace std;
 
 //strategia FIFO: first in first out
 
 //operazioni supportate:
 //- enqueue(x) mette x alla fine della coda
 //-dequeue(x) estrae l elemento all inizio della coda e lo restituisce (ad es in una variabile)
 //-empty() dice se è true o false (vuoto=true, non vuoto=false i guess )
 //-size() dice quanti elementi ci sono nella coda
 
 
 //keywyord: parola che identifica una classe che stiamo defininendo

 
 
 class Queue {
 public:
 
    void enqueue( int x){
        elements.push_back(x);
    }
    
    int dequeue(){
        if (elements.empty()){   // in questo caso posso non mettere {} nell if, perché eseguo un solo comando
            return -1;  // else in questo caso non necessario, perché c e il return, 
                        //se non if esegue automaticamente comando successivo
        //il vettore non è vuoto
        }
        
        //else {
        //}
        auto first = elements.front();
        elements.erase(elements.begin());
        return first;
    }
    
    size_t size(){
        return elements.size();
    }
    
    bool empty(){
        //return elements.empty();
        return elements.size() == 0;
    }
        
        
    
    void stampa(){
        for (auto i = 0; i < elements.size(); i++){
            cout << elements[i] << endl; 
        }
    }
    
    void stampa1(){
        for (auto x : elements){
            cout << x << endl; 
        }
    }
    
    
    
    
 private:
    vector<int> elements;
    
 };
 
 
 
 int main(){
     Queue mia;
     
     mia.enqueue(2);
     mia.enqueue(4);
     mia.enqueue(1);
     mia.stampa();
     
     cout << "fatto" << endl;
     return 0;
 }
    

 