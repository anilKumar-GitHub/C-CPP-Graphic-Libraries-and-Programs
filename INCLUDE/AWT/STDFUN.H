

int isSpecialCharacter(int ch)	{
	if( ch == 8/*back space*/ || ch == 339/* DEL key*/ || ch == 32/*white space*/ || ch == '!' /*33 ASCII CODE*/ || ch == 331/*left key*/ || ch == 333/*right key*/ ||( ch >= 35 && ch <= 47 ) || ( ch >= 58 && ch <= 64 ) || ( ch >= 91 &&  ch <= 96 ) || ( ch >= 123 && ch <= 126 ))
	return 1;
	return 0;
}


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