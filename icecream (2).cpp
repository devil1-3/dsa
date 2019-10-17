#include<iostream>
using namespace std;
struct node 
{
  int data;
  node *next;
};
node *temp=NULL;
node *head=NULL;
node *p=NULL;
node *q=NULL;

     node *create()
{
     int n,i;
     cout<<"Enter the total no of students:";
     cin>>n;
     for(i=0;i<n;i++)
{
      temp = new node;
      cout<<"Enter the student: ";
      cin>>temp->data;
      temp->next=NULL;
       if(head==NULL)
   {
        head = temp;
   }
        else
   {
      p=head;
      while(p->next!=NULL)
    {
      p=p->next;
    }
     temp->next = p;
    }
}
return head;
}

int Union( node *head1 , node *head2)
{
    int flag=0,count=0;
    temp=head1;
    while(temp!=NULL)
  {
      cout<<"\t "<<temp->data;
      temp=temp->next;
      count++;
  }
     for(q=head2;q!=NULL;q=q->next)
  {
        flag=0;
     for(temp=head1;temp!=NULL;temp=temp->next)
 	if(q->data==temp->data)
	 {
        	flag=1;
         	break;
          }
     if(flag!=1)
  {
     cout<<"  "<<q->data<<endl;
     count++;
  }
   return count;
}   
}
      void display(node *head)
   {
        int counter=0;
         p=head;
         while(p!=NULL)
       {
          cout<<"  "<<p->data;
          p=p->next;
          counter++;
       }
           cout<<"\nTotal number of students are : "<<counter<<endl;
   }
          void intersection(node *head1,node *head2)
      {
             int found=0;
           for(p=head1;p!=NULL;p=p->next)
              {
                  found=0;
           for(q=head2;q!=NULL;q=q->next)
                if(p->data==q->data)
                   {
                       found=1;
                        break;
                    }
                if(found==1)
                  cout<<"\t "<<p->data;
              }
                 cout<<endl;

      }
          void only1(node *head1,node *head2)
      {
            int found=0; 
           for(p=head1;p!=NULL;p=p->next)
          {
               found=0;
            for(q=head2;q!=NULL;q=q->next)
                if(p->data==q->data)
                  {
                      found=1;
                       break;
                   }
               if(found!=1)
               cout<<"  "<<p->data;
          }
              cout<<endl;

     }
     void only2(node *head1,node *head2)
{
       int found=0;
        for(q=head2;q!=NULL;q=q->next)
   {
         found=0;
         for(p=head1;p!=NULL;p=p->next)
              if(q->data==p->data)
            {
                found=1;
                 break;
             }
               if(found!=1)
               cout<<"  "<<q->data;
    } 
          cout<<endl;
}


int main()
{

node *head,*head1;
head=head1=NULL;
int m,ch,count=0;
cout<<"Enter Total Number of students in class: ";
cin>>m;

do
{

cout<<"\n\n......Select the options......"<<endl;
cout<<"Enter your choice :\n1.Create\n2.Print\n3.Students who like vanilla or butterscotch or both.\n4.Students who like both vanilla and butterscotch.\n5.Students who like only vanilla.\n6.Students who like only butterscotch.\n7.Number of Students who neither like vanilla nor butterscotch.\n8.Exit\n";
cin>>ch;
switch(ch)
{
case 1: cout<<"Students who like vanilla\n";
	  head=create();
	  cout<<"Students who like butterscotch\n";
	  head1=create();
	  break;
case 2: cout<<"Students who like vanilla are: \n";
	  display(head);
	  cout<<"Students who like vanilla are: \n";
	  display(head1);
	  break;
case 3: cout<<"Students who like Vanilla or Butterscotch are: \n";
	  Union(head,head1);
	  break;
case 4: cout<<"Students who like both Vanilla and butter :\n";
	intersection(head,head1);
	  break;
case 5: cout<<"Students who like only Vanilla: \n";
	  only1(head,head1);
	  break;
case 6: cout<<"Students who like only Butterscotch: \n";
	  only2(head,head1);
	  break;
case 7: count=Union(head,head1);
	cout<<"\nNumber of Students who neither like Vanilla nor Butterscotch is : "<<m-count<<endl;
	  break;
}
}while(ch!=8);

}	



