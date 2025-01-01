- Binary trees
  - traversal techniques
    - DFS
      - inorder
      - preorder
      - postorder (can be used for deletion of binary tree)
    - BFS (or) level order traversal
  - Serilization and deserialization of binary trees
    - https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
    - can we construct binary tree from inorder and preorder when the tree can have duplicates??
  - Lowest common ancestor (LCA) of two nodes in a binary tree
    - [LCA](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?page=2&company=Google&sortBy=submissions)
    - [lca.cpp](lca.cpp)


## problems
1) [Given inorder, preorder and postorder of a tree, check whether they are of same tree](https://www.geeksforgeeks.org/problems/check-tree-traversal--141628/1):
  - [my code](check_validity.cpp)
2) [Find inordered, preorder and postorder traversals of binary tree in one go](https://www.naukri.com/code360/problems/tree-traversal_981269)
  - [my code](all_traversals_in_one_go.cpp)
3) [Preorder traversal using stack](https://leetcode.com/problems/binary-tree-preorder-traversal/)
  - [Approach 1](iterative_pre_order_1.cpp)
    - O(H) auxillary space for stack, where H is the height of tree
    - O(n) time complexity
  - [Approach 2](iterative_pre_order_2.cpp)
    - O(H) auxillary space for stack, where H is the height of tree
    - O(n) time complexity
    - A simpler approach
4) [Inorder traversal using stack](https://leetcode.com/problems/binary-tree-inorder-traversal/)
  - [My solution](iterative_inorder_traversal.cpp)
    - O(H) auxillary space for stack, where H is the height of tree
    - O(n) time complexity
5) [Postorder traversal using stack](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)
  - [My solution](iterative_postorder_traversal.cpp)
    - O(H) auxillary space for stack, where H is the height of tree
    - O(n) time complexity