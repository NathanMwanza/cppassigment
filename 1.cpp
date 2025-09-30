#include <iostream>
#include <string>
using namespace std;


struct Transaction {
    int refNo;
    string senderPhone;
    string receiverPhone;
    string receiverName;
    string date;
    double amount;
};

Transaction transactions[100];
int countTrans = 0;

void Nwtrans() {
    if (countTrans >= 100) {
        cout << "Transaction list is full!" << endl;
        return;
    }
    Transaction t;
    cout << "Enter Ref Number: ";
    cin >> t.refNo;
    cout << "Enter Sender Phone: ";
    cin >> t.senderPhone;
    cout << "Enter Receiver Phone: ";
    cin >> t.receiverPhone;
    cout << "Enter Receiver Name: ";
    cin.ignore();
    getline(cin, t.receiverName);
    cout << "Enter Date (dd/mm/yyyy): ";
    cin >> t.date;
    cout << "Enter Amount: ";
    cin >> t.amount;

    transactions[countTrans++] = t;
    cout << "Transaction successful" << endl;
}
void linearSearch(int ref) {
    for (int i = 0; i < countTrans; i++) {
        if (transactions[i].refNo == ref) {
            cout << "\nTransaction Found!" << endl;
            cout << "Ref: " << transactions[i].refNo
                     << ", Sender: " << transactions[i].senderPhone
                     << ", Receiver: " << transactions[i].receiverPhone
                     << ", Name: " << transactions[i].receiverName
                     << ", Date: " << transactions[i].date
                     << ", Amount: " << transactions[i].amount << endl;
            return;}
    }
    cout << "not found!" << endl;
}
void bubbleSort() {
    for (int i = 0; i < countTrans - 1; i++) {
        for (int j = 0; j < countTrans - i - 1; j++) {
            if (transactions[j].amount > transactions[j + 1].amount) {
                swap(transactions[j], transactions[j + 1]);}
}
}
    cout << "Transactions sorted by amount!" << endl;
}
void binarySearch(int ref) {
    for (int i = 0; i < countTrans - 1; i++) {
     for (int j = 0; j < countTrans - i - 1; j++) {
        if (transactions[j].refNo > transactions[j + 1].refNo) {
            swap(transactions[j], transactions[j + 1]);
}
}
}
    int left = 0, right = countTrans - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (transactions[mid].refNo == ref) {
            cout << "\nTransaction Found!" << endl;
            cout << "Ref: " << transactions[mid].refNo
                 << ", Sender: " << transactions[mid].senderPhone
                 << ", Receiver: " << transactions[mid].receiverPhone
                 << ", Name: " << transactions[mid].receiverName
                 << ", Date: " << transactions[mid].date
                 << ", Amount: " << transactions[mid].amount << endl;
            return;
        }
        else if (transactions[mid].refNo < ref) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Transaction not found!" << endl;
}
void displayAll() {
    if (countTrans == 0) {
        cout << "No transactions available!" << endl;
        return;
    }
    cout << "\n All Transactions " << endl;
    for (int i = 0; i < countTrans; i++) {
        cout << "Ref: " << transactions[i].refNo
             << ", Sender: " << transactions[i].senderPhone
             << ", Receiver: " << transactions[i].receiverPhone
             << ", Name: " << transactions[i].receiverName
             << ", Date: " << transactions[i].date
             << ", Amount: " << transactions[i].amount << endl;
    }
}
int main() {
    int choice;
    do {
        cout << "\n MMT Nathan Mwanza 23148134" << endl;
        cout << "1. Add Transaction" << endl;
        cout << "2. linear Transaction " << endl;
        cout << "3. Bubble sort" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Transactions" << endl;
        cout << "6. Exit" << endl;
        cout << "choose ";
        cin >> choice;
        if (choice == 1) {
            Nwtrans();
        } else if (choice == 2) {
            int ref;
            cout << "Enter reference number: ";
            cin >> ref;
            linearSearch(ref);
        } else if (choice == 3) {
            bubbleSort();
        } else if (choice == 4) {
            int ref;
            cout << "Enter reference number: ";
            cin >> ref;
            binarySearch(ref);
        } else if (choice == 5) {
            displayAll();
        }
    } while (choice != 6);
    return 0;
}
