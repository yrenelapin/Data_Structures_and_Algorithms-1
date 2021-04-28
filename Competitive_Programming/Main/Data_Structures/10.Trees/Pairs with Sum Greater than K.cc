#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long int ll;

struct Node
{
    ll data;
    Node *left, *right;
} * root1, * root2;

ll k;

Node *newNode(ll key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

void insert_nodes(vector<ll> &arr, queue<Node *> &queue, ll index)
{
    while (1)
    {
        if (queue.size() == 0)
            break;
        Node *top = queue.front();
        queue.pop();
        if (index < arr.size())
        {
            if (arr[index] != INT_MAX)
            {
                top->left = newNode(arr[index]);
                queue.push(top->left);
            }
            else
            {
                top->left = NULL;
            }
            index++;
        }
        if (index < arr.size())
        {
            if (arr[index] != INT_MAX)
            {
                top->right = newNode(arr[index]);
                queue.push(top->right);
            }
            else
            {
                top->right = NULL;
            }
            index++;
        }
    }
}

void build_tree(ll a)
{
    string temp;
    vector<ll> arr;
    while (1)
    {
        cin >> temp;
        if (temp == "-1")
            break;

        if (temp != "null")
            arr.push_back(stoi(temp));
        else
            arr.push_back(INT_MAX);
    }
    
    queue<Node *> queue;
    if (a == 1){
        root1 = newNode(arr[0]);
      
        queue.push(root1);}
    if (a == 2){
        root2 = newNode(arr[0]);
        // queue<Node *> queue;
        queue.push(root2);}
    

    insert_nodes(arr, queue, 1);
}

vector<ll> v1, v2;

void post_order_traversal(struct Node *node, ll a)
{
    if (node == NULL)
        return;
    
    post_order_traversal(node->left, a);
      if ( a == 1 ){
        v1.push_back(node->data);
    }
    else{
        v2.push_back(node->data);
    }
    
    post_order_traversal(node->right, a);

}

struct Node* search_element(struct Node* &node, ll key){
    
    if (node == NULL or node->data == key){
        return node;
    }
    
    if ( node->data < key){
        return search_element(node->right, key);    
    }
    
    if ( node->data > key){
        return search_element(node->left, key);    
    }
    
    else { return node;}
}

ll count = 0 ;

void count_elements_in_subtree(struct Node* &node){
    
    if (node== NULL){
        return;
    }
    
    if (node != NULL){
        count++;
    }
    

    count_elements_in_subtree(node->left);
    count_elements_in_subtree(node->right);
    return;
}


void count_which_satisfy(struct Node* &node, ll req){
    
    if (node == NULL ){
        return;
    }
    
    if ( node->data < req){
        count_which_satisfy(node->right, req);    
    }
    
    if ( node->data >= req){
        
        if (node->data != req) count++; // The current Node is counted
        // We need to increment the `count` Number of elements in Right subtree times. 
        count_elements_in_subtree(node->right);
    }
    
    return;
}

void check_number_of_pairs_greaterthan_k(){
    
    if (v1.size() <= v2.size()){
        
        for (ll i = 0; i<v1.size(); i++){
            ll req = (k-v1[i]);     
            count_which_satisfy(root2, req);
            // cout << req <<  " " << count << "\n" ;
        }
    }
    else{
            for (ll i = 0; i<v2.size(); i++){
            ll req = (k-v2[i]);     
            count_which_satisfy(root1, req);
        // cout << req <<  " " << count << "\n" ;
        }
    }
    
}

int main()
{
   
    cin >> k;
    build_tree(1);
    post_order_traversal(root1,1);
    build_tree(2);
    post_order_traversal(root2,2);
    check_number_of_pairs_greaterthan_k();
    cout << count ;
}