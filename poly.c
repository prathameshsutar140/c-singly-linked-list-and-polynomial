#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** head, int coeff, int pow) {
    struct Node* newNode;
    struct Node* temp;
    newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    int sumCoeff;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertTerm(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insertTerm(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    
    return result;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp;
    if (head == NULL) {
        printf("0\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp != NULL) {
            if (temp->coeff >= 0)
                printf(" + ");
            else
                printf(" ");
        }
    }
    printf("\n");
}

void main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    clrscr();

    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);
    insertTerm(&poly1, 6, 0);

    insertTerm(&poly2, 6, 2);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, 2, 0);

    printf("First Polynomial  : ");
    displayPolynomial(poly1);

    printf("Second Polynomial : ");
    displayPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum Polynomial    : ");
    displayPolynomial(sum);

    getch();
}