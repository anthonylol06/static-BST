# Static Balanced BST


## General description
This is a mini-project to build up a balanced BST and make predecessor query. This is an efficient way to process predecessor query and construct balanced BST without any balancing like in AVL tree. 


## Test case
The following test case has been provided on ```sample``` file

Let say ```ds.txt``` has the example case
> 25
> 81
> 47
> 23
> 59

Then, the ```qs.txt``` has 5 queries with the following example
> qry 95
> qry 23
> qry 7
> qry 57
> qry 72

Finally, ```output.txt``` returns

> 81
> 23
> no
> 47
> 59

## How to run proj.cpp
```
$ Make
$ ./proj
```


## Note to anyone who seeing this
```ds-half.txt``` and ```qs-half.txt``` has only half of the data (which is 500,000 integers). 
```randomtest``` folder has full size of the data set (which is 1 million integers) generated by simple program. 
There also some results generated by the proj.cpp inside all random tests.
Remember to change the file name in ```proj.cpp``` if you would use different test cases.

Good luck to all learning data structures and algorithms!