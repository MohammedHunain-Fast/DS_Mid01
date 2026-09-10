#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void display(Node* head) {
    if(head == nullptr) {
        cout << "The list is empty!\n";
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

void clearList(Node* &head) {
    if(head == nullptr) return;
    Node* temp = head;
    while(temp != nullptr) {
        Node* del = temp;
        temp = temp -> next;
        delete del;
    }
    head = nullptr;
}
void insert(Node* &head,int pos) {
    int data = 0;
    cout << "Enter data: ";
    cin >> data;
    Node* newNode = new Node(data);
    if(pos == 0) {
        if(head == nullptr) {
            head = newNode;
        }
        else {
        newNode -> next = head;
        head = newNode;
        } 
    }
    if(pos > 0) {
        Node* temp = head;
        for(int i = 0; i < pos - 1 && temp; i++) {
            temp = temp -> next;
        }
        if(temp != nullptr) {
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
    }
}

void create(Node* &head, int len) {
    int data = 0;
    if(head == nullptr) {
        cout << "Enter data: ";
        cin >> data;
        Node* newNode = new Node(data);
        head = newNode;
    }
    Node* temp = head;
    for(int i = 1; i < len; i++) {
        cout << "Enter data: ";
        cin >> data;
        Node* newNode = new Node(data);
        temp -> next = newNode;
        temp = temp -> next;
    }
}
int countNodes(Node* head) {
    int count = 0;
    if(head == nullptr) {
        cout << "The list is empty!\n";
        return 0;
    }
    Node* temp = head;
    while(temp != nullptr) {
        count ++;
        temp = temp -> next;
    }
    return count;
}

void palindromeChecker(Node* head) {
    int len = countNodes(head);
    int *arr = new int[len];
    Node* temp = head;
    for(int i = 0; i < len; i++) {
        arr[i] = temp -> data;
        temp = temp -> next;
    }

    int i = 0;
    int j = len - 1;
    while(i < j) {
        if(arr[i] != arr[j]) {
            cout << "Linked List is not a Palindrome\n";
            delete[] arr;
            return;
        }
        i++;
        j--;
    }
    cout << "Linked List is a Palindrome\n";
    delete[] arr;
}

int main() {\
    Node* head = nullptr;
    create(head, 5);
    display(head);
    palindromeChecker(head);
    clearList(head);

    return 0;
}