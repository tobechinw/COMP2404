#include "Queue.h"

using namespace std;


Queue::Queue() {
    head = NULL;
    tail = NULL;
    numOrders = 0;
}

Queue::~Queue() {
    cout<<"queue ctor"<<endl;
}

int Queue::size() {
    return numOrders;
}

bool Queue::empty() {
    return size() == 0;
}

void Queue::addLast(Order *order) {

    Node *node = new Node;
    node->data = order;
    node->next = NULL;
    if(tail == NULL){
        tail = node;
        head = tail;
    }else{
        tail->next = node;
        tail = node;
    }
    numOrders++;
}

Order *Queue::peekFirst() {
    if(empty()){
        return nullptr;
    }
    head->data->print();
    return head->data;
}

Order *Queue::popFirst() {
    if(empty()){
        cout<<"empty"<<endl;
        return nullptr;
    }

    cout<<"not empty"<<endl;

    Node* tmp = head;
    Order* ret = tmp->data;
    head = head->next;
    numOrders--;
    if(head == NULL){
        tail = NULL;
    }

    return ret;

//    return nullptr;
}