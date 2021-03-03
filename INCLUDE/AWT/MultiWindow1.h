// Test Script : main program to test for adding objects to multiwindow and default window.

#include<stdio.h>
#include<conio.h>
#include<temp1.h>
#include<new.h>
void main()	{
	clrscr();
	Button b1(0,0,"Show me the meaning ! being alonly...");
	Button b2(100,200,"Save me");
	Button b3(420,550,"Read All");
	Button b4(100,0,"Open File");
	Label  l1(33,44,"2323");
	TextBox t1(23,23,5);
	Window w1("Hello World");
	Window w2("Save World");
	w1.add();
	b1.add();
	b2.add();
	t1.add();
	b3.add();
	b4.add();
	l1.add();
	w2.add();
	w1.open();
	getch();
	w2.open();
	getch();

	initRunnableThread();
	getch();
}


// Test Script : main program to test for title and status line .
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<temp.h>
main()	{
	clrscr();
	getch();
	clrscr();
	Button 	bttn1(10,30,"Save Button");
	TextBox txt1(10,10,15);
	Label 	lbl1(10,20,"Description of Machin");
	Window 	win("First Windows Program");
	Window w("Home Page");

	win.background = CYAN;
	w.background = CYAN;

	printf("\n\n Main : Address of object lbl1  : %u",&lbl1);
	lbl1.add();
	printf("\n\n Main : Address of object txt1  : %u",&txt1);
	txt1.add();


	printf("\n\n Main : Address of object win  : %u",&win);
	win.add();

	printf("\n\n Main : Address of object bttn1  : %u",&bttn1);
	bttn1.add();
	w.add();

	w.open();
	getch();
	w.setTitle("New Title 1");
	getch();
	w.setTitle("New Title 2");
	getch();
	w.setTitle("New Title 3");
	getch();

	printf("\n\n From Object's  ");
	printf("\n\t %s\tID : %d  ",win.Title,win.regId);
	printf("\n\t %s\tID : %d  x : %d  y1 : %d  y2 : %d",bttn1.Text,bttn1.regId,bttn1.x,bttn1.y1,bttn1.y2);
	printf("\n\t\t %d\tID : %d  x : %d  y1 : %d  y2 : %d",txt1.str_len,txt1.regId,txt1.x,txt1.y1,txt1.y2);
	printf("\n\t %s\tID : %d  x : %d  y1 : %d  y2 : %d",lbl1.Text,lbl1.regId,lbl1.x,lbl1.y1,lbl1.y2);

	printf("\n\n From Vector's ");
	getch();
	initRunnableThread();
	getch();
	bttn1.Text = "New Save";
	bttn1.x = 2;
	bttn1.y1 = 3;
	bttn1.y2 = 4;


	lbl1.Text = "Text Changed";
	txt1.str_len = 5;
	txt1.x = 7;
	txt1.y1 = 8;
	txt1.y2 = 9;

	setTitle("New Title");
	printf("\n\n From Object's  ");
	printf("\n\t %s\tID : %d  ",win.Title,win.regId);
	printf("\n\t %s\tID : %d  x : %d  y1 : %d  y2 : %d",bttn1.Text,bttn1.regId,bttn1.x,bttn1.y1,bttn1.y2);
	printf("\n\t\t %d\tID : %d  x : %d  y1 : %d  y2 : %d",txt1.str_len,txt1.regId,txt1.x,txt1.y1,txt1.y2);
	printf("\n\t %s\tID : %d  x : %d  y1 : %d  y2 : %d",lbl1.Text,lbl1.regId,lbl1.x,lbl1.y1,lbl1.y2);

	printf("\n\n From Vector's ");
	getch();
	initRunnableThread();
	setTitle("Press Enter Button");
	getch();
	setTitle("New Title 1");
	getch();
	setTitle("New Title 2");
	getch();
	setTitle("New Title 3");
	getch();

}



// Main Header File Programs 
// Temp.h  -----------------------------------------------------------------------------------------------------------------
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream.h>
#include<AWT\WINDOW.H>
#include<AWT\BUTTON.H>
#include<AWT\LABEL.H>
#include<AWT\TEXTBOX.H>
#include<AWT\MOUSE.H>
#include<AWT\stdfun.h>
#include<AWT\GrpInit.h>
#include<AWT\defWind.h>


// Used to specify the type Object currently used by ToolKit...
enum objectTypeSpecifier { _WINDOW_ = 1, _BUTTON_, _LABEL_, _TEXTBOX_, _MENU_};
static int IX = 0;		// holds the count for number of objcted created runtime...
unsigned int multiWindow = 0;
unsigned int currentBgClr = LIGHTGRAY;
int initGraphFlag = 0;
void openAllDefaultWindowObjects();


class Abstract_Windows_DOS_Mode_ToolKit {
    public:
		Window 	*OW;
		Button	*OB;
		Label	*OL;
		TextBox	*OT;
		unsigned int objType;
		
	Abstract_Windows_DOS_Mode_ToolKit(){}

	//Window  operator [](int _i)	{ return *(OW+_i); }
	Button  operator [](int _i)	{ return *(OB+_i); }

	int putWindowObj(Window *wObj)	{
		OB = NULL;
		OL = NULL;
		OT = NULL;
		objType = _WINDOW_;
		OW = wObj;
		//printf("\n From Windows  Kit Class\t : %u  :  %u\t Type  : %d",wObj,OW,objType);
	}
	int putButtonObj(Button *bObj)	{
		OW = NULL;
		OL = NULL;
		OT = NULL;
		objType = _BUTTON_;
		OB = bObj;
		//printf("\n From Button  Kit Class\t : %u  :  %u\t Type  : %d",bObj,OB,objType);
	}
	int putLabelObj(Label *lObj)	{
		OW = NULL;
		OB = NULL;
		OT = NULL;
		objType = _LABEL_;
		OL = lObj;
		//printf("\n From Label   Kit Class\t : %u  :  %u\t Type  : %d",lObj,OL,objType);
	}

	int putTextBoxObj(TextBox *tObj)	{
		OW = NULL;
		OB = NULL;
		OL = NULL;
		objType = _TEXTBOX_;
		OT = tObj;
		//printf("\n From TextBox Kit Class\t : %u  :  %u\t Type  : %d",tObj,OT,objType);
	}
};
	
template <class Tbttn>
int addButton(Tbttn TemplateObjButton)	{ Kit[IX].putButtonObj(TemplateObjButton);		return IX++;}

template <class Tlbl>
int addLabel(Tlbl TemplateObjLabel)   	{ Kit[IX].putLabelObj(TemplateObjLabel); 		return IX++;}

template <class Ttxt>
int addTextBox(Ttxt TemplateObjTextBox) { Kit[IX].putTextBoxObj(TemplateObjTextBox);	return IX++;}

template <class Twind>
int addWindow(Twind TemplateObjWindow)	{ Kit[IX].putWindowObj(TemplateObjWindow); 		return IX++;}

Abstract_Windows_DOS_Mode_ToolKit 	*Kit;

static unsigned int runningThreadFlag = 0; // To make thread to run only once a time
void initRunnableThread()	{
	register int z;
		
			
		if( runningThreadFlag == 1 ) return;
		runningThreadFlag = 1;		// set runningThreadFlag to 1 to indicate thread already called by main program because to avoid looping
		
		if( multiWindow == 0 ) {		//printf("\n\nDefault Window\n\n");
			openAllDefaultWindowObjects();
			//openDefalutWindow();
		}else {							//printf(" Multi Window\n\n");
		}
		
	for( z=0; z < IX; z++ ) 	{
		if( Kit[z].objType == _WINDOW_ ) {
		//printf("\n %d: %u  W : %s\tID : %d  ",z,Kit[z].OW,Kit[z].OW->Title,Kit[z].OW->regId);
		}
			
		if( Kit[z].objType == _BUTTON_ ) {
		//printf("\n %d: %u  B : %s\t Id : %d\tx : %d\ty1 : %d\ty2 : %d",z,Kit[z].OB,Kit[z].OB->Text,Kit[z].OB->regId,Kit[z].OB->x1,Kit[z].OB->y1,Kit[z].OB->y2);
		}	
		if( Kit[z].objType == _LABEL_ ) {
		//printf("\n %d: %u  L : %s\t Id : %d\tx : %d\ty1 : %d\ty2 : %d",z,Kit[z].OL,Kit[z].OL->Text, Kit[z].OL->regId,Kit[z].OL->x,Kit[z].OL->y1,Kit[z].OL->y2);
		}
			
		if( Kit[z].objType == _TEXTBOX_ ) {
		//printf("\n %d: %u  T : %d\tID : %d  x : %d  y1 : %d  y2 : %d",z,Kit[z].OT,Kit[z].OT->str_len,Kit[z].OT->regId,Kit[z].OT->x,Kit[z].OT->y1,Kit[z].OT->y2);
		}			
	}
	
	getch();
}


void openAllDefaultWindowObjects()	{

int i=0,z=0;
	for( i = 0, z = 0; z < IX; z++ ) 	{
		if( Kit[z].objType == _WINDOW_ )	{
			Kit[z].OW->winOpen = 0;
			//printf(" W -> %02d  :  Windows Open Flag wiht index and regid :  %d \n",z,Kit[z].OW->winOpen);
		}
		if( Kit[z].objType == _BUTTON_ )	{
			Kit[z].OB->winOpen = 1;
			//printf(" B -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OB->winOpen);
		}
		else if( Kit[z].objType == _LABEL_ ){
			Kit[z].OL->winOpen = 1;
			//printf(" L -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OL->winOpen);
		}
		else if( Kit[z].objType == _TEXTBOX_ ){
			Kit[z].OT->winOpen = 1;
			//printf(" T -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OT->winOpen);
		}
	}
	getch();
}





//---------------------------------------------------------------------------------------------------------------------------
// Button header File

#include<string.h>
extern unsigned int multiWindow;
extern unsigned int currentBgClr;

extern int getRegID();
template <class Tbttn>
int addButton(Tbttn TemplateObjButton);

class Button {
   public:
	char *Text;
	int regId, regFlag, Active, Enabled, winOpen, Index;
	int x1, y1, x2, y2, TextLen, bttnBgClr, bttnTxtClr;
	public:
	Button(){
		Text   = "NotAssigned";
		regId  = Index = -1;
		x1 = y1 = x2 = y2 = -1;
		Active = Enabled = regFlag = winOpen = 0;
	}

	Button( int _x, int _y, char *_name );

	void add(){

		if( regFlag == 0 )	{
			Index 	= addButton(this);
			regId 	= getRegID();
			regFlag = 1;
			winOpen = 0;
		}
		//printf("\n From Buttons Class \t\t : %u",this);
		//drawButton(bttnBgClr, bttnTxtClr, 0);
	}

	void add(Window &obj){
		if( regFlag == 0 )	{
			Index = addButton(this);
			regId = getRegID();
			obj.regObject(regId,Index);
			regFlag = 1;
			winOpen = 0;
		}
		multiWindow = 1;
		//printf("\n\n\n From Buttons Class \t\t : regFlag : %d",regFlag);
		//drawButton(bttnBgClr, bttnTxtClr, 0);
	}
	void drawButton( int bkclr, int frgclr, int press);
	void pressButton();
};

//view port with respect to window co-ordinate values
Button Button::Button( int _x, int _y, char *_name )	{
	Text  	= _name;
	TextLen = strlen( _name );
	regId 	= Index 	= -1;
	Active 	= Enabled 	= regFlag	= winOpen	= 0;

	x1 = _x + 1;
	y1 = _y + 1;
	x2 = x1 + 20;
	y2 = _y + ( TextLen * 8 ) + 15;
	bttnBgClr = BLACK;
	bttnTxtClr = WHITE;
	Enabled = 1 ;
	Active = 0;
	regFlag = 0;
}


void Button::drawButton(int bkclr, int frgclr, int press) {
	
	if( winOpen == 0 ) return;
	hideMousePointer();
	setviewport( 0, 19, 639, 464, 1);
	if( press == 0 )	setfillstyle(SOLID_FILL,BLACK);	// set 3-D button back face color
	else				setfillstyle(SOLID_FILL,currentBgClr);	// make button place to invisible using window background color
	bar(y1+6, x1+8, y2+6, x2+6);	

	setfillstyle(SOLID_FILL,bkclr);		// set  3-D button front face color
	bar(y1, x1, y2, x2);

	if( press == 0 )	{	// draw the rectangle boxes around the button
		setcolor( DARKGRAY );
		rectangle( y1, x1,   y2, x2);
		rectangle( y1, x1+1, y2, x2-1);
		rectangle( y1, x1+2, y2, x2-2);

		setcolor(bttnTxtClr);		// write Text on the button
		settextstyle(0, 0, 1);
		gprintf(y1+6,x1+7,"%s",Text);
	}
	showMousePointer();
}

void Button::pressButton() {
	//if( winOpen == 0 ) return;
	drawButton(currentBgClr,0,1);	// make button unvisible 
	hideMousePointer();	
	setviewport( 0, 19, 639, 464, 1);
	setfillstyle(SOLID_FILL,bttnBgClr);	// move the button to some new possition 
	bar(y1+6, x1+8, y2+6, x2+6-1);

	setcolor( DARKGRAY );				// draw rectangle to new possitioned button
	rectangle( y1+6, x1+8, y2+6, x2+6);
	rectangle( y1+6, x1+1+8, y2+6, x2-1+6);
	rectangle( y1+6, x1+2+8, y2+6, x2-2+6);

	setcolor( WHITE );
	settextstyle(0, 0, 1);
	gprintf(y1+13,x1+15,"%s",Text);

	delay(150);		// make some visible delay for effect of moving button back-to-front
	drawButton(bttnBgClr,bttnTxtClr,0);	// redraw the original button
}
/*	//view port with respect to button values
void Button::drawButton() {

	hideMousePointer();

	setviewport( y1+5, x+6, y2+5, x+20+6, 1);
	setfillstyle(SOLID_FILL,BLACK);		// set it to background color
	bar(0,0,y2-y1,20);
	
	setviewport( y1, x, y2, x+20, 1);
	bar( 0, 0, y2-y1, 20);

	setcolor( DARKGRAY );
	rectangle( 0, 0, y2-y1, 20);
	rectangle( 0, 2, y2-y1, 18);
	rectangle( 0, 1, y2-y1, 19);
	
	setviewport(y1+5,x+4,y2-1,x+18,1);
	gprintf(3,3,"%s",Text);
	showMousePointer();
}*/




//----------------------------------------------------------------------------------------------------------------------------
// Text Box Header File
extern unsigned int multiWindow;
extern int getRegID();
template <class Ttxt>
int addTextBox(Ttxt TemplateObjTextBox);

class TextBox {
   public:
	char *Text;
	int str_len, txtClr, boxClr, pos, Index;
	int regId, regFlag, Active, Enabled, winOpen;
	int x, y1, y2, lblLen, bttnBgClr, bttnTxtClr;
	public:
	TextBox(){
		Text = " Not Assigned ";
		regId = str_len = Index = -1;
		x = y1 = y2 = -1;
		Active = Enabled = regFlag = winOpen = 0; 
	}
	
	TextBox( int _x, int _y, int _size )	{
		str_len = _size;
		x = _x;
		y1 = _y;
		y2 = _y + str_len;
		regId = Index = -1;
		Active = Enabled  = regFlag = winOpen = 0; 
		//printf("\n From TextBox Class Constructor \t : regFlag : %d\n",regFlag);
	}

	void add(){
		if( regFlag == 0 )	{
			Index = addTextBox(this);
			regId = getRegID();
			regFlag = 1;
			winOpen = 0;
		}
		//printf("\n From TexBoxt Class \t\t : %u",this);
	}
	
	void add(Window &obj){
		if( regFlag == 0 )	{
			Index = addTextBox(this);
			regId = getRegID();
			obj.regObject(regId,Index);
			regFlag = 1;
			winOpen = 0;
		}
		multiWindow = 1;
		//printf("\n From Buttons Class \t\t : %u",this);
	}
};



//-----------------------------------------------------------------------------------------------------------------------
// Label header File

extern unsigned int multiWindow;
extern int getRegID();
template <class Tlbl>
int addLabel(Tlbl TemplateObjLabel);

class  Label{

   public:
	char *Text;
	int	 regId, regFlag, Active, Enabled, winOpen, Index;
	int	 x, y1, y2, lblLen, bttnBgClr, bttnTxtClr;
	public:
	Label(){
		Text   = " Not Assigned ";
		regId  = lblLen = Index = -1;
		x = y1 = y2 = -1;
		Active = Enabled = regFlag = winOpen = 0; 
	}
	Label(int _x, int _y, char* _dsc)	{

		Text = _dsc;
		x = _x;
		y1 = _y;
		y2 = _y*10;
		regId = Index = lblLen = -1;
		Active = Enabled = regFlag = winOpen = 0;
	}

	void add(){
		if( regFlag == 0 )	{
			Index = addLabel(this);
			regId = getRegID();
			regFlag = 1;
			winOpen = 0;
		}
	//printf("\n From Label Class \t\t : %u",this);
	}
	
	void add(Window &obj){
		if( regFlag == 0 )	{
			Index = addLabel(this);
			regId = getRegID();
			obj.regObject(regId,Index);
			regFlag = 1;
			winOpen = 0;
		}
		multiWindow = 1;
		//printf("\n From Buttons Class \t\t : %u",this);
	}

	void drawButton(){}
}; 




//-------------------------------------------------------------------------------------------------------------------------
// windows header file
#include<stdarg.h>
extern void initMousePointer();
extern void showMousePointer();
extern void hideMousePointer();
extern int 	getRegID();
extern int 	initGraphFlag;
extern unsigned int currentBgClr;
template <class Twin>
int addWindow(Twin TemplateObjWindow);
int gprintf( int xloc, int yloc, char *fmt, ... );

class Window {
   public:
	char *Title;
	int  regId, regFlag, Active, Enabled, Index, winOpen, background;
	int  arrayOfRegId[512],arrayOfIndex[512],arrCount;
 
  public:
	Window();
	Window( char *_title );
	void add();
	void regObject( int _ID_, int _ix_ );
	void displayReg();
	int checkRegNo(int id);
	void drawWindow();
	void setTitle(char *title);
	void windowOptionLabel();
	void backwardButton();
	void forwardButton();
	void setStatusLine(char *status);
	void timeLine();
	
	int open()		{
		int z,i, flag = 0;
		if( winOpen == 1 )	return 1;
		winOpen = 1;
		
		if( initGraphFlag == 0 )	{
			initGraphicMode();
			initGraphFlag  =  1;
			initMousePointer();
		}
		
		/*currentBgClr = background;
		hideMousePointer();
		drawWindow();
		showMousePointer();
		*/
		for( i = 0, z = 0; z < IX; z++ ) 	{
			// flag is used to indicate currect object is registered in window
				if( z == arrayOfIndex[i] )	{ i++; flag = 1;}	

			if( Kit[z].objType == _WINDOW_ )	{
				if( Kit[z].OW->regId != regId && z != Index)		Kit[z].OW->winOpen = 0;
				//printf(" W -> %02d  :  Windows Open Flag wiht index and regid :  %d \n",z,Kit[z].OW->winOpen);
			}
			if( Kit[z].objType == _BUTTON_ )	{
				if( flag == 1 )		Kit[z].OB->winOpen = 1;
				else 				Kit[z].OB->winOpen = 0;
				//printf(" B -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OB->winOpen);
			}
			else if( Kit[z].objType == _LABEL_ ){
				if( flag == 1 )		Kit[z].OL->winOpen = 1;
				else 				Kit[z].OL->winOpen = 0;
				//printf(" L -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OL->winOpen);
			}
			else if( Kit[z].objType == _TEXTBOX_ ){
				if( flag == 1 )		Kit[z].OT->winOpen = 1;
				else 				Kit[z].OT->winOpen = 0;
				//printf(" T -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OT->winOpen);
			}
		flag = 0;
		}
	}
};

Window::Window(){
	Title = "NONAME : UNTITLED WINDOW";
	arrCount 	= 0;
	regId    	= Index = -1;
	Active		= Enabled = regFlag = winOpen = 0;
	background 	= LIGHTGRAY;
	for( int i = 0; i < 512; i++ )	{
		arrayOfRegId[i] = 0;
		arrayOfIndex[i] = 0;
	}
}

Window::Window( char *_title )	{
	Title 	   = _title;
	arrCount   = 0;
	regId  	   = Index = -1;
	background = LIGHTGRAY ;
	Active 	   = Enabled = regFlag = winOpen = 0;
	for( int i = 0; i < 512; i++ )	{
		arrayOfRegId[i] = 0;
		arrayOfIndex[i] = 0;
	}
}


void Window::add()  {
	if( regFlag == 0 )	{
		Index 	= addWindow(this);
		regId 	= getRegID();
		regFlag = 1;
	}
	//printf("\n From Windows Class \t\t : %u",this);
}

void Window::regObject( int _ID_, int _ix_ )	{
	arrayOfRegId[ arrCount ]   = _ID_ ;
	arrayOfIndex[ arrCount++ ] = _ix_ ;
}

void Window::displayReg()	{
	//printf("\n\n Windows Registration list of :  %d\n",regId);
	//for( int i=0; i < arrCount; i++ )
	//printf("\n\n RegID  :  %d\t:  Index : %d",arrayOfRegId[i], arrayOfIndex[i]);
}

int Window::checkRegNo(int id)	{

	for( int i=0; i < arrCount; i++ )
		if( id == arrayOfRegId[i] )	return 1;
	return 0;
}

void Window::drawWindow()	{
	
	currentBgClr = background;
	hideMousePointer();
	cleardevice();
	setviewport( 0, 0, 639, 479, 1 );
	setfillstyle(SOLID_FILL, background);	
	bar( 0, 16, 639, 479 );	
//	getch();
	
	setfillstyle(SOLID_FILL, BLACK);
	bar( 0, 0, 639, 18 );
	setcolor( LIGHTGREEN );
	rectangle( 0, 0, 639, 18 );
//	getch();
	
	bar( 0,465,639,479);
	setcolor( LIGHTGREEN );
	rectangle( 0,465,639,479);
//	getch();
	
	setviewport( 62, 0, 530, 18, 1 );
	setcolor( WHITE );
	settextstyle(0, 0, 1);
	gprintf( 0, 7, "%s", Title);
//	getch();
	
	setviewport( 601, 0, 639, 18, 1 );
	setfillstyle(SOLID_FILL, LIGHTRED);
	setcolor(RED);
	fillellipse( 24, 9, 11, 8 );
	settextstyle(0, 0, 2);
	setcolor( BROWN );
	gprintf( 18, 1, "x");
//	getch();
	windowOptionLabel();
//	getch();
	backwardButton();
//	getch();
	forwardButton();
//	getch();
	timeLine();
	showMousePointer();
}
	
void Window::setTitle(char *title)	{

	hideMousePointer();
	Title = title;
	if ( winOpen == 0 )	return;
	setviewport( 62, 0, 535, 18, 1 );
	clearviewport();
	setfillstyle(SOLID_FILL, BLACK);
	bar( 0, 0, 470, 18);
	setcolor( LIGHTGREEN );
	//line( 556, 0, 556, 18);
	line( 0, 0, 480, 0);
	line( 0, 18, 480, 18);
	
	setviewport( 62, 0, 530, 18, 1 );
	setcolor( WHITE );
	settextstyle(0, 0, 1);
	gprintf( 0, 7, "%s", Title);
	showMousePointer();
}

void Window::windowOptionLabel()	{

	hideMousePointer();
	setviewport( 0, 0, 16, 18, 1 );
	setcolor( LIGHTRED );
	setlinestyle(0, 0,1);
	line( 7, 7, 15, 7);
	line( 7, 10, 15, 10);
	line( 7, 13, 15, 13);
	showMousePointer();		
}
	
void Window::backwardButton()	{
	hideMousePointer();
	setviewport( 20, 0, 38, 18, 1 );
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	setcolor( GREEN );
	fillellipse( 8, 10, 8, 6 );
	
	settextstyle(0, 0, 1);
	setcolor( BLACK );
	gprintf( 4, 7, "%c", 17 );
	showMousePointer();
}
	
void Window::forwardButton()	{
	hideMousePointer();
	setviewport( 39, 0, 60, 18, 1 );
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	setcolor( GREEN );
	fillellipse( 8, 10, 8, 6 );
	
	settextstyle(0, 0, 1);
	setcolor( BLACK );
	gprintf( 6, 7, "%c", 16 );
	showMousePointer();
}

void Window::setStatusLine(char *status)	{

	hideMousePointer();
	setviewport( 0, 465, 540, 479, 1 );
	clearviewport();
	
	setfillstyle(SOLID_FILL, BLACK);
	bar(0,0,540,14);
	setcolor( LIGHTGREEN );
	rectangle(0,0,540,14);
	
	setviewport( 0, 465, 520, 479, 1 );
	setcolor( WHITE );
	settextstyle(0, 0, 1);
	gprintf( 5, 4, "%s", status);	
	showMousePointer();
}

void Window::timeLine()	{
		
	hideMousePointer();
	setviewport( 541, 465, 639, 479, 1 );
	setfillstyle(SOLID_FILL, LIGHTGREEN);			
	bar( 0, 0, 98, 14 );
	setcolor(GREEN);
	rectangle( 0, 0, 98, 14 );
	setcolor(BLACK);
	settextstyle(0, 0, 1);
	gprintf( 5, 4, "Time Line");
	showMousePointer();
}


int gprintf( int xloc, int yloc, char *fmt, ... )
{
  va_list  argptr;			/* Argument list pointer	*/
  char str[140];			/* Buffer to build sting into	*/
  int cnt;				/* Result of SPRINTF for return */

  va_start( argptr, fmt );		/* Initialize va_ functions	*/

  cnt = vsprintf( str, fmt, argptr );	/* prints string to buffer	*/
  outtextxy( xloc, yloc, str );	/* Send string in graphics mode */
  va_end( argptr );			/* Close va_ functions		*/

  return( cnt );			/* Return the conversion count	*/

}

//-------------------------------------------------------------------------------------------------------------------------
// Default Windows Management



int background = LIGHTGRAY;
extern unsigned int currentBgClr;
extern int initGraphFlag;
static int defWindowOpen = 0;
char *Title = "Defalut Windows : Unname Workspace.";

	int  openDefalutWindow();
	void drawDefaultWindow();
	void setTitle(char *title);
	void windowOptionLabel();
	void backwardButton();
	void forwardButton();
	void setStatusLine(char *status);
	void timeLine();

	int openDefalutWindow()	{
		
		if ( defWindowOpen == 1 ) return 0;
		if( initGraphFlag == 0 )	{
			initGraphicMode();
			initGraphFlag  =  1;
			initMousePointer();
		}
		defWindowOpen = 1;
		hideMousePointer();
		drawDefaultWindow();
		showMousePointer();
	}

	void drawDefaultWindow()	{
		currentBgClr = background;
		cleardevice();
		setviewport( 0, 0, 639, 479, 1 );
		setfillstyle(SOLID_FILL, background);	
		bar( 0, 16, 639, 479 );	
		
		setfillstyle(SOLID_FILL, BLACK);
		bar( 0, 0, 639, 18 );
		setcolor( LIGHTGREEN );
		rectangle( 0, 0, 639, 18 );

		bar( 0,465,639,479);
		setcolor( LIGHTGREEN );
		rectangle( 0,465,639,479);
		
		setviewport( 62, 0, 530, 18, 1 );
		setcolor( WHITE );
		settextstyle(0, 0, 1);
		gprintf( 0, 7, "%s", Title);

		backwardButton();
		forwardButton();
		windowOptionLabel();
		timeLine();

		setviewport( 601, 0, 639, 18, 1 );
		setfillstyle(SOLID_FILL, LIGHTRED);
		setcolor(RED);
		fillellipse( 24, 9, 11, 8 );
		settextstyle(0, 0, 2);
		setcolor( BROWN );
		gprintf( 18, 1, "x");
	}
	
	void setTitle(char *title)	{
	
		Title = title;
		if ( defWindowOpen == 0 )	return;
		hideMousePointer();
		setviewport( 62, 0, 535, 18, 1 );
		clearviewport();

		setfillstyle(SOLID_FILL, BLACK);
		bar( 0, 0, 470, 18);
		setcolor( LIGHTGREEN );
		//line( 556, 0, 556, 18);
		line( 0, 0, 480, 0);
		line( 0, 18, 480, 18);
		
		setviewport( 62, 0, 530, 18, 1 );
		settextstyle(0, 0, 1);
		setcolor( WHITE );		
		gprintf( 0, 7, "%s", Title);
		showMousePointer();
	}

	void windowOptionLabel()	{
	
		hideMousePointer();
		setviewport( 0, 0, 16, 18, 1 );
		setcolor( LIGHTRED );
		setlinestyle(0, 0,1);
		line( 7, 7, 15, 7);
		line( 7, 10, 15, 10);
		line( 7, 13, 15, 13);
		showMousePointer();		
	}
	
	void backwardButton()	{
		hideMousePointer();
		setviewport( 20, 0, 38, 18, 1 );
		setfillstyle(SOLID_FILL, DARKGRAY);
		setcolor( DARKGRAY );
		fillellipse( 8, 10, 8, 6 );
		
		settextstyle(0, 0, 1);
		setcolor( BLACK );
		gprintf( 4, 7, "%c", 17 );
		showMousePointer();
	}
	
	void forwardButton()	{
		hideMousePointer();
		setviewport( 39, 0, 60, 18, 1 );
		setfillstyle(SOLID_FILL, DARKGRAY);
		setcolor( DARKGRAY );
		fillellipse( 8, 10, 8, 6 );
		
		settextstyle(0, 0, 1);
		setcolor( BLACK );
		gprintf( 6, 7, "%c", 16 );
		showMousePointer();
	}

	void setStatusLine(char *status)	{
		
		if ( defWindowOpen == 0 )	return;
		hideMousePointer();
		setviewport( 0, 465, 540, 479, 1 );
		clearviewport();
		
		setfillstyle(SOLID_FILL, BLACK);
		bar(0,0,540,14);
		setcolor( LIGHTGREEN );
		rectangle(0,0,540,14);
		
		setviewport( 0, 465, 520, 479, 1 );
		setcolor( WHITE );
		settextstyle(0, 0, 1);
		gprintf( 5, 4, "%s", status);	
		showMousePointer();
	}

	void timeLine()	{
		
		hideMousePointer();
		setviewport( 541, 465, 639, 479, 1 );
		setfillstyle(SOLID_FILL, LIGHTGREEN);			
		bar( 0, 0, 98, 14 );
		setcolor(GREEN);
		rectangle( 0, 0, 98, 14 );
		setcolor(BLACK);
		settextstyle(0, 0, 1);
		gprintf( 5, 4, "Time Line");
		showMousePointer();
	}



//-------------------------------------------------------------------------------------------------------------------------
// special Function stdfun.h

int getRegID() {
	static int __counter_ = 0 ;
	return ++__counter_;
}

int getKey(void)
{
   union REGS in, out;
   in.h.ah = 0x08;
   int86(0x21, &in, &out);
   if (out.h.al == 0)
   {
      return(getKey()+0x100);
   }
   else
   {
      return(out.h.al);
   }
}




// Test Script : for multi-windows management.
#include<stdio.h>
#include<conio.h>
#include<temp1.h>
#include<new.h>

main()	{
	clrscr();
	getch();
	clrscr();
	Button 	btn(10,30,"Save Button");
	TextBox txt(10,10,15);
	Label 	lbl(10,20,"Description of Machin");
	Window 	win("First Window Program"),w1,w2;
	Button  b1,b2,b3;
	TextBox t1,t2,t3;
	Label   l1,l2,l3;

	//w.add();
	b1.add(win);  b2.add(win);  l3.add(win);
	t1.add(w1);  t2.add(w1);  b3.add(w1);
	l1.add(w2);  l2.add(w2);  t3.add(w2);
	btn.add(win);
	lbl.add(w1);
	txt.add(w2);
	win.add();
	w1.add();
	w2.add();
	printf("\n\n From Vector's ");
	initRunnableThread();
	getch();
	clrscr();
	win.displayReg();
	getch();
	clrscr();
	w1.displayReg();
	w2.displayReg();
	getch();
	clrscr();
	win.open();
	getch();
	clrscr();
	w1.open();
	getch();
	clrscr();
	w2.open();
	getch();
}





//--------------------------------------------------------------------------------------------------------------------
// mouse header file 

// Mouse Event Listener Interface implementation...
class MouseListener {
	public:
		int  initmouse();
		void showmouseptr();
		void getmousepos(int*,int*,int*);
};

int MouseListener::initmouse()		{
	union REGS i,o;
	i.x.ax = 0;
	int86(0x33,&i,&o);
	return ( o.x.ax );
}

void MouseListener::showmouseptr()	{
	union REGS i,o;
	i.x.ax = 1;
	int86(0x33,&i,&o);
}

void MouseListener::getmousepos(int *button, int *x, int *y)	{
	union REGS i,o;
	i.x.ax = 3;
	int86(0x33,&i,&o);
	*button = o.x.bx;
	*x = o.x.dx;
	*y = o.x.cx;
	*x = *x / 8;
	*y = *y / 8;
	*x = *x + 1;
	*y = *y + 1;
}