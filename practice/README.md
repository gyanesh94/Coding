###[Question 1](./question1.cpp) 
#####Check if given four points form a square


    Given coordinates of four points in a plane, find if the four points
    form a square or not.
	
	Input:
	The first line of input contains an integer T denoting the number of
	test cases. Then T test cases follow. The first line of each test
	case contains 4 space separated integer points a , b , c , d
	
	Output:
	For each test case print 1 if the four points form a square else
	print 0.
	
	Remember to output the answer of each test case in a new line.
	
	Constraints:
	1<=T<=100
	1<=a,b,c,d<=100
	
	Example:
	
	Input:
	2
	20 20 20 10 10 20 10 10
	10 10 10 10 20 10 20 30

	Output:
	1
	0
	
	**Note - Use squres instead of square root to get correct result		

<br>

###[Question 2](./question2.cpp)
#####Overlapping rectangles


    Given two rectangles, find if the given two rectangles overlap or
    not. A rectangle is denoted by providing the x and y co-ordinates
    of two points: the left top corner and the right bottom corner
    of the rectangle.

    Note that two rectangles sharing a side are considered overlapping.

    rectanglesOverlap

    Input:

    The first integer T denotes the number of test cases. For every test
    case, there are 2 lines of input. The first line consists of 4
    integers: denoting the co-ordinates of the 2 points of the first
    rectangle. The first integer denotes the x co-ordinate and the
    second integer denotes the y co-ordinate of the left topmost
    corner of the first rectangle. The next two integers are the x
    and y co-ordinates of right bottom corner. Similarly, the second
    line denotes the cordinates of the two points of the second
    rectangle.


    Output:

    For each test case, output (either 1 or 0) denoting whether the 2
    rectangles are overlapping. 1 denotes the rectangles overlap whereas
    0 denotes the rectangles do not overlap.


    Constraints:

    1 <= T <= 10

    -10000 <= x,y <= 10000

    T denotes the number of test cases. x denotes the x co-ordinate and
    y denotes the y co-ordinate.


    Example:

    Input:

    4
    0 10 10 0
    5 5 15 0
    0 2 1 1
    -2 -3 0 2
    0 2 1 1
    -2 3 0 2
    0 10 10 0
    5 5 15 0

    Output:

    1
    0
    0
    1
    
    **Note - It is on assumption that line or point touching is not
    considered as overlapping. If it is than add '=' in method 1 or
    remove '=' in method 2
    
<br>

###[Question 3](./question3.cpp)
#####Equal to product


    Given an array of integers check whether there are two numbers
    present with given product.
    
    Input:
    
    The first line of input contains an integer T denoting the number
    of test cases.
    The first line of each test case is N and a product p.
    The second line of each test case contain N number of a[].
    
    Output:
    Print Yes if two numbers product is equal to p else No.
    
    Constraints:
    
    1 ≤ T ≤ 51
    1 ≤ N ≤ 100
    0 ≤ a[] ≤ 1000
    1 ≤ pro ≤ 2000000
    
    Example:
    
    Input:

    7
    5 2
    1 2 3 4 5
    8 46
    5 7 9 22 15 344 92 8
    2 4
    2 2
    2 4
    2 1
    2 0
    2 1
    2 0
    0 1
    2 2
    0 1
    
    Output:
    
    Yes
    No
    Yes
    No
    No
    Yes
    No
    
    **Note - Each element is taken once

<br>

###[Question 4](./question4.cpp)
#####Add two numbers represented by linked lists | Set 2


    Given two numbers represented by two linked lists, write a function
    that returns sum list. The sum list is linked list representation
    of addition of two input numbers. It is not allowed to modify the
    lists. Also, not allowed to use explicit extra space
    (Hint: Use Recursion).
    
    Example
    
    Input:
      First List: 5->6->3  // represents number 563
      Second List: 8->4->2 //  represents number 842
    Output
      Resultant list: 1->4->0->5  // represents number 1405

<br>

###[Question 5](./question5.cpp)
#####Reverse a Linked List


    Given a linked list, write a function to reverse it
    (where k is an input to the function).
    
    Example:
    Inputs:  1->2->3->4->5->6->7->8->NULL 
    Output:  8->7->6->5->4->3->2->1->NULL. 

<br>

###[Question 6](./question6.cpp)
#####Reverse a Linked List in groups of given size


    Given a linked list, write a function to reverse every k nodes
    (where k is an input to the function).
    
    Example:
    Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
    Output:  3->2->1->6->5->4->8->7->NULL. 
    
    Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
    Output:  5->4->3->2->1->8->7->6->NULL.