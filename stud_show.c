#include"project.h"
void stud_show(struct student *ptr)
{
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	while(ptr)                                                      
	{
		printf("%d %s %f\n",ptr->roll_no,ptr->name,ptr->percentage);
		ptr=ptr->next;                                   
	}
}
