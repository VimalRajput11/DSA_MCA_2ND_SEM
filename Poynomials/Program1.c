#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node * createNode(int coeff,int exp){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}

struct node* insertTerm(struct node **poly, int coeff, int exp) {
    struct node *newnode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newnode;
    } else {
        struct node *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return *poly;
}

//Function to add Two polynomials

struct node* AddPolynomials (struct node *poly1,struct node *poly2)
{
	struct node *result=NULL;
	struct node **tail=&result;
	while(poly1!=NULL && poly2!=NULL)
	{
		if(poly1->exp==poly2->exp)
		{
			insertTerm(tail,poly1->coeff+poly2->coeff,poly1->exp);
			poly1=poly1->next;
			poly2=poly2->next;
		}
		else if(poly1->exp > poly2->exp)
		{
			insertTerm(tail,poly1->coeff,poly1->exp);
			poly1=poly1->next;
		}
		else {
			insertTerm(tail,poly2->coeff,poly2->exp);
			poly2=poly2->next;
		}
		tail=&((*tail)->next);
	}
	while(poly1!=NULL)
	{
		insertTerm(tail,poly1->coeff,poly1->exp);
		poly1=poly1->next;
		tail=&((*tail)->next);
	}
	while(poly2!=NULL)
	{
		insertTerm(tail,poly2->coeff,poly2->exp);
		poly2=poly2->next;
		tail=&((*tail)->next);
	}
	return result;
}

struct node * SubtractPolynomials (struct node *poly1, struct node *poly2) {
    struct node *result = NULL;
    struct node **tail = &result;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insertTerm(tail, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insertTerm(tail, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            insertTerm(tail, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        tail = &((*tail)->next);
    }

    while (poly1 != NULL) {
        insertTerm(tail, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
        tail = &((*tail)->next);
    }

    while (poly2 != NULL) {
        insertTerm(tail, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
        tail = &((*tail)->next);
    }

    return result;
}

struct node * MultiplyPolynomials (struct node *poly1, struct node *poly2) {
    struct node *result = NULL;
    struct node **tail = &result;

    for (struct node *p1 = poly1; p1 != NULL; p1 = p1->next) {

        for (struct node *p2 = poly2; p2 != NULL; p2 = p2->next) {

            insertTerm(tail, p1->coeff * p2->coeff, p1->exp + p2->exp);
            tail = &((*tail)->next);
        }
    }

    return result;
}




 
struct node * DivisionPolynomials (struct node *poly1, struct node *poly2) {
    struct node *result = NULL;
    struct node **tail = &result;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp >= poly2->exp) {
            insertTerm(tail, poly1->coeff / poly2->coeff, poly1->exp - poly2->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else {
            insertTerm(tail, 0, poly1->exp);
            poly1 = poly1->next;
        }
        tail = &((*tail)->next);
    }

    return result;
}
void displayPolynomial(struct node *temp)
{
    while (temp != NULL) {
        if (temp->next != NULL) {
            printf("%dx^%d + ", temp->coeff, temp->exp);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        temp = temp->next;
    }
}

int main(){
    struct node *poy1 = NULL;
    struct node *poy2 = NULL;

    //insertTerming Terms in the first Polynomial
    insertTerm(&poy1, 5, 2); 
    insertTerm(&poy1, 4, 1);
    insertTerm(&poy1, 2, 0);
    //Inserting Terms in the second Polynomial
    insertTerm(&poy2, -3, 3);
    insertTerm(&poy2, 2, 1);
    insertTerm(&poy2, 1, 0);
    printf("first Polynomial: ");
    displayPolynomial(poy1);
    printf("\nSecond Polynomial: ");
    displayPolynomial(poy2);
    struct node *result = AddPolynomials(poy1, poy2);
    printf("\nResultant Polynomial after Addition: ");
    displayPolynomial(result);
    struct node *result1 = SubtractPolynomials(poy1, poy2);
    printf("\nResultant Polynomial after Subtraction: ");

    displayPolynomial(result1);
    struct node *result2 = MultiplyPolynomials(poy1, poy2);
    printf("\nResultant Polynomial after Multiplication: ");
    displayPolynomial(result2);
    struct node *result3 = DivisionPolynomials(poy1, poy2);
    printf("\nResultant Polynomial after Division: ");
    displayPolynomial(result3);
}
