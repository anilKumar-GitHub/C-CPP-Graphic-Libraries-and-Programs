#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<process.h>
#include<string.h>
#include<swrp.h>
#include<key.h>


void Insert();
void Display();
void Edit();
void Search();
void Delete();
void Sort_Data(int);
display1(int cnt, int row);
struct information {
	int reg;
	char name[30];
	char gen[5];
	float sal;
}info,info1[100],info2[100],var;

FILE *fp;
char filename[20] = "myBook.txt";

int main()	{

	char ch,ch1[40];
	while(1){
	clrscr();
	printf("1)Insert     2)View\t3)Edit\t  4)Search\t5)Delete     6)Exit");
	printf("\n\nEnter Choice : ");
	ch = getche();
		switch(ch){
			case '1': Insert();      	break;
			case '2': Display(); 		continue;
			case '3': Edit();     		break;
			case '4': Search();		continue;
			case '5': Delete();		break;
			case  27:
			case '6': printf("\n\n Thank You...");
					getch();
					exit(0); 	break;

		default:printf("Enter Again");
		}
		getch();
	}
}


int checkID(int ID) {

	fp = fopen(filename,"r+");
	while(fread(&info,sizeof(struct information),1,fp)==1)
		if(info.reg == ID ) return 0 ;
	return 1;

}


void Insert(){
	int num;
	char var1[50];
	printf("\n Enter Reg No : ");
	num = getIntegerValue();
//	scanf("%d",&num);
	if(checkID(num) == 0) {
		printf("\n\nThe Information of %d  Aleady Exist",info.reg);
		return;
	}
	info.reg = num ;
	printf("\n Name : ");


	readString(info.name,30);
	printf("\n Gender : ");
	readString(info.gen,2);
//	scanf("%s",info.gen);
	printf("\n Salary : ");
	info.sal = getIntegerValue();
//	scanf("%f",&info.sal);
//	printf(" \n Reg = %d \n Name = %s\n Gen = %s \n Sal = %f",info.reg,info.name,info.gen,info.sal);
	//addSpaceEffect(info.name);

	fp = fopen(filename,"a+");
	if(fwrite(&info,sizeof(struct information),1,fp)!=1){
	printf("\nError During Insertion ");
	}else {

	printf("\n\n\tData Inserted Successfully");
	}
	fclose(fp);
}


void Edit() {
	FILE *temp;
	int reg;
	float sal;
	char name[30],gen[5];
	int  flag = 0, num ;
	printf("\n\n Enter Number : ");
	scanf("%d",&num);
	fp = fopen(filename,"r+");
	temp = fopen("TempData.txt","w+");

	while(fread(&info,sizeof(struct information),1,fp)==1)
	{
	if( info.reg != num ){

		fseek(temp,0,SEEK_END);
		fwrite(&info,sizeof(struct information),1,temp);
	}else{
	   flag = 1 ;
	   var = info ;
     }
	}
	fclose(temp);
	fclose(fp);
	remove(filename);
	rename("TempData.txt",filename);
	if(flag == 0 ) printf("No Record Found For That Entry ");
	else {
	    printf("\n\n\nRegister No %d\t Name = %s\n\n Gender = %s\t Salary = %f\n\n",var.reg,var.name,var.gen,var.sal);
	    Insert();
	}
}




void Display() {
	int i = 0, FTB = 1, cnt = 0 ;

	fp = fopen(filename,"r+");

	do {
		FTB = fread(&info1[i],sizeof(struct information),1,fp);
		escapeSpaceEffect(info1[i].name);
		if(FTB != 1) {	break; 	}
		i++;  	cnt++;
	}while(FTB == 1 );

	fclose(fp);
	display1(cnt,8);
}

display1(int cnt, int row){
	int i,k,lim = row ;
	int ch;
	if( cnt < row )		lim = cnt;
	k=0;
	Sort_Data(cnt);
	while(1)	{
	clrscr();
	printf("\n\n SL No.	Reg No    \t Name              \t Gender\t Salary \n");
	for( i = k;  i < lim ; i++ )   {
	printf("\n %02d\t %-10d\t %-20s\t %s\t %7.3f",i+1,info1[i].reg,info1[i].name,info1[i].gen,info1[i].sal);
	//delay(100);
	}
	gotoxy(4,25);
	printf("Back Space : Exit");
	gotoxy(80,25);
	lbl:
	ch=getKey();
	if( ch == ESC || ch == BACKSPACE ) return 0;
	else if( ch == DOWN || ch == CTRL_D || ch == PGDN && k <= cnt-row )	{
		if( k == cnt - row ) goto lbl;
			k++;
		if( k > cnt-row ) k = cnt-row;
			lim = k+row;
		if(lim > cnt) lim = cnt;
		if( cnt <= lim )  lim =cnt;

	}else if( ch == UP || ch == CTRL_U || ch == PGUP && k >= 0 ) {
		if( k == 0 ) goto lbl;
			k--;
		if( lim < 0 ) lim = 0;
		if( k < 0 ) k = 0 ;
			lim = k+row;
		}else {gotoxy(60,25);printf("%c",ch);goto lbl;}
	}


}



void Delete() {
	FILE *temp;
	int flag = 0, num ;
	printf("\n\n Enter Number : ");
	scanf("%d",&num);
	fp = fopen(filename,"r+");
	temp = fopen("TempData.txt","w+");

	while(fread(&info,sizeof(struct information),1,fp)==1)
	{
	if( info.reg != num ){

		fseek(temp,0,SEEK_END);
		fwrite(&info,sizeof(struct information),1,temp);
	}else{ flag = 1 ; }
	}
	fclose(temp);
	fclose(fp);
	remove(filename);
	rename("TempData.txt",filename);
	if( flag == 1 ) printf("Deleted");
	else printf(" No Record is Delete");
}





void Search() {
	int i = 0,k = 0, j = 0, index = 0, FTB = 1, cnt = 0, row = 8;
	int lim = row, temp_cnt = 0, set = 0, ch;
	char pttrn[20]="",msg[50]="";
	clrscr();
	fp = fopen(filename,"r+");

	do{
		FTB = fread(&info1[k],sizeof(struct information),1,fp);
		escapeSpaceEffect(info1[k].name);
		if(FTB != 1) {	break;	}
		k++;   cnt++;
	}while(FTB == 1 );
	fclose(fp);

	Sort_Data(cnt);
	temp_cnt = cnt;

	for( k = 0; k < cnt; k++ )	info2[k]=info1[k];

	if( temp_cnt < row )		lim = temp_cnt;
	k=0;
	while(1)	{
	whilelbl:
	clrscr();
	printf("\n\n SL No.	Reg No\t Name              \t\t\t Gender\t Salary \n");
	for( index = k;  index < lim ; index++ )   {
		printf("\n %02d\t %-5d\t %-35s\t %s\t %7.3f",index+1,info2[index].reg,info2[index].name,info2[index].gen,info2[index].sal);
	}
	if(j==-1)	printf("\n\n\t\t\t Not Found ");

	gotoxy(2,24);
	printf("Pattern : ");
	gotoxy(2,25);
	printf("ESC : Exit  ");
	printf("\t\t\t%s",msg);
	lbl:
	gotoxy(12,24);
	printf("%s",pttrn);

	ch=getKey();

	if( ch == ESC ) return;
	if( ch >= CTRL_I && ch <= CTRL_M ) goto lbl;
	else if( ( ch == DOWN || ch == RIGHT || ch == CTRL_D ) && k <= temp_cnt-row )	{
		if( k == temp_cnt - row ) goto lbl;
			k++;
		if( k > temp_cnt-row ) k = temp_cnt-row;
			lim = k+row;
		if(lim > temp_cnt) lim = temp_cnt;
		if( cnt <= lim )   lim = temp_cnt;

	}else if( ( ch == UP || ch == LEFT || ch == CTRL_U ) && k >= 0 ) {
		if( k == 0 ) goto lbl;
			k--;
		if( lim < 0 ) lim = 0;
		if( k < 0 ) k = 0 ;
			lim = k+row;
	}else if( ( isspace(ch) || isalnum(ch) || isSpecialChar(ch) ) && ( i < 15 ) )
	{
		pttrn[i] = ch;
		cprintf("%c",ch);
		i++;
		set = 1;
		goto srch_lbl;
	}else if( ( ch == BACKSPACE ) && ( i != 0 ) )
	{
		i--;
		cprintf("\b \b");
		goto srch_lbl;
	}else if ( i == 0 && set == 1){
		for( index = 0; index < cnt; index++ )
			info2[index] = info1[index];
		set = 0 ;
		k = 0;
		temp_cnt = cnt ;
		lim = row;
		if( temp_cnt < row ) lim = temp_cnt;

	}else {	gotoxy(75,24);printf("%c",ch); goto lbl;}


}
	srch_lbl:
	pttrn[i]='\0';
	//if( ch == '_' )		escapeSpaceEffect(pttrn);
	j = -1;
	for( index = 0; index < cnt; index++ )
	if ( strncmpi(pttrn,info1[index].name,strlen(pttrn)) == 0 || info1[index].reg == atoi(pttrn) || strncmpi(pttrn,info1[index].gen,strlen(pttrn)) == 0 || info1[index].sal == atof(pttrn) )   {
		info2[++j] = info1[index];
	}

	if( j > -1 ) {
		temp_cnt = j+1;
		k = 0;
		lim = row;
		if( temp_cnt < row )	lim = temp_cnt;
		strcpy(msg," ");
	}else {
		strcpy(msg," Pattern Not Found :: ");
		strcat(msg,pttrn);
	}
	goto whilelbl;


}




void Sort_Data(int cnt){
int i,k;
	for(i = 0; i < cnt-1; i ++ )
	 for( k = i+1; k < cnt; k++ )
	  if(info1[i].reg > info1[k].reg)
//	  if(strcmpi(info1[i].name,info1[k].name)>0)
	   {
		var = info1[i];
		info1[i] = info1[k];
		info1[k] = var ;
	   }
}