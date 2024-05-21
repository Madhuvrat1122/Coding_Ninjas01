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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *fhead = NULL;
	ListNode *ftail = NULL;
    if(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val) {
            fhead = list1;
            ftail = list1;
            list1 = list1->next;
        }
        else {
            fhead = list2;
            ftail = list2;
            list2 = list2->next;
        }
    }
    else if(list1 != NULL) {
        return list1;
    } else {
        return list2;
    }

	while(list1 != NULL && list2 != NULL) {
		if(list1->val < list2->val) {
			ftail->next = list1;
			ftail = list1;
			list1 = list1->next;
		}
		else {
			ftail->next = list2;
			ftail = list2;
			list2 = list2->next;
		}
	}
	
	// Remaining elements
	if(list1 != NULL){
		ftail->next = list1;
	}
	else if(list2 != NULL) {
		ftail->next = list2;
	}

	return fhead;   
    }
};
