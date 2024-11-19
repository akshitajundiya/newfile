//RIGHT CODE FOR ADDING POLYNOMIAL USiNG LINKED LIST
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int coefficient;
    int exponent;
    Node* next;
    
};

void insertTerm(Node*& head, int coef, int exp) 
{
    Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient=coef;
    newNode->exponent=exp;
    newNode->next=NULL;
    if (!head || head->exponent < exp) 
    {
        newNode->next = head;
        head = newNode;
    } 
    else 
    {
        Node* current = head;
        while (current->next && current->next->exponent >= exp) 
        {
            if (current->next->exponent == exp) 
            {
                current->next->coefficient += coef;
                delete newNode;
                return;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printPolynomial(Node* head) 
{
    Node* current = head;
    while (current) 
    {
        if (current != head && current->coefficient > 0) 
        {
            cout << " + ";
        }
        if (current->coefficient != 0) {
            cout << current->coefficient;
            if (current->exponent != 0) {
                cout << "x^" << current->exponent;
            }
        }
        current = current->next;
    }
    cout << endl;
}

Node* addPolynomials(Node* poly1, Node* poly2) 
{
    Node* result = nullptr;
    while (poly1 || poly2) 
    {
        if (!poly1) 
        {
            insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } 
        else if (!poly2) 
        {
            insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } 
        else if (poly1->exponent == poly2->exponent) 
        {
            insertTerm(result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } 
        else if (poly1->exponent > poly2->exponent) 
        {
            insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } 
        else 
        {
            insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }
    return result;
}

void readPolynomial(Node*& poly) {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int coef, exp;
        cout << "Enter coefficient and exponent for term " << (i + 1) << ": ";
        cin >> coef >> exp;
        insertTerm(poly, coef, exp);
    }
}

int main() 
{
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    
    cout << "Enter polynomial 1:" << endl;
    readPolynomial(poly1);

    cout << "Enter polynomial 2:" << endl;
    readPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Result of addition: ";
    printPolynomial(result);
}