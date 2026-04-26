#include "Stack.h"

Stack::Stack() {
    this->currentSize = 2;
    this->stack = new int[currentSize]{};
    this->tail = -1;
};

Stack::~Stack() {
    delete[] this->stack;
}

int Stack::top() {
    if (!this->empty()) {
        return this->stack[this->tail];
    }
    return 0;
}

int Stack::size() {
    return this->tail +1;
}

void Stack::resize() {
    this->currentSize *= 2;
    int* newStack = new int[this->currentSize]{};
    for (int i = 0; i < this->tail; i++) {
        newStack[i] = this->stack[i];
    }
    delete[] this->stack;
    this->stack = newStack;
}

void Stack::push(int x) {
    if (this->tail == this->currentSize - 1) {
        this->resize();
    }
    this->stack[++this->tail] = x;
}

void Stack::pop() {
    if (!this->empty()) {
        this->tail--;
    }
}

bool Stack::empty() {
    if (this->tail == -1) {
        return true;
    }
    return false;
}

