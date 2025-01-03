# Reorder List

Tags: Linked List, Recursion, Two Pointers
Date: September 9, 2023
Level: Medium
Number: 34
Platform: Leetcode
URL: https://leetcode.com/problems/reorder-list/

You are given the head of a singly linked-list. The list can be represented as:

```
L0 → L1 → … → Ln - 1 → Ln
```

*Reorder the list to be on the following form:*

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**

![Reorder%20List%20b9464e5da06e4e9ea76a14a356e6d47e/reorder1linked-list.jpg](Reorder%20List%20b9464e5da06e4e9ea76a14a356e6d47e/reorder1linked-list.jpg)

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]

```

**Example 2:**

![Reorder%20List%20b9464e5da06e4e9ea76a14a356e6d47e/reorder2-linked-list.jpg](Reorder%20List%20b9464e5da06e4e9ea76a14a356e6d47e/reorder2-linked-list.jpg)

```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

```

**Constraints:**

- The number of nodes in the list is in the range `[1, 5 * 104]`.
- `1 <= Node.val <= 1000`

Accepted

736.1K

Submissions

1.4M

54.3%

Discussion (38)

Similar Questions

[Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

[Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/)

Related Topics

[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution

**Brute-Force Algorithm:-**

1. First some base cases that we need to take care i.e if the linked list has zero,one or two elements just return it
2. Now next we need to find the penultimate node, so after finding it we can start the relinking process
3. Now start the relinking process as 1st node with last node ,2nd node with penultimate node, 3rd node with 3rd last node ......
4. Now repeat 2nd and 3rd steps.

**Two pointer Approach Algorithm:**

1. First let's take two pointers name it as `half` and `temp` . `temp` is faster than `half` by 1.
2. When `temp` reaches the end of linkedlsit `half` reaches the middle element .So this is how the linkedlist will get divided in two halfes as the center will become a dividing node .
3. Now reverse the second half .
4. After reversing the second half, merge the first half and second half

**Let's have a dy run before starting the code:-**

Let's take the same example as above:

`Linked list:[1,2,3,4,5]
* search for the central element, which will be three in our case
* split the list in two halfes that will be [1,2,3] and [4,5]
* Now reverse the second half that will be [5,4]
* Now merge both the halfes 
[1,2,3]
	[5,4]
=>[1,5,2,4,3]`

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;

        // finding middle
        ListNode* temp = head, *half = head;
        while(temp && temp->next) {
            temp = temp->next->next;
            half = half->next;
        }

        // reversing the second half
        ListNode *prev = nullptr;
        while(half) {
            temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }

        half = prev;
        while(head && half) {
            temp = head->next;
            prev = half->next;
            head->next = half;
            half->next = temp;
            half = prev;
            head = temp;
        }

        // in even case we have to remove a self loop
        if(head) {
            head->next = nullptr;
        }
    }
};
```