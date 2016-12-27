# Generic_Linked_List
C Programming Simple Generic Data Structure
For this assignment, you will implement a simple purely generic doubly-linked list in C.
The best approach to implementing a generic list in C is discussed in CS 2505. Rather than repeat that discussion here, you
will find links to the relevant notes from CS 2505 in the Suggested Resources section later in this specification. You should
make sure you understand those notes before trying to implement your list.
Because your list implementation will be compiled with a test harness, there will be a mandatory interface, shown later in
this specification. You will find a header file for the list on the course website, and repeated below. You must not make
any changes to the specified interface of the list, although you may add helper functions as you see fit. Those helper
functions should be declared as static.
Because the nodes in the generic list do not store user data, testing might seem to be impossible. When testing your
solution, we will employ a wrapper type with integer payload, as described in the CS 2505 notes. In addition, it is fairly
simple to write a function that will traverse a list and print detailed information about the nodes and how they are linked.
The last page of this specification shows detailed information for a nonempty generic list.
Memory management requirements
The list itself does not perform any dynamic allocation or deallocation of memory. If it is not clear to you why the previous
sentence is true, you do not yet understand the CS 2505 notes referenced above. Go over them again, and see a course TA
or instructor.
Testing
Although your solution will be subjected to automated testing and grading, you are expected to test your solution
thoroughly on your own Linux system or on the rlogin cluster. In order to make it easier for you to understand how the
automated testing is performed, some test files will be provided:
driver.c driver code to manage the testing process
DList.h header file for the DList implementation (shown below)
DListTestHarness.h header file for the test harness we will use
DListTestHarness.o 64-bit Linux object file for the test harness we will use
IntegrityChecker.h header file for the list integrity checker we will use (see below)
IntegrityChecker.o 64-bit Linux object file for the integrity checker
You should download the supplied tar file and extract its contents into a directory. Object files are supplied for the test
harness and integrity checker because the C source code contains elements of the solution for the linked list itself. Place
your solution file, DList.c, into the same directory. The following command will build a 64-bit executable named
driver:
gcc –o driver –m64 –std=c99 driver.c DList.c DListTestHarness.o IntegrityChecker.o
You can execute the tests in two modes. If you execute the command: ./driver –rand
the test code will generate a pseudo-random test sequence. This will yield a collection of log files, whose names indicate
what was being tested. Examine those files to see if any errors were reported.
If you execute the command: ./driver
(after running the driver with the –prof switch) the test code will repeat the last test sequence that was performed.
CS 2506 Computer Organization II C01: C Generic Linked List
Version 2.00 This is a purely individual assignment! 2
This is essentially how the automated testing will be performed on your submission. The grading will not be done in real
time when you submit your solution to the Curator, but later by a TA. However, since you have the complete
testing/grading code, you should know in advance what we will see when we run the tests.
64-bit environment
This course will exclusively use x86-64 implementations. If you have installed a 32-bit Linux virtual machine, you are
strongly advised to immediately set up a 64-bit CentOS installation; notes covering how to do that are posted on the course
website. If you do not do so, you will be forced to use the rlogin cluster to complete the programming assignments in this
course. That is extremely inconvenient, and the cluster may become unstable or overwhelmed at times.
Suggested resources
From the CS 2505 course website at:
http://courses.cs.vt.edu/~cs2505/summer2016/
you should consider the following notes:
Intro to Pointers http://courses.cs.vt.edu/cs2505/summer2015/Notes/T14_IntroPointers.pdf
C Pointer Finale http://courses.cs.vt.edu/cs2505/summer2015/Notes/T17_CPointerFinale.pdf
C struct Types http://courses.cs.vt.edu/cs2505/summer2015/Notes/T24_CstructTypes.pdf
DT List http://courses.cs.vt.edu/cs2505/summer2015/Notes/T25_CListDT.pdf
gdb List Example http://courses.cs.vt.edu/cs2505/summer2015/Notes/T26_gdbListExample.pdf
Some of the other notes on the basics of C and separate compilation may also be useful.
