// Problem : Largest element in an array   Step: 03-arrays / Striver #1
// Link    : https://takeuforward.org/data-structure/find-maximum-minimum-element-in-an-array/
// ---------------------------------------------------------------------------
// PATTERN GUESS (write this BEFORE you code — being wrong here is useful data):
//   Guessed "sorting" — actually a single linear scan, no sort needed.
//
// BRUTE FORCE (in words, with complexity):
//   Walk the array once, track the running max seen so far.  O(n) time / O(1) space
//
// CHOSEN APPROACH:
//   Same as brute force — a single pass is already optimal; you must look at
//   every element at least once.                             O(n) time / O(1) space
//
// AFTER SOLVING — fill these in from memory before checking:
//   Actual pattern name : linear scan / single-pass reduction
//   Time  : O(n)   because every element is visited exactly once
//   Space : O(1)   because only one running variable is held regardless of n
//   Variant to think about: track index of the max, not just the value
// ---------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --- solution -------------------------------------------------------------

int largest_element(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "empty array";
        return 0;
    }
    int largest = arr[0];
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "largest element is" << largest;
    return largest;
}

// --- driver ---------------------------------------------------------------

int main() {
    // Test the edge cases deliberately: empty, one element, all-same,
    // all-negative, target absent, duplicates.
    vector<int> array1 = {1, 2, 3, 4};
    vector<int> array2 = {-1, -2, -3, -4};
    vector<int> array3 = {};

    largest_element(array1);
    largest_element(array2);
    largest_element(array3);
    return 0;
}
