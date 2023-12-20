#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coff;
    int pow;
    struct node *link;
} TERM;

TERM *create_polynomial(TERM *node);
TERM *add_term(TERM *node, int coff, int pow);
TERM *search(TERM *node, int data);
TERM *poly_add(TERM *poly1, TERM *poly2, TERM *poly3);
TERM *poly_multi(TERM *poly1, TERM *poly2, TERM *poly3);
void display(TERM *poly);

int main()
{
    printf("hallo world\n");
    TERM *exp1, *exp2, *exp3;
    exp1 = exp2 = exp3 = NULL;

    exp1 = create_polynomial(exp1);
    exp2 = create_polynomial(exp2);
    display(exp1);
    display(exp2);
    exp3 = poly_add(exp1, exp2, exp3);
    display(exp3);
    return 0;
}

TERM *create_polynomial(TERM *node)
{
    int power, cof, term;
    printf("\n___en no of terms___");
    scanf("%d", &term);
    for (int i = 0; i < term; i++)
    {
        printf("Enter the coeff: ");
        scanf("%d", &cof);
        printf("Enter the power: ");
        scanf("%d", &power);
        node = add_term(node, cof, power);
    }
    return node;
}

TERM *add_term(TERM *start, int coff, int pow)
{
    TERM *temp, *ptr;
    temp = (TERM *)calloc(1, sizeof(TERM));
    temp->coff = coff;
    temp->pow = pow;
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
        return start;
    }
    ptr = start;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return start;
}

TERM *poly_add(TERM *poly1, TERM *poly2, TERM *poly3)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow > poly2->pow)
        {
            poly3 = add_term(poly3, poly1->coff, poly1->pow);
            poly1 = poly1->link;
        }
        else if (poly1->pow < poly2->pow)
        {
            poly3 = add_term(poly3, poly2->coff, poly2->pow);
            poly2 = poly2->link;
        }
        else
        {
            poly3 = add_term(poly3, poly1->coff + poly2->coff, poly1->pow);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }
    while (poly1 != NULL)
    {
        poly3 = add_term(poly3, poly1->coff, poly1->pow);
        poly1 = poly1->link;
    }
    while (poly2 != NULL)
    {
        poly3 = add_term(poly3, poly2->coff, poly2->pow);
        poly2 = poly2->link;
    }
    // display(poly3);
    return poly3;
}

void display(TERM *head)
{
    printf("\n____Displaying the polynomial_____\n");
    if (head == NULL)
    {
        printf("\n0");
        return;
    }
    while (head != NULL)
    {
        printf(" %d^%d %s", head->coff, head->pow, (head->coff < 0 || head->link == NULL ? "" : "+"));
        head = head->link;
    }
    printf("\b\b\n");
}

//? out..
/*
____Displaying the polynomial_____
 1^3 + 5^2

____Displaying the polynomial_____
 1^5 + 2^3 + 4^1

____Displaying the polynomial_____
 1^5 + 3^3 + 5^2 + 4^1
*/

//? out 2..
/*
____Displaying the polynomial_____
 1^3 + 5^0

____Displaying the polynomial_____
 1^2 + 6^1

____Displaying the polynomial_____
 1^3 + 1^2 + 6^1 + 5^0
*/

//! there are some issue with -
/*
____Displaying the polynomial_____
 -8^2  4^0

____Displaying the polynomial_____
 5^2 + -9^1  2^0

____Displaying the polynomial_____
 -3^2  -9^1  6^0
*/

TERM *poly_multi(TERM *poly1, TERM *poly2, TERM *poly3)
{
    TERM *ptr, *temp, *location;
    int cof, pow;
    while (poly1 != NULL)
    {
        ptr = poly2;
        while (ptr != NULL)
        {
            cof = poly1->coff * poly2->coff;
            pow = poly1->pow + poly2->pow;
            ptr = temp;
            location = search(temp, pow);
            if (location != NULL)
                location->coff += cof;
            else
                poly3 = add_term(poly3, cof, pow);
            temp = temp->link;
        }
        ptr = ptr->link;
    }
}

TERM *search(TERM *node, int data)
{
    while (node != NULL)
    {
        if (node->pow == data)
            return node;
    }
    return NULL;
}
