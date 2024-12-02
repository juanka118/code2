//********************************************************************
//
//  main.cpp
//  CSCI 241 Assignment 17
//
//  Created by name (z-ID).
//
//********************************************************************

#include <iostream>
#include <iomanip>
#include "bstree.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    cout << "*** Testing default constructor ***\n\n";
    
    bstree<int, double> t1;
    bstree<int, double> t2;
    const node<int, double>* ptr;
    bool success;

    cout << fixed << setprecision(2);

    cout << "*** Testing size(), height(), empty(), and find() for empty tree ***\n\n";
    
    cout << "size(): " << t1.size() << endl;
    cout << "height(): " << t1.height() << endl;
    cout << "tree is " << ((t1.empty()) ? "empty\n" : "not empty\n");
    ptr = t1.find(56);
    cout << "56 " << ((ptr) ? "found\n\n" : "not found\n\n");

    cout << "*** Testing traversals of empty tree ***\n\n";

    cout << "preorder:\n\n";
    t1.preorder();
    cout << endl;

    cout << "inorder:\n\n";
    t1.inorder();
    cout << endl;

    cout << "postorder:\n\n";
    t1.postorder();
    cout << endl;

    cout << "level order:\n\n";
    t1.level_order();
    cout << endl;

    cout << "*** Testing insertion of root node ***\n\n";

    t2.insert(56, 7.50);

    cout << "*** Testing size(), height(), empty(), min(), max(), and find() for tree with one node ***\n\n";
    
    cout << "size(): " << t2.size() << endl;
    cout << "height(): " << t2.height() << endl;
    cout << "tree is " << ((t2.empty()) ? "empty\n" : "not empty\n");
    cout << "Minimum key: " << t2.min() << endl;
    cout << "Maximum key: " << t2.max() << endl << endl;
    ptr = t2.find(56);
    cout << "56 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl;
    else
        cout << "not found\n";
    ptr = t2.find(39);
    cout << "39 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl << endl;
    else
        cout << "not found\n\n";

    cout << "*** Testing traversals of tree with one node ***\n\n";

    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;
    
    cout << "postorder:\n\n";
    t2.postorder();
    cout << endl;
    
    cout << "level order:\n\n";
    t2.level_order();
    cout << endl;

    cout << "*** Testing insertion of additional nodes ***\n\n";

    t2.insert(34, 2.27);
    t2.insert(45, 3.91);
    t2.insert(68, 6.49);
    t2.insert(74, 7.03);
    t2.insert(21, 5.12);
    t2.insert(86, 9.74);
    t2.insert(62, 1.00);
    t2.insert(39, 8.99);

    cout << "*** Testing size(), height(), empty(), min(), max(), and find() ***\n\n";
    
    cout << "size(): " << t2.size() << endl;
    cout << "height(): " << t2.height() << endl;
    cout << "tree is " << ((t2.empty()) ? "empty\n" : "not empty\n");
    cout << "Minimum key: " << t2.min() << endl;
    cout << "Maximum key: " << t2.max() << endl << endl;
    ptr = t2.find(56);
    cout << "56 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl;
    else
        cout << "not found\n";
    ptr = t2.find(39);
    cout << "39 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl;
    else
        cout << "not found\n";
    ptr = t2.find(65);
    cout << "65 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl << endl;
    else
        cout << "not found\n\n";

    cout << "*** Testing traversals of tree ***\n\n";

    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;

    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;

    cout << "postorder:\n\n";
    t2.postorder();
    cout << endl;

    cout << "level order:\n\n";
    t2.level_order();
    cout << endl;

    cout << "*** Testing insertion of duplicate keys ***\n\n";

    cout << "*** Insert duplicate key 56 ***\n\n";
    success = t2.insert(56, 9.98);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;

    cout << "*** Insert duplicate key 39 ***\n\n";
    success = t2.insert(39, 2.09);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;

    const bstree<int, double>& t0 = t2;

    cout << "*** Testing const correctness ***\n\n";
    
    cout << "size(): " << t0.size() << endl;
    cout << "height(): " << t0.height() << endl;
    cout << "tree is " << ((t0.empty()) ? "empty\n" : "not empty\n");
    cout << "Minimum key: " << t0.min() << endl;
    cout << "Maximum key: " << t0.max() << endl << endl;
    ptr = t0.find(39);
    cout << "39 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl << endl;
    else
        cout << "not found\n\n";
    
    cout << "preorder:\n\n";
    t0.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t0.inorder();
    cout << endl;
    
    cout << "postorder:\n\n";
    t0.postorder();
    cout << endl;
    
    cout << "level order:\n\n";
    t0.level_order();
    cout << endl;

    cout << "*** Testing copy constructor ***\n\n";
    
    bstree<int, double> t3 = t1;
    bstree<int, double> t4 = t2;

    cout << "size(): " << t3.size() << endl;
    cout << "height(): " << t3.height() << endl << endl;

    cout << "preorder:\n\n";
    t3.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t3.inorder();
    cout << endl;

    cout << "size(): " << t4.size() << endl;
    cout << "height(): " << t4.height() << endl << endl;

    cout << "preorder:\n\n";
    t4.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t4.inorder();
    cout << endl;

    cout << "*** Testing clear() ***\n\n";
    
    t4.clear();
    
    cout << "size(): " << t4.size() << endl;
    cout << "height(): " << t4.height() << endl << endl;

    cout << "*** Testing for shallow copy ***\n\n";

    cout << "size(): " << t2.size() << endl;
    cout << "height(): " << t2.height() << endl << endl;

    cout << "*** Testing copy assignment operator ***\n\n";

    bstree<int, double> t5;
    t5 = t1;

    cout << "size(): " << t5.size() << endl;
    cout << "height(): " << t5.height() << endl << endl;
    
    cout << "preorder:\n\n";
    t5.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t5.inorder();
    cout << endl;

    t5 = t2;

    cout << "size(): " << t5.size() << endl;
    cout << "height(): " << t5.height() << endl << endl;
    
    cout << "preorder:\n\n";
    t5.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t5.inorder();
    cout << endl;

    cout << "*** Testing assignment to self ***\n\n";

    bstree<int, double>& r = t2;
    t2 = r;
    
    cout << "size(): " << t2.size() << endl;
    cout << "height(): " << t2.height() << endl << endl;

    cout << "*** Testing chained assignment ***\n\n";

    bstree<int, double> t6;
    
    t6.insert(8, 1.0);
    t6.insert(10, 2.0);
    t6.insert(27, 3.0);
    
    cout << "size(): " << t6.size() << endl;
    cout << "height(): " << t6.height() << endl << endl;
    
    cout << "preorder:\n\n";
    t6.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t6.inorder();
    cout << endl;

    t1 = t3 = t6;
    
    cout << "size(): " << t1.size() << endl;
    cout << "height(): " << t1.height() << endl << endl;
    
    cout << "preorder:\n\n";
    t1.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t1.inorder();
    cout << endl;

    t2.insert(65, 1.00);
    t2.insert(72, 3.00);
    t2.insert(73, 5.00);
    t2.insert(64, 7.00);

    cout << "*** Testing removal of non-existent node ***\n\n";
    
    success = t2.remove(66);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;

    cout << "*** Testing removal of node with no children ***\n\n";

    success = t2.remove(21);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;

    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;

    cout << "*** Testing removal of node with only right child ***\n\n";

    success = t2.remove(72);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;

    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;

    cout << "*** Testing removal of node with only left child ***\n\n";
    
    success = t2.remove(45);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;
    
    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;

    cout << "*** Testing removal of node with two children ***\n\n";
    
    success = t2.remove(68);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;
    
    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;

    cout << "*** Testing removal of root node with two children ***\n\n";
    
    success = t2.remove(56);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "size(): " << t2.size() << endl << endl;
    
    cout << "preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "inorder:\n\n";
    t2.inorder();
    cout << endl;

    return 0;
}
