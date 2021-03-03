#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>


int initmouse();
void showmouseptr();
getmousepos(int *button, int *x, int *y);
union REGS i, o;


void main()	{
	int status, gd = DETECT, gm, button, x, y;
	char msg[100]="";
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	status = initmouse();

	if ( status == 1 )
		printf("Mouse support not available.\n");
	else
		showmouseptr();
	printf("\n\n\n\t\t\tMenu List");
	gotoxy(10,8);
	textbackground(WHITE);
	textcolor(BLACK);
	cprintf("  Raj Hounsa  ");
	gotoxy(10,11);
	textbackground(WHITE);
	textcolor(BLACK);
	cprintf("  Volga  ");
	gotoxy(10,14);
	textbackground(WHITE);
	textcolor(BLACK);
	cprintf("  Pooja Traversal  ");
	gotoxy(10,17);
	textbackground(WHITE);
	textcolor(BLACK);
	cprintf("  Exit  ");
	    char b;
      /*	while( !kbhit() )	{
		strcpy(msg,"                                        ");
		gotoxy(60,20);
		printf("          ");
		gotoxy(60,20);
		printf("%d,%d",x,y);
		getmousepos(&button,&x,&y);
		if(button == 1 && x >= 58  && x <= 62 && y >= 65 && y <= 178 )
			strcpy(msg,"You Have Booked the Raj Hounsa Bus");
		if(button == 1 && x >= 80  && x <= 85 && y >= 80 && y <= 148  )
			strcpy(msg,"You Have Booked the Volga Bus");
		if(button == 1 && x >= 104  && x <= 111 && y >= 72 && y <= 223 )
			strcpy(msg,"You Have Booked the Pooja's Bus");
		if(button == 1 && x >= 128  && x <= 135 && y >= 73 && y <= 135 )
		{}// exit(0);

	gotoxy(25,25);
	printf("%s",msg);
	//scanf("%c",&b);
	//if(b == 27 ) break;
	} */

	gotoxy(0,0);
	_setcursortype(23);
	while( !kbhit() )	{
		strcpy(msg,"                                        ");
		getmousepos(&button,&x,&y);
		//x = wherex();
		//y = wherey();
		gotoxy(60,20);
		printf("          ");
		gotoxy(60,20);
		x = x / 8;
		y = y / 8;
		printf("%d,%d",x,y);
		//line(5,20,20,60);
		if( x == 7 && y >= 9 && y <= 22 )
			strcpy(msg,"You Have Booked the Raj Hounsa Bus");
		if( button == 1 && x == 10 && y >= 9 && y <= 17  )
			strcpy(msg,"You Have Booked the Volga Bus");
		if( button == 2 && x == 13 && y >= 9 && y <= 27 )
			strcpy(msg,"You Have Booked the Pooja's Bus");
		if( button == 1 && x == 16 && y >= 9 && y <= 16 )
		goto ex;

	gotoxy(25,25);
	printf("%s",msg);
	//scanf("%c",&b);
	//if(b == 27 ) break;
	}

	ex:
}




int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0x33,&i,&o);

}

getmousepos(int *button, int *x, int *y)	{
	i.x.ax = 3;
	int86(0x33,&i,&o);
	*button = o.x.bx;
	*x = o.x.dx;
	*y = o.x.cx;

}