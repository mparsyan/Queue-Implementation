#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template <typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue& other);
    Queue(Queue&& other);

    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other);
    ~Queue();

public:
    void enqueue(T elem);
    void dequeue();
    T& front();
    T& rear();
    bool isEmpty() const;
    size_t size() const;
    void print() const;

private:
    T* m_ptr;
    size_t m_size;
    size_t m_capacity;
    size_t m_start;
    size_t m_end;
};

#include "queue_impl.hpp"
#endif  // QUEUE_HPP