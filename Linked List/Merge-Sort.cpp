/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
// Find Mid of a linked list
void *findMidNode(Node *headRef, Node **startNode, Node **endNode) {
	Node *slow = headRef, *fast = headRef;
	while(fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	*startNode = headRef;
	*endNode = slow->next;
	slow->next = NULL;
}

Node *mergeTwoList(Node *list1, Node *list2){
    Node *fhead = NULL;
	Node *ftail = NULL;
    if(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data) {
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
		if(list1->data < list2->data) {
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


Node *mergeSort(Node *head)
{
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node *startNode = NULL, *endNode = NULL, *headRef = head;;
	findMidNode(headRef, &startNode, &endNode);
	Node *list1 = mergeSort(startNode);
	Node *list2 = mergeSort(endNode);
	headRef = mergeTwoList(list1, list2);

	return headRef;
}
