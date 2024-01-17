#include "grainedQueue.h"

FineGrainedQueue::FineGrainedQueue(int initVal)
{
    head_ = new Node(initVal);
}

FineGrainedQueue::~FineGrainedQueue()
{
    clear();
}

void FineGrainedQueue::insertIntoMiddle(int value, int pos)
{
    auto newNode = new Node(value);
    pos = (pos <= 0)? 1 : pos;
    int currentPos = 0;
    auto currentNode = head_;
    while(currentPos < pos - 1 && currentNode->next_)
    {
        currentNode = currentNode->next_;
        ++currentPos;
    }
    auto next = currentNode->next_;
    currentNode->next_ = newNode;
    newNode->next_ = next;
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
