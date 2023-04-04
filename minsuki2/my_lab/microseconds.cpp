#include <iostream>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
	std::size_t	microseconds = tv.tv_sec * 1000000 + tv.tv_usec;
    std::cout << "Microseconds since epoch: " << microseconds << std::endl;
    return 0;
}

