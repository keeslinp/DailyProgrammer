#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Node{
    
    public:
        bool init = false;
        int value;
        Node *left = NULL;
        Node *right = NULL;
        Node(int i);
        Node();
        void add(int i);
        void delete_all();
};

Node::Node(int i){
    value = i;
    left= new Node();
    right = new Node();
    init = true;
}

Node::Node(){
}

void Node::add(int i){
    if(!init){
        value = i;
        left = new Node();
        right = new Node();
        init = true;
        cout << value << endl;
    }else{
        (i<value) ? (*left).add(i) : (*right).add(i);
    }
}

void Node::delete_all(){
    //(*left).delete_all();
    //(*right).delete_all();
    delete left;
    delete right;
}

ostream &operator<<(ostream &out, Node n)
{
    if(!n.init) return out;
    out << n.value << endl;
    out << n.left << endl;
    out << n.right << endl;
    return out;
}

int main(int argc, char* argv[])
{
    vector<int> nums(argc-1);
    for(int i = 1;i < argc;i++)
    {
        stringstream(argv[i]) >> nums[i-1];
    }
    Node root;
    cout << "est"<<endl;
    for(vector<int>::iterator it = nums.begin();it<nums.end();it++)
    {
        root.add(*it);
    }
    
    cout << root << endl;
    
    root.delete_all();
    
    return 0;
}
