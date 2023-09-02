#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left, *right;
};
struct node *newNode(int item) {
  struct node *temp = new node();
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}
struct node *insert(struct node *node, int data) {
  if (node == NULL) 
  return newNode(data);
  if (data < node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);

  return node;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
  }
}
int minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current->data;
}
int maxValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->right != NULL)
    current = current->right;

  return current->data;
}
void Search(node *root, int data)
{
	int depth = 0;
	node *temp = new node;
	temp = root;
	while(temp != NULL)
	{
		depth++;
		if(temp->data == data)
		{
			cout<<"\nData found at depth: "<<depth;
			return;
		}
		else if(temp->data > data)
			temp = temp->left;
		else
			temp = temp->right;
	}
 
	cout<<"\n Data not found";
	return;
}
struct node  *copyTree(struct node *root){ 
   if (root == NULL )
   return root;

   node *temp = new node() ; 
   temp->data = root-> data;    
   temp->left = copyTree(root -> left);    
   temp->right = copyTree(root -> right);  
   return temp; 
};
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);
  cout<<endl;
  cout<<"Enter the element to be founud in the tree"<<endl;
  int n;
  cin>>n;
  Search(root,n);
  cout<<endl;
  int min;
  min= minValueNode(root);
  cout<<"The minimum value in the tree is-"<<min<<endl;
  cout<<endl;
  int max;
  max= maxValueNode(root);
  cout<<"The maximum value in the tree is-"<<max<<endl;
  node *copy = copyTree(root);
  cout << "\n\n Inorder traversal of copied binary tree is: \n";
  inorder(copy);
  cout<<endl;
}