# Reverse Linked List II

Tags: Linked List
Date: September 7, 2023
Level: Medium
Number: 33
Platform: Leetcode
URL: https://leetcode.com/problems/reverse-linked-list-ii/

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.

**Example 1:**

![Reverse%20Linked%20List%20II%209b491f991ee648409ff3645ebd30ff3a/rev2ex2.jpg](Reverse%20Linked%20List%20II%209b491f991ee648409ff3645ebd30ff3a/rev2ex2.jpg)

```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

```

**Example 2:**

```
Input: head = [5], left = 1, right = 1
Output: [5]

```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `500 <= Node.val <= 500`
- `1 <= left <= right <= n`

## Solution

### Intuition and Logic Behind the Solution

In this efficient method, we employ two pointers to traverse and 
manipulate the linked list in one go. The clever use of a dummy node 
helps us elegantly handle edge cases, and tuple unpacking makes the code
 more Pythonic and straightforward.

### Step-by-step Explanation

1. **Initialization**:
    - Create a `dummy` node and connect its `next` to the head of the list.
    - Initialize a `prev` pointer to the `dummy` node.
2. **Move to Start Position**:
    - Traverse the list until the node just before the `left`th node is reached.
3. **Execute Sublist Reversal**:
    - Use a `current` pointer to keep track of the first node in the sublist.
    - Reverse the sublist nodes using `prev` and `current`.
4. **Link Back**:
    - Automatically link the reversed sublist back into the original list.

### Complexity Analysis

- **Time Complexity**: `O(n)` — A single traversal does the job.
- **Space Complexity**: `O(1)` — Smart pointer manipulation eliminates the need for additional data structures.

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        // dummy incase rev from starting
        ListNode *dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for(int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* current = prev->next;
        ListNode* next_node;
        for(int i = left; i < right; i++) {
            next_node = current->next;
            current->next = next_node->next;
            // push back nextnode;
            next_node->next = prev->next;
            // Link back
            prev->next = next_node;
        }
        return dummy->next;
    }
};
```