// Created using Library management system using linklist BY Huzaifa Rehman
// login and password are needed to run this program
// Login = admin
// Password = library

#include<iostream>					//	Several standard input-output stream.
#include<conio.h>					// used provide console input/output
#include<stdlib.h>					// program control, dynamic memory allocation,
#include<string>					// for string
#include<dos.h>						//Used to delay, handling interrupts, producing sound,
#include<windows.h>					//All of the functions used in Windows 

using namespace std;

// Node deleration
struct libraryNode											//objects represent the information associated to node of the structure.
{
public:
    string Bookinfo,Authorinfo,publisherinfo;		// string variable
	
	int Secdepositinfo,Secdeposit,fine;	
    
	libraryNode *next;										//  next is pointer to node and next would point to an integer or string etc
};

//----------------------

class Listing:public libraryNode
{
 	libraryNode *head,*last;								//  first and last are pointers to node

public:
    Listing()
    {
        head=NULL;
        last=NULL;
}
    void purchaseInserting();
    void deleting();
    void searching();
    void displaying();
    void fullscreen();
    void login();
	void loading();
};


/*
 * Inserting elements
 */
void Listing::purchaseInserting()
{
		
    libraryNode *prev,*current;							//  prev and current is pointer to node and they would point to an integer
    
	prev=NULL;
    current=head;
    
	int count=1,choice,Secdeposit,pos; 
	string n,author,publisher;
	
    libraryNode *temp=new libraryNode;
    
	cout<<"\n\tEnter Book Name you want to buy:       ";
    cin>>n;
    cout<<"\n\tEnter a Book Author of your book:      ";
    cin>>author;
    cout<<"\n\tEnter a Book Publisher of your book:   ";
    cin>>publisher;
    cout<<"\n\tSecdeposit of Book is: \t\t\t";
    cin>>Secdeposit;
    
	temp->Bookinfo=n;						
	temp->Authorinfo=author;
    temp->publisherinfo = publisher;
	temp->Secdepositinfo=Secdeposit;
    
    temp->next=NULL;
    
    cout<<"\nAt which position you want INSERT Book."; 
	cout<<"\n\n 1:Book insertion at first in list \n 2:Insert BETWEEN the list of books or anywhere in list\n";
    
	cout<<"Press 1 insert at starting poistion of list\n  \t---OR--- \n Press 2 to insert at between of list \n";
	cout<<"\nEnter Your Choice:";
	
    cin>>choice;
    switch(choice)
    {
    	/*
 		* Inserting book in beginning
 		*/
    case 1:	
											// head = current
        temp->next=head;						// haed point to temp ky next ko
        head=temp;								// head value stored in temp
        break;
    
    	/*
 		* Insertion of Book at a given position
		*/
	case 2:
        cout<<"\nEnter the Position to Insert:";
		cin>>pos;
        
        while(count!=pos)
        {										// prev = NULL
            prev=current;						//previous have current value OR prev = NULL so current = NULL
            current=current->next;				//As previous = current and current. next = pre( false) because 2 member are on same position
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;					// prev points to next  
            temp->next=current;					// new address will be palced in temp as temp points to next and stored in current
        }
        else
            cout<<"\nInsert correct position of book in List. Not Able to Insert!!!";
        break;
 
    }
}
/*
 * Delete BOOK at a given position
 */
void Listing::deleting()
{
    libraryNode *prev=NULL,*current=head;
    
	int count=1,choice,pos;
    
    string n,author,publisher;
    
	cout<<"\nDELETE the book you want \n";
	
	cout<<"1. Delete the book from first position from your list \n";
    cout<<"2. Delete BETWEEN the list of books or anywhere in list";
	
	cout<<"\nPress 1 insert at starting poistion of list\n  \t---OR--- \n Press 2 to insert at between of list \n";
	cout<<"\nEnter Your Choice:";
    cin>>choice;
    
	switch(choice)
    {
    case 1:
    								// first = current value
        if(head!=NULL)				// if current value != NULL than delete
        {
            cout<<"\nDeleted Element is "<<"\n\t Book : \t\t\t\t\t"<<head->Bookinfo<<"\n\t Author : \t\t\t\t\t"<<head->Authorinfo<<"\n\t publisher : \t\t\t\t\t"<<head->publisherinfo<<"\n\t Secdeposit is retured at returning the book: \t"<<head->Secdepositinfo;
            head=head->next;			//item would be deleted and head will points to next
        }
        else
        
		    cout<<"\nNot Able to Delete from list, because already being used by others student";
        
		break;

    case 2:
    	
        cout<<"\nEnter the Position(1,2 0r 3 etc) of Deletion:";
        cin>>pos;
        								// previous == NULL
		while(count!=pos)				// if position != count
        {
            prev=current;				//previous have current value 
            current=current->next;		//As previous = current and current. next
            count++;
        }
        if(count==pos)					// position is equal to point
        {
            cout<<"\nDeleted Element is: "<<"\n\t BOOK \t\t"<<current->Bookinfo<<"\n\t Author : \t"<<current->Authorinfo<<"\n\t Publisher : \t"<<current->publisherinfo<<"\n\t Security deposit : \t"<<current->Secdepositinfo;
            
			prev->next=current->next;		// prev points to next and current points to next and element will be delted
											// "pos" link will break and prev.next will made connection with current.next
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}

//=============================
//--------Display Elements of a link list
//============================= 

void Listing::displaying()
{
    libraryNode *temp=head;						// temp pointer to Node and will point
    
    if(temp==NULL)
    {
        cout<<"\nBook is not in Library!!!";
    }
    while(temp!=NULL)
    {	
    
	cout<<"\n";	
    cout<<"\n  ----------------------------------";
		
        cout<<"\nBook Name is:\t\t\t"<<temp->Bookinfo;
        cout<<"\nAuthor Name is:\t\t\t"<<temp->Authorinfo;
        cout<<"\nPublisher Name is:\t\t"<<temp->publisherinfo;
        cout<<"\nBook Secuirty deposit is :\t"<<temp->Secdepositinfo;
		
		cout<<"\n============================ \n";
		temp=temp->next;					// temp points to next
    }
    cout<<"\n\t  ----------------------------------";
}

//===========================
//--------Searching an element
//===========================

void Listing::searching()
{
    string value; 
    
	int pos=0;
	
    bool flag=false;
    
	if(head==NULL)							// nothing to display
    {
        cout<<"No Book is found in library \n";
        return;
    }
    cout<<"Enter the Book name to be Searched in Library at where it is placed: \n";
    cin>>value;
    
    libraryNode *temp;							// temp pointer to libraryNode 
    
	temp=head;
    
    while(temp!=NULL)
    {
    	pos++;
        if(temp->Bookinfo==value)			// bookinfo == value
        {
        	flag=true;
            cout<<"\n \tBook || \t "<<value<<" \t || is Found at "<<pos<<" Position " << "in Library\n";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Book "<<value<<" not Found in the library and out of stock";
    }
}

void fullscreen()//fuction for fullscreen

{  	keybd_event(VK_MENU,
            	0x38,
                0,
				0);
   	keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
	keybd_event(VK_RETURN,
          		0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}
void login()//fuction for login
{
	
	
	int i=0; 				//for number of tries if you write wrong password
    char username[10]; 		//input from user
    char password[10]; 		//input from user
    char user[10]="admin"; 	//user name for camparing
    char pass[10]="library"; 	// password for camparing
    
	while(1)
	{
		cout<<"\n\n\n\n";
	    cout<<"\n\t\t\t\t\t_________________________________________________________________";
		cout<<"\n\t\t\t\t\t			LOGIN TO CONTINUE";
		cout<<"\n\t\t\t\t\t_________________________________________________________________";
		
		cout<<"\n\n\t\t\t\t\t_________________________________________________________________";
		cout<<"\n\t\t\t\t\tENTER USERNAME: \t";
		cin>>username; 									//inputs user name
		cout<<"\t\t\t\t\t_________________________________________________________________";
		
		cout<<"\n\n\t\t\t\t\t_________________________________________________________________";
		cout<<"\n\t\t\t\t\tENTER PASSWORD: \t";
		cin>>password; 									//inputs password
		cout<<"\t\t\t\t\t_________________________________________________________________";
		
		if(strcmp(username,"admin")==0 && strcmp(password,"library")==0)	//camparing username and password
		{
			cout<<"\n\n\n\t\t\t\t\tLOGIN IS SUCCESSFUL!!!!!!!!!!!!!";
			cout<<"\n\n\n\n\n\t\t\t\t\t\t\tPress any key to continue...";
			
			getch(); //holds the program
			system("cls"); //clears screen
			break;
		}
		else//if username and password is incorrect
		{
			cout<<"\n\n\n\t\t\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL!!!!";
			i++;
			cout<<"\n\n\n\n\n\t\t\t\t\t\t\tPlease Enter username and password again";
			
			getch();
			system("cls");	
		}
	}
}


// For loading purpose

void gotoxy(int x, int y) //function for cursor position
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loading() //function for loading screen
{
	int j;
	gotoxy(32,20);  //function for cursor position
	cout<<"Loading.......";
	gotoxy(0,22);
	
	for(j=0;j<=167;j++) //loop to print the characters for loading bar
	{
		cout<< 219; //219 is the ascii code for the character used in loading bar	
	int	usleep(10240); //to slow the program
	}
	
	int sleep(1); //for program to wait one second
	system("cls"); //clears screen
}


//===================================
// ----------- main------------------
//===================================
int main()
{
	fullscreen(); 					//function call of full screen
	login(); 						//function call of login screen
	loading(); 						//function call of loading screen
	
	system("color 6");				//color Change of text
	
	cout<< ("\n\n\n\n\n");
	cout<< ("\t\t\t\t\t   ______________________________________________________________\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                         WELCOME                             |\n");
	cout<< ("\t\t\t\t\t  |                           TO                                |\n");
	cout<< ("\t\t\t\t\t  |                      LIBRARY OF DSU                       	|\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |                                                             |\n");
	cout<< ("\t\t\t\t\t  |_____________________________________________________________|\n");

	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPress any key to Continue");
	getch(); 		//screen hold
	system("cls"); //clear screen
	
    Listing LL;
    int choice;		
    while(1)
    {	
		cout<<"\n\t\t  =============================";
        cout<<"\n\t\t  *********** MENU ************";
        cout<<"\n\t\t  =============================";
        
        cout<<"\n\t\t || \t 1:ADD New Book      || \n\t\t || \t 2:DELETE the Book   ||\n\t\t || \t 3:SEARCH the Book   || \n\t\t || \t 4:DISPLAY all Books ||\n\t\t || \t 5:EXIT Progarm!!!   ||\n ";
		cout<<"\n\t\t  =============================";
        cout<<"\n\t\t  =============================";
        
		cout<<"\nEnter Your Choice:  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            LL.purchaseInserting();
            break;
        case 2:
            LL.deleting();
            break;
        case 3:
            LL.searching();
            break;
        case 4:
            LL.displaying();
            break;
            
        case 5:    
            return 0;
        
        }
    }
}
