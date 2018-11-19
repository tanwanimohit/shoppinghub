#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
#include <dirent.h>
#include <windows.h>
void login();
void signup();
void seepro();
void searchpro(char Mobile_no[11]);
void purchase();
void searchpro2(char Mobile_no[11]);
void purchase(char Mobile_no[20]);
void forgetpassword();
void home(char Mobile_no[20]);
void profile(char Mobile_no[20]);
char *pathcat(const char *str1, char *str2);
void displaypro(char path[50],char Mobile_no[11],char pname[20]);
int printStrongNess(char *input);
char *getprice(char path[50]);
void updorder(char path[50],char Mobile_no[11],char pname[20]);
void urorder(char Mobile_no[11]);
void topdeals();
void main()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	int choice;
	while(choice!=4)
	{
		printf("\nChoose from Below Options...");
		printf("\n1. Login");
		printf("\n2. Signup");
		printf("\n3. Forget Password");
		printf("\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: login(); 
					break;
			case 2: signup(); 
					break;
			case 3: forgetpassword(); 
					break;
			case 4: printf("Thankyou for Using Blahblah.. Exiting.."); 
					break;
			default: printf("Ahh! Wrong Input.. Retry !");
					break;
		}
	}
	
}
void login()
{
	printf("\n\n--Login--\n\n");
	char Mobile_no[11]="\0",maind[20]="Users\\",Password[20];
	int count=0,temp;
	retryMobile:
	
	printf("\nEnter Your Mobile Number : ");
	scanf("%s",&Mobile_no);
	if(strlen(Mobile_no)<10)
	{
		printf("Wrong Mobile No.Retry... ");
		goto retryMobile;
	}
	strcat(maind,Mobile_no);
	if( access( maind, F_OK ) != -1 ) {
    	
		printf("\nEnter Your Password : ");
		FILE *file=fopen(maind,"r");
		char line[256],*p,pass[20]="\0";
	    int i = 0;
	    while (fgets(line, sizeof(line), file)) {
	        i++;
	        if(i == 4 )
	        {
	            break;   
	        }
	    }
    	i=0;
		p = strtok (line,"=");
		while (p!= NULL)
		{
			
		    strcpy(pass,p);
		    p = strtok (NULL, "="); 
		}
	//	printf("%s %d",pass,strlen(pass));
		
		retrypass:
		if(count<4)
		{
			fflush(stdin);
			gets(Password);
			strcat(Password,"\n");
			temp=strcmp(Password,pass);
		//	printf("%d",temp);
			if(temp==0)
			{
				
				home(Mobile_no);
			}
			else
			{
				
				printf("\nWrong Password :( Retry..\n");
				count++;
				goto retrypass;
			}
		}
		else
		{
			printf("\nMaximum Retry Reached :( ");
		}
			
	}
	else
	{
		printf("\nNo Record Found :( Go and Register Yourself...");
	}
}
void signup()
{
	printf("\n\n--SignUp--\n\n");
	
	char maind[20]="Users\\",Fname[20]="\0",Lname[20]="\0",emailid[20]="\0",address[30]="\0",password[50]="\0",Mobile_no[11]="\0",day[3]="\0",month[3]="\0",year[5]="\0",orders[20]="\0";
	int res,email1=0,email2=0,i;
	retryMobile:
	printf("\nEnter Your Mobile Number : ");
	scanf("%s",&Mobile_no);
	if(strlen(Mobile_no)<10)
	{
		printf("Wrong Mobile No.Retry... ");
		goto retryMobile;
	}
	strcat(maind,Mobile_no);
	if( access( maind, F_OK ) != -1 ) {
    	printf("\nMobile Already exists..");
    	
	} else {
	    FILE *in_file=fopen(maind,"w");
	    printf("\nA password is said to be strong if it satisfies the following criteria \n\n1. It contains at least one lowercase English character.\nIt contains at least one uppercase English character.\nIt contains at least one special character. The special characters are: !@#$%^&*()-+\nIts length is at least 8.\nIt contains at least one digit.\n\n");
	    //Retry Password Label...
		retrypass:
		printf("\nEnter Your Password : ");
		scanf("%s",password);
	    
	    res=printStrongNess(password);
	    
	    if(res==1)
	    {
	    	printf("\nRetry :( ");
	    	goto retrypass;
		}
		printf("\nEnter Your FirstName : ");
		scanf("%s",Fname);
		printf("\nEnter Your LastName : ");
		scanf("%s",Lname);
		retryEmail:
		printf("\nEnter Your Email-ID : ");
		scanf("%s",emailid);
		for(i=0; i<strlen(emailid); i++)
		{
			if(emailid[i]=='@')
			{
				email1=1;
			}
			if(emailid[i]=='.')
			{
				email2=1;
			}
		}
		if(email1==0 || email2==0)
		{
			printf("Wrong Input.. Retry..");
			goto retryEmail;
		}
		
		
		
		printf("\nEnter Your Date of Birth :");
		printf("\nEnter Date : ");
		scanf("%s",day);
		printf("Enter Month : ");
		scanf("%s",month);
		printf("Enter Year : ");
		scanf("%s",year);
		
		fflush(stdin);
		printf("\nEnter Your Address :\n");
		gets(address);
		
		
		fprintf(in_file,"First Name =%s\n",Fname);
		fprintf(in_file,"Last Name =%s\n",Lname);
		fprintf(in_file,"Mobile No =%s\n",Mobile_no);
		fprintf(in_file,"Password =%s\n",password);
		fprintf(in_file,"Email ID =%s\n",emailid);
		fprintf(in_file,"Day=%s\n",day);
		fprintf(in_file,"Month=%s\n",month);
		fprintf(in_file,"Year=%s\n",year);
		fprintf(in_file,"Address=%s\n",address);
		
		fclose(in_file);
		strcpy(orders,maind);
		strcat(orders,"_orders");
		printf("\nRegistration SuccessFull :) \n");
		FILE *in_file2=fopen(orders,"w");
		fclose(in_file2);
		FILE *upd=fopen("users.txt","a");
		fprintf(upd,"%s %s %s %s %s %s \n",Mobile_no,Fname,Lname,emailid,password,address);
		
		fclose(upd);
	}
	
	
	
}
void forgetpassword()
{
	printf("\n\n--Forget Password--\n\n");
	
	char Mobile_no[11]="\0",Password[20],day[3]="\0",month[3]="\0",year[5]="\0",s1[10]="\0",s2[10]="\0",s3[10]="\0",ss1[3]="\0",ss2[3]="\0",ss3[5]="\0",password[50]="\0",pass[20],maind[30]="Users\\";
	int count=0,res;
	retryMobile:
	printf("\nEnter Your Mobile Number : ");
	scanf("%s",&Mobile_no);
	if(strlen(Mobile_no)<10)
	{
		printf("Wrong Mobile No.Retry... ");
		goto retryMobile;
	}
	strcat(maind,Mobile_no);
	if( access( maind, F_OK ) != -1 ) {
    	
		printf("\nTo Change your Password You Need to Verify yourself for That Date of Birth :");
		printf("\nEnter Date : ");
		scanf("%s",day);
		printf("Enter Month : ");
		scanf("%s",month);
		printf("Enter Year : ");
		scanf("%s",year);
		
		FILE *file=fopen(maind,"r");
		char line[256],*p,pass[20]="\0";
	    int i = 0;
	    while (fgets(line, sizeof(line), file)) {
	        i++;
	        
	        if(i==4)
	        {
	        	strcpy(pass,line);
			}
	        if(i == 6 )
	        {
	            strcpy(s1,line);   
	        }
	        if(i == 7 )
	        {
	            strcpy(s2,line);   
	        }
	        if(i == 8 )
	        {
	            strcpy(s3,line);   
	        }
	    }
	    ss1[0]=s1[4];
	    ss1[1]=s1[5];
	    
		ss2[0]=s2[6];
		ss2[1]=s2[7];
		
		ss3[0]=s3[5];
		ss3[1]=s3[6];
		ss3[2]=s3[7];
		ss3[3]=s3[8];
		fclose(file);
		//printf("day : %s %s , month : %s %s , year : %s %s ",ss1,day,ss2,month,ss3,year);
		if(strcmp(ss1,day)==0)
		{
			if(strcmp(ss2,month)==0)
			{
				int t3=strcmp(ss3,year);
				if(t3==0)
				{
					printf("Your %s ",strcpy(s1,pass));
				}
				else
				{
					printf("Failed3 %d ",strcmp(ss3,year));
				}
				
			}
			else
			{
				printf("Failed2");
			}
		}
		else
		{
			printf("Failed1 %d",strcmp(ss1,day));
		}
			
	}
	else
	{
		printf("\nNo Record Found :( Go and Register Yourself...");
	}
	
}
void home(char Mobile_no[20])
{
	printf("\n\n--Dashboard--\n\n");
	int choice,choiced;
	while(choice!=7)
	{
		printf("\nChoose from Below Options...");
		printf("\n1. Profile");
		printf("\n2. Top Deals");
		printf("\n3. Search Product");
		printf("\n4. Choose Product By Category");
		printf("\n5. Purchase an Item");
		printf("\n6. Your Orders");
		printf("\n7. Logout\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: profile(Mobile_no); 
					break;
			case 4: seepro(Mobile_no);
					break;
			case 3: searchpro(Mobile_no);
					break;
			case 2: topdeals();
					printf("Want to Purchase Product ? Type 1");
					scanf("%d",&choiced);
					if(choiced==1)
					{
						purchase(Mobile_no);
					}
					break;
			case 5: purchase(Mobile_no);
					break;
			case 6: urorder(Mobile_no);
					break;				
			case 7: printf("See you Soon.... Byee..."); 
					break;
					
			default: printf("Ahh! Wrong Input.. Retry !");
					break;
		}
	}
}
int printStrongNess(char *password) 
{ 
    int digitflag=0;
    int res=0;
	int upperflag=0;
	int lowerflag=0;
	int i;
	if(strlen(password)<8)
	{
	printf("Length is less than 8");
	res=1;
	}
	else
	{
	    for(i=0;i<strlen(password);i++)
	        {
	           if(isdigit(password[i]))
	           digitflag=1;
	           if(isupper(password[i]))
	           upperflag=1;
	           if(islower(password[i]))
	           lowerflag=1;
	        }
	      if(digitflag==0)
	      {
			printf("No digits\n");
			res=1;
		  }
	      if(upperflag==0)
	      {
	      	printf("No Upper Case Letters\n");
			res=1;
		  }
	      
	      if(lowerflag==0)
	      {
	      	printf("No Lower Case Letters\n");
			res=1;
		  }
	      
	}
	
	if(res==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void profile(char Mobile_no[20])
{
	printf("\n\n---Profile----\n\n");
	char maind[50]="Users\\";
	strcat(maind,Mobile_no);
	FILE *file=fopen(maind,"r");
		char line[256],*p,pass[20]="\0";
	   
	    while (fgets(line, sizeof(line), file)) {
	        
	        printf("%s",line);
	    }
}

void seepro(char Mobile_no[20])
{
	printf("\n\nCategories\n\n");
	system("dir .\\Products /b");
	printf("\n\n");
	int choice;
	char pname[20]="dir .\\Products\\";
	char name[20],maind[20]="Products\\";
	first:
	maind[9]='\0';
	printf("Enter Category Name to see all Products :- ");
	scanf("%s",name); 
    strcat(maind,name);
	
	if( access( maind, F_OK ) != -1 ) {
    	printf("\n\nProducts Inside %s Category \n\n",name);
    	strcat(pname,name);
    	strcat(pname," /b");
		system(pname);
		printf("\nWant to See Information of Product ? Type 1 Or Type any Key to End : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			searchpro2(Mobile_no);
		}
    	else
    	{
    		
		}
	}
	else
	{
		printf("\nCategory Not Found ");
		goto first;
	}
}
void searchpro(char Mobile_no[20])
{
	char pname[20]="\0",maind[50]="\0";
	printf("\nEnter Product Name : ");
	scanf("%s",&pname);
    struct dirent *dp;
    char *fullpath;
    int i=0,ss=0,choice;
    FILE *file;
    const char *path="Products\\"; // Directory target
    DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
    while (dp=readdir(dir)) // if dp is null, there's no more content to read
    {
    	maind[0]='\0';
        fullpath = pathcat(path, dp->d_name);
        //printf("%s\n", fullpath);
    	if(i>=2)
    	{
    		strcat(maind,fullpath);
    		strcat(maind,"\\");
    		strcat(maind,pname);
    		if( access( maind, F_OK ) != -1 ) {
    			//printf("%s",maind);
    			printf("\nProduct Found ! ");
    			ss=1;
    			printf("\nWant to Checkout its Details? Type 1 to See... ");
    			scanf("%d",&choice);
    			if(choice==1)
    			{
    				printf("\n");
					displaypro(maind,Mobile_no,pname);
    				
    				break;
				}
				else
				{
					break;
				}
			
			}
		}
		free(fullpath);
		i++;
    }
    closedir(dir); // close the handle (pointer)
    if(ss==0)
    {
    	printf("\nProduct Not Found ! \n");
	}

}

void searchpro2(char Mobile_no[20])
{
	char pname[20]="\0",maind[50]="\0";
	printf("\nEnter Product Name : ");
	scanf("%s",&pname);
    struct dirent *dp;
    char *fullpath;
    int i=0,ss=0,choice;
    FILE *file;
    const char *path="Products\\"; // Directory target
    DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
    while (dp=readdir(dir)) // if dp is null, there's no more content to read
    {
    	maind[0]='\0';
        fullpath = pathcat(path, dp->d_name);
        //printf("%s\n", fullpath);
    	if(i>=2)
    	{
    		strcat(maind,fullpath);
    		strcat(maind,"\\");
    		strcat(maind,pname);
    		if( access( maind, F_OK ) != -1 ) {
    			//printf("%s",maind);
    			//printf("\nProduct Found ! ");
    			ss=1;
    			
					displaypro(maind,Mobile_no,pname);
    				
    				break;
			
			
			}
		}
		free(fullpath);
		i++;
    }
    closedir(dir); // close the handle (pointer)
    if(ss==0)
    {
    	printf("\nWrong Input, Product Not Found ! \n");
	}

}

void displaypro(char path[50],char Mobile_no[11],char pname[20])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE *file=fopen(path,"r");
		char line[256],*price,pass[20]="\0";
		int choice;
	   
	    while (fgets(line, sizeof(line), file)) {
	        
	        printf("%s",line);
	    }
	    printf("\n");
	    printf("Inside yo... %s %s\n",Mobile_no,pname);
	    printf("\nTo Purchase this Order Type 1 Or to Cencel type any Key...  ");
	    scanf("%d",&choice);
	    
		if(choice==1)
	    {
	    	FILE *upd=fopen("orders.txt","a");
			price=getprice(path);
			
			fprintf(upd,"%s %s %d-%d-%d %d:%d:%d %s \n",Mobile_no,pname,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,price);
			fclose(upd);
			updorder(price,Mobile_no,pname);
			printf("\n\nPurchase Sucess\n\n");
			
		}
		else
		{
			
		}
}

char *pathcat(const char *str1, char *str2)
{
    char *res;
    size_t strlen1 = strlen(str1);
    size_t strlen2 = strlen(str2);
    int i, j;
    res = malloc((strlen1+strlen2+1)*sizeof *res);
    strcpy(res, str1);
    for (i=strlen1, j=0; ((i<(strlen1+strlen2)) && (j<strlen2)); i++, j++)
        res[i] = str2[j];
    res[strlen1+strlen2] = '\0';
    return res;
}

void purchase(char Mobile_no[20])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char pname[20]="\0",maind[50]="\0",*price;
	printf("\nEnter Product Name to Purchase : ");
	scanf("%s",&pname);
    struct dirent *dp;
    char *fullpath;
    int i=0,ss=0,choice;
    FILE *file;
    const char *path="Products\\"; // Directory target
    DIR *dir = opendir(path); // Open the directory - dir contains a pointer to manage the dir
    while (dp=readdir(dir)) // if dp is null, there's no more content to read
    {
    	maind[0]='\0';
        fullpath = pathcat(path, dp->d_name);
        //printf("%s\n", fullpath);
    	if(i>=2)
    	{
    		strcat(maind,fullpath);
    		strcat(maind,"\\");
    		strcat(maind,pname);
    		if( access( maind, F_OK ) != -1 ) {
    			//printf("%s",maind);
    			printf("\nProduct Found ! ");
    			ss=1;
    			printf("\nWant to Checkout its Details? Type 1 Or to Direct Purchase Type 2 or Type any key to Cencel...  ");
    			scanf("%d",&choice);
    			if(choice==1)
    			{
    				printf("\n");
					displaypro(maind,Mobile_no,pname);
    				
    				break;
				}
				if(choice==2)
				{
					FILE *upd=fopen("orders.txt","a");
					price=getprice(maind);
					fprintf(upd,"%s %s %d-%d-%d %d:%d:%d %s \n",Mobile_no,pname,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,price);
					fclose(upd);
					updorder(price,Mobile_no,pname);
					printf("\n\nPurchase Sucess\n\n");
					
				}
				else
				{
					break;
				}
			
			}
		}
		free(fullpath);
		i++;
    }
    closedir(dir); // close the handle (pointer)
    if(ss==0)
    {
    	printf("\nProduct Not Found ! \n");
    	
	}
}
char *getprice(char path[50])
{
	FILE *file=fopen(path,"r");
	char line[256]="\n",*p,*price, *token;
	   
    while (fgets(line, sizeof(line), file)) { 
	    
	}
	token=strtok(line,"=");
	while (token != NULL) { 
        price=token; 
        token = strtok(NULL, "-"); 
    }

	return (char *)price;
}
void updorder(char price[50],char Mobile_no[11],char pname[20])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char Mobile[20]="Users\\";
	strcat(Mobile,Mobile_no);
	strcat(Mobile,"_orders");
	FILE *upd=fopen(Mobile,"a");
	
	fprintf(upd,"%s %s %d-%d-%d %d:%d:%d %s \n",Mobile_no,pname,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,price);
	fclose(upd);
	
	
}
void urorder(char Mobile_no[11])
{
	int size;
	char Mobile[20]="Users\\";
	char line[256],*p,pass[20]="\0";
	strcat(Mobile,Mobile_no);
	strcat(Mobile,"_orders");
	FILE *file=fopen(Mobile,"r");
	fseek(file, 0, SEEK_END);
    size = ftell(file);
    if(size==0)
    {
    	printf("\nOrders not Found ! \n");
	}
	else
	{
		fseek(file, 0, SEEK_SET);
		printf("\n------------------------------------------\n");
		printf("\nMobile_no\tProduct_Name\tDate&Time\n\n");
		printf("\n------------------------------------------\n");
		while (fgets(line, sizeof(line), file))
		{
			printf("%s",line);
		}
	}
	
}
void topdeals()
{
	char line[256],*token,buyfile[100][20];
	int count=0,size=1;
	FILE *file=fopen("topdeals.txt","r");
	fseek(file, 0, SEEK_END);
    size = ftell(file);
    if(size==0)
    {
    	printf("\nNo Top Deals Found ! \n");
	}
	else
	{
		fseek(file, 0, SEEK_SET);
		printf("\n------------------------------------------\n");
		printf("\nProductName\tDescription\t       Price\n\n");
		printf("\n------------------------------------------\n");
		while (fgets(line, sizeof(line), file))
		{
			printf("%s",line);

		}
	}
	
}
