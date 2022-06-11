void search_sno()
{
	FILE *fp;
	int found,n;
	textcolor(WHITE);
	clrscr();
	printf("Enter Sno.: ");
	scanf("%d",&n);
	fp=fopen("info.dat","r");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
	if(cont.sno==n)
	{
		printf("\nCategory : %s",cont.category);
		printf("\nName     : %s",cont.name);
		printf("\nGender   : %c",cont.gender);
		printf("\nAge      : %d",cont.age);
		printf("\nAddress  : %s",cont.address);
		printf("\nEmail id : %s",cont.email);
		found=1;
		break;
		}
	}
	if(found==0)
	{
		printf("\nNOT FOUND!!! PRESS ANY KEY");
		fclose(fp);
		getch();
		return;
		}
		fclose(fp);
		getch();

}
//search by category
void search_category()
{
	int i;
	char cat[20];
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(GREEN);
	clrscr();
	printf("ENTER CATEGORY:  ");
	gets(cat);
	gotoxy(34,1);
	printf("List Of Contacts");
	printf("\n");
	for(i=1;i<=80;i++)
	printf("-");
	gotoxy(1,3);
	printf("SNO.");
	gotoxy(8,3);
	printf("CATEGORY");
	gotoxy(20,3);
	printf("NAME");
	gotoxy(36,3);
	printf("GENDER");
	gotoxy(46,3);
	printf("AGE");
	gotoxy(50,3);
	printf("ADDRS");
	gotoxy(60,3);
	printf("EMAIL");
	printf("\n");
	for(i=1;i<=80;i++)
	printf("-");
	fp=fopen("info.dat","rb");
	i=5;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
		if(strcmpi(cat,cont.category)==0)
		{
		gotoxy(1,i);
		printf("%d",cont.sno);
		gotoxy(8,i);
		printf("%s",cont.category);
		gotoxy(20,i);
		printf("%s",cont.name);
		gotoxy(36,i);
		printf("%c",cont.gender);
		gotoxy(46,i);
		printf("%d",cont.age);
		gotoxy(50,i);
		printf("%s",cont.address);
		gotoxy(60,i);
		printf("%s",cont.email);
		i++;
		}
	}
fclose(fp);
textcolor(BLACK+BLINK);
printf("\n");
cprintf("Press any Key");
getch();
}
void search_name()
{
	int i;
	char na[20];
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(GREEN);
	clrscr();
	printf("ENTER NAME:  ");
	gets(na);
	gotoxy(34,1);
	printf("List Of Contacts");
	printf("\n");
	for(i=1;i<=80;i++)
	printf("-");
	gotoxy(1,3);
	printf("SNO.");
	gotoxy(8,3);
	printf("CATEGORY");
	gotoxy(20,3);
	printf("NAME");
	gotoxy(36,3);
	printf("GENDER");
	gotoxy(46,3);
	printf("AGE");
	gotoxy(50,3);
	printf("ADDRS");
	gotoxy(60,3);
	printf("EMAIL");
	printf("\n");
	for(i=1;i<=80;i++)
	printf("-");
	fp=fopen("info.dat","rb");
	i=5;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
		if(strcmpi(na,cont.name)==0)
		{
		gotoxy(1,i);
		printf("%d",cont.sno);
		gotoxy(8,i);
		printf("%s",cont.category);
		gotoxy(20,i);
		printf("%s",cont.name);
		gotoxy(36,i);
		printf("%c",cont.gender);
		gotoxy(46,i);
		printf("%d",cont.age);
		gotoxy(50,i);
		printf("%s",cont.address);
		gotoxy(60,i);
		printf("%s",cont.email);
		i++;
		}
	}
	getch();
}
void search_age()
{
	FILE *fp;
	int found,n;
	textcolor(WHITE);
	clrscr();
	printf("Enter AGE: ");
	scanf("%d",&n);
	fp=fopen("info.dat","r");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
	if(cont.age==n)
	{
		printf("\nCategory : %s",cont.category);
		printf("\nName     : %s",cont.name);
		printf("\nGender   : %c",cont.gender);
		printf("\nAge      : %d",cont.age);
		printf("\nAddress  : %s",cont.address);
		printf("\nEmail id : %s",cont.email);
		found=1;
		break;
		}
	}
	if(found==0)
	{
		printf("\nNOT FOUND!!! PRESS ANY KEY");
		fclose(fp);
		getch();
		return;
		}
		fclose(fp);
		getch();

	}
