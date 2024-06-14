#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define Student struct stu

void add(FILE * fp); //to add to list
FILE * del(FILE * fp);//to delete from list
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();


struct stu
{
    int id;
    char name[100];
    char branch[10];
    int year;
    char jdate[8];
    char gender[10];
    char campus[50];
    char psaddr[200];
    char prtaddr[200];
    char phone[15];
    char mail[20];
};


int main()
{
 FILE * fp;
 Student e;
int option;
char another;

if((fp=fopen("StudentInfo.txt","rb+"))==NULL)
{
    if((fp=fopen("StudentInfo.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}
char username[10],password[10];
printHead();
welcome();
printHead();
printf("\n\t\t\t\t  Login Screen");
printf("\n\t\t\t      Enter Your Credential");
printf("\n\n\n\t\tUsername: ");
scanf("%s",username);
printf("\n\t\tPassword: ");
int i;
i=0;
    do
    {
        password[i] = getch();
        if(password[i] == 13 )
        {
            break;
        }
        else if(password[i]==8 && i>0)
        {
            printf("%c%c%c",8,32,8);
            i--;
        }
        else
        {
            printf("*");
            i++;
        }
    }while(password[i]!=13);
    password[i] = '\0';

if(((strcasecmp(username,"admin"))==0)&&((strcasecmp(password,"pass")==0)))
{
    while(1)
{
    printHead();
    printf("\n\t\t\t\tMain Menu");
    printf("\n\n\n");

    printf("\n\n\t\t\t1. Add Student");
    printf("\n\n\t\t\t2. Delete Student");
    printf("\n\n\t\t\t3. Modify Student");
    printf("\n\n\t\t\t4. Display Student List");
    printf("\n\n\t\t\t5. Search Record");
    printf("\n\n\t\t\t6. Display Basic Info");
    printf("\n\n\t\t\t7. Display Basic Contact Info");
    printf("\n\n\t\t\t8. List of Male Student");
    printf("\n\n\t\t\t9. List of Female Student");
    printf("\n\n\t\t\t10. Register a complaint");
    printf("\n\n\t\t\t11. List of NRI students");
    printf("\n\n\t\t\t12. List of Student of Main Campus");
    printf("\n\n\t\t\t13. List of Student of Sector 128 Campus");
    printf("\n\n\t\t\t0. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);

    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: fp=del(fp);
                break;
        case 3: modify(fp);
                break;
        case 4: displayList(fp);
                break;
        case 5: searchRecord(fp);
                break;
        case 6: displaybasic(fp);
                break;
        case 7: basiccontact(fp);
                break;
        case 8: malestu(fp);
                break;
        case 9: femalestu(fp);
                break;
        case 10: complaints(fp);
                break;
        case 11: frmors(fp);
                break;
        case 12: mainca(fp);
                break;
        case 13: sec128ca(fp);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);

    }
}
}
else {
    printf("\n\t\tLogin Failed");
}

return 1;

}

//====Welcome Screen=====
void welcome()
{
    printf("\n\n\n\n\n\t\t[ [ [ WELCOME TO OUR HOSTEL MANAGEMENT SYSTEM ] ] ]\n\n\n\n\n\n\n\t");
    system("pause");
}

//----printing character ch at n times ------

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----

void printHead()
{ system("cls");
printf("\t");
printChar('=',65);
printf("\n\t");
printChar('=',16);
printf("[HOSTEL] [MANAGEMENT] [SYSTEM]");
printChar('=',16);
printf("\n\t");
printChar('=',65);

}


// ==========ADDING NEW RECORD==========================

void add(FILE * fp)
{
printHead();

printf("\n\t\t\t\Add Student");
char another='y';
Student e;

fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{
    printf("\n\n\t\tEnter ID number: ");
    scanf("%d",&e.id);

    printf("\n\n\t\tEnter Full Name of Student: ");
    fflush(stdin);
    fgets(e.name,100,stdin); //fgets takes an extra \n character as input
    e.name[strlen(e.name)-1]='\0';

    printf("\n\n\t\tEnter Branch: ");
    fflush(stdin);
    fgets(e.branch,10,stdin); //fgets takes an extra \n character as input
    e.branch[strlen(e.branch)-1]='\0';

    printf("\n\n\t\tEnter Gender: ");
    fflush(stdin);
    fgets(e.gender,10,stdin); //fgets takes an extra \n character as input
    e.gender[strlen(e.gender)-1]='\0';

    printf("\n\n\t\tEnter Campus: ");
    fflush(stdin);
    fgets(e.campus,50,stdin);
    e.campus[strlen(e.campus)-1]='\0';

    printf("\n\n\t\tEnter year: ");
    scanf("%f",&e.year);

    printf("\n\n\t\tEnter Present Address: ");
    fflush(stdin);
    fgets(e.psaddr,200,stdin);
    e.psaddr[strlen(e.psaddr)-1]='\0';

    printf("\n\n\t\tEnter Permanant Address: ");
    fflush(stdin);
    fgets(e.prtaddr,200,stdin);
    e.prtaddr[strlen(e.prtaddr)-1]='\0';

    printf("\n\n\t\tEnter Phone: ");
    fflush(stdin);
    fgets(e.phone,50,stdin);
    e.phone[strlen(e.phone)-1]='\0';

    printf("\n\n\t\tEnter E-mail: ");
    fflush(stdin);
    fgets(e.mail,20,stdin);
    e.mail[strlen(e.mail)-1]='\0';

    fwrite(&e,sizeof(e),1,fp);

    printf("\n\n\t\tWant to enter another Student info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}

//===================DELETING A RECORD FROM LIST ============
FILE * del(FILE * fp)
{
 printHead();
printf("\n\t\t\t\Delete Student");
Student e;
int flag=0,tstuid,siz=sizeof(e);
FILE *ft;

if((ft=fopen("tstu.txt","wb+"))==NULL)
{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tEnter ID number of Student to Delete the Record");
printf("\n\n\t\t\tID No. : ");
scanf("%d",&tstuid);

rewind(fp);

while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tstuid)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",e.name,e.campus,e.id);
    continue;
    }

    fwrite(&e,siz,1,ft);
}

fclose(fp);
fclose(ft);

remove("StudentInfo.txt");
rename("tstu.txt","StudentInfo.txt");

if((fp=fopen("StudentInfo.txt","rb+"))==NULL)
{
    printf("ERROR");
    return  NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}


//===========MODIFY A RECORD ===========================

void modify(FILE * fp)
{
printHead();
printf("\n\t\t\t\Modify Student");
Student e;
int i,flag=0,tstuid,siz=sizeof(e);
int year;

printf("\n\n\tEnter ID Number of Student to Modify the Record : ");
scanf("%d",&tstuid);

rewind(fp);

while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tstuid)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRecord Found");
    printf("\n\n\t\tEnter New Data for the Record");

     printf("\n\n\t\tEnter ID number: ");
    scanf("%d",&e.id);

    printf("\n\n\t\tEnter Full Name of Student: ");
    fflush(stdin);
    fgets(e.name,100,stdin); //fgets takes an extra \n character as input
    e.name[strlen(e.name)-1]='\0';

    printf("\n\n\t\tEnter Branch: ");
    fflush(stdin);
    fgets(e.branch,10,stdin); //fgets takes an extra \n character as input
    e.branch[strlen(e.branch)-1]='\0';

    printf("\n\n\t\tEnter Gender: ");
    fflush(stdin);
    fgets(e.gender,10,stdin); //fgets takes an extra \n character as input
    e.gender[strlen(e.gender)-1]='\0';

    printf("\n\n\t\tEnter campus: ");
    fflush(stdin);
    fgets(e.campus,50,stdin);
    e.campus[strlen(e.campus)-1]='\0';

    printf("\n\n\t\tEnter Year: ");
    scanf("%d",&e.year);

    printf("\n\n\t\tEnter Present Address: ");
    fflush(stdin);
    fgets(e.psaddr,200,stdin);
    e.psaddr[strlen(e.psaddr)-1]='\0';

    printf("\n\n\t\tEnter Permanant Address: ");
    fflush(stdin);
    fgets(e.prtaddr,200,stdin);
    e.prtaddr[strlen(e.prtaddr)-1]='\0';

    printf("\n\n\t\tEnter Phone: ");
    fflush(stdin);
    fgets(e.phone,50,stdin);
    e.phone[strlen(e.phone)-1]='\0';

    printf("\n\n\t\tEnter E-mail: ");
    fflush(stdin);
    fgets(e.mail,20,stdin);
    e.mail[strlen(e.mail)-1]='\0';

    fwrite(&e,sizeof(e),1,fp);
}

else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

printf("\n\n\t");
system("pause");

}

//====================DISPLAY THE LIST =================
void displayList(FILE * fp)
{   printHead();
printf("\n\t\t\t\List  of Students");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tGENDER : %s",e.gender);
        printf("\n\n\t\tCAMPUS : %s",e.campus);
        printf("\n\n\t\tYEAR : %d",e.year);
        printf("\n\n\t\tPRESENT ADDRESS : %s",e.psaddr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s",e.prtaddr);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//================SEARCH Student==
void searchRecord(FILE *fp)
{printHead();
printf("\n\t\t\t\Search Student");
int tstuid,flag,siz,i;
Student e;
char another='y';

siz=sizeof(e);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID Number of Student to search the record : ");
scanf("%d",&tstuid);

rewind(fp);

while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tstuid)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    printf("\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tCAMPUS : %s",e.campus);
        printf("\n\n\t\tYEAR: %d",e.year);
        printf("\n\n\t\tPRESENT ADDRESS : %s",e.psaddr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s",e.prtaddr);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s",e.mail);

        printChar('=',65);

}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}

//========================LIST OF MALE Student==
void malestu(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\List of Male Student");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.gender,"Male")==0)||(strcmp(e.gender,"male")==0))
        {

        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printChar('-',65);
        }
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF FEMALE Student==

void femalestu(FILE * fp)
{
    printHead();
     printf("\n\t\t\t\List of Female Student");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.gender,"Female")==0)||(strcmp(e.gender,"female")==0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printChar('-',65);
        }
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

//========================REGISTERING A COMPLAINT====

void complaints(FILE * fp)
{
    int opt;
    char compt;
    printHead();
     printf("\n\t\t\t\Register a complaint\n");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
    printf("\n1.Electricity Issue\n2.Pest problems\n3.Broken Furniture\n4.Cleanliness Problem\n5.Water Quality problem\n");
    printf("choose any option:");
    scanf("%d",&opt);
    if(opt==1 ||opt==2 ||opt==3 ||opt==4 ||opt==5)
    {
        printf("Thank You\n Your problem will be resolved soon\npress any other key to continue");
    }
    else{
        break;
    }

    }



    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF NRI STUDENTS====

void frmors(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\List of NRI Students");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strstr(e.prtaddr,"India")==1)&&(strstr(e.prtaddr,"india")==1)&&(strstr(e.prtaddr,"INDIA")==1))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s",e.mail);
        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//==============DISPLAY BASIC INFO LIST==

void displaybasic(FILE * fp)
{   printHead();
printf("\n\t\t\t\Display Basic Information");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tGENDER : %s",e.gender);
        printf("\n\n\t\tCAMPUS : %s",e.campus);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========BASIC CONTACT INFO LIST====

void basiccontact(FILE * fp)
{   printHead();
printf("\n\t\t\t\Basic Contact Information");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF STUDENTS OF MAIN CAMPUS====

void mainca(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\List of Student of Main Branch");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.campus,"Main")==0)||(strcmp(e.prtaddr,"main")==0)||(strcmp(e.prtaddr,"MAIN")==0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\t",e.mail);
        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF STUDENTS OF SECTOR 128 CAMPUS====

void sec128ca(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\List of students of 128 campus");
    Student e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.campus,"128")!=0))
        {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNAME : %s",e.name);
        printf("\n\n\t\tBranch : %s",e.branch);
        printf("\n\n\t\tPHONE : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        printChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

