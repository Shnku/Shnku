#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int coff;
    int pow;
    struct node *link;
} TERM;

TERM *create_polynomial(TERM *node);
TERM *add_term(TERM *node, int coff, int pow);
void poly_add(TERM *poly1, TERM *poly2, TERM **poly3);
void display(TERM *poly);

int main() {
    printf("hallo world\n");
    TERM *exp1, *exp2, *exp3;
    exp1 = exp2 = exp3 = NULL;

    exp1 = create_polynomial(exp1);
    display(exp1);
    exp2 = create_polynomial(exp2);
    display(exp2);
    poly_add(exp1, exp2, &exp3);
    display(exp3);
    return 0;
}

TERM *create_polynomial(TERM *node) {
    int power, cof, quit = 0;
    while (quit != 1) {
        printf("enter the coeff: ");
        scanf("%d", &cof);
        printf("Enter the power: ");
        scanf("%d", &power);
        node = add_term(node, cof, power);
        printf("done?? 1 for quit; ");
        scanf("%d", &quit);
    }
    return node;
}

TERM *add_term(TERM *start, int coff, int pow) {
    TERM *temp, *ptr = start;
    if (start == NULL) {
        temp = (TERM *)calloc(1, sizeof(TERM));
        temp->coff = coff;
        temp->pow = pow;
        temp->link = start;
        start = temp;
        return start;
    }
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    temp = (TERM *)calloc(1, sizeof(TERM));
    temp->coff = coff;
    temp->pow = pow;
    temp->link = NULL;
    ptr->link = temp;
    return start;
}

void poly_add(TERM *poly1, TERM *poly2, TERM **poly3) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            *poly3 = add_term(*poly3, poly1->coff, poly1->pow);
        } else if (poly1->pow < poly2->pow) {
            *poly3 = add_term(*poly3, poly2->coff, poly2->pow);
        } else {
            *poly3 = add_term(*poly3, poly1->coff + poly2->coff, poly1->pow);
        }
    }
}

void display(TERM *head) {
    printf("\n____Displaying the polynomial_____\n");
    if (head == NULL) {
        printf("\n0");
        return;
    }
    while (head != NULL) {
        printf(" %d^%d %s", head->coff, head->pow,
               (head->coff < 0 || head->link == NULL ? "" : "+"));
        head = head->link;
    }
    printf("\b\b\n");
}