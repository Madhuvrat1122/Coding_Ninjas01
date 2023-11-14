Node *deleteNodeRec(Node *head, int pos) {
	if(head == NULL){
		return head;
	}

	if(pos == 0){
		head = head->next;
		return head;
	}

	Node* tempHead = deleteNodeRec(head->next, pos-1);
	head->next = tempHead;
	return head;
}