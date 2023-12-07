#include"project.h"
void stud_add(struct student **ptr)
{
	struct student *new=malloc(sizeof(struct student));
	printf("Enter the name and percentage of student\n");
	scanf("%s %f",new->name,&new->percentage);
	if(*ptr==0 || (*ptr)->roll_no!=1)
	{
		new->roll_no=1;
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		struct student *last=*ptr;
		while(last->next!=0 && (last->roll_no == last->next->roll_no-1))
			last=last->next;
		new->roll_no=last->roll_no+1;
		new->next=last->next;
		last->next=new;
	}
}
