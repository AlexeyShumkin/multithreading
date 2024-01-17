#include <iostream>
#include <mutex>

struct Node
{
    Node(int value) : value_{ value }, next_{ nullptr } {}
    int value_;
    Node* next_;
    std::mutex* nodeMutex_;
};

class FineGrainedQueue
{
public:
    FineGrainedQueue(int initVal);
    ~FineGrainedQueue();
    void insertIntoMiddle(int value, int pos);
    void show();
    void clear();
private:
    Node* head_;
    std::mutex* queueMutex_;
};
