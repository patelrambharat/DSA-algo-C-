#include<iostream>
#include<queue>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildBST(Node* root, int data) {
    if( root == NULL) {
        Node* temp = new Node(data);
        return temp;
    }

    if(data > root->data) {
        root -> right = buildBST(root->right, data);
    }
    else {
        root->left = buildBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root) {

    cout << "Enter the value for Root Node" << endl;
    int data;
    cin >> data;

    while(data != -1) {
        root = buildBST(root, data);
        cout << "Enter the data for node " << endl;
        cin >> data;
    }

}

void preOrder(Node* root) {
    //base case
    if(root == NULL)
        return;

    //N
    cout << root->data << " ";
    //L
    preOrder(root->left);
    //R
    preOrder(root->right);
}

void inOrder(Node* root) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    inOrder(root->left);
    //N
    cout << root->data << " ";
    //R
    inOrder(root->right);
}

void postOrder(Node* root) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    postOrder(root->left);
    //R
    postOrder(root->right);
    //N
    cout << root->data << " ";

}

void lvlOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    //change no. 1
    q.push(NULL);

    while(!q.empty()) {
        //tu nikal
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            cout << endl;
            //catch here
            if(!q.empty())//still elements are present
                q.push(NULL);
        }
        else{
            cout << front->data << " ";

            //bache chor jaio
            if(front->left != NULL)
                q.push(front->left);
            if(front->right != NULL)
                q.push(front->right);
        }
    }
}

bool search(Node* root, int target) {

    if(root == NULL)
        return false;

    if(root -> data == target) 
        return true;

    if(target < root->data) {
        bool leftAns = search(root->left, target);
        if(leftAns == true)
            return true;
    }
    else{
        bool rightAns = search(root->right, target);
        if(rightAns == true)
            return true;
    }
    return false;
}

Node* maxVal(Node* root) {
    Node* temp = root;
    while(temp ->right != NULL) {
        temp = temp -> right;
    }
    return temp;
}

Node* deleteNode(Node* root, int target) {
    if(root == NULL)
        return NULL;
    
    if( root -> data == target) {
        //0 child
        if( root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //1 child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if( root->left != NULL && root->right != NULL) {
            //get Inorder pred
            int pred = maxVal(root->left) -> data;
            //copy
            root->data = pred;
            //solve bachi hui   problem
            root->left = deleteNode(root->left, pred);
            return root;
        }

    }
    else if(target > root->data) {
        root->right = deleteNode(root->right, target);
    } 
    else{
        root->left = deleteNode(root->left, target);
    }
    return root;
}


int main() {
    Node* root = NULL;
    createBST(root);

    // lvlOrderTraversal(root);
    // cout << "Printing Inorder " << endl;  
    // inOrder(root);
    // cout << endl;
    // cout << "Printing PreOrder " << endl;  
    // preOrder(root);
    // cout << endl;
    // cout << "Printing PostOrder " << endl;  
    // postOrder(root);
    // cout << endl;
    
    cout << "Printing the tree" << endl;
    lvlOrderTraversal(root);
    cout << endl;

    int target;
    cout << "enter the target" << endl;
    cin >> target;
    // cout << "Found or not " << search(root, target);

    root = deleteNode(root, target);

    cout << "Printing the tree again " << endl;
    lvlOrderTraversal(root);
    cout << endl;


    return 0;
}