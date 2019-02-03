#!/usr/bin/env python
# coding: utf-8

# ### To use just import this
# ```python
# from common_code.python_list_to_linked_list import convertListToLinkedList
# ```

# In[ ]:


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def convertListToLinkedList(l):
    if len(l) == 0:
        return None
    startNode = ListNode(l[0])
    currentNode = startNode
    for i in range(1, len(l)):
        currentNode.next = ListNode(l[i])
        currentNode = currentNode.next
    return startNode

