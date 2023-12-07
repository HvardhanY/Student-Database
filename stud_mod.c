#include"project.h"
void stud_mod(struct student **ptr)
{
	if(*ptr==0)
	{
		printf("No records fount to modify\n");
		return;
	}
	char ch;
	printf("Enter which record to search for modification\n");
	printf("r/R : To search a rollno\n");
	printf("n/N : To search a name\n");
	printf("p/P : Percentage based\n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case 'r':search_num(ptr);break;
		case 'R':search_num(ptr);break;
		case 'n':search_name(ptr);break;
		case 'N':search_name(ptr);break;
		case 'p':search_percent(ptr);break;
		case 'P':search_percent(ptr);break;
		default:printf("Invalid option chosen\n");
	}
}
void search_num(struct student **ptr)
{
	int rollno;
	printf("Enter rollno to search\n");
	scanf("%d",&rollno);
	struct student *del=*ptr,*prev=0;
	while(del)
	{
		if(rollno==del->roll_no)
		{
			char ch;
			printf("Roll no found enter what you want to modify? Name/Percentage\n");
			printf("n/N : Name modification of this record\n");
			printf("p/P : Percentage modification of this record\n");
			scanf(" %c",&ch);
			char name1[20];
			int per1;
			switch(ch)
			{
				case 'n':printf("Enter new name\n");
					 scanf(" %s",name1);
					 strcpy(del->name,name1);break;
				case 'N':printf("Enter new name\n");
					 scanf(" %s",name1);
					 strcpy(del->name,name1);break;
				case 'p':printf("Enter the new percentage\n");
					 scanf("%d",&per1);
					 del->percentage=per1;break;
				case 'P':printf("Enter the new percentage\n");
					 scanf("%d",&per1);
					 del->percentage=per1;break;
			}
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("Rollno not found......\n");
	printf("Add the data as a new entry\n");
	stud_add(ptr);
}
void search_name(struct student **ptr)
{
	char name[20];
	printf("Enter name to search\n");
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
				char ch1;
				printf("Name found enter what you want to modify? Name/Percentage\n");
				printf("n/N : Name modification of this record\n");
				printf("p/P : Percentage modification of this record\n");
				scanf(" %c",&ch1);
				char name2[20];
				int per2;
				switch(ch1)
				{
					case 'n':printf("Enter new name\n");
						 scanf(" %s",name2);
						 strcpy(del->name,name2);break;
					case 'N':printf("Enter new name\n");
						 scanf(" %s",name2);
						 strcpy(del->name,name2);break;
					case 'p':printf("Enter the new percentage\n");
						 scanf("%d",&per2);
						 del->percentage=per2;break;
					case 'P':printf("Enter the new percentage\n");
						 scanf("%d",&per2);
						 del->percentage=per2;break;
				}
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
		printf("Enter roll no of the particular name u want to modify\n");
		search_num(ptr);
		return;
	}
	printf("No name found.....\n");
	printf("Enter the record as a new data\n");
	stud_add(ptr);
}
void search_percent(struct student **ptr)
{
	int percent;
	printf("Enter percentage to search\n");
	scanf("%d",&percent);
	struct student *del=*ptr,*prev=0,*dup=*ptr;
	int c=0;
	for(dup;dup;dup=dup->next)
		if(dup->percentage==percent)
			c++;
	if(c==1)
	{
		while(del)
		{
			if(percent==del->percentage)
			{
				char ch;
				printf("Percentage found enter what you want to modify? Name/Percentage\n");
				printf("n/N : Name modification of this record\n");
				printf("p/P : Percentage modification of this record\n");
				scanf(" %c",&ch);
				char name1[20];
				int per1;
				switch(ch)
				{
					case 'n':printf("Enter new name\n");
						 scanf(" %s",name1);
						 strcpy(del->name,name1);break;
					case 'N':printf("Enter new name\n");
						 scanf(" %s",name1);
						 strcpy(del->name,name1);break;
					case 'p':printf("Enter the new percentage\n");
						 scanf("%d",&per1);
						 del->percentage=per1;break;
					case 'P':printf("Enter the new percentage\n");
						 scanf("%d",&per1);
						 del->percentage=per1;break;
				}
				return;
			}
			prev=del;
			del=del->next;
		}
	}
	else
	{
		struct student *d=*ptr;
		printf("Multiple records found with same percentage\n");
		for(d;d;d=d->next)
			if(d->percentage==percent)
				printf("%d %s %f\n",d->roll_no,d->name,d->percentage);
		printf("Enter roll no of the particular percentage u want to modify\n");
		search_num(ptr);
		return;

	}
	printf("Percentage not found......\n");
	printf("Add the data as a new entry\n");
	stud_add(ptr);
}
