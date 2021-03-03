#include<stdarg.h>
#include<string.h>
#include<time.h>
struct tm *local;  // These are Local and Universal time function
char str[20],prev[20];
time_t  lt ;

extern void initMousePointer();
extern void showMousePointer();
extern void hideMousePointer();
extern int 	getRegID();
extern int 	initGraphFlag;
extern unsigned int currentBgClr;
extern unsigned int currentWindow;
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
	int  checkRegNo(int id);
	void drawWindow();
	void setTitle(char *title);
	void windowOptionLabel();
	void backwardButton();
	void forwardButton();
	void setStatus(char *status);
	static void timeLine();
	void setBackground(int _bkClr);


	int open()  {
		register int z,i;
		int flag = 0;
		if( winOpen == 1 )	return 1;
		winOpen = 1;

		if( initGraphFlag == 0 )	{
			initGraphicMode();
			initGraphFlag  =  1;
			initMousePointer();
		}
		currentWindow = Index;
		currentBgClr  = background;

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

		if( !runningThreadFlag ) return 1;
		drawWindow();
		createWindow_And_AddObjectToWindowScreen();
		return 1;
	}

	void createWindow_And_AddObjectToWindowScreen()	{

		register int z,i;
		// before adding object create window...
		for( i = 0; i < arrCount; i++ ) 	{
				z = arrayOfIndex[i];	// arrayOfIndex holds all object index and initialized to z-index

			if( Kit[z].objType == _BUTTON_ )	{	// Test regId and winOpen flag of object...
				if( Kit[z].OB->getRegistrationID() == arrayOfRegId[i] && Kit[z].OB->TestWindowIsOpened() )
					// call the function for displaying the button
					if( Kit[z].OB->isEnabled() )	Kit[z].OB->drawButton( Kit[z].OB->getBackground(), 0 );
					else 							Kit[z].OB->drawButton(LIGHTGRAY,2);
			}
			if( Kit[z].objType == _LABEL_ )	{	// Test regId and winOpen flag of object...
				if( Kit[z].OL->getRegistrationID() == arrayOfRegId[i] && Kit[z].OL->TestWindowIsOpened() )
					// call the function for displaying the button
					Kit[z].OL->drawLabel( 0 );
			}
			if( Kit[z].objType == _TEXTBOX_ )	{	// Test regId and winOpen flag of object...
				if( Kit[z].OT->getRegistrationID() == arrayOfRegId[i] && Kit[z].OT->TestWindowIsOpened() )
					// call the function for displaying the button
					Kit[z].OT->drawTextBox(0);
			}
		}
	}


};

Window::Window(){
	Title 		= "NONAME : UNTITLED WINDOW";
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
	if( checkRegNo( _ID_ ) )	return;
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
void Window::setBackground(int _bkClr)	{
	background = _bkClr;
	currentBgClr = _bkClr;
	if( !winOpen ) return;
	hideMousePointer();
	setviewport( 0, 0, 639, 479, 1 );
	setfillstyle(SOLID_FILL, background);
	bar( 0, 19, 639, 464 );
	createWindow_And_AddObjectToWindowScreen();
	showMousePointer();
}
void Window::drawWindow()	{

	if( !winOpen ) return;
	currentBgClr = background;
	hideMousePointer();
	cleardevice();
	setlinestyle(0, 0,  1);
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

/* Window Status Line design */
	setviewport( 0, 465, 540, 479, 1 );
	clearviewport();
	setlinestyle(0, 0, 1);
	setfillstyle(SOLID_FILL, BLACK);
	bar(0,0,540,14);
	setcolor( LIGHTGREEN );
	rectangle(0,0,540,14);


//	getch();
//	showMousePointer();
	windowOptionLabel();
//	getch();
	backwardButton();
//	getch();
	forwardButton();
//	getch();
	timeLine();
}

void Window::setTitle(char *title)	{

	Title = title;
	if ( !winOpen )	return;
	hideMousePointer();
	setviewport( 62, 0, 535, 18, 1 );
	clearviewport();
	setlinestyle(0, 0,  1);
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


void Window::setStatus(char *status)	{
	if ( !winOpen )	return;
	delay(20);
	hideMousePointer();
	setviewport( 5, 468, 535, 477, 1 );
	setfillstyle(SOLID_FILL, BLACK);
	bar(0,0,535,14);
	
	if( strlen(status) > 66 )	{
		*(status+63) = '.';
		*(status+64) = '.';
		*(status+65) = '.';
		*(status+66) = '\0';
	}
	
	setcolor( WHITE );
	settextstyle(0, 0, 1);
	gprintf( 0, 1, "%s", status);	
	showMousePointer();
}



void Window::timeLine()	{

	lt = time(NULL);	
	local = localtime(&lt);
	strftime(str,100,"  %I:%M %p",local);
	if(	strcmpi(str,prev) == 0 )	return;
	strcpy(prev,str);
	hideMousePointer();
	setviewport( 541, 465, 639, 479, 1 );
	setlinestyle(0, 0,  1);
	setfillstyle(SOLID_FILL, LIGHTGREEN);			
	bar( 0, 0, 98, 14 );
	setcolor(GREEN);
	rectangle( 0, 0, 98, 14 );
	setcolor(BLACK);
	settextstyle(0, 0, 1);
	gprintf( 5, 4, str);
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
