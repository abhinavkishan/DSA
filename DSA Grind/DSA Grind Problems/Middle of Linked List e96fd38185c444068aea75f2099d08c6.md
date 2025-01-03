# Middle of Linked List

Tags: Linked List
Date: September 3, 2023
Level: Easy
Number: 28
Platform: Leetcode

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```