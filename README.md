The following programs were written in C for CS211 Fall 2015.

##First: Looping
Program checks whether the number is prime or not.
Example Execution:
$./first 10
no
$./first 7
yes
$./first
error

##Second: Linked List
Program implements a linked list that maintains a list of integers in sorted order.
Example Execution:
Lets assume we have 3 text files with the following contents:
“file1.txt” is empty
file2.txt:
i 10
i 12
d 10
i 5
file3.txt:
d 7
i 10
i 5
i 10
d 10
Then the result will be:
$./second file1.txt
$./second file2.txt
5 12
$./second file3.txt
5
$./second file4.txt
error

##Third: Hash Table
A program that implements a hash table containing integers with 10,000 buckets. This hash table uses collision resolution.
Example Execution:
Lets assume we have 2 text files with the following contents:
“file1.txt” is empty
file2.txt:
i 10
i 12
s 10
c 5
i 10
s 5 The the results will be:
$./third file1.txt
$./third file2.txt
inserted
inserted
present
error
duplicate
absent
$./third file3.txt
error

##Fourth: Matrix Addition
A program that requires you to add 2 matrices.
Example Execution:
Lets assume we have a text file, file1.txt, with the following contents:
file1.txt:
3 3
1 1 1
1 1 1
1 1 1

1 1 1
1 1 1
1 1 1
Then the output will be:
$./fourth file1.txt
2 2 2
2 2 2
2 2 2

##Fifth: Matrix Multiplication
Program that multiplies two matrices.
Example Execution:
Lets assume we have ”file1.txt”:
3 2
4
2 2
2 2
2 2

2 3
1 1 1
1 1 1
The the output will be:
$./seventh file1.txt
4 4 4
4 4 4
4 4 4

##Sixth: String Operation
Reads input string and generates acryonm from first letter of the words, and prints out.
Example Execution:
$./sixth Hello World!
HW
$./sixth Welcome to CS211
WtC
$./sixth Rutgers Scarlet Knights
RSK

##Seventh: String Operations II
This program forms a word whose letters are the last letters or punctuation of the words of the given sentence.
Execution Example:
$./seventh Hello World!
o!
$./seventh Welcome to CS211
eo1
$./seventh Rutgers Scarlet Knights
sts

##Eighth: Binary Search Tree
Implements a Binary Search Tree
Example Execution:
Lets assume we have a file file1.txt with the following contents:
i 5
i 3
i 4
i 1
i 6
s 1
Executing the program in the following fashion should produce the output shown below:
$./eighth file1.txt
inserted 1
inserted 2
inserted 3
inserted 3
inserted 2
present 3
 
##Ninth: Binary Search Tree with Deletion
 Program executes a BST with the function to delete numbers.
 Lets assume we have a file file1.txt with the following contents:
i 5
i 3
i 4
i 1
i 6
i 2
s 1
d 3
s 4
Executing the program in the following fashion should produce the output shown below:
./ninth file1.txt
inserted 1
7
inserted 2
inserted 3
inserted 3
inserted 2
inserted 4
present 3
success
present 2
