//C++ program to insert a node in AVL tree 
#include<bits/stdc++.h> 
#include<string>
#include<iostream>
using namespace std; 

// An AVL tree node 
class Node 
{ 
	public: 
	long int key; 
	string name;
	Node *left; 
	Node *right; 
	int height; 
}; 

// A utility function to get maximum 
// of two integers 
long int max(long int a,long int b); 

// A utility function to get the 
// height of the tree 
int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum 
// of two integers 
long int max(long int a,long int b) 
{ 
	return (a > b)? a : b; 
} 

Node * minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
   	 current = current->left;

    return current;
}

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */

Node* newNode(long int key, string name) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->name=name;
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially 
					// added at leaf 
	return(node); 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree. 
Node* insert(Node* node, long int key, string name) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key,name)); 

	if (key < node->key) 
		node->left = insert(node->left, key,name); 
	else if (key > node->key) 
		node->right = insert(node->right, key,name); 
	else // Equal keys are not allowed in BST 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 
// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, long int key)
{
    
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
   	 return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->key )
   	 root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->key )
   	 root->right = deleteNode(root->right, key);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
   	 // node with only one child or no child
   	 if( (root->left == NULL) ||
   		 (root->right == NULL) )
   	 {
   		 Node *temp = root->left ?
   					 root->left :
   					 root->right;

   		 // No child case
   		 if (temp == NULL)
   		 {
   			 temp = root;
   			 root = NULL;
   		 }
   		 else // One child case
   		 *root = *temp; // Copy the contents of
   					 // the non-empty child
   		 free(temp);
   	 }
   	 else
   	 {
   		 // node with two children: Get the inorder
   		 // successor (smallest in the right subtree)
   		 Node* temp = minValueNode(root->right);

   		 // Copy the inorder successor's
   		 // data to this node
   		 root->key = temp->key;

   		 // Delete the inorder successor
   		 root->right = deleteNode(root->right,
   								 temp->key);
   	 }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
   					 height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
   	 getBalance(root->left) >= 0)
   	 return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
   	 getBalance(root->left) < 0)
    {
   	 root->left = leftRotate(root->left);
   	 return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
   	 getBalance(root->right) <= 0)
   	 return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
   	 getBalance(root->right) > 0)
    {
   	 root->right = rightRotate(root->right);
   	 return leftRotate(root);
    }

    return root;
}

// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 
void preOrder(Node *root, int height) 
{ 
	if(root != NULL) 
	{ 
      if(height==0){
        cout<<root->key<<" "<<root->name<<endl<<" ";
      if(root->left!=NULL)
		preOrder(root->left,height+1);
      if(root->right!=NULL)
		preOrder(root->right,height+1); 
      } 
    
      else{
		cout << setw(4*height+10)<<root->key <<" "<<root->name<< endl<<" "; 
      if(root->left!=NULL)
		preOrder(root->left,height+1);
      if(root->right!=NULL)
		preOrder(root->right,height+1); 
      }
	} 
    
} 

string search(Node* root, long int data)
{
	//base case
    if (root == NULL)
        return "Element not found";
 
    else if(root->key == data){
        return root->name;
	}

    else if(root->key > data)
		return search(root->left, data);

    else
        return search(root->right, data);
}

void modify(Node* root, string name1, long int data)
{
	//base case
    if (root == NULL)
        cout<< "Element not found\n";
	
    if(root->name == name1){
        root->key=data;
	}
    /*else if(root->key > data)
		return search(root->left, data);
		
    else
        return search(root->right, data);
*/}


// Driver Code 
int main() 
{ 
	Node *root = NULL; 
	
	/* Constructing tree given in 
	the above figure */
	root = insert(root, 990271033,"name1"); 
	root = insert(root, 948160469,"name2"); 
	root = insert(root, 805067832,"name3"); 
	root = insert(root, 734956637,"name4"); 
	root = insert(root, 789274724,"name5"); 
	root = insert(root, 953533826,"Abhinav"); 
	root = insert(root, 953573030,"Anirudh"); 
	root = insert(root, 890439569,"BV"); 
	root = insert(root, 949133705,"Exculsec"); 
	root = insert(root, 948114818,"Dell"); 
	root = insert(root, 944400805,"DoST"); 
	root = insert(root, 951333138,"Gaurav"); 
	root = insert(root, 997245659,"Guhan"); 
	root = insert(root, 442257833,"Hospital"); 
	root = insert(root, 953516034,"Jobless"); 
	root = insert(root, 961989327,"Keshav"); 
	root = insert(root, 897182490,"Mainak"); 
	root = insert(root, 994031598,"Milind"); 
	
	digraph(root);

	int t; 
	char a;
	interesting: cout<<"\nDo you want to continue? ";
	a=getchar();
	while(a=='Y'||a=='y'){
	cout<<"\nEnter a number from the given choices\n\n";
	cout<<" 1. To insert: Go to the int main() and add there\n";
	cout<<" 2. List\n 3. Search\n 4. Modify\n 5. Delete\n 6. Any other number will exit from loop\n\n";
	cin>>t;

	switch(t){

		case 2:  {
					cout << "\nThe constructed AVL tree is \n\n"; 
					preOrder(root,0); 
					break;
		}
		case 3: {
					long int l;
					cout<<"\nEnter a number to be searched ";
					cin>>l;

					if(search(root,l)!="Element not found")
						cout<<"\nYes, number exists and belongs to "<<search(root,l)<<endl;
					else
						cout<<"\nNumber does not exist in directory\n";					
					break;
		}
		case 4: {
					long int l2; string s;
					cout<<"\nEnter name whose number is to be modified ";
					cin>>s;
					cout<<"\nNumber should be modified to? ";
					cin>>l2;
					modify(root,s,l2);
					cout<<"\nModified. Print tree to check\n\n";
					break;
		}
		case 5: {
					long int l1;
					cout<<"\nEnter number to be deleted ";
					cin>>l1;
					root = deleteNode(root, l1 );
					cout<<"\nAfter deletion the AVL tree is: "<<endl<<endl;
					preOrder(root,0);
					break;
		}
		default: exit(0);
				
		}
		}
	return 0; 
}
	
	/* The constructed AVL Tree would be 
			30 
			/ \ 
		          20 40 
			/ \ \ 
		        10 25 50 
	*/
	/*cout << "Preorder traversal of the "
			"constructed AVL tree is \n\n"; 
	preOrder(root,0); 
	
root = deleteNode(root, 734956637 );
cout<<"After deletion the AVL tree is: "<<endl;
preOrder(root,0); */

	
 
