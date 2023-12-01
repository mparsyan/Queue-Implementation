#include "queue.hpp"
#include <iostream>

int main()
{
    Queue<int> q1;

    // Enqueue elements
    std::cout << "Enqueueing elements..." << std::endl;
    for (int i = 1; i <= 5; ++i) 
    {
        q1.enqueue(i);
    }
    q1.print();

    // Display size of the queue
    std::cout << "Size of queue after enqueueing: " << q1.size() << std::endl;

    // Demonstrate front and rear
    std::cout << "Front element: " << q1.front() << std::endl;
    std::cout << "Rear element: " << q1.rear() << std::endl;

    // Dequeue elements
    std::cout << "Dequeuing..." << std::endl;
    q1.dequeue();
    q1.print();

    // Copy constructor
    std::cout << "Using copy constructor..." << std::endl;
    Queue<int> q2(q1);
    q2.print();

    // Move constructor
    std::cout << "Using move constructor..." << std::endl;
    Queue<int> q3(std::move(q2));
    q3.print();

    // Copy assignment operator
    std::cout << "Using copy assignment operator..." << std::endl;
    Queue<int> q4;
    q4 = q1;
    q4.print();

    // Move assignment operator
    std::cout << "Using move assignment operator..." << std::endl;
    Queue<int> q5;
    q5 = std::move(q4);
    q5.print();

    // Check if queue is empty
    std::cout << "Is \"q1\" queue empty? " << (q1.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is \"q2\" queue empty? " << (q2.isEmpty() ? "Yes" : "No") << std::endl;    
    return 0;
}
