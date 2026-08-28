// Problem : Second largest element without sorting   Step: 03-arrays / Striver #2
// Link    :
// https://takeuforward.org/data-structure/find-second-largest-element-in-an-array-without-sorting/
// ---------------------------------------------------------------------------
// PATTERN GUESS (write this BEFORE you code — being wrong here is useful data):
//   Guessed sorting-adjacent — actually a single pass, two running accumulators.
//
// BRUTE FORCE (in words, with complexity):
//   Single pass tracking largest and second-largest simultaneously; when a new
//   largest is found, the old largest demotes to second.  O(n) time / O(1) space
//
// CHOSEN APPROACH:
//   Same as brute force — already optimal for k=2. Two INT_MIN-seeded
//   accumulators, demote-on-new-max, guard duplicates of the max so second
//   stays distinct.                                        O(n) time / O(1) space
//
// AFTER SOLVING — fill these in from memory before checking:
//   Actual pattern name : running top-2 (single-pass); generalizes to top-K via min-heap
//   Time  : O(n)   because one pass, one comparison-set per element
//   Space : O(1)   because two fixed accumulators regardless of n
//   Variant to think about: k-th largest -> min-heap of size k, O(n log k)
// ---------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --- solution -------------------------------------------------------------

int second_largest(vector<int>& nums) {
    if (nums.empty()) {
        cout << "empty array";
        return 0;
    }
    int largest = INT_MIN;
    int s_largest = INT_MIN;

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] > largest) {
            s_largest = largest;
            largest = nums[i];
        } else if (nums[i] > s_largest && nums[i] != largest) {
            s_largest = nums[i];
        }
    }

    if (INT_MIN == s_largest) {
        cout << "\nall nos are the same";
        return 0;
    }

    cout << "\nsecond largest is " << s_largest << "\n";
    return s_largest;
}

// --- driver ---------------------------------------------------------------

int main() {
    // Test the edge cases deliberately: empty, one element, all-same,
    // all-negative, target absent, duplicates.

    vector<int> array1 = {4, 4, 4, 4, 9};
    vector<int> array2 = {-1, -2, -3, -4};
    vector<int> array3 = {};

    second_largest(array1);
    second_largest(array2);
    second_largest(array3);

    return 0;
}
