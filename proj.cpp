/* Static Balanced Binary Search Tree    */
/* Author: anthonylol06                  */
/* Info: https://github.com/anthonylol06 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//structure of a node
struct node{
    int key;
    node *left, *right;
};

class BST{
    public:
        // structure of BST
        node *root;

        // instance of BST
        BST(){
            root = NULL;
        };

        // predecessor qurey
        void predecessor(int value, int &p, node *root) { 
            if (root == NULL)
                return;
            if (root->key == value){
                p = value;
                return;
            }
            else if (root->key > value){
                predecessor(value, p, root->left);
            }
            else{
                p = root->key;
                return predecessor(value, p, root->right);
            }
        };

        // construct new node
        node* newNode(int value) {
            root = new node();
            root->key = value;
            root->left = NULL;
            root->right = NULL;
            return root;
        };

        // construct static binary search tree by recursive approach
        node* insert(vector<int> &arr, int lo, int hi){
            if (lo > hi) return NULL;
            int mid = (hi + lo) / 2;
            int value = arr[mid];
            node* tree = newNode(value);
            tree->left = insert(arr, lo, mid - 1);  
            tree->right = insert(arr, mid + 1, hi);
            return tree;
        };
};

/* swap the integers for partition */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* partition algorithm */
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* quicksort algorithm */
void quicksort(vector<int> &arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

int main(){
    BST *tree = new BST();
    ifstream ds;
    ifstream qs;
    ofstream resultFile;
    resultFile.open("output.txt");
    ds.open("ds.txt");
    qs.open("qs.txt");

    // construct stastic binary search tree
    string input;
    vector<int> bsttree;
    while (getline(ds, input)){
        int val = stoi(input.substr(0));
        bsttree.push_back(val);
    }
    int max = bsttree.size() - 1;
    quicksort(bsttree, 0, max);
    tree->root = tree->insert(bsttree, 0, max);

    // predecessor query
    while (getline(qs, input)){
        string qry = input.substr(0, 4);
        int value = stoi(input.substr(4));
        if (qry.compare("qry ") == 0){
            int q = INT32_MIN;
            tree->predecessor(value, q, tree->root);
            if (q != INT32_MIN) resultFile << q << endl;
            else resultFile << "no" << endl;
        }
    }
    ds.close();
    qs.close();
    resultFile.close();
    return 0;
}
