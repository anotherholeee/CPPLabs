#ifndef MENU_H
#define MENU_H

#include "computer.h"

// Функции меню
void show_main_menu();
void handle_menu_choice(Computer* computers[], int& actual_count, int choice);
void run_main_menu(Computer* computers[], int size);

#endif