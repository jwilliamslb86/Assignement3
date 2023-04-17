#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* front_node;
    Node* rear_node;
    int size;

public:
    Queue() : front_node(nullptr), rear_node(nullptr), size(0) {}

    void push(T value) {
        Node* new_node = new Node(value);
        if (rear_node == nullptr) {
            front_node = rear_node = new_node;
        }
        else {
            rear_node->next = new_node;
            rear_node = new_node;
        }
        size++;
    }

    T pop() {
        if (front_node == nullptr) {
            throw runtime_error("Queue is empty");
        }
        Node* temp = front_node;
        T value = temp->data;
        front_node = front_node->next;
        if (front_node == nullptr) {
            rear_node = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    T front() const {
        if (front_node == nullptr) {
            throw runtime_error("Queue is empty");
        }
        return front_node->data;
    }

    bool empty() const {
        return front_node == nullptr;
    }

    int get_size() const {
        return size;
    }
};
