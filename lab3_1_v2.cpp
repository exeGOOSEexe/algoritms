class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def __find(self, node, parent, value):
        if node is None:
            return None, parent, False

        if value == node.data:
            return node, parent, True

        if value < node.data:
            if node.left:
                return self.__find(node.left, node, value)

        if value > node.data:
            if node.right:
                return self.__find(node.right, node, value)

        return node, parent, False

    def append(self, obj):
        if self.root is None:
            self.root = obj
            return obj

        s, p, fl_find = self.__find(self.root, None, obj.data)

        if not fl_find and s:
            if obj.data < s.data:
                s.left = obj
            else:
                s.right = obj

        return obj
    def show_wide_tree(self, node):
        if node is None:
            return

        v = [node]
        result = []
        while v:
            vn = []
            for x in v:
                result.append(str(x.data))
                if x.left:
                    vn.append(x.left)
                if x.right:
                    vn.append(x.right)
            v = vn
        print(" ".join(result))

def main(t):
    time = [1, 15, 2.0, 6.3, 0.3, (15, 43), "def", {15: 40}, [15, 20]]
    for i in time:
        if isinstance(i, (str, int, float, tuple)):
            t.append(Node(str(i)))
        else:
            continue

if __name__ == "__main__":
    t = Tree()
    main(t)
    t.show_wide_tree(t.root)
