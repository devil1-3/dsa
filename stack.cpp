#include<iostream>
using namespace std;
int a[20];
int top=-1;

void push(char x)
{
    top++;
    a[top]=x;
}

 
void pop()
{
     top--;
}

int main()
{
    char ch,x[20];
    cout<<"\n Enter the expression:\n";
    cin>>x;
    int i=0,c=0;
    while(x[i]!='\0')
     {
         ch=x[i];
         if(top==-1&&(ch==')'||ch=='}'||ch==']'))
          {
               cout<<"\n Invalid expreesion";
               c=1;
               break;
           }
          else
             {
               switch(ch)
                {
                   case'(':push(ch);
                   break;
                   case'[':push(ch);
                   break;
                   case'{':push(ch);
                   break;
                   case')':if(a[top]=='(')
                   pop();
                   break;
                   case'}':if(a[top]=='{')
                   pop();
                   break;
                   case']':if(a[top]=='[')
                   pop();
                   break;
                }
             }
                i++;
      }
         
       if(top==-1&&x[i]=='\0')
       cout<<"\n valid expression";
       else if(c!=1)
       cout<<"\n Invalid expression";


}
