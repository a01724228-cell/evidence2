#ifndef DRAFTEVIDENCE2_DOUBLYLINKEDLIST_H
#define DRAFTEVIDENCE2_DOUBLYLINKEDLIST_H
#include "NodeDoubly.h"
#include "StackSingly.h"

class DoublyLinkedList {
private:
    NodeDoubly* head;
    NodeDoubly* tail;

    void swap(NodeDoubly* node1, NodeDoubly* node2) {
        if (node1 == node2 || node1 == nullptr || node2 == nullptr) {
            return;
        }
        if (node1->next == node2) {
            node1->next = node2->next;
            node2->prev = node1->prev;
            node2->next = node1;
            node1->prev = node2;
            if (node2->prev != nullptr) {
                node2->prev->next = node2;
            }
            if (node1->next != nullptr) {
                node1->next->prev = node1;
            }
        }
        else if (node2->next == node1) {
            node2->next = node1->next;
            node1->prev = node2->prev;
            node1->next = node2;
            node2->prev = node1;
            if (node1->prev != nullptr) {
                node1->prev->next = node1;
            }
            if (node2->next != nullptr) {
                node2->next->prev = node2;
            }
        }
        else {
            if (node2->prev != nullptr) {
                node2->prev->next = node1;
            }
            if (node2->next != nullptr) {
                node2->next->prev = node1;
            }
            if (node1->next != nullptr) {
                node1->next->prev = node2;
            }
            if (node1->prev != nullptr) {
                node1->prev->next = node2;
            }
            NodeDoubly* tempPrev = node1->prev;
            NodeDoubly* tempNext = node1->next;
            node1->prev = node2->prev;
            node1->next = node2->next;
            node2->next = tempNext;
            node2->prev = tempPrev;
        }
        if (head == node1) {
            head = node2;
        }
        else if (head == node2) {
            head = node1;
        }
        if (tail == node1) {
            tail = node2;
        }
        else if (tail == node2) {
            tail = node1;
        }
    }

    NodeDoubly* partition(NodeDoubly* left, NodeDoubly* right) {
        NodeDoubly* pivot = right;
        NodeDoubly* i = left->prev;
        NodeDoubly* j = left;
        while (j != pivot) {
            if (*j < *pivot) {
                if (i == nullptr) {
                    i = left;
                }
                else {
                    i = i->next;
                }
                swap(i, j);
            }
            j = j->next;
        }
        if (i == nullptr) {
            i = left;
        }
        else {
            i = i->next;
        }
        swap(i, pivot);
        return i;
    }
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~DoublyLinkedList() {
        while (head != nullptr) {
            NodeDoubly* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addNode(string IP, Date d, string compLine) {
        NodeDoubly* newNode = new NodeDoubly(IP, d, compLine);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    NodeDoubly* getHead() {
        return head;
    }
    NodeDoubly* getTail() {
        return tail;
    }
    void quickSort(NodeDoubly* left, NodeDoubly* right) {
        if (left == nullptr || right == left) {
            return;
        }
        StackSingly stack;
        stack.push(left, right);
        while (!stack.isEmpty()) {
            NodeDoubly* L = stack.getTopLeft();
            NodeDoubly* R = stack.getTopRight();
            stack.pop();
            NodeDoubly* pivot = partition(L, R);
            if (L != pivot && L != pivot->prev) {
                stack.push(L, pivot->prev);
            }
            if (R != pivot && R != pivot->next) {
                stack.push(pivot->next, R);
            }
        }
    }
};

#endif //DRAFTEVIDENCE2_DOUBLYLINKEDLIST_H
