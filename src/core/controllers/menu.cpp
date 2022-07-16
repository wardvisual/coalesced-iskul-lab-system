/**
 * @file /src/core/controllers/menu.cpp
 * @brief
 *
 * */

#ifndef CPP_MAIN_MENU_CONTROLLER
#define CPP_MAIN_MENU_CONTROLLER

#include <conio.h>

#include "../components/header.cpp"
#include "../components/input.cpp"
#include "../components/menu.cpp"
#include "../components/text.cpp"

// #include "../../core/apps/controller.cpp"
// #include "../../core/apps/finals/index.cpp"
// #include "../../core/apps/information/index.cpp"
// #include "../../core/apps/midterm/index.cpp"
// #include "../../core/apps/secondsem/index.cpp"

#include "../../includes/constants/alignment.cpp"
#include "../../includes/constants/color.cpp"
#include "../../includes/constants/keyStroke.cpp"
#include "../../includes/constants/menu.cpp"
#include "../../includes/constants/validation.cpp"

#include "../../includes/helpers/cleanUp.cpp"
#include "../../includes/helpers/search.cpp"

void mainMenuController() {
  char userInput = _getch();
  int reAlignLabelYCoordinate = ALIGNMENTY24,
      reAlignErrorMsgYCoordinate = ALIGNMENTY26, keyStroke = 0;
  std::string inputLabel = "Select Menu";

  int maxMenuLength = 6;
  char expectedArrayOfValue[maxMenuLength] = {MENU_ITEM_A, MENU_ITEM_B,
                                              MENU_ITEM_C, MENU_ITEM_D,
                                              MENU_ITEM_E, MENU_ITEM_F};

  /* It displays the menu items without the selected item.*/
  menuComponent(MENU_ITEM_NONE);

  do {

    /* It handles user input and prints an error if there is an error. */
    input<char>(inputLabel, userInput, expectedArrayOfValue, maxMenuLength,
                RESTRICTED_INPUT, reAlignLabelYCoordinate,
                reAlignErrorMsgYCoordinate);

    std::cout << "nice good";

    char foundedElement =
        findElement(expectedArrayOfValue, maxMenuLength, userInput);

    /* Accessing keyboard stroke */

    if (userInput == foundedElement) {
      char currentMenuItem = userInput;

      if (currentMenuItem == MENU_ITEM_F) {

        keyStroke = ESCAPE_KEY;

        menuComponent(currentMenuItem);

        text("Thank you for using this application!", TEXT_BLUE, ALIGNMENTX2,
             ALIGNMENTY24);

        std::cout << "\n\n";
      }

      cleanUpScreen(mainMenuHeaderComponent, headerComponent);
      menuComponent(currentMenuItem);

      // while (currentMenuItem == foundedElement) {
      //   if (foundedElement == MENU_ITEM_A) {
      //     displaySystemInformation();
      //   }
      //   if (foundedElement == MENU_ITEM_B) {
      //     cleanUpScreen(mainMenuHeaderComponent, headerComponent);
      //     menuComponent(currentMenuItem);

      //     secondSem(currentSelectedMenu, mainMenuController);
      //   }
      //   if (foundedElement == MENU_ITEM_C) {
      //     midterm(currentSelectedMenu, mainMenuController);
      //   }
      //   if (foundedElement == MENU_ITEM_D) {
      //     displaySystemInformation();
      //     finalSem(currentSelectedMenu, mainMenuController);
      //   }
      //   if (foundedElement == MENU_ITEM_E) {
      //     supplementary(currentSelectedMenu, mainMenuController);
      //   }
      // }
    } else {
      std::cout << "\nSomething went wrong.";
    }

  } while (keyStroke != ESCAPE_KEY);
}

#endif