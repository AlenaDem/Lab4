#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q;
    cout << "Push:\n";
    for (int i =0; i < 10; i++) {
        q.push(i);
    }
    q.print();
    cout << "Size: " << q.size() << endl;
    cout << "Top: " << q.top() << endl;

    cout << endl << "Pop (0-7):\n";
    for (int i =0; i < 8; i++) {
        q.pop();
    }
    q.print();
    cout << "Size: " << q.size() << endl;
    cout << "Top: " << q.top() << endl << "isEmpty: ";
    q.isEmpty();


    cout << endl << "Copy:\n";
    Queue<int> secondq(q);
    secondq.print();

    q.clear();
    cout << "\nClear: " << endl;
    q.print();
    cout << "isEmpty: ";
    q.isEmpty();

    q.push(5);
    cout << "\nOperator overloading =:\nQueue 1:\n";
    q.print();
    cout << "Queue 2:\n";
    secondq.print();
    cout << "Queue 1 = Queue 2:\n";
    q = secondq;
    q.print();
    secondq.print();
}
