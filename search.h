void search_sno()
{

    FILE *fp;
    int n, found=0;
    system("cls");
    printf("Enter the serial no : ");
    scanf("%d", &n);
    fp = fopen("info.txt", "r");
    while(fread(&cont, sizeof(cont), 1, fp)!= NULL)
    {
        if (cont.Sno == n)
        {
            printf("\nCategory  : %s", cont.category);
            printf("\nName      : %s", cont.name);
            printf("\nAge       : %d", cont.age);
            printf("\nGender    : %c", cont.gender);
            printf("\nAddress   : %s", cont.address);
            printf("\nPhone no  : %s", cont.phone);
            printf("\nEmail Id  : %s", cont.email);
            printf("\n_____________________________");
            found=1;
            break;
        }
    }
    if(found = 0)
    {
        printf("\nNot found, Press any key...");
        fclose(fp);
        getch();
        return;
    }
    fclose(fp);
    getch();
}


void search_category()
{
    FILE *fp;
    int  i;
    char cat[20];
    system("cls");
    getch();
    printf("Enter category: ");
    gets(cat);
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
        if(strcmpi(cat, cont.category)==0)
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
    }

    fclose(fp);
    printf("\n");
    printf("Press any key...");
    getch();
}

void search_name()
{
    FILE *fp;
    int i;
    char name[20];
    system("cls");
    getch();
    printf("Enter name: ");
    gets(name);
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
        if(strcmpi(name, cont.name)==0)
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
    }

    fclose(fp);
    printf("\n");
    printf("Press any key...");
    getch();
}

void search_phone()
{
    FILE *fp;
    int i;
    char phone[20];
    system("cls");
    getch();
    printf("Enter phone no.: ");
    gets(phone);
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
        if(strcmpi(phone, cont.phone)==0)
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
    }

    fclose(fp);
    printf("\n");
    printf("Press any key...");
    getch();
}
