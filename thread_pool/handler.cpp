#include "handler.h"

RequestHandler::RequestHandler()
{
    pool_.start();
}

RequestHandler::~RequestHandler()
{
    pool_.stop();
}

res_type RequestHandler::push_task(FuncType f, RequestHandler& rh, int* arr, long arg1, long arg2)
{
    return pool_.push_task(f, rh, arr, arg1, arg2);
}
