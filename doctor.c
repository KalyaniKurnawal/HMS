
/********* Include files **********/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/******** global variable **********/

struct address
{
	int hno;
	char street[10];
	char city[10];
	char state[10];
	char pin[6];
};


struct doctor
{
	
	char name[10];
	int doctor_id;
	int age;
	char gender[1];
	char qualification[10];
	char speciality[10];
	char bloodgroup[3];
	struct address addr;
	char mail_id[10];
	char phone_no[10];
	char date_of_join[10];
	double salary;
struct doctor *next;

};



struct doctor *head = NULL;
#define SUCCESS 0

/******* Prototypes ********/
int doctor();
int add_doctor(struct doctor *,FILE*);
int modify_doctor();
int search_doctor();
int all_doctor_details();
int delete_doctor();
int display(struct doctor *,FILE*);



int doctor()
{
	int choice;
	struct doctor *ptr = NULL;
	ptr  = (struct doctor *)malloc(sizeof(struct doctor));
	
	FILE *outfile,*infile;
	
	head = ptr;
	printf("1.Add doctor\n2.Modify doctor details\n3.Search doctor\n4.All doctor details\n5.Delete doctor record\n6.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:add_doctor(ptr,outfile);
			display(ptr,infile);
			break;
		case 2:modify_doctor();
			break;
		case 3:serach_doctor();
			break;
		case 4:all_doctor_details();
			break;
		case 5:delete_doctor();
			break;
		case 6:return SUCCESS;
		default:printf("\nInvalid choice");

	}

}
int add_doctor(struct doctor *p,FILE *outfile)
{
	int val;
	char ch;

	outfile = fopen ("doctor.dat", "a");
   	 if (outfile == NULL)
  	  {
       		 fprintf(stderr, "\nError opend file\n");
        	 return SUCCESS;
   	  }
	printf("\n******************* Add Doctor Details ********************\n");	

	printf("Enter your name: ");
	scanf("%s",p->name);
	printf("Enter doctor_id : ");
	scanf("%d",&(p->doctor_id));
	
	printf("Enter your age : ");
	scanf("%d",&(p->age));
	getchar();
	printf("Enter gender : ");
	scanf("%s",p->gender);
	
	
	printf("Enter qualification : ");
	scanf("%s",p->qualification);
	printf("Enter speciality : ");
	scanf("%s",p->speciality);
	printf("Enter bloodgroup: ");
	scanf("%s",p->bloodgroup);


	printf("Enter House_No : ");
	scanf("%d",&(p->addr.hno));
	printf("Enter Street : ");
	scanf("%s",p->addr.street);
	printf("Enter City : ");
	scanf("%s",p->addr.city);
	printf("Enter State : ");
	scanf("%s",p->addr.state);
	printf("Enter Pin : ");
	scanf("%s",p->addr.pin);




	printf("Enter Mail_id : ");
	scanf("%s",p->mail_id);
	printf("Enter Phone_No : ");
	scanf("%s",p->phone_no);
	printf("Enter date_of_join: ");
	scanf("%s",p->date_of_join);
	printf("Enter salary: ");
	scanf("%lf",&(p->salary));
	p->next = NULL;
	

	fwrite (p->name, sizeof(struct doctor), 1, outfile);
	if(fwrite != 0)
	{ 
	        printf("contents to file written successfully !\n");
	}
    	else
	{
        	printf("error writing file !\n");
	}

	
    	fclose(outfile);
	printf("\nDo you want to continue press [y] :");
	scanf(" %c",&ch);
	if(ch == 'y'|| ch == 'Y')
	{	
		struct doctor *p1= NULL;
		p1  = (struct doctor *)malloc(sizeof(struct doctor));
		p->next=p1;
		add_doctor(p1,outfile);
	}
	
}

int modify_doctor()
{
	return SUCCESS;
}

int serach_doctor()
{
	int choice;
	printf("1.Search by name\n2.Search by id\n3.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:search_by_name();
			break;
		case 2:search_by_id();
			break;
		case 3:return SUCCESS;
		default:printf("\n Inavalid choice");
	}
	return SUCCESS;
}

int search_by_name()
{
	return SUCCESS;
}

int search_by_id()
{
	return SUCCESS;
}
int all_doctor_details()
{
	return SUCCESS;
}

int delete_doctor()
{
	return SUCCESS;
}

int main()
{
	doctor();
	return SUCCESS;
}

int display(struct doctor *p,FILE *infile)
{
	printf("\n***********  Details of all doctors  *********************\n");


	infile = fopen ("doctor.dat", "r");
    	if (infile == NULL)
    	{
        	fprintf(stderr, "\nError opening file\n");
        	return SUCCESS;
    	}
	while(fread(p,sizeof(struct doctor), 1, infile))
	{
		printf("\n%s\n%d\n%d\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%lf",p->name,p->doctor_id,p->age,p->gender,p->qualification,p->speciality,p->bloodgroup,p->addr.hno,p->addr.street,p->addr.city,p->addr.state,p->addr.pin,p->mail_id,p->phone_no,p->date_of_join,p->salary);
		printf("\n|-------------------------------------------------------------------------------\n");
	}
	
	fclose(infile);
   	return SUCCESS;  
}
