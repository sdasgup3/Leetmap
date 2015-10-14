#include<iostream>
#include<map>

typedef struct _Node {
    int i;
    struct _Node* ptr1;
    struct _Node* ptr2;
} Node;

typedef std::map<Node*, Node*> NodeMap;

Node * copy_recursive(Node * cur, NodeMap & nodeMap) {
    if(cur == NULL) {
        return NULL;
    }   
    NodeMap::iterator i = nodeMap.find(cur);
    if (i != nodeMap.end()) {
        return i->second;
    }

    
    Node * node = new Node;
    nodeMap[cur] = node; // map current before traversing links

    node->i = cur->i;
    node->ptr1 = copy_recursive(cur->ptr1, nodeMap);
    node->ptr2 = copy_recursive(cur->ptr2, nodeMap);

    return node;
}

Node * copy_structure(Node * root) {
    NodeMap nodeMap; 
    return copy_recursive(root, nodeMap);
}


int main()
{
    Node * node1 = new Node;
    node1->i = 1;
    Node * node2 = new Node;
    node2->i = 2;
    Node * node3 = new Node;
    node3->i = 3;

    node1->ptr1 = node2;
    node1->ptr2 = node3;
    
    node2->ptr1 = node1;
    node2->ptr2 = node3;

    node3->ptr1 = node1;
    node3->ptr2 = node2;

    std::cout << " node1 : " << node1->i <<" " << node1->ptr1->i << " " << node1->ptr2->i << "\n";
    std::cout << " node2 : " << node2->i <<" " << node2->ptr1->i << " " << node2->ptr2->i << "\n";
    std::cout << " node3 : " << node3->i <<" " << node3->ptr1->i << " " << node3->ptr2->i << "\n";

    node1 = copy_structure(node1);

    std::cout << " node1 : " << node1->i <<" " << node1->ptr1->i << " " << node1->ptr2->i << "\n";
    std::cout << " node2 : " << node2->i <<" " << node2->ptr1->i << " " << node2->ptr2->i << "\n";
    std::cout << " node3 : " << node3->i <<" " << node3->ptr1->i << " " << node3->ptr2->i << "\n";

}

