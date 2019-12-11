/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include "Menu.hpp"

/*********************************************************************
** main function
** Paramaters are: none
** What it does: Runs game functions until user terminates
** Returns: 0
*********************************************************************/
int main() {
    Menu menu;
    menu.showMenu();
    return 0;
}


/* WORKS CITED

Afshari, Mehrdad, and Kevin Loney. "How do I declare a 2d array in C++ using new?" StackOverflow, https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new/936702#936702.

Barfa, Avinash. "How can I delete an element from a dynamic array?" Quora, https://www.quora.com/How-can-I-delete-an-element-from-a-dynamic-array.

Bartwal, Upendra. "Generating random number in a range in C." GeeksforGeeks, https://www.geeksforgeeks.org/generating-random-number-range-c/.

Beta <StackOverflow username>. "Counte elements (size) of array of objects." StackOverflow, https://stackoverflow.com/questions/6947400/counte-elements-size-of-array-of-objects.

Bi, Brian. "What is the difference between delete and delete[]?" Quora, https://www.quora.com/What-is-the-difference-between-delete-and-delete.

caf <StackOverflow username>. "What range of values can integer types store in C++?" StackOverflow, https://stackoverflow.com/questions/1819189/what-range-of-values-can-integer-types-store-in-c.

CPlusPlus.com. "std::array::size." CPlusPlus.com, http://www.cplusplus.com/reference/array/array/size/.

CPlusPlus.com. "std::chrono::high_resolution_clock." CPlusPlus.com, http://www.cplusplus.com/reference/chrono/high_resolution_clock/.

CPlusPlus.com. "std::stoi." CPlusPlus.com, http://www.cplusplus.com/reference/string/stoi/.

CppReference.com. "std::chrono::duration." CppReference.com, https://en.cppreference.com/w/cpp/chrono/duration.

CppReference.com. "std::chrono::duration_cast." CppReference.com, https://en.cppreference.com/w/cpp/chrono/duration/duration_cast.

Dima <StackOverflow username>. "How do I check if an object's type is a particular subclass in C++?" StackOverflow, https://stackoverflow.com/questions/307765/how-do-i-check-if-an-objects-type-is-a-particular-subclass-in-c.

Gupta, Akash. "Doubly Circular Linked List." GeeksForGeeks, https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/.

Haapala, Antti. "How to properly deallocate 2d array c++." StackOverflow, https://stackoverflow.com/questions/28935944/how-to-properly-deallocate-2d-array-c.

Helios <CPlusPlus.com username>. "std::string::npos ??." CPlusPlus.com, http://www.cplusplus.com/forum/beginner/233668/.

julian <CodeProject username>. "Fibonacci Recursive and Non Recursive C++." CodeProject.com, https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c.

McNellis, James. "Can a c++ class include itself as a member?" StackOverflow, https://stackoverflow.com/questions/2706129/can-a-c-class-include-itself-as-an-member.

KevenK <StackOverflow username>. "Delete element from C++ array." StackOverflow, https://stackoverflow.com/questions/4023011/delete-element-from-c-array.

Koon, Rebekah. "Feedback for Project1." OSU Instructure, https://oregonstate.instructure.com/courses/1738874/grades

LearnCpp.Com. "5.10 — std::cin, extraction, and dealing with invalid text input." LearnCpp.com Tutorials, https://www.learncpp.com/cpp-tutorial/5-10-stdcin-extraction-and-dealing-with-invalid-text-input/.

LearnCpp.Com. "8.9 — Class code and header files." LearnCpp.com Tutorials, https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/.

Rajput, Abhishek. "delete() in C++." GeeksforGeeks, https://www.geeksforgeeks.org/delete-in-c/.

Tusher, Tunvir Rahman "When to use virtual destructors?" StackOverflow, https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors.
    */