#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream.h>
#include<ctype.h>
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
static long int IX = 0;		// holds the count for number of objcted created runtime...
static unsigned int multiWindow = 0;
unsigned int currentBgClr = LIGHTGRAY;
unsigned int currentWindow = -1;
int initGraphFlag = 0;
void openAllDefaultWindowObjects();
void callExit(int *btn);
extern int isSpecialCharacter(int ch);

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

	void putWindowObj(Window *wObj)	{
		OB = NULL;
		OL = NULL;
		OT = NULL;
		objType = _WINDOW_;
		OW = wObj;
		//printf("\n From Windows  Kit Class\t : %u  :  %u\t Type  : %d",wObj,OW,objType);
	}
	void putButtonObj(Button *bObj)	{
		OW = NULL;
		OL = NULL;
		OT = NULL;
		objType = _BUTTON_;
		OB = bObj;
		//printf("\n From Button  Kit Class\t : %u  :  %u\t Type  : %d",bObj,OB,objType);
	}
	void putLabelObj(Label *lObj)	{
		OW = NULL;
		OB = NULL;
		OT = NULL;
		objType = _LABEL_;
		OL = lObj;
		//printf("\n From Label   Kit Class\t : %u  :  %u\t Type  : %d",lObj,OL,objType);
	}

	void putTextBoxObj(TextBox *tObj)	{
		OW = NULL;
		OB = NULL;
		OL = NULL;
		objType = _TEXTBOX_;
		OT = tObj;
		//printf("\n From TextBox Kit Class\t : %u  :  %u\t Type  : %d",tObj,OT,objType);
	}
};

template <class Tbttn>
int addButton(Tbttn TemplateObjButton)	{ Kit[IX].putButtonObj(TemplateObjButton);		return IX++;	}

template <class Tlbl>
int addLabel(Tlbl TemplateObjLabel)   	{ Kit[IX].putLabelObj(TemplateObjLabel); 		return IX++;	}

template <class Ttxt>
int addTextBox(Ttxt TemplateObjTextBox) { Kit[IX].putTextBoxObj(TemplateObjTextBox);	return IX++;	}

template <class Twind>
int addWindow(Twind TemplateObjWindow)	{ Kit[IX].putWindowObj(TemplateObjWindow); 		return IX++;	}

Abstract_Windows_DOS_Mode_ToolKit 	*Kit;



class EventListener {
	char* _str;
	int regNo;
	public:
		EventListener()	{	_str = '\0';	regNo = -1;		}
		static void actionPerformed(EventListener);
		void setCommand(char* _s, int _no) {
		       _str = _s;
		       regNo = _no;
		}
		char* actionCommand()	{
			return _str;
		}
		int equal(char* _s){
			if( strcmp(_str,_s) == 0 ) return 1;
			else 	       return 0;
		}
		int equal(Button _btn_){
			if( regNo == _btn_.getRegistrationID() ) return 1;
			else 	       return 0;
		}
};



static unsigned int runningThreadFlag = 0; // To make thread to run only once a time


/*void *fname;
void Button::Handler(void (*func)(void))	{
		void(*function_name)(void) = *func;
		function_name();
		void(*fname)() = *func;
		//func();
}*/


void initRunnableThread()	{

		if( runningThreadFlag == 1 ) return;
		runningThreadFlag = 1;		// set runningThreadFlag to 1 to indicate thread already called by main program because to avoid looping

		if( multiWindow == 0 ) {		//printf("\n\nDefault Window\n\n");
			openDefalutWindow();
			openAllDefaultWindowObjects();
		}else {							//printf(" Multi Window\n\n");
				if( currentWindow == -1 ) {
					printf("\n Error : Window Initiallization and Openning Failed.");
					exit(0);
				}
				Kit[currentWindow].OW->drawWindow();
				Kit[currentWindow].OW->createWindow_And_AddObjectToWindowScreen();
		}


register long int z;		// declared as register int type for fast access
int _button = 0,_x,_y, key;
char status[20];
int prev=1, next =1;
int curTxtBox = -1;
EventListener _EL_;
	lbl:
	while( !kbhit() ) {

		getMousePosition(&_button,&_x,&_y);
		showMousePointer();
/*		gotoxy(20,24);		// testing for reachability of code
		printf("%05d",prev++);
*/
		if( multiWindow )		Window::timeLine();
		else					timeLine();

		sprintf(status,"%02d:%02d",	/*(_x>19)?(_x<=460?_x-19:0):0*/_x	,_y);
		if( multiWindow ) Kit[currentWindow].OW->setStatus(status);
		else	setStatusLine(status);

		if( _button != 1 )  continue;

		//if( _x >= 3 && _x <= 16 && _y >= 617 && _y <=633 )  closeButton(RED, BLACK, 1);
		if( _button == 1 && _x >= 3 && _x <= 16 && _y >= 617 && _y <=633 ) {
			delay(100);
			callExit(&_button);
		}
		for( z=0; z < IX; z++ ) 	{

			if( Kit[z].objType == _BUTTON_ ) {
				if( Kit[z].OB->TestWindowIsOpened() && Kit[z].OB->TestButtonIsEnabled())
				if((_x >= Kit[z].OB->x1+19 &&  _x <= Kit[z].OB->x2+19) && (_y >= Kit[z].OB->y1 && _y <= Kit[z].OB->y2))	{
					Kit[z].OB->pressButton();
					_EL_.setCommand(Kit[z].OB->getText(),Kit[z].OB->getRegistrationID());
					EventListener::actionPerformed( _EL_ );
					delay(100);
					break;
					}
			}
			else if( Kit[z].objType == _TEXTBOX_ ) {
				if( Kit[z].OT->TestWindowIsOpened() )
				if((_x >= Kit[z].OT->x1+19 &&  _x <= Kit[z].OT->x2+19) && (_y >= Kit[z].OT->y1 && _y <= Kit[z].OT->y2))	{

					if( curTxtBox != -1 && curTxtBox != z )			Kit[curTxtBox].OT->drawTextBox(0);
					if( curTxtBox != z )	{
						curTxtBox = z;
						Kit[curTxtBox].OT->drawTextBox(1);
						/*gotoxy(20,23);
						printf("%05d",next++);
						delay(300);
						*/gotoxy(60,23);
						printf("%02d",curTxtBox);

					}
					delay(100);
					goto lbl;
				}
			}else	{
					if( curTxtBox != -1 )		Kit[curTxtBox].OT->drawTextBox(0);
					curTxtBox = -1;
					/*gotoxy(40,23);
					printf("%05d",prev++);
					gotoxy(60,23);
					printf("%02d",curTxtBox);
					*/
			}
		}		/* 	End of for loop 	*/
	} 		/* 	End of while loop 	*/
	key = getKey();
	if( (isalnum (key) || isSpecialCharacter(key)) && curTxtBox != -1 )
	Kit[curTxtBox].OT->putText(key);

	if( curTxtBox != -1 && key == 27 )	{			// to escape from current TextBox
		Kit[curTxtBox].OT->drawTextBox(0);
		curTxtBox = -1;
		goto lbl;
	}

	if ( key != 27/*ESC*/ &&  key != 363 /*ALT-F4*/) goto lbl;
	//goto lbl;
}



void callExit(int *btn){
	
	*btn = 0;
//	gotoxy(70,3);
//	printf("Exit Called");
//	getch();
	delay(100);
	exit(0);	
}

void openAllDefaultWindowObjects()	{

int z=0;

	for( z = 0; z < IX; z++ ) 	{
		if( Kit[z].objType == _WINDOW_ )	{
			Kit[z].OW->winOpen = 0;
			//printf(" W -> %02d  :  Windows Open Flag wiht index and regid :  %d \n",z,Kit[z].OW->winOpen);
		}
		if( Kit[z].objType == _BUTTON_ )	{
			Kit[z].OB->winOpen = 1;
			if( Kit[z].OB->isEnabled() )	Kit[z].OB->drawButton(Kit[z].OB->getBackground(), 0);
					else 							Kit[z].OB->drawButton(LIGHTGRAY,2);
			//printf(" B -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OB->winOpen);
			//gotoxy(Kit[z].OB->y1/8, Kit[z].OB->x1/8);
			//printf(" x1:%d, y1:%d, x2:%d, y2:%d",Kit[z].OB->x1, Kit[z].OB->y1, Kit[z].OB->x2, Kit[z].OB->y2);
		}
		else if( Kit[z].objType == _LABEL_ ){
			Kit[z].OL->winOpen = 1;
			Kit[z].OL->drawLabel(0);
			//printf(" L -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OL->winOpen);
		}
		else if( Kit[z].objType == _TEXTBOX_ ){
			Kit[z].OT->winOpen = 1;
			Kit[z].OT->drawTextBox(0);
			//printf(" T -> %02d  :  Windows Open Flag  :  %d \n",z,Kit[z].OT->winOpen);
		}
	}
}




/*  Test Script object testing 

	for( z=0; z < IX; z++ ) 	{
	if( Kit[z].objType == _BUTTON_ ) {
		printf("\n\n%ld B : %u  x1:%d, y1:%d, x2:%d, y2:%d",z,Kit[z].OB,Kit[z].OB->x1, Kit[z].OB->y1, Kit[z].OB->x2, Kit[z].OB->y2);
	}
	}
	getch();

		int k;
	
	for( k=0; k < IX; k++ ) 	{
		if( Kit[k].objType == _WINDOW_ )
			printf("\n\n%d %u  W : %s\tID : %d  ",k,Kit[k].OW,Kit[k].OW->Title,Kit[k].OW->regId);
		if( Kit[k].objType == _BUTTON_ )
			printf("\n\n%d %u  B : %s\t Id : %d\tx : %d\ty1 : %d\ty2 : %d",k,Kit[k].OB,Kit[k].OB->Text,Kit[k].OB->regId,Kit[k].OB->x1,Kit[k].OB->y1,Kit[k].OB->y2);
		if( Kit[k].objType == _LABEL_ )
			printf("\n %u  L : %s\t Id : %d\tx : %d\ty1 : %d\ty2 : %d",Kit[k].OL,Kit[k].OL->Text, Kit[k].OL->regId,Kit[k].OL->x,Kit[k].OL->y1,Kit[k].OL->y2);
		if( Kit[k].objType == _TEXTBOX_ )
			printf("\n %u  T : %d\tID : %d  x : %d  y1 : %d  y2 : %d",Kit[k].OT,Kit[k].OT->str_len,Kit[k].OT->regId,Kit[k].OT->x,Kit[k].OT->y1,Kit[k].OT->y2);
	}
 getch();
*/