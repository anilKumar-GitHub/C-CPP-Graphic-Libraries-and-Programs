#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>


void wel_come_msg();
void BGcolor();
char name[30];
int Ans;


char QB1[15][80] = {"What is CS Long Form?","Who is the Presidant of India ?","What is the ratio of CET Examination in 2005?","Which city called the Silicon Valley of India ?","First World War Held at ......?","What is the product of nVdia manufactures?","In one of these Popular Watch maker company....?","What was the name of the character played by Amjab Khan in the film Sholay ?","Who is called \"Pitamaha\" in Mahabharata ?"," 10"," 11"," 12"," 13"," 14"," 15"};

struct AnSheet	{
	char one[30];
	char two[30];
	char three[30];
	char four[30];
	int ans;
};

struct AnSheet Answer[15] = {{"Company Security","Computer Science","Component Science","Corporation Socialogy",2},{"Dr.Manmohan Sigh","Sonia Ghandi","Dr. APJ Kalam","None of These",4},{"20:40","60:40","70:30","50:50",2},{"Calcutta","Hyderabad","Bangalore","Pune",3},{"1956","1938","1939","1940",3},{"Mouse","Processors","Graphic Card","Mother Bord",3},{"Titanic","Titinio","titanium","Titan",4},{"Gabbar","Shamba","Shakal","Mugambo",1},{"Bhishma","Shakuni","Dhritharastra","Dronacharya",1},{"10","12","13","15",1},{"11","23","33","65",1},{"12","23","34","45",1},{"13","654","65","75",1},{"14","45","634","34",1},{"15","34","45","45",1}};

long long int Cash_Book[15] = {1000,2000,3000,5000,10000,20000,40000,80000,160000,320000,640000,1250000,2500000,5000000,10000000};

void mainFun();

main()	{
	BGcolor();
	wel_come_msg();
	clrscr();
	mainFun();
	getch();
	return 0 ;
}

void wel_come_msg() {
	clrscr();
	textcolor(GREEN);
	gotoxy(20,10);
	cprintf("Welcome to the KBC Participation Game");
	gotoxy(22,12);
	cprintf("\n Name : ");
	cscanf("%s",name);
	gotoxy(30,16);
	cprintf(" Best of Luck ");
	getch();
	getch();
}

void BGcolor() {
	int i,j;
	clrscr();
	textbackground(RED);
	for( i=0; i<25; i++ )
		for( j=0; j<80; j++ )
			cprintf(" ");

}

void mainFun(){
	int ans;  int runSel;  int i = 0;
	long long int amount = 0;
	clrscr();

	for(i = 0 ; i < 15 ; i++ ) {
		printf("\n\t\t\t   Kaun Banega Crorepati");
		printf("\n------------------------------ Best of Luck ---------------------------");
		printf("\n\n Patricipate  : %s",name);
		printf("\t\t\t Level : %d",i+1);
		printf("\n\n Earned Amount Rs. %08ld",amount);
		printf("\t\t Q Worth of %ld Rs.",Cash_Book[i]);
		printf("\n\n\n Q: %s",QB1[i]);
		printf("\n\n 1] %-25s",Answer[i].one);
		printf("\t 2] %-25s",Answer[i].two);
		printf("\n\n 3] %-25s",Answer[i].three);
		printf("\t 4] %-25s",Answer[i].four);
		printf("\n\n\n\n Enter Option Here : [ Enter 0 to Quit the Game ] :   ");
		scanf("%d",&ans);



	if( ans == 0 )  {
		clrscr();
		printf("\n\n\n\n\n\n\n\n\t\t Congragulation You Have Owned Totally  Rs. %ld",amount);
		printf("\n\n\t\t\tThanks for Playing with KBC");
		printf("\n\n\n\t\tMr/Miss. %s you have won Rs. %ld",name,amount);
		getch();
		exit(0);
	}

	if(ans != Answer[i].ans )	{

		printf("\n\n\t\t Sorry You have entered the Wrong Option");
		printf("\n\n\t\t The Correct Option is : %d ",Answer[i].ans);
		getch(); getch();
		clrscr();
		printf("\n\n\n\n\n\t\t\tThanks for Playing with KBC");
		getch();
		exit(0);
	}
	if(i == 0 )
		amount = Cash_Book[i];
	else
		amount = Cash_Book[i];
	printf("\n\n\t Mr/Miss. %s you have won Rs. %ld",name,amount);
	getch();
	if( i == 14 )
	{
		printf("\n\n\n\t\t\t  Round Comlited ");
		getch();
		getch();
		goto lbl;
	}
	clrscr();
}
	lbl:
	clrscr();
	printf("\n\n\n\n\n\n\n\n\t\t Congragulation You Have Owned Totally  Rs. %ld",amount);
	printf("\n\n\t\t\tThanks for Playing with KBC");
	printf("\n\n\n\t\tMr/Miss. %s you have won Rs. %ld",name,amount);
	getch();
	exit(0);

}



