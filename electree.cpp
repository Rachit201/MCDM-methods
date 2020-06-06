#include <bits/stdc++.h>
using namespace std;

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
	cout << "Step-1 : NORMALIZATION " << endl << endl;

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

	cout << "STEP-2 :Now we multiply the weights of the each criteria" << endl
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
	space(1);
	cout << "STEP-3 : Concordance set. \n";
	cout << "Here we calculate the Concordance set.";
	space(0);

	float concord[types][types] = {0};
	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			if (i != j)
			{
				float val = 0;
				for(int k=0;k<attribute;k++)
				{
					if(cost_matrix[i][k] >= cost_matrix[j][k])
						val = val + weights[k];
				}
				concord[i][j] = val;
			}
		}
	}
	float sum = 0;
	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			cout << concord[i][j] << " ";
			sum = sum + concord[i][j];
		}
		cout << endl;
	}
	space(0);
	cout << "Now we convert the Concordance set into binary values. \n";
	cout << "For converting to binary values we neet the C_BAR value.\n";
	cout << "C_BAR value is = " << sum/6;
	float C_BAR = sum/6;

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			if(concord[i][j] >= C_BAR)
				concord[i][j] = 1;
			else
				concord[i][j] = 0;

			
		}
	}
	space(0);
	cout << "The binary Concordance set is - \n \n";
	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			cout << concord[i][j] << " ";
		}
		cout << endl;
	}

	space(1);
	cout << "STEP -4 DISCORDANCE SET \n";
	space(0);

	float discord[types][types] = {0};
	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			if(i != j)
			{
				float deno = 0;
				float numo = 99;
				for(int k=0;k<attribute;k++)
				{
					deno = max(deno,abs(cost_matrix[i][k]-cost_matrix[j][k]));
					numo = min(numo,cost_matrix[i][k]-cost_matrix[j][k]);
				}
				discord[i][j] = abs(numo/deno);
			}
		}
	}
	float sumd = 0;
	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			cout << discord[i][j] << " ";
			sumd = sumd + discord[i][j];
		}
		cout << endl;
	}
	space(0);

	cout << "Now we convert the discordance set into binary values. \n";
	cout << "For converting to binary values we neet the D_BAR value.\n";
	cout << "D_BAR value is = " << sumd/6;

	float D_BAR = sumd/6;
	space(0);

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			if(discord[i][j] >= D_BAR)
				discord[i][j] = 1;
			else
				discord[i][j] = 0;
		}
	}
	cout << "The binary discordance set -" << endl;

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			cout << discord[i][j] << " ";
		}
		cout << endl;
	}

	space(1);

	cout << "STEP-5 Aggregation of discordance set and the Concordance set.";
	space(0);

	for(int i=0;i<types;i++)
	{
		for(int j=0;j<types;j++)
		{
			if(discord[i][j] == 1 && concord[i][j] == 1)
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}

}