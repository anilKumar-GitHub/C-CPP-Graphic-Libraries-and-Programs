#include<stdio.h>
#include<conio.h>
#include<awt.h>

int size = 1, dir = 0, style = 0;


TextBox T1(100,2,10);
TextBox T2(200,2,50);
TextBox T3(150,2,75);
Window w("Testing TextBox");

void main()	{
	//w.add();
	//l.add(w);
	T1.add(w);
	T2.add(w);
	T3.add(w);
	w.add();
	w.open();
	initRunnableThread();

}

void EventListener::actionPerformed(EventListener EL)	{
}
