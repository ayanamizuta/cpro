#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

template <typename T> struct BinTreeNode {
  T data;
  struct BinTreeNode<T> *Parent;
  struct BinTreeNode<T> *LHS;
  struct BinTreeNode<T> *RHS;
  int height;
  int bias;
};

template <typename T> class BinTree {
public:
  BinTree();
  ~BinTree();

  BinTreeNode<T> *getRoot();
  bool search(T data);
  bool append(T data);
  bool erase(T data);
  T max();
  T max_(BinTreeNode<T>* node);
  bool checkBin();
  bool checkAVL();
  struct BinTreeNode<T> *nullNode;

private:
  struct BinTreeNode<T> *root;
  int animationCount;

  int bias(struct BinTreeNode<T> *node);
  void modHeight(struct BinTreeNode<T> *node);

  BinTreeNode<T> *searchNode(struct BinTreeNode<T> *node, T data);
  BinTreeNode<T> *searchParentNode(struct BinTreeNode<T> *node, T data);

  struct BinTreeNode<T> *LeftMax(struct BinTreeNode<T> *node);

  void Replace(struct BinTreeNode<T> *before, struct BinTreeNode<T> *after);

  struct BinTreeNode<T> *RotateR(struct BinTreeNode<T> *node);
  struct BinTreeNode<T> *RotateL(struct BinTreeNode<T> *node);
  struct BinTreeNode<T> *RotateRL(struct BinTreeNode<T> *node);
  struct BinTreeNode<T> *RotateLR(struct BinTreeNode<T> *node);

  void ToDot();

  void BalanceA(struct BinTreeNode<T> *node);
  void BalanceE(struct BinTreeNode<T> *node);

  void DumpNode(struct BinTreeNode<T> *node);
};

template <typename T> inline BinTree<T>::BinTree() {
  nullNode = new struct BinTreeNode<T>;
  nullNode->LHS = nullptr;
  nullNode->RHS = nullptr;
  nullNode->Parent = nullptr;
  nullNode->height = 0;

  root = nullNode;

  animationCount = 0;
}

template <typename T> T BinTree<T>::max() {
  if(root == nullNode)return 1e15;
  if(root->RHS == nullNode)return max_(root);
  return max_(root);
}

template <typename T> T BinTree<T>::max_(BinTreeNode<T>* node) {
  if(node->RHS == nullNode){
    return node->data;
  }
  return max_(node->RHS);
}

template <typename T> BinTree<T>::~BinTree<T>() {
  std::queue<struct BinTreeNode<T> *> queue;

  if (root == nullNode) {
    delete nullNode;
    return;
  }

  if (root->LHS != nullNode) {
    queue.push(root->LHS);
  }
  if (root->RHS != nullNode) {
    queue.push(root->RHS);
  }

  while (!queue.empty()) {
    struct BinTreeNode<T> *front = queue.front();
    queue.pop();

    if (front->LHS != nullNode) {
      queue.push(front->LHS);
    }
    if (front->RHS != nullNode) {
      queue.push(front->RHS);
    }

    delete front;
  }
  delete nullNode;
  delete root;
}

// getter
template <typename T> inline BinTreeNode<T> *BinTree<T>::getRoot() {
  return root;
}

//--------------------
// utility
//--------------------

// node must not nullNode
template <typename T> inline int BinTree<T>::bias(struct BinTreeNode<T> *node) {
  return node->LHS->height - node->RHS->height;
}

template <typename T>
inline void BinTree<T>::modHeight(struct BinTreeNode<T> *node) {
  int lHeight = node->LHS->height;
  int rHeight = node->RHS->height;
  node->height = 1 + (lHeight > rHeight ? lHeight : rHeight);
  node->bias = lHeight - rHeight;
}

template <typename T>
void BinTree<T>::Replace(struct BinTreeNode<T> *before,
                         struct BinTreeNode<T> *after) {
  struct BinTreeNode<T> *parentNode = before->Parent;

  if (before == root) {
    root = after;
  } else if (parentNode->LHS == before) {
    parentNode->LHS = after;
  } else {
    parentNode->RHS = after;
  }

  after->Parent = parentNode;
}
//--------------------
// search
//--------------------
template <typename T> bool BinTree<T>::search(T data) {
  struct BinTreeNode<T> *result = searchNode(root, data);

  if (result == nullNode) {
    return false;
  }

  return true;
}

template <typename T>
BinTreeNode<T> *BinTree<T>::searchNode(struct BinTreeNode<T> *node, T data) {
  if (node == nullNode) {
    return node;
  }

  struct BinTreeNode<T> *tmp = node;

  while (tmp != nullNode && tmp->data != data) {
    tmp = data < tmp->data ? tmp->LHS : tmp->RHS;
  }
  return tmp;
}

//--------------------
// append
//--------------------
template <typename T> bool BinTree<T>::append(T data) {
  // initial append
  if (root == nullNode) {
    struct BinTreeNode<T> *newNode = new struct BinTreeNode<T>;
    newNode->data = data;
    newNode->Parent = nullNode;
    newNode->LHS = nullNode;
    newNode->RHS = nullNode;
    newNode->height = 1;
    newNode->bias = 0;

    root = newNode;
    return true;
  }

  struct BinTreeNode<T> *parent = searchParentNode(root, data);

  if (parent->data == data) {
    return false;
  }

  if (data < parent->data) {
    if (parent->LHS != nullNode) {
      return false;
    }
  } else {
    if (parent->RHS != nullNode) {
      return false;
    }
  }

  struct BinTreeNode<T> *newNode = new struct BinTreeNode<T>;
  newNode->data = data;
  newNode->Parent = parent;
  newNode->LHS = nullNode;
  newNode->RHS = nullNode;
  newNode->height = 1;
  newNode->bias = 0;

  if (data < parent->data) {
    parent->LHS = newNode;
    BalanceA(parent->LHS);
  } else {
    parent->RHS = newNode;
    BalanceA(parent->RHS);
  }

  return true;
}

// return parent node's pointer whose child will have "data".
template <typename T>
BinTreeNode<T> *BinTree<T>::searchParentNode(struct BinTreeNode<T> *node,
                                             T data) {
  // if node is root or nullNode,return themself.
  if (node->data == data || node == nullNode) {
    return node;
  }

  struct BinTreeNode<T> *parent = node;
  struct BinTreeNode<T> *canditate = data < node->data ? node->LHS : node->RHS;

  while (canditate != nullNode && canditate->data != data) {
    parent = canditate;
    canditate = data < canditate->data ? canditate->LHS : canditate->RHS;
  }

  return parent;
}

//--------------------
// erase
//--------------------
template <typename T> bool BinTree<T>::erase(T data) {
  struct BinTreeNode<T> *deleteNode = searchNode(root, data);

  if (deleteNode == nullNode) {
    return false;
  }

  if (deleteNode->LHS == nullNode) {
    Replace(deleteNode, deleteNode->RHS);
    BalanceE(deleteNode->RHS);
    delete deleteNode;
  } else {
    struct BinTreeNode<T> *leftMaxNode = LeftMax(deleteNode);
    deleteNode->data = leftMaxNode->data;
    Replace(leftMaxNode, leftMaxNode->LHS);
    BalanceE(leftMaxNode->LHS);
    delete leftMaxNode;
  }
  return true;
}

template <typename T>
struct BinTreeNode<T> *BinTree<T>::LeftMax(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *leftMaxNode = node->LHS;

  while (leftMaxNode->RHS != nullNode) {
    leftMaxNode = leftMaxNode->RHS;
  }
  return leftMaxNode;
}

//--------------------
// rotate
//--------------------

//      node            LHS
//   LHS    Z   -->    X   node
//  X   Y                 Y    Z
template <typename T>
struct BinTreeNode<T> *BinTree<T>::RotateR(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *LHS = node->LHS;
  struct BinTreeNode<T> *Y = node->LHS->RHS;

  struct BinTreeNode<T> *partitionRoot = LHS;

  node->LHS = Y;
  if (Y != nullNode) {
    Y->Parent = node;
  }

  partitionRoot->RHS = node;

  Replace(node, LHS);
  node->Parent = LHS;

  modHeight(partitionRoot->RHS);
  modHeight(partitionRoot);

  return partitionRoot;
}

//   node                   LHS
// W      RHS          node     RHS
//     LHS   Z  -->   W    X   Y   Z
//    X   Y
template <typename T>
struct BinTreeNode<T> *BinTree<T>::RotateRL(struct BinTreeNode<T> *node) {
  RotateR(node->RHS);
  return RotateL(node);
}

//   node                RHS
//  X    RHS   -->   node   Z
//     Y    Z       X    Y
template <typename T>
struct BinTreeNode<T> *BinTree<T>::RotateL(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *RHS = node->RHS;
  struct BinTreeNode<T> *Y = node->RHS->LHS;

  struct BinTreeNode<T> *partitionRoot = RHS;

  node->RHS = Y;
  if (Y != nullNode) {
    Y->Parent = node;
  }

  partitionRoot->LHS = node;
  Replace(node, RHS);
  node->Parent = RHS;

  modHeight(partitionRoot->LHS);
  modHeight(partitionRoot);

  return partitionRoot;
}

//       node            RHS
//   LHS      Z      LHS     node
//  W   RHS     --> W   X   Y    Z
//     X   Y
template <typename T>
struct BinTreeNode<T> *BinTree<T>::RotateLR(struct BinTreeNode<T> *node) {
  RotateL(node->LHS);
  return RotateR(node);
}

//--------------------
// balance
//--------------------

template <typename T>
void BinTree<T>::BalanceA(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *targetNode = node;

  while (targetNode->Parent != nullNode) {
    struct BinTreeNode<T> *parentNode = targetNode->Parent;
    int height = parentNode->height;

    // when target node is LHS
    if (parentNode->LHS == targetNode) {
      if (bias(parentNode) == 2) {

        parentNode = bias(parentNode->LHS) >= 0 ? RotateR(parentNode)
                                                : RotateLR(parentNode);
      } else {
        modHeight(parentNode);
      }
      // when target node is RHS
    } else {
      if (bias(parentNode) == -2) {
        parentNode = bias(parentNode->RHS) <= 0 ? RotateL(parentNode)
                                                : RotateRL(parentNode);
      } else {
        modHeight(parentNode);
      }
    }

    if (height == parentNode->height) {
      break;
    }

    targetNode = parentNode;
  }
}

template <typename T> void BinTree<T>::BalanceE(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *targetNode = node;

  while (targetNode->Parent != nullNode) {
    struct BinTreeNode<T> *parentNode = targetNode->Parent;
    int height = parentNode->height;

    // when objective node is RHS
    if (parentNode->RHS == targetNode) {
      if (bias(parentNode) == 2) {

        parentNode = bias(parentNode->LHS) >= 0 ? RotateR(parentNode)
                                                : RotateLR(parentNode);
      } else {
        modHeight(parentNode);
      }
      // when objective node is LHS
    } else {
      if (bias(parentNode) == -2) {
        parentNode = bias(parentNode->RHS) <= 0 ? RotateL(parentNode)
                                                : RotateRL(parentNode);
      } else {
        modHeight(parentNode);
      }
    }

    if (height == parentNode->height) {
      break;
    }

    targetNode = parentNode;
  }
}


const int MAXSEGN = 200010;
class SegmentTree{
public:
  int size=0;
  int depth=0; // the depth of the tree
  int best=0;  // the index of maximum element
  int start=0; // the initial index of inputs
  long long dat[4 * MAXSEGN];
  
  SegmentTree(int n){
    size=n;
    while((1<<depth)<n)depth++;
    start=(1<<depth)-1;
    for(int i=start;i<(1<<(depth+1));i++){
      if(i<start+n)
	dat[i]=1e15;
      else
	dat[i]=1e15;
    }
    for(int i=0;i<4 * MAXSEGN;i++)dat[i]=1e15;
    for(int i=start;i<start+n;i++){
      int tmp=i;
      while(par(tmp)!=-1){
	dat[par(tmp)]=min(dat[tmp],dat[(tmp+1)/2*4-1-tmp]);
	tmp=par(tmp);
      }
    }
    int i=0;
    while(i<start)i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    best=i-start;
  }

  int par(int i){
    if(i==0)
      return -1;
    return (i-1)/2;
  }
  void dump(){
    for(int i=0;i<(3+1);i++){
      for(int j=0;j<(1<<i);j++)
	cerr<<dat[j+(1<<i)-1]<<" ";
      cerr<<endl;
    }
    cerr<<endl;
  }

  void update(int d,long long x){
    int i=d+start;
    dat[i]=x;
    while(par(i)!=-1){
      dat[par(i)]=min(dat[i],dat[(i+1)/2*4-1-i]);
      i=par(i);
    }
    i=0;
    while(i<start){
      i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }

  long long max_element(){
    return dat[0];
  }
  
};

int n,q;
LL a,b,c,d;
std::vector<BinTree<LL> > v;
int table[200000];
LL as[200001];

int main(){
  cin>>n>>q;
  v.resize(200000);
  REP(i,n){
    cin>>a>>b;
    b--;
    v[(int)b].append(a);
    as[i] = a;
    table[i] = (int)b;
  }
  SegmentTree segt(200000);
  REP(i,200000){
    segt.update(i,v[i].max());
  }
  

  REP(i,q){
    cin>>c>>d;
    c--;
    d--;
    int dpre = table[c];
    table[c] = d;
    
    v[(int)dpre].erase(as[c]);
    v[(int)d].append(as[c]);
    LL dpremax = v[(int)dpre].max();
    LL dmax = v[(int)d].max();
    segt.update(dpre,dpremax);
    segt.update(d,dmax);
    cout<<segt.max_element()<<endl;
  }


  return 0;
}
