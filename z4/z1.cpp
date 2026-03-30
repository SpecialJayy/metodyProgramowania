#include <iostream>
#include <ostream>
#include <stack>
#include "../libraries/libFile.h"
using namespace std;

//implementacja dynamiczna tablicą
class Stack {
    public:
    int currentSize;
    int* stack;
    int tail;
        Stack() {
            this->currentSize = 2;
            this->stack = new int[currentSize]{};
            this->tail = -1;
        };

        ~Stack() {
            delete[] this->stack;
        }

        int top() {
            if (!this->empty()) {
                return this->stack[this->tail];
            }
            return 0;
        }

        int size() {
            return this->tail +1;
        }

        void resize() {
            this->currentSize *= 2;
            int* newStack = new int[this->currentSize]{};
            for (int i = 0; i < this->tail; i++) {
                newStack[i] = this->stack[i];
            }
            delete[] this->stack;
            this->stack = newStack;
        }

        void push(int x) {
            if (this->tail == this->currentSize - 1) {
                this->resize();
            }
            this->stack[++this->tail] = x;
        }

        void pop() {
            if (!this->empty()) {
                this->tail--;
            }
        }

        bool empty() {
            if (this->tail == -1) {
                return true;
            }
            return false;
        }
};

//implementacja listą jednokierunkową
struct Element {
    int head;
    Element* next;

    Element(int x, Element* next = nullptr) {
        this->head = x  ;
        this->next = next;
    }
};

class LinkedList {
public:
    int currentSize;
    Element* topElement;

    LinkedList() {
        this->topElement = nullptr;
        this->currentSize = 0;
    }

    ~LinkedList() {
        while (!this->empty()) {
            this->pop();
        }
    }

    bool empty() {
        return this->topElement == nullptr;
    }

    int size() {
        return this->currentSize;
    }

    void push(int x) {
        this->topElement = new Element(x, this->topElement);
        this->currentSize++;
    }

    void pop() {
        if (!this->empty()) {
            Element* temp = this->topElement;
            this->topElement = this->topElement->next;
            delete temp;
            this->currentSize--;
        }
    }
    int top() {
        if (!this->empty()) {
            return this->topElement->head;
        }
    }
};

//implementacje std::stack

int main() {
    // tablica
    Stack sterta;

    // stack
    //stack<int> sterta;

    // LinkedList
    //LinkedList sterta;

    fstream file = openFile("../assets/z4/input.txt");

    int amount;

    file >> amount;

    for (int i = 0; i < amount; i++) {
        int temp;
        file >> temp;
        cout << "dodano do stosu ";
        sterta.push(temp);
        cout << sterta.top() << endl;
    }

    cout << "sprawdzanie czy stos jest pusty" << endl;
    if (sterta.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    cout << "liczba elementow w stosie" << endl;
    cout << sterta.size() << endl;

    cout << "wartosc szcztowego elementu w stosie" << endl;
    cout << sterta.top() << endl;

    cout << "zdjecie ostatniego elementu ze szczytu" << endl;
    sterta.pop();
    cout << sterta.top() << endl;
}