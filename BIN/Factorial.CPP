#include<stdio.h>
#include<conio.h>

long long int facto(int);

int main()	{
	int fact;
	clrscr();
	printf("Enter : ");
	scanf("%d",&fact);
	printf("\n\n Factorial  : %ld",facto(fact));
	getch();
}

long long int facto(int n)	{
	if( n < 0 ) {
		n = n * -1;
		return  ( -1 * facto(n) );
	}else {
		if( n == 0 ) 	return 1;
		else		return n*facto(n-1);
	}
}