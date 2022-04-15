#include <iostream>
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	BST()
    {
        data=0;
        left =NULL;
        right=NULL;
    }
	BST(int value)
    {
	data = value;
	left = right = NULL;
    }
	BST* Insert(BST*, int);
	void Inorder(BST*);
};

BST* BST ::Insert(BST* root, int value)
{
	if (!root)
	{
		return new BST(value);
	}
	// Insert data.
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else
	{
		root->left = Insert(root->left, value);
	}
	return root;
}

void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

int main()
{    
    int value;
    char c;
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	do{
     
     cout<<"enter value"<<endl;
     cin>>value;
     b.Insert(root, value);

     cout<<"\n want to enter value again\n\t y=yes n=no\n";
     cout<<"\t";cin>>c;

    }while(c=='y');

	b.Inorder(root);
	return 0;
}


