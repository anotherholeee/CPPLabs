#ifndef MENU_H
#define MENU_H

#include "computer.h"
#include "monoblock.h"
#include "laptop.h"
#include "tablet.h"
#include "deque.h"

// Функции меню
void show_main_menu();
void handle_menu_choice(Deque<Computer*>& computers, int choice);
void run_main_menu(Deque<Computer*>& computers);

#endif