#include <stdio.h>
#include <string.h>//for strcmp function
#include <stdlib.h>//for exit function
#include "data.h"
#include "search.h"//our search header file

/*struct contact
{
    int  Sno;
    char dummy1;
    char category[20];
    char dummy2;
    char name[20];
    char dummy3;
    char gender;
    char dummy4;
    int  age;
    char dummy5;
    char address[50];
    char dummy6;
    char email[50];
    char dummy7;
    char phone[15]
 //   char dummy8;

}cont;*/

void add_contact(void);
void list_contact(void);
void delete_contact(void);
void edit_contact(void);
void search_contact(void);
void change_pass(void);

void main()
{
    char pass[30], ch, original[30], choice;
    int i;
    FILE *fp;

    system("cls");

    printf("Enter the password: ");
    i = 0;
    while(1)
    {
        ch = getch();
        //printf("%")
        if(ch == 13)//ASCII code for enter
        {
            pass[i] = '\0';
            break;
        }
        pass[i++]=ch;
        printf("*");
    }
    //printf("\nYou entered: %s", pass);
    //Reading data from the file
    fp = fopen("password.dat", "r");
    fgets(original, 30, fp);//stores the input in original
    fclose(fp);
    if(!strcmp(original, pass)==0)//returns 0 if equal
    {

        printf("\nIncorrect password");
        printf("\nPress any key...");
        getch();//will delay the program for some time
        exit(0);//exits the program
    }
    else
    {
        system("cls");
        //for (i = 0; i<=255; i++)
        //printf("%d = %c\t", i,i);//if you print %d char with %c, you will get ASCII char for that
       printf("People Directory");
       printf("\nDeveloped by: Deepansha Garg");
       printf("\nPlease wait ");
       for (i =1; i <=10; i++)
       {
           printf("%c ", 220);

       }
       while(1)
       {

       getch();
       system("cls");
       printf("MAIN MENU");
       printf("\n____________");
       printf("\n1. Add new contact");
       printf("\n2. Delete contact");
       printf("\n3. Edit contact ");
       printf("\n4. Search contact");
       printf("\n5. List of contacts");
       printf("\n6. Change password");
       printf("\n7. Exit");
       printf("\n--------------------");
       printf("\nEnter your choice (1-7):");
       choice = getche();
       switch (choice)
       {
       case '1':
            add_contact();
                break;
       case '2':
            delete_contact();
            break;
       case '3':
            edit_contact();
            break;
       case '4':
        search_contact();
        break;
       case '5':
            list_contact();
            break;
       case '6':
        change_pass();
        break;
       case '7':
        exit(0);
       }



    }
    }



    getch();
}

int getsno()
{
    FILE *fp;
    int n, size;
    fp=fopen("info.txt", "rb");
    size = sizeof(cont);
    fseek(fp, -size, SEEK_END);
    fread(&cont, sizeof(cont), 1, fp);
    n = cont.Sno;
    fclose(fp);
    n++;
    return(n);
}
void add_contact()
{
    system("cls");
    FILE *fp;
 fp = fopen("info.txt", "ab");
 printf("Add new contact");
 printf("\n---------------------------------------------");
 fflush(stdin);
 cont.dummy1=',';
 cont.dummy2=',';
 cont.dummy3=',';
 cont.dummy4=',';
 cont.dummy5=',';
 cont.dummy6=',';
 cont.dummy7=',';

 cont.Sno=getsno();
 printf("\nSerial no: %d", cont.Sno);

 fflush(stdin); // to clear input buffer
 printf("\nEnter category(Friend/PG/Salesman/Customer/Student): ");
 gets(cont.category);
 fflush(stdin);
 printf("\nEnter name: ");
 gets(cont.name);
 fflush(stdin);
 printf("\nEnter gender m/f:");
 scanf("%c", &cont.gender);
 fflush(stdin);
 printf("\nEnter age: ");
 scanf("%d", &cont.age);
 fflush(stdin);
 printf("\nEnter Address: ");
 gets(cont.address);
 fflush(stdin);
 printf("\nEnter the email id: ");
 gets(cont.email);
 fflush(stdin);
 printf("\nEnter the phone no.: ");
 gets(cont.phone);
 fflush(stdin);
 //fprintf(fp, "\n");

 fwrite(&cont, sizeof(cont), 1, fp);
 fclose(fp);
 printf("\nSuccesfully saved, Press any key...");
 getch();

}

void delete_contact()
{
    int n, found = 0;
    char choice;
    FILE *fp1, *fp2;

    system("cls");
    printf("Delete Contact");
    printf("\n_________________________________");
    printf("\nEnter serial no to be deleted: ");
    scanf("%d", &n);
    fp1 = fopen("info.txt", "rb");
    while(fread(&cont, sizeof(cont), 1, fp1)!= NULL)
    {
        if(cont.Sno == n)
        {
            printf("\nCategory  : %s", cont.category);
            printf("\nName      : %s", cont.name);
            printf("\nAge       : %d", cont.age);
            printf("\nGender    : %c", cont.gender);
            printf("\nAddress   : %s", cont.address);
            printf("\nPhone no  : %s", cont.phone);
            printf("\nEmail Id  : %s", cont.email);
            printf("\n_____________________________");
            found = 1;
            break;

        }
    }
    if (found == 0)
    {
        printf("\nNot found, Press any key");
        getch();
        fclose(fp1);
        return;
    }
    printf("\nDelete it y/n: ");
    choice=getche();
    if (choice == "y"|| choice =="Y")
    {


    rewind(fp1);//the cursor will comne at tge beginning of the file
    fp2=fopen("temp.dat", "wb");
    while(fread(&cont, sizeof(cont), 1, fp1)!=NULL)
    {
        if(cont.Sno != n)
            fwrite(&cont, sizeof(cont), 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("info.txt");
    rename("temp.dat", "info.txt");
    printf("\nSuccessfully deleted, Press any key...");
    getch();
    }
    return;
}

void edit_contact()
{
    FILE *fp;
    int pos, n, found=0;

    system("cls");
    printf("Edit Contact");
    printf("\n-----------------------------------");
    printf("\nEnter the serial no. to be edited: ");
    scanf("%d", &n);
    fp = fopen("info.txt", "r+b");//read and write
    while(fread(&cont, sizeof(cont), 1, fp)!=NULL)
    {


            if(cont.Sno==n)
        {
        found = 1;
        printf("\nCategory      : %s\n", cont.category);
        printf("\nName          : %s\n", cont.name);
        printf("\nGender        : %c\n", cont.gender);
        printf("\nAge           : %d\n", cont.age);
        printf("\nAddress       : %s\n", cont.address);
        printf("\nContact no.   : %s\n", cont.address);
        printf("\nEmail ID      : %s\n", cont.email);
        break;
        }
    }

    if(found==0)
    {
        printf("\nNot Found. Press any key...");
        fclose(fp);
        getch();
        return;
    }
    printf("\n\nEnter New Data\n");

    pos = ftell(fp);
    fseek(fp, pos-sizeof(cont), SEEK_SET);
 fflush(stdin);
 printf("\nEnter category(Friend/PG/Salesman/Customer/Student): ");
 gets(cont.category);
 fflush(stdin);
 printf("\nEnter name: ");
 gets(cont.name);
 fflush(stdin);
 printf("\nEnter gender m/f:");
 scanf("%c", &cont.gender);
 fflush(stdin);
 printf("\nEnter age: ");
 scanf("%d", &cont.age);
 fflush(stdin);
 printf("\nEnter Address: ");
 gets(cont.address);
 fflush(stdin);
 printf("\nEnter the email id: ");
 gets(cont.email);
 fflush(stdin);
 printf("\nEnter the phone no.: ");
 gets(cont.phone);
 fflush(stdin);

 fwrite(&cont, sizeof(cont), 1, fp);
 fclose(fp);
 printf("\nSuccessfully Updated. Press any key...");
 getch();
}

void search_contact()
{
    char ch;
    system("cls");
    printf("SEARCH OPTIONS");
    printf("\n-------------------------------");
    printf("\n1. Search by serial no ");
    printf("\n2. Search by category");
    printf("\n3. Search by name");
    printf("\n4. Search by phone no");
    printf("\n5. Back to main menu");
    printf("\n-------------------------------");
    printf("\n\nEnter your choice:");
    ch = getche();

    switch(ch)
    {
    case '1':
        search_sno();
        break;
    case '2':
        search_category();
        break;
    case '3':
        search_name();
        break;
    case '4':
        search_phone();
        break;
    case '5':
        return;

    }
}

void list_contact()
{
    FILE *fp;
    int i;
    system("cls");
    getch();
    printf("LIST OF CONTACTS");
    printf("\n");
    for (i = 0; i <= 120; i++)
    {
        printf("-");

    }
    printf("\nSno.");
    printf("\tCATEGORY");
    printf("\tNAME");
    printf("\t\tGENDER");
    printf("\t\tAGE");
    printf("\t\tADDRESS");
    printf("\t\tEMAIL ID");
    printf("\tPHONE");
    printf("\n");
    for (i = 0; i<=120; i++ )
        printf("-");

    fp = fopen("info.txt", "rb");//read in binary
    while(fread(&cont, sizeof(cont), 1, fp)!=NULL)
    {
        printf("\n%d", cont.Sno);
        printf("\t%s", cont.category);
        printf("\t%s", cont.name);
        printf("\t\t%c", cont.gender);
        printf("\t\t%d", cont.age);
        printf("\t%s", cont.address);
        printf("\t%s", cont.email);
        printf("\t%s", cont.phone);
        i++;
    }
    fclose(fp);
    printf("\n");
    printf("Press any key...");
    getch();
}


void change_pass()
{
    FILE *fp;
    char current[30], ori[30], newpass[30], confirm[30];
    system("cls");
    printf("CHANGE PASSWORD");
    printf("\n---------------------");
    getch();

    printf("\nEnter the current password: ");
    gets(current);

    fp = fopen("password.dat", "r");
    fgets(ori, 30, fp);
    fclose(fp);
    if(strcmp(current, ori)!=0)
    {
        printf("\nIncorrect password, press any key...");
        getch();
        return;
    }

    printf("\nEnter new password: ");
    gets(newpass);
    printf("\nRe-enter password: ");
    gets(confirm);

    if(strcmp(newpass, confirm)!=0)
    {
        printf("\nThe passwords don't match. Press any key...");
        getch();
        return;
    }
    fp = fopen("password.dat", "w");
    fprintf(fp, "%s", newpass);
    fclose(fp);
    printf("\nSuccessfully updated.");


}
