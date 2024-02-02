#include "handler.h"
#include <iostream>

RequestHandler::RequestHandler()
{
    pool_.start();
}

RequestHandler::~RequestHandler()
{
    pool_.stop();
}

std::future<void> RequestHandler::push_task(FuncType f, int* arr, long arg1, long arg2)
{
    return pool_.push_task(f, arr, arg1, arg2);
}
