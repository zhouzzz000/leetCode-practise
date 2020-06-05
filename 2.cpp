#include<iostream>
using namespace std;
const int MAX_COUNT=12500;
typedef struct
{
	int row,col;
	int value;
}Triple;

typedef struct
{
	Triple data[MAX_COUNT];
	int rows,cols,count;
}Matrix;

int findV(Matrix m, int row, int col){
	for(int i = 0; i<m.count; i++)
	{
		if(m.data[i].row > row){
			continue;
		}
		if(m.data[i].col > col){
			continue;
		}
		if(m.data[i].row == row && m.data[i].col == col)
		{
			return m.data[i].value;
		}
	}
	return 0;
}

int main()
{
	int row, col;
	Matrix m,t;
	int cur, count=0;
	cin >> row >> col;
	m.rows = row;
	m.cols = col;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin >> cur;
			if(cur != 0)
			{
				m.data[count].row = i;
				m.data[count].col = j;
				m.data[count].value = cur;
				count++;
			}
		}
	}
	m.count = count;
	t.count = count;
	t.rows = col;
	t.cols = row;
	for(int i=0; i<count; i++)
	{
		t.data[i].value = m.data[i].value;
		t.data[i].row = m.data[i].col;
		t.data[i].col = m.data[i].row;
	}
	for(int i=0; i<t.rows; i++){
		for(int j=0; j<t.cols; j++){
			cout << findV(t,i,j) << " ";
		}
		cout << endl;
	}
	return 0;
}