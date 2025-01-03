# Reverse Linked List

Tags: Linked List
Date: August 23, 2023
Level: Easy
Number: 24
Platform: Leetcode

![https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif)

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prevNode = nullptr) {
        ListNode *curNode, *nextNode, *prevNode = nullptr;
        curNode = head;
        while(curNode) {
             nextNode = curNode->next;
             curNode->next = prevNode;
             prevNode = curNode;
             curNode = nextNode;
         }
				 return prevNode;
        // return head ? reverseList(head->next, (head->next = prevNode, head)) : prevNode;
    }
};
```

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* newHead = head;
        if(head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;
        return newHead;
    }
};
```