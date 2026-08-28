// Problem : Remove duplicates from sorted array   Step: 03-arrays / Striver #4
// Link    : https://takeuforward.org/data-structure/remove-duplicates-in-place-from-a-sorted-array/
// ---------------------------------------------------------------------------
// PATTERN GUESS (write this BEFORE you code — being wrong here is useful data):
//   Guessed hash-set of seen elements (TS instinct). Correct approach for
//   unsorted+order-preserving, but overkill here since the array is sorted.
//
// BRUTE FORCE (in words, with complexity):
//   Hash set of seen values, build a new deduped array.    O(n) time / O(n) space
//
// CHOSEN APPROACH:
//   Sorted array means duplicates are adjacent. Two-index in-place compaction:
//   read scans every element every iteration; write only advances (and copies
//   nums[read] into the new slot) when nums[read] != nums[write].
//                                                           O(n) time / O(1) space
//
// AFTER SOLVING — fill these in from memory before checking:
//   Actual pattern name : two pointers, fast/slow geometry (see patterns/01-two-pointers.md, problem B)
//   Time  : O(n)   because read visits every element exactly once
//   Space : O(1)   because two index variables regardless of n
//   Variant to think about: unsorted + order must be preserved -> hash set of
//     seen values instead of adjacent-compare, O(n) time / O(n) space
// ---------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --- solution -------------------------------------------------------------

// TODO
size_t remove_duplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    size_t write = 0;
    for (size_t read = 1; read < nums.size(); read++) {
        if (nums[read] != nums[write]) {
            write++;
            nums[write] = nums[read];
        }
    }
    return write + 1;
}

// --- driver ---------------------------------------------------------------

void run_case(vector<int> nums) {
    size_t k = remove_duplicates(nums);
    cout << "k=" << k << "  unique prefix: ";
    for (size_t i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << "\n";
}

int main() {
    run_case({});                     // empty
    run_case({7});                    // single element
    run_case({1, 1, 1, 1});           // all-same
    run_case({-3, -3, -1, 0, 0, 2});  // negatives + duplicates mixed
    run_case({0, 1, 2, 3, 4});        // no duplicates at all
    return 0;
}
