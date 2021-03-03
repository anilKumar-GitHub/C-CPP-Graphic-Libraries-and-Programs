#include<stdio.h>
#include<conio.h>
#include<awt.h>

int size = 1, dir = 0, style = 0, wdth = 610, hight = 230;

Label title(0,0," Happy Independance Day..! INDIA ");
Label subtitle(75,500," Vande Mataram !");
Label birth(350,0,"Happy Birth-Day VayuRoop...! ");
Label date(200,0,"    15 - 08 - 2025");
Window w("Mera Bharath Mahan...! Jai Hoo..ss");

void main()	{
	title.add(w);
	title.setFontStyle(7,4);
	title.setWidth(640);
	title.setHieght(70);
	title.setLabelColor(LIGHTRED+LIGHTGREEN);
	subtitle.add(w);
	birth.setFontStyle(1,5);
	birth.setWidth(640);
	birth.setHieght(70);
	//birth.setLabelColor(BLUE);
	birth.add(w);
	date.setFontStyle(7,6);
	date.setWidth(640);
	date.setHieght(70);
	date.setLabelColor(WHITE);
	date.add(w);
	w.add();
	w.open();
	initRunnableThread();

}

void EventListener::actionPerformed(EventListener EL)	{

}