#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;       // Dynamic array to store queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int maxSize;    // Maximum capacity of the queue
    int size;       // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        maxSize = capacity;
        arr = new int[maxSize];
        front = 0;    // Front starts at the 0th index
        rear = -1;    // Rear is initialized to -1
        size = 0;     // No elements in the queue initially
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation: Add an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        } else {
            rear = (rear + 1) % maxSize; // Circular increment of rear
            arr[rear] = value;
            size++;
            cout << value << " enqueued to queue." << endl;
        }
    }

    // Dequeue operation: Remove the front element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1; // Return a sentinel value
        } else {
            int dequeuedValue = arr[front];
            front = (front + 1) % maxSize; // Circular increment of front
            size--;
            return dequeuedValue;
        }
    }

    // Peek operation: Get the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No element to peek." << endl;
            return -1; // Return a sentinel value
        } else {
            return arr[front];
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == maxSize;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[(front + i) % maxSize] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the size of the queue: ";
    cin >> capacity;

    Queue queue(capacity);

    return 0;
}
