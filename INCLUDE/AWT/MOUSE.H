// Mouse Event Listener Interface implementation...

//int initMousePointer()
void initMousePointer()		{
	union REGS i,o;
	i.x.ax = 0;
	int86(0x33,&i,&o);
	if ( !o.x.ax )	{	
			printf(" \n\n Error while Initializing mouse ");
			exit(0);
		}
	//return ( o.x.ax );
	
}

void showMousePointer()	{
	union REGS i,o;
	i.x.ax = 1;
	int86(0x33,&i,&o);
}

void hideMousePointer()	{
	union REGS i,o;
    i.x.ax=2;
    int86(0x33,&i,&o);
}

void getMousePosition(int *button, int *x, int *y)	{
	union REGS i,o;
	i.x.ax = 3;
	int86(0x33,&i,&o);
	*button = o.x.bx;
	*x = o.x.dx;
	*y = o.x.cx;
//	gotoxy(60,1);
//	printf("              ");
//	gotoxy(61,1);
//	printf("%d : %d",*x,*y);
	//*x = *x / 8;
	//*y = *y / 8;
	//*x = *x + 1;
	//*y = *y + 1;
}



void setMousePosition(int xpos,int ypos)	{ 
	union REGS i,o;
	i.x.ax=4;
	i.x.cx=xpos;
	i.x.dx=ypos;
	int86(51,&i,&o);
}
