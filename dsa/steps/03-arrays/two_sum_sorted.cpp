#include <iostream>
#include <utility>
#include <stdexcept>

std::pair<int, int> two_sum_sorted(const std::vector<int> &nums, int target)
{
    for (size_t i = 0; i < nums.size(); i++)

        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)

                return {i, j};
        }
    throw std::logic_error("no pair found");
}

std::pair<int, int> two_sum_sorted_fast(const std::vector<int> &nums, int target)
{
    size_t lo = 0;
    size_t hi = nums.size() - 1;
    while (lo < hi)
    {
        int sum = nums[lo] + nums[hi];
        // debug print
        //  std::cout << "lo" << lo << " hi" << hi << " sum" << sum << "\n";
        if (sum == target)
            return {lo, hi};
        else if (sum < target)
            lo++;
        else
            hi--;
    }
    throw std::logic_error("no pair found");
}

int main()
{

    // If sorted array, then go with two pointers
    // If unsorted then go for hashMap

    std::vector<int> arr = {2, 7, 11, 13, 17};
    int target = 100;
    std::pair<int, int> p = two_sum_sorted_fast(arr, target);
    std::cout << "first: " << p.first << "\t second: " << p.second << "\n";
    return 0;
}

