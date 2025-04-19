# My linked list  
 This is my own implementation of a template-based doubly linked list  

## Features & Tools Used
- __Valgrind__ - no memory leaks.  
- __Google Test__ - the entire basic interface is covered with unit tests.

## Interface
- List() - default constructor, creates an empty list  
- List(T obj) - constructs a list with a single element  
- ~List()	- destructor, deletes all nodes, fully deallocates  
- T& front() - returns a reference to the first element  
- T& back() - returns a reference to the last element  
- bool is_empty() - checks if the list is empty  
- void push_back(T obj) - inserts a new element at the end of the list  
