// C++ program to insert a node in AVL tree 
#include<bits/stdc++.h> 
#include<math.h>
using namespace std; 


// An AVL tree node 
class Node 
{ 
        public: 
        int key; 
        Node *left; 
        Node *right; 
        int height; 
        //void printGraphviz();
}; 


// A utility function to get maximum 
// of two integers 
int max(int a, int b); 


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
int max(int a, int b) 
{ 
        return (a > b)? a : b; 
} 


/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
Node* newNode(int key) 
{ 
        Node* node = new Node(); 
        node->key = key; 
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
Node* insert(Node* node, int key) 
{ 
        /* 1. Perform the normal BST insertion */
        if (node == NULL) 
                return(newNode(key)); 


        if (key < node->key) 
                node->left = insert(node->left, key); 
        else if (key > node->key) 
                node->right = insert(node->right, key); 
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


// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 
void preOrder(Node *root, int height) 
{ 
if(root != NULL) 
    { 
      if(height==0){
        cout<<root->key<<endl;
      if(root->left!=NULL)
        preOrder(root->left,height+1);
      if(root->right!=NULL)
        preOrder(root->right,height+1); 
      } 
    
      else{
        cout << setw(4*height+4)<<root->key << endl<<" "; 
      if(root->left!=NULL)
        preOrder(root->left,height+1);
      if(root->right!=NULL)
        preOrder(root->right,height+1); 
      }
	} 
    
} 

void printGraphviz(Node *rr) {
    
    if (rr!=NULL) {
        if (rr->left) {
            cout << '"' << rr->key << '"';
            //std::cout << '"' << rr->data << rr->id << '"';
            cout << " -> ";
            cout << '"' << rr->left->key << '"';
            //std::cout << '"' << rr->left->data << rr->left->id << '"';
            cout << endl;
            printGraphviz(rr->left);
        }
        if (rr->right) {
            cout << '"' << rr->key << '"';
            //std::cout << '"' << rr->data << rr->id << '"';
            cout << " -> ";
            cout << '"' << rr->right->key << '"';
            //std::cout << '"' << rr->right->data << rr->right->id << '"';
            cout << endl;
            printGraphviz(rr->right);
        }
    }
    
}

void printGraphviz(Node* root,int n) {
    std::cout << "digraph G {\n";
    printGraphviz(root);
    std::cout << "}\n";
}

// Driver Code 
int main() 
{ 
        Node *root = NULL;
        while(1){
        int a; 
        cout<<"\n0. Insert custom numbers or \n1. Test with random inputs? or \n2. Exit?\n";
        cin>>a;

        switch(a){

        case 0: {
        root=insert(root,3);
        root=insert(root,2);
        root=insert(root,4);
        root=insert(root,5);
        root=insert(root,6);
        root=insert(root,9);
        root=insert(root,8);
        cout<<endl<<"Height of tree is: "<<height(root)<<endl<<endl;
        break;
        }

        case 1: {
                cout<<"\nHow many random inputs? ";
                int b;
                cin>>b;
                
                int x[b];
                for(int i=0;i<b;i++){
        	        x[i]=(rand()%32000);
        	        root = insert(root, x[i]); 
                
                }        
                cout<<endl<<"Height of tree is: "<<height(root)<<endl;
                cout<<"\nHeight is less than 1.44*(log n)/(log 2) which is equal to "<<float(1.44*log(b))/(log(2))<<endl<<endl;
        
                break;
        }

        case 2: exit(0);
        default: {exit(0); break;}
        }
       
        
        /* Constructing tree given in 
        the above figure */
        /*for(int i=0;i<1000;i++){
        	int x[i]=(rand()%32000);
        	root = insert(root, x[i]); 
        }*/
        
    
        
        /* The constructed AVL Tree would be 
                        30 
                        / \ 
                          20 40 
                        / \ \ 
                        10 25 50 
        */
        //cout << "Printing the indented"
          //              " AVL tree: \n\n"; 
        if(height(root)<9)
                printGraphviz(root,0); 
        }
        
        
        return 0; 
} 









