class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None

class KeyValueBST:
    def __init__(self):
        self.root = None

    def insert(self, key, value):
        if self.root is None:
            self.root = Node(key, value)
        else:
            self._insert_recursively(self.root, key, value)

    def _insert_recursively(self, current, key, value):
        if key < current.key:
            if current.left is None:
                current.left = Node(key, value)
            else:
                self._insert_recursively(current.left, key, value)
        elif key > current.key:
            if current.right is None:
                current.right = Node(key, value)
            else:
                self._insert_recursively(current.right, key, value)
        else:  # key already exists, update the value
            current.value = value

    def search(self, key):
        return self._search_recursively(self.root, key)

    def _search_recursively(self, current, key):
        if current is None:
            return None  # Key not found
        if key == current.key:
            return current.value  # Return the value associated with the key
        if key < current.key:
            return self._search_recursively(current.left, key)
        return self._search_recursively(current.right, key)

    def inorder(self):
        result = []
        self._inorder_recursively(self.root, result)
        return result

    def _inorder_recursively(self, current, result):
        if current:
            self._inorder_recursively(current.left, result)
            result.append((current.key, current.value))
            self._inorder_recursively(current.right, result)

    def find_min(self):
        return self._find_min_recursively(self.root)

    def _find_min_recursively(self, current):
        if current.left is None:
            return current
        return self._find_min_recursively(current.left)

    def delete(self, key):
        self.root = self._delete_recursively(self.root, key)

    def _delete_recursively(self, current, key):
        if current is None:
            return None
        if key < current.key:
            current.left = self._delete_recursively(current.left, key)
        elif key > current.key:
            current.right = self._delete_recursively(current.right, key)
        else:
            if current.left is None:
                return current.right
            if current.right is None:
                return current.left
            temp = self._find_min_recursively(current.right)
            current.key = temp.key
            current.value = temp.value
            current.right = self._delete_recursively(current.right, temp.key)
        return current

    def compare_equal(self, other):
        return self._compare_equal(self.root, other.root)

    def _compare_equal(self, current, other):
        if current is None and other is None:
            return True
        if current is None or other is None:
            return False
        return current.key == other.key and current.value == other.value and self._compare_equal(current.left, other.left) and self._compare_equal(current.right, other.right)



# Beispielverwendung:
bst = KeyValueBST()
bst.insert("apple", 100)
bst.insert("banana", 200)
bst.insert("cherry", 150)

print(bst.search("apple"))  # 100
print(bst.search("banana"))  # 200
print(bst.search("grape"))  # None

print(bst.inorder())  # [('apple', 100), ('banana', 200), ('cherry', 150)]

# Test compare_equal
bst2 = KeyValueBST()
bst2.insert("apple", 100)
bst2.insert("banana", 200)
bst2.insert("cherry", 150)
print(bst.compare_equal(bst2))  # True

#difference between Heap and Binary Search Tree is that Heap is a complete binary tree, but BST is not a complete binary tree.

# Komplexität:
# insert: O(h), h = Höhe des Baums
# search: O(h), h = Höhe des Baums
# inorder: O(n)
# find_min: O(h)
# delete: O(h)
# compare_equal: O(n)
# h = log(n) für balancierte Bäume, h = n für unbalancierte Bäume


