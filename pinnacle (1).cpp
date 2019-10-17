#include<iostream>
using namespace std;

struct node

{
	int PRN;
	char name[50];
	struct node *addr_next;
};

class Pinnacle_club
{
	public:
	int totalcount;
	node *start,*end,*q;
	
	Pinnacle_club()
	{
		start=NULL;
		end=NULL;
		totalcount=0;

	}
	void create();
	void display();
	void recursion(struct node*);
	void count();
	void concatinate(struct node*,struct node*);
	void president();
	void scretory();
	void deletepresident();
	void deletesectory();
	void deletemember();

};
void Pinnacle_club::president()
{
	node *tmp=new node;
	cout<<"\nEnter PRN and NAME::\n";
	cin>>tmp->PRN>>tmp->name;
	tmp->addr_next=NULL;
	if(start==NULL)
	{

		start=tmp;

	}


}
void Pinnacle_club::scretory()
{
	node *tmp=new node;
	cout<<"\nEnter PRN and NAME::\n";
	cin>>tmp->PRN>>tmp->name;
	tmp->addr_next=NULL;
	if(end==NULL)
	{

		end=tmp;

	}
	start->addr_next=end;


}
void Pinnacle_club::create()
{
	node *tmp=new node;
	cout<<"\nEnter PRN and NAME::\n";
	cin>>tmp->PRN>>tmp->name;
	tmp->addr_next=NULL;
	
			q=start;
		while(q->addr_next!=end)
		{
			q=q->addr_next;
				

		}
		tmp->addr_next=end;
		q->addr_next=tmp;

	

}
		

void Pinnacle_club:: display()
{
	if(start==NULL)
	{
		cout<<"Linked list is empty";


	}
	else
	{

		q=start;
		while(q!=NULL)
		{
			cout<<" [<"<<q->PRN<<","<<q->name<<">|"<<q->addr_next<<"]  --> ";
			q=q->addr_next;
			

		}
		cout<<"\n";
	}
}

void Pinnacle_club::recursion(struct node* head)
{
	
		

    // Base case  
    if (head == NULL)
    {
       return;
    }
 
    // print the list after head node
   recursion(head->addr_next);
 
    // After everything else is printed, print head
  	cout<<" [<"<<head->PRN<<","<<head->name<<">|"<<head->addr_next<<"]  --> ";

 
	
}
void Pinnacle_club:: count()
{

	

		q=start;
		while(q!=NULL)
		{
			
			q=q->addr_next;
			totalcount++;

		}
	
}
void Pinnacle_club::concatinate(struct node* start1,struct node* end1)
{
	node *tmp=new node;
	tmp=end;
	tmp->addr_next=start1;
	end=end1;
	display();

}
void Pinnacle_club::deletepresident()
{
	node *tmp=new node;
	tmp=start;
	start=start->addr_next;
	delete tmp;

}
void Pinnacle_club::deletesectory()
{
		node *tmp=new node;
		q=start;
		while(q->addr_next!=NULL)
		{
			tmp=q;
			q=q->addr_next;
				

		}
		tmp->addr_next=NULL;
		end=tmp;
	delete q;

}
void Pinnacle_club::deletemember()
{
	node *tmp=NULL;
	int mid,count=0;
	display();
	cout<<"Enter postion no::";
	cin>>mid;
	q=start;
	for(int i=1;i<=mid-1;i++)
	{
		tmp=q;
		q=q->addr_next;

	}
	tmp->addr_next=q->addr_next;
	q->addr_next=NULL;
	delete q;
	cout<<"\nAfter deltetion\n";
	display();



}
int main()
{
	Pinnacle_club p,p2;
	int ch, membercount;;
	char con;
	
	do
	{
	cout<<"\n-----------club operation---------\n1.Shift A\n2.Shift B\n3.display members\n4.recursion reverse\n5.compute total count\n6.delete\n";
	cout<<"Enter ur choice:\n";
	cin>>ch;
	
		switch(ch)
		{

			case 1:
			cout<<"\n******Enter Shift A*******\n";
			cout<<"Enter president & scretory\n";
			p.president();
			p.scretory();
			cout<<"Enter how many members do u want to enter....\n";
			
			cin>>membercount;
			for(int i=0;i<membercount;i++)
			{
				p.create();
			}
			p.display();
			
			break;


			case 2:
			cout<<"\n******Enter Shift B*******\n";
			cout<<"Enter president & scretory\n";
			p2.president();
			p2.scretory();
			cout<<"Enter how many members do u want to enter....\n";
			
			cin>>membercount;
			for(int i=0;i<membercount;i++)
			{
			p2.create();
			}
			cout<<"\n-----------------Concatination--------------\n";
			p.concatinate(p2.start,p2.end);
			p2.display();
			break;
			case 3:
			p.display();
			break;
			case 4:
			p.recursion(p.start);
			break;
			case 5:
			p.count();
			cout<<"TotalCount::"<<p.totalcount;
			break;
			
		
			case 6:
			cout<<"---------operation---------\n1.delete president\n2.delte scretory\n3.delete member.\n";
			int choice;
			cout<<"\nenter ur choice::\n ";
			cin>>choice;
			if(choice==1)
			{
				p.deletepresident();
			}
			else if(choice==2)
			{

				p.deletesectory();
			}
			else
			{
				p.deletemember();

			}
			break;



		}
		cout<<"\n\nDo you want to continue???press y::";	
		cin>>con;
	}while(con=='y');
	return 0;
	
}

