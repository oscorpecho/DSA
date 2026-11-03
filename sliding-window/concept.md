# Sliding Window

## 1. What is Sliding Window?

Sliding Window is a technique used to solve problems involving **contiguous subarrays or substrings**.

Instead of repeatedly calculating values for every possible subarray/substring, we maintain a window using two pointers:

- `left` → starting index of the window
- `right` → ending index of the window

We expand the window by moving `right` and shrink it by moving `left`.

**Window size:**

```cpp
right - left + 1
```

The goal is to avoid unnecessary repeated work and solve many problems in O(n).

---

## 2. When should I use Sliding Window?

Look for these clues in a problem:

- Contiguous subarray or substring
- K consecutive elements
- Maximum/minimum sum of a subarray of size K
- Longest substring satisfying a condition
- Shortest subarray satisfying a condition
- At most K distinct characters/elements
- No repeating characters

**Important:** Sliding Window is generally for contiguous elements, not subsequences.

---

## 3. Types of Sliding Window

### A. Fixed Size Window

The window size `k` is given in the problem.

Examples:
- Maximum sum of a subarray of size K
- Maximum average of a subarray of size K
- First negative number in every window of size K

**Approach:**

1. Expand the window by moving `right`.
2. Add the incoming element to the window.
3. Once the window size becomes K, calculate/update the answer.
4. Remove the outgoing element at `left`.
5. Increment `left` to slide the window.

**C++ Template:**

```cpp
int left = 0;
int windowSum = 0;
int ans = 0;

for (int right = 0; right < n; right++) {

    // Add incoming element
    windowSum += arr[right];

    // Process when window size becomes k
    if (right - left + 1 == k) {

        ans = max(ans, windowSum);

        // Remove outgoing element
        windowSum -= arr[left];
        left++;
    }
}
```

**Key idea:** Add one element, process the window, remove one element.

---

### B. Variable Size Window

The window size is not fixed. It changes depending on a condition.

Examples:
- Longest substring without repeating characters
- Minimum size subarray sum
- Longest substring with at most K distinct characters
- Max consecutive ones with at most K flips

There are two common variations:

#### 1. Find the longest valid window

**Approach:**

1. Expand the window by moving `right`.
2. Add the incoming element.
3. While the window is invalid, shrink it from the left.
4. Once valid, calculate the window size and update the maximum answer.

**C++ Template:**

```cpp
int left = 0;
int ans = 0;

for (int right = 0; right < n; right++) {

    // Add incoming element

    while (window is invalid) {

        // Remove outgoing element
        left++;
    }

    // Current window is valid
    ans = max(ans, right - left + 1);
}
```

#### 2. Find the shortest valid window

**Approach:**

1. Expand the window.
2. Add the incoming element.
3. While the window is valid:
   - Update the minimum answer.
   - Shrink the window from the left.

**C++ Template:**

```cpp
int left = 0;
int ans = INT_MAX;

for (int right = 0; right < n; right++) {

    // Add incoming element

    while (window is valid) {

        ans = min(ans, right - left + 1);

        // Remove outgoing element
        left++;
    }
}
```

**Remember the difference:**

- Longest valid window → shrink while invalid, then update answer.
- Shortest valid window → update answer while valid, then shrink.

---

## 4. Sliding Window with Data Structures

Sometimes we need additional data structures to track the contents of our window.

| Data structure | When to use |
|---|---|
| `unordered_set` | Track unique elements |
| `unordered_map` | Track frequency of elements |
| `vector<int>` | Frequency counting when the character range is small |
| `deque` | Maintain maximum/minimum efficiently |

### Example: Longest Substring Without Repeating Characters (LC 3)

**Problem:** Find the length of the longest substring without repeating characters.

**Data structure:** `unordered_set<char>`

**Logic:**

1. Expand the window using `right`.
2. Check whether the incoming character already exists.
3. If it exists, shrink the window until the duplicate is removed.
4. Insert the incoming character.
5. Update the maximum window length.

```cpp
int lengthOfLongestSubstring(string s) {

    unordered_set<char> st;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {

        char c = s[right];

        while (st.find(c) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        st.insert(c);

        ans = max(ans, right - left + 1);
    }

    return ans;
}
```

**Why `while` and not `if`?**

There may be multiple characters between `left` and `right` that need to be removed before the incoming character is no longer a duplicate.

**Why `st.erase(s[left])`?**

We are shrinking from the left, so we must remove the outgoing character, not the incoming duplicate character.

---

## 5. Important C++ Syntax

```cpp
// Set
unordered_set<int> st;

st.insert(x);
st.erase(x);
st.find(x) != st.end();

// Map
unordered_map<char, int> mp;

mp[c]++;
mp[c]--;
mp.erase(c);

// Window size
right - left + 1;

// Maximum / minimum
ans = max(ans, right - left + 1);
ans = min(ans, right - left + 1);
```

Note: `st.contains(x)` is available in C++20. `st.find(x) != st.end()` works in older C++ standards too.

---

## 6. Common Mistakes

1. Forgetting that window size is `right - left + 1`.
2. Using `if` instead of `while` when multiple elements may need to be removed.
3. Removing the incoming element instead of the outgoing element.
4. Updating the answer before restoring the window's validity.
5. Forgetting to update the window state when moving `left`.
6. Confusing a substring/subarray with a subsequence.
7. Applying a sum-based variable window blindly when negative numbers are present.

**Important caveat:** The usual expand-and-shrink sliding window for sum constraints works naturally with positive numbers. Negative numbers can break the logic because extending a window may decrease its sum.

---

## 7. Complexity

For standard Sliding Window:

- **Time:** O(n), because each pointer moves forward at most n times.
- **Space:** Depends on the data structure used. For example, O(1) for a running sum, or O(k) for a set/map holding the current window.

---

## 8. Problem Revision Checklist

### Fixed Size

- [ ] LC 643 – Maximum Average Subarray I
- [ ] LC 239 – Sliding Window Maximum
- [ ] LC 438 – Find All Anagrams in a String

### Variable Size – Longest Window

- [x] LC 3 – Longest Substring Without Repeating Characters
- [ ] LC 1004 – Max Consecutive Ones III
- [ ] LC 904 – Fruit Into Baskets
- [ ] LC 340 – Longest Substring with At Most K Distinct Characters

### Variable Size – Minimum Window

- [ ] LC 209 – Minimum Size Subarray Sum
- [ ] LC 76 – Minimum Window Substring

---

## 9. Quick Revision: How to Approach a Problem

Whenever I encounter a Sliding Window problem, ask:

1. Is the problem asking about a contiguous subarray or substring?
2. Is the window size fixed or variable?
3. What makes the current window valid or invalid?
4. What information do I need to maintain? Sum, frequency, set, map, etc.
5. When should I shrink the window?
6. When should I update the answer?

**Core idea to remember:**

Don't recalculate every possible subarray. Maintain a window, update it as you move the pointers, and reuse the information already available.
