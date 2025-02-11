| S.no | problem | notes | implementation |
|:-----|:-------|:-------|:---------|
| 1 | [Majority element](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1) | Moore's voting algorithm (or) Majority voting algorithm | [My code](moores_voting_algo.cpp) | 
| 2 | Reversal algorithm | In-place linear time algo: [GFG](https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/) | [My code](reverse_by_d_positions.cpp) |
| 3 | Pair sum | 	ϴ(nlogn) time if not sorted, ϴ(n) time if sorted and ϴ(1) space |
| 4 | [triplet sum](https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1) | O(nlogn + n^2) time, O(1) space.  | [triplet_sum.cpp](triplet_sum.cpp) |
| 5 | [quadraple sum](https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1) | Find all unique quadraples which sum to k. | |
| 6 | [Given an array arr[], find the maximum j – i such that arr[i] <= arr[j]](https://www.geeksforgeeks.org/problems/maximum-index3307/1) | [approach1](maximum_index1.cpp), O(nlogn) time, O(1) space <br/> [approach2](maximum_index2.cpp), O(n) time, 2*n space <br/> [approach3](maximum_index3.cpp), O(n) time, n space <br/> [approach4](maximum_index4.cpp), O(n) time, n space <br/> All the above approaches are inspired from [this article](https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/)| 
| 7 | [Minimize the maximum difference between the heights](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1) | Time: O(nlogn) <br/> Space: O(1) |
| 8 | [Find the closest pair from two arrays](https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1) | Time: O(n + m), Space: O(1) | [find_the_closest_pair_from_two_arrays.cpp](find_the_closest_pair_from_two_arrays.cpp) |
| 9 | [Trapping rain water problem](https://leetcode.com/problems/trapping-rain-water/) | Time: O(n), Space: O(1) for most optimized version | [trapping_rain_water_solution_1.cpp](trapping_rain_water_solution_1.cpp), [trapping_rain_water_solution_2.cpp](trapping_rain_water_solution_2.cpp) |
| 10 | [Next permutation](https://leetcode.com/problems/next-permutation/description/) | O(n + logn) time, O(1) space | [next_permutation.cpp](next_permutation.cpp)|
| 11 | [Number of greater elements to the right](https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1) | [next_greater_using_merge_sort.cpp](next_greater_using_merge_sort.cpp) which has time complexity O(n * logn) |


## Efficent ways to find all permuataions
To generate all permutations of an array efficiently, you can use **backtracking**, **lexicographic ordering**, or **Heap’s algorithm**. The most efficient way depends on whether you want **all permutations at once** or **generate them one by one**.

---

### 1. **Backtracking Approach (DFS) – O(N!)**
This is a standard approach that generates permutations recursively by swapping elements.

#### **C++ Code (Backtracking)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}

vector<vector<int>> getPermutations(vector<int>& nums) {
    vector<vector<int>> result;
    permute(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = getPermutations(nums);

    for (auto& p : permutations) {
        for (int num : p) cout << num << " ";
        cout << "\n";
    }
    return 0;
}
```
**Complexity:** O(N!) (Factorial growth)

---

### 2. **Lexicographic Order (std::next_permutation) – O(N!)**
This approach generates permutations **in sorted order** using the **C++ STL** function.

#### **C++ Code (next_permutation)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    do {
        for (int num : nums) cout << num << " ";
        cout << "\n";
    } while (next_permutation(nums.begin(), nums.end()));
}
```
**Why use this?**  
- Generates permutations in **sorted order**.
- **Efficient in memory** (modifies in place).
- **Best for generating permutations one by one**.

**Complexity:** O(N!) but optimized for in-place generation.

---

### 3. **Heap’s Algorithm – O(N!) (Faster than naive recursion)**
A classic algorithm that generates permutations efficiently by **minimizing swaps**.

#### **C++ Code (Heap's Algorithm)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void heapPermute(vector<int>& nums, int n) {
    if (n == 1) {
        for (int num : nums) cout << num << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        heapPermute(nums, n - 1);
        swap(nums[n % 2 == 0 ? i : 0], nums[n - 1]); // even-index swap
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    heapPermute(nums, nums.size());
}
```
**Why use Heap’s Algorithm?**  
- **Fewer swaps** than backtracking.
- **Best for iterative implementations**.

---

### **Which one should you use?**
| Approach | Best for | Complexity |
|----------|----------|-------------|
| Backtracking | Small arrays (N ≤ 10) | O(N!) |
| `next_permutation` | Generating permutations one by one in sorted order | O(N!) |
| Heap’s Algorithm | Efficient swapping, useful for iterative implementations | O(N!) |

For **large arrays**, it's better to **avoid generating all permutations** and use **lexicographic order** for **on-the-fly generation**.