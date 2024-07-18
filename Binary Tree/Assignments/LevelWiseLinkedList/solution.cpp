int findHeight(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	return 1+max(findHeight(root->left),findHeight(root->right));
}
Node<int>* constructLinkedListFoLevelWise(BinaryTreeNode<int>* root, int level){
	if(root == NULL || level < 1){
		return NULL;
	}
	Node<int>* head = NULL;
	if(level == 1){
		head = new Node(root->data);
	}
	else if(level > 1){
		if(root->left){
			if(head == NULL){
				head = constructLinkedListFoLevelWise(root->left, level-1);
			}
			else {
				Node<int>* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = constructLinkedListFoLevelWise(root->left, level-1);
			}
		}
		
		if(root->right){
			if(head == NULL){
				head = constructLinkedListFoLevelWise(root->right, level-1);
			}
			else {
				Node<int>* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = constructLinkedListFoLevelWise(root->right, level-1);
			}
		}
	}

	return head;
}
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	vector<Node<int>*> result;
	int h = findHeight(root);
	for(int i=1; i<=h;i++){
		Node<int>* head = constructLinkedListFoLevelWise(root, i); 
		result.push_back(head);
	}

	return result;
}
