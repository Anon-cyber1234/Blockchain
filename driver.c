#include <stdio.h>
#include <string.h>
#include "user.h"


int main(void) {
	struct User * head=NULL;
	head = add(head, "rob");
	head = add(head, "hanif");
	head = add(head, "gahyun");
	head = add(head, "matt");
	head = add(head, "sumita");
	head = add(head, "james");
	printLog(head);
	/*strcpy_s(head->next->Username, sizeof(head->next->Username), "hacker");
	printf("\nTest: Modified sumita to hacker.\n");*/

	/*head->next->loginTime += 3600;
	printf("\n Test: Modified sumita's login timestamp by one hour \n");*/
	/*head->next->hash.hash0 ^= 1;
	printf("\ntest: modified sumita's stored hash\n");*/


	verify(head);
}