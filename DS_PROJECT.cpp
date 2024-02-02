#include <stdio.h>                                                                                             
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct voter_information
{
    char reg_no[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head;
node *space,*start=NULL;
node *search(char x[],char y[],node *,int *);
node *voter_insert(node *);
node *main_logs(node *);
 void admin();
 void winner();
 	void exi();
 	void voting();
 	void not_again();
 	void stop();
 	void show();


int count=0,R=3,vote=0;
int vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;
int main()
{
	while(1){

    system("cls");
    cout<<"\n\n\n";
    cout<<"\t\t\t****** WELCOME TO THE ONLINE VOTING PORTAL ******\n\n";


    cout<<"\t\t\t****** Please Enter 1 for logging vote main Logs ******    \n\n\n";
    int BB;

    cin>>BB;
    if(BB==1)
    {
      start=  main_logs(start);
    }

}
    return 0;
}

node *main_logs(node *start)
{
    system("cls");
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t1. FOR VOTE ENTRY     \n";
    Sleep(300);
    cout<<"\t\t\t\t\t2. FOR ADMIN PANEL    \n";
    Sleep(300);
    cout<<"\t\t\t\t\t3. FOR WINNER         \n\n";
    cout<<"IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n";
    Sleep(500);
    cout<<"*******Please Enter your choice*******\n\n\n";
    int T;
    cin>>T;
    if(T==1)
    {
       start= voter_insert(start);
    }
    if(T==2)
    {
      admin();
    }
    if(T==3)
    {
      winner();
    }
    if(T!=1||T!=2||T!=3)
    {
    	main_logs(start);
	}


    return start;
}


node *voter_insert(node *start)
{
	int UNIVERSAL=0;
int *z;
 z = &UNIVERSAL;
     
     char name[50],birth_date[15],aadhar[20];
     system("cls");
     cout<<"\n\n\n\n";
     cout<<"IF REGISTRATION NUMBER MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n";
     Sleep(300);
     cout<<"ATTEMPTS LEFT :" <<R<<"\n\n\n";
     Sleep(300);
     cout<<"Please enter your \n";
     Sleep(300);
     cout<<"\t\tRegistration  number : ";
     fflush(stdin);
     fflush(stdout);
     cin.get(aadhar,20);
     cout<<"\t\tNAME :  ";
     fflush(stdin);
     fflush(stdout);
     cin.get(name,50);
     //cout<<"\t\t\tEnter Your BIRTH DATE  in dd-mm-yyyy format";
     //fflush(stdin);
     
     //gets(birth_date);
     node *temp =new node();
     strcpy(temp->reg_no,aadhar);
     strcpy(temp->name,name);
     //strcpy(temp->birth_date,birth_date);
     temp->next=NULL;
     head=temp;
     while(temp!=NULL)
     {
     	int regno=atoi(temp->reg_no);
     	
       
         if((regno>=210968000)&&(regno <=210968999)){
         	R=3;
         	start=search(temp->reg_no,temp->name,start,&UNIVERSAL);

         	if(UNIVERSAL==0)
            {
            	 voting();
			}
            else
             {
             	not_again();
			 }
           }
         else
            {
              R--;
         if(R==0)
         {
             stop();
             break;
         }
         cout<<"\n\n\n\n";
         cout<<"\tYour Registration Number or Name or Date of Birth is wrong\n\n";
         Sleep(300);
         cout<<"\t\t\tPlz Re-Enter\n\n";
         Sleep(300);
         system("pause");
        start= main_logs(start);
            }
            temp=temp->next;
     }
     return start;
}


void voting()
{
     system("cls");
     
    cout<<"\n\n\n\n";
    cout<<"\t\t         * * * * * LIST OF CANDIDATES * * * * * \n\n\n";
    Sleep(300);
    cout<<"\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n";
    Sleep(300);
    cout<<"\t\t\t 1. Amarendra Baahubali      	   (1)Chariot\n";
    Sleep(300);
    cout<<"\t\t\t 2. Kattapa                       (2)Sword\n";
    Sleep(300);
    cout<<"\t\t\t 3. Bhallaladeva                  (3)Bull\n";
    Sleep(300);
    cout<<"\t\t\t 4. Sivagami                      (4)Albatross\n";
    Sleep(300);
    cout<<"\t\t\t 5. Devasena                      (5)Swan \n\n\n";



       int B,j;
       
       cout<<"\t\t\t Enter Your Choice \n";
       for(j=1;j<=1;j++)
       {
           cin>>B;

           if(B==1)
           {
               vote1++;
               cout<<"\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO AMARENDRA BAHUBALI\n";
               break;

           }
           if(B==2)
           {
               vote2++;
                cout<<"\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO KATAPPA\n";
               break;

           }
           if(B==3)
           {
               vote3++;
                cout<<"\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO BHALLADEVA\n";
               break;

           }
           if(B==4)
           {
               vote4++;
                cout<<"\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO SIVAGAMI\n";
               break;
           }
           if(B==5)
           {
               vote5++;
                cout<<"\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO DEVASENA\n";
               break;
           }
            if(B!=1||B!=2||B!=3||B!=4||B!=5)
           {
           	cout<<"\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n";
           	cout<<"\n\t\t\tENTER AGAIN\t\t\t\n";
		   }



       }
	   cout<<"\n\n*************************THANK YOU**************************\n\n";
	   cout<<"press any key";
	   cin.get();
}

 void admin()
 {
     int B;
     cout<<"\n\n\n\n";
     cout<<"\t\t\t\t\tEnter Your Password To Unlock The Admin Panel\n\n";
     cin>>B;
     if(B==3692)
     {
         show();

     }
     else
     {
         cout<<"Wrong Password\n";
     }
 }

  void show()
  {
  	int G;
      system("cls");

      cout<<"\n\n\n\n";
      cout<<"\t\t\tPresent Vote Count :\n\n";
      Sleep(500);
      cout<<"\t\t\t  Amarendra Bahubali is on "<< vote1 <<  " Votes\n";
      Sleep(500);
      cout<<"\t\t\t  KATAPPA is on "<< vote2<<" Votes\n";
      Sleep(500);
      cout<<"\t\t\t  Bhalladeva is on  "<<vote3<<" Votes\n";
      Sleep(500);
      cout<<"\t\t\t  Sivagami  is on  "<<vote4<<"Votes\n";
      Sleep(500);
      cout<<"\t\t\t  Devasena  is on "<<vote5<<" Votes\n\n\n\n";
      Sleep(500);


      cout<<"\t\t\t\t\tEnter Any Key For Main Logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL\n ";
    cin>>G;
    if(G==1234)
    exi();
    else
    main_logs(start);

  }

   void winner()
   {
       system("cls");
       cout<<"\n\n\n\n";
       if(vote2<vote1 && vote3< vote1 && vote4<vote1 && vote5<vote1)
        cout<<"\t\t\tThe present Winner is Amarendra Bahubali and she has got "<<vote1<<" votes\n\n\n\n";

       if(vote1<vote2 && vote3< vote2 && vote4<vote2 && vote5<vote2)
        cout<<"\t\t\tThe present Winner is KATAPPA and she has got "<<vote2<<" votes\n\n\n\n";

        if(vote1<vote3 && vote2< vote3 && vote4<vote3 && vote5<vote3)
        cout<<"\t\t\tThe present Winner is Bhalladeva and she has got "<<vote3<<" votes\n\n\n\n";

        if(vote1<vote4 && vote2< vote4 && vote3<vote4 && vote5<vote4)
        cout<<"\t\t\tThe present Winner is Sivagami and he has got "<<vote4<<" votes\n\n\n\n";

        if(vote1<vote5 && vote2< vote5 && vote3<vote5 && vote4<vote5)
        cout<<"\t\t\tThe present Winner is Devasena and he has got "<<vote5<<" votes\n\n\n\n";
		
		else
		
        cout<<"\t\t\t\tEnter Any Key for Main Log\n\n";
        cin.get();
        main_logs(start);

   }

   void stop()
   {
       system("cls");

       cout<<"\n\n\n\n";
       cout<<"\t\t\t (:-SORRY YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW -:) \n\n\n";
       Sleep(500);
       cout<<"\t\t\t Plz try again After A few Moment\n\n\n";
       Sleep(500);
       cout<<"\t\t\t * * Thank You * *  \n\n\n";
       Sleep(500);
       cout<<"press any key";
       cin.get();

   }

   void not_again()
   {
        int A;
		system("cls");
        cout<<"\n\n\n\n";
        cout<<"\t\t\tYOU HAVE GIVEN YOUR VOTE SUCCESSFULLY \n\n\n";
        Sleep(300);
        cout<<"\t\t\tYOU CANNOT GIVE YOUR VOTE MORE THAN ONCE    \n\n\n";
        Sleep(300);
        cout<<"\t\t\t If You want to see present winner Enter One(1) or Enter Any Other Key for Main  Logs\n\n";
        Sleep(300);

        cin>>A;
        if(A==1)
        {
            winner();
        }
        else
        {
            main_logs(start);
        }

   }

   void exi()
   {
       system("cls");

       cout<<"\n\n\n\n\n";
       Sleep(500);
       cout<<"\t\t\tYOU ARE NOW EXITING THE PORTAL     \n\n\n";
       Sleep(1000);
       cout<<"\t\t\tThank You For Using This ONLINE PLATFORM For VOTING  \n\n\n";
       Sleep(1000);
       exit(0);
   }
node *search(char x[],char y[],node *start,int *Y)
{
	 *Y=0;
  node *t,*space;
  if(start==NULL)
  {
      node *space=new node();
     strcpy(space->reg_no,x);
     strcpy(space->name,y);
    

      start=space;
      space->next=NULL;

  }
  else
  {
      t=start;
      while(t!=NULL)
       {
          if((strcmp(t->reg_no,x)==0&& strcmp(t->name,y)==0 ))
          {
          	*Y=1;

          	break;
          }
              t=t->next;
    	}

          if(*Y==0)
          {

              node *space=new node();

       		strcpy(space->reg_no,x);

       		strcpy(space->name,y);

	        t=space;
    	    space->next=NULL;

    	}
  }
  return start;
 }