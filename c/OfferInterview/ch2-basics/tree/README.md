# Tree

## Implementation  
```C
struct TreeNode{
	ElementType Element;
	PtrToNode FirstChild;
	PtrToNode NextSibling;
}
```
## Traversals
+ Preorder
+ Postorder
+ Inorder

## Binary Tree
+ 普通二叉树

	+ 完全二叉树: 只有最后一层有空的

	+ 不完全二叉树:


## Binary Search Tree(二叉搜索树)

左节点小于等于根节点; 右节点大于等于根节点

所有指令运行时间大概是O(D=O(logN)): D为二叉树的深度


## AVL Tree

左子树的节点数与右节点的节点数最多相差1

### 多出两个函数

+ Single Rotation

面对左子树的左节点 或者 右子树的右节点

+ Double Rotation

面对左子树的右节点 或者 右子树的左节点

## Splay Tree(伸展树)

每访问一个节点, 就用AVL的Rotation策略重新解构树, 让其更靠近根节点

但是略有不同的是: Zig-Zag情况

保证了M个连续操作, 其复杂度为Mlog(N)

虽然单个操作的复杂度可能为O(N)


## B Tree

不是二叉树, Order M表示其子节点数在2-M之间









## 红黑树
