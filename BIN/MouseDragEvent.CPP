#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

int X,Y;
int initmouse();
void showmouseptr();
void setposi(int xp, int yp);
getmousepos(int *button, int *x, int *y);
union REGS i, o;
int _X,_Y;

int    GraphDriver;		/* The Graphics device driver		*/
int    GraphMode;		/* The Graphics mode value		*/
double AspectRatio;		/* Aspect ratio of a pixel on the screen*/
int    MaxX, MaxY;		/* The maximum resolution of the screen */
int    MaxColors;		/* The maximum # of colors available	*/
int    ErrorCode;		/* Reports any graphics errors		*/
struct palettetype palette;		/* Used to read palette info	*/

void Initialize(void)
{
  int xasp, yasp;			/* Used to read the aspect ratio*/

  GraphDriver = DETECT; 		/* Request auto-detection	*/
  initgraph( &GraphDriver, &GraphMode, "..//bgi" );
  ErrorCode = graphresult();		/* Read result of initialization*/
  if( ErrorCode != grOk ){		/* Error occured during init	*/
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }

/*  getpalette( &palette );		/* Read the palette from board	*/
  //MaxColors = getmaxcolor() + 1;	/* Read maximum number of colors*/

  //MaxX = getmaxx();
  //MaxY = getmaxy();			/* Read size of screen		*/

  //getaspectratio( &xasp, &yasp );	/* read the hardware aspect	*/
  //AspectRatio = (double)xasp / (double)yasp; /* Get correction factor	*/

}

void setColor();
void hidemouse();

void main()	{
	int status, button, x, y;
	int prev_x, prev_y;
	char msg[100]="";
	char msg2[100]="";
	clrscr();
	Initialize();
	status = initmouse();

	if ( status == 1 )
		printf("Mouse support not available.\n");
	else    showmouseptr();
	cleardevice();
	//setbkcolor(BLACK);
	setColor();
	while( !kbhit() )	{																																																																																																																									      clrscr();
		lbl:
		clrscr();
		setbkcolor(BLACK);
		strcpy(msg2,"");
		showmouseptr();
		getmousepos(&button,&x,&y);
		setcolor(BLUE);
		settextstyle(3,0,3);
		sprintf(msg,"%d:%d",x,y);
		if( y > 500 && x > 350 )outtextxy(500,350,msg);
		else if( y > 500 )	outtextxy(500,x,msg);
		else if( x > 350 )   	outtextxy(y,350,msg);
		else
				outtextxy(y+5,x+15,msg);
		if(button == 1) sprintf(msg2," Left Button Pressed");
		else if(button == 2) sprintf(msg2," Right Button Pressed");
		else if(button == 3) sprintf(msg2," Both Button Pressed");
		else if(button == 4) sprintf(msg2," Middle Button Pressed");
		else if(button == 6) sprintf(msg2," Double Click");
		else if( prev_x - x != 0 || prev_y - y != 0 ) sprintf(msg2," Mouse Draged");
		prev_x = X = x, prev_y = Y = y;
		outtextxy(0,350,msg2);
		delay(40);
	}

	hidemouse();
	setposi(0,0);
	getch();
	char ch;
	ch = getch();
	if( ch != 27 )
	goto lbl;
	//getch();
}

void setColor() {
	textbackground(RED);
	for (int i=1; i<=25; i++)
	   for (int j=1; j<=80; j++) {
		gotoxy(j,i);
		cprintf(" ");
	   }
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
   int86(51,&i,&o);
}

void hidemouse()	{

	i.x.ax = 2;
	int86(51,&i,&o);
	//return 1;
}

void setposi(int xp, int yp){

	i.x.ax = 4;
	i.x.cx = xp;
	i.x.dx = yp;
	int86(51,&i,&o);
}

getmousepos(int *button, int *x, int *y)	{

	//static int bttnFlag = 0;
	//lbl:
	i.x.ax = 3;
	int86(0x33,&i,&o);
	*button = o.x.bx;
	*x = o.x.dx;
	*y = o.x.cx;
	_X = *x;
	_Y = *y;
	//*x = *x / 19.16;
	//*y = *y / 8.0886;
/*	if( bttnFlag == 0 && *button == 1 )  {
		bttnFlag = 1;
		goto lbl;
	}else if( bttnFlag == 1 && *button == 1 ){
		*button = 6;
		bttnFlag = 0;
	}else if( bttnFlag == 1 ){
		*button = 1;
		bttnFlag = 0;
	}
  */

}



