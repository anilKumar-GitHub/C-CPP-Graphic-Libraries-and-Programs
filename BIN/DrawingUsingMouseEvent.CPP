
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>


int X,Y;
int initmouse();
void showmouseptr();
getmousepos(int *button, int *x, int *y);
union REGS i, o;
int _X,_Y;


void main()	{
	int status, gd = DETECT, gm, button, x, y;
	int prev_x, prev_y;
	char msg[100]="";
	clrscr();

	status = initmouse();

	if ( status == 1 )
		printf("Mouse support not available.\n");
	else    showmouseptr();
	lbl:
	//textcolor(BLUE);
	//textbackground(BLACK);
	while( !kbhit() )	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		//if( ( y != 1 && x > 1) || ( x != 1 && y > 1) )

		if( button == 1 && ( prev_x - x != 0 || prev_y - y != 0 ) )	{
			gotoxy(y,x);
			printf("*");
			gotoxy(80,25);
		}
		if( button == 2 && ( prev_x - x != 0 || prev_y - y != 0 ) )	{
			gotoxy(y,x);
			printf(" ");
			gotoxy(80,25);
		}

		prev_x = x, prev_y = y;
		delay(10);
		gotoxy(70,24);printf("%02d:%02d",x,y);
	}
	char ch;
	ch = getch();
	if( ch == ' ') 	clrscr();
	if( ch != 27 )	goto lbl;

}




int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
   gotoxy(Y,X);
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
	_X = *x;
	_Y = *y;
	*x = *x / 8;
	*y = *y / 8;
}

