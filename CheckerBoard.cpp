//2019328 Hasan Khan

#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class CheckerBoard
{
private:

	struct word
	{
		string str;
		int rs, cs, re, ce;
	};

	struct Char
	{
		char ch;
		int r, c;
	};

	word list[100];
	string wordlist[3814];
	char grid[8][8];

	string append;
	string str;

	int lines = 0;
	int l = 0;

public:
	CheckerBoard()
	{
		int a = 2;
	}

	void Grid()
	{
		for (int r = 0; r < 8; r++)
		{
			while (str.length() != 8)
			{
				cout << "Input line " << r + 1 << " of grid without spaces (8 alphabets in each line )" << endl;
				cin >> str;
				system("cls");
			}

			for (int c = 0; c < 8; c++)
			{
				grid[r][c] = str[c];
			}
			str.clear();
		}
	}
	void RetrieveWordFile()
	{
		ifstream myfile("words.txt");

		while (!myfile.eof())
		{
			getline(myfile, wordlist[lines]);
			lines++;
		}
	}

	void SearchHorizontalRight()
	{
		for (int r = 0; r < 8; r++)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int c = a; c < 8; c++)
				{
					append = append + grid[r][c];
					for (int b = 0; b < lines; b++)
					{
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = r + 1;
							list[l].re = r + 1;
							list[l].cs = a + 1;
							list[l].ce = c + 1;
							l++;
							break;
						}
					}
				}
				append.clear();
			}
		}
		append.clear();
	}

	void SearchHorizontalLeft()
	{
		for (int r = 0; r < 8; r++)
		{
			for (int a = 7; a >= 0; a--)
			{
				for (int c = a; c >= 0; c--)
				{
					append = append + grid[r][c];
					for (int b = 0; b < lines; b++)
					{
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = r + 1;
							list[l].re = r + 1;
							list[l].cs = a + 1;
							list[l].ce = c + 1;
							l++;
							break;
						}
					}
				}
				append.clear();
			}
		}
	}
	void SearchVerticalUp()
	{
		for (int c = 0; c < 8; c++)
		{
			for (int a = 7; a >= 0; a--)
			{
				for (int r = a; r >= 0; r--)
				{
					append = append + grid[r][c];
					for (int b = 0; b < lines; b++)
					{
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = a + 1;
							list[l].re = r + 1;
							list[l].cs = c + 1;
							list[l].ce = c + 1;
							l++;
							break;
						}
					}
				}
				append.clear();
			}
		}
	}
	void SearchVerticalDown()
	{
		for (int c = 0; c < 8; c++)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int r = a; r < 8; r++)
				{
					append = append + grid[r][c];
					for (int b = 0; b < lines; b++)
					{
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = a + 1;
							list[l].re = r + 1;
							list[l].cs = c + 1;
							list[l].ce = c + 1;
							l++;
							break;
						}
					}
				}
				append.clear();
			}
		}
	}
	void SearchForwardDiagonalDown()
	{
		int start = 0;
		int end = 8;

		for (int k = 0; k < 8; k++)
		{
			for (int i = 0; i < end; )
			{
				for (int j = start; j < 8; )
				{
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						i++;
						j++;
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start++;
			end--;
		}

		start = 0;
		end = 8;

		for (int k = 0; k < 8; k++)
		{
			for (int i = start; i < 8; )
			{
				for (int j = 0; j < end; )
				{
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						i++;
						j++;
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start++;
			end--;
		}
	}
	void SearchForwardDiagonalUp()
	{
		int start = 7;
		int end = 8;

		for (int k = 0; k < 8; k++)
		{
			for (int i = 0; i < end; )
			{
				for (int j = start; j >= 0; )
				{
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						i++;
						j++;
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start--;
			end--;
		}

		start = 0;
		end = 0;

		for (int k = 0; k < 8; k++)
		{
			for (int i = start; i < 8; )
			{
				for (int j = 7; j >= end; )
				{
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						i++;
						j++;
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start++;
			end++;
		}
	}
	void SearchReverseDiagonalDown()
	{
		int start = 0;
		int end = 7;

		for (int k = 0; k < 8; k++)
		{
			for (int i = end; i > 0; )
			{
				for (int j = 7; j > start; )
				{
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						i++;
						j++;
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start++;
			end--;
		}

		start = 0;
		end = 7;

		for (int k = 0; k < 8; k++)
		{
			for (int i = 7; i > start; )
			{
				for (int j = end; j > 0; )
				{
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						i++;
						j++;
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start++;
			end--;
		}
	}
	void SearchReverseDiagonalUp()
	{
		int start = 7;
		int end = 8;

		for (int k = 0; k < 8; k++)
		{
			for (int i = end; i > 0; )
			{
				for (int j = 0; j <= start; )
				{
					i++;
					j++;
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start--;
			end--;
		}

		start = 0;
		end = 0;

		for (int k = 0; k < 8; k++)
		{
			for (int i = 8; i > start; )
			{
				for (int j = end; j <= 7; )
				{
					i++;
					j++;
					append = append + grid[i][j];
					for (int b = 0; b < lines; b++)
					{
						if (append == wordlist[b])
						{
							list[l].str = append;
							list[l].rs = start + 1;
							list[l].re = j + 1;
							list[l].cs = i + 1;
							list[l].ce = end + 1;
							l++;
							break;
						}
					}
				}
			}
			append.clear();
			start++;
			end++;
		}
	}

	void PrintGrid()
	{
		cout << "\tYour Grid" << endl;
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < 8; c++)
			{
				cout << grid[r][c];
			}
			cout << endl;
		}
	}

	void takeInputAndStore()
	{
		string input;

		cout << "\nInput Word to search from the grid: ";
		cin >> input;

		for (int i = 0; i < l; i++)
		{
			if (list[i].str == input)
			{
				cout << "Word Found" << endl;
				cout << "\nWord Start row: " << list[i].rs;
				cout << "\nWord Start column: " << list[i].cs;
				cout << "\nWord End Row: " << list[i].re;
				cout << "\nWord End column: " << list[i].ce;
				break;
			}
		}
		ofstream write("answer.txt");

		for (int i = 0; i < l; i++)
		{
			write << list[i].str << "(" << list[i].rs << "," << list[i].cs << ")" << "(" << list[i].re << "," << list[i].ce << ")" << endl;
		}
	}
};

int main()
{
	CheckerBoard Check;
	Check.Grid();
	Check.RetrieveWordFile();
	Check.SearchHorizontalRight();
	Check.SearchHorizontalLeft();
	Check.SearchVerticalUp();
	Check.SearchVerticalDown();
	/*Check.SearchForwardDiagonalDown();
	Check.SearchForwardDiagonalUp();
	Check.SearchReverseDiagonalDown();
	Check.SearchReverseDiagonalUp();*/
	Check.PrintGrid();
	Check.takeInputAndStore();
}