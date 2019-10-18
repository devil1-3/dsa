#include<iostream>
using namespace std;
char exp[30];
struct node
{
char data;
struct node *next,*prev;
};

class stack
{
public:
node *top;
stack()
{
top=NULL;
}
void check();
void push(char c);
char pop();
};


void stack::check()
{
for(int i=0;exp[i]!='\0';i++)
{
if(exp[i]=='['||exp[i]=='('||exp[i]=='{')
{
push(exp[i]);
}
else 
{
if(top!=NULL)
{
char present=pop();
switch(exp[i])
{
case')':
if(present!='(')
    goto one;
    break;
case']':
if(present!='[')
    goto one;
    break;
case'}':
if(present!='{')
    goto one;
    break;
    
}
}
else
   {
     goto one;
   }

}
}
if(top==NULL)
   {
     cout<<"Valid expression";
   }
else 
   {
     one:
     cout<<"Invalid expression";
   }
}

void stack::push(char c)
{
node *temp=new node;
node *q;
temp->data=c;
temp->next=NULL;
temp->prev=NULL;
if(top==NULL)
{
temp->prev=NULL;
top=temp;
}
else
{
temp->prev=top;
top->next=temp;
top=temp;
}
}

char stack::pop()
{
node *temp;
temp=top;
char data=top->data;
top=top->prev;
delete(temp);
return data;
}

int main()
{
stack s;
cout<<"STACK OPERATION  \nENTER EXPRESSION\n";
cin>>exp;
s.check();
return 0;
}
