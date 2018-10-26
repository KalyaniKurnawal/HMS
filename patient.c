/********* Include files **********/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/******** global variable **********/



struct patient
{
	int p_id;
	char *name;
	struct patient *next;
};



struct patient *head = NULL;
#define SUCCESS 0


/******* Prototypes ********/
int patient();
int new_entry_patient();
int list_all_patient();


int patient()
{
	int choice;
	printf("1.New Entry\n2.List of Patient\n3.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:new_entry_patient();
			break;
		case 2:list_all_patients();
			break;
		case 3:return SUCCESS;
		default:printf("\n Invalid choice");

	}

}


int new_entry_patient()
{
	return SUCCESS;
}

int list_all_patient()
{
	return SUCCESS;
}





