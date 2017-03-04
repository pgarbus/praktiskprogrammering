#include "box.h"
#include "eigen.h"
#include <stdio.h>
int main(void)
{
	int eigen_success = eigen();
	int box_success = box();
	

	printf("\n\nSTATEMENTS FOR EXECUTION OF SUBRUTINES:\n");
	if (!eigen_success)
	{
		printf("Execution of eigen was succesful.\n");
	}
	else printf("Failure in eigen rutine.\n");
	if (!box_success)
	{
		printf("Execution of box was succesful.\n");
	}
	else printf("Failure in box rutine.\n");


	return 0;
}