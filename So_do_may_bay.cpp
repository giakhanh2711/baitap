#include <iostream>
#include <iomanip>
#define MAX  100
using namespace std;

void inmenu(char a[][MAX])
{
	for (char i = 'A'; i <= 'F'; i++)
		cout << setw(9) << i;
	cout << endl;
	for (int i = 0; i < 13; i++)
	{
		cout << "Row " << setw(4) << left << i+1;
		for (int j = 0; j < 6; j++)
			cout << setw(9) << left << a[i][j];
		cout << endl;
	}
}

int chonhang()
{
	int hang = 0;
	while (hang != 1 && hang != 2 && hang != 3)
	{
		cout << "Nhap 1 neu chon hang nhat" << endl
			<< "     2 neu chon hang thuong gia" << endl
			<< "     3 neu chon hang pho thong" << endl;
		cout << "Moi chon 1 so: ";
		cin >> hang;
	}
	return hang;
}


// Viet Ham check row



void chon_cho_ngoi(char a[][MAX])
{
	char check;
	int i, j;
	int row;
	char col;
	int hang = chonhang();
	if (hang == 1)
	{
		i = 1;
		j = 2;
	}
	else if (hang == 2)
	{
		i = 3;
		j = 7;
	}
	else
	{
		i = 8;
		j = 13;
	}

	while (1)
	{
		row = i - 1;
		col = 'A' - 1;
		while (row < i || row > j) // Dùng kỹ thuật gán để vào vòng lặp và có điều kiện trùng với vòng while. Sẽ ngắn hơn dùng vòng while(1).
			/*while này có if vì ta muốn ghi dòng không hợp lệ cho user*/
		{
			{
				cout << "Nhap 1 hang tu " << i << " den " << j << ": ";
				cin >> row;
				if (row < i || row > j)
				{
					cout << "Invalid row" << endl
						<< "Moi nhap lai" << endl;
				}
			}
			while (!((col >= 'A' && col <= 'F') || (col >= 'a' && col <= 'f')))
			{
				cout << "Nhap cot: ";
				cin >> col;
				if (!((col >= 'A' && col <= 'F') || (col >= 'a' && col <= 'f')))
				{
					cout << "Invalid column" << endl
						<< "Moi nhap lai" << endl;
				}

			}

			cout << "Your choice is: Row " << row << " and Column " << col << endl;
			
			check = 'a';
			while (check != 'y' && check != 'Y' && check != 'n' && check != 'N') // Kỹ thuật để vào vòng while cho đến khi lấy được 1 giá trị
				/*while này không có if vì nếu ko nhập đúng thì chỉ hiện lại cho user nhập lại*/
			{
				cout << "Are you sure ? (Y/N): ";
				cin >> check;
			}

			if (check == 'Y' || check == 'y')
			{
				if (a[row-1][col-65] == '*')
					break;
				else
					cout << "That seat is occupied! Please choose another one" << endl;
			}
		}



	}
}

int main()
{
	char a[MAX][MAX];
	a[0][0] = a[0][1] = a[0][3] = '*'; a[0][2] = a[0][4] = a[0][5] = 'X';
	a[1][0] = a[1][2] = a[1][4] = '*'; a[1][1] = a[1][3] = a[1][5] = 'X';
	a[2][0] = a[2][1] = a[2][4] = '*'; a[2][2] = a[2][3] = a[2][5] = 'X';
	a[3][1] = a[3][3] = '*'; a[3][0] = a[3][2] = a[3][4] = a[3][5] = 'X';
	a[4][0] = a[4][2] = a[4][4] = a[4][5] = '*'; a[4][1] = a[4][3] = 'X';
	a[5][0] = a[5][2] = a[5][3] = a[5][4] = '*'; a[5][1] = a[5][5] = 'X';
	a[6][1] = a[6][2] = a[6][3] = '*'; a[6][0] = a[6][4] = a[6][5] = 'X';
	a[7][0] = a[7][2] = a[7][5] = '*'; a[7][1] = a[7][3] = a[7][4] = 'X';
	a[8][1] = a[8][4] = '*'; a[8][0] = a[8][2] = a[8][3] = a[8][5] = 'X';
	a[9][0] = a[9][2] = '*'; a[9][1] = a[9][3] = a[9][4] = a[9][5] = 'X';
	a[10][0] = a[10][1] = a[10][3] = a[10][5] = '*'; a[10][2] = a[10][4] = 'X';
	a[11][0] = a[11][1] = a[11][4] = '*'; a[11][2] = a[11][3] = a[11][5] = 'X';
	a[12][0] = a[12][1] = a[12][2] = a[12][3] = a[12][5] = '*'; a[12][4] = 'X';

	inmenu(a);

	chon_cho_ngoi(a);

	return 0;
}