# My Linked List

This is my own implementation of a template-based doubly linked list.

## Features & Tools Used

- **Valgrind**: No memory leaks.
- **Google Test**: The entire basic interface is covered with unit tests.

## Interface

- `List()`                 — Default constructor, creates an empty list.
- `List(T obj)`            — Constructs a list with a single element.
- `~List()`                 — Destructor, deletes all nodes, fully deallocates memory.
- `T& front()`              — Returns a reference to the first element.
- `T& back()`               — Returns a reference to the last element.
- `bool is_empty()`         — Checks if the list is empty.
- `void push_back(T obj)`   — Inserts a new element at the end of the list.

## Example Usage

```cpp
List<int> list;
list.push_back(10);
list.push_back(20);
std::cout << list.front() << std::endl;  // Output: 10
std::cout << list.back() << std::endl;   // Output: 20
```
## Build and Run

To build and run the project, follow these steps:

1. **Needed:**:  
   - **Ubuntu**
   - **VS Code**  
   - **CMake(Release)**  
   - **Git**

2. **Clone the Repository**:

3. **Open folder with VSCode and start build**

4. **In build folder**
```bash
./list
