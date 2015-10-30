#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"rail.h"

char f[10]="f"; // first class //
char s[10]="s"; // second class //
int  addr, ad, flag, f1, d, m, i, amt;
float tamt;   // total amount //

void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();
void getcancdet();
void displaycancdet();
void getdetail();
void displaydetail();
void getid();
void displayid();
void getresdet();
void displayresdet();

void main () {
	printf("1.Admin mode\n 2.User mode\n 3.Exit\n");
	printf("Enter your choice:");
	scanf("%d", &ch);
	switch(ch)

	{
	case 1:
		database();
		break;
	case 2:
		user();
		break;
	default :
		break;
	}
}

void database() {
	char *password;
	char *pass="12345678";
	password=getpass("Enter the admininistrator password:");
	detail a;
	int ch;
	char c;
	if(strcmp(pass,password)!=0)
	{
	printf("Enter the password correctly \n You are not permitted to login this mode\n");
	//goto ch;
	}
	if(strcmp(pass,password)==0)
	{
	char c;
	do
	{
	printf("...........ADMINISTRATOR MENU...........\n");
	printf("1.Create detail data base\n 2.Add details\n 3.Display details\n 4.User management\n 				5.Display passenger details\n 6.Return to main menu\n");
	printf("Enter your choice:");
	scanf("%d\n", &ch);
	}
	}
switch(ch) {
	case 1:
		fp = fopen("t.txt","r");
		do
		{
		getdetail(a);
		fwrite((char *) & a,sizeof(a), fp);
		printf("Do you want to add one more record?\n");
		printf("y-for Yes\nn-for No\n");
		scanf("%c\n", &c);
		}
		while(c=='y');
		fclose(fp);
		break;
	case 2:
		fp = fopen("t.txt","r");
		getdetail(a);
		fwrite((char *) & a,sizeof(a), fp);
		fclose(fp);
		break;
	case 3:
		fp = fopen("t.txt","r");
		//fseek(0);
		while(fread((char *) & a,sizeof(a), fp))
		{
		displaydetail(a);
		}
		fclose(fp);
		break;
	case 4:
		manage();
		break;
	case 5:
		displaypassdetail();
		break;
	default :
		break;
	}
	while(ch<=5);
	fclose(fp);
	// h:
}
void reserve() {
	int ch;
	do
	{
	printf("1.Reserve\n2.Return to the main menu\n");
	printf("Enter your choice:");
	scanf("%d\n", &ch);
		switch(ch)
		{
		case 1:
			res();
			break;
		default :
			break;
		}
	}
	while(ch==1);
	getch();
}
void res()
{
	detail a;
	reser b;
	FILE *fp1, *fp2;
	time_t t;
	fp1 = fopen("t.txt","r");
	fp2 = fopen("p.txt","r");
	int ch;
	getresdet(b);
	while(fread((char *) &a,sizeof(a), fp1))
	{
	if(a.tno == b.tno)
	{
	if(strcmp(b.clas,f) == 0)
	{
	if(a.c1> = b.nosr)
	{
	amt = a.c1fare;
	/*addr=f1.tellg();
	ad=sizeof(a.c1);
	f1.seekp(addr-(7*ad)); */
	a.c1= a.c1 - b.nosr;
	fwrite((char *) & a.c1,sizeof(a.c1),  fp1);
	if(b.con == 1)
	{
	printf("Concession category:MILITARY PERSONNEL\n");
	b.amc = b.nosr*((amt*50)/100);
	}
	else if(b.con == 2)
	{
	printf("Concession category:SENIOR CITIZEN\n");
	b.amc = b.nosr*((amt*60)/100);
	}
	else if(b.con == 3)
	{
	printf("Concession category:CHILDERN BELOW FIVE\n");
	b.amc = 0.0;
	}
	else if(b.con == 4)
	{
	printf("You cannot get any concession\n");
	b.amc = b.nosr*amt;
	}
	srand((unsigned) time(&t));
	b.pnr = rand();
	fwrite((char *) & b,sizeof(b), fp2);
	displayresdet(b);
	printf("--------------Your ticket is reserved-----------\n");
	}
	else
	{
	printf("**********Sorry req seats not available********\n");
	}
	}
	else if(strcmp(b.clas,s)==0)
	{
	if(a.c2 >= b.nosr)
	{
	amt = a.c2fare;
	//addr=f1.tellg();
	//ad=sizeof(a.c2);
	//f1.seekp(addr-(5*ad));
	a.c2 = a.c2 - b.nosr;
	fwrite((char *) & a.c2,sizeof(a.c2) ,fp1);
	if(b.con == 1)
	{
	printf("Concession category:MILITARY PRESONNEL\n");
	b.amc = b.nosr * ((amt*50)/100);
	}
	else if(b.con == 2)
	{
	printf("Concession category:SENIOR CITIZEN\n");
	b.amc = b.nosr * ((amt*60)/100);
	}
	else if(b.con == 3)
	{
	printf("Concession category:CHILDERN BELOW FIVE\n");
	b.amc = 0.0;
	}
	else if(b.con == 4)
	{
	printf("You cannot get any concession\n)";
	b.amc = b.nosr * amt;
	}
	fwrite((char *) & b,sizeof(b), fp2);
	displayresdet(b);
	printf("--------Your ticket is reserved--------\n");
	}
	else {
	printf("Sorry req no of seats not available\n");
	}
	}
	getch();

	//goto h;
	}
	else
	{
	flag=0;
	}
	}
	if(flag==0)
	{
	printf("....Wrong train no..Enter the train no from the data base.....\n");
	}
	fclose(fp1);
	fclose(fp2);
	getch();
	//h:
	}

void displaypassdetail() {
	FILE *fp;
	reser b;
	fp = fopen("p.txt","r");
		//fseek(0);//
	while(fread((char *) & b,sizeof(b), fp))
	{
	displayresdet(b);
	}
	fclose(fp);
	getch();
	}
void enquiry()
	{
	FILE *fp;
	fstream f;
	fp = fopen("t.txt","r");
	detail a;
	while(fread((char *) & a,sizeof(a), fp))
	{
	displaydetail(a);
	}
	getch(fp);
	}

void cancell() {
	detail a;
	reser b;
	canc c;
	FILE *fp1,*fp2,*fp3;
	fp1 = fopen("t.txt","r");
	fp2 = fopen("p.txt","r");
	fp3 = fopen("cn.txt","r");
	printf("****CANCELLATION MENU****\n");
	getcancdet(c);
	while(fread((char *) & b,sizeof(b), fp2))
	{
	if(b.pnr == c.pnr)
	{
	c.tno = b.tno;
	strcpy(c.tname,b.tname);
	strcpy(c.bp,b.bp);
	strcpy(c.dest,b.dest);
	c.nosc=b.nosr;
	for(int j=0;j < c.nosc;j++)
	{
	strcpy(c.pname[j],b.pname[j]);
	c.age[j] = b.age[j];
	}
	strcpy(c.clas,b.clas);
	if(strcmp(c.clas,f) == 0)
	{
	while(fread((char *) & a,sizeof(a), fp1))
	{
		if(a.tno == c.tno)
	{
	a.c1 = a.c1  + c.nosc;
	d = a.dd;
	m = a.mm;
	/*addr=f1.tellg();
	ad=sizeof(a.c1);
	f1seekp(addr-(7*ad)); */
	fwrite((char *) & a.c1,sizeof(a.c1), fp1);
	tamt = b.amc;
	if((c.dd == d) && (c.mm == m))
	{
	printf("You are cancelling at the date of departure\n");
	c.amc = tamt - ((tamt*60)/100);
	}
	else if(c.mm  == m)
	{
	printf("You are cancelling at the month of departure\n");
	c.amc = tamt-((tamt*50)/100);
	}
	else if(m > c.mm)
	{
	printf("You are cancelling one month before the date of departure\n");
	c.amr = tamt-((tamt*20)/100);
	}
	else
	{
	printf("Cancelling after the departure\n Your request cannot be completed\n");
	}
	//goto h;
	displaycancdet();
	}
	}
	}
	else if(strcmp(c.clas,s)==0)
	{
	while(fread((char *) & a,sizeof(a), fp1))
	{

	if(a.tno == c.tno)
	{
	a.c2 = a.c2 + c.nosc;
	d = a.dd;
	m = a.mm;
	/*addr=f1.tellg();
	ad=sizeof(a.c2);
	f1.seekp(addr-(5*ad));*/
	fwrite((char *) & a.c2,sizeof(a.c2), fp1);
	tamt = b.amc;
	if((c.dd == d)&&(c.mm == m))
	{
	printf("You are cancelling at the date of departure\n");
	c.amr = tamt-((tamt*60)/100);
	}
	else if(c.mm == m)
	{
	printf("You are cancelling at the month of departure\n");
	c.amr=tamt-((tamt*50)/100);
	}
	else if(m > c.mm)
	{
	printf("You are cancelling one month before the date of departure\n");
	c.amc = tamt-((tamt*20)/100);
	}
	else
	{
	printf("Cancelling after the departure\n");
	printf("Your request cannot be completed\n");
	}
	//goto h;
	displaycancdet();
	}
	}
	}
	}
	else
	{
	flag=0;
	}
	}
	h:
	if(flag==0)
	{
	printf("Enter the correct pnr no\n");
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	getch();
	}
void can() {
	int ch;
	do
		{
		printf("1.Cancell\n2.Return to the main menu\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				cancell();
				break;
			default:
				break;
		}
		}
	while(ch==1);
	getch();
	}

void user() {
	login a;
	int ch;
	char *password;
	FILE *fp;
	fp = fopen("id.txt","r");
	char id[100];
	puts("Enter your id:");
	gets(id);
	password=getpass("Enter your password:");
	while(fread((char *) & a,sizeof(a), fp))
	{
	if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
	{
	do
	{
		printf("1.Reserve\n 2.Cancell\n 3.Enquiry\n 4.Return to the main menu\n");
		//printf("Enter your choice:");//
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				reserve();
				break;
			case 2:
				cancell();
				break;
			case 3:
				enquiry();
				break;
			default :
				break;

		}
		}
	while(ch<=3);

	}
			else
			{
			d=1;
			}
			}
			if(d == 1)
			{
			printf("Enter your user id and password correctly\n");
			}
			getch();
			//j:
			}
void manage()
{
	int ch;
	FILE *fp;
	char c;
	login a;
	printf(".........WELCOME TO THE USER MANAGEMENT MENU........\n");
	do
	{
	printf("1.Create id data base\n 2.Add details\n 3.Display details\n 4.Return to the main menu\n");
	printf("Enter your choice:");
	scanf("%d", &ch);

		switch(ch)
		{
		case 1:
			fp = fopen("id.txt","r");
			do
			{
			getid(a);
			fwrite((char *) & a,sizeof(a), fp);
			printf("Do you want to add one more record\n");
			printf("y-Yes\nn-No\n");
			scanf("%c", &c);
			}
			while(c=='y');
			fclose(fp);
			break;

		case 2:
			fp = fopen("id.txt","w");
			getid(a);
			fwrite((char *) & a,sizeof(a), fp);
			fclose(fp);
			break;

		case 3:
			fp = fopen("id.txt","w");

			//fseek(0);//
			while(fread((char *) & a,sizeof(a), fp))
			{
			displayid(a);
			}
			fclose(fp);
			break;
		default :
			break;
			}
		}
	while(ch<=3);
	getch();
}
