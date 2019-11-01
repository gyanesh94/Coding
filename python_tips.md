## Numbers

### Swapping 2 numbers

```python
>>> a = 5
>>> b = 10
>>> a, b = b, a
>>> a
10
>>> b
5
```

### Bitwise

```python
# Converting to bitwise
>>> bin(6)
'0b110'
>>> bin(6)[2:].zfill(8)
'00000110'
>>> f'{4:08b}'					# in python 3
'00000100'
>>> print('{0:08b}'.format(6))
00000110

# binary to int
>>> int('11111111', 2)
255


# x << y Returns x with the bits shifted to the left by y places (and new bits on the right-hand-side are zeros). This is the same as multiplying x by 2**y.
>>> 2 << 1
4
>>> 2 << 8
512
>>> -2 << 1
-4
>>> -2 << 8
-512

# x >> y Returns x with the bits shifted to the right by y places. This is the same as //'ing x by 2**y.
>>> 512 >> 1
256
>>> 512 >> 8
2
>>> -512 >> 8
-2
>>> -512 >> 1
-256

# x & y Does a "bitwise and". Each bit of the output is 1 if the corresponding bit of x AND of y is 1, otherwise it's 0.
>>> 1 & 2
0
>>> 4 & 5
4
>>> 4 & -5
0
>>> -4 & -5
-8
>>> -4 & -4
-4

# x | y Does a "bitwise or". Each bit of the output is 0 if the corresponding bit of x AND of y is 0, otherwise it's 1.
>>> 1 | 2
3
>>> 1 | -2
-1
>>> -1 | -2
-1
>>> -1 | -8
-1
>>> -9 | -8
-1


# ~ x. Returns the complement of x - the number you get by switching each 1 for a 0 and each 0 for a 1. This is the same as -x - 1.


# x ^ y Does a "bitwise exclusive or". Each bit of the output is the same as the corresponding bit in x if that bit in y is 0, and it's the complement of the bit in x if that bit in y is 1.


```



## List

### Functions available

```python
>>> l = []
>>> l
[]

# list.append(x). equivalent to a[len(a):] = [x]
>>> l.append(1)
>>> l
[1]
>>> l.append(2)
>>> l
[1, 2]

# list.extend(iterable). Equivalent to a[len(a):] = iterable or a[len(a):] = [x], (explained in comma)
>>> l.extend([12, 123])
>>> l
[1, 2, 12, 123]

# list.insert(i, x). Insert an item x at a given position i
>>> l
[2, 12, 123]
>>> l.insert(1, "hello")
>>> l
[2, 'hello', 12, 123]

# list.remove(x). Remove the first item from the list whose value is equal to x. It raises a ValueError if there is no such item
>>> l.remove(1)
>>> l
[2, 12, 123]
>>> l.remove(1123)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: list.remove(x): x not in list

# list.pop([i]) Remove the item at the given position in the list, and return it. If no index is specified, a.pop() removes and returns the last item in the list.
>>> l
[2, 'hello', 12, 123]
>>> l.pop(1)
'hello'
>>> l
[2, 12, 123]
>>> l.pop()
123
>>> l
[2, 12]

# list.clear(). Remove all items from the list. Equivalent to del a[:]

# list.index(x[, start[, end]])
# Return zero-based index in the list of the first item whose value is equal to x. Raises a ValueError if there is no such item.
# The optional arguments start and end are interpreted as in the slice notation and are used to limit the search to a particular subsequence of the list. The returned index is computed relative to the beginning of the full sequence rather than the start argument.

>>> l
[2, 12, 1, 2, 4, 5, 12, 1]
>>> l.index(2)
0
>>> l.index(2, 1)
3
>>> l.index(2, 1, 2)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: 2 is not in list

# list.count(x). Return the number of times x appears in the list
>>> l
[2, 12, 1, 2, 4, 5, 12, 1]
>>> l.count(1)
2
```



### Condition

```python
>>> e = list()
>>> e
[]
>>> if e:
...     print("true")
... else:
...     print("false")
...
false
```



### About the commas

Three people asked about them in the comments, so I'll also explain it here as well. I have these two basic cases:

```python
ranges += [],
r[1:] = n,
```

Why the trailing commas? Because it turns the right hand side into a tuple and I get the same effects as these more common alternatives:

```python
ranges += [[]]
or
ranges.append([])

r[1:] = [n]
```

Without the comma, ...

- `ranges += []` wouldn't add `[]` itself but only its elements, i.e., nothing.
- `r[1:] = n` wouldn't work, because my `n` is not an iterable.

```python
>>> r = [1, 2, 4]
>>> r
[1, 2, 4]
>>> r[2:]
[4]
>>> r[2:] = 10,
>>> r
[1, 2, 10]
>>> r[1:] = 10,
>>> r
[1, 10]
```

### Change Subset of List directly

```python
>>> r = [1, 2, 4, 5]
>>> r[1:2] = [10, 12]
>>> r
[1, 10, 12, 4, 5]
>>> r[1:3] = [100, 101]
>>> r
[1, 100, 101, 4, 5]
```

### List Comprehensions

```python
>>> squares = []
>>> for x in range(10):
...     squares.append(x**2)
...
>>> squares
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

# or, equivalently:

>>> squares = list(map(lambda x: x**2, range(10)))

# or, equivalently:

>>> squares = [x**2 for x in range(10)]
```



#### More examples creating tuple

```python
>>> vec = [-4, -2, 0, 2, 4]

# create a new list with the values doubled
>>> [x*2 for x in vec]
[-8, -4, 0, 4, 8]

# filter the list to exclude negative numbers
>>> [x for x in vec if x >= 0]
[0, 2, 4]

# apply a function to all the elements
>>> [abs(x) for x in vec]
[4, 2, 0, 2, 4]

# call a method on each element
>>> freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
>>> [weapon.strip() for weapon in freshfruit]
['banana', 'loganberry', 'passion fruit']

# create a list of 2-tuples like (number, square)
>>> [(x, x**2) for x in range(6)]
[(0, 0), (1, 1), (2, 4), (3, 9), (4, 16), (5, 25)]

# the tuple must be parenthesized, otherwise an error is raised
>>> [x, x**2 for x in range(6)]
  File "<stdin>", line 1, in <module>
    [x, x**2 for x in range(6)]
               ^
SyntaxError: invalid syntax

# flatten a list using a listcomp with two 'for'
>>> vec = [[1,2,3], [4,5,6], [7,8,9]]
>>> [num for elem in vec for num in elem]
[1, 2, 3, 4, 5, 6, 7, 8, 9]

# List comprehensions can contain complex expressions and nested functions
>>> from math import pi
>>> [str(round(pi, i)) for i in range(1, 6)]
['3.1', '3.14', '3.142', '3.1416', '3.14159']
```



#### Nested List Comprehensions

```python
>>> matrix = [
...     [1, 2, 3, 4],
...     [5, 6, 7, 8],
...     [9, 10, 11, 12],
... ]

# transpose rows and columns
>>> [[row[i] for row in matrix] for i in range(4)]
[[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
```





### List as Stack

```python
>>> stack = [3, 4, 5]
>>> stack.append(6)
>>> stack.append(7)
>>> stack
[3, 4, 5, 6, 7]
>>> stack.pop()
7
>>> stack
[3, 4, 5, 6]
>>> stack.pop()
6
>>> stack.pop()
5
>>> stack
[3, 4]
```



### Using Lists as Queues

It is also possible to use a list as a queue, where the first element added is the first element retrieved (“first-in, first-out”); however, lists are not efficient for this purpose. While appends and pops from the end of list are fast, doing inserts or pops from the beginning of a list is slow (because all of the other elements have to be shifted by one).

To implement a queue, use [`collections.deque`](https://docs.python.org/3/library/collections.html#collections.deque) which was designed to have fast appends and pops from both ends. For example:

```python
>>> from collections import deque
>>> queue = deque(["Eric", "John", "Michael"])
>>> queue.append("Terry")           # Terry arrives
>>> queue.append("Graham")          # Graham arrives
>>> queue.popleft()                 # The first to arrive now leaves
'Eric'
>>> queue.popleft()                 # The second to arrive now leaves
'John'
>>> queue                           # Remaining queue in order of arrival
deque(['Michael', 'Terry', 'Graham'])
```

## Set

### Initializing a Set

```python
# Empty Set
>>> a = set()
>>> a
set()

# With Values
# Method 1
>>> b = set([1, 2, "asd"])
>>> b
{1, 2, 'asd'}

# Method 2
>>> c = {1, 2, 'asd123'}
>>> c
{1, 2, 'asd123'}

# Set comprehenshion
>>> a = {x for x in 'abracadabra' if x not in 'abc'}
>>> a
{'r', 'd'}
```

### Add to set

```python
>>> a
set()
>>> a.add(1)
>>> a
{1}
>>> a.add("asd")
>>> a
{1, 'asd'}

# Only Immutable objects can be add. Since List is mutable it gives errror
>>> a.add([])
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: unhashable type: 'list'
```

### Remove From Set

```python
# Method 1 using remove
>>> c
{1, 2, 'asd123'}
>>> c.remove(1)
>>> c
{2, 'asd123'}

# if object is not present it will give an error
>>> c.remove("not present")
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 'not present'

# Method 2 using discard. It won't give an error if value is not present
>>> b
{1, 2, 'asd'}
>>> b.discard(2)
>>> b
{1, 'asd'}
>>> b.discard("not present")
>>> b
{1, 'asd'}


# Method 3 pop. It gives arbitrary value. Note if set is empty it raises error
>>> a
{1, 12, 'asd'}
>>> a.pop()
1
>>> a
{12, 'asd'}
>>> a.pop()
12
>>> a
{'asd'}
>>> a.pop()
'asd'
>>> a
set()
>>> a.pop()
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 'pop from an empty set'
```

### Mathematics on set

```python
>>> a = set('abracadabra')
>>> b = set('alacazam')
>>> a                                  # unique letters in a
{'a', 'r', 'b', 'c', 'd'}
>>> b                                  # unique letters in b
{'z', 'm', 'l', 'c', 'a'}

>>> a.difference(b)                    # letters in a but not in b
{'r', 'd', 'b'}
>>> a - b
{'r', 'd', 'b'}

>>> a.union(b)                         # letters in a or b or both
{'a', 'c', 'r', 'd', 'b', 'm', 'z', 'l'}
>>> a | b
{'a', 'c', 'r', 'd', 'b', 'm', 'z', 'l'}

>>> a.intersection(b)                  # letters in both a and b
{'a', 'c'}
>>> a & b
{'a', 'c'}

>>> a.symmetric_difference(b)          # letters in a or b but not both
{'r', 'd', 'b', 'm', 'z', 'l'}
>>> a ^ b                              # letters in a or b but not both
{'r', 'd', 'b', 'm', 'z', 'l'}

>>> a.isdisjoint(b)
False

>>> a.issubset(b)
False
>>> s
{1, 2, 3, 4}
>>> ss
{2, 3}
>>> s.issubset(ss)
False
>>> ss.issubset(s)
True
```

### Frozenset

Only immutable elements can be added to a set. So to make a nested set frozenset are used.

A frozenset is very similar to a set except that a frozenset is immutable.

```python
>>> temp = set()
>>> temp
set()
>>> temp.add(['a'])
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: unhashable type: 'list'
>>> set([['a']])
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: unhashable type: 'list'
>>> set(set([1, 2]))
{1, 2}
>>> set(set(set([1, 2])))
{1, 2}
    
# Using Frozenset
>>> set([frozenset('a')])						# add single element in list
{frozenset({'a'})}

>>> set([frozenset('a', 'b')])
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: frozenset expected at most 1 arguments, got 2

>>> set([frozenset(['a', 'b'])]) 		# to add multiple elements make them in list
{frozenset({'b', 'a'})}

>>> temp.add(frozenset([1, 2]))
>>> temp
{frozenset({1, 2})}
>>> temp.add(frozenset([1, 2]))		 # If added again they it will be discarded as duplicate
>>> temp
{frozenset({1, 2})}
```



### Notes

- Sets are unordered.



## Interesting Tips/Tricks

### ASCII

```python
>>> ord('A')
65
>>> chr(65)
A
```

### String

```python
# Output string Conditionally using * (condition)
>>> 'asdad' * (not 10 % 5)
'asdad'
>>> 'asdad' * (not 10 % 4)
''
```





## Interesting Facts

### Removing duplicates (Using Set is better)

```python
# Approach 1: Use a set to remove duplicates from a list.
>>> print(list(set([1, 2, 3, 1, 7])))
[1, 2, 3, 7]

# Approach 2: Use a list comprehension to remove duplicates from a list (If you would like a refresher on list comprehensions, see this tutorial).
>>> def remove_duplicates(original):
...     unique = []
...     [unique.append(n) for n in original if n not in unique]
...     return(unique)
...

>>> print(remove_duplicates([1, 2, 3, 1, 7]))
[1, 2, 3, 7]


# now if we timeit these 2 approaches. Approach 2 takes almost twice the time

>>> print(timeit.timeit('list(set([1, 2, 3, 1, 7]))', number=10000000))
7.4270955760002835

>>> print(timeit.timeit('remove_duplicates([1, 2, 3, 1, 7])', globals=globals(), number=10000000))
13.837052635999953
```



## Interesting Built-in Function

### [zip](https://docs.python.org/3/library/functions.html#zip)

Make an iterator that aggregates elements from each of the iterables.

Returns an **iterator of tuples**, where the *i*-th tuple contains the *i*-th element from each of the argument sequences or iterables. The iterator stops when the shortest input iterable is exhausted. 

**Implementation**

```python
def zip(*iterables):
    # zip('ABCD', 'xy') --> Ax By
    sentinel = object()
    iterators = [iter(it) for it in iterables]
    while iterators:
        result = []
        for it in iterators:
            elem = next(it, sentinel)
            if elem is sentinel:
                return
            result.append(elem)
        yield tuple(result)
```



**Example**

```python
>>> x = [1, 2, 3]
>>> y = [4, 5, 6]
>>> zipped = zip(x, y)
>>> list(zipped)
[(1, 4), (2, 5), (3, 6)]

# Reversing a zip. By * operator list is openend
>>> x2, y2 = zip(*zip(x, y))		# zip((1, 4), (2, 5), (3, 6))
>>> x2
(1, 2, 3)
>>> y2
(4, 5, 6)
>>> x == list(x2) and y == list(y2)
True

>>> x = "hello how"
>>> y = "are you"
>>> zip(x, y)
<zip object at 0x10a01c288>			# iterator of tuple used in for loop
>>> list(zip(x, y))
[('h', 'a'), ('e', 'r'), ('l', 'e'), ('l', ' '), ('o', 'y'), (' ', 'o'), ('h', 'u')]			# length is shortest of the string

# With list of strings
>>> a = ["abc", "def", "ghi"]
>>> a
['abc', 'def', 'ghi']
>>> list(zip(*a))
[('a', 'd', 'g'), ('b', 'e', 'h'), ('c', 'f', 'i')]
```

**Note**

To remove the limitation of shortest string use **itertools.zip_longest** explained in [Finite Iterators](#Finite%20Iterators)

It fills extra ones with None

```python
>>> from itertools import zip_longest
>>> x
'hello how'
>>> y
'are you'
>>> list(zip_longest(x, y))
[('h', 'a'), ('e', 'r'), ('l', 'e'), ('l', ' '), ('o', 'y'), (' ', 'o'), ('h', 'u'), ('o', None), ('w', None)]
```



### [sorted](https://docs.python.org/3/library/functions.html#sorted)

```python
>>> a = [1, 3, 2, 8, 0]
>>> sorted(a)
[0, 1, 2, 3, 8]
>>> sorted(a, reverse=True)
[8, 3, 2, 1, 0]

# always returns the list based on key, never change actual value
>>> a
[1, 3, 2, 8, 0]

>>> d = {1: 'a', 3: 'b', 2: 'e', 6: 'f', 0: 'a'}
>>> d
{1: 'a', 3: 'b', 2: 'e', 6: 'f', 0: 'a'}

# By default taken sort based on key
>>> sorted(d)
[0, 1, 2, 3, 6]
>>> sorted(d.values())
['a', 'a', 'b', 'e', 'f']

# keys
>>> sorted(d.items())
[(0, 'a'), (1, 'a'), (2, 'e'), (3, 'b'), (6, 'f')]

# based on values. If they are same then keys
>>> sorted(d.items(), key=lambda kv: (kv[1], kv[0]))
[(0, 'a'), (1, 'a'), (3, 'b'), (2, 'e'), (6, 'f')]
>>> d
{1: 'a', 3: 'b', 2: 'e', 6: 'f', 0: 'a'}
```



### [divmod](https://docs.python.org/3/library/functions.html#divmod)

Take two (non complex) numbers as arguments and return a pair of numbers consisting of their quotient and remainder when using integer division. With mixed operand types, the rules for binary arithmetic operators apply. For integers, the result is the same as (a // b, a % b). For floating point numbers the result is (q, a % b), where q is usually math.floor(a / b) but may be 1 less than that. In any case q * b + a % b is very close to a, if a % b is non-zero it has the same sign as b, and 0 <= abs(a % b) < abs(b).

```python
>>> divmod(7, 3)
(2, 1)
>>> divmod(7.1, 3)
(2.0, 1.0999999999999996)
```



### [enumerate](https://docs.python.org/3/library/functions.html#enumerate)

Return an enumerate object. iterable must be a sequence, an iterator, or some other object which supports iteration. The __next__() method of the iterator returned by enumerate() returns a tuple containing a count (from start which defaults to 0) and the values obtained from iterating over iterable.

```python
>>> seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]
```



## Interesting Modules

### [timeit](https://pymotw.com/3/timeit/)

[python3 doc](https://docs.python.org/3/library/timeit.html)

The `timeit` module provides a simple interface for determining the execution time of small bits of Python code



### [itertools](https://docs.python.org/3/library/itertools.html#module-itertools)

```python
>>> from itertools import *
```

#### Infinite Iterators

- itertools.count(start=0, step=1)
- itertools.cycle(iterable)
- itertools.repeat(object[, times])

```python
# itertools.count(start=0, step=1). Make an iterator that returns evenly spaced values starting with number start.
>>> count(10) --> 10 11 12 13 14 ...
>>> count(10, 2) --> 10 12 14 16 18 ...

# itertools.cycle(iterable) . Make an iterator returning elements from the iterable and saving a copy of each
>>> cycle('ABCD') --> A B C D A B C D ...

# itertools.repeat(object[, times]). Make an iterator that returns object over and over again. Runs indefinitely unless the times argument is specified.
>>> repeat(10) --> 10 10 10 10 ...
>>> repeat(10, 3) --> 10 10 10
```

#### Finite Iterators

- itertools.accumulate(iterable[, func])
- itertools.chain(*iterables)
- itertools.chain.from_iterable(iterable)
- itertools.compress(data, selectors)
- itertools.dropwhile(predicate, iterable)
- itertools.filterfalse(predicate, iterable)
- itertools.groupby(iterable, key=None)
- itertools.islice(iterable, stop)
- itertools.starmap(function, iterable)
- itertools.takewhile(predicate, iterable)
- itertools.tee(iterable, n=2)
- itertools.zip_longest(*iterables, fillvalue=None)

```python
# itertools.accumulate(iterable[, func]). p0, p0+p1, p0+p1+p2, … Make an iterator that returns accumulated sums, or accumulated results of other binary functions (specified via the optional func argument)

#implementation
def accumulate(iterable, func=operator.add):
    'Return running totals'
    # accumulate([1,2,3,4,5]) --> 1 3 6 10 15
    # accumulate([1,2,3,4,5], operator.mul) --> 1 2 6 24 120
    it = iter(iterable)
    try:
        total = next(it)
    except StopIteration:
        return
    yield total
    for element in it:
        total = func(total, element)
        yield total

>>> list(accumulate([1,2,3,4,5]))
[1, 3, 6, 10, 15]
>>> data = [3, 4, 6, 2, 1, 9, 0, 7, 5, 8]
>>> list(accumulate(data, operator.mul))     # running product
[3, 12, 72, 144, 144, 1296, 0, 0, 0, 0]
>>> list(accumulate(data, max))              # running maximum
[3, 4, 6, 6, 6, 9, 9, 9, 9, 9]

# Amortize a 5% loan of 1000 with 4 annual payments of 90
>>> cashflows = [1000, -90, -90, -90, -90]
>>> list(accumulate(cashflows, lambda bal, pmt: bal*1.05 + pmt))
[1000, 960.0, 918.0, 873.9000000000001, 827.5950000000001]


## itertools.chain(*iterables). Make an iterator that returns elements from the first iterable until it is exhausted, then proceeds to the next iterable, until all of the iterables are exhausted p0, p1, … plast, q0, q1, …

#Implemetation
def chain(*iterables):
    # chain('ABC', 'DEF') --> A B C D E F
    for it in iterables:
        for element in it:
            yield element

>>> list(chain('ABC', 'DEF'))
['A', 'B', 'C', 'D', 'E', 'F']


# chain.from_iterable(iterable). Alternate constructor for chain(). Gets chained inputs from a single iterable argument that is evaluated lazily

# Implementation
def from_iterable(iterables):
    # chain.from_iterable(['ABC', 'DEF']) --> A B C D E F
    for it in iterables:
        for element in it:
            yield element
>>> list(chain.from_iterable(['ABC', 'DEF']))
['A', 'B', 'C', 'D', 'E', 'F']


# itertools.compress(data, selectors)
# Make an iterator that filters elements from data returning only those that have a corresponding element in selectors that evaluates to True. (d[0] if s[0]), (d[1] if s[1]), …
>>> list(compress('ABCDEF', [1,0,1,0,1,1]))
['A', 'C', 'E', 'F']



# itertools.dropwhile(predicate, iterable)
# Make an iterator that drops elements from the iterable as long as the predicate is true; afterwards, returns every element. seq[n], seq[n+1], starting when pred fails
>>> list(dropwhile(lambda x: x<5, [1,4,6,4,1]))
[6, 4, 1]


# itertools.filterfalse(predicate, iterable)
# Make an iterator that filters elements from iterable returning only those for which the predicate is False. If predicate is None, return the items that are false.
# elements of seq where pred(elem) is false
>>> list(filterfalse(lambda x: x%2, range(10)))
[0, 2, 4, 6, 8]



# itertools.groupby(iterable, key=None)
# Make an iterator that returns consecutive keys and groups from the iterable. The key is a function computing a key value for each element. If not specified or is None, key defaults to an identity function and returns the element unchanged. Generally, the iterable needs to already be sorted on the same key function.

# sub-iterators grouped by value of key(v)

# [k for k, g in groupby('AAAABBBCCDAABBB')] --> A B C D A B
>>> [k for k, g in groupby('AAAABBBCCDAABBB')]
['A', 'B', 'C', 'D', 'A', 'B']

# [list(g) for k, g in groupby('AAAABBBCCD')] --> AAAA BBB CC D
>>> [list(g) for k, g in groupby('AAAABBBCCD')]
[['A', 'A', 'A', 'A'], ['B', 'B', 'B'], ['C', 'C'], ['D']]

>>> [k for k, g in groupby('122333446666667', key=lambda x: x if int(x) % 2 == 0 else None)]
[None, '2', None, '4', '6', None]
>>> [list(g) for k, g in groupby('122333446666667', key=lambda x: x if int(x) % 2 == 0 else None)]
[['1'], ['2', '2'], ['3', '3', '3'], ['4', '4'], ['6', '6', '6', '6', '6', '6'], ['7']]

>>> [k for k, g in groupby('122333446666667', key=lambda x: "Even" if int(x) % 2 == 0 else "Odd")]
['Odd', 'Even', 'Odd', 'Even', 'Odd']
>>> [list(g) for k, g in groupby('122333446666667', key=lambda x: "Even" if int(x) % 2 == 0 else "Odd")]
[['1'], ['2', '2'], ['3', '3', '3'], ['4', '4', '6', '6', '6', '6', '6', '6'], ['7']]


# itertools.islice(iterable, stop)
# itertools.islice(iterable, start, stop[, step])
# Make an iterator that returns selected elements from the iterable.
# elements from seq[start:stop:step]
>>> list(islice('ABCDEFG', 2, None))
['C', 'D', 'E', 'F', 'G']
>>> list(islice('ABCDEFG', 2, None, 2))
['C', 'E', 'G']


# itertools.starmap(function, iterable)
# Make an iterator that computes the function using arguments obtained from the iterable. Used instead of map() when argument parameters are already grouped in tuples from a single iterable (the data has been “pre-zipped”). The difference between map() and starmap() parallels the distinction between function(a,b) and function(*c)
# func(*seq[0]), func(*seq[1]), …

# Implementation
def starmap(function, iterable):
    # starmap(pow, [(2,5), (3,2), (10,3)]) --> 32 9 1000
    for args in iterable:
        yield function(*args)


>>> list(starmap(pow, [(2,5), (3,2), (10,3)]))
[32, 9, 1000]
>>> list(starmap(max, [(2,5), (3,2), (10,3)]))
[5, 3, 10]


# itertools.takewhile(predicate, iterable)
# Make an iterator that returns elements from the iterable as long as the predicate is true. Roughly equivalent to
# seq[0], seq[1], until pred fails

# Implementation
def takewhile(predicate, iterable):
    # takewhile(lambda x: x<5, [1,4,6,4,1]) --> 1 4
    for x in iterable:
        if predicate(x):
            yield x
        else:
            break

>>> list(takewhile(lambda x: x<5, [1,4,6,4,1]))
[1, 4]


# itertools.tee(iterable, n=2)
# Return n independent iterators from a single iterable.

# This itertool may require significant auxiliary storage (depending on how much temporary data needs to be stored). In general, if one iterator uses most or all of the data before another iterator starts, it is faster to use list() instead of tee().

# Implementation
def tee(iterable, n=2):
    it = iter(iterable)
    deques = [collections.deque() for i in range(n)]
    def gen(mydeque):
        while True:
            if not mydeque:             # when the local deque is empty
                try:
                    newval = next(it)   # fetch a new value and
                except StopIteration:
                    return
                for d in deques:        # load it to all the deques
                    d.append(newval)
            yield mydeque.popleft()
    return tuple(gen(d) for d in deques)

>>> [list(x) for x in tee("ab", 4)]
[['a', 'b'], ['a', 'b'], ['a', 'b'], ['a', 'b']]


# itertools.zip_longest(*iterables, fillvalue=None)
# Make an iterator that aggregates elements from each of the iterables. If the iterables are of uneven length, missing values are filled-in with fillvalue. Iteration continues until the longest iterable is exhausted.
# If one of the iterables is potentially infinite, then the zip_longest() function should be wrapped with something that limits the number of calls (for example islice() or takewhile()).
# If not specified, fillvalue defaults to None.

# Implementation
def zip_longest(*args, fillvalue=None):
    # zip_longest('ABCD', 'xy', fillvalue='-') --> Ax By C- D-
    iterators = [iter(it) for it in args]
    num_active = len(iterators)
    if not num_active:
        return
    while True:
        values = []
        for i, it in enumerate(iterators):
            try:
                value = next(it)
            except StopIteration:
                num_active -= 1
                if not num_active:
                    return
                iterators[i] = repeat(fillvalue)
                value = fillvalue
            values.append(value)
        yield tuple(values)

>>> list(zip_longest('hello how', 'are you'))
[('h', 'a'), ('e', 'r'), ('l', 'e'), ('l', ' '), ('o', 'y'), (' ', 'o'), ('h', 'u'), ('o', None), ('w', None)]
>>> list(zip_longest('hello how', 'are you', fillvalue=0))
[('h', 'a'), ('e', 'r'), ('l', 'e'), ('l', ' '), ('o', 'y'), (' ', 'o'), ('h', 'u'), ('o', 0), ('w', 0)]
```

#### Combinatoric iterators

- itertools.product(*iterables, repeat=1)
- itertools.permutations(iterable, r=None)
- itertools.combinations(iterable, r)
- itertools.combinations_with_replacement(iterable, r)



```python
# itertools.product(*iterables, repeat=1)
# Cartesian product of input iterables. Roughly equivalent to nested for-loops in a generator expression. For example, product(A, B) returns the same as ((x,y) for x in A for y in B).
# The nested loops cycle like an odometer with the rightmost element advancing on every iteration. This pattern creates a lexicographic ordering so that if the input’s iterables are sorted, the product tuples are emitted in sorted order.
# To compute the product of an iterable with itself, specify the number of repetitions with the optional repeat keyword argument. For example, product(A, repeat=4) means the same as product(A, A, A, A).

# Implementation
def product(*args, repeat=1):
    # product('ABCD', 'xy') --> Ax Ay Bx By Cx Cy Dx Dy
    # product(range(2), repeat=3) --> 000 001 010 011 100 101 110 111
    pools = [tuple(pool) for pool in args] * repeat
    result = [[]]
    for pool in pools:
        result = [x+[y] for x in result for y in pool]
    for prod in result:
        yield tuple(prod)

>>> list(product('ABCD', 'xy'))
[('A', 'x'), ('A', 'y'), ('B', 'x'), ('B', 'y'), ('C', 'x'), ('C', 'y'), ('D', 'x'), ('D', 'y')]
>>> list(product(range(2), repeat=3))
[(0, 0, 0), (0, 0, 1), (0, 1, 0), (0, 1, 1), (1, 0, 0), (1, 0, 1), (1, 1, 0), (1, 1, 1)]
>>> list(product('AB', repeat=2))
[('A', 'A'), ('A', 'B'), ('B', 'A'), ('B', 'B')]

# itertools.permutations(iterable, r=None)
# Return successive r length permutations of elements in the iterable.
# If r is not specified or is None, then r defaults to the length of the iterable and all possible full-length permutations are generated.
# Permutations are emitted in lexicographic sort order. So, if the input iterable is sorted, the permutation tuples will be produced in sorted order.
# The number of items returned is n! / (n-r)! when 0 <= r <= n or zero when r > n

# Implementation
def permutations(iterable, r=None):
    # permutations('ABCD', 2) --> AB AC AD BA BC BD CA CB CD DA DB DC
    # permutations(range(3)) --> 012 021 102 120 201 210
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    if r > n:
        return
    indices = list(range(n))
    cycles = list(range(n, n-r, -1))
    yield tuple(pool[i] for i in indices[:r])
    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                yield tuple(pool[i] for i in indices[:r])
                break
        else:
            return


>>> list(permutations('ABCD', 2))
[('A', 'B'), ('A', 'C'), ('A', 'D'), ('B', 'A'), ('B', 'C'), ('B', 'D'), ('C', 'A'), ('C', 'B'), ('C', 'D'), ('D', 'A'), ('D', 'B'), ('D', 'C')]
>>> list(permutations('ABB', 2))
[('A', 'B'), ('A', 'B'), ('B', 'A'), ('B', 'B'), ('B', 'A'), ('B', 'B')]


# itertools.combinations(iterable, r). Return r length subsequences of elements from the input iterable.
# Combinations are emitted in lexicographic sort order. So, if the input iterable is sorted, the combination tuples will be produced in sorted order.
# The number of items returned is n! / r! / (n-r)! when 0 <= r <= n or zero when r > n.

# Imlementation
def combinations(iterable, r):
    # combinations('ABCD', 2) --> AB AC AD BC BD CD
    # combinations(range(4), 3) --> 012 013 023 123
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = list(range(r))
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)

>>> list(combinations('ABCD', 2))
[('A', 'B'), ('A', 'C'), ('A', 'D'), ('B', 'C'), ('B', 'D'), ('C', 'D')]
>>> list(combinations('ABBD', 2))
[('A', 'B'), ('A', 'B'), ('A', 'D'), ('B', 'B'), ('B', 'D'), ('B', 'D')]


# itertools.combinations_with_replacement(iterable, r).
# Return r length subsequences of elements from the input iterable allowing individual elements to be repeated more than once.
# Combinations are emitted in lexicographic sort order. So, if the input iterable is sorted, the combination tuples will be produced in sorted order.

# Implementation
def combinations_with_replacement(iterable, r):
    # combinations_with_replacement('ABC', 2) --> AA AB AC BB BC CC
    pool = tuple(iterable)
    n = len(pool)
    if not n and r:
        return
    indices = [0] * r
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != n - 1:
                break
        else:
            return
        indices[i:] = [indices[i] + 1] * (r - i)
        yield tuple(pool[i] for i in indices)

>>> list(combinations_with_replacement('ABCD', 2))
[('A', 'A'), ('A', 'B'), ('A', 'C'), ('A', 'D'), ('B', 'B'), ('B', 'C'), ('B', 'D'), ('C', 'C'), ('C', 'D'), ('D', 'D')]


```

### [collections](https://docs.python.org/3/library/collections.html)

This module implements specialized container datatypes providing alternatives to Python’s general purpose built-in containers, [`dict`](https://docs.python.org/3/library/stdtypes.html#dict), [`list`](https://docs.python.org/3/library/stdtypes.html#list), [`set`](https://docs.python.org/3/library/stdtypes.html#set), and [`tuple`](https://docs.python.org/3/library/stdtypes.html#tuple).

| Class name | Description |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [`ChainMap`](https://docs.python.org/3/library/collections.html#collections.ChainMap) | dict-like class for creating a single view of multiple mappings |
| [`Counter`](https://docs.python.org/3/library/collections.html#collections.Counter) | dict subclass for counting hashable objects                  |
| [`defaultdict`](https://docs.python.org/3/library/collections.html#collections.defaultdict) | dict subclass that calls a factory function to supply missing values |
| [`deque`](https://docs.python.org/3/library/collections.html#collections.deque) | list-like container with fast appends and pops on either end |
| [`namedtuple()`](https://docs.python.org/3/library/collections.html#collections.namedtuple) | factory function for creating tuple subclasses with named fields |
| [`OrderedDict`](https://docs.python.org/3/library/collections.html#collections.OrderedDict) | dict subclass that remembers the order entries were added    |

```python
# collections.ChainMap(*maps)
# A ChainMap groups multiple dicts or other mappings together to create a single, updateable view. If no maps are specified, a single empty dictionary is provided so that a new chain always has at least one mapping.


>>> baseline = {'music': 'bach', 'art': 'rembrandt'}
>>> adjustments = {'art': 'van gogh', 'opera': 'carmen'}
>>> list(ChainMap(adjustments, baseline))
['music', 'art', 'opera']

# This gives the same ordering as a series of dict.update() calls starting with the last mapping
>>> combined = baseline.copy()
>>> combined.update(adjustments)
>>> list(combined)
['music', 'art', 'opera']



# collections.Counter([iterable-or-mapping])
# A Counter is a dict subclass for counting hashable objects. It is a collection where elements are stored as dictionary keys and their counts are stored as dictionary values. Counts are allowed to be any integer value including zero or negative counts.

>>> cnt = Counter()
>>> for word in ['red', 'blue', 'red', 'green', 'blue', 'blue']:
...     cnt[word] += 1
>>> cnt
Counter({'blue': 3, 'red': 2, 'green': 1})
>>> c = Counter('gallahad')                 # a new counter from an iterable
>>> c
Counter({'a': 3, 'l': 2, 'g': 1, 'h': 1, 'd': 1})

>>> c = Counter({'red': 4, 'blue': 2})      # a new counter from a mapping
>>> c
Counter({'red': 4, 'blue': 2})

>>> c = Counter(cats=4, dogs=8)             # a new counter from keyword args
>>> c
Counter({'dogs': 8, 'cats': 4})

>>> c = Counter(['eggs', 'ham'])
>>> c['bacon']                              # count of a missing element is zero
0

# elements() Return an iterator over elements repeating each as many times as its count. 
>>> c = Counter(a=4, b=2, c=0, d=-2)
>>> sorted(c.elements())
['a', 'a', 'a', 'a', 'b', 'b']

# most_common([n]) Return a list of the n most common elements and their counts from the most common to the least. 
>>> Counter('abracadabra').most_common(3)  # doctest: +SKIP
[('a', 5), ('r', 2), ('b', 2)]

# subtract([iterable-or-mapping]) Elements are subtracted from an iterable or from another mapping (or counter).
>>> c = Counter(a=4, b=2, c=0, d=-2)
>>> d = Counter(a=1, b=2, c=3, d=4)
>>> c.subtract(d)
>>> c
Counter({'a': 3, 'b': 0, 'c': -3, 'd': -6})


>>> c = Counter(a=3, b=1)
>>> d = Counter(a=1, b=2)
>>> c + d                       # add two counters together:  c[x] + d[x]
Counter({'a': 4, 'b': 3})
>>> c - d                       # subtract (keeping only positive counts)
Counter({'a': 2})
>>> c & d                       # intersection:  min(c[x], d[x]) # doctest: +SKIP
Counter({'a': 1, 'b': 1})
>>> c | d                       # union:  max(c[x], d[x])
Counter({'a': 3, 'b': 2})

# Intersection of Two Arrays II
# 1
C = collections.Counter
return list((C(nums1) & C(nums2)).elements())
# 2
a, b = map(collections.Counter, (nums1, nums2))
return list((a & b).elements())
# 3
return list((collections.Counter(nums1) & collections.Counter(nums2)).elements())

# class collections.deque([iterable[, maxlen]])
# Returns a new deque object initialized left-to-right (using append()) with data from iterable. If iterable is not specified, the new deque is empty.

>>> from collections import deque
>>> d = deque('ghi')                 # make a new deque with three items
>>> for elem in d:                   # iterate over the deque's elements
...     print(elem.upper())
G
H
I

>>> d.append('j')                    # add a new entry to the right side
>>> d.appendleft('f')                # add a new entry to the left side
>>> d                                # show the representation of the deque
deque(['f', 'g', 'h', 'i', 'j'])

>>> d.pop()                          # return and remove the rightmost item
'j'
>>> d.popleft()                      # return and remove the leftmost item
'f'
>>> list(d)                          # list the contents of the deque
['g', 'h', 'i']
>>> d[0]                             # peek at leftmost item
'g'
>>> d[-1]                            # peek at rightmost item
'i'

>>> list(reversed(d))                # list the contents of a deque in reverse
['i', 'h', 'g']
>>> 'h' in d                         # search the deque
True
>>> d.extend('jkl')                  # add multiple elements at once
>>> d
deque(['g', 'h', 'i', 'j', 'k', 'l'])
>>> d.rotate(1)                      # right rotation
>>> d
deque(['l', 'g', 'h', 'i', 'j', 'k'])
>>> d.rotate(-1)                     # left rotation
>>> d
deque(['g', 'h', 'i', 'j', 'k', 'l'])

>>> deque(reversed(d))               # make a new deque in reverse order
deque(['l', 'k', 'j', 'i', 'h', 'g'])
>>> d.clear()                        # empty the deque
>>> d.pop()                          # cannot pop from an empty deque
Traceback (most recent call last):
    File "<pyshell#6>", line 1, in -toplevel-
        d.pop()
IndexError: pop from an empty deque

>>> d.extendleft('abc')              # extendleft() reverses the input order
>>> d
deque(['c', 'b', 'a'])


# collections.defaultdict([default_factory[, ...]])
# Returns a new dictionary-like object. defaultdict is a subclass of the built-in dict class. It overrides one method and adds one writable instance variable. The remaining functionality is the same as for the dict class and is not documented here.

>>> s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
>>> d = defaultdict(list)
>>> for k, v in s:
...     d[k].append(v)
...
>>> sorted(d.items())
[('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]

# This technique is simpler and faster than an equivalent technique using dict.setdefault()
>>> d = {}
>>> for k, v in s:
...     d.setdefault(k, []).append(v)
...
>>> sorted(d.items())
[('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]

      w
# namedtuple(typename, field_names, *, rename=False, defaults=None, module=None)
# Named tuples assign meaning to each position in a tuple and allow for more readable, self-documenting code.
# Returns a new tuple subclass named typename. The new subclass is used to create tuple-like objects that have fields accessible by attribute lookup as well as being indexable and iterable. Instances of the subclass also have a helpful docstring (with typename and field_names) and a helpful __repr__() method which lists the tuple contents in a name=value format.

>>> # Basic example
>>> Point = namedtuple('Point', ['x', 'y'])
>>> p = Point(11, y=22)     # instantiate with positional or keyword arguments
>>> p[0] + p[1]             # indexable like the plain tuple (11, 22)
33
>>> x, y = p                # unpack like a regular tuple
>>> x, y
(11, 22)
>>> p.x + p.y               # fields also accessible by name
33
>>> p                       # readable __repr__ with a name=value style
Point(x=11, y=22)

# Named tuples are especially useful for assigning field names to result tuples returned by the csv or sqlite3 modules:

EmployeeRecord = namedtuple('EmployeeRecord', 'name, age, title, department, paygrade')

import csv
for emp in map(EmployeeRecord._make, csv.reader(open("employees.csv", "rb"))):
    print(emp.name, emp.title)

import sqlite3
conn = sqlite3.connect('/companydata')
cursor = conn.cursor()
cursor.execute('SELECT name, age, title, department, paygrade FROM employees')
for emp in map(EmployeeRecord._make, cursor.fetchall()):
    print(emp.name, emp.title)


# classmethod somenamedtuple._make(iterable) Class method that makes a new instance from an existing sequence or iterable.
>>> t = [11, 22]
>>> Point._make(t)
Point(x=11, y=22)

# somenamedtuple._asdict() Return a new dict which maps field names to their corresponding values:
>>> p = Point(x=11, y=22)
>>> p._asdict()
OrderedDict([('x', 11), ('y', 22)])

# somenamedtuple._replace(**kwargs) Return a new instance of the named tuple replacing specified fields with new values:
>>> p = Point(x=11, y=22)
>>> p._replace(x=33)
Point(x=33, y=22)

>>> for partnum, record in inventory.items():
...     inventory[partnum] = record._replace(price=newprices[partnum], timestamp=time.now())


#somenamedtuple._fields Tuple of strings listing the field names. Useful for introspection and for creating new named tuple types from existing named tuples.
>>> p._fields            # view the field names
('x', 'y')

>>> Color = namedtuple('Color', 'red green blue')
>>> Pixel = namedtuple('Pixel', Point._fields + Color._fields)
>>> Pixel(11, 22, 128, 255, 0)
Pixel(x=11, y=22, red=128, green=255, blue=0)

# somenamedtuple._field_defaults Dictionary mapping field names to default values.
>>> Account = namedtuple('Account', ['type', 'balance'], defaults=[0])
>>> Account._field_defaults
{'balance': 0}
>>> Account('premium')
Account(type='premium', balance=0)

# To retrieve a field whose name is stored in a string, use the getattr() function:
>>> getattr(p, 'x')
11

# To convert a dictionary to a named tuple, use the ** operator (as described in Unpacking Argument Lists):
>>> d = {'x': 11, 'y': 22}
>>> Point(**d)
Point(x=11, y=22)

# class collections.OrderedDict([items])
'''
Ordered dictionaries are just like regular dictionaries but have some extra capabilities relating to ordering operations. They have become less important now that the built-in dict class gained the ability to remember insertion order (this new behavior became guaranteed in Python 3.7).

Some differences from dict still remain:
- The regular dict was designed to be very good at mapping operations. Tracking insertion order was secondary.
- The OrderedDict was designed to be good at reordering operations. Space efficiency, iteration speed, and the performance of update operations were secondary.
- Algorithmically, OrderedDict can handle frequent reordering operations better than dict. This makes it suitable for tracking recent accesses (for example in an LRU cache).
- The equality operation for OrderedDict checks for matching order.
- The popitem() method of OrderedDict has a different signature. It accepts an optional argument to specify which item is popped.
- OrderedDict has a move_to_end() method to efficiently reposition an element to an endpoint.
- Until Python 3.8, dict lacked a __reversed__() method.
'''
```

