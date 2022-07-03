#ifndef CPP_MENU_COMPONENT
#define CPP_MENU_COMPONENT

/* Including the files in the structures folder. */
#include "../../includes/structures/menuStruct.cpp"

/* Including the files in the helpers folder. */
#include "../../includes/helpers/menu.cpp"

/* Including the files in the utilities folder. */
#include "../../includes/utilities/color.cpp"
#include "../../includes/utilities/gotoxy.cpp"

/* Including the files in the constants folder. */
#include "../../includes/constants/app.cpp"
#include "../../includes/constants/color.cpp"

using std::cout;

void menuComponent() {
  const int maxMenuLength = 5;
  std::string generatedSymbol18 = generateSymbol("-", 20);
  std::string generatedSymbol91 = generateSymbol(" ", 20);
  std::string generatedSymbol87 = generateSymbol("-", 20);

  MenuStruct developersInformation, secondSemMenu, midtermMenu, finalSemMenu,
      supplementaryApp;

  applyBackgroundColor(BG_BLUE);
  alignContent(10, 3);
  std::cout << generatedSymbol91;

  applyTextColor(TEXT_BLUE);
  alignContent(6, 10);
  cout << "Main Menu";

  /* Assigning values to the secondSemMenu struct instance. */
  developersInformation.name = "01. About Us";
  developersInformation.textColor = TEXT_WHITE;
  developersInformation.fontSize = 20;
  developersInformation.alignmentX = 6;
  developersInformation.alignmentY = 12;
  developersInformation.type = DEVELOPERS_INFORMATION;

  secondSemMenu.name = "02. Second Sem Applications";
  secondSemMenu.textColor = TEXT_WHITE;
  secondSemMenu.fontSize = 20;
  secondSemMenu.alignmentX = 6;
  secondSemMenu.alignmentY = 14;
  secondSemMenu.type = SECOND_SEM;

  /* Assigning values to the  midtermMenu struct instance. */
  midtermMenu.name = "03. Midterm Applications";
  midtermMenu.textColor = TEXT_WHITE;
  midtermMenu.fontSize = 20;
  midtermMenu.alignmentX = 6;
  midtermMenu.alignmentY = 16;
  midtermMenu.type = MID_TERM;

  /* Assigning values to the  finalSemMenu struct instance. */
  finalSemMenu.name = "04. Final Sem Applications";
  finalSemMenu.textColor = TEXT_WHITE;
  finalSemMenu.fontSize = 20;
  finalSemMenu.alignmentX = 6;
  finalSemMenu.alignmentY = 18;
  finalSemMenu.type = FINAL_SEM;

  supplementaryApp.name = "05. Supplementary Applications";
  supplementaryApp.textColor = TEXT_WHITE;
  supplementaryApp.fontSize = 20;
  supplementaryApp.alignmentX = 6;
  supplementaryApp.alignmentY = 20;
  supplementaryApp.type = SUMPPLEMENTARY_APP;

  /* Creating an array of MenuStruct. */
  struct MenuStruct menuStruct[maxMenuLength] = {
      developersInformation, secondSemMenu, midtermMenu, finalSemMenu,
      supplementaryApp};

  /* Calling the function createMenu() and passing the array of MenuStruct and
the maxMenuLength value. */
  createMenu(menuStruct, maxMenuLength);
}

#endif
