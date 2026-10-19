#ifndef DRAFTEVIDENCE2_NODESTACK_H
#define DRAFTEVIDENCE2_NODESTACK_H
#include "NodeDoubly.h"

class NodeStack {
public:
    NodeDoubly* L;
    NodeDoubly* R;
    NodeStack* next;

    NodeStack(NodeDoubly* left, NodeDoubly* right) {
        L = left;
        R = right;
        next = nullptr;
    }
};

#endif //DRAFTEVIDENCE2_NODESTACK_H
