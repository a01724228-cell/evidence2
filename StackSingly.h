#ifndef DRAFTEVIDENCE2_STACKSINGLY_H
#define DRAFTEVIDENCE2_STACKSINGLY_H
#include "NodeStack.h"

class StackSingly {
private:
    NodeStack* top;

public:
    StackSingly() {
        top = nullptr;
    }

    ~StackSingly() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(NodeDoubly* left, NodeDoubly* right) {
        NodeStack* newNode = new NodeStack(left, right);
        newNode->next = top;
        top = newNode;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        NodeStack* temp = top;
        top = top->next;
        delete temp;
    }

    NodeDoubly* getTopLeft() {
        return top->L;
    }

    NodeDoubly* getTopRight() {
        return top->R;
    }
};

#endif //DRAFTEVIDENCE2_STACKSINGLY_H
