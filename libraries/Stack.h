//
// Created by Pawe on 14.04.2026.
//

#ifndef METODYPROGRAMOWANIA_STACK_H
#define METODYPROGRAMOWANIA_STACK_H


class Stack {
public:
    int currentSize;
    int* stack;
    int tail;

    Stack();

    ~Stack();

    int top();

    int size();

    void resize();

    void push(int x);

    void pop();

    bool empty();
};


#endif //METODYPROGRAMOWANIA_STACK_H