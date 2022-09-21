#include<iostream>
#include<string>
#include<string.h>
using namespace std;    
struct Node            //------>patient credentials node
{
    Node* next;
    string name;
    long long cnic;  
    string disease;
    int day;
	int month;
	int year;
	int roomNo;        //--------->auto select
};
Node* head = NULL;
Node* tail = NULL;
class Hospital
{
    int length;       //----->as patient added
    int total_room;  //------>==20
public:
    Hospital()
    {
        length = 0;
        total_room=20;
    }
    bool room_available() const
    {
    	if(length>total_room)
       {
       	cout<<"Sorry :-( Room Not Available"<<endl;
       	return false;
	   }
	   return true;
	}
	void Insert(string Name,long long CNIC,string Disease,int Day,int Month,int Year)
    {   Node* newNode = new Node;//new patient
        newNode->name = Name;//credentials
        newNode->cnic=CNIC;
        newNode->disease=Disease;
        newNode->day=Day;
        newNode->month=Month;
        newNode->year=Year;
        newNode->roomNo=length;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;//passing adress of next one 
            tail = tail->next;//moving tail itself forwrd
        }
    length++;
    total_room--;    
    cout<<"\t\t  Patient added successfully"<<endl;
    
   }
   void Delete(long long CNIC){
  Node* temp = head;
        //----->for first patient
        if (CNIC==head->cnic)
		  { 
			head = head->next;
            length--;
            return;
            }
        //----------> for middle patient            
        while (temp->next != NULL){
            if (temp->next->cnic==CNIC){ 
	   		    temp->next = temp->next->next;
                length--;
                return;
            }
            temp = temp->next;
			}
		//----------> for last patient
		if(temp->next==NULL)
		{	Node *temp2=head;
        	while(temp2->next->next!=NULL)
        	{
        		temp2=temp2->next;
			}
			temp2=NULL;
         return;	
		}
        cout << "Patient Not Found " << endl;
     }
    bool isEmpty() const
    {
        if (head == NULL)
        {
            return true;
        }
        else 
        return false;
    }  
	 void Display()
    {
	    if(isEmpty())
		{
			cout<<"No data found "<<endl;
		}
		else
		{
		cout<<endl<<endl<<"\t\t__________Patient Data___________"<<endl;
        Node* temp = head;
        do{
		 cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;   
		 temp = temp->next;
        } while (temp->next != NULL);
		 cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl;
    }
    }
       bool checkString(string passed,string inClass) const
    {
    	int size1=passed.length();
    	//cout<<"Length of passed string"<<size1<<endl;
    	int size2=inClass.length();
    	//cout<<"Length of string in ccc"<<size2<<endl;
    	if(size1==size2)
    	{
			for(int i=0;i<size1;i++)
			{
				if(passed[i]!=inClass[i])
				{
					return false;
				}
			}
			return true;
    	}
    	else 
    	return false;
}
void searching (int room)//---------->by room number
{       Node* temp = head;
		while (temp->next != NULL)
        {
            if (temp->roomNo == room)
            {
         cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;
        return;
            }
            temp = temp->next;
        
		}   
		if(temp->next==NULL&&temp->roomNo==room)
        {
         cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;
         return;	
		}
        
        else	  
        cout << "Data Not Found " << endl;

}
//------->by cnic
void searching (long long CNIC)
{       Node* temp = head;
		while (temp->next != NULL)
        {
            if (temp->cnic == CNIC)
        {
         cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;
         return;
        }
            temp = temp->next;
        
		}   
		if(temp->next==NULL&&temp->cnic==CNIC)
        {
         cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;
         return;	
		}
        else	  
        cout << "Data Not Found " << endl;

}
//------------->by disease
void searching (string pass)
{       Node* temp = head;
		while (temp->next != NULL)
        {
            if (checkString(pass,temp->disease))
        {
         cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;
         return;
        }
            temp = temp->next;
		}   
		if(temp->next==NULL&&checkString(pass,temp->disease))
        {
         cout<<"\t\t          Name        : "<<temp->name<<endl;
         cout<<"\t\t          CNIC        : "<<temp->cnic<<endl;
         cout<<"\t\t          Disease     : "<<temp->disease<<endl;
         cout<<"\t\t          Admit Date  : "<<temp->day<<" / "<<temp->month<<" / "<<temp->year<<endl;
         cout<<"\t\t          Room Number : "<<temp->roomNo<<endl<<endl<<endl;
         return;	
		}
        else	  
        cout << "Data Not Found " << endl;
}

};
int main()
{   cout<<endl;
    cout<<"\t\t| Welcome to Hopital Managment System |"<<endl;
	Hospital obj;
menu:  
    cout<<"\t\t| Press 1 to Add Patient              |"<<endl;
    cout<<"\t\t| Press 2 to Discharge Patient        |"<<endl;
    cout<<"\t\t| Press 3 to Search patient           |"<<endl;
    cout<<"\t\t| Press 4 to Dispaly all patients     |"<<endl;
    cout<<"\t\t| Press any other key to exit         |"<<endl<<endl;
    int choice=0;
    cout<<"\n\t\t    Enter choice: ";
    cin>>choice;
    string Name,Disease;
 long long CNIC;
    int dd,mm,yy;
    int room;
    char option='y';
    bool check=true;
    while(choice==1||choice==2||choice==3||choice==4)
    {
    	if (choice==1)
    	{
		 while(option=='y'||option=='Y')
    	 {check=obj.room_available();
		 if(check==true)
		 {
         cout<<"\t\t    Enter Name        : ";cin>>Name;
         cout<<"\t\t    Enter CNIC        : ";cin>>CNIC;
         cout<<"\t\t    Enter Disease     : ";cin>>Disease;
         cout<<"\t\t    Enter Admit Date  : ";
		 cout<<"\n\t\t    Day               : ";cin>>dd;
		 cout<<"\t\t    Month             : ";cin>>mm;
		 cout<<"\t\t    Year              : ";cin>>yy;
		 obj.Insert(Name,CNIC,Disease,dd,mm,yy);
         cout<<"\t\t   you want to add another patient y/n  ";
         cin>>option;
         if(option=='n'||option=='N')
		  goto menu;
		}
		else
			goto menu;
		}
	}
     else if (choice==2){
        	cout<<"\t\t  Enter the Cnic to Discharge patient     "<<endl;
        	cin>>CNIC;
	        obj.Delete(CNIC);
	        cout<<"Patient Discharged"<<endl;
	        cout<<"Take CAre :-)"<<endl;
	goto menu;
        }	
    else if (choice==3)
        {   int opt;
            system("cls");
            while(opt==1||opt==2||opt==3){
		    cout<<"\t\t  Press 1 to Search with CNIC          "<<endl;
	        cout<<"\t\t  Press 2 to search with Room          "<<endl;
	        cout<<"\t\t  Press 3 to search with Disease       "<<endl;
	        cout<<"\t\t  Press 4 to go back to main menu      "<<endl;
        	cin>>opt;
        	if(opt==1){
        	cout<<"\t\t  Enter the Cnic to Search patient     "<<endl;
        	cin>>CNIC;
	        obj.searching(CNIC);
	        }
	        else if(opt==2){
	        cout<<"\t\t  Enter the Room to Search patient     "<<endl;
        	cin>>room;
	        obj.searching(room);
	        }
	        else if(opt==3){
	        cout<<"\t\t  Enter the dise to Search patient     "<<endl;
        	cin>>Disease;
	        obj.searching(Disease);
	        }
	        else if(opt==4)
	        {goto menu;
			}

         }
        }	
     
	    else if (choice==4)
        {
	       obj.Display();
	       goto menu;
        }
	}
	
    return 0;
}
