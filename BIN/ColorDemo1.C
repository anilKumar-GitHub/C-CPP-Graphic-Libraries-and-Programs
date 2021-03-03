
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>


void main()	{
	int i;
	//float i = 0.0;
	clrscr();

	i= 0;
	while( i < 16 )	{

		drawBox(5,10,15,70,i);
		gotoxy(30,20);
		printf("                       ");
		gotoxy(30,20);
		textcolor(i);
		textbackground(BLACK);
		cprintf(" Color Value : %d",i);
		getch();
		i = i+1;
	}
	///getch();


/*	i= 0.0;
	while( i < 16.0 )	{

		drawBox(5,10,15,70,i);
		gotoxy(30,20);
		printf("                       ");
		gotoxy(30,20);
		textcolor(i);
		textbackground(BLACK);
		cprintf(" Color Value : %f",i);
		getch();
		i = i+1;
	}
*/

	//drawBox(5,10,15,60,BLUE);
	/*printf("\n %d ",BLACK);
	printf("\n %d ",BLUE);
	printf("\n %d ",GREEN);
	printf("\n %d ",CYAN);
	printf("\n %d ",RED);
	printf("\n %d ",MAGENTA);
	printf("\n %d ",BROWN);
	printf("\n %d ",LIGHTGRAY);
	printf("\n %d ",DARKGRAY);
	printf("\n %d ",LIGHTBLUE);
	printf("\n %d ",LIGHTGREEN);
	printf("\n %d ",LIGHTCYAN);
	printf("\n %d ",LIGHTRED);
	printf("\n %d ",LIGHTMAGENTA);
	printf("\n %d ",YELLOW);
	printf("\n %d ",WHITE);
	printf("\n %d ",BLINK);
	*/
getch();
}


drawBox(int trow,int lcol,int brow,int rcol,int bgClr)  {
int i,k;
textbackground(bgClr);
textcolor(YELLOW);
for(i=trow;i<=brow;i++)
for(k=lcol;k<=rcol;k++)  {
gotoxy(k,i);
cprintf(" ");
}
}
