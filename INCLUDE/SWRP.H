/*  swrp.h     	 	  	    	 Initiated in	D: 01/06/2013

    Definations for Generalized Personally Specified Generic Functions for
    dealing with MSDOS and the Intel iAPX86 microprocessor family.

    Copyright (c) 1993, In 2013, To Mr.Anil Kumar.
    Borland International.
    All Rights Reserved for Anil Kumar.
*/
#include<stdlib.h>
#include<stdarg.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<iostream.h>


#define MAX(F,S)    ((F>S)?F:S)
#define MIN(F,S)    ((F<S)?F:S)
#define jump        goto
//typedef char* date;

int echo(char *format, ...)	{
	va_list ptr;
	va_start(ptr,format);
	auto int n = vprintf(format,ptr);
	va_end(ptr);
	return n;
}


int echo(unsigned x, unsigned y, char *format, ...)	{
	auto char *buf;
	va_list ptr;
	va_start(ptr, format);
	vsprintf(buf, format, ptr);	//Only used when we need to process that whole statement it strores this string in buffer tempararly
	va_end(ptr);
	gotoxy(y, x);
	auto int n = printf("%s",buf);
	free(buf);
	return n;
}


int getRandNum(int _s, int _e)	{
	int _num = 0;
	randomize();
	if( _s == _e ) return _s;
	if( ( _s > _e ) || ( _s < 0) || ( _e < 1 )) return -1;
	while(1)	{
		_num = random(_e+1);
		if( _num > _s-1 && _num < _e+1 )	return _num;
	}
}

int isSpecialChar(char ch)	{
	int i;
	if( ( ch >= 33 && ch <= 47 ) || ( ch >= 58 && ch <= 64 ) || ( ch >= 91 &&  ch <= 96 ) || ( ch >= 123 && ch <= 126 ) )
	return 1;
	return 0;
}
// used when we use the file concept
void  addSpaceEffect(char *_str)	{
	int i=0;
	for(i=0; i<strlen(_str); i++)
		if( *(_str+i) == ' ')  *(_str+i) =  '_';
}

void  escapeSpaceEffect(char *_str)	{
	int i=0;
	for(i=0; i<strlen(_str); i++)
		if( *(_str+i) == '_')  *(_str+i) =  ' ';
}

int getPassword(char *_pw,int _len)	{
	int i=0;
	char ch;
	_len = _len<16? _len:16;
	do{
		ch=getch();
		if( ( isalnum(ch) || isSpecialChar(ch) ) && ( i < _len-1 ) )	{
			*(_pw+i) = ch;
			printf("%c",ch);
			delay(20);
			printf("\b*");
			i++;
		}else if( ( ch == 8 /* BackSpace */ ) && ( i != 0 ) )  	{
			i--;
			printf("\b \b");
		}
	}while( ch != 13 /* ENTER */ );
	*(_pw+i) = '\0';
	return i;
}

void getDate(char *_date)	{
	char ch,c0,c1,c2,c3,c4,year[5],month[2],day[2];
	int i=0,flag=0,yr=0,mth,leap=0,type=0;
	int yFlag=0, mFlag=0, dFlag=0;
	printf("YYYY-MM-DD\b\b\b\b\b\b\b\b\b\b");
	do{
	   lbl:
	   ch = getch();
	   if( isdigit(ch) && i <= 9 )	{    	// Scan for Digit
		if( i <= 3 ){
		    if( i == 0 && ( ch >= '1' && ch <= '9' ) ){
			*(_date+i) = ch;
			printf("%c",ch);
			c0 = ch ;
			i++;       // set year flag bit for increment i
		    }
		    else if( i > 0 ) {         // other bits other than first bit
			*(_date+i) = ch;
			printf("%c",ch);
			if(i==1) c1 = ch;
			if(i==2) c2 = ch;
			if(i==3) c3 = ch;
			i++;
		    }
		    if( i == 4 ) {                         // attach '-' charctr after year
			*(_date+i) = '-';	printf("-");
			i++;   // store full year
			year[0]=c0;
			year[1]=c1;
			year[2]=c2;
			year[3]=c3;
			year[4]='\0';
			yr = atoi(year);         // get integer eauivalent year
			leap = ((yr % 4 == 0) || (yr % 100 == 0) || (yr % 400 == 0))?1:0;
		    }
		}
		else if( i == 5 || i == 6 ){
		    if( i == 5 && ( ch == '0' || ch == '1' )){
			printf("%c",ch);
			*(_date+i) = ch ;
			month[0]=ch; i++;
		    }
		    else if( i == 6 && ((month[0] == '0' && ( ch >= '1' && ch <= '9' )) || (month[0] == '1' && ( ch >= '0' && ch <= '2' ))))    {
			printf("%c",ch);
			*(_date+i) = ch;
			month[1]=ch; i++;
			month[2]='\0';
			mth = atoi(month);
		    }
		    if( i == 7 ) {
			*(_date+i) = '-';	printf("-");
			i++;
			     if(leap == 0 && mth == 2)			  	type = 0; // This is for non-leap year, indicates february upto 28
			else if(leap == 1 && mth == 2)			  	type = 1; // This is for leap year, indicates february upto 29
			else if(mth  == 4 || mth == 6 || mth == 9 || mth == 11) type = 4; // This is all months whose have 30 day's
			else 							type = 7; // This is all months whose have 31 day's
		    }
		}
		else if(i == 8 || i == 9)  {
		   if(i == 8 && (type == 0 || type == 1) && (ch >= '0' && ch <= '2' )) {
		      *(_date+i) = ch; printf("%c",ch); i++; day[0] = ch;
		   }
		   else if(i == 9 && type == 0 && ((day[0] == '0' && ch >= '1' && ch <= '9') || (day[0] == '1' && ch >='0' && ch <= '9') || (day[0] == '2' && ch >= '0' && ch <= '8' ))){
		      *(_date+i) = ch; printf("%c",ch); i++; day[1] = ch;
		   }
		   else if(i == 9 && type == 1 && ((day[0] == '0' && ch >= '1' && ch <= '9') || (day[0] == '1' && ch >='0' && ch <= '9') || (day[0] == '2' && ch >= '0' && ch <= '9' ))){
		      *(_date+i) = ch; printf("%c",ch); i++; day[1] = ch;
		   }
		   else if(i == 8 && (type == 4 || type == 7) && (ch >='0' && ch <='3')) {
		      *(_date+i) = ch; printf("%c",ch); i++; day[0] = ch;
		   }
		   else if(i == 9 && type == 4 && ((day[0] == '0' && ch >= '1' && ch <= '9') || (( day[0] == '1' || day[0] == '2') && ch >='0' && ch <= '9') || (day[0] == '3' && ch == '0'))){
		      *(_date+i) = ch; printf("%c",ch); i++; day[1] = ch;
		   }
		   else if(i == 9 && type == 7 && ((day[0] == '0' && ch >= '1' && ch <= '9') || (( day[0] == '1' || day[0] == '2') && ch >='0' && ch <= '9') || (day[0] == '3' && ch >= '0' && ch <='1'))){
		      *(_date+i) = ch; printf("%c",ch); i++; day[1] = ch;
		   }
		}
	   }
	   if( ch == 8 && i != 0 ){
		if( i == 5 || i == 8 ) {
			if( i == 5 ) printf("\b\bY-\b\b");
			if( i == 8 ) printf("\b\bM-\b\b");
			i=i-2;

		}else{
			if( i >= 1 && i <= 3  ) printf("\bY\b");
			else if( i == 6 ) printf("\bM\b");
			else if( i == 9 || i == 10 ) printf("\bD\b");
			i--;
		}
	   }

	   if( ch == 13 && i <= 9 ) goto lbl;
	}while( ch != 13  /* ENTER */ );
	*(_date+i) = '\0';
}

int readString(int x, int y, char *_str, int _len)	{
	int i=0;
	char ch;
	gotoxy(y, x);
	*_str = '\0';
	do	{
		ch = getch();
		if((ch != 13 && isspace(ch) || isalnum(ch) || isSpecialChar(ch) ) && ( i < _len - 1 ) )	{
			if(isspace(ch))	*(_str+i) = 14;
			else      	*(_str+i) = ch;
			cprintf("%c",ch);
			i++;
		}
		if( ( ch == 8  ) && ( i != 0 ) )	{
			i--;
			cprintf("\b \b");
		}
		if( i == _len-1 && ch != 13 ) {
			sound(500);
			delay(1);
			nosound();
		}
	}while( ch != 13 );
	*(_str+(i)) = '\0';
	for( i=0; i<strlen(_str); i++ )
	if( *(_str+i) == 14 )		*(_str+i) = ' ';
	return i;
}

int readString(char *_str, int _len)	{
	int i=0;
	char ch;
	*_str = '\0';
	do	{
		ch=getch();
		if((ch != 13 && isspace(ch) || isalnum(ch) || isSpecialChar(ch) ) && ( i < _len - 1 ) )	{
			if(isspace(ch))	*(_str+i) = 14;
			else      	*(_str+i) = ch;
			cprintf("%c",ch);
			i++;
		}
		if( ( ch == 8  ) && ( i != 0 ) )	{
			i--;
			cprintf("\b \b");
		}
		if( i == _len-1 && ch != 13 ) {
			sound(500);
			delay(1);
			nosound();
		}
	}while( ch != 13 );
	*(_str+(i)) = '\0';
	for( i=0; i<strlen(_str); i++ )
	if( *(_str+i) == 14 )		*(_str+i) = ' ';
	return i;
}

long int toInteger(char *alph)	{
	char *a,*f;
	int i=0,k=0,j=0,temp=0,dot=0,sign=0;
	long long long unsigned int num=0;

	if ( *alph == '-' ) 		sign = 1;
	if ( *alph == '+' ) 		sign = 0;

	while( i < strlen(alph)){
		if( dot == 0 ) {
			if( isdigit(*(alph+i)) ){
				*(a+k++) = *(alph+i);
				//printf("\n %c",a[k]);
				//k++;
			}

		}else{
			if( isdigit(*(alph+i)) ) {
				*(f+j++) = *(alph+i);
				//printf("\n %c",f[j]);
				//j++;
			}

		}


		if( *(alph+i) == '.' ) {
			if( dot == 1 ) { *(f+j)='\0'; break; }
			dot = 1; //printf(" \n\n Set Dot = %d",dot);
		}

		if( (i == 0) && ( (*(alph+i) == '-') || ( *(alph+i) == '+') ) )
			{  i++;  continue; }

		if( isalpha(*(alph+i)) || ( *(alph+i) != '.' && isSpecialChar(*(alph+i)) ) )
		break;
		else i++;


	}
	*(a+k) = '\0';

	for(i=0; i<strlen(a); i++)	{
		temp = *(a+i) - '0' ;	 // it return equivalent integer value of the character
		num = num + temp;
		if ( i != strlen(a)-1 )		      num = num * 10;
	}

	if( *(f+0)-'0' >= 5 ) num++;
	if( sign == 1 ) num = num * -1;
   return num;

}

long int getIntegerValue()	{
	char ch,alph[10];
	int i=0,k,temp;
	int max = 9,start=0;
	long long int num=0;
	int sign = 0;
	do{
		ch = getch();
		if( ( ch == '-' || ch == '+' ) && i == 0 )	{
			printf("%c",ch);
			alph[i] = ch ;
			i++;
			max = 10;
		}
		if( isdigit(ch) && i <= max )	{
			printf("%c",ch);
			alph[i] = ch ;
			i++;
		}
		if( ch == 8 /* BACKSPACE */  && i != 0)		{
			i--;
			printf("\b \b");
		}
	}while( ch != 13 /* ENTER */ );

	if( i==0 ) 	alph[0] ='\0';
	alph[i] = '\0';
	if( alph[0] == '-' || alph[0] == '+' ) start = 1;
	if( alph[0] == '-' ) sign = 1 ;

	for(i=start; i<strlen(alph); i++)	{
		temp = alph[i] - '0' ;
		num = num + temp;
		if ( i != strlen(alph)-1 )
			num = num * 10;
	}
	if( sign == 1 ) num*= -1;
	return num;
}

void dec2bin(long int _dec, char *bin)	{

	int _i = 0, rem = 0 ;
	while ( _dec > 0 )      	{
		rem = _dec % 2;
		*(bin+_i) = (char)(rem+48);
		_dec = _dec / 2;
		_i++;
	}
	*(bin+_i) = '\0';
	strrev(bin);
}

void _dec2bin(long int _dec, char *_bin)	{
	int _i = 0, rem = 0 ;
	char b[128]={'1'};
	while ( _dec > 0 )      	{
		rem = _dec % 2;
		b[_i] = (char)(rem+48);
		_dec = _dec / 2;
		_i++;
	}
	b[_i] = '\0';
	strrev(b);
	strcpy(_bin,b);

}
