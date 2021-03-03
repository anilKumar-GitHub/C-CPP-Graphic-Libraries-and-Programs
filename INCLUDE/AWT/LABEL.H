extern unsigned int multiWindow;
extern int getRegID();
template <class Tlbl>
int addLabel(Tlbl TemplateObjLabel);

class  Label{

   public:
	char *Text;
	int	 regId, regFlag, Active, Enabled, winOpen, Index;
	int	 x1, y1, x2, y2, lblLen, lblBgClr, lblTxtClr;
	int font_style, direction, font_size;
	public:
	Label(){
		Text   = " Not Assigned ";
		regId  = lblLen = Index = -1;
		x1 = x2 = y1 = y2 = -1;
		Active = Enabled = regFlag = winOpen = 0;
		font_style = direction = 0;
		font_size  = 1;
		lblBgClr   = lblTxtClr = -1;
	}
	
	//int getBackground()				{	return bttnBgClr;  }
	//int getTextColor()				{	return bttnTxtClr; }
	int getRegistrationID()			{	return regId;	   }
	//char* getText()					{	return Text;	   }
	//int TestButtonIsEnabled()		{	return Enabled;    }
	int TestWindowIsOpened()		{	return winOpen;    }

	
	Label(int _x, int _y, char* _dsc)	{

		Text = _dsc;
		lblLen = strlen( _dsc );
		x1 = _x + 1;
		y1 = _y + 1;
		x2 = x1 + 19;
		y2 = _y + ( lblLen * 8 ) + 15;
		regId = Index = lblLen = -1;
		Active = Enabled = regFlag = winOpen = 0;
		font_style = direction = 0;
		font_size  = 1;
		lblBgClr   = LIGHTGREEN ;
		lblTxtClr  = BLACK;
	}
	char *getLabel(){	return Text;	}	
	void setLabel(char * _lbl){	
		Text = _lbl;
		drawLabel(0);
	}	
	void setLabel(Button &_bttn){	
		Text = _bttn.getText();
		drawLabel(0);
	}	
	
	void setLabelColor(int _clr){	
		lblBgClr = _clr;
		drawLabel(0);
	}	
	
	void drawLabel( int flag ){
		
		if( winOpen == 0 ) return;
		int X1, Y1, X2, Y2;
		hideMousePointer();
		setviewport( 0, 19, 639, 464, 1);
		if( flag == 0 )	setfillstyle(SOLID_FILL,lblBgClr);
		else			setfillstyle(SOLID_FILL,currentBgClr);
		bar(y1, x1, y2, x2);
		if( flag == 1 )	{	showMousePointer();		return;		}
	
		X1 = x1 + 19 ;		
		Y1 = y1;
		X2 = x2 + 19;
		Y2 = y2;
			
		if( Y1 > 639 )	{	showMousePointer();		return;		}
		if( Y2 > 639 )	Y2 = 635; 
		if( X1 > 464 )	{	showMousePointer();		return;		}
		if( X2 > 464 )	X2 = 463;
		setcolor(lblTxtClr);
		settextstyle(font_style, direction, font_size);
		setviewport(Y1, X1, Y2, X2,1);
		gprintf( 5, 5, "%s", Text);
		showMousePointer();
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
			regFlag = 1;
			winOpen = 0;
		}
		obj.regObject(regId,Index);
		multiWindow = 1;
		//printf("\n From Buttons Class \t\t : %u",this);
	}
	void setFontStyle(int _style, int _dir, int _size){
		if( _style < 11 && _style > -1 )		font_style = _style;
		else									font_style = 0;
		if( _dir == 0 || _dir == 1 )			direction = _dir;
		else 									direction = 0;
		if( _size <= 10 && _size >= 1 )			font_size = _size;
		else									font_size = 1;
		drawLabel(0);
	}
	void setFontStyle(int _style, int _size){
		if( _style < 11 && _style > -1 )		font_style = _style;
		else									font_style = 0;
		if( _size <= 10 && _size >= 1 )			font_size = _size;
		else									font_size = 1;
		drawLabel(0);
	}
	void setFontStyle(int _style){

		if( _style < 11 && _style > -1 )		font_style = _style;
		else									font_style = 0;
		drawLabel(0);
	}
	void setFontDirection(int _dir){
		if( _dir == 0 || _dir == 1 )			direction = _dir;
		else 									direction = 0;
		drawLabel(0);
	}
	void setFontSize(int _size){
		if( _size <= 10 && _size >= 1 )			font_size = _size;
		else									font_size = 1;
		drawLabel(0);
	}
	void setHieght(int _h)	{
		if( _h <= 0 ) 	return; 
		if( _h < x2 )	drawLabel(1);
		x2 = x1 + _h;
		drawLabel(0);
	}
	void setWidth(int _w)	{
		if( _w <= 0 ) 	return;
		if( _w < y2 )	drawLabel(1);
		y2 = y1 + _w;
		drawLabel(0);
	}
}; 