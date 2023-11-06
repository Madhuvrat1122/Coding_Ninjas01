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
Node* takeInput(){
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
Node* insertAtIthIndex(Node *head, int i, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 0;
    // Handle Insetion at start
    if(i==0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    //Check the out of index
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;   
    }
    
    return head;
}
int main() {
    int data, index;
    Node* head = takeInput();
    
    cout<<"Before INsert at ith index:- "<<endl;
    print(head);
    
    cout<<"Enter data and index:- "<<endl;
    cin>>data>>index;
    head = insertAtIthIndex(head, index, data);
    
    cout<<"After INsert at ith index:- "<<endl;
    print(head);
    return 0;
}