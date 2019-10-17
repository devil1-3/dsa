//Implement C++ program for expression conversion as infix to postfix and its evaluation using //stack .


#include <iostream>
using namespace std;

class inpo
{
    char in[20],po[20],stk[10];
    int i,j,is,ic,top,top1; 
    int stk1[10];
public:
    inpo()
    {
     i=j=is=ic=0; 
     top=top1=-1;
    }
    bool IsOperand(char C)
    {
        if(C >= '0' && C <= '9') return true;
        if(C >= 'a' && C <= 'z') return true;
        if(C >= 'A' && C <= 'Z') return true;
        return false;
    }
    void getinfix()
    {
        cout<<"\nEnter valid infix Expression: ";
        cin>>in; 
    }
    void showinfix() 
    {
        cout<<"\t"<<in;
    }
    int isempty() 
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if(top==9)
            return 1;
        else
            return 0;
    }
    void push1(int x1)
    {
        top=top+1;
        stk1[top]=x1;
    }
    int pop1() 
    {
       int s1;
       s1=stk1[top];
       top=top-1;
       return s1;
    }
    void push(char x)
    {
        top=top+1;
        stk[top]=x;
    }
    char pop()
    {
        char s;
        s=stk[top];
        top=top-1;
        return s;
    }
    void showpostfix()
    {
        cout<<"\t"<<po;
    }
    void convert();
    int instackprio();
    int incomingprio(char); 
    void postfixExpEval();
};
void inpo::convert()
{
    i=j=0;
    char p,k;
    while(in[i]!='\0')
    {
     p=in[i];
     if((p=='(')||(p=='+')||(p=='-')||(p=='*')||(p=='/')||(p=='^')||(p==')'))
     {
         if(isempty()) 
         {
             push(p); 
         }
         else if(p==')') 
         {
             k=pop();
             while(k!='(') 
             {
                 po[j]=k; 
                 j++;     
                 k=pop(); 
             }
         }
         else
         {
             is=instackprio(); 
             ic=incomingprio(p);
             if(is>ic)
             {
              k=pop();
              po[j]=k;
              j++;  
              push(p);
             }
             else
             {
                 push(p);
             }            
         }
     }
     else
     {
        po[j]=p;
        j++; 
     }
     i=i+1; 
    }
    if(in[i]=='\0')
    {
        while(!isempty())
        {
         k=pop(); 
         po[j]=k; 
         j++;  
        }
    }
 po[j]='\0'; 
}

/* * Function to check the instack priority of operator * */
int inpo::instackprio()
{
    char b;
    b=stk[top];
    switch(b)
    {
     case '(':return 0; break;
     case '+':return 2; break;
     case '-':return 2; break;
     case '*':return 4; break;
     case '/':return 4; break;
     case '^':return 5; break;
    }
}
/* * Function to check the priority of incoming operator * */
int inpo::incomingprio(char ch)
{
    switch(ch)
    {
     case '(':return 9; break;
     case '+':return 1; break;
     case '-':return 1; break;
     case '*':return 3; break;
     case '/':return 3; break;
     case '^':return 6; break;
    }
}

/*
void inpo::postfixExpEval() //To evaluate the postfix expression
{
    i=0;
    char ch;
    int op1,op2,res,tot;
        while(po[i]!='\0')//read postfix expression one by one
        {
            ch=po[i];
            if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^')) //isdigit(ch) built in function to check digit.
            {
                switch(ch)//if operator pop and perform operation and push back into the stack.
                {
                case '+':op2=pop1();
                         op1=pop1();
                         res=op1+op2;
                         push1(res);
                         break;
                case '-':op2=pop1();
                         op1=pop1();
                         res=op1-op2;
                         push1(res);
                         break;
                case '*':op2=pop1();
                         op1=pop1();
                         res=op1*op2;
                         push1(res);
                         break;
                case '/':op2=pop1();
                         op1=pop1();
                         res=op1/op2;
                         push1(res);
                         break;
                case '^':op2=pop1();
                         op1=pop1();
                         res=op1;
                         while(op2>1)
                         {
                          res=res*op1;
                          op2--;
                         }
                         push1(res);
                         break;
                }//end of switch

            } //end of if
            else if(IsOperand(ch))//To check operand we use IsOperand function.
            {
                push1(ch-'0'); //if operand push it inside stack
            } //end of else
            i=i+1;
        }//end of while

    tot=pop1(); //final evaluated result at the top of stack.
    cout<<"\nResult is:"<<tot;
}//end of function
*/



int main()
{
    inpo p1;
    p1.getinfix();
    p1.showinfix();
    cout<<"\nAfter conversion from infix to postfix...\n";
    p1.convert();
    p1.showpostfix();
 /*   cout << "\n\n!!!POSTFIX EXPRESSION EVALUATION ARE AS FOLLOWS..!!!" << endl;
    p1.postfixExpEval();*/
    return 0;
}
