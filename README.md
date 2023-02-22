# c-types-extended
Learning project for experimenting with data types in C. All projects are built with Make and tested using the Unity library.

## List Library
### Description
The liblist directory contains a simple dynamic list class with automatic resizing as elements are added/removed. The file demo_liblist.c contains boilerplate code for playing around with the class. Comments about each function can be found in the header file liblist.h.

### Features
- Automatic memory management through its own init and free function.
- Automatic resizing when adding new elements (Resizes in batches of 10, can be customized in code).
- Various sorting algorithms are implemented for the class.
- Verbose mode to visualize memory management, flag can be set in header file.

### Todo
- Implement automatic resizing when removing elements.
- Additional functionality.

## Linked List Library
### Description
The liblinkedlist directory contains a simple linked list class with omni-directional stepping. The class handles it's own memory through its own init and free function. The class can be tested by modifying the demo_liblinkedlist.c file.

### Features
- Automatic memory management through its own init and free functions.
- Automatic resizing when adding/removing elements to the list.
- Verbose mode to visualize memory management, flag can be set in header file.

### Todo
- Implement sorting functions for the list.
- Additional functionality.
