#include<stdio.h>
#include<conio.h>
#include<awt.h>

Button r(200,180,"Red");
Button g(200,280,"Green");
Button b(200,380,"Blue");
Button btn(100,200,"  Color Changing Demo  ");

void main()	{
	//clrscr();
	Button exit(200,480,"Exit");
	r.add();
	g.add();
	b.add();
	btn.add();
	exit.add();
	setTitle("  Color Changing Demo Program.  ");
	initRunnableThread();
}


void EventListener::actionPerformed(EventListener EL)	{

	//char *string = EL.actionCommand();
	if( EL.equal("Red") )	btn.setBackground(RED);
	if( EL.equal("Green") )	btn.setBackground(GREEN);
	if( EL.equal("Blue") )	btn.setBackground(BLUE);
	if( EL.equal("Exit") )	exit(0);
}