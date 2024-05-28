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

Node *reverseLinkedList(Node *head) {
	if(head == NULL || head->next == NULL){
		return head;
	}
    Node* prev = NULL, *c = head, *n = head->next;
	while(n != NULL) {
		c->next = prev;
		prev = c;
		c = n;
		n = n->next;
	}
	c->next = prev;
	prev = c;
	return prev;
}