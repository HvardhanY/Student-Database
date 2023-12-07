#include"project.h"
void stud_del(struct student **ptr)
{
	if(*ptr==0)
	{
		printf("No records to delete\n");
		return;
	}
	char ch;
	printf("How do u want to delete\n");
	printf("r/R : Based on rollno\n");
	printf("n/N : Based on name\n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case 'r':del_num(ptr);break;
		case 'R':del_num(ptr);break;
		case 'n':del_name(ptr);break;
		case 'N':del_name(ptr);break;
		default:printf("Invalid option chosen\n");
	}
}
void del_num(struct student **ptr)
{
	int rollno;
	printf("Enter rollno to delete\n");
	scanf("%d",&rollno);
	struct student *del=*ptr,*prev=0;
	while(del)
	{
		if(rollno==del->roll_no)
		{
			if(del==*ptr)
				*ptr=del->next;
			else
				prev->next=del->next;
			printf("%d record deleted\n",del->roll_no);
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("Rollno not found\n");
}
void del_name(struct student **ptr)
{
	char name[20];
	printf("Enter name to delete\n");
	scanf(" %s",name);
	struct student *del=*ptr,*prev=0,*dup=*ptr;
	int c=0;
	for(dup;dup;dup=dup->next)
		if(strcmp(dup->name,name)==0)
			c++;
	if(c==1)
	{
		while(del)
		{
			if((strcmp(del->name,name)==0))
			{
				if(del==*ptr)
					*ptr=del->next;
				else
					prev->next=del->next;
				printf("%s record deleted\n",del->name);
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}
	}
	else
	{
		struct student *d=*ptr;
		printf("Multiple records found with same name\n");
	        for(d;d;d=d->next)
		if(strcmp(d->name,name)==0)
			printf("%d %s %f\n",d->roll_no,d->name,d->percentage);
		del_num(ptr);
		return;
	}
	printf("No name found\n");
}
