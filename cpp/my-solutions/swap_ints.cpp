#include <iostream>

void swap_ints(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a = 5;
    int b = 10;
    std::cout << "a = " << a << " b = " << b;
    swap_ints(&a, &b);
    std::cout << "\nafter swap\n"
              << "a = " << a << " b = " << b;
    return 0;
}