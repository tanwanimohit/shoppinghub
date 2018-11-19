#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>
#include <windows.h>
#include <dirent.h>
#include <dir.h> 
#include<time.h>
#include <process.h> 
void dashboard();
void adddeal();
char *getprice(char path[50]);
char *getdesc(char path[50]);
void category();
void deletecat();
void addpro();
void delpro();
void searchpro();
char *pathcat(const char *str1, char *str2);
void displaypro(char path[50]);
void seecat();
void profile();
void seepro();
void allusers();
void allorders();
char* deblank(char* input);
void deltopdeals();
void main()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	char pass[20];
	printf("Please Enter Admin Password to Access the Admin Panel :- ");
	retry:	
	scanf("%s",&pass);
	if(strcmp(pass,"Admin007"))
	{
		printf("Wrong Password :( Try Again... ");
		goto retry;	
	}
	else
	{
		dashboard();
	}
}
void dashboard()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	printf("\n\n--Dashboard--\n\n");
	int choice;
	while(choice!=13)
	{
		printf("\n\nChoose from Below Options...");
		printf("\n1. Add Product Category ");
		printf("\n2. Add Product ");
		printf("\n3. See All Products");
		printf("\n4. See All Categories");
		printf("\n5. Remove Category");
		printf("\n6. Delete Product");
		printf("\n7. See All Users");
		printf("\n8. Show User Information");
		printf("\n9. See Product Information/Search Product");
		printf("\n10.See All Orders");
		printf("\n11.Add New Top Deal");
		printf("\n11.Clear Top Deals");
		printf("\n13. Logout\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: category();
					break;
			case 2: addpro();
					break;
			case 3: seepro();
					break;
			case 4: seecat();
					break;
			case 5: deletecat();
					break;
			case 6: delpro();
					break;
			case 7: allusers();
					break;		
			case 8: profile();
					break;
			case 9: searchpro();
					break;
			case 10: allorders();
					break;
			case 11: adddeal();
					break;
			case 12: deltopdeals();
					break;						
			case 13: printf("See you Soon.... Byee..."); 
					break;
			default: printf("Ahh! Wrong Input.. Retry !");
					break;
		}
	}
}
void deltopdeals()
{
	printf("\nTop Deals Cleared ! \n");
	system("del topdeals.txt");
	system("type NUL > topdeals.txt");
}
void category()
{
	int check; 
    char name[20],maind[20]="Products\\";
	printf("Enter New Category Name :- ");
	scanf("%s",name); 
    strcat(maind,name); 
  
    check = mkdir(maind); 
  
    // check if directory is created or not 
    if (!check) 
        printf("Category created\n"); 
    else { 
        printf("Unable to create Category \n"); 
        
    } 
}
void seecat()
{
	printf("\n\nCategories\n\n");
	system("dir .\\Products /b");	
	
}

void seepro()
{
	printf("\n\nCategories\n\n");
	system("dir .\\Products /b");
	printf("\n\n");
	
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
		
		
		
    	
	}
	else
	{
		printf("\nCategory Not Found ");
		goto first;
	}
}

void deletecat()
{
	int check; 
    char name[20],maind[20]="Products\\";
	printf("Enter Category Name to Remove:- ");
	scanf("%s",name); 
    strcat(maind,name); 
  
    check = rmdir(maind); 
  
    // check if directory is created or not 
    if (!check) 
        printf("Category Deleted\n"); 
    else { 
        printf("Unable to delete Category As Category Contents Products... \n"); 
        
    } 
}
void addpro()
{
	printf("\n\n--Add New Product--\n\n");
	
	char pname[20]="\0",desc[80]="\0",price[5]="\0";
	char name[20],maind[20]="Products\\";
	first:
	maind[9]='\0';
	printf("Enter Category Name to Add a Product :- ");
	scanf("%s",name); 
    strcat(maind,name);
	
	if( access( maind, F_OK ) != -1 ) {
    	printf("\nCategory Found ");
    	goto retry;
	}
	else
	{
		printf("\nCategory Not Found ");
		goto first;
	}

	
	retry:
	printf("\n\nEnter Product Name : ");
	scanf("%s",&pname);
	strcat(maind,"\\");
	strcat(maind,pname);

	if( access( maind, F_OK ) != -1 ) {
    	printf("\n Product Already exists..");
    	
    	
	} else {
		
	    FILE *in_file=fopen(maind,"w");
		fflush(stdin);
		printf("\nEnter Product Description : ");
		gets(desc);

		printf("\nEnter Product Price : ");
		scanf("%s",price);
		
		fprintf(in_file,"Product Name =%s\n",pname);
		fprintf(in_file,"Description =%s\n",desc);
		fprintf(in_file,"Product Price =%s\n",price);
		
		fclose(in_file);
		printf("\nProduct Added SuccessFully :) \n");

	}
}
void delpro()
{
	printf("\n\n--Deletion of A Product--\n\n");
	
	char pname[20]="\0",desc[80]="\0",price[5]="\0";
	char name[20],maind[20]="Products\\";
	first:
	maind[9]='\0';
	printf("Enter Category Name from which you want to delete a Product :- ");
	scanf("%s",name); 
    strcat(maind,name);
	
	if( access( maind, F_OK ) != -1 ) {
    	printf("\nCategory Found ");
    	goto retry;
	}
	else
	{
		printf("\nCategory Not Found ");
		goto first;
	}

	
	retry:
	printf("\n\nEnter Product Name : ");
	scanf("%s",&pname);
	strcat(maind,"\\");
	strcat(maind,pname);

	if( access( maind, F_OK ) != -1 ) {
    	
    	if (remove(maind) == 0) 
		    printf("\nDeleted successfully"); 
		else
		    printf("\nUnable to delete the file"); 
    	
	} else {
		printf("\nProduct Not Found... Retry.. "); 
	    

	}
}
void profile()
{
	char Mobile_no[11]="\0",maind[20]="Users\\";
	retryMobile:
	
	printf("\nEnter User\'s Mobile Number : ");
	scanf("%s",&Mobile_no);
	if(strlen(Mobile_no)<10)
	{
		printf("Wrong Mobile No.Retry... ");
		goto retryMobile;
	}
	strcat(maind,Mobile_no);
	if( access( maind, F_OK ) != -1 ) {
		FILE *file=fopen(maind,"r");
		char line[256],*p,pass[20]="\0";
	   	printf("\nUser Found !\n");
	    while (fgets(line, sizeof(line), file)) {
	        printf("%s",line);
	    }
	}
	else
	{
		printf("\nUser Not Found !\n");		
	}	
}
void searchpro()
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
					displaypro(maind);
    				
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

void displaypro(char path[50])
{
	FILE *file=fopen(path,"r");
		char line[256],*p,pass[20]="\0";
	   
	    while (fgets(line, sizeof(line), file)) {
	        
	        printf("%s",line);
	    }
	    printf("\n");
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
void allusers()
{
	FILE *file=fopen("users.txt","r");
	char line[256],*p,pass[20]="\0";
	printf("\n ----- User List ---- !\n");
	printf("\n-----------------------------------------------------------------------------------\n");
	printf("\n Mobile No  FName   LName   EmailID         PassWord    Address    \n");
	printf("\n-----------------------------------------------------------------------------------\n\n");
	while (fgets(line, sizeof(line), file)) {
	    printf("%s\n",line);
	}
}
void allorders()
{
	FILE *file=fopen("orders.txt","r");
	char line[256],*p,pass[20]="\0";
	printf("\n ----- User List ---- !\n");
	printf("\n------------------------------------------------------------------\n");
	printf("\n Mobile No  Product    Date        Time     Price    \n");
	printf("\n------------------------------------------------------------------\n\n");
	while (fgets(line, sizeof(line), file)) {
	    printf("%s",line);
	}
}
void adddeal()
{
	char pname[20]="\0",maind[50]="\0",price[5]="\0",desc[50]="\0";
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
    			printf("\nProduct Added to List ! ");
    			ss=1;
    			FILE *upd=fopen("topdeals.txt","a");
    			strcpy(price,getprice(maind));
    			strcpy(desc,deblank(getdesc(maind)));
    			
				fprintf(upd,"%s %s %s \n",pname,desc,price);
				fclose(upd);
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
	printf("--%s--",price);
	return (char *)price;
}

char *getdesc(char path[50])
{
	FILE *file=fopen(path,"r");
	int i=0,j=0;
	char line[256]="\n",*desc,*price, *token;
	   
    while (fgets(line, sizeof(line), file)) { 
	    if(i==1)
        {
        	break;
        }
        i++;
	}
	token=strtok(line,"=");
	while (token != NULL) { 
        desc=token; 
        token = strtok(NULL, "-"); 
    }
	fclose(file);
	printf("--%s--",desc);
	return (char *)desc;
}
char* deblank(char* input)                                         
{
    int i,j;
    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)          
    {
        if (input[i]!='\n')                           
            output[j]=input[i];                     
        else
            j--;                                     
    }
    output[j]=0;
    return output;
}

