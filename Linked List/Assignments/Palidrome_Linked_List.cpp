// Palindrome Linked List
bool compareLL(Node *firsthalf, Node *secondhalf){
	Node *temp1 = firsthalf, *temp2 = secondhalf;
	while(temp1 && temp2){
		if(temp1->data != temp2->data){
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if(temp1 != NULL || temp2 != NULL){
		return false;
	}
	return true;
}
Node* revserseLL(Node* head){
	Node *prev = NULL, *curr = head, *second = head->next;
	while(second != NULL){
		curr->next = prev;
		prev = curr;
		curr = second;
		second = second->next;
	}
	curr->next = prev;
	prev = curr;
	return prev;
}
bool isPalindrome(Node *head)
{
	if( head == NULL || head->next == NULL){
		return true;
	}
	Node *slow = head, *fast = head, *prev_of_slow = NULL;
	Node *first_half, *second_half;
	// calculate the mid node of linked list
	while(fast != NULL && fast->next != NULL){
		prev_of_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	// find out the first half and second half of linked list
	first_half = head;
	// if even no of node
	if(fast == NULL){
		prev_of_slow->next = NULL;
		second_half = slow;
	}
	// odd no of node
	else {
		prev_of_slow->next = NULL;
		second_half = slow->next;
	}

	// reverse the second half of linked list
	second_half = revserseLL(second_half);
	
	// compare the both the side of linked list
	return compareLL(first_half, second_half);
}