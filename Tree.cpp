#include <iostream>

using namespace std;

typedef struct Btree
{
    struct Btree *left, *right;
    int i;
}BTree;


class BT 
{
    public:
        BTree **head;
    
        BT()
        {
            head = (BTree **)malloc(sizeof(BTree)); 
        };

        ~BT()
        {
            delete(head);
        };
    
        void insert(int); 
        void display(); 
    
    private:
        void insert(BTree**, int);
        void display(BTree *);
};


void BT::display()
{
    return BT::display(*head);
}

void BT::display(BTree *head)
{
    if (head != NULL)
    {
        BT::display(head->left);
        cout << head->i << " ";
        BT::display(head->right);
    }
}

void BT::insert(int i)
{
    return BT::insert(head, i);
}

void BT::insert(BTree **head, int i)
{
    if (*head == NULL)
    {
        *head = (BTree *)malloc(sizeof(BTree));
        (*head)->left = NULL;
        (*head)->right = NULL;
        (*head)->i = i;
    }
    else
    {
        if (i < (*head)->i)
        {
            return BT::insert (&((*head)->left), i);
        }
        else
        {
            return BT::insert (&((*head)->right), i);
        }
    }
}
    

int main() {
    BT* bt = new BT();
    bt->insert(5);
    bt->insert(3);
    bt->insert(7);
    bt->insert(2);
    bt->insert(4);
    bt->insert(6);
    bt->insert(8);
    bt->display();
    return 0;
}

