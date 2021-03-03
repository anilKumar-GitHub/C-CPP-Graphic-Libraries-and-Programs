 /* This program have been written for to mentain the student record of diploma
    training institute   i,e "Student_Record_Book"  */

  #include<stdio.h>
  #include<stdlib.h>
  #include<conio.h>
  #include<swrp.h>
  #include<ctype.h>
  #include<string.h>
  #define  RCDSIZE        10
  #define  YES            'Y'
  #define  MINUS          "-1"
  #define  CHARUP(ch)     toupper(ch)
  #define  STREQLT(str)   (strcmp((str),YES)==0)
  #define  TRMNAT(str)    (strcmp((str),MINUS)==0)

     /* Function Prototype */
 void print_line();
 void print_title1();
 void print_title2();
 void print_file1();
 void print_pop();
 void print_editor();
 void print_display1();
 void print_display2();
 void print_display3();
 void open_file();
 void save_file();
 void del_file();
 void Insert();
 void Remove();
 void Delete();
 void Display();
 void Search();
 void Modify();
 void Editor();
 void Sorting();

     /*  Global    Declaration  */

     /*  Structure Declaration  */
 struct Student_Record_Book
  {
   char name[40];
   char regst[15];
   char DOJ[10];
   char ph_no[15];
   char qulftion[10];
   char sub[15];
   char place[20];
   int amount,balance,paid;
  }Re_temp,Rcd[RCDSIZE];

  char c,ans,rpt='Y',Regst[15],Name[30],Date[10],SUB[15],Plc[20],quali[10],PH_NO[15];
  char filename[10],NewFile[10],password[20];
  int i,j,k,count,choice,pos,amt,Paid,flag;
  long int Total_amount=0,Total_paid=0,Total_bal=0;
  int top=-1;
  FILE *fptr;

      /*  main()  C-Program  from here   */

 void main()
  {
    pass:
    clrscr();
    printf("\n\n\n\n\n   Enter the password to login:\n\n ");
    print_line();
    printf("\n\n\t\t Password :  ");

/*    for(i=0;i<6;i++)
    {
    password[i]=getch();
    printf("*");
    }
    password[6]='\0';
 */

    getPassword(password,10);
    if(strcmp(password,"012345")==0)
    {
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  Successful Entery ");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t Press <ENTER> to continue");
    getch();
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t Wel-Come To Studnet Record Book Database Software Packege.");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n Developed By : VAYU * ROOP ");
    printf("\n\n\n\t\t\t Press <ENTER> to continue");
    getch();
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\t Note ::  Don't use the whitespace [ ] between the one complete word's \n\n \t\t         use underscore [_] insted of whitespace.");
    getch();

    /* Starting ofwhile() statement */
    while( rpt=='Y' || rpt=='y' )	//while(strcmp(touppe(rpt),"Y")==0)
    {

     F_TOP:
     print_title2();
     printf("\n\n Enter Your Choice :\t");
     START:                                     /* label */
     scanf("%d",&choice);
     switch(choice)
     {
      case 1:   F_SRT1:
		print_file1();
		printf("\n\n Enter Your Choice : ");
		F_SRT2:
		scanf("%d",&choice);
		switch(choice)
		{
		  case 1:
		       printf("\n\n File Name :    ");
		       scanf("%s",NewFile);
		       print_line();
		       printf("\n\n The File record database has been created for the application.\n\n You must restart the application.");
		       print_line();
		       top=-1;
		       getch();
					       goto F_TOP;           break;
		  case 2:
			   clrscr();
			   printf("\n\n\n\n\n\n  NOTE :-\n\n\n\t Enter the file name if it is exists in hard disk and related\n\n\t to this record.");
			   getch();
			   print_title2();
			   print_file1();
			   open_file();        goto F_TOP;           break;
		  case 3:  save_file();        goto F_SRT1;          break;
		  case 4:  del_file();         goto F_SRT1;          break;
		  case 5:  getch();            goto F_TOP;          break;
		  default: printf("\n\n Invailid Selection.\n\n \t Enter once again.");
					       goto F_SRT2;
		}
								    break;
      case 2:    Insert();                     goto F_TOP;          break;
      case 3:    Remove();                     goto F_TOP;          break;
      case 4:    Sorting();        Display();  goto F_TOP;          break;
      case 5:    Sorting();        Search();   goto F_TOP;          break;
      case 6:    Modify();                     goto F_TOP;          break;
      case 7:    goto END;                     goto F_TOP;          break;
      default:   printf(" \n\n\t Invailid Selection \n\n Enter Once Again :");
		 goto START;                    /* label */
     }   /*  End of switch() statement */
    }   /*  End of while() statement */
  }
  else
  {
    printf("\n\n Password does matches. Enter once again.");
    getch();
    goto pass;
  }
   END:                                                  /* label  */
   printf("\n\n Thank You \n\n Press <ENTER> to exit.");
   getch();
  }


 void print_line()
  {
	printf("\n-------------------------------------------------------------------------------");
  }

 void print_title1()
 {
  clrscr();
  print_line();
  printf("\n\t\t\t Student Record Book");
  print_line();
 }

  void print_title2()
 {
  print_title1();
  printf("\n1-> File  2-> Insert  3-> Remove  4-> Display  5-> Search  6-> Editor  7-> Exit");
  print_line();
 }

 void print_file1()
 {
  print_title1();
  printf("\n\n 1-> New File   2-> Open File   3-> Save File    4-> Delete File   5-> Back ");
  print_line();
 }


 void open_file()
 {
  printf("\n\n File Name :  ");
  scanf("%s",NewFile);
  if((fptr=fopen(NewFile,"r"))==NULL)
  {
   printf("\n\n Error opening in file. Can't open the file. ");
   getch();
   return;
  }
  else
  {
    Total_amount=Total_paid=0;
    top=-1;
    while(!feof(fptr))
    {
      if(ferror(fptr))
      {
	printf("\n\n Error in reading a file.");
	top=-1;
	getch();
	return;
      }
      else
      {
	top++;
	fscanf(fptr,"\n\n%s %s %s %ld %s %s %s %d %d",Rcd[top].regst,Rcd[top].name,Rcd[top].place,Rcd[top].ph_no,Rcd[top].qulftion,Rcd[top].sub,Rcd[top].DOJ,&Rcd[top].amount,&Rcd[top].paid);
	//fread(&Rcd[i],sizeof(struct Student_Record_Book),1,fptr);
	Total_amount+=Rcd[top].amount;
	Total_paid+=Rcd[top].paid;
      }
    }
  }
  fclose(fptr);
  printf("\n\n File [ %s ] is loaded. ",NewFile);
  getch();
 }

void save_file()
{
  fptr=fopen(NewFile,"w");
  for(i=0;i<=top;i++)
  {
   if(ferror(fptr))
   {
      printf("\n\n Error in saving a file.");
      getch();
      return;
   }
   else
   {
      //fprintf(fptr,"\n\n %-10.10s   %-20.20s   %-10.10s  %ld  %-10.10s  %-15.15s  %-10.10s  %05d  %05d",Rcd[i].regst,Rcd[i].name,Rcd[i].place,Rcd[i].ph_no,Rcd[i].qulftion,Rcd[i].sub,Rcd[i].DOJ,Rcd[i].amount,Rcd[i].paid);
      fwrite(&Rcd[i],sizeof(struct Student_Record_Book),1,fptr);
   }
  }
  fclose(fptr);
  printf("\n\n File [ %s ] is saved.",NewFile);
  getch();
 }

 void del_file()
 {
  printf("\n\n File Name :  ");
  scanf("%s",filename);
  if(remove(filename))
  {
    printf("\n\n File [ %s ] is not deleted. Error in deleting file.",filename);
  }
  else
  {
   printf("\n\n File [ %s ] is deleted.",filename);
  }
  getch();
 }

 void Insert()
 {
  START:
  print_title1();
  printf("\n \t\t\t Insert Function ");
  print_line();
  if(top==RCDSIZE-1)
  {
   printf("\n\n\t Over Flow....\n\n No more space for new record.");
   getch();
   return;
  }
  else
  {
   printf("\n\n Enter the student record.\n\n [ Note:- If you want to terminate enter the register number == -1 ] ");
   print_line();
   printf("\n\n Register Number :: ");
   Reg:
   scanf("%s",Regst);
   print_line();
     if(TRMNAT(Regst))
     { getch();
       return;
     }
     else
     {
      flag=0;
      for(i=-1;i<=top;i++)
       if(strcmpi(Regst,Rcd[i].regst)==0)
       {
	flag=1;
	break;
       }

      if(flag>0)
      {
	printf("\n\n This record already exists in the record book.\n\n Enter the Register number once again( -1 to terminate ):");
	goto Reg;
      }
      else
      {
       top++;  /* Increament the top position */
       strcpy(Rcd[top].regst,Regst);
       printf("\n\n Candidate Name :  ");
       scanf("%s",Rcd[top].name);
       print_line();
       printf("\n\n Place :  ");
       scanf("%s",Rcd[top].place);
       print_line();
       printf("\n\n Qualification :  ");
       scanf("%s",Rcd[top].qulftion);
       print_line();
       printf("\n\n Subject Name :  ");
       scanf("%s",Rcd[top].sub);
       print_line();
       printf("\n\n Date of Joining [ dd-mm-yyyy ] :");
       scanf("%s",Rcd[top].DOJ);
       print_line();
       printf("\n\n Phone Number  :");
       scanf("%s",Rcd[top].ph_no);
       print_line();
       printf("\n\n Total Amount :");
       scanf("%d",&Rcd[top].amount);
       print_line();
       printf("\n\n Paid Amount :");
       scanf("%d",&Rcd[top].paid);
       print_line();
       Total_amount+=Rcd[top].amount;
       Total_paid+=Rcd[top].paid;
       getch();
       goto START;
      }
     }
   }

  getch();
}


 void print_pop()
 {
  print_title1();
  printf("\n \t\t\t  Delete Function ");
  print_line();
  printf("\n 1-> Delet All        2-> Delet One-By-One        3->Display       4->Back ");
  print_line();
 }

 void Remove()
 {
  print_title2();
  if(top==-1)
  {
   printf("\n\n Under Flow...\n\n Student record book database does not exists.\n\n First creat the record database.");
   print_line();
   getch();
   return;
  }
  print_pop();
  printf("\n\n Enter Your Choice : ");
  POP_START:                               /* label */
  scanf("%d",&choice);
  print_pop();
  switch(choice)
  {
   case 1:
	  printf("\n\n Processing\a.\a.\a.\a.\a.");
	  top=-1;
	  Total_amount=Total_paid=0;
	  printf("..\a.\a.\a.\a...");
	  printf("\n\n Record data base is Removed.");
	  return;
							 break;

   case 2:           Delete();                           break;

   case 3:           Display();                          break;

   case 4:           return;                             break;

   default:
	   printf("\n\n\t\t Invailid  Selection. \n\n Enter once again.");
	   goto POP_START;
  }
  getch();
 }


 void Delete()
 {
  DEL_START1:                                         /* label */
  print_pop();
  printf("\n\n Enter the student register number.\n\n\t[ Note :: To terminate enter Register Number == -1 ]");
  DEL_START2:
  print_line();
  printf("\n\n Register Number :: ");
  scanf("%s",Regst);
  print_line();
  if(TRMNAT(Regst))
  {
   getch();
   return;
  }
  else
  {
    if(top==-1)
    {
     printf("\n\n\t Under Flow...\n\n Student record data base does not exists. \n\n First creat the data base. ");
    }
    else
    {
      flag=0;
      for(i=0;i<=top;i++)
       if(strcmpi(Regst,Rcd[i].regst)==0)
	{
	  Re_temp=Rcd[i];
	  Rcd[i]=Rcd[top];
	  Rcd[top]=Re_temp;
	  flag=1;
	  break;
	}
      if(flag==0)
      {
	printf("\n\n \t Entered Register Number information is does not exists.\n\n \t Check the student record book.");
	printf("\n\n \t Enter the Register Number once again [ -1 to terminate ] : ");
	goto DEL_START2;
      }
      else
      {
	Total_amount-=Rcd[top].amount;
	Total_paid-=Rcd[top].paid;
	printf("\n\n The Register number  %s  record's are removed.",Rcd[top].regst);
	top--;
	getch();
	goto DEL_START1;
       }

    }
  }
  getch();
 }


 void Search()
 {
  print_title2();
  if(top==-1)
  {
    printf("\n\n Student record book database does not exists.\n\n First creat the record database.");
    print_line();
    getch();
    return;
  }
  else
  {
    printf("\n\n Enter the Register Number to search.\n\n \t [ NOTE : Enter Register Number = -1 to terminate ]");
    SRCH_TOP:
    print_line();
    printf("\n\n Register Number : ");
    scanf("%s",Regst);
    if(TRMNAT(Regst))
    {
     getch();
     return;
    }
    else
    {
     flag=pos=0;
     for(i=0;i<=top;i++)
      if(strcmpi(Regst,Rcd[i].regst)==0)
       {
	 flag=1;
	 pos=i;
	 break;
       }

     if(flag==0)
      {
	printf("\n\n The student record of  %s  does not exists.",Regst);
	print_line();
	printf("\n\n Enter once again. [-1 to terminate ]");
	goto SRCH_TOP;
      }
      else
      {
	printf("\n\n The student record of %s  register is found at position %d ",Rcd[pos].regst,pos+1);
	getch();
	return;
      }
    }
  }
 }


 void print_editor()
 {
  print_title1();
  print_line();
  printf("\n 1-> Register Number  2-> Candidate Name    3-> Qualification 4-> Place");
  print_line();
  printf(" 5-> Phone Number   6-> Subject   7-> Date of Join  8-> Total Amount ");
  print_line();
  printf("\n 9-> Paid Amount      10-> All Field's      11-> Back  ");
  print_line();
 }

 void Modify()
 {
  print_title2();
  if(top==-1)
  {
   printf("\n\n Student record book database does not exists.\n\n First creat the student record book database.");
   getch();
   return;
  }
  else
  {
    rpt='Y';
    while( rpt == 'Y' || rpt == 'y' )		//while(STREQLT(CHARUP(rpt)))
    {
     printf("\n\n Enter the register number to edit the data.\n\n\t [ NOTE : Enter Register Number == -1 to terminate ] ");
     print_line();
     E_START1:
     printf("\n\n Register Number :  ");
     scanf("%s",Regst);
     if(TRMNAT(Regst))
     {
      print_line();
      getch();
      return;
     }
     else
     {
      flag=pos=0;
      for(i=0;i<=top;i++)
       if(strcmpi(Regst,Rcd[i].regst)==0)
	{
	 flag=1;
	 pos=i;
	 break;
	}

      if(flag==0)
      {
       printf("\n\n The student record of %s register is does not exists. ");
       print_line();
       printf("\n\n Enter the register once again. [ -1 to terminate ] ");
       goto E_START1;
      }
      else
      {
       while( rpt == 'Y' || rpt == 'y' )	//while(STREQLT(CHARUP(rpt)))
       {
	print_editor();
	printf("\n\n Enter your choice :   ");
	E_START2:
	scanf("%d",&choice);
	print_editor();
	switch(choice)
	{
	  case 1:
	       R_TOP:
	       printf("\n\n New Register Number ::  ");
	       scanf("%s",Regst);
	       print_line();
	       count=0;
	       for(j=0;j<=top;j++)
	       {
		 if(pos==j)
		    continue;
		 if(strcmpi(Regst,Rcd[j].regst)==0)
		 {
		  count=1;
		  break;
		 }
	       }
	       if(count==0)
	       {
		printf("\n\n Register Number [ %s ] is modified",Rcd[pos].regst);
		print_line();
		strcpy(Rcd[pos].regst,Regst);
		printf("\n\n New Register Number = %s",Rcd[pos].regst);
		print_line();
		getch();
	       }
	       else
	       {
		 printf("\n\n The process of editing of register number is not possiable, because this record is already exists.");
		 printf("\n\n Enter the register number once again.");
		 print_line();
		 goto R_TOP;
	       }

	       break;

	  case 2:
	       printf("\n\n Candidate New Name :  ");
	       scanf("%s",Name);
	       print_line();
	       printf("\n\n The Candidate Name [ %s ] is modified",Rcd[pos].name);
	       strcpy(Rcd[pos].name,Name);
	       print_line();
	       printf("\n\n The Candidate New Name ::  %s",Rcd[pos].name);
	       print_line();
	       getch();
	       break;


	 case 3:
	       printf("\n\n New Qualification :  ");
	       scanf("%s",quali);
	       print_line();
	       printf("\n\n The student Qualification [ %s ] is modified.",Rcd[pos].qulftion);
	       strcpy(Rcd[pos].qulftion,quali);
	       print_line();
	       printf("\n\n The Student Qualification is  %s ",Rcd[pos].qulftion);
	       print_line();
	       getch();
	       break;


	 case 4:
	      printf("\n\n Student Place :  ");
	      scanf("%s",Plc);
	      print_line();
	      printf("\n\n The student place [ %s ] is modified.",Rcd[pos].place);
	      print_line();
	      strcpy(Rcd[pos].place,Plc);
	      printf("\n\n The Student Place :   %s  ",Rcd[pos].place);
	      print_line();
	      getch();
	      break;

	case 5:
	      printf("\n\n Phone Number :  ");
	      scanf("%s",PH_NO);
	      print_line();
	      printf("\n\n The Student Phone Number  [ %s ] is modified.",Rcd[pos].ph_no);
	      print_line();
	      strcpy(Rcd[pos].ph_no,PH_NO);
	      printf("\n\n New Phone Number : %s",Rcd[pos].ph_no);
	      print_line();
	      getch();
	      break;

	 case 6:
	      printf("\n\n Subject Name :  ");
	      scanf("%s",SUB);
	      print_line();
	      printf("\n\n The Subject Name [ %s ] is modified.",Rcd[pos].sub);
	      print_line();
	      strcpy(Rcd[pos].sub,SUB);
	      printf("\n\n New Subject :  %s. ",Rcd[pos].sub);
	      print_line();
	      getch();
	      break;


	 case 7:
	       printf("\n\n New Date [dd-mm-yyyy] :  ");
	       scanf("%s",Date);
	       print_line();
	       printf("\n\n Old Join Date : %s",Rcd[pos].DOJ);
	       strcpy(Rcd[pos].DOJ,Date);
	       print_line();
	       printf("\n\n New Date :  %s",Rcd[pos].DOJ);
	       print_line();
	       getch();
	       break;

	 case 8:
	       printf("\n\n New Total Amount :  ");
	       scanf("%d",&amt);
	       print_line();
	       printf("\n\n Old Amount :  %d",Rcd[pos].amount);
	       Total_amount-=Rcd[pos].amount;
	       Rcd[pos].amount=amt;
	       print_line();
	       printf("\n\n New Amount : %d",Rcd[pos].amount);
	       Total_amount+=Rcd[pos].amount;
	       print_line();
	       getch();
	       break;

	 case 9:
	       printf("\n\n New Paid Amount : ");
	       scanf("%d",&Paid);
	       print_line();
	       printf("\n\n Old Paid Amount : %d",Rcd[pos].paid);
	       Total_paid-=Rcd[pos].paid;
	       Rcd[pos].paid=Paid;
	       print_line();
	       printf("\n\n New Paid Amount : %d",Rcd[pos].paid);
	       Total_paid+=Rcd[pos].paid;
	       print_line();
	       getch();
	       break;

	 case 10:
	       printf("\n\n Enter the Student New Information. ");
	       CASE_6:
	       print_line();
	       printf("\n\n Register Number :  ");
	       scanf("%s",Regst);
	       flag=0;
	       for(j=0;j<=top;j++)
	       {
		 if(pos==j)
		    continue;
		 if(strcmpi(Regst,Rcd[j].regst)==0)
		  {
		    flag=1;
		    break;
		  }
	       }

	       if(flag==0)
	       {
		  print_line();
		  strcpy(Rcd[pos].regst,Regst);
		  printf("\n\n Candidate Name :  ");
		  scanf("%s",Rcd[pos].name);
		  print_line();
		  printf("\n\n Qualification : ");
		  scanf("%s",Rcd[pos].qulftion);
		  print_line();
		  printf("\n\n Place :  ");
		  scanf("%s",Rcd[pos].place);
		  print_line();
		  printf("\n\n Phone Number : ");
		  scanf("%s",Rcd[pos].ph_no);
		  print_line();
		  printf("\n\n Subject Name : ");
		  scanf("%s",Rcd[pos].sub);
		  print_line();
		  printf("\n\n Date Of Join [ dd-mm-yyyy ] :  ");
		  scanf("%s",Rcd[pos].DOJ);
		  print_line();
		  Total_amount-=Rcd[pos].amount;
		  printf("\n\n Total Amount : ");
		  scanf("%d",&Rcd[pos].amount);
		  Total_amount+=Rcd[pos].amount;
		  print_line();
		  Total_paid-=Rcd[pos].paid;
		  printf("\n\n Paid Amount :  ");
		  scanf("%d",&Rcd[pos].paid);
		  Total_paid+=Rcd[pos].paid;
		  Rcd[pos].balance=Rcd[pos].amount-Rcd[pos].paid;
		  print_line();
		  getch();
		  print_editor();
		  printf("\n\n The New Record.\n\n");
		  print_line();
		  print_display2();
		  printf("\n\n %03d   %-10.10s %-20.20s  %-15.15s  %-10.10s  %-10.10s",pos+1,Rcd[pos].regst,Rcd[pos].name,Rcd[pos].ph_no,Rcd[pos].place,Rcd[pos].qulftion);
		  print_line();
		  print_line();
		  print_display3();
		  printf("\n\n %03d    %-10.10s    %-15.15s %-10.10s    %05d     %05d     %06d",pos+1,Rcd[pos].regst,Rcd[pos].sub,Rcd[pos].DOJ,Rcd[pos].amount,Rcd[pos].paid,Rcd[pos].balance);
		  print_line();
		  getch();
		  return;
	       }
	       else
	       {
		printf("\n\n This record is alreary exists.");
		print_line();
		printf("\n\n Enter the New Register Number once again.");
		goto CASE_6;
	       }

	       break;


	 case 11:       return;
	       break;

	}
       }
      }
     }
    }
  }
  getch();
 }

 void print_display1()
 {
  print_title1();
  print_line();
  printf("\n \t\t\t  Display  Function ");
  print_line();
  printf("\n 1-> Query    2-> Display All    3->Back  ");
  print_line();

 }

 void print_display2()
 {
  printf("\n Sl.No Regst No   Candidate Name         Phone No.        Place   Qualification \n");
  print_line();
 }


 void print_display3()
 {
  printf("\n Sl.No  Register No.  Subject Name    Date of Join  T.Amount  P.Amount  Balace ");
  print_line();
 }


 void Display()
 {
  TOP:
  print_title2();
   if(top==-1)
   {
    printf("\n\n Student record database does not exists.\n\n First creat the record database.");
    print_line();
    getch();
   }
   else
   {
    print_display1();
    printf("\n\n Enter Your Choice : ");
    scanf("%d",&choice);
     switch(choice)
      {
	case 1:  rpt='Y';
	  while( rpt == 'Y' ||  rpt == 'y'  )	//while(STREQLT(CHARUP(rpt)))
	  {
	    print_display1();
	    printf("\n\n Enter the Register Number.\n\n\t [ Note : -1 to terminate ]");
	    Q_START:
	    print_line();
	    printf("\n\n Register Number :: ");
	    scanf("%s",Regst);
	    if(TRMNAT(Regst))
	    {
	     getch();
	     return;
	    }
	    else
	    {
	     flag=0;
	     for(i=0;i<=top;i++)
	      if(strcmpi(Regst,Rcd[i].regst)==0)
	      {
	       flag=1;
	       pos=i;
	       break;
	      }
	    if(flag==0)
	    {
	     printf("\n\n The student record of  %s Register number does not exists.\n\n Enter once again. [-1 to terminate] ",Regst);
	     goto Q_START;
	    }
	    else
	    {
	     print_display1();
	     print_display2();
	     printf("\n\n %03d   %-10.10s %-20.20s  %-15.15s  %-10.10s  %-10.10s",pos+1,Rcd[pos].regst,Rcd[pos].name,Rcd[pos].ph_no,Rcd[pos].place,Rcd[top].qulftion);
	     print_line();
	     print_line();
	     print_display3();
	     Rcd[pos].balance=Rcd[pos].amount-Rcd[pos].paid;
	     printf("\n\n %03d    %-10.10s    %-15.15s %-10.10s    %05d     %05d     %06d",pos+1,Rcd[pos].regst,Rcd[pos].sub,Rcd[pos].DOJ,Rcd[pos].amount,Rcd[pos].paid,Rcd[pos].balance);
	     print_line();
	     getch();
	    }

	    }
	  }
	  break;

	case 2:
	   printf("\n\n 1-> Student Record\t  2-> Subject Record\t  3-> Back");
	   print_line();
	   printf("\n\n Enter Your Choice :  ");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	    case 1:
		  print_display1();
		  print_display2();
		  for(i=0;i<=top;i++)
		  {
		    printf("\n\n %03d   %-10.10s %-20.20s  %-15.15s  %-10.10s  %-10.10s",i+1,Rcd[i].regst,Rcd[i].name,Rcd[i].ph_no,Rcd[i].place,Rcd[i].qulftion);
		  }
		  print_line();
		  break;
	    case 2:
		  print_display1();
		  print_display3();
		  for(i=0;i<=top;i++)
		  {
		    Rcd[i].balance=Rcd[i].amount-Rcd[i].paid;
		    printf("\n\n %03d    %-010.10s   %-15.15s %-10.10s    %05d     %05d     %06d",i+1,Rcd[i].regst,Rcd[i].sub,Rcd[i].DOJ,Rcd[i].amount,Rcd[i].paid,Rcd[i].balance);
		  }
		  print_line();
		  printf("\n\n   Total Amount     -  Total Paid Amount  =  Balance Amount  ");
		  print_line();
		  Total_bal=Total_amount-Total_paid;
		  printf("\n\n   %08ld \t    -  %08ld\t          =   %08ld  ",Total_amount,Total_paid,Total_bal);
		  print_line();
		  break;

	    case 3:  return;
		  break;


		}

      }

   }


  getch();
 }

void Sorting()
{
  for(i=0;i<=top;i++)
   for(j=0;j<=top-i-1;j++)
    if(strcmpi(Rcd[j].regst,Rcd[j+1].regst)>0)
     {
	Re_temp=Rcd[j];
	Rcd[j]=Rcd[j+1];
	Rcd[j+1]=Re_temp;
     }
 }
