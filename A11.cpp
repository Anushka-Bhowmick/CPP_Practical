#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
public:
    Queue(int size) {
        arr = new T[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    void enqueue(T value) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[i] << endl;
    }

    ~Queue() {
        delete[] arr;
        cout << "Queue destroyed" << endl;
    }
};

int main() {
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
