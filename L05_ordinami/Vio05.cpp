#include <iostream>
#include <vector>

using namespace std;

template<typename T> //parametro per definiire qualcosa nel nostro caso è tipo di vettore
class stack {
private:
    vector<T>
public:
    void push(const T & x) //push aggiunge un valore ad una struttura
    {
        elements.push_back(x);

    } //const quell'argomento non vogliamo modificarlo dentro la push(le parentesi graffe)
      //& serve per prendere proprio quel valore 
    T.pop(){
        if(elements.empty()){
            throw out_of_range("empty stack");
        }
        T top_elem = elements.back();
        elements.pop_back();
        return top_elem;
    }
    bool empty(){
        return elements.empty();
    } //<< funzione in forma infissa
    friend ostream & operator <<(ostream &os ,const stack<T> & s){
        for(const T & x: s.elements){ //ciclo for su tutti elementi
            os << x << " ";
        }
        return os;
    }

};

//coda con strategia FIFO=:first in first out

//operazioni supportate:
//- enqueue(x): mette x nella coda
//- dequeue(): estrae l'elemento all'inzio della coda e lo restituisce
//- empty(): se la coda è vuota
//- size(): quanti elementi sono nella coda

//vettore è dinamico aggiunge elementi e aumenta dimenzione (push-back) e erase () elimina primo elemento

// keyword per definire una classe

// posso impostare parametro
//template <typename T>

class coda {

public: // si può modificare da anche dal main
    void enqueue(int x){  // void non restituisce niente
        elements.push_back(x);
    } 

    int dequeue(){
        if(elements.empty()){
        return -1; 
        }
        // -1 si ferma perchè azione non permessa 
        // con return non è necessario else perchè se if vero si ferma altrimenti va avanti
        auto first = elements.front(); //elements zero
        elements.erase(elements.begin()); //con begin ho packing ma non il contenuto del pacco
        return first;
    }

    size_t size(){
        return elements.size();
    }

    bool empty(){
        return elements.size() == 0; //return elements.size() = 0
    }

    void stampa1(){
        for(auto i = 0; i<elements.size(); i++){ //auto prende da solo tipo di variabile
            //auto e: prende tutti gli elementi del vettore
            cout<<elements[i]<<endl;
        }
    }
    
    void stampa(){
        for(auto x: elements){ 

            cout<< x <<endl;
        }

private: //fuori della classe non posso modificare private
    vector <int> elements;

};


int main(){
    stack<int> 5;
    coda mio; //dichiarazione della classe
            // con T parametro poi dopo devo metterci il tipo del vettore così posso cambiare tipo di varaibile
    cout<<endl;
    mio.enqueue(2);
    mio.enqueue(4);
    mio.enqueue(8);
    mio.stampa();

    cout<< "fatto"<< endl;
    return 0;
}
