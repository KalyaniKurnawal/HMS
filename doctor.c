
/********* Include files **********/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


#define BUFFER 100
#define SUCCESS 0
#define FAILURE -1
#define  BUF_LEN 100
/******** global variable **********/

struct address
{
	char *hno;
	char *street;
	char *city;
	char *state;
	char *pin;
};

struct date
{
    int day;
    int month;
    int year;
    struct date* next;
};
struct doctor
{
	
	char *name;
	char *doctor_id;
	char *age;
	char *gender;
	char *qualification;
	char *speciality;
	char *bloodgroup;
	struct address addr;
	char *mail_id;
	char *phone_no;
	struct date *issue_date;
	char *salary;
	struct doctor *next;

};



struct doctor *head = NULL;
struct doctor *end=NULL;

/******* Prototypes ********/
int doctor1();
void display();
void add_doctor();
void add_to_file();
void data_from_file();


int doctor1()
{
	data_from_file();
	int choice;	
	while(1)
	{
	printf("\n***************  MENU *****************\n");
	printf("\n1.Add doctor\n2.display\n3.Exit\n");
	printf("\n***************************************\n");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			while(1)
			{

    				add_doctor();;
				char ch;
				printf("\nDo you want to stop press [Y/y] :");
				scanf(" %c",&ch);
				if(ch == 'Y' || ch == 'y')
				{	
					break;
				}

			}
			
			break;

		case 2:display();
			break;
		case 3:add_to_file();
			return SUCCESS;
		default:printf("\nInvalid choice");

	}
	}
}

void data_from_file()
{
    FILE *infile; 
    struct doctor *input; 
      
 
    infile = fopen ("newfile.txt", "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    // read file contents till end of file 
    while(fread(input, sizeof(struct doctor), 1, infile)) 
        printf ("name = %s\n",input->name); 
  
    // close file 
    fclose (infile); 


}

void add_to_file()
{
	FILE *fp;
	fp = fopen("newfile.txt", "w+");
	struct doctor *d;
	d=head;
	while(d!=NULL)
	{
		fwrite(d, 1, sizeof(struct doctor),fp);

		d=d->next;
	}
	fclose(fp);
	printf("\nContent to the file written successfully.......\n");
}
void display()
{
	struct doctor *p=head;
    	printf("\nDoctor List:");
			while(p!=NULL)
			{
					
					printf("\n------------------------------------------------------");

					printf("\nDr. NAme : %s",p->name);
	
					printf("\nDr. ID : %s",p->doctor_id);
	
					printf("\nDr. age : %s",p->age);

					printf("\nDr. gender : %s",p->gender);
	
	

					printf("\nDr. qualification : %s",p->qualification);
	
					printf("\nDr. speciality : %s",p->speciality);
	
					printf("\nDr. bloodgroup: %s",p->bloodgroup);



					printf("\nDr. House_No : %s",p->addr.hno);
					printf("\nAddress of Dr.");
					printf("\nStreet : %s",p->addr.street);

					printf("\nCity : %s",p->addr.city);

					printf("\nState : %s",p->addr.state);

					printf("\nPin : %s",p->addr.pin);

					printf("\nMail_id : %s",p->mail_id);
	
					printf("\nPhone_No : %s",p->phone_no);
					printf("\nDate of Joining : %d/%d/%d\n",p->issue_date->day,p->issue_date->month,p->issue_date->year);

					printf("\nsalary: %s",p->salary);
					printf("\n------------------------------------------------------");
				
				p=p->next;	
			}
}
int validate_no(char *c)
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
        	printf("\nYou entered a string\n");
		return 1;	
	}

	return 0;
}
int validate_gender(char *c)
{
	switch(c[0])
    	{
        case 'M':
        case 'm':
            break;
        case 'F':
        case 'f':
            break;
        default:
            printf("\nUnspecified Gender.\n");
		return 1;
    	}
	return 0;

}
int validate_bloodgroup(char *c)
{
	switch(c[0])
    	{
        case 'A':
        case 'a':
		switch(c[1])
		{
			case 'B':
			case 'b':
				switch(c[2])
				{
					case '+':
					case '-':
					break;
					default:printf("\nUnspecified Bloodgroup.\n");
					return 1;
				}
				break;
			case '+':
			case '-':
				break;
			default:printf("\nUnspecified Bloodgroup.\n");
				return 1;
		}
            break;
        case 'B':
		
        case 'b':
		switch(c[1])
		{
			case '+':
			case '-':
				break;
			default:printf("\nUnspecified Bloodgroup.\n");
				return 1;
		}
            break;
        case 'O':
        case 'o':
		switch(c[1])
		{
			case '+':
			case '-':
				break;
			default:printf("\nUnspecified Bloodgroup.\n");
				return 1;
		}

            break;
        default:
            printf("\nUnspecified Bloodgroup.\n");
		return 1;
    	}
	return 0;
}


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

int validate_date(int dd,int mm,int yy)
{

    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=28) && (mm==2))
                printf("Date is valid.\n");
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                printf("Date is valid.\n");
            else
	     {
                printf("Day is invalid.\n");
		return FAILURE;
	     }
        }
        else
        {
            printf("Month is not valid.\n");
	    return FAILURE;
        }
    }
    else
    {
        printf("Year is not valid.\n");
	return FAILURE;
    }
 
    return SUCCESS;
}


void add_doctor()
{
	char *s;
	int size,i,day,month,year;
	struct doctor *temp = (struct doctor*)malloc(sizeof(struct doctor));
	printf("\n******************* Add Doctor Details ********************\n");	
	
	while(1)
	{
	printf("Enter your name: ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_string(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->name=malloc(sizeof(char)*size);
    	strcpy(temp->name,s);
	free(s);
	break;
	}
	free(s);
	}

	while(1)
	{
	printf("Enter doctor_id : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	size=strlen(s);
	if(size>4)
	{	
		printf("\nPlease! Enter ID less than 4 digit\n");
	}
	else
	{
	i=validate_no(s);
	if(i==0)
	{
	size++;
	temp->doctor_id=malloc(sizeof(char)*size);
    	strcpy(temp->doctor_id,s);
	free(s);
	break;
	}
	}
	free(s);
	}




	while(1)
	{
	printf("Enter your age : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	size=strlen(s);
	if(size>2)
	{	
		printf("\nPlease! Enter valid age.\n");
	}
	else
	{
	i=validate_no(s);
	if(i==0)
	{
	size++;
	temp->age=malloc(sizeof(char)*size);
    	strcpy(temp->age,s);
	free(s);
	break;
	}
	}
	free(s);
	}



	while(1)
	{
	printf("Enter gender : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_gender(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->gender=malloc(sizeof(char)*size);
    	strcpy(temp->gender,s);
	free(s);
	break;
	}
	free(s);
	}


	while(1)
	{
	printf("Enter qualification : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_string(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->qualification=malloc(sizeof(char)*size);
    	strcpy(temp->qualification,s);
	free(s);
	break;
	}
	free(s);
	}


	while(1)
	{
	printf("Enter speciality : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_string(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->speciality=malloc(sizeof(char)*size);
    	strcpy(temp->speciality,s);
	free(s);
	break;
	}
	free(s);
	}


	while(1)
	{	
	printf("Enter bloodgroup: ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_bloodgroup(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->bloodgroup=malloc(sizeof(char)*size);
    	strcpy(temp->bloodgroup,s);
	free(s);
	break;
	}
	free(s);
	}

	while(1)
	{	
	printf("Enter House_No : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	size=strlen(s);
	if(size>3)
	{	
		printf("\nPlease! Enter 3 digit House no.\n");
	}
	else
	{
	i=validate_no(s);
	if(i==0)
	{
	size++;
	temp->addr.hno=malloc(sizeof(char)*size);
    	strcpy(temp->addr.hno,s);
	free(s);
	break;
	}
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
	temp->addr.street=malloc(sizeof(char)*size);
    	strcpy(temp->addr.street,s);
	free(s);
	break;
	}
	free(s);
	}


	while(1)
	{	
	printf("Enter City : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_string(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->addr.city=malloc(sizeof(char)*size);
    	strcpy(temp->addr.city,s);
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
	temp->addr.state=malloc(sizeof(char)*size);
    	strcpy(temp->addr.state,s);
	free(s);
	break;
	}
	free(s);
	}


	while(1)
	{	
	printf("Enter Pin : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	size=strlen(s);
	if(size!=6)
	{	
		printf("\nPlease! Enter 6 digit Pin no.\n");
	}
	else
	{
	i=validate_no(s);
	if(i==0)
	{
	size++;
	temp->addr.pin=malloc(sizeof(char)*size);
    	strcpy(temp->addr.pin,s);
	free(s);
	break;
	}
	}
	free(s);
	}


	while(1)
	{	
	printf("Enter Mail_id : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	i=validate_string(s);
	if(i==0)
	{
	size=strlen(s);
	size++;
	temp->mail_id=malloc(sizeof(char)*size);
    	strcpy(temp->mail_id,s);
	free(s);
	break;
	}
	free(s);
	}


	while(1)
	{		
	printf("Enter Phone_No : ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	size=strlen(s);
	if(size!=10)
	{	
		printf("\nPlease! Enter 10 digit Phone no.\n");
	}
	else
	{
	i=validate_no(s);
	if(i==0)
	{
	size++;
	temp->phone_no=malloc(sizeof(char)*size);
    	strcpy(temp->phone_no,s);
	free(s);
	break;
	}
	}
	free(s);
	}
	/***************Date********************/
	while(1)
	{
    	printf("Issue date: day\n");
    	scanf("%d",&day);
    	printf("Issue date: month\n");
    	scanf("%d",&month);
    	printf("Issue date: year\n");
    	scanf("%d",&year);
	i=validate_date(day,month,year);
	if(i==0)
	{
   	temp->issue_date = malloc(sizeof(struct date));
	temp->issue_date->day = day;
    	temp->issue_date->month = month;
    	temp->issue_date->year = year;
    	temp->issue_date->next = NULL;
	break;
	}
	}
	while(1)
	{	
	printf("Enter salary: ");
	s = malloc(sizeof(char) * BUF_LEN);
	scanf("%s",s);
	size=strlen(s);
	if(size>10)
	{	
		printf("\nPlease! Enter valid salary.\n");
	}
	else
	{
	i=validate_no(s);
	if(i==0)
	{

	size++;
	temp->salary=malloc(sizeof(char)*size);
    	strcpy(temp->salary,s);
	free(s);
	break;
	}
	}
	free(s);
	}
	

	temp->next=NULL;

	if(head==NULL)
    	{
        		//Executed only if head is NULL
        		//Executed only once i.e. when inserting first node
        		head=temp;
        		end=temp;
        		return;
    	}
    	end->next=temp;
    	//Making last node point to newly created temp node

    	end=temp;	
    	//Making newly created temp node as end node

		while(1)
		{

    		
		char ch;
		printf("\nDo you want to stop press [Y/y] :");
		scanf(" %c",&ch);
		if(ch == 'Y' || ch == 'y')
		{	
			break;
		}

			add_doctor();
 		
		}
	return;

}



int main()
{	

	doctor1();
	return SUCCESS;
}

