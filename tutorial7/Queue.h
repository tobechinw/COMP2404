#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Order.h"

class Queue {
    class Node {
        public:
            Node *next;
            Order *data;
    };

    public:
        Queue();
        ~Queue();
        bool empty() const;
        int size() const;
        Order* peekFirst() const;
        Order* popFirst();
        void addLast(Order* order);

    private:
        Node *head;
        Node *tail;
        int numOrders;
};

#endif