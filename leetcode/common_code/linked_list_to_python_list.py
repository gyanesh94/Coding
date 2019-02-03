#!/usr/bin/env python
# coding: utf-8

# ### To use just import this
# ```python
# from common_code.linked_list_to_python_list import convertLinkedListToList
# ```

# In[1]:


def convertLinkedListToList(l):
    if not l:
        return None
    output = []
    while l:
        output.append(l.val)
        l = l.next
    return output

