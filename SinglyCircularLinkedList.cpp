#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int data, Node* next = nullptr) : data(data), next(next) {}

};

void insert(Node* &head, int data, int pos) {
    if(pos < 0) {
        cout << "Invalid\n";
        return;
    }
    Node* newNode = new Node(data);
    if(head == nullptr) {
        if(pos == 0) {
            head = newNode;
            newNode -> next = head;
            return;
        }
        else {
            cout << "Invalid Position for empty list!\n";
            delete newNode;
            return;
        }
    }
    if(pos == 0) {
        Node* temp = head;
        while(temp -> next != head) {
            temp = temp -> next;
        }
        newNode -> next = head;
        head = newNode;
        temp -> next = head;
        return;
    }
    
    Node* temp = head;

    for(int i = 0; i < pos - 1; i++) {
        temp = temp -> next;
        if(temp == head){
            cout << "invalid Position\n"; 
            delete newNode;
            return;
        }
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;


}

void traverse(Node* head) {
    Node* temp = head;
    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != head);
    cout << "\n";
}

void deleteNode(Node* &head, int pos) {
    if(pos < 0) {
        cout << "invalid Position!\n";
        return;
    }
    if(pos == 0) {
        if(head == nullptr) {
            return;
        }
        Node* temp1 = head;
        if(head -> next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp2 = head;
        while(temp2 -> next != head){
            temp2 = temp2 -> next;
        }
        head = head -> next;
        temp2 -> next = head;
        temp1 -> next = nullptr;
        delete temp1;
        return;
    }
    Node* temp = head;
    for(int i = 0; i < pos - 1; i++) {
        temp = temp -> next;
        if(temp -> next == head) {
            cout << "Invalid Position\n";
            return;
        }
    }
    Node* del = temp -> next;
    temp -> next = temp -> next -> next;
    del -> next = nullptr;
    delete del;
}



int main() {
    Node* head = nullptr;
    insert(head, 10, 0);
    insert(head, 20, 1);
    insert(head, 30, 2);
    insert(head, 40, 3);

    insert(head, 25, 2);

    traverse(head);

    deleteNode(head, 4);

    traverse(head);


    return 0;
}