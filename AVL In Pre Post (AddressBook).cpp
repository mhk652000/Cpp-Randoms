#include<iostream>
#include<cmath>
#include<conio.h>
#include<string>

using namespace std;




class node
{
private:

	int height;
	int data;
	string name, email, address;
	node* right, * left;

public:

	node* root;


	void RightRotate(node*& root)
	{
		node* x = root->left;
		node* y = x->right;
		x->right = root;
		root->left = y;
		root = x;
		y = root->right;


		y->height = 1 + max(heightt(y->left), heightt(y->right));
		root->height = 1 + max(heightt(root->left), heightt(root->right));


	}
	int max(int a, int b)
	{
		if (a > b)
		{
			return a;
		}

		else
		{
			return b;
		}
	}

	void LeftRotate(node*& root)
	{
		node* x = root->right;
		node* y = x->left;

		x->left = root;
		root->right = y;
		root = x;
		y = root->left;

		y->height = 1 + max(heightt(y->left), heightt(y->right));
		root->height = 1 + max(heightt(root->left), heightt(root->right));
	}





	int heightt(node* root)
	{
		if (root == NULL)
		{
			return -1;
		}
		else
		{
			return root->height;
		}
	}


	node()
	{
		root = NULL;
	}


	void add(node*& root, int a, string n,string ad, string m)
	{
		node* temp = new node;

		temp->data = a;
		temp->name = n;
		temp->address = ad;
		temp->email = m;


		temp->left = NULL;
		temp->right = NULL;
		temp->height = 0;
		if (root == NULL)
		{
			root = temp;
			return;
		}
		else if (a < root->data)
		{
			add(root->left, a,n,ad,m);
			root->height = 1 + max(heightt(root->left), heightt(root->right));


			if (heightt(root->left) - heightt(root->right) > 1)
			{

				if (a < root->left->data) //LEFT LEFT
				{
					RightRotate(root);
				}
				else if (a > root->left->data) //LEFT RIGHT
				{
					LeftRotate(root->left);
					RightRotate(root);

				}
			}

		}
		else if (a > root->data)
		{
			add(root->right, a,n,ad,m);
			root->height = 1 + max(heightt(root->left), heightt(root->right));

			if (heightt(root->left) - heightt(root->right) < -1)
			{
				if (a < root->right->data) //RIGHT LEFT
				{
					RightRotate(root->right);
					LeftRotate(root);


				}
				else if (a > root->right->data) //RIGHT RIGHT
				{
					LeftRotate(root);
				}

			}

		}
	}




	void displayinorder(node* x)
	{
		if (x != NULL)
		{
			if (x->left != NULL)
			{
				displayinorder(x->left);
				return;
			}
			cout << x->name << " ";

			if (x->right != NULL)
			{
				displayinorder(x->right);
				return;
			}
			return;
		}
	}

	void displaypreorder(node* x)
	{
		if (x != NULL)
		{
			cout << x->name << " ";
			displaypreorder(x->left);
			displaypreorder(x->right);
			return;
		}
	}

	void displaypostorder(node* x)
	{
		if (x != NULL)
		{
			displaypostorder(x->left);
			displaypostorder(x->right);
			cout << x->name << " ";
			return;
		}
	}
	void displayAVL(node* ptr, int level)
	{
		int i;
		if (ptr != NULL)
		{
			displayAVL(ptr->right, level + 1);
			printf("\n");
			if (ptr == root)
				cout << "Root -> ";
			for (i = 0; i < level && ptr != root; i++)
				cout << "        ";
			cout << ptr->name;
			displayAVL(ptr->left, level + 1);
		}
	}

	bool search(int key)
	{
		node* nodeptr = root;

		

		while (nodeptr)
		{
			if (nodeptr->data == key)
			{
				return true;
			}

			else if (key< nodeptr->data)
			{
				nodeptr = nodeptr->left;
			}

			else
			{
				nodeptr = nodeptr->right;
			}
		}
		return false;
	}


	void deletee(int key)
	{
		deletenode(key, root);
	}

	void deletenode(int num, node*& nodee)
	{
		if (num < nodee->data)
		{
			deletenode(num, nodee->left);
		}

		else if (num > nodee->data)
		{
			deletenode(num, nodee->right);
		}

		else
		{
			makedeletion(nodee);
		}
	}

	void makedeletion(node*& nodee)
	{
		node* tempptr;

		if (nodee == NULL)
		{
			cout << "\n Node Empty!\n";
		}
		else if (nodee->right == NULL && nodee->left == NULL)
		{
			tempptr = nodee;
			delete tempptr;
		}
		else if (nodee->right == NULL && nodee->left != NULL)
		{
			tempptr = nodee;
			nodee = nodee->left;

			delete tempptr;
		}

		else if (nodee->left == NULL && nodee->right != NULL)
		{
			tempptr = nodee;
			nodee = nodee->right;

			delete tempptr;
		}

		else
		{
			tempptr = nodee->right;

			while (tempptr->left)
			{
				tempptr = tempptr->left;
			}

			tempptr->left = nodee->left;

			tempptr = nodee;

			nodee = nodee->right;

			delete tempptr;
		}

	}


};

int main()
{
	int choice=0;
	int num;
	string nam, mail, addr;
	node caller;
	
	do
	{
		cout << "1) Add New Contact \n2) Delete a contact \n3) Search for a contact \n4) Display \n5) Exit";
		cout << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("CLS");
			cout << "Enter the Name: ";
			cin >> nam;
			cout << "\nEnter the Phone-Num: ";
			cin >> num;
			cout << "\nEnter the Address: ";
			cin >> addr;
			cout << "\nEnter the E-Mail: ";
			cin >> mail;
			caller.add(caller.root,num, nam, addr, mail);
			cout <<  "\nSuccessfull!";

			cout << endl << endl;

			break;
		}

		case 2:
		{
			system("CLS");
			cout << "Enter the Number to delete: ";
			cin >> num;
			caller.deletee(num);

			cout << "\nSuccessfull!";

			cout << endl << endl;
			break;
		}

		case 3:
		{
			system("CLS");
			cout << "\nEnter the Phone-Num of the Person: ";
			cin >> num;

			if (caller.search(num) == true)
			{
				cout << "\nPerson is present!\n";
			}

			if (caller.search(num) == false)
			{
				cout << "\nPerson is not present!\n";
			}
			cout << endl;
			break;
		}

		case 4:
		{
			system("CLS");

			cout << "1) InOrder" << endl << "2) PreOrder" << endl << "3) PostOrder" << endl << "4) Display AVL Tree (Names)<<endl";
			cin >> choice;

			if (choice == 1)
			{
				system("CLS");
				caller.displayinorder(caller.root);
				cout << endl;
			}

			else if (choice == 2)
			{
				system("CLS");
				caller.displaypreorder(caller.root);
				cout << endl;
			}

			else if (choice == 3)
			{
				system("CLS");
				caller.displaypostorder(caller.root);
				cout << endl;
			}

			else
			{
				system("CLS");
				caller.displayAVL(caller.root,1);
				cout << endl;
			}
			cout << endl;
			break;
		}

		case 5:
		{
			system("CLS");
			exit(0);
			break;
		}
		}
	} while (choice != 5);





}
