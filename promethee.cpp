#include<bits/stdc++.h>
using namespace std;

int main()
{
	int crt,alt;
	cout<<"Enter no. of criteria and alternative :"<<endl;
	cin>>crt>>alt;
	float table[alt][crt];
	cout<<endl;

	cout<<"enter values of table :"<<endl;

	for(int i=0;i<alt;i++)
		for(int j=0;j<crt;j++)
			cin>>table[i][j];
	cout<<endl;
	cout<<"enter weights :"<<endl;

	float weight[crt];
	for(int i=0;i<crt;i++)
		cin>>weight[i];

	cout<<"Enter benifit :"<<endl;
	int benifit[crt];
	for(int i=0;i<crt;i++)
		cin>>benifit[i];

	cout<<endl;

	float maxv[crt];
	float minv[crt];
	for(int i=0;i<crt;i++)
	{
		maxv[i]=table[0][i];
		minv[i]=table[0][i];
	}
	for(int i=0;i<crt;i++)
	{
		for(int j=1;j<alt;j++)
		{
			maxv[i]= max(table[j][i],maxv[i]);
			minv[i]= min(table[j][i],minv[i]);
		}
	}

	cout<<"Max X(i,j), Min X(i,j) :"<<endl;

	for(int i=0;i<crt;i++)
	{
		cout<<"Alt 1 : "<<maxv[i]<<" , "<<minv[i]<<endl;
	}
	cout<<endl;

	cout<<"Table after next step :"<<endl;
	cout<<endl;
	for(int i=0;i<alt;i++)
	{
		for(int j=0;j<crt;j++)
		{
			if(benifit[j]==1)
			{
				table[i][j]=(table[i][j]-minv[j])/(maxv[j]-minv[j]);
			}
			else
				table[i][j]=(maxv[j]-table[i][j])/(maxv[j]-minv[j]);
			cout<<table[i][j]<<"       ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"Table after next step :"<<endl;
	cout<<endl;

	int k=0;
	float table2[alt*alt][crt];

	for(int i=0;i<alt;i++)
	{
		for(int i1=0;i1<alt;i1++)
		{
			if(i!=i1)
			{
			for(int j=0;j<crt;j++)
			{
			
				table2[k][j]=table[i][j]-table[i1][j];
				cout<<table2[k][j]<<"     ";
			}
			k++;
			cout<<endl;
			}
		}
	}
	cout<<endl;

	

	cout<<"Table after next step :"<<endl;

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<crt;j++)
		{
			if(table2[i][j]<0)
			{
				table2[i][j]=0;
			}
			cout<<table2[i][j]<<"     ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"Table after next step :"<<endl;
	cout<<endl;

	float sum_table[k][1];

	for(int i=0;i<k;i++)
	{
		sum_table[i][0]=0;
		for(int j=0;j<crt;j++)
		{
			table2[i][j]*=weight[j];
			cout<<table2[i][j]<<"    ";
			sum_table[i][0]+=table2[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"Summition Table after next step :"<<endl;
	cout<<endl;

	for(int i=0;i<k;i++)
		cout<<sum_table[i][0]<<endl;
	cout<<endl;

	int temp=0;

	cout<<"Table after next step :"<<endl;
	cout<<endl;

	float table3[alt][alt]; 
	for(int i=0;i<alt;i++)
	{
		for(int j=0;j<alt;j++)
		{
			if(i!=j)
			{
				table3[i][j]=sum_table[temp][0];
				temp++;
			}
			else
			{
				table3[i][j]=0;
			}

			cout<<table3[i][j]<<"    ";
		}
		cout<<endl;
	}
	cout<<endl;

	float lf_pos[alt],lf_neg[alt],lf[alt];

	for(int i=0;i<alt;i++)
	{
		lf_pos[i]=0;
		for(int j=0;j<alt;j++)
		{
			lf_pos[i]+=table3[i][j];
		}
		lf_pos[i]/=alt-1;
	}

	for(int j=0;j<alt;j++)
	{
		lf_neg[j]=0;
		for(int i=0;i<alt;i++)
		{
			lf_neg[j]+=table3[i][j];
		}
		lf_neg[j]/=alt-1;
	}

	for(int i=0;i<alt;i++)
		lf[i]=lf_pos[i]-lf_neg[i];

	cout<<"Table after next step :"<<endl;
	cout<<endl;
	cout<<"Leaving flow, Entering flow, sum :"<<endl;
	cout<<endl;
	for(int i=0;i<alt;i++)
	{
		cout<<lf_pos[i]<<", "<<lf_neg[i]<<", "<<lf[i]<<endl;
	}
	cout<<endl;

	cout<<"greatest sum has rank 1";
}