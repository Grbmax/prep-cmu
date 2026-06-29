#include <iostream>
#include <utility>
#include <unordered_map>
#include <stdexcept>

std::pair<int, int> two_sum_unsorted(const std::vector<int> &nums, int target)
{
    std::unordered_map<int, size_t> seen;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int need = target - x;
        if (seen.count(need))
            return {(int)seen[need], i};
        seen[x] = i;
    }
    throw std::logic_error("no pair found");
}

int main()
{
    std::vector<int> arr = {2, 7, 11, 13, 17};
    int target = 19;
    std::pair<int, int> p = two_sum_unsorted(arr, target);
    std::cout
        << "first: " << p.first << "\t second: " << p.second << "\n";
    return 0;
}