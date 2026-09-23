# Tree Aggregate

**Input:** a binary tree encoded in preorder, using `-1` for an empty child.  
**Output:** height, sum, and inorder traversal.

Example:

```text
5 3 -1 -1 8 6 -1 -1 9 -1 -1
```

Output:

```text
height=3
sum=31
inorder=3 5 6 8 9
```

Each recursive call handles one subtree, giving `O(n)` time and `O(h)` call-stack space for tree height `h`.
