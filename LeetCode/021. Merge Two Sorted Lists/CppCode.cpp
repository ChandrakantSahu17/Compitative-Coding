/*
Ques :- https://leetcode.com/problems/merge-two-sorted-lists/
Merge two sorted linked lists and return it as a sorted list.
The list should be made by splicing together the nodes of the first two lists.

*/


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *l3,*l3_copy;
        
        if(l1->val <= l2->val){
            l3 = new ListNode(l1->val);
            l1 = l1->next;
        }  
        else{
            l3 = new ListNode(l2->val);
            l2 = l2->next;
        }
        l3_copy = l3;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                l3->next = new ListNode(l1->val);
                l1 = l1->next;
            }  
            else{
                l3->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        
        while(l1){
            l3->next = new ListNode(l1->val);
            l1 = l1->next;
            l3 = l3->next;
        }
        
        while(l2){
            l3->next = new ListNode(l2->val);
            l2 = l2->next;
            l3 = l3->next;
        }
        
        return l3_copy;
    }
        
};