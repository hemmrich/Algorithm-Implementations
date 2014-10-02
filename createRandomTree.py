import random

class Node:
    '''Node contains value, left child, and right child'''

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        
    def insert(self,  value):
        if value < self.value:
            if self.left is not None:
                self.left.insert(value)
            else:
                self.left = Node(value)
                print str(value) + ' is left child of ' + str(self.value)
        else:
            if self.right is not None:
                self.right.insert(value)
            else:
                self.right = Node(value)
                print str(value) + ' is right child of ' + str(self.value)
                
def createTree(root, numElts):
    for i in range(1, numElts):
        root.insert(random.randrange(0, 21))

def getBinaryTree(numElts, randSeed):
    random.seed(randSeed)
    root = Node(random.randrange(0, 21))
    createTree(root, numElts)
    return root
    



