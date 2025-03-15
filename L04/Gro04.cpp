#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private: 
    vector<T> elements;

public:
    void push(const T & x){
        elements.push_back(x);
    }

    T pop(){
        if (elements.empty()){
            throw out_of_range("empty stack");
        }
        T top_elem = elements.back();
        elements.pop_back();
        return top_elem;
    }

    bool empty(){
        return elements.empty();
    }

    // Overload operator<< per stampare lo stack
    friend ostream & operator <<(ostream &os, const Stack<T> & s){
        for (const auto & x: s.elements){
            os << x << " ";
        }
        return os;
    }
};

template<typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    // Enqueue an element into the queue
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    // Dequeue an element from the queue
    T dequeue() {
        if (elements.empty()) {
            throw std::out_of_range("Queue<>::dequeue(): empty queue");
        }
        T front_element = elements.front();
        elements.erase(elements.begin());
        return front_element;
    }

    // Get the front element of the queue without removing it
    T& front() {
        if (elements.empty()) {
            throw std::out_of_range("Queue<>::front(): empty queue");
        }
        return elements.front();
    }

    // Check if the queue is empty
    bool empty() const {
        return elements.empty();
    }

    // Return the size of the queue
    size_t size() const {
        return elements.size();
    }

    // Overload operator<< for printing the queue
    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        for (const T& element : queue.elements) {
            os << element << " ";
        }
        return os;
    }
};

inline bool stesso_tipo(const char a, const char c){
    return 
    (a == '(' && c == ')') ||
    (a == '[' && c == ']') ||
    (a == '{' && c == '}');
}

bool verifica_parentesi(string P){ // esempio semplice di un parser
    Stack<char> S;
    for (auto c : P){
        if (c == '(' || c == '[' || c == '{'){
            S.push(c);
        } else if (c == ')' || c == ']' || c == '}'){
            auto a = S.pop();
            if (!stesso_tipo(a,c)) return false;
        } else {
            return false;   
        }
        cout << S << endl;
    }
    return true;
}


int main() {
    vector<int> V = {1, 2, 3, 4, 5, 6, 7};

    Stack<int> S; // classe Stack e l'oggetto S di tipo Stack
    Queue<int> Q;

    for (auto x : V){
        S.push(x);
        Q.enqueue(x);
    }

    cout << S << endl;
    cout << Q << endl << endl;

    while (!S.empty()){
        auto x = S.pop();
        cout << x << " ";
    }
    cout << endl;

    while (!Q.empty()){
        auto x = Q.dequeue();
        cout << x << " ";
    }
    cout << endl << endl;

    // valida = stringa vuota oppure
    //        = valida (valida) 
    // esempio di grammatica

    auto valida =      "(){[()][{}](())}";
    auto valida2 =     "(){[()][{{([])}}()](())}";
    auto non_valida =  "(){[()[{})[()]}";
    auto non_valida2 = "(){[()][{)(}](())}";

    cout << valida2 << endl << endl;
    cout << verifica_parentesi( valida2 ) << endl;


    {[{{([   ])}}()](())}

}