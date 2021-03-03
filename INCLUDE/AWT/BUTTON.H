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

	int getBackground()			{	return bttnBgClr;  }
	int getTextColor()			{	return bttnTxtClr; }
	int getRegistrationID()			{	return regId;	   }
	char* getText()				{	return Text;	   }
	int TestButtonIsEnabled()		{	return Enabled;    }
	int TestWindowIsOpened()		{	return winOpen;    }

	void add(){
		if( regFlag == 0 )	{
			Index 	= addButton(this);
			regId 	= getRegID();
			regFlag = 1;
			winOpen = 0;
		}
	}

	void add(Window &obj){
		if( regFlag == 0 )	{
			Index = addButton(this);
			regId = getRegID();
			regFlag = 1;
			winOpen = 0;
		}
		obj.regObject(regId,Index);
		multiWindow = 1;
	}

	void drawButton( int bkclr, int press);
	void pressButton();
	void setBackground(int _clr)	{
		bttnBgClr = _clr;
		if( !winOpen ) return;
		drawButton( bttnBgClr, 0);
	}

	void setTextColor(int _clr)	{
		bttnTxtClr = _clr;
		if( !winOpen ) return;
		drawButton( bttnBgClr, 0);
	}
	void setText(char *_text)		{
		Text = _text;
		TextLen = strlen( _text );
		if( winOpen )	{
			hideMousePointer();
			setviewport( 0, 19, 639, 464, 1);
			setfillstyle(SOLID_FILL,currentBgClr);	// make button place to invisible using window background color
			bar(y1+6, x1+8, y2+6, x2+6);
			bar(y1, x1, y2, x2);
		}
		y2 = y1 + ( TextLen * 8 ) + 15;
		if( !winOpen )	return;
		drawButton( bttnBgClr,0);
	}

	void setEnable(int _state)	{
		Enabled = _state;
		if(	_state )	drawButton(bttnBgClr,0);
		else			drawButton(LIGHTGRAY,2);
	}
	void setEnable()	{
		Enabled = 1;
		drawButton(bttnBgClr,0);
	}
	void setDisable()	{
		Enabled = 0;
		drawButton(LIGHTGRAY,2);
	}
	int isEnabled()	{	return Enabled;	}

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


void Button::drawButton(int bkclr, int press) {

	if( !winOpen ) return;
	hideMousePointer();
	setviewport( 0, 19, 639, 464, 1);
	if( press == 1 )	setfillstyle(SOLID_FILL,currentBgClr);	// make button place to invisible using window background color
	else				setfillstyle(SOLID_FILL,BLACK);	// set 3-D button back face color

	bar(y1+6, x1+8, y2+6, x2+6);
	setfillstyle(SOLID_FILL,bkclr);		// set  3-D button front face color
	bar(y1, x1, y2, x2);

	if( press != 1 )	{	// draw the rectangle boxes around the button
		setcolor( DARKGRAY );
		rectangle( y1, x1,   y2, x2);
		rectangle( y1, x1+1, y2, x2-1);
		rectangle( y1, x1+2, y2, x2-2);

		if( press == 2 )	setcolor(DARKGRAY);
		else 				setcolor(bttnTxtClr);		// write Text on the button
		settextstyle(0, 0, 1);
		gprintf(y1+6,x1+7,"%s",Text);
	}
	showMousePointer();
}

void Button::pressButton() {
	//if( winOpen == 0 ) return;
	drawButton(currentBgClr,1);	// make button unvisible
	hideMousePointer();
	setviewport( 0, 19, 639, 464, 1);
	setfillstyle(SOLID_FILL,bttnBgClr);	// move the button to some new possition
	bar(y1+6, x1+8, y2+6, x2+6-1);

	setcolor( LIGHTGRAY );				// draw rectangle to new possitioned button
	rectangle( y1+6, x1+8, y2+6, x2+6);
	rectangle( y1+6, x1+1+8, y2+6, x2-1+6);
	rectangle( y1+6, x1+2+8, y2+6, x2-2+6);

	setcolor( WHITE );
	settextstyle(0, 0, 1);
	gprintf(y1+13,x1+15,"%s",Text);

	delay(150);		// make some visible delay for effect of moving button back-to-front
	drawButton(bttnBgClr,0);	// redraw the original button
}