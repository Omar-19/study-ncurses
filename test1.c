#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ncurses.h"

int main()
{
	// ---EX1--- базовая работа с либой
	initscr();					// Инициализация ncurses
    curs_set(0);				// Делаем курсор невидимым
    printw("Hello, World!");	// Вывод строки Hello, World!
    refresh();					// Отображение строки на реальном экране
    getch();					// Ожидание пользовательского ввода
    endwin();					// Завершение работы с ncurses
	return (0);
}