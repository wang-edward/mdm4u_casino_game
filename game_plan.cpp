// CPP program to construct binary
// tree from given array in level
// order fashion Tree Node
#include <iostream>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */

struct Pair {
    int data; double chance;
    Pair (int _a, double _b) {
        data = _a;
        chance = _b;
    }

};

struct Node
{
	int data;
    double chance;
	Node* left, * right;
};

/* Helper function that allocates a
new node */
Node* newNode(int data, double chance)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
    node->chance = chance;
	node->left = node->right = NULL;
	return (node);
}

// Function to insert nodes in level order
Node* insertLevelOrder(Pair arr[], Node* root,
					int i, int n)
{
	// Base case for recursion
	if (i < n)
	{
		Node* temp = newNode(arr[i].data, arr[i].chance);
		root = temp;

		// insert left child
		root->left = insertLevelOrder(arr,
				root->left, 2 * i + 1, n);

		// insert right child
		root->right = insertLevelOrder(arr,
				root->right, 2 * i + 2, n);
	}
	return root;
}

// Function to print tree nodes in
// InOrder fashion
void inOrder(Node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << "("<<root->data <<", " << root->chance<<"), ";
		inOrder(root->right);
	}
}



// Driver program to test above function
int main()
{
    //(win or loss, chance)
    double l_chance = 0.5;
    double w_chance = 17/36.;
    Pair W(-1,w_chance);
    Pair L(1,l_chance);
    Pair start(0,0);

    Pair arr[] = {
        start,
        L,W,
        L,W,L,W
    };

	
	double n = sizeof(arr)/sizeof(arr[0]);
	Node* root = insertLevelOrder(arr, root, 0, n);
	inOrder(root);
}

// This code is contributed by Chhavi


// int arr[] = {
//         0,
//         -1,1,
//         -1,1,-1,1,
//         -1,1,-1,1,-1,1,-1,1,
//         -1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,
//         -1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,
//         -1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,
//         -1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1
//     };