//construct a binary serach tree using the elements of array arr={6,3,17,5,11,18,2,1,20,14}
# include<iostream>
using namespace std;
class Node{
    public:
   int data;
   Node* left;
   Node* right;
   Node(int value){
    data=value;
    left=right=NULL;
   }
};

//insert function
Node* insert(Node* root,int target){
    //Base Case
    if(root==NULL){
        Node* temp=new Node(target);
        return temp;
    }
    //target<root->data then insert left side
    if(target<root->data){
        root->left=insert(root->left,target);
    }
    //target>root->data then insert on right side
    else{
        root->right=insert(root->right,target);
    }
    return root;
}
//function for searching a element 
bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    //key==root->data
    if(key==root->data){
        return true;
    }
    //key<root->data;
    else if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    //first left child
    inorder(root->left);
    //second node
    cout<<root->data<<" ";
    //third right child
    inorder(root->right);
    
}

int main(){
    Node* root=NULL;
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);
    }
    int key;
    cout<<"Enter The Target key: ";
    cin>>key;
    //function call  for searching
    if(search(root,key)){
        cout<<"Target Element Found: "<<endl;;
    }
    else {
        cout<<"Target Element Not Found: "<<endl;
    }
    //function call for traversal
    inorder(root);
    return 0;
}