#include <iostream>
#include <time.h>

int main()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long long nanoseconds = ts.tv_sec * 1000000000 + ts.tv_nsec;
    std::cout << "Nanoseconds since epoch: " << nanoseconds << std::endl;
    return 0;
}

