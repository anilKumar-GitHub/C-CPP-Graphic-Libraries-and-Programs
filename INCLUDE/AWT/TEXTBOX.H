extern unsigned int multiWindow;
extern int getRegID();
template <class Ttxt>
int addTextBox(Ttxt TemplateObjTextBox);

class TextBox {
   public:
	char Text[150];
	int str_len, txtClr, boxClr, Index;
	int regId, regFlag, Active, Enabled, winOpen;
	int x1, y1, x2, y2, boxBgClr, boxTxtClr;
	int strStart, strEnd, cursor;
	public:
	TextBox(){
		strcpy(Text,'\0');
		regId = str_len = Index = -1;
		x1 = x2 = y1 = y2 = -1;
		Active = Enabled = regFlag = winOpen = 0; 
		boxBgClr = WHITE; 
		boxTxtClr = BLACK;
	}
	
	TextBox( int _x, int _y, int _size )	{
		x1 = _x + 1;
		x2 = x1 + 18;
		y1 = _y + 1;
		y2 = y1 + _size * 8 + 10 ;  // Width of each character
		strcpy(Text,'\0');
		str_len = 0;
		regId = Index = -1;
		Active = Enabled  = regFlag = winOpen = 0; 
		boxBgClr = WHITE; 
		boxTxtClr = BLACK;	
		strStart = 0; strEnd = 0; cursor = 0;
		//printf("\n From TextBox Class Constructor \t : regFlag : %d\n",regFlag);
	}
	
	//int getBackground()				{	return bttnBgClr;  }
	//int getTextColor()				{	return bttnTxtClr; }
	int getRegistrationID()			{	return regId;	   }
	//char* getText()					{	return Text;	   }
	//int TestButtonIsEnabled()		{	return Enabled;    }
	int TestWindowIsOpened()		{	return winOpen;    }

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
			regFlag = 1;
			winOpen = 0;
		}
		obj.regObject(regId,Index);
		multiWindow = 1;
		//printf("\n From Buttons Class \t\t : %u",this);
	}
	void drawTextBox(int);
	void putText(int);
};


void TextBox::drawTextBox(int selected ) {
	
	if( !winOpen ) return;
	hideMousePointer();
	setviewport( 0, 19, 639, 464, 1);	
	
	setfillstyle(SOLID_FILL,currentBgClr);
	bar(y1, x1, y2, x2);
//	getch();
	setcolor(LIGHTGREEN);
	if( selected )		{
		setfillstyle(SOLID_FILL,boxBgClr);
		bar(y1+2, x1+2, y2-2, x2-2);
		setlinestyle(0, 0,  3);
		rectangle( y1+1, x1+1, y2-1, x2-1);
		setcolor(BLACK);
		setlinestyle(0, 0,  1);
		rectangle( y1+2, x1+2, y2-2, x2-2);
	}else	{
		setfillstyle(SOLID_FILL,boxBgClr);
		bar(y1, x1, y2, x2);
		setlinestyle(0, 0,  1);
		rectangle( y1, x1+1, y2, x2-1);
		setcolor( BLACK );
		rectangle( y1, x1, y2, x2);
	}
	setcolor(boxTxtClr);
	settextstyle(2, 0, 5);
	gprintf(y1+6,x1+1,"%s",Text);
	showMousePointer();
}


void TextBox::putText( int ch )	{

		int len = strlen(Text);
		int width = (y2 - y1 - 10)  ;
		char text[1];
		gotoxy(5,13);
		text[0] = ch;
		text[1] = '\0';
		settextstyle(2, 0, 5);
		printf("%c => %d",ch,textwidth(text));

		if( len*6 < width )	{
			if( ch == 8 && len != 0 )	{
				Text[len-1] = '\0';
				cursor--;
			}
			if( ch != 8 )	{
				Text[len] = ch;
				Text[len+1] = '\0';
				cursor++;
			}
		}
		
		hideMousePointer();
		setviewport( 0, 19, 639, 464, 1);
		setfillstyle(SOLID_FILL,boxBgClr);
		bar(y1+3, x1+3, y2-3, x2-3);
		setcolor(boxTxtClr);
		//settextstyle(2, 0, 5);
		gprintf(y1+6,x1+1,"%s",Text);
		showMousePointer();
		//drawTextBox(1);
		
		gotoxy(5,3);
		printf("%s  :  %d",Text,cursor);
}




/*

void TextBox::putText( int ch )	{

		int len = strlen(Text);
		gotoxy(5,13);
		printf("%c",ch);
	
		
		if( ch == 8 )	{
			Text[len-1] = '\0';
		}else {
			Text[len] = ch;
			Text[len+1] = '\0';
		}
		
		hideMousePointer();
		setviewport( 0, 19, 639, 464, 1);
		setfillstyle(SOLID_FILL,boxBgClr);
		bar(y1+3, x1+3, y2-3, x2-3);
		setcolor(boxTxtClr);
		settextstyle(2, 0, 5);
		gprintf(y1+6,x1+1,"%s",Text);
		showMousePointer();
		//drawTextBox(1);
		
		gotoxy(5,3);
		printf("%s",Text);
}


*/