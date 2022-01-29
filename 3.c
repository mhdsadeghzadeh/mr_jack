#include "stdio.h"

/*
    1= barrage//2= house//3=off lamp//4=on lamp//5=open hole//6=escape//7=jw//8=wg//9=il//10=js//11=sh//12=jb//13=ms//14=sg
    //15=empty//16= close hole*/
typedef struct {
    int block_number;
    char name[20];
    char symbol;
} block;

/*
{1,"barrage",'B'}
{2,"house",'H'}
{3,"off lamp",'Y'}
{4,"on lamp",'L'}
{5,"open hole",'O'}
{6,"escape",'E'}
{7,"JW",'J'},
{8,"WG",'W'}
{9, "IL",'I'}
{10,"JS",'J'}
{11,"SH",'S'}
{12,"JB",'K'}
{13,"MS",'M'}
{14,"Sg",'s'}
{15,"empty",' '}
{16,"close hole",'X'}

*/
void start_game();

void set_map();

block map[11][15] = {{{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house",   'H'},
                             {2,  "house",      'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",   'H'},
                             {2,  "house",      'H'},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {1,  "barrage", 'B'},
                             {2,  "house",      'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {5,  "open hole", 'O'},
                             {13, "MS",    'M'},
                             {2,  "house", 'H'},
                             {2,  "house",   'H'},
                             {6,  "escape",     'E'},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}},
                     {{2, "house", 'H'},
                             {15, "empty",     ' '},
                             {15, "empty",   ' '},
                             {16, "close hole", 'X'},
                             {2,  "house", 'H'},
                             {15, "empty", ' '},
                             {15, "empty",     ' '},
                             {15, "empty", ' '},
                             {3,  "off lamp",  'Y'},
                             {15, "empty", ' '},
                             {2,  "house", 'H'},
                             {4,  "on lamp", 'L'},
                             {15, "empty",      ' '},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {15, "empty",     ' '},
                             {4,  "on lamp", 'L'},
                             {15, "empty",      ' '},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {11, "SH",    'S'},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {15, "empty",   ' '},
                             {15, "empty",      ' '},
                             {15, "empty",     ' '},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {7,  "JW",        'J'},
                             {15, "empty",   ' '},
                             {15, "empty",      ' '},
                             {2,  "house", 'H'},
                             {9,  "IL",    'I'},
                             {4,  "on lamp",   'L'},
                             {15, "empty", ' '},
                             {5,  "open hole", 'O'},
                             {15, "empty", ' '},
                             {2,  "house", 'H'},
                             {2,  "house",   'H'},
                             {2,  "house",      'H'},
                             {5,  "open hole", 'O'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {15, "empty",     ' '},
                             {2,  "house",   'H'},
                             {2,  "house",      'H'},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {12, "JB",    'K'},
                             {15, "empty", ' '},
                             {15, "empty",   ' '},
                             {2,  "house",      'H'},
                             {14, "Sg",        's'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {5,  "open hole", 'O'},
                             {2,  "house",   'H'},
                             {15, "empty",      ' '},
                             {2,  "house", 'H'},
                             {15, "empty", ' '},
                             {5,  "open hole", 'O'},
                             {10, "JS",    'J'},
                             {4,  "on lamp",   'L'},
                             {15, "empty", ' '},
                             {2,  "house", 'H'},
                             {15, "empty",   ' '},
                             {15, "empty",      ' '},
                             {15, "empty",     ' '},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {15, "empty",   ' '},
                             {4,  "on lamp",    'L'},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {15, "empty",   ' '},
                             {4,  "on lamp",    'L'},
                             {15, "empty",     ' '},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {15, "empty",   ' '},
                             {2,  "house",      'H'},
                             {2,  "house", 'H'},
                             {8,  "WG",    'W'},
                             {3,  "off lamp",  'Y'},
                             {15, "empty", ' '},
                             {15, "empty",     ' '},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",   'H'},
                             {16, "close hole", 'X'},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {6,  "escape",  'E'},
                             {2,  "house",      'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {5,  "open hole", 'O'},
                             {2,  "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",   'H'},
                             {1,  "barrage",    'B'},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house",   'H'},
                             {2,  "house",      'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house", 'H'},
                             {2,  "house",     'H'},
                             {2,  "house", 'H'},
                             {2,  "house", 'H'},
                             {2,  "house",   'H'},
                             {2,  "house",      'H'},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}}};


int get_choice();

void game_menu();

void start_menu();

void action();

void print_game_page();

void print_hexagon() {
    for (int j = 0; j < 7; j++) {
        printf("         _____");
    }
    int flag1 = 10, flag2 = 0, flag3 = 11, flag4 = 1;
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
                    printf("\\   ");
                    printf("%c", map[flag1 - flag2][(2 * j)].symbol);
                    printf("   /     ");
                }
                flag1++;
                flag2 += 2;
                printf("\n ");
                for (int j = 0; j < 8; j++) {
                    if (j < 7) {
                        printf("\\_____/    ");
                        printf("   ");
                    } else
                        printf("\\_____/       ");
                }
            }
        } else {
            printf("\n ");
            for (int j = 0; j < 8; j++) {
                if (j < 7) {
                    printf("/     \\   ");
                    printf("%c", map[flag3 - flag4][(2 * j) + 1].symbol);
                    printf("   ");
                } else
                    printf("/     \\       ");
            }
            flag3++;
            flag4 += 2;
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