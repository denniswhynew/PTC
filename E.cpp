#include<iostream>
using namespace std;
char fpoint[2][2][20000];
int main()
{
	while (1)
	{
		char re, c;
		int flag = 0;
		int i[2][2] = { 0 };
		cin >> re >> re;
		if (cin.eof()) return 0;
		while (1)
		{
			cin.get(c);
			if (flag == 0)
			{
				if (c == '(')
				{
					flag = 1;
				}
				else if (c == ' ')
				{
					fpoint[0][1][0] = 0;
					//i[0][1]++;
					break;
				}
				else
				{
					fpoint[0][0][i[0][0]] = c-'0';
					i[0][0]++;
				}
			}
			else
			{
				if (c == ')')
				{
					cin.get();
					flag = 0;
					break;
				}
				else
				{
					fpoint[0][1][i[0][1]] = c - '0';
					i[0][1]++;
				}
			}
		}
		cin >> re >> re;
		while (1)
		{
			cin.get(c);
			if (flag == 0)
			{
				if (c == '(')
				{
					flag = 1;
				}
				else if (c == '\n')
				{
					fpoint[1][1][0] = 0;
					//i[1][1]++;
					break;
				}
				else
				{
					fpoint[1][0][i[1][0]] = c - '0';
					i[1][0]++;
				}
			}
			else
			{
				if (c == ')')
				{
					cin.get();
					flag = 0;
					break;
				}
				else
				{
					fpoint[1][1][i[1][1]] = c - '0';
					i[1][1]++;
				}
			}
		}


		if (i[0][0] < i[1][0])
		{
			int j = 0;
			for (;  i[1][0] > i[0][0]; j++)
			{
				if (i[0][1] == 0)
				{
					fpoint[0][0][i[0][0]] = 0;
				}
				else
				{
					fpoint[0][0][i[0][0]] = fpoint[0][1][j%i[0][1]];
				}
				i[0][0]++;
			}
			if (i[0][1])
			{
				j %= i[0][1];
			}

			for (int k = 0; k < j; k++)
			{
				fpoint[0][1][k+i[0][1]]= fpoint[0][1][k];
			}
			for (int k = j; k < j + i[0][1]; k++)
			{
				fpoint[0][1][k - j] = fpoint[0][1][k];
			}
		}
		else if(i[0][0] > i[1][0])
		{
			int j = 0;
			for (; i[0][0] > i[1][0]; j++)
			{
				if (i[1][1] == 0)
				{
					fpoint[1][0][i[1][0]] = 0;
				}
				else
				{
					fpoint[1][0][i[1][0]] = fpoint[1][1][j%i[1][1]];
				}
				i[1][0]++;
			}
			if (i[1][1])
			{
				j %= i[1][1];
			}

			for (int k = 0; k < j; k++)
			{
				fpoint[1][1][k + i[1][1]] = fpoint[1][1][k];
			}
			for (int k = j; k < j + i[1][1]; k++)
			{
				fpoint[1][1][k - j] = fpoint[1][1][k];
			}
		}
		for (int j = 0; j < i[1][1] - 1; j++)
		{
			for (int k = 0; k < i[0][1]; k++)
			{
				fpoint[0][1][k + (j + 1)*i[0][1]] = fpoint[0][1][k];
			}
		}
		for (int j = 0; j < i[0][1] - 1; j++)
		{
			for (int k = 0; k < i[1][1]; k++)
			{
				fpoint[1][1][k + (j + 1)*i[1][1]] = fpoint[1][1][k];
			}
		}

		int carry = 0;
		for (int j = i[0][1] * i[1][1] - 1; j >= 0; j--)
		{
			fpoint[0][1][j] += fpoint[1][1][j]+carry;
			if (carry = fpoint[0][1][j] / 10)
			{
				fpoint[0][1][j] %= 10;
			}
		}
		if (i[0][1] == 0 && i[1][1] != 0)
		{
			for (int j = 0; j < i[1][1]; j++)
			{
				fpoint[0][1][j] = fpoint[1][1][j];
			}
			i[0][1] = i[1][1];
			i[1][1] = 0;
		}



		int carry2 = carry;
		for(int j = i[0][1] * i[1][1] - 1;carry; j--)
		{
			fpoint[0][1][j] += carry;
			if (carry = fpoint[0][1][j] / 10)
			{
				fpoint[0][1][j] %= 10;
			}
		}


		for (int j = i[0][0] - 1; j >= 0; j--)
		{
			fpoint[0][0][j] += fpoint[1][0][j] + carry2;
			if (carry2 = fpoint[0][0][j] / 10)
			{
				fpoint[0][0][j] %= 10;
			}
		}
		/*
		for (int j = i[0][0] - 1; carry2&&j >= 0; j--)
		{
			fpoint[0][0][j] += carry2;
			if (carry2 = fpoint[0][0][j] / 10)
			{
				fpoint[0][0][j] %= 10;
			}
		}*/


		//shorter
		for (int j = 1; j <= i[0][1] * i[1][1]; j++)
		{
			if (i[0][1] * i[1][1] % j) continue;
			int isshort = 1;
			for (int k = 1; k < i[0][1] * i[1][1] / j; k++)
			{

				for (int l = 0; l < j; l++)
				{
					if (fpoint[0][1][l] != fpoint[0][1][l + j*k])
					{
						isshort = 0;
						break;
					}
				}
				if (isshort == 0) break;
			}
			if (isshort)
			{
				i[0][1] = j;
				break;
			}
		}

		while (i[0][0]&&fpoint[0][0][i[0][0] - 1] == fpoint[0][1][i[0][1] - 1])
		{
			for (int j = i[0][1] - 1; j > 0; j--)
			{
				fpoint[0][1][j] = fpoint[0][1][j-1];
			}
			fpoint[0][1][0] = fpoint[0][0][i[0][0] - 1];
			i[0][0]--;
		}



		if (i[0][1] == 1 && fpoint[0][1][0] == 9)
		{
			carry = 1;
			i[0][1] = 0;
			if (i[0][0] > 0)
			{
				for (int j = i[0][0] - 1; carry&&j >= 0; j--)
				{
					fpoint[0][0][j] += carry;
					if (carry = fpoint[0][0][j] / 10)
					{
						fpoint[0][0][j] %= 10;
					}
				}
			}
			else
			{
				carry2++;
			}
		}
		cout << carry2;
		if (i[0][0] || i[0][1])
		{
			cout << ".";
		}
		for (int j = 0; j < i[0][0]; j++)
		{
			cout << int(fpoint[0][0][j]);
		}
		/*
		if (i[0][1] == 0 && fpoint[0][1][0] == 0)
		{
			cout << endl;
			continue;
		}*/
		if (i[0][1])
		{
			cout << "(";
			for (int j = 0; j < i[0][1]; j++)
			{
				cout << int(fpoint[0][1][j]);
			}
			cout << ")";
		}
		cout << endl;
	}
}
