# Remove Nth node from back

Tags: Linked List, Two Pointers
Date: September 3, 2023
Level: Medium
Number: 29

- To solve this problem in one-pass & O(n) space, we need to find a way to both reach the end of the linked list & reach the nth node from the end simultaneoulsy.
- To do that, we initialize 2 pointers `fast` & `slow` both pointing to the head of the linked lits, the stagger the both by `n` nodes, so that `fast` is `n` nodes ahead of `slow`.
- Doing this will cause `slow` to reach the `n`'th node from the end at the same time that `fast` reaches the end.
- Since we will need access to the node before the target node in order to remove the target node, we are going to loop until `fast->next != NULL` rather than until `fast != null`, so that we stop one node earlier.
- This method will be a problem when `n` is same as the no. of nodes in the linked list, which would make the first node the target node, and hence it's not possible to find the node before the target node. If that's the case, we can just return `head->next`

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(fast == nullptr) return head->next;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
```