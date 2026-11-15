# BACKTRACKING — CONCEPT NOTES

## 1. What is Backtracking?

Backtracking is an algorithmic technique where we:
1. Make a choice.
2. Explore that choice using recursion.
3. Undo the choice.
4. Try another possibility.

**Basic pattern:**

`Choose → Explore → Undo`

## 2. General Backtracking Structure

```cpp
void backtrack(...) {

    // Base condition

    for(...) {

        // Check if choice is valid

        // Choose
        path.push_back(...);

        // Explore
        backtrack(...);

        // Undo
        path.pop_back();
    }
}
```

## 3. Important Concepts

### A. Base Conditions

Base conditions decide when to stop exploring a recursive branch.

Examples:

- `remaining < 0` → Invalid combination, return.
- `remaining == 0` → Target achieved, store answer and return.
- `path.size() == nums.size()` → Complete permutation, store answer and return.

### B. Push and Pop

```cpp
path.push_back(nums[i]);
backtrack(...);
path.pop_back();
```

- Push: Make a choice.
- Recursive call: Explore.
- Pop: Undo the choice.

After a recursive call returns, execution resumes at the line immediately after that call.

### C. Return vs Continue vs Break

| Keyword | Meaning |
|---|---|
| return | Exit current function call |
| continue | Skip current loop iteration |
| break | Exit the loop |

### D. The Start Variable

Used in combination-based problems.

- Controls where the next recursive call starts.
- `i + 1` → Move to the next index; don't reuse the current index.
- `i` → Allow reuse of the current index.

### E. Handling Duplicates

When unique combinations are required:

1. Sort the input.
2. Skip duplicate choices at the same recursion level.

```cpp
if(i > start && nums[i] == nums[i-1])
    continue;
```

**Important:**
- Same recursion level → Skip duplicate choice.
- Different recursion level → Allow duplicate value if the problem permits it.

### F. Permutations — Used Array

Permutations are different from combinations because order matters.

We fill positions using any element that hasn't already been selected.

```cpp
vector<bool> used(nums.size(), false);
```

Inside the loop:

```cpp
if(used[i]) continue;

used[i] = true;
path.push_back(nums[i]);

backtrack(...);

path.pop_back();
used[i] = false;
```

- `false` → Available.
- `true` → Currently selected.
- `path.pop_back()` → Remove the element from the path.
- `used[i] = false` → Make it available again.

Base condition:

```cpp
if(path.size() == nums.size()) {
    result.push_back(path);
    return;
}
```

## 4. Combination vs Permutation

| Concept | Combination | Permutation |
|---|---|---|
| Does order matter? | No | Yes |
| Typical loop | Starts from `start` | Starts from 0 |
| Tracking | `start` | `used` array |
| Reusing index | Depends on problem | No, for standard permutations |
| Base condition | Depends on problem | Path size equals input size |

## 5. The Five Questions to Ask Before Coding

1. What am I trying to construct?
2. What is my base condition?
3. What choices can I make at each step?
4. Do I need `start`, `remaining`, or `used`?
5. When and how do I undo my choice?

**Remember: Backtracking = Choose → Explore → Undo.**
