#include <iostream>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* takeInput_Better(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            // OR tail = tail->next;
        }
        cin>>data;
    }
    return head;
}
Node *deleteNode(Node *head, int pos)
{
   int count = 0;
    Node* temp = head;
    if(head == NULL){
        return head;
    }
    else if(pos == 0){
       return head->next;
    }
    else{
        while(temp != NULL && count < pos-1) {
            temp = temp->next;
            count++;
        }

        if(temp == NULL || temp->next == NULL){
            return head;
        }
        // Delete Operation
        Node* a = temp->next;
        temp->next = a->next;
        delete a;   
    }
    
    return head;
}
int main() {
    Node* head = takeInput_Better();
    print(head);
    cout<<"After Delete:- "<<endl;
    head = deleteNode(head, 0);
    print(head);
    return 0;
}