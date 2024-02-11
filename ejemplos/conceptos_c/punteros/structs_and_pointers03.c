/* This program demonstrates the usage of an arrow operator */
#include <stdio.h>

struct item {
	char code[5];
	int Qty;
	float cost;
};

int main() {

	struct item item_rec; /* Define a variable of struct type */
	struct item *ptr;	  /* Define a pointer of type struct */

	/* Read data through dot operator */
	printf("\n Enter the data for an item");
	printf("\nCode:");
	scanf("%s", &item_rec.code);
	printf("\nQty:");
	scanf("%d", &item_rec.Qty);
	printf("\nCost:");
	scanf("%f", &item_rec.cost);
	/* Assign the address of item_rec */
	ptr = &item_rec;
	printf("\n The data for the item...");
	printf("\nCode : %s", ptr->code);
	printf("\nQty : %d", ptr->Qty);
	printf("\nCost : %5.2f", ptr->cost);
	return 0;
}
