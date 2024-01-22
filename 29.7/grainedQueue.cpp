#include "grainedQueue.h"

FineGrainedQueue::FineGrainedQueue(int initVal)
{
    head_ = new Node(initVal);
}

FineGrainedQueue::~FineGrainedQueue()
{
    clear();
}

void FineGrainedQueue::insertIntoMiddle(int value, size_t position)
{
    Node *previous,*current;
    queueMutex_.lock();
    previous = head_;
    current = head_->next_;
    previous->nodeMutex_.lock();
    queueMutex_.unlock();
    if(current)
    {
        current->nodeMutex_.lock();
    }
    int currentPosition = 0;
    while (currentPosition < position - 1 && current)
    {
        auto oldPrevious = previous;
        previous = current;
        current = current->next_;
        oldPrevious->nodeMutex_.unlock();
        if (current)
        {
            current->nodeMutex_.lock();
        }
        ++currentPosition;
    }
    auto next = current;
    auto newNode = new Node(value);
    previous->next_ = newNode;
    newNode->next_ = next;
    previous->nodeMutex_.unlock();
    if(current)
    {
        current->nodeMutex_.unlock();
    }
}

void FineGrainedQueue::clear()
{
    Node* current{ nullptr };
    while(head_)
    {
        current = head_;
        head_ = head_->next_;
        delete current;
    }
}

void FineGrainedQueue::show()
{
    auto current = head_;
    while (current)
    {
        std::cout << current->value_ << " -> ";
        current = current->next_;
    }
    std::cout << std::endl;
}
