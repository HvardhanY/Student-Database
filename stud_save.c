#include"project.h"
void stud_save(struct student *ptr)
{
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	FILE *fp;
	fp=fopen("std.txt","w");
	if(fp==0)
	{
		printf("File not found\n");
		return;
	}
	while(ptr)                                                      
	{
		fprintf(fp,"%d %s %f\n",ptr->roll_no,ptr->name,ptr->percentage);
		ptr=ptr->next;                                   
	}
	printf("All records are saved in a file successfully\n");
}
