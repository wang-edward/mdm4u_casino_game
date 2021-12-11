// CPP program to construct binary
// tree from given array in level
// order fashion Tree Node
#include <iostream>
#include <vector>
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

struct Result {
    int rolls;
    int position;
    double chance;
    vector<int>path;
    Result (int _rolls, int _position, double _chance, vector<int> _path) {
        rolls = _rolls;
        position = _position;
        chance = _chance;
        path = _path;
    }
};

int places = 9;
    vector<vector<Result> > results(places+1);

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

vector<int> empty1 (10);
static Result ans(0,0,0,empty1);

void printPathsUtil(Node* curr_node, int sum,
            int sum_so_far, vector<int> &path, double scalar, int rolls)
{
    if (curr_node == NULL)
        return;
 
    // add the current node's value
    sum_so_far += curr_node->data;
    scalar *= curr_node->chance;
    rolls++;

    // add the value to path
    path.push_back(curr_node->data);
 
    // print the required path
    if (sum_so_far == sum )
    {
        // cout << "Path found: ";
        for (int i=0; i<path.size(); i++)
            // cout << path[i] << " ";
 
        // cout <<", chance = "<< scalar <<", number of rolls = "<<rolls<<endl;
        ans.rolls = rolls;
        ans.position = sum_so_far;
        ans.chance = scalar;
        ans.path = path;
        // Result ans(rolls, sum_so_far, scalar, path);
        results[rolls].push_back(ans);
    }
 
    // if left child exists
    if (curr_node->left != NULL)
        printPathsUtil(curr_node->left, sum, sum_so_far, path, scalar,rolls);
 
    // if right child exists
    if (curr_node->right != NULL)
        printPathsUtil(curr_node->right, sum, sum_so_far, path, scalar,rolls);
 
 
    // Remove last element from path
    // and move back to parent
    path.pop_back();
}
 
// Wrapper over printPathsUtil
void printPaths(Node *root, int sum)
{
    vector<int> path;
    printPathsUtil(root, sum, 0, path, 1,-1);
}



// Driver program to test above function
int main()
{
    //(win or loss, chance)
    double l_chance = 0.5;
    double w_chance = 17/36.;
    Pair W(1,w_chance);
    Pair L(-1,l_chance);
    Pair start(0,1);

    Pair arr[] = {
        start,
        L,W,
        L,W,L,W,
        L,W,L,W,L,W,L,W,
        L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,
        L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,
        L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,
        L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,
        L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,
        L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,L,W,
    };

	
	double n = sizeof(arr)/sizeof(arr[0]);
	Node* root = insertLevelOrder(arr, root, 0, n);

    for (int i=-4;i<=4;i++) {
        // cout<<i<<": "<<endl;
        printPaths(root, i);
    }

    double w_chances [places+1][places];
    double l_chances [places+1][places];
    double start_chances [places+1];

    for (int i=0;i<results.size();i++) {
        cout<<i<<" rolls: -----------------------"<<endl;
        for (Result r: results[i]) {
            if (r.position>0) {
                w_chances[r.rolls][r.position] += r.chance;
            } else if (r.position == 0) {
                start_chances[r.rolls]+=r.chance;
            } else {
                l_chances[r.rolls][-r.position] += r.chance;
            }
            cout<<r.rolls<<" "<<r.chance<<" "<<r.position<<endl;
        }
    }

    // cout<<"WINNING CHANCES=================="<<endl;
    // for (int i=0;i<places+1;i++) {
    //     for (int j=0;j<places+1;j++) {
    //         cout<<i<<","<<j<<": "<<w_chances[i][j]<<endl;
    //     }
    // }

    // cout<<"LOSING CHANCES=================="<<endl;
    // for (int i=0;i<places+1;i++) {
    //     for (int j=0;j<places+1;j++) {
    //         cout<<i<<","<<j<<": "<<l_chances[i][j]<<endl;
    //     }
    // }

    // cout<<"START CHANCES==================="<<endl;
    // for (int i=0;i<places+1;i++) {
    //     for (int j=0;j<places+1;j++) {
    //         cout<<i<<","<<j<<": "<<start_chances[i]<<endl;
    //     }
    // }

    // cout<<"SNAKE EYE CHANCES==================="<<endl;
    // for (int i=0;i<places+1;i++) {
    //     for (int j=0;j<places+1;j++) {
    //         cout<<i<<","<<j<<": "<<1-start_chances[i]-w_chances[i][j]-l_chances[i][j]<<endl;
    //     }
    // }

}

// int rolls;
//     int position;
//     double chance;
//     vector<int>path;


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