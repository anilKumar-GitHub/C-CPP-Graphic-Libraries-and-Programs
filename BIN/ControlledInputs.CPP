#include<stdio.h>
#include<dir.h>
#include<conio.h>
#include<swrp.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

void main(){

	char word[10];
	int i,j; int k =999;
	clrscr();


	gotoxy(25,5);
	//Echo("Enter the Password : ");

	char ps[15];


	int len = getPassword(ps,15);
	printf("\n Pass word : %s\t%d\n\n Date : ",ps,len);

	getDate(ps);
	printf("\n Date : %s",ps);



	printf("\n\nEnter the number : " );

	scanf("%s",ps);
	long long int num = toInteger(ps);
	printf("\n\nNumber : %ld",num);


	printf("\n\nEnter The Random number Limit : ");
	int s,e;
	scanf("%d%d",&s,&e);
	printf("\n\n Random Number : ");

	num = getRandNum(s,e);
	printf("%d",num);


	//clrscr();
	printf("\n\n Enter Symbol : ");
	char syb[34] = {"~`!@#$%^&*()_-+={}[]\\|:;\"'<,>.?/"};
	char ch;

	for(i=0; i<strlen(syb); i++)
	if( isSpecialChar(syb[i]) )
		printf("\t Symbol = %c",syb[i]);
	else
		printf("\t Character = %c",syb[i]);

	printf("\n\n Enter Character to Test : ");
	ch = getch();

	if( isSpecialChar(ch) )		printf("%c\n\n Symbol ",ch);
	else 				printf("%c\n\n Not a Symbol ",ch);

	  printf("\n\n Enter Integer : ");
	  //int num=0;
	  num = getIntegerValue();
	  printf("\n\n Integer : %d",num);


	int dec=0;
	printf("\n\nEnter Decimal Number : ");
	scanf("%d",&dec);
	//printf("\n\nBinary Number   : %ld",DecToBin(dec));
	//printf("\n\nOctal  Number   : %ld",DecToOct(dec));
	char hex[20];
	//DecToHex(dec,hex) ;
	//printf("\n\n HexaDecimal Number : %s",DecToHex(dec));



	getch();

}

