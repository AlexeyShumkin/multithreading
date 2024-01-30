#include "pool.h"

class RequestHandler
{
public:
    RequestHandler();
    ~RequestHandler();
    res_type push_task(FuncType f, RequestHandler& rh, int* arr, long arg1, long arg2);
private:
    ThreadPool pool_;
};
