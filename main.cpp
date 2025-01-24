#include <iostream>

struct ListNode { // ListNode definition
    int data;
    ListNode *link;
};

//All linked list functions
void Print(ListNode *head);
void DeleteAtPos(ListNode **headPtr, int pos);
void Insert(ListNode **headPtr, int data);
void InsertAtNpos(ListNode **headPtr, int data, int pos);
int GetMiddle(ListNode *head);
void Reverse(ListNode **headPtr);

int main() {

    ListNode *head = nullptr;
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head,3);
    Insert(&head,6);
    Insert(&head,2);
    Insert(&head,1);
    Print(head);
    Reverse(&head);
    Print(head);
    return 0;
}

//Function that inserts a new node to the beginning of the list
void Insert(ListNode **headPtr, const int data) {
    auto *temp = new ListNode();
    temp->data = data;
    if(*headPtr!=nullptr) {
        temp->link = *headPtr;
    }
    *headPtr = temp;
}

//Function that adds a new node to the n-th position
void InsertAtNpos(ListNode** headPtr, int data, int pos) {
    auto *node = new ListNode();
    node->data = data;
    node->link = nullptr;
    if (pos==1) {
        node->link = *headPtr;
        *headPtr = node;
        return;
    }
    ListNode *cur = *headPtr;
    for(int j=0; j<pos-2; j++) {
        cur = cur->link;
    }
    node->link = cur->link;
    cur->link = node;
}

//Function that deletes the node at the n-th position
void DeleteAtPos(ListNode **headPtr, int pos) {
    ListNode *current = *headPtr;
    ListNode *previous = *headPtr;
    if(*headPtr == nullptr) {
        return;
    }else if (pos == 1) {
        *headPtr = current->link;
        delete(current);
        current = nullptr;
    }else {
        while(pos !=1) {
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        delete(current);
        current = nullptr;
    }
}

//Function to print list
void Print(ListNode* head) {
    ListNode *temp = head;
    std::cout<<"The list is:"<<std::endl;
    while(temp!=nullptr) {
        std::cout<<temp->data<<" ";
        temp=temp->link;
    }
    std::cout<<std::endl;
}

//Function to get the middle node's value ( can change to mem. address )
int GetMiddle(ListNode *head) {
    if (head == nullptr) {
        std::cout<<"The list is empty"<<std::endl;
        return -1;
    }
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->link != nullptr) {
        slow = slow->link;
        fast = fast->link->link;
    }
    return slow->data;
}

//Function to reverse the linked list
void Reverse(ListNode **headPtr) {
    ListNode *next;
    ListNode *current = *headPtr;
    ListNode *prev = nullptr;
    while(current != nullptr) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *headPtr = prev;
}