# HashMaps in C and Java

This project will have you create a HashMap data structure in both C and Java. HashMaps are built of LinkedLists with a few additional complications. From class, you should already have the pseudocode to add a node to the end of a list, as well as a basic C implementation for a linked list. You will have to add functionality to put items in the HashMap using two different insertion methods: alphabetical order and duration.

Project Goals:

- Understand pointers/references in both C and Java
- See a more complex C project composed of multiple files
- Use the `make` build system to compile and run your code

You will be creating a HashMap data structure which holds a playlist -- each song has an artist name, title, and duration. You will be given a template that already contains the data structures to use for your HashMap and a print function that demonstrates how to step through the HashMap and its Linked Lists and display all the elements.
The C structure is defined in the `hashmap.h` file:

    struct HashMap
    {
      struct LList buckets[NUM_BUCKETS];
      char policy;
    };
    
    struct LList
    {
      struct LNode* head;
    };
    
    struct LNode {
      char* artistName;
      char* songName;
      double duration;
      struct LNode* next;
    };

In Java, you will have similar code put into `HashMap`, `LList` and `LNode` classes. You **may not** change the fields defined in the classes/structs.

### Deadlines: 

**NOTE:** You should **NOT** modify the code/files for each phase/deadline after the deadline unless you are using a late pass for that. Doing so will make the grading harder and will result in loss of points.


## Phase 1: Algorithms

Before writing your code you must prepare pseudocode algorithms for each of the different functions. You must submit these in your repository [Algorithms/README.md](Algorithms/README.md) file by the deadline. You are encouraged to submit much sooner so that you can make progress on your coding -- if you submit sooner, you will get feedback sooner! Keep in mind that your algorithms should be language agnostic since you will be using this for both C and Java.

> **NOTE:** to notify us about "Ready to review" **only BEFORE** the deadline:
> - post an issue to github in your repository and put `@fall20-2113/ta` in the textbox to notify the teaching team.
> - fill up this [form](https://forms.gle/VDd4b9FNxqwRrEjV9)

`struct hashmap* hm_create(char policy)` (C only)

- Create the HashMap and allocate space for the linked lists contained within. The insertion policy will be determined by the policy character
    - `A` denotes alphabetical song title
    - `D` denotes song duration

`int hm_put(…)`

- Add a song to the HashMap.
- Return `0` on success, `-1` otherwise.

`int hash_alphabetical(…)`

- The alphabetical hash will take the given song title and return an int specifying which bucket to add to. This can be done by taking the sum of the ASCII codes of all the characters, then modulo by the number of buckets, and return the result.

`int hash_duration(…)`

- The duration hash will take the given song duration and return an int specifying which bucket to add to. This can be done by taking the duration modulo by the number of buckets, and return the result.

`struct LNode* hm_get(…) / LNode hm_get(…)`

- hm_get should retrieve a node using the hash policy defined for the specific HashMap struct. Only return a node if ALL properties match (i.e. title, artist AND duration).
- Returns the node if found, `NULL` otherwise

`int hm_remove(…)`

- Remove a song from the HashMap that has the given title, artist, and duration.
- Return `0` on success, `1` if not found, `-1` otherwise.

`void hm_destroy(struct hashmap* hm)` (C only)

- Deallocate (free) the HashMap that is passed in and **all of its elements.**

## Phase 2: Implementation

The git repository has starter code for both C and Java, as well as very basic test cases to give an example of how to write a unit test for this project.

- You must use those as a base and *may not change the structure or class definitions* (e.g., you may not add a rear pointer to your list structure).
- You *may not* use other data structure libraries (e.g., the java collections framework) to implement your code. You should be writing your linked lists from scratch.

This is our first C program that spans over multiple files:

- `hashmap.h` is a "Header File" that defines the prototypes for the functions and data structures used in the HashMap library
- `hashmap.c` is the C file that implements those functions. This is where you will write your code.
- `tests.c` is a C file containing the program's `main` function.  It only includes the simplest possible test case to see if you can add an entry to a list that has already been started. **You must add comprehensive test cases to verify that your different functions are working correctly and to test your edge cases**

The Java code also spans over multiple files/classes:

- `Hashmap.java` contains the HashMap object declaration and methods. Write your HashMap implementation here.
- `LList.java`  contains the LList object declaration. You may write a constructor for this object, but you may not change its data members.
- `LNode.java` contains the LNode object declaration. You may write a constructor for this object, but you may not change its data members.
- `Tests.java` contains the program's `main` method. It only includes the simplest possible test case to see if you can add an entry to a list that has already been started. **You must add comprehensive test cases to verify that your different methods are working correctly and to test your edge cases**

 ***Implementation tip:*** you cannot test if two strings are equal with `==` in C or Java! In C you will have to learn to use the [strcmp](https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm) function and in Java you will want to use `.equals`

**How to run your code:** You will see that the C code is made up of several files, so to simplify compilation we have provided a `Makefile` that automates the building and running process. Simply run the commands listed below to build or execute either the C or Java code.
To build and run the C code use:

      make c
      make runc

To build and run the Java code use:

      make java
      make runjava

**Where to run your code: Repl.it**, then commit and push (frequently!) to GitHub.
