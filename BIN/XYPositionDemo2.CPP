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

	textcolor(WHITE);
	while( !kbhit() )	{																																																																																																																									      clrscr();
		lbl:
		showmouseptr();
		getmousepos(&button,&x,&y);
		if( y > 73 ) 	gotoxy(y-6,x+1);
		else gotoxy(y+3,x+1);
		printf("%d:%d == %d ",x,y,button);
		if(button == 1) printf(" Left Button Pressed");
		else if(button == 2) printf(" Right Button Pressed");
		else if(button == 3) printf(" Both Button Pressed");
		else if(button == 4) printf(" Middle Button Pressed");
		else if( prev_x - x != 0 || prev_y - y != 0 ) printf("Mouse Draged");
		prev_x = X = x, prev_y = Y = y;
		delay(10);
	}
	char ch;
	ch = getch();
	if( ch != 27 )
	goto lbl;
	//getch();
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