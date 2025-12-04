#ifndef MENU_H
#define MENU_H

#include "computer.h"
#include "monoblock.h"
#include "laptop.h"
#include "tablet.h"

#define MAX_COMPUTERS 100


void show_main_menu();
void handle_menu_choice(Computer* computers[], int& actual_count, int choice);
void run_main_menu(Computer* computers[], int size);

#endif