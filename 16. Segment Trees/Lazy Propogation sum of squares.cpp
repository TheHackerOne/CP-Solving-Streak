// #include<bits/stdc++.h>
// using namespace std;

// // Sum of Squares Lazy Propogation
// // Updation type-1 increment all elements in range L to R with value v
// // a^2 = (a + v)^2 = a^2 + b^v + 2*a*v
// // Updation type-2 replace all elements with value v
// // a^2 = v^2
// class treeNode {
// public:
//  int sum;
//  int sumOfSquares;
// };

// class lazyNode {
// public:
//  int flag;
//  int value;
// };

// updateSegmentTreeLazy(int *tree, int *lazy, int treeNode, int l, int h, int s, int e, int val, int type) {
//  if (l > h) return;

//  if (lazy[treeNode].value != 0) {
//    if (lazy[treeNode].flag == 1) {
//      tree[treeNode] += (pow(lazy[treeNode].value, 2) * (h - l + 1)) + (2 * lazy[treeNode].value * tree[treeNode].sum);
//    } else {
//      tree[treeNode]  = pow(lazy[treeNode].value, 2) * (h - l + 1);
//    }
//    lazy[2 * treeNode].flag = lazy[treeNode].flag;
//    lazy[2 * treeNode].value = lazy[treeNode].value;
//    lazy[2 * treeNode + 1].flag = lazy[treeNode].flag;
//    lazy[2 * treeNode + 1].value = lazy[treeNode].value;
//    lazy[treeNode].value = 0;
//    lazy[treeNode].flag = 0;
//  }

//  // for completely outside
//  if(s > h || e < l) return;

//  // completely inside
//  if(s <= l && e >= h){
//    if(type == 1){
//      tree[treeNode] += (pow(val, 2) * (h - l + 1)) + (2*val*tree[treeNode].sum);
//    }else{
//      tree[treeNode] = pow(val, 2) * (h - l + 1);
//    }
//    if(l != h){
//      lazy[2*treeNode].flag = type;
//      lazy[2*treeNode].value = val;
//      lazy[2*treeNode+1].flag = type;
//      lazy[2*treeNode+1].value = val;
//    }
//  }

//  // partially inside
//  int mid = (s + e)/2;
//  updateSegmentTreeLazy(tree, lazy, 2*treeNode, l, mid, s, e, val, type);
//  updateSegmentTreeLazy(tree, lazy, 2*treeNode+1, mid+1, h, s, e, val, type);
//  tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
//  tree[treeNode].sumOfSquares = tree[2*treeNode].sumOfSquares + tree[2*treeNode+1].sumOfSquares;
// }

// void buildTree(int *arr, int *tree, int treeNode, int s, int e) {
//  if (s == e) {
//    tree[treeNode].sum = arr[s];
//    tree[treeNode].sumOfSquares = pow(arr[s], 2);
//    return;
//  }

//  int mid = (s + e) / 2;
//  buildTree(arr, tree, 2 * treeNode, s, mid);
//  buildTree(arr, tree, 2 * treeNode + 1, mid + 1, e);
//  tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
//  tree[treeNode].sumOfSquares = tree[2 * treeNode].sumOfSquares + tree[2 * treeNode + 1].sumOfSquares;
// }

// int main() {
//  int n;
//  cin >> n;

//  int arr[n];
//  for (int i = 0; i < n; i++) arr[i];

//  treeNode tree[4 * n];
//  lazyNode lazy[4 * n];

//  for (int i = 1; i <= 3 * n; i++) lazy[i] = 0;

//  buildTree(arr, tree, 1, 0, n - 1);
//  updateSegmentTreeLazy(tree, lazy, 1, 0, n - 1, 0, 2, 5, 1);

//  return 0;
// }

/*
   Time Complexity:O(N*log(N)+q*log(N))
   Space Complexity:O(N)
   where N is size of array and q is number of queries.
*/

class obj {
public:
  long long int Square_Sum;
  long long int Sum;
  obj()
  {
    Square_Sum = 0;
    Sum = 0;
  }
};


class obj1 {
public:
  long long int set;
  long long int increment;
  obj1()
  {
    set = 0;
    increment = 0;
  }
};

class segmentTree
{
public:

  vector<obj> segment;
  vector<obj1> lazy;

  segmentTree(int N)
  {
    // Intialising the segment and lazy vector to 4*N.
    segment = vector<obj>(4 * N);
    lazy = vector<obj1>(4 * N);
  }
  // Building segment tree corresponding to given array.
  void buildtree(vector<int> &arr, int l, int r, int index = 0)
  {
    if (l > r)
    {
      return ;
    }
    // The particular node will store sum and sum of squares.
    if (l == r)
    {

      segment[index].Square_Sum = arr[l] * arr[l];
      segment[index].Sum = arr[l];
      return ;

    }

    int lChild = 2 * index + 1;
    int rChild = 2 * index + 2;

    int mid = (l + r) >> 1;

    buildtree(arr, l, mid, lChild);
    buildtree(arr, mid + 1, r, rChild);
    // Mering left and right for parent node.
    segment[index].Square_Sum = segment[lChild].Square_Sum + segment[rChild].Square_Sum;
    segment[index].Sum = segment[lChild].Sum + segment[rChild].Sum;
  }


  void update_lazy_Update(int l, int r, int index)
  {
    // Passing the lazy value to node.
    segment[index].Square_Sum += (r - l + 1) * lazy[index].increment *  lazy[index].increment + 2 *  lazy[index].increment * segment[index].Sum;
    segment[index].Sum += lazy[index].increment * (r - l + 1);
    // Passing the lazy value to child nodes.
    if (l != r)
    {
      lazy[2 * index + 1].increment += lazy[index].increment;
      lazy[2 * index + 2].increment += lazy[index].increment;

    }
    // Setting 0 to the lazy value.
    lazy[index].increment = 0;
  }

  void update_lazy_Set(int l, int r, int index)
  {
    if (lazy[index].set != 0)
    {
      segment[index].Square_Sum = (r - l + 1) * lazy[index].set * lazy[index].set;
      segment[index].Sum = (r - l + 1) * lazy[index].set;

      if (l != r)
      {
        lazy[2 * index + 1].set = lazy[index].set;
        lazy[2 * index + 2].set = lazy[index].set;
        lazy[2 * index + 1].increment = 0;
        lazy[2 * index + 2].increment = 0;

      }
      lazy[index].set = 0;
    }
  }

  long long int query(int ql, int qr, int l, int r, int index = 0)
  {
    // Updating the lazy values.
    update_lazy_Set(l, r, index);
    update_lazy_Update(l, r, index);

    // Returning the sum of squares withing query.
    if (ql <= l && qr >= r)
    {
      return segment[index].Square_Sum;
    }

    int mid = (l + r) >> 1;

    if (mid < ql)
    {
      return query(ql, qr, mid + 1, r, 2 * index + 2);
    }

    if (mid + 1 > qr)
    {
      return query(ql, qr, l, mid, 2 * index + 1);
    }

    return query(ql, qr, l, mid, 2 * index + 1) + query(ql, qr, mid + 1, r, 2 * index + 2);

  }

  void update(int ql, int  qr, int x, int l, int r, int ch, int index = 0)
  {
    if (l > r)
      return ;

    update_lazy_Set(l, r, index);
    update_lazy_Update(l, r, index);


    if (l > qr || r < ql)
    {
      return ;
    }
    // Updating the node.
    if (ql <= l && qr >= r)
    {

      if (ch == 0)
      {
        segment[index].Square_Sum += (r - l + 1) * x *  x + 2 * x * segment[index].Sum;
        segment[index].Sum += x * (r - l + 1);

        // Passing the lazy values.
        if (l != r)
        {
          lazy[2 * index + 1].increment += x;
          lazy[2 * index + 2].increment += x;

        }

      }
      else
      {
        segment[index].Square_Sum = (r - l + 1) * x * x;
        segment[index].Sum = (r - l + 1) * x;

        if (l != r)
        {
          lazy[2 * index + 1].set = x;
          lazy[2 * index + 2].set = x;
          lazy[2 * index + 1].increment = 0;
          lazy[2 * index + 2].increment = 0;
        }
      }
      return ;
    }



    int mid = (l + r) >> 1;

    int lChild = 2 * index + 1;
    int rChild = 2 * index + 2;

    update(ql, qr, x, l, mid, ch, lChild);
    update(ql, qr, x, mid + 1, r, ch, rChild);
    // Updating the parent node.
    segment[index].Square_Sum = segment[lChild].Square_Sum + segment[rChild].Square_Sum;
    segment[index].Sum = segment[lChild].Sum + segment[rChild].Sum;
  }

};

vector<long long int> solve(int N, vector<int> &arr, int q, vector<vector<int>> &queries)
{
  // Creating Segment Tree.
  segmentTree tree(N);
  tree.buildtree(arr, 0, N - 1);
  vector<long long int>ans;

  for (int i = 0; i < q; i++)
  {
    // Calling update function of class.
    if (queries[i][0] == 1 || queries[i][0] == 0)
    {
      tree.update(queries[i][1], queries[i][2], queries[i][3], 0, N - 1, queries[i][0]);
    }
    // Calling query function of class.
    else
    {
      ans.push_back(tree.query(queries[i][1], queries[i][2], 0, N - 1));
    }
  }

  return ans;

}