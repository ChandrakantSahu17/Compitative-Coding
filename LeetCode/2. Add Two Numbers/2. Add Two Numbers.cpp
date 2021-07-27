/* Ques : 
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     carry += l1->val+l2->val;
                            l1->val = carry%10;
                            carry /= 10; : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Method 1

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* l1_copy = l1;
        if(l1){
            if(l2){
                while(l1->next && l2->next){
                    carry += l1->val+l2->val;
                    l1->val = carry%10;
                    carry /= 10;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                if(l2->next){
                    l1->next = l2->next;
                }
                carry += l1->val+l2->val;
                l1->val = carry%10;
                carry /= 10;
                goto Lable;
            }
            else return l1;  
        }
        else return l2;
Lable : if(l1->next){
            l1=l1->next;
            while(l1->next){
                carry += l1->val;
                l1->val = carry%10;
                carry /= 10;
                l1=l1->next;
            }
            carry += l1->val;
            l1->val = carry%10;
            carry /= 10;
        }                   
        if(carry){
            l1->next = new ListNode(carry);
        }
        return l1_copy;  
    }
};

/*
Runtime: 36 ms, faster than 39.81% of C++ online submissions for Add Two Numbers.
Memory Usage: 70.8 MB, less than "99.58%" of C++ online submissions for Add Two Numbers.

But this is not a good way to code because at some point if we need to access the original 
link list we will be accessing the modified one.
*/