#include<stdio.h>
#include<conio.h>
#include<awt.h>

Button bttn(50,100,"Show me the meaning Of being alonly...");
Button b1(150,100,"Enable");
Button b2(150,400,"Disable Karo");

void main()	{

	b2.add();
	bttn.add();
	initRunnableThread();

}

void EventListener::actionPerformed(EventListener EL)	{

	if( EL.equal("Enable") )	{
		bttn.setEnable();
		b2.setText("Disable Karo");
	}
	if( EL.equal("Disable Karo") )	{
		bttn.setDisable();
		b2.setText("Enable");
	}
}