#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>

class Queue {
private:
    T* p{nullptr};
    int left{0};
    int right{0};
    int space{0};

    void reserve(int size);

public:
    Queue() = default;
    ~Queue() {delete[] p;}
    Queue(const Queue &queue);

    Queue& operator= (const Queue &queue) {
    delete[] p;
    int size = queue.size();
    reserve(size);
    left = 0;
    right = 0;
    for (int i = queue.left; i < queue.right; i++, right++) {
        p[right] = queue.p[i];
        }
    }
    void push(T x);
    void pop();
    void print() const;
    int size() const;
    T top() const;
    void clear();
    void isEmpty() const;

};

template<typename T>
Queue<T>::Queue(const Queue &queue) {
    int size = queue.size();
    reserve(size);
    left = 0;
    right = 0;
    for (int i = queue.left; i < queue.right; i++, right++) {
        p[right] = queue.p[i];
    }
}

template<typename T>
void Queue<T>::reserve(int size) {
    if (space >= size) {
        return;
    }
    T *t = new T[size];
    int j = 0;
    for (int i = left; i < right; i++, j++) {
        t[j] = p[i];
    }
    delete[] p;
    p = t;
    left = 0;
    right = j;
    space = size;
}

template<typename T>
void Queue<T>::push(T x) {
    if (space == 0) {
        reserve(4);
    }
    else if (right == space) {
        if (left > space / 2) {
            int j = 0;
            for (int i = left; i < right; i++, j++)
                p[j] = p[i];
            left = 0;
            right = j;
        }
        else reserve(space*2);
    }
    p[right] = x;
    right++;
}

template<typename T>
void Queue<T>::pop() {
    if (left == right) {
        cout << "Queue is empty." << endl;
        return;
    }
    left++;
}

template<typename T>
int Queue<T>::size() const {
    return right - left;
}

template<typename T>
T Queue<T>::top() const {
    if (right-left == 0) {
        cout << "Queue is empty, top element is not found." << endl;
        return 0;
    }
    return p[left];
}

template<typename T>
void Queue<T>::clear() {
    delete[] p;
    p = nullptr;
    left = 0;
    right = 0;
    space = 0;
}

template<typename T>
void Queue<T>::isEmpty() const {
    if (right-left == 0) {
        cout << "Queue is empty." << endl;
    }
    else {
        cout << "Queue isn't empty." << endl;
    }
}

template<typename T>
void Queue<T>::print() const {
    cout << "Queue(";
    for (int i = left; i < right; i++) {
        cout << p[i] << (i < right - 1 ? ", " : "");
    }
    cout << ")\n";
}


#endif // QUEUE_H_INCLUDED
