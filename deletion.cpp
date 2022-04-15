#include <iostream>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key<<" ";
		inorder(root->right);
	}
}
struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}
struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);


	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if (root->left==NULL and root->right==NULL)
			return NULL;
	
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
	struct node* root = NULL;
	root = insert(root, 55);
	root = insert(root, 35);
	root = insert(root, 64);
	root = insert(root, 89);
	root = insert(root, 32);
	root = insert(root, 77);
	root = insert(root, 88);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 64\n";
	root = deleteNode(root, 64);
	cout << "Inorder traversal\e\n";
	inorder(root);

	cout << "\nDelete 32\n";
	root = deleteNode(root, 32);
	cout << "Inorder traverse\n";
	inorder(root);

	cout << "\nDelete 55\n";
	root = deleteNode(root, 55);
	cout << "Inorder traverse\n";
	inorder(root);
	return 0;
}

