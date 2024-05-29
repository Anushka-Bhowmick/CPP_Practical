#include <iostream>
using namespace std;

class Stack {
    private:
        int* arr;
        int top;
        int capacity;
    public:
        Stack(int size) {
            arr = new int[size];
            capacity = size;
            top = -1;
        }

        ~Stack() {
            delete[] arr;
        }

        void push(int x) {
            if (isFull()) {
                cout << "Stack Overflow\n";
                return;
            }
            arr[++top] = x;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return -1;
            }
            return arr[top--];
        }

        int peek() {
            if (!isEmpty()) {
                return arr[top];
            } else {
                cout << "Stack is empty\n";
                return -1;
            }
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == capacity - 1;
        }

        int size() {
            return top + 1;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return;
            }
            cout << "Stack contents (bottom to top): ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Get stack size\n";
        cout << "7. Display stack\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1)
                    cout << "Popped value: " << value << endl;
                break;
            case 3:
                value = stack.peek();
                if (value != -1)
                    cout << "Top value: " << value << endl;
                break;
            case 4:
                if (stack.isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
                break;
            case 5:
                if (stack.isFull())
                    cout << "Stack is full\n";
                else
                    cout << "Stack is not full\n";
                break;
            case 6:
                cout << "Current stack size: " << stack.size() << endl;
                break;
            case 7:
                stack.display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
