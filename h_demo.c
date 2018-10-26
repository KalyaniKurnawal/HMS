/********** Include files ************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/********* Global Variables **********/
struct address
{
	int hno;
	char street[10];
	char city[10];
	char state[10];
	char pin[6];
};

struct hospital
{
	char name[10];
	struct address addr;
	char phone_no[10];
	char department[10];
	struct hospital *next;
};

int h=0;
struct hospital *head = NULL;

#define SUCCESS 0
/************ Prototypes *************/
int hospital();
int add_hospital(struct hospital*,FILE*);
int delete_hospital();
int modify_hospital();



int main()
{
	hospital();
	return 0;
}

int hospital()
{
	int choice;

	struct hospital *ptr = NULL;
	ptr  = (struct hospital *)malloc(sizeof(struct hospital));

	head = ptr;
	while(1)
	{
	printf("1.Add Hospital\n2.Delete Hospital\n3.Modify Hospital\n4.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			head = ptr;
			strcpy(head->name," ");
			FILE *outfile;
			add_hospital(ptr,outfile);
			h++;
			break;
		case 2:delete_hospital();
			break;
		case 3:modify_hospital();
			break;

		case 4:return SUCCESS;
		default:printf("\nInvalid choice");
	}
	}
}


int add_hospital(struct hospital *p,FILE *outfile)
{
	int size;
	 outfile = fopen ("hospital.dat", "r");
   	 if (outfile == NULL)
  	  {
       		 fprintf(stderr, "\nError opend file\n");
        	 exit (1);
   	  }
	if (NULL != outfile) 
	{
   	 	fseek (outfile, 0, SEEK_END);
    		size = ftell(outfile);

    		if (0 == size) 
		{
       		 	printf("file is empty\n");
			h=0;
    		}
		else
		{
			h=1;
			printf("Hospital is already exist\n");
		}
	}
	if(h==0)
	{
   	 	// open file for writing
		outfile = fopen ("hospital.dat", "w");
   	 	if (outfile == NULL)
  	 	 {
       			 fprintf(stderr, "\nError opend file\n");
        		 exit (1);
   	 	 }
		printf("Enter Hospital name : ");
		scanf("%s",p->name);
		printf("Enter hospital H-Number : ");
		scanf("%d",&(p->addr.hno));
		printf("Enter Street : ");
		scanf("%s",p->addr.street);
		printf("Enter city : ");
		scanf("%s",p->addr.city);
		printf("Enter State : ");
		scanf("%s",p->addr.state);
		printf("Enter Pin Code : ");
		scanf("%s",p->addr.pin);
		printf("Enter Phone No : ");
		scanf("%s",p->phone_no);
		printf("Enter Department : ");
		scanf("%s",p->department);
	
		p->next = NULL;
	
		fwrite (p->name, sizeof(struct hospital), 1, outfile);
		if(fwrite != 0)
		{ 
	       		 printf("contents to file written successfully !\n");
		}
    		else
		{
        		printf("error writing file !\n");
		}

	
        	fclose(outfile);
	}
	
	return SUCCESS;
}


int delete_hospital()
{
	fclose(fopen("hospital.dat", "w"));
	return SUCCESS;
}

int modify_hospital()
{
	int uid=123,UID;
	printf("Enter uid : ");
	scanf("%d",&UID);
	if(UID==uid)
	{
		fclose(fopen("hospital.dat", "w"));

		struct hospital *ptr = NULL;
		ptr  = (struct hospital *)malloc(sizeof(struct hospital));
		head = ptr;
		strcpy(head->name," ");
		FILE *outfile;
		add_hospital(ptr,outfile);
		h++;		
		
	}
	return SUCCESS;
}

