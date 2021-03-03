#include<stdio.h>
#include<conio.h>
#include<awt.h>

int size = 1, dir = 0, style = 0, wdth = 610, hight = 230;

Button FN(300,100,"Font Style Next");
Button H(300,250,"Horizontal");
Button IS(300,360,"Increament Size");
Button FP(400,100,"Font Style Prev");
Button DS(400,360,"Decrement Size");
Button IW(300,5,"Inc Width");
Button IH(300,520,"Inc Hieght");
Button DW(400,5,"Dec Width");
Button DH(400,520,"Dec Hieght");
Label lbl(50,10,"Happy Independance Day..! INDIA ");
Window w("Testing Label");

void main()	{
	//w.title("Font Demo");
	FN.add();
	H.add();
	IS.add();
	FP.add();
	DS.add();
	lbl.add();
	IW.add();
	IH.add();
	DW.add();
	DH.add();
	lbl.setFontStyle(7,4);
	FP.setDisable();
	DS.setDisable();
	lbl.setWidth(wdth);
	lbl.setHieght(hight);
	w.add();
	w.open();
	w.setTitle("Font Demo");
	initRunnableThread();

}

void EventListener::actionPerformed(EventListener EL)	{

	if( EL.equal(FN) )	{
		if( style == 9 )	FN.setDisable();
		if( style == 0 ) 	FP.setEnable();
		lbl.setFontStyle(++style);
		//lbl.setLabel( FN );
		gotoxy(20,24);
		printf("%02d",style);
	}
	if( EL.equal("Horizontal") )	{
		lbl.setFontDirection(++dir);
		//lbl.setLabel( H );
		gotoxy(35,24);
		printf("%02d",dir);
		H.setText("Vertical");
	}
	if( EL.equal(IS) )	{
		lbl.setFontSize(++size);
		//lbl.setLabel( IS );
		gotoxy(60,24);
		printf("%02d",size);
		if( size == 10 ) IS.setDisable();
		if( size == 2  ) DS.setEnable();
	}
	if( EL.equal(FP) )	{
		if( style == 10 ) FN.setEnable();
		if( style == 1 ) FP.setDisable();
		lbl.setFontStyle(--style);
		//lbl.setLabel( FP );
		gotoxy(20,24);
		printf("%02d",style);
	}
	if( EL.equal("Vertical") )	{
		lbl.setFontDirection(--dir);
		//lbl.setLabel( H );
		gotoxy(35,24);
		printf("%02d",dir);
		H.setText("Horizontal");
	}
	if( EL.equal(DS) )	{
		lbl.setFontSize(--size);
		//lbl.setLabel(DS);
		gotoxy(60,24);
		printf("%02d",size);
		if( size == 1 ) DS.setDisable();
		if( size == 9 ) IS.setEnable();
	}
	if( EL.equal(IW) )	{
		wdth +=10;
		lbl.setWidth(wdth);
		gotoxy(2,24);
		printf("%02d",wdth);
	}
	if( EL.equal(IH) )	{
		hight +=10;
		lbl.setHieght(hight);
		gotoxy(70,24);
		printf("%02d",hight);
	}
	if( EL.equal(DW) )	{
		wdth -=10;
		lbl.setWidth(wdth);
		gotoxy(2,24);
		printf("%02d",wdth);
	}
	if( EL.equal(DH) )	{
		hight -=10;
		lbl.setHieght(hight);
		gotoxy(70,24);
		printf("%02d",hight);
	}
}