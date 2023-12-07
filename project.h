#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
struct student
{
	int roll_no;
	char name[20];
	float percentage;
	struct student *next;
};
void stud_add(struct student **);
void stud_del(struct student **);
void del_num(struct student**);
void del_name(struct student**);
void stud_show(struct student *);
void stud_mod(struct student **);
void search_num(struct student **ptr);
void search_name(struct student **ptr);
void search_percent(struct student **ptr);
void stud_save(struct student *);
void sort_data(struct student **);
void delete_all(struct student **);
void reverse_links(struct student **);
