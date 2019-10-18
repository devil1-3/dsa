
#include<iostream>
using namespace std;
class sparse_matrix
{
private:int r,c,t;
	int B[10][3];
public:
	void accept();
	void display();
	void addition(sparse_matrix p,sparse_matrix q);
	void simple_transpose(sparse_matrix p);
	void fast_transpose(sparse_matrix q);
};
void sparse_matrix:: accept()
{
	cout<<"\nEnter no. of rows and columns and no. of non-zero elements";
	cin>>r>>c>>t;
	B[0][0]=r;
	B[0][1]=c;
	B[0][2]=t;
	for(int i=1;i<=t;i++)
	{
		cout<<"\nEnter the element at row no.,column no. and the non-zero term";
		cin>>B[i][0]>>B[i][1]>>B[i][2];
	}
}
void sparse_matrix::display()
{
	cout<<"\nThe sparse matrix is:";

	for(int i=0;i<=t;i++)
		{
			cout<<"\n"<<B[i][0]<<"\t"<<B[i][1]<<"\t"<<B[i][2]<<"\n";
		}
}
void sparse_matrix::addition(sparse_matrix p,sparse_matrix q)
{
	int i=1,j=1,k=1;
	B[0][0]=p.B[0][0];
	B[0][1]=p.B[0][1];
	while(i<=p.t && j<=q.t)
	{
		if(p.B[i][0]==q.B[j][0])
		{
			if(p.B[i][1]==q.B[j][1])
			{
				B[k][0]=p.B[i][0];
				B[k][1]=p.B[i][1];
				B[k][2]=p.B[i][2]+q.B[j][2];
				i=i+1;
				j=j+1;
				k=k+1;
			}
			else if(p.B[i][1]<q.B[j][1])
			{
				B[k][0]=p.B[i][0];
				B[k][1]=p.B[i][1];
				B[k][2]=p.B[i][2];
				i=i+1;
				k=k+1;
			}
			else
			{
				B[k][0]=q.B[j][0];
				B[k][1]=q.B[j][1];
				B[k][2]=q.B[j][2];
				j=j+1;
				k=k+1;
			}
		  }
		else if (p.B[i][0]<q.B[j][0])
			{
				B[k][0]=p.B[i][0];
				B[k][1]=p.B[i][1];
				B[k][2]=p.B[i][2];
				i=i+1;
				k=k+1;
			}
		else
		{
			B[k][0]=q.B[j][0];
			B[k][1]=q.B[j][1];
			B[k][2]=q.B[j][2];
			j=j+1;
			k=k+1;
        }
	}
while(i<=p.B[0][2])
{
	B[k][0]=p.B[i][0];
	B[k][1]=p.B[i][1];
	B[k][2]=p.B[i][2];
	i=i+1;
	k=k+1;
}
while(j<=q.B[0][2])
{
	B[k][0]=q.B[j][0];
	B[k][1]=q.B[j][1];
	B[k][2]=q.B[j][2];
	j=j+1;
	k=k+1;
}

cout<<"\nThe addition of sparse matrix is:";
B[0][2]=k-1;
for(int i=0;i<k;i++)
	{
		cout<<"\n"<<B[i][0]<<"\t"<<B[i][1]<<"\t"<<B[i][2]<<"\n";
	}
}
void sparse_matrix::simple_transpose(sparse_matrix q)
{
	int j=1;
	 B[0][0]=q.B[0][1];
	 B[0][1]=q.B[0][0];
	 B[0][2]=q.B[0][2];
	 for(int i=0;i<q.B[0][1];i++)
	 {
		 for(int k=1;k<=B[0][2];k++)
		 {
			 if(q.B[k][1]==i)
			 {
				 B[j][0]=q.B[k][1];
				 B[j][1]=q.B[k][0];
				 B[j][2]=q.B[k][2];
				  j++;

			 }
		 }
	 }
	 cout<<"\nsimple transpose\n";
	 for(int num=0;num<=q.B[0][2];num++)
	 {
		 cout<<"\n"<<B[num][0]<<"\t"<<B[num][1]<<"\t"<<B[num][2]<<"\t";

	 }

}
void sparse_matrix::fast_transpose(sparse_matrix p)
{
	B[0][0]=p.c;
	B[0][1]=p.r;
	B[0][2]=p.B[0][2];
	int temp;
	int d;
	int count[temp];
	for(int i=0;i<p.B[0][1];i++)
	{
		count[i]=0;
	}
	for(int i=1;i<=p.B[0][2];i++)
	{
		temp=p.B[i][1];
		count[temp]++;
	}
	int index[temp];
	index[0]=1;
	for(int i=1;i<p.B[0][1];i++)
	{
		index[i] = index[i-1] + count[i-1];
	}
	for(int i=1;i<=p.B[0][2];i++)
	{
		int k;

		d=p.B[i][1];
		k=index[d];
		B[k][0] = p.B[i][1];
		B[k][1] = p.B[i][0];
		B[k][2] = p.B[i][2];
		index[d]++;
	}
	cout<<"\nfast transpose\n";
	int i;
	for(i=0;i<=B[0][2];i++)
	{
		cout<<"\n"<<B[i][0]<<"\t"<<B[i][1]<<"\t"<<B[i][2];
	}
}
int main()
{
	sparse_matrix s1,s2,s3,s4,s5,s6;
	s1.accept();
	s1.display();
	s2.accept();
	s2.display();
	s3.addition(s1,s2);
	//s3.addition(s1,s2);
	cout<<"\nEnter matrix for transpose";
	s4.accept();
	s5.simple_transpose(s4);
	s6.fast_transpose(s4);
	return 0;
}



