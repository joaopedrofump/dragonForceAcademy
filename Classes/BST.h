#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;


template <class T>
class BTItrIn;

template <class T>
class BTItrPre;

template <class T>
class BTItrPost;

template <class T>
class BTItrLevel;

template <class T>
class BinaryTree;

class Underflow { };

template <class T>
class BTNode {
    T element;
    BTNode *left, *right;
    
    friend class BinaryTree<T>;
    friend class BTItrIn<T>;
    friend class BTItrPre<T>;
    friend class BTItrPost<T>;
    friend class BTItrLevel<T>;
public:
    BTNode(const T &e, BTNode *esq = 0, BTNode *dir = 0)
    : element(e), left(esq), right(dir) { }
    //added to professor's code
    T getElement() const {return this->element;}
    BTNode* getLeftNode() const {return this->left;};
    BTNode* getRightNode() const {return this->right;};
};

template <class T>
class BinaryTree {
public:
    BinaryTree() { root = 0; }
    BinaryTree(const BinaryTree &t);
    BinaryTree(const T&);
    BinaryTree(const T&elem, const BinaryTree & esq, const BinaryTree & dir);
    ~BinaryTree() { makeEmpty(); }
    const BinaryTree &operator=(const BinaryTree & rhs);
    
    bool isEmpty () const
    { return (root == 0) ? true : false; }
    T & getRoot () const
    { if (root) return root->element; else throw Underflow(); }
    
    void makeEmpty();
    void outputPreorder(ostream &out) const;
    
private:
    BTNode<T> *root;
    
    void makeEmpty (BTNode<T> *r);
    BTNode<T> *copySubtree(const BTNode<T> *n) const;
    void outputPreorder(ostream &out, const BTNode<T> *n) const;
    
    friend class BTItrIn<T>;
    friend class BTItrPre<T>;
    friend class BTItrPost<T>;
    friend class BTItrLevel<T>;
};


template <class T>
BinaryTree<T>::BinaryTree(const T &v)
{
    root = new BTNode<T>(v);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &t)
{
    root = copySubtree(t.root);
}

template <class T>
BTNode<T> *BinaryTree<T>::copySubtree(const BTNode<T> *n) const
{
    if (n) {
        BTNode<T> *node = new BTNode<T>(n->element, copySubtree(n->left),
                                        copySubtree(n->right));
        return node;
    } else
        return 0;
}

template <class T>
BinaryTree<T>::BinaryTree(const T&elem, const BinaryTree & esq,
                          const BinaryTree & dir)
{
    root = new BTNode<T>(elem, copySubtree(esq.root), copySubtree(dir.root));
}

template <class T>
const BinaryTree<T> & BinaryTree<T>::operator=(const BinaryTree<T> & rhs)
{
    if (this != & rhs) {
        makeEmpty();
        root = copySubtree(rhs.root);
    }
    return *this;
}


template <class T>
void BinaryTree<T>::makeEmpty()
{
    makeEmpty(root);
}


template <class T>
void BinaryTree<T>::makeEmpty(BTNode<T> *r)
{
    if (r) {
        makeEmpty(r->left);
        makeEmpty(r->right);
        delete r;
    }
}

template <class T>
void BinaryTree<T>::outputPreorder(ostream &out) const
{
    outputPreorder(out, root);
    
}

template <class T>
void BinaryTree<T>::outputPreorder(ostream &out, const BTNode<T> *r) const
{
    out << '(';
    if (r) {
        out <<  r->element << ' ';
        outputPreorder(out, r->left);
        out << ' ';
        outputPreorder(out, r->right);
    }
    out << ')';
}

// Para usar o operador <<
template <class T>
ostream &operator<<(ostream &out, const BinaryTree<T> &t)
{
    t.outputPreorder(out);
    return out;
}


// Iteradores

template <class T>
class BTItrPost {
public:
    BTItrPost(const BinaryTree<T> &bt);
    
    void advance();
    T &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }
    
private:
    stack<BTNode<T> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BTNode<T> *n);
};


template <class T>
BTItrPost<T>::BTItrPost (const BinaryTree<T> &bt)
{
    if (!bt.isEmpty())
        slideDown(bt.root);
}

template <class T>
void BTItrPost<T>::advance ()
{
    itrStack.pop();
    visitStack.pop();
    if ((!itrStack.empty()) && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class T>
void BTItrPost<T>::slideDown(BTNode<T> *n)
{
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        } else if (n->right) {
            visitStack.push(true);
            n = n->right;
        } else {
            visitStack.push(true);
            break;
        }
    }
}


/////////////////////

template <class T>
class BTItrPre {
public:
    BTItrPre(const BinaryTree<T> &bt);
    
    void advance();
    T &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }
    
private:
    stack<BTNode<T> *> itrStack;
    
};

template <class T>
BTItrPre<T>::BTItrPre (const BinaryTree<T> &bt)
{
    if (!bt.isEmpty())
        itrStack.push(bt.root);
}

template <class T>
void BTItrPre<T>::advance()
{
    BTNode<T> * actual = itrStack.top();
    BTNode<T> * seguinte = actual->left;
    if (seguinte)
        itrStack.push(seguinte);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            seguinte = actual -> right;
            if (seguinte) {
                itrStack.push(seguinte);
                break;
            }
        }
    }
}


template <class T>
class BTItrIn {
public:
    BTItrIn(const BinaryTree<T> &bt);
    
    void advance();
    T &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }
    
private:
    stack<BTNode<T> *> itrStack;
    
    void slideLeft(BTNode<T> *n);
};

template <class T>
BTItrIn<T>::BTItrIn (const BinaryTree<T> &bt)
{
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template <class T>
void BTItrIn<T>::slideLeft(BTNode<T> *n)
{
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class T>
void BTItrIn<T>::advance()
{
    BTNode<T> * actual = itrStack.top();
    itrStack.pop();
    BTNode<T> * seguinte = actual->right;
    if (seguinte)
        slideLeft(seguinte);
}


template <class T>
class BTItrLevel {
public:
    BTItrLevel(const BinaryTree<T> &bt);
    void advance();
    T &retrieve() { return itrQueue.front()->element; }
    bool isAtEnd() {return itrQueue.empty(); }
    //added to professor's code
    BTNode<T>* getNode() const {return itrQueue.front();};
    
private:
    queue<BTNode<T> *> itrQueue;
    
};

template <class T>
BTItrLevel<T>::BTItrLevel (const BinaryTree<T> &bt)
{
    if (!bt.isEmpty())
        itrQueue.push(bt.root);
}

template <class T>
void BTItrLevel<T>::advance()
{
    BTNode<T> * actual = itrQueue.front();
    itrQueue.pop();
    BTNode<T> * seguinte = actual->left;
    if (seguinte)
        itrQueue.push(seguinte);
    seguinte = actual->right;
    if (seguinte)
        itrQueue.push(seguinte);
}

/****************************************************************
***********************    BST     ******************************
*****************************************************************/

template <class Comparable>
class BSTItrIn;

template <class Comparable>
class BSTItrPre;

template <class Comparable>
class BSTItrPost;

template <class Comparable>
class BSTItrLevel;

template <class Comparable>
class BST;

template <class Comparable>
class BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
    
    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
    : element( theElement ), left( lt ), right( rt ) { }
    
    friend class BST<Comparable>;
    friend class BSTItrIn<Comparable>;
    friend class BSTItrPre<Comparable>;
    friend class BSTItrPost<Comparable>;
    friend class BSTItrLevel<Comparable>;
};

template <class Comparable>
class BST
{
public:
    explicit BST( const Comparable & notFound );
    BST( const BST & rhs );
    ~BST( );
    
    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    
    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    
    const BST & operator=( const BST & rhs );
    
private:
    BinaryNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;
    
    const Comparable & elementAt( BinaryNode<Comparable> *t ) const;
    
    void insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
    void makeEmpty( BinaryNode<Comparable> * & t ) const;
    void printTree( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;
    
    friend class BSTItrIn<Comparable>;
    friend class BSTItrPre<Comparable>;
    friend class BSTItrPost<Comparable>;
    friend class BSTItrLevel<Comparable>;
};

// Note that all "matching" is based on the < method.

template <class Comparable>
BST<Comparable>::BST( const Comparable & notFound ) :
root(NULL), ITEM_NOT_FOUND( notFound )
{ }

template <class Comparable>
BST<Comparable>::BST( const BST<Comparable> & rhs ) : root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{
    *this = rhs;
}


template <class Comparable>
BST<Comparable>::~BST( )
{
    makeEmpty( );
}

template <class Comparable>
void BST<Comparable>::insert( const Comparable & x )
{
    insert( x, root );
}

template <class Comparable>
void BST<Comparable>::remove( const Comparable & x )
{
    remove( x, root );
}

template <class Comparable>
const Comparable & BST<Comparable>::findMin( ) const
{
    return elementAt( findMin( root ) );
}

template <class Comparable>
const Comparable & BST<Comparable>::findMax( ) const
{
    return elementAt( findMax( root ) );
}

template <class Comparable>
const Comparable & BST<Comparable>::
find( const Comparable & x ) const
{
    return elementAt( find( x, root ) );
}

template <class Comparable>
void BST<Comparable>::makeEmpty( )
{
    makeEmpty( root );
}

template <class Comparable>
bool BST<Comparable>::isEmpty( ) const
{
    return root == NULL;
}


template <class Comparable>
void BST<Comparable>::printTree( ) const
{
    if( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree( root );
}

template <class Comparable>
const BST<Comparable> &
BST<Comparable>::
operator=( const BST<Comparable> & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}


template <class Comparable>
const Comparable & BST<Comparable>::
elementAt( BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return ITEM_NOT_FOUND;
    else
        return t->element;
}


template <class Comparable>
void BST<Comparable>::
insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
    if( t == NULL )
        t = new BinaryNode<Comparable>( x, NULL, NULL );
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
        ;  // Duplicate; do nothing
}

template <class Comparable>
void BST<Comparable>::
remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
    if( t == NULL )
        return;   // Item not found; do nothing
    if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    }
    else
    {
        BinaryNode<Comparable> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
    }
}

template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::findMin( BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    if( t->left == NULL )
        return t;
    return findMin( t->left );
}


template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::findMax( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;
    return t;
}

template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::
find( const Comparable & x, BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    else if( x < t->element )
        return find( x, t->left );
    else if( t->element < x )
        return find( x, t->right );
    else
        return t;    // Match
}
/****** NONRECURSIVE VERSION*************************
 template <class Comparable>
 BinaryNode<Comparable> *
 BST<Comparable>::
 find( const Comparable & x, BinaryNode<Comparable> *t ) const
 {
 while( t != NULL )
 if( x < t->element )
 t = t->left;
 else if( t->element < x )
 t = t->right;
 else
 return t;    // Match
 
 return NULL;   // No match
 }
 *****************************************************/

/**
 * Internal method to make subtree empty.
 */
template <class Comparable>
void BST<Comparable>::
makeEmpty( BinaryNode<Comparable> * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

template <class Comparable>
void BST<Comparable>::printTree( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        printTree( t->left );
        cout << t->element << endl;
        printTree( t->right );
    }
}

template <class Comparable>
BinaryNode<Comparable> *
BST<Comparable>::clone( BinaryNode<Comparable> * t ) const
{
    if( t == NULL )
        return NULL;
    else
        return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}


/**************
 // Iteradores
 **************/


template <class Comparable>
class BSTItrPost {
public:
    BSTItrPost(const BST<Comparable> &bt);
    
    void advance();
    Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }
    
private:
    stack<BinaryNode<Comparable> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BinaryNode<Comparable> *n);
};


template <class Comparable>
BSTItrPost<Comparable>::BSTItrPost (const BST<Comparable> &bt)
{
    if (!bt.isEmpty())
        slideDown(bt.root);
}

template <class Comparable>
void BSTItrPost<Comparable>::advance ()
{
    itrStack.pop();
    visitStack.pop();
    if ((!itrStack.empty()) && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class Comparable>
void BSTItrPost<Comparable>::slideDown(BinaryNode<Comparable> *n)
{
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        } else if (n->right) {
            visitStack.push(true);
            n = n->right;
        } else {
            visitStack.push(true);
            break;
        }
    }
}


/////////////////////

template <class Comparable>
class BSTItrPre {
public:
    BSTItrPre(const BST<Comparable> &bt);
    
    void advance();
    Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }
    
private:
    stack<BinaryNode<Comparable> *> itrStack;
    
};

template <class Comparable>
BSTItrPre<Comparable>::BSTItrPre (const BST<Comparable> &bt)
{
    if (!bt.isEmpty())
        itrStack.push(bt.root);
}

template <class Comparable>
void BSTItrPre<Comparable>::advance()
{
    BinaryNode<Comparable> * actual = itrStack.top();
    BinaryNode<Comparable> * seguinte = actual->left;
    if (seguinte)
        itrStack.push(seguinte);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            seguinte = actual -> right;
            if (seguinte) {
                itrStack.push(seguinte);
                break;
            }
        }
    }
}


template <class Comparable>
class BSTItrIn {
public:
    BSTItrIn(const BST<Comparable> &bt);
    
    void advance();
    Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }
    
private:
    stack<BinaryNode<Comparable> *> itrStack;
    
    void slideLeft(BinaryNode<Comparable> *n);
};

template <class Comparable>
BSTItrIn<Comparable>::BSTItrIn (const BST<Comparable> &bt)
{
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template <class Comparable>
void BSTItrIn<Comparable>::slideLeft(BinaryNode<Comparable> *n)
{
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class Comparable>
void BSTItrIn<Comparable>::advance()
{
    BinaryNode<Comparable> * actual = itrStack.top();
    itrStack.pop();
    BinaryNode<Comparable> * seguinte = actual->right;
    if (seguinte)
        slideLeft(seguinte);
}


template <class Comparable>
class BSTItrLevel {
public:
    BSTItrLevel(const BST<Comparable> &bt);
    
    void advance();
    Comparable &retrieve() { return itrQueue.front()->element; }
    bool isAtEnd() {return itrQueue.empty(); }
    
private:
    queue<BinaryNode<Comparable> *> itrQueue;
    
};

template <class Comparable>
BSTItrLevel<Comparable>::BSTItrLevel (const BST<Comparable> &bt)
{
    if (!bt.isEmpty())
        itrQueue.push(bt.root);
}

template <class Comparable>
void BSTItrLevel<Comparable>::advance()
{
    BinaryNode<Comparable> * actual = itrQueue.front();
    itrQueue.pop();
    BinaryNode<Comparable> * seguinte = actual->left;
    if (seguinte)
        itrQueue.push(seguinte);
    seguinte = actual->right;
    if (seguinte)
        itrQueue.push(seguinte);
}


#endif
