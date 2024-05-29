#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void push(T value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
        cout << "Stack destroyed" << endl;
    }
};

int main() {
    Stack<int> s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}
