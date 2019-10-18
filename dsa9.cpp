#include<iostream>
using namespace std;
struct node
{
	int roll_no;
	struct node *addr_next;	
};
class Queue
{
	node *front,*rear;
	public:
	Queue()
	{
		front=rear=NULL;
	}
	void insert();
	void Delete();
	void display();
};
void Queue::insert()
{
	int roll_no;
	cout<<"\nEnter Job-ID:\n";
	cin>>roll_no;	
	node *tmp=new node;
	tmp->roll_no=roll_no;
	tmp->addr_next=NULL;
	if(front==NULL)
	{
		front=rear=tmp;
	}
	else
	{
		rear->addr_next=tmp;
		rear=tmp;
	}
}
void Queue::Delete()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty :-(\n";
	}
	else
	{
		node *tmp;
		tmp=front;
		cout<<" [<"<<tmp->roll_no<<">|"<<tmp->addr_next<<"]  --> ";
		front=front->addr_next;
		delete(tmp);
	}
}
void Queue:: display()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty :-(\n";
	}
	else
	{
		node *q=front;
		while(q!=NULL)
		{
			cout<<" [<"<<q->roll_no<<">|"<<q->addr_next<<"]  --> ";
			q=q->addr_next;	
		}
	}
}
int main()
{
	Queue q;
	int ch, con;
	do
	{
	cout<<"\n\n\n~~~~~~~~~QUEUE OPERATION~~~~~~~~\n1.Insert\n2.Delete\n3.display\nEnter your choice::\n";
	cin>>ch;
	switch(ch)
	{
		case 1:	q.insert();
		break;
		case 2:
			q.Delete();
		break;
		case 3:
			q.display();
			break;
	}
	cout<<"\nDO you want to continue???press 1:";
	cin>>con;
	}while(con==1);
	return 0;
}
