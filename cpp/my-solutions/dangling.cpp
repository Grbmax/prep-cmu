#include <iostream>

int *make_counter_start_broken()
{
    int start = 100;
    return &start;
}

int *make_counter_start_heap()
{
    int *start = new int(100);
    return start;
}

int make_counter_start_value()
{
    return 100;
}

int main()
{
    int *val = make_counter_start_broken();
    int *heap = make_counter_start_heap();
    int int_val = make_counter_start_value();
    std::cout << "broken:" << *val << "\n";
    std::cout << "heap:" << *heap << "\n";
    std::cout << "value:" << int_val << "\n";

    delete heap;

    return 0;
}