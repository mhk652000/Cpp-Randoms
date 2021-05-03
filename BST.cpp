//  Muhammad Hasan Khan (2019328) Task1 & Task2


#include <iostream> 
using namespace std;

class bst
{
    bst* head;
    bst* left;
    bst* right;
    int data;

public:

    bst()                                   //constructor
    {
        head = NULL;
    }

    void addroot(int val)
    {
        bst* newptr = new bst;                               //Creates a new leaf
        bst* temp=head;

        newptr->data = val;
        newptr->left = NULL;
        newptr->right = NULL;

        if (head == NULL)        //if the tree is empty
        {
            head = newptr;
        }

        else                     //if not empty
        {
            while (temp != NULL)
            {
                if (val < temp->data)                        //if value less than existing value
                {
                    if (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = newptr;
                        break;
                    }
                }

                else if (val > temp->data)                  //if value greater than existing value
                {
                    if (temp->right != NULL)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = newptr;
                        break;
                    }
                }
                else                                        // Value equal to existing
                {
                    cout << "\nDuplicate Value Found!\n";
                    break;
                }
            }
        }
    }




    void deletee(int key)
    {
        deletenode(key, head);
    }

    void deletenode(int num, bst*& node)
    {
        if (num < node->data)
        {
            deletenode(num, node->left);
        }

        else if (num > node->data)
        {
            deletenode(num, node->right);
        }

        else
        {
            makedeletion(node);
        }
    }

    void makedeletion(bst*& node)
    {
        bst* tempptr;

        if (node == NULL)
        {
            cout << "\n Node Empty!\n";
        }
        else if (node->right == NULL &&node->left==NULL)
        {
            tempptr = node;
            delete tempptr;
        }
        else if (node->right == NULL && node->left != NULL)
        {
            tempptr = node;
            node = node->left;

            delete tempptr;
        }

        else if (node->left == NULL && node->right != NULL)
        {
            tempptr = node;
            node = node->right;

            delete tempptr;
        }

        else
        {
            tempptr = node->right;

            while (tempptr->left)
            {
                tempptr = tempptr->left;
            }

            tempptr->left = node->left;

            tempptr = node;

            node = node->right;

            delete tempptr;
        }

    }




    void display(int check)
    {
        switch (check)
        {
        case 1:
        {
            displayinorder(head);
            break;
        }
        case 2:
        {
            displaypreorder(head);
            break;
        }

        case 3:
        {
            displaypostorder(head);
            break;
        }

        }
    }




    void displayinorder(bst *root)
    {
        if (root!=NULL)
        {
            if (root->left != NULL)
            {
                displayinorder(root->left);
                return;
            }
            cout <<root->data << " ";

            if (root->right != NULL)
            {
                displayinorder(root->right);
                return;
            }
            return;
        }
    }

    void displaypreorder(bst* root)
    {
        if (root!=NULL)
        {
            cout << root->data << " ";
            displaypreorder(root->left);
            displaypreorder(root->right);
            return;
        }
    }

    void displaypostorder(bst* root)
    {
        if (root!=NULL)
        {
            displaypostorder(root->left);
            displaypostorder(root->right);
            cout << root->data << " ";
            return;
        }
    }




    bool search(int num)
    {
        bst* nodeptr = head;
        
        while (nodeptr)
        {
            if (nodeptr->data == num)
            {
                return true;
            }

            else if (num < nodeptr->data)
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

};

int main()
{
    int choice,subchoice;
    int valu;
    bst accesser;

    do
    {
        cout << "1) Add Value" << endl << "2) Display" << endl << "3) Delete a node" << endl << "4) Search" << endl << "5) Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("CLS");
            cout << "Enter the value: ";
            cin >> valu;
            cout << endl;
            accesser.addroot(valu);
            break;
        }

        case 2:
        {
            system("CLS");
            cout << "1) InOrder" << endl << "2) PreOrder" << endl << "3) PostOrder" << endl;
            cin >> subchoice;

            if (subchoice == 1)
            {
                cout << endl<<"InOrder: ";
                accesser.display(1);
                cout << endl << endl;
            }

            else if (subchoice == 2)
            {
                cout << endl << "PreOrder: ";
                accesser.display(2);
                cout << endl << endl;
            }

            else if (subchoice == 3)
            {
                cout << endl << "PostOrder: ";
                accesser.display(3);
                cout << endl<<endl;
            }
            break;
        }

        case 3:
        {
            system("CLS");
            cout << "Enter the value to delete: ";
            cin >> valu;
            cout << endl;
            accesser.deletee(valu);
            break;
        }

        case 4:
        {
            system("CLS");
            cout << "Enter the value to search: ";
            cin >> valu;
            cout << endl;
            
            if (accesser.search(valu))
            {
                cout << "\nValue Found!\n";
            }

            else
            {
                cout << "\nValue not found!\n";
            }
            break;
        }
        }

    } while (choice != 5);
}