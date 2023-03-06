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
        bool empty();
        int size();
        Order* peekFirst();
        Order* popFirst();
        void addLast(Order* order);

    private:
        Node *head;
        Node *tail;
        int numOrders;
};

#endif