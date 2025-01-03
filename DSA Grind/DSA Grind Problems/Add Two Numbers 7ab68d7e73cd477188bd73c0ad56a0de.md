# Add Two Numbers

Tags: Linked List, Recursion
Date: September 16, 2023
Level: Medium
Number: 36
Platform: Leetcode
URL: https://leetcode.com/problems/add-two-numbers/description/

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

![Add%20Two%20Numbers%207ab68d7e73cd477188bd73c0ad56a0de/addtwonumber1.jpg](Add%20Two%20Numbers%207ab68d7e73cd477188bd73c0ad56a0de/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]

```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution

```cpp
// Striver's Solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int n_carry = 0) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};
```

```cpp
// my solution, recursive
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int n_carry = 0) {
        if(l1 == nullptr && l2 == nullptr) {
            if(n_carry) return new ListNode(n_carry);
            return nullptr;
        }
        int sum = 0, carry = 0;
        ListNode* sumHead = new ListNode();
        if(l1 == nullptr) {
            sum += l2->val + n_carry;
            sumHead->next = addTwoNumbers(l1, l2->next, sum / 10);
        } else if(l2 == nullptr) {
            sum += l1->val + n_carry;
            sumHead->next = addTwoNumbers(l1->next,l2, sum / 10);
        } else {
            sum += l1->val + l2->val + n_carry;
            sumHead->next = addTwoNumbers(l1->next, l2->next, sum / 10);
        }
        sumHead->val = sum % 10;
        return sumHead;
    }
};
```