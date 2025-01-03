# Palindrome Linked List

Tags: Linked List, Stack, Two Pointers
Date: September 18, 2023
Level: Easy
Number: 35
Platform: Leetcode
URL: https://leetcode.com/problems/palindrome-linked-list/description/

Given the `head` of a singly linked list, return `true` *if it is a*

*palindrome*

*or* `false` *otherwise*.

**Example 1:**

![Palindrome%20Linked%20List%2097d246b0a7d04263ab9e2a72365d1fe1/pal1linked-list.jpg](Palindrome%20Linked%20List%2097d246b0a7d04263ab9e2a72365d1fe1/pal1linked-list.jpg)

```
Input: head = [1,2,2,1]
Output: true

```

**Example 2:**

```
Input: head = [1,2]
Output: false

```

**Constraints:**

- The number of nodes in the list is in the range `[1, 105]`.
- `0 <= Node.val <= 9`

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

Accepted

1.6M

Submissions

3.1M

Discussion (114)

Similar Questions

[Palindrome Number](https://leetcode.com/problems/palindrome-number/)

[Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)

Related Topics

[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution

- Find the middle element of the linked list. Refer to this article to know the steps [https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/](https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/)
- Reverse a linked list from the next element of the middle element. Refer to this article to know the steps [https://takeuforward.org/data-structure/reverse-a-linked-list/](https://takeuforward.org/data-structure/reverse-a-linked-list/)
- Iterate through the new list until the middle element reaches the end of the list.
- Use a dummy node to check if the same element exists in the linked list from the middle element.

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) {
            slow = slow->next;
        }
        
        ListNode *prev = nullptr;
        while(slow) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        slow = prev;
        while(slow && head->val == slow->val) {
            slow = slow->next;
            head = head->next;
        }
        
        return slow ? false : true;
    }
};
```