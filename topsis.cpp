#include <bits/stdc++.h>

using namespace std;

struct value{
	float best;
	float worst;
}typedef value;

void space(int n)
{
	if (n == 1)
		cout << endl << endl << endl;
	if (n ==0)
		cout << endl << endl;

}
int main()
{

	int attribute;
	int types;
	cout << "Enter dimension of Decision matrix -" ;
	cin >> types >> attribute;
	float cost_matrix[types][attribute];

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<attribute;j++)
			cin >> cost_matrix[i][j];
	}
	cout << endl;
	cout << endl;
	cout << "Step 1 : VECTOR NORMALIZATION " << endl << endl;

	float root_sum[attribute] = {0};
	for(int j=0;j<attribute;j++)
	{	for(int i=0;i<types;i++)
		{
			root_sum[j] = root_sum[j] + cost_matrix[i][j]*cost_matrix[i][j];
		}
	root_sum[j] = sqrt(root_sum[j]);
	}
	
	cout << "First we calculate the square of all the elements in a column " << endl 
	<< "and square root the answer to get" << endl;
	cout << endl;
	for(int i=0;i<attribute;i++)
		cout << root_sum[i] << " ";

	space(0);

	cout << "Now we normalize the matrix by dividing each column element" << endl
	<< "by its respective square sum root " ;
	space(0);
	for(int j=0;j<attribute;j++)
	{	
		for(int i=0;i<types;i++)
		{
			cost_matrix[i][j] = cost_matrix[i][j]/root_sum[j]; 
		}
	}

	space(0);
	cout << "The normalized decision matrix is -" << endl;
	space(0);

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<attribute;j++)
			cout << cost_matrix[i][j] << " ";
		cout << endl;
	}
	space(0);
	cout << "The value in each cell is the normalized performance value.";
	space(1);

	cout << "Now we multiply the weights of the each criteria" << endl
	<<  "with the each cell";
	space(0);
	float weights[attribute];
	cout << "Enter the weights of each attribute -";

	for(int i=0;i<attribute;i++)
		cin >> weights[i];

	for(int j=0;j<attribute;j++)
	{	
		for(int i=0;i<types;i++)
		{
			cost_matrix[i][j] = cost_matrix[i][j]* weights[j]; 
		}
	}
	cout << endl << "The weighted Normalized Decision matrix is - ";
	space(1);

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<attribute;j++)
			cout << cost_matrix[i][j] << " ";
		cout << endl;
	}

	space(0);

	cout << "STEP 2 \n" << endl;
	int beneficial[attribute];
	cout << "Enter 1 if the attribute is beneficial and 0 if elsewise -"
	<< endl;

	for(int i=0;i<attribute;i++)
		cin >> beneficial[i];
	cout << endl;

	float max_val = -2 ,min_val = 2;

	value v[attribute];

	for(int j=0;j<attribute;j++)
	{
		for(int i=0;i<types;i++)
		{
			max_val = max(max_val,cost_matrix[i][j]);
			min_val = min(min_val,cost_matrix[i][j]);
		}
		if(beneficial[j] == 1)
		{
			v[j].best = max_val;
			v[j].worst = min_val;
		}
		if(beneficial[j] == 0)
		{
			v[j].best = min_val;
			v[j].worst = max_val;
		}
		max_val = -2;
		min_val = 2;
	}

	for(int i=0;i<attribute;i++)
	{
		cout << "Vj+ = " << v[i].best << endl
		<< "Vj- = " << v[i].worst << endl << endl;
	}
	space(1);
	cout << "Here vj+ is the ideal best and \n vj- is the ideal worst." << endl;
	space(0);
	cout << "Using Vj+ and Vj- we calculate the Euclidean distance.";
	space(0);

	value Euclidean[types];
	float smax;
	for(int j=0;j<types;j++)
	{	smax = 0;
		for(int i=0;i<attribute;i++)
		{
			smax = smax + (cost_matrix[j][i]-v[i].best)*(cost_matrix[j][i]-v[i].best);
		}
		Euclidean[j].best = sqrt(smax);
	}

	float smin;
	for(int j=0;j<types;j++)
	{	smin = 0;
		for(int i=0;i<attribute;i++)
		{
			smin = smin + (cost_matrix[j][i]-v[i].worst)*(cost_matrix[j][i]-v[i].worst);
		}
		Euclidean[j].worst = sqrt(smin);
	}

	for(int i=0;i<types;i++)
		cout << "Si+ = " << Euclidean[i].best <<  " Si- = " << Euclidean[i].worst << endl;

	space(0);
	cout << "Using the Euclidean distance we calculat ethe performance score.\n";

	float performance_score[types];
	space(0);
	for(int i=0;i<types;i++)
	{
		performance_score[i] = Euclidean[i].worst/(Euclidean[i].worst + Euclidean[i].best);
	}

	for(int i=0;i<types;i++)
	{
		cout << "for type " << i+1 << " we have " << performance_score[i] << endl; 
	}

}