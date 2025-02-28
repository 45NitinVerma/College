# Trees in Data Structures (Hinglish mein samajhiye)

## Introduction to Trees
- **Tree Definition**: Ek tree ek hierarchical data structure hai jo nodes ke form mein organized hota hai. Tree ke andar ek root node hota hai aur usse connected child nodes hote hain.
- **Uses**: Trees ka use searching, sorting, hierarchical data representation (like file systems), aur Huffman coding jaise tasks mein hota hai.

### Basic Terminology
1. **Node**: Tree ka basic element, jo data aur pointers store karta hai.
2. **Root**: Tree ka sabse pehla node.
3. **Parent**: Ek node jo kisi doosre node ko directly refer karta hai.
4. **Child**: Ek node jo kisi parent se connected hota hai.
5. **Leaf Node**: Ek node jo kisi child ko point nahi karta.
6. **Height**: Tree ke root se sabse door wali leaf node tak ki depth.
7. **Degree**: Kisi node ke child nodes ki total sankhya.
8. **Path**: Ek sequence of nodes jo ek node se doosri tak jaata hai.

---

## Binary Trees

Binary Tree ek aisa tree hai jisme har node ke paas maximum do child nodes ho sakte hain: **left child** aur **right child**.

### Representation of Binary Tree
1. **Array Representation**:
   - Tree ko ek array mein represent kiya jaata hai.
   - Example:
     - Root node array ke index 1 par hoti hai.
     - Left child at index `2*i` aur right child at index `2*i + 1` (agar node index `i` par hai).
   
   Example Tree:
   ```
       10
      /  \
     20   30
    / \    
   40  50
   ```
   Array Representation: [10, 20, 30, 40, 50]

2. **Pointer Representation (Linked List)**:
   - Har node ke paas ek data field aur do pointer fields hote hain (left aur right children ke liye).
   
---

## Binary Search Tree (BST)
Binary Search Tree ek special binary tree hai jisme:
- Left subtree ke sabhi nodes root se chhote hote hain.
- Right subtree ke sabhi nodes root se bade hote hain.
- No duplicates allowed

**Advantages**:
- Searching aur insertion fast hoti hai (O(log n)).

**Example**:
```
       50
      /  \
    30    70
   / \   / \
  20 40 60 80
```

---

## Types of Binary Trees
1. **Strictly Binary Tree**:
   - Har node ya toh 2 children rakhta hai ya koi bhi nahi.

2. **Complete Binary Tree**:
   - Saare levels poore tarah filled hote hain except last level, jo left se fill hota hai.

3. **Extended Binary Tree**:
   - Extra "dummy nodes" add kiye jaate hain jisme sabhi leaf nodes ek level par hoti hain.

---

## Tree Traversal Algorithms
Traversal ka matlab tree ke sabhi nodes ko ek sequence mein visit karna.

1. **Inorder Traversal (LNR)**:
   - Left subtree -> Node -> Right subtree.
   - Example: Agar tree hai:
     ```
         1
        / \
       2   3
      /
     4
     ```
     Traversal: 4, 2, 1, 3

2. **Preorder Traversal (NLR)**:
   - Node -> Left subtree -> Right subtree.
   - Traversal: 1, 2, 4, 3

3. **Postorder Traversal (LRN)**:
   - Left subtree -> Right subtree -> Node.
   - Traversal: 4, 2, 3, 1

---

## Constructing Binary Tree from Traversals
- Agar humein Inorder aur Preorder traversal diye gaye hain, toh hum unique tree construct kar sakte hain.
- Example:
  - Inorder: [D, B, E, A, F, C]
  - Preorder: [A, B, D, E, C, F]

---

## Binary Search Tree Operations
1. **Insertion Algorithm**:
   1. Start from root
   2. If `value < current node`, go left
   3. If `value > current node`, go right
   4. If empty position found, insert
   5. Repeat until inserted

2. **Deletion**:
   1. Find node to delete
   2. Case 1: Leaft node - Simply remove
   3. Case 3: Two children
      - Find inorder successor 
      - Replace node with successor
      - Delete successor

3. **Searching**:
   - Target value ke liye tree traverse karte hain (O(log n)).

4. **Modification**:
   - Kisi node ka data update karte hain.

---

## Threaded Binary Trees
- Ek binary tree jisme har NULL pointer ko kisi predecessor ya successor node ki taraf point karte hain.
- Traversal fast hota hai kyunki pointers direct traversal mein help karte hain.

### Traversing Threaded Binary Trees
1. Start from smallest node.
2. Successor pointer ko follow karte jaaiye.

---

## Huffman Coding
- Ek binary tree ka use karke lossless data compression achieve kiya jaata hai.
- Process:
  1. Characters aur unki frequencies ke according nodes banaiye.
  2. Sabse chhoti 2 frequencies ko merge karke ek tree banaiye.
  3. Repeat till ek hi tree bache.

**Algorithm**:
1. Frequency count karo 
2. Min heap banao
3. Do minimum nodes combine karo 
4. New internal node banao
5. Repeat until single tree forms 
6. 0/1 codes assign karo (left=0, right=1)

---

## AVL Trees
- Ek self-balancing binary search tree jisme har node ke left aur right subtrees ke heights ka difference zyada se zyada 1 hota hai.
- **Rotations** (Left, Right, Left-Right, Right-Left) ka use balance karne ke liye hota hai.
- **Balance Factor = left subtree height - right subtree height**

---

## B-Trees
- Ek generalized form of binary search trees jo disk-based storage ke liye efficient hai.
- Har node ke multiple children hote hain (balance aur disk I/O optimize hota hai).

---

## Binary Heaps
- Ek complete binary tree jo min-heap ya max-heap property ko follow karta hai.
- Use: Priority queues banane ke liye.

---

Yeh saari information trees ke concepts ko acche se samajhne ke liye kaafi hai. Agar diagrams ya further examples chahiye ho toh batayein!

