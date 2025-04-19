# My linked list  
 This is my own implementation of a template-based doubly linked list  

## Features & Tools Used
- __Valgrind__ - no memory leaks.  
- __Google Test__ - the entire basic interface is covered with unit tests.

## Interface
- __List()__ - default constructor, creates an empty list  
- __List(T obj)__ - constructs a list with a single element  
- __~List()__	- destructor, deletes all nodes, fully deallocates  
- __T& front()__ - returns a reference to the first element  
- __T& back()__ - returns a reference to the last element  
- __bool is_empty()__ - checks if the list is empty  
- __void push_back(T obj)__ - inserts a new element at the end of the list  
