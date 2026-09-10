#include <iostream>

using namespace std;

class Node {
    public:
        string data;
        Node* next;

        Node(string data, Node* next = nullptr) : data(data), next(next) {}
};

void create(Node* &head, int len) {
    string data = " ";
    if(head == nullptr) {
        cout << "Enter Name: ";
        cin >> data;
        Node* newNode = new Node(data);
        head = newNode;
        newNode -> next = head;
    }
    Node* temp = head;
    for(int i = 1; i < len; i++) {
        cout << "Enter Name: ";
        cin >> data;
        Node* newNode = new Node(data);
        temp -> next = newNode;
        newNode -> next = head;
        temp = temp -> next;
    }
}

void display(Node* head) {
    if(head == nullptr) {
        cout << "The list is empty!\n";
        return;
    }
    Node* temp = head;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    } while(temp != head);
    cout << "\n";
}
void insert(Node* &head,int pos) {
    string data = " ";
    cout << "Enter data: ";
    cin >> data;
    Node* newNode = new Node(data);
    if(pos == 0) {
        if(head == nullptr) {
            head = newNode;
            newNode -> next = head;
        }
        else {
            Node* temp = head;
            do {
                temp = temp -> next;
            } while(temp -> next != head);
            newNode -> next = head;
            head = newNode;
            temp -> next = head;
        } 
        return;
    }
    if(pos > 0) {
        if(head == nullptr) {
            cout << "The list is empty!\n";
            delete newNode;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1 ; i++) {
            temp = temp -> next;
            if(temp == head) {
                cout << "position out of bounds!\n";
                delete newNode;
                return;
            }
        }

        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}
int countNodes(Node* head) {
    int count = 0;
    if(head == nullptr) {
        cout << "The list is empty!\n";
        return 0;
    }
    Node* temp = head;
    do{
        count ++;
        temp = temp -> next;
    }while(temp != head);
    return count;
}


void removePlayers(Node* &head) {
    if (head == nullptr || head -> next == head) {
        cout << "Not enough players to eliminate!\n";
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    Node* tail = head;
    while (tail -> next != head) {
        tail = tail -> next;
    }
    prev = tail;

    while (current -> next != current) {
        for (int step = 0; step < 2; step++) {
            prev = current;
            current = current -> next;
        }
        
        Node* del = current;
        cout << del -> data << " has been eliminated!\n";
    
        current = current -> next;
        prev -> next = current;

        if (del == head) {
            head = current;
        }

        delete del;
    }

    cout << "\nThe ultimate survivor is: " << head -> data << "!\n";
}


int main() {
    Node* head = nullptr;
    create(head, 11);
    display(head);
    removePlayers(head);
    display(head);
    return 0;
}