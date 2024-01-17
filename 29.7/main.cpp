#include "grainedQueue.h"

int main()
{
    FineGrainedQueue q(42);
    q.insertIntoMiddle(43, 0);
    q.insertIntoMiddle(44, 4);
    q.insertIntoMiddle(66, 2);
    q.insertIntoMiddle(100, 22);
    q.show();
}
