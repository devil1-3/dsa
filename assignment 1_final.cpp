
Name: Shreya .S. Wattamwar
div:B
roll no.:64
Assignment 1




#include<iostream>
using namespace std;

class student
{
	string name[5];
	int roll[10];
	int mark[5];
	char att[10];
	int N;
public:
	void get_data()
	{
			cout<<"enter total no. of students";
			cin>>N;
			int i;
			for(i=0;i<N;i++)
			{
				cout<<"enter roll, name, attendance(p/a)";
				cin>> roll[i]>>name[i]>>att[i];

				if(att[i]=='P'||att[i]=='p')
						{
							cout<<"enter marks";
							cin>>mark[i];
						}
				else
				{
					mark[i]= -1;
				}
			}
	}
	void display()
	{
		int i;
		for(i=0;i<N;i++)
		{
			cout<<"\n"<<roll[i]<<"\t"<<"\t"<<name[i]<<"\t"<<att[i]<<"\t"<<"\t"<<mark[i];

		}
	}
	void min_score()
	{
		int min=101;
		for(int i=0;i<N;i++)
		{
			if(att[i]=='p')
			{
				if(min>mark[i])
					min=mark[i];

			}
		}
		cout<<"\nminimum marks are="<<min;
	}
	void max_score()
	{
		int max=0;
		for(int i=0;i<N;i++)
		{
			if(att[i]=='p')
			{
				if(max<mark[i])
				{
					max=mark[i];
				}

			}

		}
		cout<<"\nmaximum marks are ="<< max;

	}
	void avg()
	{
		int avg;
		int x=0;
		for(int i=0;i<N;i++)
		{
			if(att[i]=='p')
			{
				x=x+mark[i];
			}
		}
		avg=x/N;
		cout<<"\n"<<"average marks are="<<avg;
	}
	void most()
	{
		int i,k,count[10];
		for(i=0;i<10;i++)
		{
			count[i]=0;
		}
			for (i=0;i<N;i++)

			{
				k=mark[i]/10;
				count[k]++;
			}
		int max=0;
		for(i=0;i<10;i++)
		{
			if(count[i]>max)
				max=count[i];

		}

		cout<<"\nmaximum range in which students have scored the marks out of"<<N<<" students is"<<k*10<<"to"<<(k*10)+9;
	}
};
int main()
{
	student s;
	s.get_data();
	cout<<"\nroll no."<<"\tname"<<"\tattendance"<<"\tmarks";
	s.display();
	s.min_score();
	s.max_score();
	s.avg();
	s.most();
	return 0;
}


output
roll no.	name	attendance	marks
1		f	p		56
2		h	a		-1
3		g	p		58
minimum marks are=56
maximum marks are =58
average marks are=38
maximum range in which students have scored the marks out of3 students is50to59
