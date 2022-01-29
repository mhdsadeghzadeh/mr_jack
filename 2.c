#include "stdio.h"

struct Block {
    int block_number;
    char name[20];
};

void start_game();

void set_map();

int get_choice();

void game_menu();

void start_menu();

void action();

void print_game_page();

void print_hexagon() {
    for (int j = 0; j < 7; j++) {
        printf("         _____");
    }
    for (int i = 0; i < 23; i++) {
        if (i % 2 == 0) {
            if (i == 0) {
                printf("\n ");
                for (int j = 0; j < 7; j++) {
                    printf("       /     \\");
                }
                printf("\n  ");
                for (int j = 0; j < 7; j++) {
                    printf("_____/       \\");

                }
                printf("_____");
            } else {
                printf("\n");
                for (int j = 0; j < 8; j++) {
                    printf("\\       /     ");
                }
                printf("\n ");
                for (int j = 0; j < 8; j++) {
                    printf("\\_____/       ");
                }
            }
        } else {
            printf("\n ");
            for (int j = 0; j < 8; j++) {
                printf("/     \\       ");
            }
            printf("\n");
            for (int j = 0; j < 7; j++) {
                printf("/       \\_____");
            }
            printf("/       \\");
        }
    }
}


int main() {
    print_hexagon();
//    start_game();
//    int round = 8;
//    while ((round) > 0) {
//        print_map();
//        if (round % 2) {
//            handle_odd_round();
//        } else {
//            handle_even_round();
//        }
//        round--;
//    }
    return 0;
}