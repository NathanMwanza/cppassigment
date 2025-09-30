#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
        for (int i = 0; i <= 100; i += 2) {
            insertAtEnd(i);
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node{value, nullptr};
        if (position <= 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        int currentPos = 1;
        while (temp->next != nullptr && currentPos < position - 1) {
            temp = temp->next;
            currentPos++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) return;
        if (position == 1) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        int currentPos = 1;
        while (temp->next != nullptr && currentPos < position - 1) {
            temp = temp->next;
            currentPos++;
        }
        if (temp->next == nullptr) return;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << "-";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void findMax() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        int maxVal = head->data;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data > maxVal) maxVal = temp->data;
            temp = temp->next;
        }
        cout << "Maximum even number: " << maxVal << endl;
    }

    void findMin() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        int minVal = head->data;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data < minVal) minVal = temp->data;
            temp = temp->next;
        }
        cout << "Minimum even number: " << minVal << endl;
    }

    void countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Count of even numbers: " << count << endl;
    }

    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        int mid = count / 2;
        temp = head;
        for (int i = 0; i < mid; i++) temp = temp->next;
        cout << "Middle even number: " << temp->data << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    cout << "ASSIGNMENT1 NATHAN MWANZA 23148134\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display List\n";
        cout << "8. Find Max\n";
        cout << "9. Find Min\n";
        cout << "10. Count Nodes\n";
        cout << "11. Find Middle\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter an even number: ";
            cin >> value;
            if (value % 2 == 0)
                list.insertAtBeginning(value);
            else
                cout << "Invalid! Only even numbers allowed.\n";
        }
        else if (choice == 2) {
            cout << "Enter an even number: ";
            cin >> value;
            if (value % 2 == 0)
                list.insertAtEnd(value);
            else
                cout << "Invalid! Only even numbers allowed.\n";
        }
        else if (choice == 3) {
            cout << "Enter an even number: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            if (value % 2 == 0)
                list.insertAtPosition(value, pos);
            else
                cout << "Invalid! Only even numbers allowed.\n";
        }
        else if (choice == 4) {
            list.deleteAtBeginning();
        }
        else if (choice == 5) {
            list.deleteAtEnd();
        }
        else if (choice == 6) {
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
        }
        else if (choice == 7) {
            list.display();
        }
        else if (choice == 8) {
            list.findMax();
        }
        else if (choice == 9) {
            list.findMin();
        }
        else if (choice == 10) {
            list.countNodes();
        }
        else if (choice == 11) {
            list.findMiddle();
        }
        else if (choice == 12) {
            cout << "Bye";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
