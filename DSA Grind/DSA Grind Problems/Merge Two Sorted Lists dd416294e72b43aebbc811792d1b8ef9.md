# Merge Two Sorted Lists

Tags: Linked List, Recursion
Date: August 30, 2023
Level: Easy
Number: 26
Platform: Leetcode
URL: https://leetcode.com/problems/merge-two-sorted-lists/description/

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val <= list2->val) list1->next = mergeTwoLists(list1->next, list2);
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            list1 = list2;
        }
        return list1;
    }
};
```

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list2->val < list1->val) {
            swap(list1, list2);
        }
        ListNode* res = list1;
        while(list1 && list2) {
            ListNode* temp = nullptr;;
            while(list1 && list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};
```