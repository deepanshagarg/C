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
        if (cont.sno == n)
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
}
