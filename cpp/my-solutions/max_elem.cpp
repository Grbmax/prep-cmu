#include <iostream>
#include <vector>
#include <stdexcept>

const int &find_max_elem(const std::vector<int> &v)
{
    size_t pos = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > v[pos])
        {
            pos = i;
        }
    }
    return v[pos];
}

int main()
{
    int max = find_max_elem({70, 20, 190, 60});
    std::cout << "max elem is " << max;
    return 0;
}

// If i was mogging
// #include <algorithm>
// int m = *std::max_element(v.begin(), v.end());