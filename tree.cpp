#include <iostream>

template <typename T>
class Tree
{
private:
    struct Node
    {
        T data;
        Node *right;
        Node *left;
    };
    Node *root;

public:
    Tree() : root{NULL} {};
    ~Tree(){};
    Tree(const Tree &);
    void add(const T &data)
    {
        Node *tmp = new Node;
        tmp->data = data;

        if (NULL == root)
        {
            root = tmp;
            return;
        }

        Node *p = root;
        while (p->data > data && NULL != p->left || p->data <= data && NULL != p->right)
        {
            if (p->data > data)
            {
                p = p->left;
                continue;
            }
            if (p->data < data)
            {
                p = p->right;
                continue;
            }
        }
        if (p->data > data)
        {
            p->left = tmp;
            return;
        }
        if (p->data < data)
        {
            p->right = tmp;
            return;
        }
    };

    bool search(const T &val) const
    {
        if (NULL == root)
        {
            return false;
        }
        Node *p = root;
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
};

int main()
{
    Tree<int> t;
    t.add(5);
    t.add(10);
    t.add(7);
    std::cout << t.search(5) << std::endl;
    return 0;
}