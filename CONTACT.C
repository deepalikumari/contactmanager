#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"data.h"
#include"search.h"

void main()
{	void add_contact(); //declaration
	void list_contacts();
	void delete_contact();
	void edit_contact();
	void search_contact();
	void change_password();
	char pass[30],original[30],ch,choice;
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(YELLOW);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	clrscr();
	gotoxy(4,3);
	textcolor(RED+BLINK);
	cprintf("Enter the password : ");
	i=0;
	while(1)
{
ch=getch();
if(ch==13) //ASCI code of ENTER key
{
pass[i]='\0';
break;
}
pass[i++]=ch;
printf("*");
}
printf("\nYou entered: %s",pass);
fp=fopen("passwrd.dat","r"); //readind data from the file
fgets(original,30,fp);
fclose(fp);
if(!strcmp(original,pass)==0)
{
gotoxy(4,5);
textcolor(WHITE+BLINK);
cprintf("\nINCORRECT PASSWORD");
cprintf("\nPress Any Key....");
getch();
exit(0);
}
else
{
window(1,1,80,25);
textbackground(11);
clrscr();
gotoxy(32,3);
textcolor(RED);
cprintf("CONTACT MANAGER");
gotoxy(31,5);
textcolor(BLUE);
cprintf("Version No. : 1.0.0");
gotoxy(22,8);
textcolor(YELLOW);
cprintf("Developed By : Deepali Kumari");
textcolor(WHITE);
gotoxy(5,15);
cprintf("Please Wait := ");
for(i=1;i<=50;i++)
	{
	cprintf("%c",220);
	delay(50);
	}
	while(1)
	{
	textbackground(LIGHTMAGENTA);
	clrscr();
	window(18,5,60,22);
	textbackground(CYAN);
	clrscr();
	textcolor(BROWN);
	gotoxy(18,2);
	cprintf("MAIN MENU");
	gotoxy(16,3);
	cprintf("=============");
	textcolor(BLACK);
	gotoxy(12,5);
	cprintf("1. Add New Contact");
	gotoxy(12,6);
	cprintf("2. Delete Contact");
	gotoxy(12,7);
	cprintf("3. Edit");
	gotoxy(12,8);
	cprintf("4. Search Contact");
	gotoxy(12,9);
	cprintf("5. List of Contacts");
	gotoxy(12,10);
	cprintf("6. Change Password");
	gotoxy(12,11);
	cprintf("7. Exit");
	gotoxy(5,12);
	cprintf("-----------------------------------");
	gotoxy(12,14);
	textcolor(RED+BLINK);
	cprintf("Enter Choice(1-7)) ? ");
	choice=getche();
		switch(choice)
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
		list_contacts();
		break;
	case '6':
		change_password();
		break;
	case '7':
		exit(0);
		}
}
}
}
void change_password()
{
	FILE *fp;
	char current[30],original[30],newpass[30],confirm[30];
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();
	printf("	CHANGE PASSWORD ");
	printf("\n-----------------------------------------------");
	printf("\nEnter Current Password : ");
	gets(current);
	fp=fopen("passwrd.dat","r");
	fgets(original,30,fp);
	fclose(fp);
	if(strcmp(current,original)!=0)
	{
	printf("\nINCORRECT PASSWORD <PRESS ANY KEY> ");
	getch();
	return;
	}
	printf("\nEnter New Password : ");
	gets(newpass);
	printf("\nRe-Enter Password : ");
	gets(confirm);
	if(strcmp(confirm,newpass)!=0)
	{
		printf("\nNOT MATCH <press any key> ");
		getch();
		return;
	}
	fp=fopen("passwrd.dat","w");
	fprintf(fp,"%s",newpass);
	fclose(fp);
	printf("SUCCESSFULLY UPDATED <press any key>");
	getch();
}
int getsno()
{
	FILE *fp;
	int n,size;
	fp=fopen("info.dat","rb");
	size=sizeof(cont);
	fseek(fp,-size,SEEK_END);
	n=cont.sno;
	fclose(fp);
	n++;
	return(n);
}
void add_contact()
{
	FILE *fp;
	window(1,1,80,25);
	textbackground(CYAN);
	textcolor(BLACK);
	clrscr();
	printf("ADD NEW CONTACT :== \n");
	printf("-------------------------------------");
	fflush(stdin);
	cont.sno=getsno();
	printf("\nSNo. : %d ",cont.sno);

	fflush(stdin);
	printf("\nEnter Category (Friend/PG/Salesman/Customer/Student) : ");
	gets(cont.category);
	fflush(stdin);
	printf("Enter Name : ");
	gets(cont.name);
	fflush(stdin);
	printf("Enter Gender (M/F) : ");
	scanf("%c",&cont.gender);
	fflush(stdin);
	printf("Enter Age : ");
	scanf("%d",&cont.age);
	fflush(stdin);
	printf("Enter Add : ");
	gets(cont.address);
	fflush(stdin);
	printf("Enter Email.id : ");
	gets(cont.email);
	fflush(stdin);
	fp=fopen("info.dat","ab");
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	textcolor(MAGENTA+BLINK);
	printf("\nSuccessfully Saved, Press any key..");
	getch();
}
void delete_contact()
{
	char choice;
	int n,found;
	FILE *fp1,*fp2;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLACK);
	clrscr();
	printf("	DELETE CONTACT ");
	printf("\n----------------------------------------");
	printf("\nEnter Sno. to be DELETED : " );
	scanf("%d",&n);
	fp1=fopen("info.dat","rb");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
	{
		if(cont.sno==n)
	{
	printf("\nCATEGORY : %s",cont.category);
	printf("\nNAME     : %s",cont.name);
	printf("\nGENDER   : %c",cont.gender);
	printf("\nAGE      : %d",cont.age);
	printf("\nADDRS    : %s",cont.address);
	printf("\nEMAIL ID : %s",cont.email);
	printf("\n======================================");
	found=1 ;
	break;
		}
	}
	if(found==0)
	{
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("NOT FOUND!!! , <<PRESS ANY KEY>>");
		getch();
		fclose(fp1);
		return;
	}
	printf("\nDELETE ? (y/n) : ");
	choice=getche();
	if(choice=='y' || choice== 'Y')
	{
	rewind(fp1);
	fp2=fopen("temp.dat","wb");
	while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
	{
		if(cont.sno!=n)
			fwrite(&cont,sizeof(cont),1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("info.dat");
	rename("temp.dat","info.dat");
	textcolor(YELLOW+BLINK);
	printf("\n");
	cprintf("SUCCESSFULLY DELETED !! << PRESS ANY KEY >> ");
	getch();
 }
 }
 void edit_contact()
 {
	FILE *fp;
	int n, pos,found;
	window(1,1,80,25);
	textcolor(YELLOW);
	textbackground(LIGHTBLUE);
	clrscr();
	printf("	EDIT CONTACT\n ");
	printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("Enter Sno. to EDIT : ");
	scanf("%d",&n);
	fp=fopen("info.dat","r+b");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)!=NULL)
	{
		if(cont.sno==n)
		{
		found=1;
		printf("\nCategory : %s",cont.category);
		printf("\nName     : %s",cont.name);
		printf("\nGender   : %c",cont.gender);
		printf("\nAge      : %d",cont.age);
		printf("\nAddress  : %s",cont.address);
		printf("\nEmail id : %s",cont.email);
		break;
		}
	}
	if(found==0)
	{
		printf("\n");
		textcolor(MAGENTA+BLINK);
		cprintf("NOT FOUND < press any key >");
		fclose(fp);
		getch();
		return;
	}
	printf("\n\nENTER NEW DATA\n");
	pos=ftell(fp);
	fseek(fp,pos-sizeof(cont),SEEK_SET);
	fflush(stdin);
	printf("\n\nEnter Category (Friend/PG/Salesman/Customer/Student) : ");
	gets(cont.category);
	fflush(stdin);
	printf("Enter Name : ");
	gets(cont.name);
	fflush(stdin);
	printf("Enter Gender (M/F) : ");
	scanf("%c",&cont.gender);
	fflush(stdin);
	printf("Enter Age : ");
	scanf("%d",&cont.age);
	fflush(stdin);
	printf("Enter Add : ");
	gets(cont.address);
	fflush(stdin);
	printf("Enter Email.id : ");
	gets(cont.email);
	fflush(stdin);
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	printf("\n");
	textcolor(BLACK+BLINK);
	cprintf("SUCCESSFULLY UPDATED <<PRESS ANY KEY>>");
	getch();
 }




void list_contacts()
{
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(GREEN);
	clrscr();
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
fclose(fp);
textcolor(BLACK+BLINK);
printf("\n");
cprintf("Press any Key");
getch();
}
void search_contact()
	{
	char ch;
	window(1,1,80,25);
	textbackground(CYAN);
	textcolor(BLACK);
	clrscr();
	textcolor(RED);
	cprintf("   SEARCH OPTIONS");
	printf("\n-------------------------------------");
	printf("\n1. Search by Sno. ");
	printf("\n2. Search by Category ");
	printf("\n3. Search by Name ");
	printf("\n4. Search by Age ");
	printf("\n5. BACK TO HOME ");
	printf("\n--------------------------------------");
	textcolor(YELLOW+BLINK);
	printf("\n");
	cprintf("\nENTER CHOICE???");
	ch=getche();
	switch(ch)
	{
		case '1' :
			search_sno();
			break;
		case '2':
			search_category();
			break;
		case '3':
			search_name();
			break;
	   case '4':
			search_age();
			break;
	   case '5':
			return;
	}
}