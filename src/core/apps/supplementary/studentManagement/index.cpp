/**
 * @file /src/core/apps/supplementary/studentManagement/index.cpp
 * @brief Second sem quiz two
 *
 * */

/* A preprocessor directive that prevents the file from being included more than
  once. */
#ifndef CPP_STUDENT_MANAGEMENT_SUPPLEMENTARY
#define CPP_STUDENT_MANAGEMENT_SUPPLEMENTARY

/* Student Management operations */
#include "./functions/create/index.cpp"

/* Student Management menu */
#include "./menu/showMenu.cpp"

/* Components */
#include "../../../components/input.cpp"
#include "../../../components/text.cpp"
#include "../../../components/view.cpp"

/* Constants */
#include "../../../../includes/constants/alignment.cpp"
#include "../../../../includes/constants/color.cpp"
#include "../../../../includes/constants/menu.cpp"
#include "../../../../includes/constants/validation.cpp"

/* Helpers */
#include "../../../../includes/helpers/cleanUp.cpp"

void (*studentManagementMethods[4])(std::string type,
                                    std::string currentMenu) = {create};

void studentManagement(void (&previousMenu)(std::string menuType)) {
  /* Declaring variables. */
  int maxMenuLength = 4;
  std::string userInput;
  std::string backMenu = MENU_ITEM_4;
  int reAlignLabelYCoordinate = ALIGNMENTY25;
  int reAlignErrorMsgYCoordinate = ALIGNMENTY29;
  std::string inputLabel = "Select Operation";
  std::string expectedArrayOfValue[maxMenuLength] = {MENU_ITEM_1, MENU_ITEM_2,
                                                     MENU_ITEM_3, MENU_ITEM_4};

  /* A function that clears the screen. */
  cleanUpScreen(mainMenuHeaderComponent, headerComponent);

  /* Calling the function `studentManagementMenu` and passing the value
    `MENU_ITEM_NONE` to it. */
  studentManagementMenu(MENU_ITEM_NONE);

  /* It handles user input and prints an error if there is an error. */
  input<std::string>(inputLabel, userInput, expectedArrayOfValue, maxMenuLength,
                     RESTRICTED_INPUT, reAlignLabelYCoordinate,
                     reAlignErrorMsgYCoordinate);

  /* A loop that handles user input and prints an error if there is an error. */
  while (userInput != backMenu) {
    /* Finding the element in the array. */
    std::string foundElement = findElement<std::string>(
        expectedArrayOfValue, maxMenuLength, userInput);

    /* Checking if the user input is equal to the found element. If it is, it
    will call the function that is in the array. */
    if (userInput == foundElement) {
      for (int i = 0; i < maxMenuLength; i++) {
        if (foundElement == expectedArrayOfValue[i]) {
          cleanUpScreen(mainMenuHeaderComponent, headerComponent);
          studentManagementMenu(foundElement);
          (*studentManagementMethods[i])(STUDENT_MANAGEMENT_SYSTEM_APP,
                                         foundElement);
        }
      }

      /* It handles user input and prints an error if there is an error. */
      input<std::string>(inputLabel, userInput, expectedArrayOfValue,
                         maxMenuLength, RESTRICTED_INPUT,
                         reAlignLabelYCoordinate, reAlignErrorMsgYCoordinate);
    }
  }

  /* Calling the function `studentManagementMenu` and passing the value
     `MENU_ITEM_NONE` to it. */
  studentManagementMenu(MENU_ITEM_NONE);
  /* A function that clears the screen. */
  cleanUpScreen(mainMenuHeaderComponent, headerComponent);
  /* renders previous function caller */
  previousMenu(MENU_ITEM_NONE);
}

#endif
