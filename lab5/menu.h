#ifndef MENU_H
#define MENU_H

#include "deque.h"

// Прототипы функций
void show_main_menu();
void show_device_type_menu();
void show_sort_menu();
void show_search_menu();
Computer* create_computer_by_type(int type);
void display_all_computers_table(Deque<Computer*>& computers);
void sort_computers(Deque<Computer*>& computers);
void search_computers(Deque<Computer*>& computers);
void handle_menu_choice(Deque<Computer*>& computers, int choice);
void run_main_menu(Deque<Computer*>& computers);

#endif // MENU_H