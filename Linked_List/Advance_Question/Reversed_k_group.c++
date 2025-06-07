#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list in C++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    ListNode* reverseList(ListNode* head, int k, ListNode** nextGroupHead) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr && count < k) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        *nextGroupHead = curr;
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int count = 0;
        ListNode* ptr = head;
        while (ptr) {
            count++;
            ptr = ptr->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;
        while (count >= k) {
            ListNode* nextGroupHead = nullptr;
            ListNode* newGroupHead = reverseList(curr, k, &nextGroupHead);
            prevGroupEnd->next = newGroupHead;
            curr->next = nextGroupHead;
            prevGroupEnd = curr;
            curr = nextGroupHead;
            count -= k;
        }
        return dummy.next;
    }
};