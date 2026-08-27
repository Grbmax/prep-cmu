// bits/stdc++.h — portability shim.
//
// This header is a GCC/libstdc++ convenience that does not exist in Apple clang's
// libc++, so competitive-programming code that opens with `#include <bits/stdc++.h>`
// fails to compile on a Mac out of the box. The Makefile adds `-Itemplates` so that
// include resolves to this file instead, and your solutions stay copy-pasteable to
// LeetCode / Codeforces (both of which use GCC, where the real header exists).
//
// Nothing here is magic — it is just the common standard headers.

#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
