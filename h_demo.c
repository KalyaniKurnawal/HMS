
/******************************************************************************
** Write code to maintain hospital details using structure and linked list  ***
******************************************************************************/

/******************************************************************************
 *
 * @file    hospital4.c
 * @author  Kalyani Kurnawal
 * @brief   This file is used to maintain hospital details
 * @date    OCT/16/2018,Created
 *****************************************************************************/

/*********************************
******* Include files ************
**********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*********************************/



/************************************
 *********** MACROS *****************
 ***********************************/
#define SUCCESS 0
#define MAX 10
#define FAILURE -1
#define  BUF_LEN 100


/**********************************
***** Global Variables ************
**********************************/
struct address
{
	char *hno;
	char *street;
	char *city;
	char *state;
	char *pin;
};

struct room
{
	char *room_id;
	char *room_type;
	char *no_of_beds;
	struct room *next;
};

struct room *root1=NULL;
struct room *end1=NULL;

struct department
{
	char *name;
	struct room *rm;
	struct department *next;
};

struct department *root=NULL;
struct department *end=NULL;

struct hospital
{
	char *name;
	struct address addr;
	struct department *ptr;
	char *phone_no;

};

FILE *outfile;

/***************************************
************** Prototypes *************
****************************************/
int hospital();
int add_hospital(struct hospital*,FILE*);
int modify_hospital(struct hospital*);
int display(FILE*,struct hospital*);
int validate_string(char *);
int validate_number(char *);
void print();
void insertatend();
/*************************************/




/**************************************************
 * Function     main
 * @date        OCT/16/2018
 * @brief       Main function of the program.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 *************************************************/
int main()
{
	hospital();
	return 0;
}
/**************** End of main function **********/



/**************************************************
 * Function     hospital
 * @date        OCT/16/2018
 * @brief       Main function of the program.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 *************************************************/
int hospital()
{
	int choice,h=0;
	struct hospital ptr,*head;
	head=&ptr;
	while(1)
	{
	printf("\n********** MENU  **************\n");
	printf("\n1.Add Hospital\n2.Modify Hospital\n3.Display\n4.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			if (h==0)
			{			
				add_hospital(head,outfile);
				h++;
			}
			else
			{
				printf("\nHospital already existing\n");
			}
				break;
		case 2:
			if(h!=0)
			{
			modify_hospital(head);
			}
			else
			{
				printf("\nHospital does not exist\n");
			}
			break;
		case 3:display(outfile,head);
			break;
		case 4:return SUCCESS;
		
		default:printf("\nInvalid choice");
	}
	}
}
/************************* End of hospital function *******************************/



/********************************************************************************
 * Function     validate_string
 * @date        OCT/16/2018
 * @brief       This function is used to check user entered only characters or not.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 ********************************************************************************/
int validate_string(char *str)
{
	
		for(int i=0;i<strlen(str);i++)
		{
			if(isalpha(str[i]) == 0)
			{
			
				printf("\nEnter valid string\n");
				return FAILURE;
			}

		}
	return SUCCESS;
	
}


/************************* End of validate_string function **********************/


/********************************************************************************
 * Function     validate_number
 * @date        OCT/16/2018
 * @brief       This function is used to check user entered only number or not.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 ********************************************************************************/
int validate_number(char *c)
{
	
	int i;
    	int found_letter = 0;
    	int len = strlen(c);

    	for( i = 0; i < len; i++)
   	 {
        	if(c[i] < '0' || c[i] > '9')
        	{
            		found_letter=1; // this variable works as a boolean
            		break;
        	}
   	 }
    	if(found_letter) // value 0 means false, any other value means true
	{
        	printf("\nPlease! Enter numbers only\n");
		return FAILURE;	
	}
    	else
	{
	
	return SUCCESS;
	}
}
/************************* End of validate_number function **********************/


/********************************************************************************
 * Function     print
 * @date        OCT/16/2018
 * @brief       This function is used to display departments which is added into
		linked list.
 * @return      None
 ********************************************************************************/
void print()
{
    	struct department *temp=root;

    	printf("\nList:");
    	while(temp!=NULL)
    	{
        		printf("\n%s ",temp->name);
			struct room *rm=root1;
			while(temp->rm!=NULL)
			{
			printf("\n%s ",temp->rm->room_id);
			printf("\n%s ",temp->rm->room_type);
			printf("\n%s ",temp->rm->no_of_beds);
			temp->rm=temp->rm->next;
			}
        		temp=temp->next;		
	}
}
/************************* End of print function *******************************/


/********************************************************************************
 * Function     insertatend1
 * @date        OCT/16/2018
 * @brief       This function is used to add rooms which is linked list and 
		data is inserted at the end of linked list.
 * @return      None
 ********************************************************************************/
void insertatend1(struct department *t)
{
	char *s;
	int size,i;
	t->rm=malloc(sizeof(struct room));
	
	while(1)
	{
	printf("\nEnter room_id: ");
    	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_number(s);
	if(i==0)
	{	
 	size=strlen(s);
	size++;
	t->rm->room_id=malloc(sizeof(char)*size);	
	strcpy(t->rm->room_id,s);
	free(s);
	break;
	}
	free(s);
	}
	
	printf("\nEnter room type: ");
    	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
 	size=strlen(s);
	size++;
	t->rm->room_type=malloc(sizeof(char)*size);	
	strcpy(t->rm->room_type,s);
	free(s);
	
	while(1)
	{

	printf("\nEnter no_of_beds: ");
    	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_number(s);
	if(i==0)
	{
 	size=strlen(s);
	size++;
	t->rm->no_of_beds=malloc(sizeof(char)*size);
	strcpy(t->rm->no_of_beds,s);
	free(s);
	break;
	}
	free(s);
	}
	
	t->rm->next=NULL;

		
    	if(root1==NULL)
    	{
        		//Executed only if root1 is NULL
        		//Executed only once i.e. when inserting first node
        		root1=t->rm;
        		end1=t->rm;
        		return;
    	}
    	end1->next=t->rm;
    	//Making last node point to newly created t->rm node

    	end1=t->rm;	


}
/************************* End of insertatend1 function **************************/

/********************************************************************************
 * Function     insertatend
 * @date        OCT/16/2018
 * @brief       This function is used to add departments which is linked list and 
		data is inserted at the end of linked list.
 * @return      None
 ********************************************************************************/
void insertatend()
{

	printf("\nEnter department name to insert at end of the list: ");
    	char *s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	struct department *temp = (struct department*)malloc(sizeof(struct department));
 	int size=strlen(s);
	size++;
	temp->name=malloc(sizeof(char)*size);
    	strcpy(temp->name,s);
	free(s);

	while(1)
		{

    		insertatend1(temp);
		char ch;
		printf("\nDo you want to stop entering rooms press [Y/y] :");
		scanf(" %c",&ch);
		if(ch == 'Y' || ch == 'y')
		{	
			break;
		}
		}

    	temp->next=NULL;

	
		
    	if(root==NULL)
    	{
        		//Executed only if head is NULL
        		//Executed only once i.e. when inserting first node
        		root=temp;
        		end=temp;
        		return;
    	}
    	end->next=temp;
    	//Making last node point to newly created temp node

    	end=temp;	
    	//Making newly created temp node as end node
}
/************************* End of insertatend function **************************/


/********************************************************************************
 * Function     add_hospital
 * @date        OCT/16/2018
 * @brief       hospital data taken from user and validate and store it into file.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 ********************************************************************************/
int add_hospital(struct hospital *p,FILE *outfile)
{
		int i,n,size,len;
		char *s;
    		
		outfile = fopen ("hospital.txt", "w");
   	 	if (outfile == NULL)
  	 	 {
       			 fprintf(stderr, "\nError opend file\n");
        		 return FAILURE;
   	 	 }
		
		while(1)
		{
		printf("Enter Hospital name : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		i=validate_string(s);
		if(i==0)
		{
		size=strlen(s);
		size++;
		p->name=malloc(sizeof(char)*size);
		strcpy(p->name,s);
		free(s);
		break;
		}
		free(s);
		}
		while(1)
		{
		printf("Enter hospital H-Number : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		i=validate_number(s);
		if(i==0)
		{
		size=strlen(s);
		size++;
		p->addr.hno=malloc(sizeof(char)*size);
		strcpy(p->addr.hno,s);
		free(s);
		break;
		}
		free(s);
		}

		while(1)
		{
		printf("Enter Street : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		i=validate_string(s);
		if(i==0)
		{
		size=strlen(s);
		size++;
		p->addr.street=malloc(sizeof(char)*size);
		strcpy(p->addr.street,s);
		free(s);
		break;
		}
		free(s);
		}

	
		while(1)
		{
		printf("Enter city : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		i=validate_string(s);
		if(i==0)
		{
		size=strlen(s);
		size++;
		p->addr.city=malloc(sizeof(char)*size);
		strcpy(p->addr.city,s);
		free(s);
		break;
		}
		free(s);
		}

		while(1)
		{
		printf("Enter State : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		i=validate_string(s);
		if(i==0)
		{
		size=strlen(s);
		size++;
		p->addr.state=malloc(sizeof(char)*size);
		strcpy(p->addr.state,s);
		free(s);
		break;
		}
		free(s);
		}

		while(1)
		{
		printf("Enter Pin Code : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		len=strlen(s);

		if(len!=6)
		{
			
			printf("\nPlease! Enter 6 digit Pin no.\n");
		}
		else
		{
		i=validate_number(s);
		if(i==0)
		{
		len++;
		p->addr.pin=malloc(sizeof(char)*len);
		strcpy(p->addr.pin,s);
		free(s);
		break;
		}
		}
		free(s);
		
		}


		/****************************************** Code for Department Link List ********************************/


	

		/* Insert data at the end of the singly linked list*/
		while(1)
		{

    		insertatend();
		char ch;
		printf("\nDo you want to stop entering departments press [Y/y] :");
		scanf(" %c",&ch);
		if(ch == 'Y' || ch == 'y')
		{	
			break;
		}
		}
		print();
		/*********************************************************************************************************/

		while(1)
		{
		printf("\nEnter Phone No : ");
		s = malloc(sizeof(char) * BUF_LEN);
		scanf("%s",s);
		len=strlen(s);

		if(len!=10)
		{	
			printf("\nPlease! Enter 10 digit Phone no.\n");
		}
		else
		{
		i=validate_number(s);
		if(i==0)
		{
			size++;
			p->phone_no=malloc(sizeof(char)*len);
			strcpy(p->phone_no,s);
			free(s);
			break;
		}
		}
		free(s);
		}
		
	
		fwrite (p, sizeof(struct hospital), 1, outfile);
		if(fwrite != 0)
		{ 
	       		 printf("contents to file written successfully !\n");
		}
    		else
		{
        		printf("error writing file !\n");
			return FAILURE;
		}

	
        	fclose(outfile);
	
	
	return SUCCESS;
}
/**************** End of add_hospital function ***********************************/



/********************************************************************************
 * Function     modify_hospital
 * @date        OCT/16/2018
 * @brief       modify hospital data just by calling add_hospital function and 
		erase previous data by opening file in write mode.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 ********************************************************************************/
int modify_hospital(struct hospital *p)
{
	root=NULL;
	int uid=123,UID;
	printf("Enter uid : ");
	scanf("%d",&UID);
	if(UID==uid)
	{
		fclose(fopen("hospital.txt", "w"));
		add_hospital(p,outfile);		
		
	}
	return SUCCESS;
}
/**************** End of modify_hospital function **************************/



/********************************************************************************
 * Function     display
 * @date        OCT/16/2018
 * @brief       hospital details will be displayed by this function.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *        
 ********************************************************************************/
int display(FILE *outfile,struct hospital *p)
{

	outfile = fopen ("hospital.txt", "r");
	printf("\nEntered in display.......\n");
   	 if (outfile == NULL)
  	  {
       		 printf("\nError opend file\n");
        	 return FAILURE;
   	  }

   	while (fread (p, sizeof(struct hospital), 1, outfile))
	{
	    printf("Hospital Name : %s \n", p->name); 
	    printf("Hospital No. : %s \n", p->addr.hno); 
	    printf("Street : %s \n", p->addr.street);
	    printf("City : %s \n", p->addr.city); 
	    printf("State : %s \n", p->addr.state); 
	    printf("Pin : %s \n", p->addr.pin); 
	   

    struct department *temp;

    /*
     * If the list is empty i.e. root = NULL
     */
    if(root == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = root;
        while(temp != NULL)
        {
            printf("Department Name : %s\n", temp->name); // Print data of current node
	    printf("\nno_of_beds : %s\n ",temp->rm->no_of_beds);
            printf("\nroom_type : %s\n",temp->rm->room_type);
	    printf("\nroom_id : %s\n ",temp->rm->room_id);
            temp = temp->next;                 // Move to next node
        }
    }
	  
	 printf("Phone No. : %s \n", p->phone_no); 
	}

    	fclose(outfile); 
	return SUCCESS;

}
/**************************** End of display function **************************/
