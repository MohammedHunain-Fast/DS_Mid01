#include <iostream>

using namespace std;

class Node {                    //Node Class
    public:
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void insertAtTail(Node* &head, int data) {      //Inserting element at the end
    Node* newNode = new Node(data);
    if(head == nullptr) {
        head = newNode;
        return;
    } 
    Node* temp = head;
    while(temp -> next != nullptr) {
        temp = temp -> next;
    }
    temp -> next = newNode; 
}


void traverseLL(Node* head) {               //displaying all elements through the loop
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


void countNodes(Node* head) {
    int counter = 0;
    while(head != nullptr) {
        counter++;
        head = head -> next;
    }
    cout << "Number of Nodes: " << counter << endl;

}
void addElements(Node *head) {
    int sum = 0;
    while(head != nullptr) {
        sum += head -> data;
        head = head -> next;
    }
    cout << "Sum: " << sum << endl;

}

Node* linearSearch(Node* head, int key) {
    while(head != nullptr) {
        if(head -> data == key) return head;
        head = head -> next;
    }
    return nullptr;
}

Node* moveToHead(Node* &head, int key) {
    Node* tail = nullptr;
    Node* temp = head;
    if(head == nullptr || head -> data == key) return head;
    while(temp != nullptr) {
        if(temp -> data == key) {
            tail -> next = temp -> next;
            temp -> next = head;
            head = temp; 
            return head;
        }
        tail = temp;
        temp = temp -> next;
    }
    return nullptr;
}

void insert(Node* &head, int data, int pos) {
    if(pos < 0) return;
    if(pos == 0) {
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    if(pos > 0) {
        for(int i = 0; i < pos - 1 && temp; i++) {
            temp = temp -> next;
        }
        if(temp != nullptr) {
            Node* newNode = new Node(data);
            newNode -> next = temp -> next;
            temp -> next = newNode; 
        }
    }
}

void deleteNode(Node* &head, int pos) {
    if(head == nullptr || pos < 0) return;
    if(pos == 0) {
        Node* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp; 
        return;
    }
    Node* temp = head;
    if(pos > 0) {
        for(int i = 0; i < pos - 1 && temp; i++) {
            temp = temp -> next;
        }
        if(temp != nullptr && temp -> next != nullptr) {
        Node *del = temp -> next;
        temp -> next = temp -> next -> next;
        del -> next = nullptr;
        delete del;
        }
    }
}


//Recursive Methods

void traveseRecursively(Node* head) {     //displaying all elements recursively
    if(head == nullptr) return;
    cout << head -> data << " ";
    traveseRecursively(head -> next);
}

void reverseRecursively(Node* head) {       //reversing all elements recursively
    if(head == nullptr) return;
    reverseRecursively(head -> next);
    cout << head -> data << " ";
}

int addRecursively(Node* head) {
    if(head == nullptr) return 0;
    else{ 
        return addRecursively(head -> next) + head -> data;
    };
}

//

int main() {
    Node *head = nullptr;
    
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    // traverseLL(head);
    // traveseRecursively(head);
    // reverseRecursively(head);
    // countNodes(head);
    // addElements(head);
    // cout << "sum: " << addRecursively(head) << endl;
    
    // Node* found = linearSearch(head, 40);
    // cout << "Adress: " << found << " " << "Value:" << found -> data << endl;
    // Node* found = moveToHead(head, 30);
    // cout << "Adress: " << found << " " << "Value:" << found -> data << endl;
    // traverseLL(head);


    // insert(head, 80, 0);
    // insert(head, 25, 3);
    // traverseLL(head);

    traverseLL(head);
    deleteNode(head, 2);
    cout << "\n";
    traverseLL(head);


    return 0;
}