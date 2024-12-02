#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <queue>

// Template Node structure
template <class K, class V>
struct node {
    K key;
    V value;
    node<K, V>* left;
    node<K, V>* right;

    // Constructor for node
    node(const K& key, const V& value)
        : key(key), value(value), left(nullptr), right(nullptr) {}
};

// Template BSTree class
template <class K, class V>
class bstree {
private:
    node<K, V>* root;
    size_t tree_size;

    // Helper function for deep copy
    node<K, V>* copy_tree(node<K, V>* other_root);

    // Helper function for clearing the tree
    void clear_tree(node<K, V>* root);

    // Helper function for finding a node
    const node<K, V>* find_node(node<K, V>* root, const K& key) const;

    // Helper function for the height of the tree
    size_t height_helper(node<K, V>* root) const;

    // Helper function for preorder traversal
    void preorder_helper(node<K, V>* root) const;

    // Helper function for inorder traversal
    void inorder_helper(node<K, V>* root) const;

    // Helper function for postorder traversal
    void postorder_helper(node<K, V>* root) const;

    // Helper function for level-order traversal
    void level_order_helper(node<K, V>* root) const;

    // Helper function to perform an insertion
    bool insert_helper(node<K, V>*& root, const K& key, const V& value);

    // Helper function to remove a node
    bool remove_helper(node<K, V>*& root, const K& key);

    // Helper function to find the minimum node
    node<K, V>* find_min(node<K, V>* root) const;

public:
    bstree();
    ~bstree();
    bstree(const bstree<K, V>& x);
    bstree<K, V>& operator=(const bstree<K, V>& x);

    void clear();
    size_t size() const;
    size_t height() const;
    bool empty() const;
    const K& min() const;
    const K& max() const;
    bool insert(const K& key, const V& value);
    bool remove(const K& key);
    const node<K, V>* find(const K& key) const;
    void preorder() const;
    void inorder() const;
    void postorder() const;
    void level_order() const;
};

////////////////////////// Implementations //////////////////////////

// Constructor
template <class K, class V>
bstree<K, V>::bstree() : root(nullptr), tree_size(0) {}

// Destructor
template <class K, class V>
bstree<K, V>::~bstree() {
    clear();
}

// Copy Constructor
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x) : root(nullptr), tree_size(0) {
    root = copy_tree(x.root);
    tree_size = x.tree_size;
}

// Copy helper function
template <class K, class V>
node<K, V>* bstree<K, V>::copy_tree(node<K, V>* other_root) {
    if (!other_root) return nullptr;
    node<K, V>* new_node = new node<K, V>(other_root->key, other_root->value);
    new_node->left = copy_tree(other_root->left);
    new_node->right = copy_tree(other_root->right);
    return new_node;
}

// Assignment operator
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x) {
    if (this != &x) {
        clear();
        root = copy_tree(x.root);
        tree_size = x.tree_size;
    }
    return *this;
}

// Clear function
template <class K, class V>
void bstree<K, V>::clear() {
    clear_tree(root);
    root = nullptr;
    tree_size = 0;
}

template <class K, class V>
void bstree<K, V>::clear_tree(node<K, V>* root) {
    if (!root) return;
    clear_tree(root->left);
    clear_tree(root->right);
    delete root;
}

// Size function
template <class K, class V>
size_t bstree<K, V>::size() const {
    return tree_size;
}

// Height function
template <class K, class V>
size_t bstree<K, V>::height() const {
    return height_helper(root);
}

template <class K, class V>
size_t bstree<K, V>::height_helper(node<K, V>* root) const {
    if (!root) return 0;
    size_t left_height = height_helper(root->left);
    size_t right_height = height_helper(root->right);
    return 1 + std::max(left_height, right_height);
}

// Empty check
template <class K, class V>
bool bstree<K, V>::empty() const {
    return tree_size == 0;
}

// Minimum key function
template <class K, class V>
const K& bstree<K, V>::min() const {
    return find_min(root)->key;
}

template <class K, class V>
node<K, V>* bstree<K, V>::find_min(node<K, V>* root) const {
    if (!root) return nullptr;
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Maximum key function
template <class K, class V>
const K& bstree<K, V>::max() const {
    node<K, V>* current = root;
    while (current && current->right) {
        current = current->right;
    }
    return current->key;
}

// Insert function
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value) {
    return insert_helper(root, key, value);
}

template <class K, class V>
bool bstree<K, V>::insert_helper(node<K, V>*& root, const K& key, const V& value) {
    if (!root) {
        root = new node<K, V>(key, value);
        ++tree_size;
        return true;
    }
    if (key < root->key)
        return insert_helper(root->left, key, value);
    else if (key > root->key)
        return insert_helper(root->right, key, value);
    return false;  // Key already exists
}

// Remove function
template <class K, class V>
bool bstree<K, V>::remove(const K& key) {
    return remove_helper(root, key);
}

template <class K, class V>
bool bstree<K, V>::remove_helper(node<K, V>*& root, const K& key) {
    if (!root) return false;  // Base case: key not found

    // Search for the node to remove
    if (key < root->key) {
        return remove_helper(root->left, key);
    } else if (key > root->key) {
        return remove_helper(root->right, key);
    }

    // Node found, now remove it
    if (!root->left) {
        // Node has no left child, replace with right child
        node<K, V>* temp = root;
        root = root->right;
        delete temp;
    } else if (!root->right) {
        // Node has no right child, replace with left child
        node<K, V>* temp = root;
        root = root->left;
        delete temp;
    } else {
        // Node has two children, replace with in-order successor
        node<K, V>* successor = find_min(root->right);
        root->key = successor->key;  // Copy the successor's key
        root->value = successor->value;  // Copy the successor's value

        // Now remove the successor node
        return remove_helper(root->right, successor->key);  // Remove successor
    }

    --tree_size;
    return true;
}


// Find function
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const {
    return find_node(root, key);
}

template <class K, class V>
const node<K, V>* bstree<K, V>::find_node(node<K, V>* root, const K& key) const {
    if (!root) return nullptr;
    if (key < root->key) return find_node(root->left, key);
    if (key > root->key) return find_node(root->right, key);
    return root;  // Key found
}

// Preorder traversal
template <class K, class V>
void bstree<K, V>::preorder() const {
    preorder_helper(root);
}

template <class K, class V>
void bstree<K, V>::preorder_helper(node<K, V>* root) const {
    if (!root) return;
    std::cout << root->key << ": " << root->value << "\n";
    preorder_helper(root->left);
    preorder_helper(root->right);
}

// Inorder traversal
template <class K, class V>
void bstree<K, V>::inorder() const {
    inorder_helper(root);
}

template <class K, class V>
void bstree<K, V>::inorder_helper(node<K, V>* root) const {
    if (!root) return;
    inorder_helper(root->left);
    std::cout << root->key << ": " << root->value << "\n";
    inorder_helper(root->right);
}

// Postorder traversal
template <class K, class V>
void bstree<K, V>::postorder() const {
    postorder_helper(root);
}

template <class K, class V>
void bstree<K, V>::postorder_helper(node<K, V>* root) const {
    if (!root) return;
    postorder_helper(root->left);
    postorder_helper(root->right);
    std::cout << root->key << ": " << root->value << "\n";
}

// Level-order traversal (non-recursive)
template <class K, class V>
void bstree<K, V>::level_order() const {
    level_order_helper(root);
}

template <class K, class V>
void bstree<K, V>::level_order_helper(node<K, V>* root) const {
    if (!root) return;
    std::queue<node<K, V>*> q;
    q.push(root);

    while (!q.empty()) {
        node<K, V>* current = q.front();
        q.pop();
        std::cout << current->key << ": " << current->value << "\n";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

#endif // BSTREE_H
