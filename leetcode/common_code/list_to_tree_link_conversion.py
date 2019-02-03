#!/usr/bin/env python
# coding: utf-8

# ### To use just import this
# ```python
# from common_code.list_to_tree_link_conversion import convertListToTreeLinkNode
# ```
# 
# #### Note
# - Convert all 'null' values to 'None' in the list

# In[ ]:


class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None


def fillTreeWithData(data, loc):
    if loc > len(data) or data[loc - 1] is None:
        return None
    root = TreeLinkNode(data[loc - 1])
    root.left = fillTreeWithData(data, 2*loc)
    root.right = fillTreeWithData(data, (2*loc) + 1)
    return root


def convertListToTreeLinkNode(l):
    if len(l) == 0:
        return None
    return fillTreeWithData(l, 1)

