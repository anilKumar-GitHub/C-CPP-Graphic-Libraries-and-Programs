#include<stdio.h>
#include<conio.h>
#include<string.h>


void main()		{
	clrscr();/*   */

	int rows =10;
	char frmt[20] = "";
	for( int i = 0; i < rows; i++ ){
		int n = 1;
		sprintf(frmt,"%%%ds",(rows-i)*2);
		printf(frmt,"");
		for( int j = 0; j <= i; j++ )	{
			printf("%4d",n);
			n = n * ( i - j ) / ( j + 1 );
		}
		printf("\n");
	}

	getch();
}
