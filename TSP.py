class Node():
    def __init__(self,parent=None,position=None):
        self.parent=parent
        self.position=position
        self.gval=0
        self.hval=0
        self.fval=0
    def __eq__(self,other):
        return self.position==other.position
def astar(tsp,start,end):
    start_node=Node(None,start)
    end_node=Node(None,end)
    open=[]
    close=[]
    open.append(start_node)
    while len(open)>0:
        current_node=open[0]
        current_index=0
        for index,val in enumerate(open):
            if val.fval<current_node.fval:
                current_node=val
                current_index=index
        open.pop(current_index)
        close.append(current_node)
        if current_node==end_node:
            path=[]
            current=current_node
            while current is not None:
                path.append(current.position)
                current=current.parent
            return path[::-1]
        children=[]
        for new_position in [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])
            if node_position[0] > (len(tsp) - 1) or node_position[0] < 0 or node_position[1] > (len(tsp[len(tsp)-1]) -1) or node_position[1] < 0:
                continue
            if tsp[node_position[0]][node_position[1]] != 0:
                continue
            new_node = Node(current_node, node_position)
            children.append(new_node)
        for child in children:
            for closed_child in close:
                if child == closed_child:
                    continue
            child.gval = current_node.gval + 1
            child.hval = ((child.position[0] - end_node.position[0]) ** 2) + ((child.position[1] - end_node.position[1]) ** 2)
            child.fval = child.gval + child.hval
            for open_node in open:
                if child == open_node and child.gval > open_node.gval:
                    continue
            open.append(child)
def main():
    tsp =   [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
            [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]]
    start = (0, 0)
    end = (7, 9)
    path = astar(tsp, start, end)
    print(path)
if __name__ == '__main__':
    main()
