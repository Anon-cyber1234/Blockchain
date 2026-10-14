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

	/*printf("\nTEST 1: Unchanged blockchain\n");

	verify(head);

	strcpy_s(head->next->Username, sizeof(head->next->Username), "hacker");
	printf("\nTEST 2: username changed from sumita to hacker\n");

	verify(head);*/
	printf("\nTEST 1: Unchanged blockchain\n");
	verify(head);

	head->next->loginTime += 3600;
	printf("\nTEST 2: timestamp tampering\n");

	/*head->next->hash.hash0 ^= 1;
	printf("\ntest 3: stored hash modified \n");*/

	/*strcpy_s(head->next->Username, sizeof(head->next->Username), "hacker");
	printf("\nTEST 2: username tampering\n");*/
	verify(head);


}