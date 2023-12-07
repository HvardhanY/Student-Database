#include"project.h"
extern void delete_all(struct student **ptr)
{
	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}
	struct student *del=*ptr;
	int c=1;
	while(del)
	{
		*ptr=del->next;
		printf("node %d is deleted\n",c++);
		sleep(1);
		free(del);
		del=*ptr;
	}
	printf("All records deleted\n");
}
