#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;         // Coefficient of the term
    int exp;           // Exponent of the term
    struct node *next; // Pointer to the next node
} node;

// Function to create a new node
node *getnode(int coeff, int exp)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a term in the polynomial in descending order of exponents
void insert_descending_order(node **start, int coeff, int exp)
{
    node *newnode = getnode(coeff, exp);
    if (newnode == NULL)
        return;

    if (*start == NULL || (*start)->exp < exp)
    {
        newnode->next = *start;
        *start = newnode;
    }
    else
    {
        node *ptr = *start;
        while (ptr->next != NULL && ptr->next->exp > exp)
        {
            ptr = ptr->next;
        }

        if (ptr->next != NULL && ptr->next->exp == exp)
        {
            // If exponent already exists, add the coefficient
            ptr->next->coeff += coeff;
            free(newnode);
        }
        else
        {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }
}

// Function to display the polynomial
void display_polynomial(node *start)
{
    if (start == NULL)
    {
        printf("Polynomial is empty\n");
        return;
    }

    node *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->exp != 0)
            printf("%dx^%d ", ptr->coeff, ptr->exp);
        else
            printf("%d", ptr->coeff);

        if (ptr->next != NULL)
            printf("+ ");

        ptr = ptr->next;
    }
    printf("\n");
}

// Function to add two polynomials
node *add_polynomials(node *poly1, node *poly2)
{
    node *result = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insert_descending_order(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            insert_descending_order(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0)
                insert_descending_order(&result, sum, poly1->exp);

            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        insert_descending_order(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        insert_descending_order(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main()
{
    int choice, coeff, exp;
    node *poly1 = NULL; // Polynomial 1
    node *poly2 = NULL; // Polynomial 2

    while (1)
    {
        printf("1. Insert term into polynomial 1\n");
        printf("2. Insert term into polynomial 2\n");
        printf("3. Add polynomials\n");
        printf("4. Display polynomial 1\n");
        printf("5. Display polynomial 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter coefficient and exponent for polynomial 1: ");
            scanf("%d %d", &coeff, &exp);
            insert_descending_order(&poly1, coeff, exp); // Insert terms for poly1
            break;
        case 2:
            printf("Enter coefficient and exponent for polynomial 2: ");
            scanf("%d %d", &coeff, &exp);
            insert_descending_order(&poly2, coeff, exp); // Insert terms for poly2
            break;
        case 3:
        {
            node *result = add_polynomials(poly1, poly2);
            printf("Result of addition: ");
            display_polynomial(result);
            break;
        }
        case 4:
            printf("Polynomial 1: ");
            display_polynomial(poly1);
            break;
        case 5:
            printf("Polynomial 2: ");
            display_polynomial(poly2);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
