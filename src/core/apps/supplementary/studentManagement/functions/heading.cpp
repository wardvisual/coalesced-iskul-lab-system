/**
 * @file /src/core/apps/supplementary/studentmanagement/functions/heading.cpp
 * @brief A helper function
 *
 * */

/* A preprocessor directive that prevents the file from being included more than
  once. */
#ifndef CPP_SUPPLEMENTARY_STUDENT_MANAGEMENT_HEADING
#define CPP_SUPPLEMENTARY_STUDENT_MANAGEMENT_HEADING

/* Constants */
#include "../../../../../includes/constants/alignment.cpp"
#include "../../../../../includes/constants/color.cpp"

/* Components */
#include "../../../../components/text.cpp"

/**
 * It displays the heading for the midterm.
 */
void displayStudentManagementHeading() {
  /* It's displaying the instruction for the user. */
  text("Information:", TEXT_BLUE, ALIGNMENTX38, ALIGNMENTY10);
  text("This student management system has four basic things to do. It can "
       "create, view, update, ",
       TEXT_WHITE, ALIGNMENTX38, ALIGNMENTY12);
  text("and delete student records.", TEXT_WHITE, ALIGNMENTX38, ALIGNMENTY13);
}

#endif