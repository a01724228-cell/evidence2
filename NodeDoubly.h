#ifndef DRAFTEVIDENCE2_NODE_H
#define DRAFTEVIDENCE2_NODE_H
#include "Date.h"

class NodeDoubly {
public:
    string ip;
    Date date;
    string line;
    NodeDoubly* next;
    NodeDoubly* prev;

    /* Description: Constructor that takes the value to be placed
     *              in the node and sets next and previous to nullptr.
     * Parameters: val - value for the node
     * Return Value: None (constructor)
     * Complexity: O(1)
    */
    NodeDoubly(string IP, Date d, string compLine) {
        date = d;
        ip = IP;
        line = compLine;
        next = nullptr;
        prev = nullptr;
    }

    bool operator<(const NodeDoubly& other) {
        if (ip < other.ip) {
            return true;
        }
        if (ip == other.ip) {
            int comparison = date.beforeAfter(other.date);
            if (comparison == -1) {
                return true;
            }
            return false;
        }
        return false;
    }
};

#endif //DRAFTEVIDENCE2_NODE_H
