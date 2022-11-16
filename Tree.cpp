#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

class Tree{
public:
	Tree(){
	    root = NULL;
    }
    ~Tree(){
        destructor();
    }
	
	void add(int key){
        if(root != NULL){
            add(key, root);
        }else{
            root = new node;
            root->data = key;
            root->left = NULL;
            root->right = NULL;
        }
    }

    ////


    bool search(const int &val) const
    {
        if (NULL == root)
        {
            return false;
        }
        node *p = root;
        while (NULL != p)
        {
            if (p->data == val)
            {
                return p->data;
            }
            if (p->data > val)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        return false;
    };

    void destructor(){
        destructor(root);
    }

	void inorder(){
        cout << "Inorder Print = ";
        inorder(root);
        cout <<"\n";
    }

    void postorder(){
        cout << "Postorder Print = ";
        postorder(root);
        cout << "\n";
    }


    void preorder(){
        cout << "Preorder Print = ";
        preorder(root);
        cout << "\n";
    }

private:
	void destructor(node *p){
	if(p != NULL){
		destructor(p->left);
		destructor(p->right);
		delete p;
	}
    }

	void add(int key, node *p){

        if(key < p->data){
            if(p->left != NULL){
                add(key, p->left);
            }else{
                p->left = new node;
                p->left->data = key;
                p->left->left = NULL;
                p->left->right = NULL;
            }
        }else if(key >= p->data){
            if(p->right != NULL){
                add(key, p->right);
            }else{
                p->right = new node;
                p->right->data = key;
                p->right->right = NULL;
                p->right->left = NULL;
            }
        }

    }

    ////////


    bool search(const int &val , node* p) const
    {
        if (NULL == root)
        {
            return false;
        }
        node *pp = root;
        while (NULL != p)
        {
            if (pp->data == val)
            {
                return pp->data;
            }
            if (pp->data > val)
            {
                pp = pp->left;
            }
            else
            {
                pp = pp->right;
            }
        }
        return false;
    };

	void inorder(node *p){
        if(p != NULL){
            inorder(p->left);
            cout << p->data << ",";
            inorder(p->right);
        }
    }

	void postorder(node *p){
        if(p != NULL){
            inorder(p->left);
            inorder(p->right);
            cout << p->data << ",";
        }
    }

    void preorder(node *p){
        if(p != NULL){
            cout << p->data << ",";
            inorder(p->left);
            inorder(p->right);
        }
    }
    
	node *root;
};










int main(){
	Tree *tree = new Tree();

	tree->add(24);
	tree->add(4);
	tree->add(3);
	tree->add(12);
	tree->add(15);
	tree->add(7);
	tree->add(9);
	tree->add(16);
	tree->add(21);

    ////////

	tree->preorder();
	tree->inorder();
	tree->postorder();
    int n;
    cout << "Write number... ";
    cin >> n;
    cout << "There is - "<< n << " Search number? = " << tree->search(n) << endl; 
    

	delete tree;

}