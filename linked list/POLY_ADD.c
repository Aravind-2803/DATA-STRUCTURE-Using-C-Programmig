#include <stdio.h>
#include <stdlib.h>
struct polynomial_node 
{
    int coeff;
    int exp;
    struct polynomial_node* next;
};
struct polynomial_node* createNode(int coeff, int exp) 
{
    struct polynomial_node* newNode = (struct polynomial_node *)malloc(sizeof(struct polynomial_node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct polynomial_node** head, int coeff, int exp) 
{
    struct polynomial_node* newNode = createNode(coeff, exp);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct polynomial_node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void displayPoly(struct polynomial_node* poly) 
{
    if (poly == NULL) 
    {
        printf("0\n");
        return;
    }
    while (poly != NULL) 
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}
struct polynomial_node* addPolynomials(struct polynomial_node* A,struct polynomial_node* B) {
    struct polynomial_node* C = NULL;
    struct polynomial_node* C_temp = NULL;
    while (A != NULL && B != NULL) 
    {
        struct polynomial_node* Newterm = NULL;
        if (A->exp == B->exp) 
        {
            int sum = A->coeff + B->coeff;
            if (sum != 0) 
            {
                Newterm = createNode(sum, A->exp);
            }
            A = A->next;
            B = B->next;
        }
        else if (A->exp > B->exp) 
        {
            Newterm = createNode(A->coeff, A->exp);
            A = A->next;
        }
        else 
        {
            Newterm = createNode(B->coeff, B->exp);
            B = B->next;
        }
        if (Newterm != NULL) 
        {
            if (C == NULL) 
            {
                C = Newterm;
                C_temp = Newterm;
            } else 
            {
                C_temp->next = Newterm;
                C_temp = Newterm;
            }
        }
    }
    while (A != NULL) 
    {
        struct polynomial_node* Newterm = createNode(A->coeff, A->exp);
        if (C == NULL) 
        {
            C = Newterm;
            C_temp = Newterm;
        } else 
        {
            C_temp->next = Newterm;
            C_temp = Newterm;
        }
        A = A->next;
    }
    while (B != NULL) 
    {
        struct polynomial_node* Newterm = createNode(B->coeff, B->exp);
        if (C == NULL) 
        {
                C = Newterm;
            C_temp = Newterm;
        } else 
        {
            C_temp->next = Newterm;
            C_temp = Newterm;
        }
        B = B->next;
    }
    return C;
}
void readPolynomial(struct polynomial_node** poly) 
{
    int n;
    printf("\nENTER THE NUMBER OF TERMS THE POLYNOMIAL CONTAINS : ");
    scanf("%d", &n);
    printf("\nENTER EACH TERM [COEFFICIENT,EXPONENT]: ");
    for (int i = 0; i < n; ++i) 
    {
        int coeff, exp;
        printf("\nTERM [%d] : ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertNode(poly, coeff, exp);
    }
}
int main() 
{
    struct polynomial_node* A = NULL;
    struct polynomial_node* B = NULL;
    struct polynomial_node* C = NULL;
    printf("\n ENTER THE FIRST POLYNOMIAL : ");
    readPolynomial(&A);
    printf("\nENTER THE SECOND POLYNOMIAL : ");
    readPolynomial(&B);
    printf("\nPOLYNOMIAL A : ");
    displayPoly(A);
    printf("\nPOLYNOMIAL B : ");
    displayPoly(B);
    C = addPolynomials(A, B);
    printf("\nADDITION OF POLYNOMIAL A AND B :  ");
    displayPoly(C);
    return 0;
}