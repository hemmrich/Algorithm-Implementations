import createRandomTree as tree
import Queue

'''BFS uses a FIFO structure (queue)'''
numNodes = 50
randSeed = 1
goal = 6 #arbitrarily defined

root = tree.getBinaryTree(numNodes, randSeed)

queue = Queue.Queue()

queue.put(root)
counter = 0
while not queue.empty():
    print 'Iteration ' + str(counter)
    counter += 1

    tmp = queue.get()
    if tmp.left is not None:
        if tmp.left.value == goal:
            print 'GOAL (' + str(goal) + ') found!'
            exit()
        else:
            queue.put(tmp.left)
    if tmp.right is not None:
        if tmp.right.value == goal:
            print 'GOAL (' + str(goal) + ') found!'
            exit()
        else:
            queue.put(tmp.right)


