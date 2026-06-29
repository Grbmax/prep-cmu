#include <iostream>

int *make_squares(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * (i + 1);
    }
    return arr;
}

// const int *arr because print is just reading it, a pointer to a read-only int
void print_array(const int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }
}

int main()
{
    size_t n = 5;
    int *array = make_squares(n);
    print_array(array, n);
    delete[] array;
    return 0;
}