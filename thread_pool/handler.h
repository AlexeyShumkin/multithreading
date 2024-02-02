#include "pool.h"

class RequestHandler
{
public:
    RequestHandler();
    ~RequestHandler();
    std::future<void> push_task(FuncType f, int* arr, long arg1, long arg2);
private:
    ThreadPool pool_;
};
