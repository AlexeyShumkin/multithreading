#include <thread>
#include "grainedQueue.h"

int main()
{
    FineGrainedQueue q(1);
    // insertion in the non-positive position will be redirected to the first position
    q.insertIntoMiddle(22, 0);
    q.insertIntoMiddle(3, 2);
    q.insertIntoMiddle(4, 3);
    q.show();
    std::thread t1(&FineGrainedQueue::insertIntoMiddle, &q, 66, 3);
    std::thread t2(&FineGrainedQueue::insertIntoMiddle, &q, 77, 3);
    // if the position is longer than the list length, the insertion takes place at the end of the list 
    q.insertIntoMiddle(99, 88);
    t2.join();
    t1.join();
    q.show();
}
