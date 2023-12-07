#include"project.h"
void main()
{
	char ch;
	struct student *headptr=0;
	while(1)
	{
		printf("*****STUDENT RECORD MENU*****\n");
		printf("a/A : add new record\n");
		printf("d/D : delete a record\n");
		printf("s/S : show the list\n");
		printf("m/M : modify a record\n");
		printf("v/V : save\n");
		printf("e/E : exit\n");
		printf("t/T : sort the list\n");
		printf("l/L : delete all the records\n");
		printf("r/R : reverse the list\n");
		printf("Enter your choice :\n");
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'a':stud_add(&headptr);break;
			case 'A':stud_add(&headptr);break;
			case 'd':stud_del(&headptr);break;
			case 'D':stud_del(&headptr);break;
			case 's':stud_show(headptr);break;
			case 'S':stud_show(headptr);break;
	                case 'm':stud_mod(&headptr);break;
			case 'M':stud_mod(&headptr);break;
			case 'v':stud_save(headptr);break;
			case 'V':stud_save(headptr);break;
			case 'e':exit(0);
			case 'E':exit(0);
		     /* case 't':sort_data(&headptr);break;
    		        case 'T':sort_data(&headptr);break;*/
			case 'l':delete_all(&headptr);break;
			case 'L':delete_all(&headptr);;break;
		     /* case 'r':reverse_links(&headptr);break;
		        case 'R':reverse_links(&headptr);break;*/
			default :printf("Invalid Choice\n");
		}
	}
}

