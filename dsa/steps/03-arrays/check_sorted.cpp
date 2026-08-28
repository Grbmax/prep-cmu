// Problem : Check if array is sorted   Step: 03-arrays / Striver #3
// Link    : https://takeuforward.org/data-structure/check-if-an-array-is-sorted/
// ---------------------------------------------------------------------------
// PATTERN GUESS (write this BEFORE you code — being wrong here is useful data):
//   Guessed sorting-adjacent, correctly spotted early exit was possible.
//
// BRUTE FORCE (in words, with complexity):
//   Walk the array, compare each element to the previous one, bail the moment
//   a violation is found.                                  O(n) time / O(1) space
//
// CHOSEN APPROACH:
//   Same as brute force, rewritten from flag-variable+break to direct early
//   return — one fewer variable, same complexity.           O(n) time / O(1) space
//
// AFTER SOLVING — fill these in from memory before checking:
//   Actual pattern name : linear scan, early-exit
//   Time  : O(n)   because worst case (already sorted) visits every element
//   Space : O(1)   because one running "previous value" var regardless of n
//   Variant to think about: strictly increasing -> change < to <=
// ---------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --- solution -------------------------------------------------------------

// TODO
bool check_sorted(vector<int>& nums) {
    if (nums.empty()) {
        return false;
    }

    int prev_val = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] < prev_val)
            return false;
        prev_val = nums[i];
    }
    return true;
}

// --- driver ---------------------------------------------------------------

int main() {
    // Test the edge cases deliberately: empty, one element, all-same,
    // all-negative, target absent, duplicates.

    vector<int> array1 = {1, 2, 3, 4};
    vector<int> array2 = {-1, -2, -3, -4};
    vector<int> array3 = {};

    cout << "array1: " << check_sorted(array1);
    cout << "\narray2: " << check_sorted(array2);
    cout << "\narray3: " << check_sorted(array3);
    return 0;
}
