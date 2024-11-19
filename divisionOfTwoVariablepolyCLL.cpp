//RIGHT CODE FOR DIVISION OF TWO VARIABLE POLYNOMIAL USING CLL
#include <bits/stdc++.h>
using namespace std;

struct Node {
    float coeff;
    int expo1;
    int expo2;
    struct Node* link;
};

Node* insert(Node* head, float co, int ex1, int ex2) {
    Node* newP = new Node();
    newP->coeff = co;
    newP->expo1 = ex1;
    newP->expo2 = ex2;

    if (head == nullptr) {
        head = newP;
        head->link = head; 
    } else if ((ex1 > head->expo1) || (ex1 == head->expo1 && ex2 > head->expo2)) {
        Node* temp = head;
        while (temp->link != head) {
            temp = temp->link;
        }
        temp->link = newP;
        newP->link = head;
        head = newP;
    } else {
        Node* temp = head;
        while (temp->link != head && 
               (temp->link->expo1 > ex1 || 
               (temp->link->expo1 == ex1 && temp->link->expo2 >= ex2))) {
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

Node* create(Node* head) {
    int n;
    float coeff;
    int expo1, expo2;

    cout << "Enter the number of terms: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter the coefficient for term " << i+1 << ": ";
        cin >> coeff;

        cout << "Enter the exponent for x in term " << i+1 << ": ";
        cin >> expo1;

        cout << "Enter the exponent for y in term " << i+1 << ": ";
        cin >> expo2;

        head = insert(head, coeff, expo1, expo2);
    }
    return head;
}

void print(Node* head) {
    if (head == nullptr) return;

    Node* current = head;
    bool first = true;
    do {
        if (!first && current->coeff > 0) {
            cout << " + ";
        }
        if (current->coeff != 0) {
            cout << current->coeff;
            if (current->expo1 != 0) {
                cout << "x^" << current->expo1;
            }
            if (current->expo2 != 0) {
                cout << "y^" << current->expo2;
            }
            first = false;
        }
        current = current->link;
    } while (current != head);

    if (first) {
        cout << "0";
    }
    cout << endl;
}

Node* simplify(Node* head) {
    if (head == nullptr) return head;

    Node* temp1 = head;
    do {
        Node* temp2 = temp1;
        while (temp2->link != head) {
            if (temp1->expo1 == temp2->link->expo1 && temp1->expo2 == temp2->link->expo2) {
                temp1->coeff += temp2->link->coeff;
                Node* temp = temp2->link;
                temp2->link = temp2->link->link;
                delete temp;
            } else {
                temp2 = temp2->link;
            }
        }
        temp1 = temp1->link;
    } while (temp1 != head);

    return head;
}

void polyDivide(Node* head1, Node* head2, Node*& head3) {
    if (head1 == nullptr || head2 == nullptr) {
        cout << "Zero polynomial" << endl;
        return;
    }

    Node* ptr1 = head1;
    do {
        Node* ptr2 = head2;
        do {
            head3 = insert(head3, ptr1->coeff / ptr2->coeff, ptr1->expo1 - ptr2->expo1, ptr1->expo2 - ptr2->expo2);
            ptr2 = ptr2->link;
        } while (ptr2 != head2);
        ptr1 = ptr1->link;
    } while (ptr1 != head1);
    
    cout << "Before simplification: ";
    print(head3);

    head3 = simplify(head3);
    
    cout << "After simplification: ";
    print(head3);
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;

    cout << "Enter the first polynomial:" << endl;
    head1 = create(head1);

    cout << "Enter the second polynomial:" << endl;
    head2 = create(head2);

    polyDivide(head1, head2, head3);
}
