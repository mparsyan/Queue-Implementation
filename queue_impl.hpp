#include "queue.hpp"

// Default constructor
template <typename T>
Queue<T>::Queue()
    : m_ptr(nullptr)
    , m_size(0)
    , m_capacity(0)
    , m_start(0)
    , m_end(1)
    {}

// Copy constructor
template <typename T>
Queue<T>::Queue(const Queue& other)
    : m_ptr(nullptr)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
    , m_start(other.m_start)
    , m_end(other.m_end)
    {
        if (other.m_ptr)
        {
            m_ptr = new T[m_capacity];
            for (size_t i = m_start; i < m_end - 1; ++i)
            {
                m_ptr[i] = other.m_ptr[i];           
            }
        }
    }

// Move constructor
template <typename T>
Queue<T>::Queue(Queue&& other)
    : m_ptr(other.m_ptr)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
    , m_start(other.m_start)
    , m_end(other.m_end)
    {
        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_start = 0;
        other.m_end = 0;
    }

// Copy assignment operator
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this != &other)
    {
        delete[] m_ptr;

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_start = other.m_start;
        m_end = other.m_end;

        if (other.m_ptr)
        {
            m_ptr = new T[m_capacity];
            for (size_t i = m_start; i < m_end - 1; ++i)
            {
                m_ptr[i] = other.m_ptr[i];
            }
        }
        else
        {
            m_ptr = nullptr;
        }
    }
    return *this;
}

// Move assignment operator
template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
{
    if (this != &other)
    {
        delete[] m_ptr;

        m_ptr = other.m_ptr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_start = other.m_start;
        m_end = other.m_end;

        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_start = 0;
        other.m_end = 0;
    }
    return *this;
}

// Destructor
template <typename T>
Queue<T>::~Queue() 
{
    if (m_ptr)
    {
        delete[] m_ptr;
    }
}  

// enqueue() - Inserts an element at the end of the queue i.e. at the rear end
template <typename T>
void Queue<T>::enqueue(T elem)
{
    if(!m_ptr) 
    {
        m_capacity = 1;
        m_ptr = new T[m_capacity];
    }
    if (m_end == m_capacity)
    {
        // Replace the elements of queue one by one
        if (m_start >= m_capacity / 2)          
        {
            for (size_t i = m_start, j = 0; j < m_size; ++i,++j)
            {
                m_ptr[j] = m_ptr[i];
            }
        }

        // Allocate a new memory
        else                                    
        {
            m_capacity *= 2;
            T* tmp = new T[m_capacity];
                for (size_t i = m_start, j = 0; j < m_size; ++i, ++j)
                {
                    tmp[j] = m_ptr[i];
                }
                delete [] m_ptr;
                m_ptr = tmp;
            
        }
        m_end = m_end - m_start;
        m_start = 0;
    } 
    m_ptr[m_end - 1] = elem;
    m_end++;
    m_size++;
}

// dequeue() - This operation removes and returns an element that is at the front end of the queue
template <typename T>
void Queue<T>::dequeue()
{
    if (m_size)
    {
        ++m_start;
        --m_size;
    }
    else 
    {
        throw std::out_of_range("Queue is empty");
    }
}

// front() - This operation returns the element at the front end without removing it
template <typename T>
T& Queue<T>::front()
{
    return m_ptr[m_start];
}

// rear() - This operation returns the element at the rear end without removing it
template <typename T>
T& Queue<T>::rear()
{
    return m_ptr[m_end - 2];
}

//isEmpty() - This operation indicates whether the queue is empty or not
template <typename T>
bool Queue<T>::isEmpty() const
{
    return m_size == 0;
}

//size() - This operation returns the size of the queue i.e. the total number of elements it contains
template <typename T>
size_t Queue<T>::size() const
{
    return m_size;
}

// print() - print elements of queue
template <typename T>
void Queue<T>::print() const
{
    for (size_t i = m_start; i < m_end - 1; ++i)
    {
        std::cout << m_ptr[i] << " ";
    }
    std::cout << std::endl;
}
