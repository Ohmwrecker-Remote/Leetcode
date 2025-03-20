/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

 int lenthOf(struct ListNode* l);


 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
     int length1 = lenthOf(l1);
     int length2 = lenthOf(l2);
     struct ListNode* pointerl1 = l1;
     struct ListNode* pointerl2 = l2;
     int carry = 0;
     if (length1 <= length2) {
         for (int i = 0; i < length1; i++)
         {
             if (pointerl1->val + pointerl2->val + carry > 9) {
                 pointerl2->val = pointerl1->val + pointerl2->val + carry - 10;
                 carry = 1;
             }
             else {
                 pointerl2->val = pointerl1->val + pointerl2->val + carry;
                 carry = 0;
             }
             if (pointerl1->next != NULL) {
                 pointerl1 = pointerl1->next;
             }
             if (pointerl2->next != NULL) {
                 pointerl2 = pointerl2->next;
             }
         }
         if (length2 == length1 && carry == 1) {
             pointerl2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
             if (pointerl2->next != NULL) {
                 pointerl2->next->val = 1;
                 pointerl2->next->next = NULL;
                 carry = 0;
                 return l2;
             }
         }
         //如果最后还有进位，继续检测
         while (carry == 1 && pointerl2 != NULL)
         {
             if (pointerl2->val + carry <= 9) {
                 pointerl2->val = pointerl2->val + carry;
                 carry = 0;
             }
             // 有进位但是下一个节点不为空
             else if (pointerl2->val == 9 && pointerl2->next != NULL) {
                 pointerl2->val = 0;
                 carry = 1;
                 pointerl2 = pointerl2->next;
             }
             // 有进位但是下一个节点为空
             else if (pointerl2->val == 9 && pointerl2->next == NULL) {
                 pointerl2->val = 0;
                 carry = 0;
                 pointerl2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                 if (pointerl2->next != NULL) {
                     pointerl2->next->val = 1;
                     pointerl2->next->next = NULL;
                 }
             }
         }
         return l2;
     }
     else {
         for (int i = 0; i < length2; i++)
         {
             if (pointerl1->val + pointerl2->val + carry > 9) {
                 pointerl1->val = pointerl1->val + pointerl2->val + carry - 10;
                 carry = 1;
             }
             else {
                 pointerl1->val = pointerl1->val + pointerl2->val + carry;
                 carry = 0;
             }
             if (pointerl1->next != NULL) {
                 pointerl1 = pointerl1->next;
             }
             if (pointerl2->next != NULL) {
                 pointerl2 = pointerl2->next;
             }
         }
         //如果最后还有进位，继续检测
         while (carry == 1 && pointerl1 != NULL)
         {
             if (pointerl1->val + carry <= 9) {
                 pointerl1->val = pointerl1->val + carry;
                 carry = 0;
             }
             // 有进位但是下一个节点不为空
             else if (pointerl1->val == 9 && pointerl1->next != NULL) {
                 pointerl1->val = 0;
                 carry = 1;
                 pointerl1 = pointerl1->next;
             }
             // 有进位但是下一个节点为空
             else if (pointerl1->val == 9 && pointerl1->next == NULL) {
                 pointerl1->val = 0;
                 carry = 0;
                 pointerl1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                 if (pointerl1->next != NULL) {
                     pointerl1->next->val = 1;
                     pointerl1->next->next = NULL;
                 }
             }
         }
         return l1;
     }
 }
 
 int lenthOf(struct ListNode* l) {
     int lenth = 1;
     struct ListNode* pointer = l;
     while (l->next != NULL) {
         lenth++;
         l = l->next;
     }
     return lenth;
 }
// @lc code=end

