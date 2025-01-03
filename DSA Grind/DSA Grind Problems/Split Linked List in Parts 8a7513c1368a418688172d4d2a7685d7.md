# Split Linked List in Parts

Tags: Linked List
Date: September 6, 2023
Level: Medium
Number: 32
Platform: Leetcode
URL: https://leetcode.com/problems/split-linked-list-in-parts/

Given the `head` of a singly linked list and an integer `k`, split the linked list into `k` consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return *an array of the* `k` *parts*.

**Example 1:**

![Split%20Linked%20List%20in%20Parts%208a7513c1368a418688172d4d2a7685d7/split1-lc.jpg](Split%20Linked%20List%20in%20Parts%208a7513c1368a418688172d4d2a7685d7/split1-lc.jpg)

```
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

```

**Example 2:**

![Split%20Linked%20List%20in%20Parts%208a7513c1368a418688172d4d2a7685d7/split2-lc.jpg](Split%20Linked%20List%20in%20Parts%208a7513c1368a418688172d4d2a7685d7/split2-lc.jpg)

```
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

```

**Constraints:**

- The number of nodes in the list is in the range `[0, 1000]`.
- `0 <= Node.val <= 1000`
- `1 <= k <= 50`

## Solution

The key insight here is that we can efficiently split the linked list into **equal-sized parts** by calculating the **minimum guaranteed size** of each part (n) and distributing any extra nodes (r) as evenly as possible among the first r parts. **This approach ensures that we meet both conditions specified in the problem statement**.

**By maintaining two pointers (node and prev)** and 
updating them as we traverse the linked list, we can keep track of the 
current part and efficiently split the list into k parts.

**To solve this problem efficiently, we can follow these steps:**

- **Calculate the Length:** First, we need to **determine the length of the linked list**. This is **important because it helps** us evenly distribute the nodes among the k parts.

```cpp
for (ListNode* node = root; node; node = node->next)
            len++;
```

- **Calculate Sizes:** Calculate the minimum guaranteed size of each part, n, **by dividing the total length by k**. **Also, calculate the number of extra nodes, r**, which will be spread among the first r parts (remainder of length / k).

```cpp
 // Calculate the minimum guaranteed part size (n) and the number of extra nodes (r).
        int n = len / k, r = len % k;
```

- **Traverse and Split:** Initialize **two pointers**, node and prev, **to traverse the linked list.** Then, loop through each part:
    - **Store the current node** as the start of the current part in the parts array.
    - **Traverse n + 1 nodes** if there are remaining extra nodes (when r > 0). Otherwise, traverse only n nodes.
    - After traversing, **we disconnect the current part from the rest of the list by setting prev->next to nullptr**. This ensures that each part is isolated.

```cpp
// Loop through each part.
        for (int i = 0; node && i < k; i++, r--) {
            // Store the current node as the start of the current part.
            parts[i] = node;
            // Traverse n + 1 nodes if there are remaining extra nodes (r > 0).
            // Otherwise, traverse only n nodes.
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            // Disconnect the current part from the rest of the list by setting prev->next to nullptr.
            prev->next = nullptr;
        }
```

- **Return Result:** Return the parts array containing the k parts of the linked list.