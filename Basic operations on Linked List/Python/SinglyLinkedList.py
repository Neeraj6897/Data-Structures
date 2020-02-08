class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head;
        while(temp):
            print(temp.data, end=" ")
            temp = temp.next
        print("\n")
            
    def insert_start(self, value):
        temp = Node(value)
        temp.next = self.head
        self.head = temp
        
    def insert_end(self, value):
        temp = Node(value)
        if self.head is None:   #If list is empty
            self.head = temp
        
        current = self.head
        while(current.next):    #Else iterate in list to the last
            current = current.next
        current.next = temp
        temp.next = None
        
    def insert_at_pos(self, pos, value):
        temp = Node(value)
        cur = self.head
        count = 0
        while(cur.next):
            count = count+1
            cur = cur.next
        if((count+1)>=pos and pos !=1 ):   
            cur = self.head
            for i in range (1,pos):
                pre = cur
                cur = cur.next
            pre.next = temp
            temp.next = cur
        
        elif(pos==1):
            self.insert_start(value)
        
        else:
            print("Position should be less than",count+2)
            
    def delete_first(self):
        temp = self.head
        self.head = temp.next
        
    def delete_last(self):
        cur = self.head
        while(cur.next):
            pre = cur
            cur = cur.next
        pre.next = None
        
    def delete_at_pos(self, pos):
        cur = self.head
        count = 0
        while(cur.next):
            count = count+1
            cur = cur.next
        
        if(pos==1):
            self.delete_first()
            
        elif((count+1)>=pos and pos !=1 ):   
            cur = self.head
            for i in range (1,pos):
                pre = cur
                cur = cur.next
            pre.next = cur.next
        
        else:
            print("Position should be less than ", count+2)
            
    def reverse_list(self):
        cur = self.head
        pre = None
        while(cur):
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        self.head = pre
        
if __name__ == '__main__':
    
    element = LinkedList()
    element.head = Node(9)
    element.insert_start(8)
    element.insert_end(10)
    element.insert_at_pos(1,18)
    element.printList()
    element.reverse_list()
    element.printList()


