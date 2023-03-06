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

int Queue::size() const{
    return numOrders;
}

bool Queue::empty() const{
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

Order *Queue::peekFirst() const{
    if(empty()){
        return nullptr;
    }
    head->data->print();
    return head->data;
}

Order *Queue::popFirst() {
    if(empty()){
        return nullptr;
    }
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