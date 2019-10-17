#include<iostream>
using namespace std;

struct node
{
	int rollno;
	struct node *next;
};
class queue
{
	node *front,*rear;
	public:
		queue()
		{
			front=rear=NULL;
		}
		void insert();
		void delet();
		void display();
};
void queue::insert()
{
	int rollno;
	cout<<"Enter job ID\n";
	cin>>rollno;
	node *temp=new node;
	temp->rollno=rollno;
	temp->next=NULL;
	if(front==NULL)
	{
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
void queue::delet()
{
	if(front==NULL)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		node *temp;
		temp=front;
		cout<<temp->rollno<<temp->next;
		front=front->next;
		delete(temp);
	}
}
void queue::display()
{
	if(front==NULL)
	{
		cout<<"QUEUE is empty\n";
	}
	else
	{
		node *q=front;
		while(q!=NULL)
		{
			cout<<"["<<q->rollno<<">|"<<q->next<<"]--->";
			q=q->next;
		}
	}
}
int main()
{
queue q;
int ch,m;
do
{
cout<<"QUEUE OPERATION \n";
cout<<"1.INSERT\n 2.DELETE \n 3.DISPLAY\n ";
cout<<"Enter your Choice\n";
cin>>ch;
switch(ch)
{
	case 1: q.insert();
		break;
	case 2: q.delet();
		break;
	case 3: q.display();
		break;
}
cout<<"DO you Want to continue??press 1:";
cin>>m;
}while(m==1);
return 0;
}

	
