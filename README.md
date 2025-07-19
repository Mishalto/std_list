# My Linked List

This is my own implementation of a template-based doubly linked list, without using `std`.  

## Features & Tools Used

- **Valgrind**: No memory leaks.
```bash
in use at exit: 0 bytes in 0 blocks
total heap usage: 335 allocs, 335 frees, 127,066 bytes allocated

All heap blocks were freed - no leaks are possible

For lists of detected and suppressed errors, rerun with: -s
ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

- **Google Test**: The entire basic interface is covered with unit tests.
```cpp
TEST(MyList, push_back) {
    List<int> list;
    list.push_back(4);
    ASSERT_EQ(list.back(), 4);

    list.push_back(2);
    ASSERT_EQ(list.back(), 2);
    ASSERT_EQ(list.front(), 4);
}
```

## Interface

- `List()`                        - Default constructor, creates an empty list.
- `List(const T& obj)`            - Constructs a list with a single element.
- `List(const List &other)`       — Copy constructor
- `List& operator=(const List& other)` - Copy assigment constructor
- `~List()`                       - Destructor, deletes all nodes, fully deallocates memory.
- `void clear()`                  - Destruct list   
- `T& front()`                    - Returns a reference to the first element.
- `T& back()`                     - Returns a reference to the last element.
- `bool is_empty()`               - Checks if the list is empty.
- `void push_back(const T& obj)`  - Inserts a new element at the end of the list.
- `void pop_back()`               - Delete last element
- `void push_front(const T& obj)` - Inserts a new element at the head.
- `void pop_front()`              - Delete first element
- `size_t size()`                 - Return list size

## Notes  

I know std::list overloads operators like front, back and other,
but I see no point in overloading them here since my project isn't for development purposes.



## Example Usage

```cpp
List<int> list;
list.push_back(10);
std::cout << list.back() << '\n'       // Output: 10
std::cout << list.is_empty() << '\n'   // Output: 0
```
## Build and Run

To build and run the project, follow these steps:

1. **Requirements:**:  
   - **VS Code**  
   - **CMake (last stable release)**  
   - **Git**

2. **Clone the Repository**:

3. **Open folder with VSCode and start build**

4. **In build folder**
```bash
./list
