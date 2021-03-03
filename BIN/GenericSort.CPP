#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>

template<class T>
void buble(T a[],int n)	{
	T temp;
	for(int i=0; i<n-1; i++)
	  for(int j=n-1; i<j; j--)
	     if(a[j] < a[j-1] )	{
		temp = a[j];
		a[j] = a[j-1];
		a[j-1] = temp;
	     }
}

template<class T>
T add(T a, T b)
{
	return a+b;
}
main(){

	int i;
	int x[10] = {64,55,67,43,54,32,12,4,1,34};
	float y[10] = {7.1,5.5,2.3,3.4,2.2};
	char z[20] = "I Love My India";
	buble(x,10);
	buble(y,5);
	buble(z,20);
	clrscr();
	cout<<"\n\n Sorted Array List  :\n\n";
	for(i=0; i<10; i++)
	cout<<x[i]<<"   ";


	cout<<"\n\n Sorted Array List  :\n\n";
	for(i=0; i<5; i++)
	cout<<y[i]<<"   ";

	cout<<"\n\n Sorted Array List  :\n\n";
	for(i=0; i<20; i++)
	cout<<z[i]<<"   ";

	printf("Result = %d",add(3,5));
	getch();
}