#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
    1= barrage//2= house//3=off lamp//4=on lamp//5=open hole//6=escape//7=jw//8=wg//9=il//10=js//11=sh//12=jb//13=ms//14=sg
    //15=empty//16= close hole*/
typedef struct {
    int block_number;
    int number;
} block;

struct node {
    int info;
    struct node *next;
};

struct node *create_node(int i) {
    struct node *nn;
    nn = (struct node *) malloc(sizeof(struct node));
    if (nn == NULL)
        return NULL;
    nn->info = i;
    nn->next = NULL;
    return nn;
}

void add_end(struct node *list, struct node *new_node) {
    struct node *current;
    for (current = list; current->next != NULL; current = current->next);
    current->next = new_node;
    new_node->next = NULL;
}

/*
{1,"barrage",'B'}
{2,"house",'H'}
{3,"off lamp",'offL'}
{4,"on lamp",'on_L'}
{5,"open hole",'O'}
{6,"escape",'E'}
{7,"JW",'JW'},
{8,"WG",'WG'}
{9, "IL",'IL'}
{10,"JS",'JS'}
{11,"SH",'SH'}
{12,"JB",'JB'}
{13,"MS",'MS'}
{14,"Sg",'SG'}
{15,"empty",' '}
{16,"close hole",'x'}

*/
char *convert(int n) {
    if (n == 1)
        return "B";
    else if (n == 2)
        return "H";
    else if (n == 3)
        return "offL";
    else if (n == 4)
        return "on_L";
    else if (n == 5)
        return "O";
    else if (n == 6)
        return "E";
    else if (n == 7)
        return "JW";
    else if (n == 8)
        return "WG";
    else if (n == 9)
        return "IL";
    else if (n == 10)
        return "JS";
    else if (n == 11)
        return "SH";
    else if (n == 12)
        return "JB";
    else if (n == 13)
        return "MS";
    else if (n == 14)
        return "SG";
    else if (n == 15)
        return " ";
    else if (n == 16)
        return "X";
}

block map[11][15] = {{{2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2}},

                     {{2},
                             {2},
                             {1},
                             {2},
                             {2},
                             {2},
                             {2},
                             {15},
                             {5},
                             {13},
                             {2},
                             {2},
                             {6},
                             {2},
                             {2}},

                     {{2},
                             {15},
                             {15},
                             {16},
                             {2},
                             {15},
                             {15},
                             {15},
                             {3},
                             {15},
                             {2},
                             {4},
                             {15},
                             {2},
                             {2}},

                     {{2},
                             {15},
                             {4},
                             {15},
                             {15},
                             {15},
                             {2},
                             {11},
                             {2},
                             {15},
                             {15},
                             {15},
                             {15},
                             {15},
                             {2}},

                     {{2},
                             {7},
                             {15},
                             {15},
                             {2},
                             {9},
                             {4},
                             {15},
                             {5},
                             {15},
                             {2},
                             {2},
                             {2},
                             {5},
                             {2}},

                     {{2},
                             {15},
                             {2},
                             {2},
                             {15},
                             {15},
                             {2},
                             {15},
                             {2},
                             {12},
                             {15},
                             {15},
                             {2},
                             {14},
                             {2}},

                     {{2},
                             {5},
                             {2},
                             {15},
                             {2},
                             {15},
                             {5},
                             {10},
                             {4},
                             {15},
                             {2},
                             {15},
                             {15},
                             {15},
                             {2}},

                     {{2},
                             {2},
                             {15},
                             {4},
                             {15},
                             {15},
                             {2},
                             {15},
                             {2},
                             {15},
                             {15},
                             {15},
                             {4},
                             {15},
                             {2}},

                     {{2},
                             {2},
                             {15},
                             {2},
                             {2},
                             {8},
                             {3},
                             {15},
                             {15},
                             {2},
                             {2},
                             {2},
                             {16},
                             {2},
                             {2}},

                     {{2},
                             {2},
                             {6},
                             {2},
                             {2},
                             {2},
                             {5},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {1},
                             {2},
                             {2}},

                     {{2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2},
                             {2}}};

void print_list(struct node *list) {
    struct node *current = list->next;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

void print_list_with_char(struct node *list) {
    struct node *current = list->next;
    while (current != NULL) {
        printf("%d)", current->info);
        if (current->info == 1)
            printf("SH: move 1 to 3 houses then show suspect card\n");
        else if (current->info == 2)
            printf("JB: move 1 to 3 houses before or after change location cap of hole\n");
        else if (current->info == 3)
            printf("WG: move 1 to 3 houses then or change location with other character\n");
        else if (current->info == 4)
            printf("IL: move 1 to 3 houses then change position of barrage \n");
        else if (current->info == 5)
            printf("JW: move 1 to 3 houses then chose position for clarify\n");
        else if (current->info == 6)
            printf("MS: move 1 to 4 houses but can transit engaged location\n");
        else if (current->info == 7)
            printf("SG: move 1 to 3 houses before or after altogether change 3 location of other character \n");
        else if (current->info == 8)
            printf("JS: move 1 to 3 houses after or before turn off one lamp and turn on other lamp\n");
        current = current->next;
    }
    printf("\n");
}

struct node *print_first_half_list(struct node *list) {
    int flag = 1;
    struct node *list2 = NULL;
    list2 = create_node(0);
    struct node *current = list->next;
    while (current != NULL && flag <= 4) {
        add_end(list2, create_node(current->info));
        current = current->next;
        flag++;
    }
    return list2;
}

struct node *print_second_half_list(struct node *list) {
    int flag = 1;
    struct node *list2 = NULL;
    list2 = create_node(0);
    struct node *current = list->next;
    while (current != NULL) {
        if (flag > 4) {
            add_end(list2, create_node(current->info));
            current = current->next;
            flag++;
        } else {
            current = current->next;
            flag++;
        }
    }
    return list2;
}


struct node *random1() {
    struct node *list = NULL;
    srand(time(NULL));
    int rand_num = 0;
    list = create_node(rand_num);
    int cnt = 1;
    struct node *current;
    while (cnt <= 8) {
        int rand_number = rand() % 8 + 1;
        int flag = 0;
        for (current = list; current != NULL; current = current->next) {
            if (rand_number == current->info) {
                flag = 1;
            }
        }
        if (flag == 0) {
            add_end(list, create_node(rand_number));
            cnt++;
        }
    }
    return list;
}

int mr_jack;

void who_is_jack() {
    srand(time(NULL));
    int rand_number = rand() % 8 + 1;
    if (rand_number == 1) {
        printf("mr_jack is sh\n");
        mr_jack = 1;
    } else if (rand_number == 2) {
        printf("mr_jack is jb\n");
        mr_jack = 2;
    } else if (rand_number == 3) {
        printf("mr_jack is wg\n");
        mr_jack = 3;
    } else if (rand_number == 4) {
        printf("mr_jack is il\n");
        mr_jack = 4;
    } else if (rand_number == 5) {
        printf("mr_jack is jw\n");
        mr_jack = 5;
    } else if (rand_number == 6) {
        printf("mr_jack is ms\n");
        mr_jack = 6;
    } else if (rand_number == 7) {
        printf("mr_jack is sg\n");
        mr_jack = 7;
    } else if (rand_number == 8) {
        printf("mr_jack is js\n");
        mr_jack = 8;
    }
}

struct node *suspect_list = NULL;

void suspect() {
    suspect_list = create_node(0);
    for (int i = 1; i <= 8; i++) {
        if (i != mr_jack) {
            add_end(suspect_list, create_node(i));
        }
    }
}

void delete(struct node **list, int num) {
    struct node *temp;
    if ((*list)->info == num) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    } else {
        struct node *current = *list;
        while (current->next != NULL) {
            if (current->next->info == num) {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            } else
                current = current->next;
        }
    }
}

void show_suspect() {
    struct node *current = suspect_list->next;
    if (current->info != mr_jack) {
        if (current->info == 1) {
            printf("mr_jack is not sh\n");
        }
        if (current->info == 2) {
            printf("mr_jack is not jb\n");
        }
        if (current->info == 3) {
            printf("mr_jack is not wg\n");
        }
        if (current->info == 4) {
            printf("mr_jack is not il\n");
        }
        if (current->info == 5) {
            printf("mr_jack is not jw\n");
        }
        if (current->info == 6) {
            printf("mr_jack is not ms\n");
        }
        if (current->info == 7) {
            printf("mr_jack is not sg\n");
        }
        if (current->info == 8) {
            printf("mr_jack is not js\n");
        }
    }
    delete(&suspect_list, current->info);
}

void start_game() {
    printf("welcome to mr_jack game\n");
    printf("enter your selection:\n1) player1:mr_jack  player2:sleuth\n2) player1:sleuth  player2:mr_jack\n");
    int select;
    scanf("%d", &select);
    if (select != 1 && select != 2) {
        printf("selection is invalid");
        start_game();
    }
    who_is_jack();
    suspect();
}


void set_map();

int get_choice();

void game_menu();

void start_menu();

void move(int location) {
    int i = 0, j = 0;
    for (int h = 0; h < 11; h++) {
        for (int k = 0; k < 15; k++) {
            if (map[h][k].number == location) {
                j = h + 1;
                i = k + 1;
            }
        }
    }
    printf("if you want to move, enter the appropriate number:\n"
           "1)up\n"
           "2)down\n"
           "3)up_right\n"
           "4)up_left\n"
           "5)down_right\n"
           "6)down_left\n");
    printf("%d %d\n", i, j);
    printf("%d\n", map[i][j + 1].number);
    int select;
    scanf("%d", &select);
    if (select == 1) {
        if (map[i][j + 1].block_number == 15) {
            int block_number_temp;
            block_number_temp = map[i][j + 1].block_number;
            map[i][j + 1].block_number = map[i][j].block_number;
            map[i][j].block_number = block_number_temp;
        } else
            printf("invalid move\n");
    } else if (select == 2) {
        if (map[i][j - 1].block_number == 15) {
            int block_number_temp;
            block_number_temp = map[i][j - 1].block_number;
            map[i][j - 1].block_number = map[i][j].block_number;
            map[i][j].block_number = block_number_temp;
        } else
            printf("invalid move\n");


    } else if (select == 3) {
        if (map[i + 1][j + 1].block_number == 15) {
            int block_number_temp;
            block_number_temp = map[i + 1][j + 1].block_number;
            map[i + 1][j + 1].block_number = map[i][j].block_number;
            map[i][j].block_number = block_number_temp;
        } else
            printf("invalid move\n");


    } else if (select == 4) {
        if (map[i - 1][j + 1].block_number == 15) {
            int block_number_temp;
            block_number_temp = map[i - 1][j + 1].block_number;
            map[i - 1][j + 1].block_number = map[i][j].block_number;
            map[i][j].block_number = block_number_temp;
        } else
            printf("invalid move\n");


    } else if (select == 5) {
        if (map[i + 1][j].block_number == 15) {
            int block_number_temp;
            block_number_temp = map[i + 1][j].block_number;
            map[i + 1][j].block_number = map[i][j].block_number;
            map[i][j].block_number = block_number_temp;
        } else
            printf("invalid move\n");


    } else if (select == 6) {
        if (map[i - 1][j].block_number == 15) {
            int block_number_temp;
            block_number_temp = map[i - 1][j].block_number;
            map[i - 1][j].block_number = map[i][j].block_number;
            map[i][j].block_number = block_number_temp;
        } else
            printf("invalid move\n");

    } else {
        printf("incorrect input");
        move(location);
    }

}

void turn_on_way();

void turn_on_lamp();

void change_token();

void action_sh() {
    printf("enter number of move (1 to 3):\n");
    int move_num;
    scanf("%d", &move_num);
    if (move_num > 3) {
        printf("invalid number of move\n");
        while (move_num > 3) {
            printf("invalid number of move\n");
            scanf("%d", &move_num);
        }
    }
    int i = 0, j = 0;
    for (int x = 0; x < move_num; x++) {
        for (int h = 0; h < 11; h++) {
            for (int k = 0; k < 15; k++) {
                if (map[h][k].block_number == 11) {
                    j = h + 1;
                    i = k + 1;
                }
            }
        }
        move(map[i][j].number);
    }
    show_suspect();
}

void action_jb() {

}

void action_wg() {

}

void action_il() {
    printf("enter number of move (1 to 3):\n");
    int move_num;
    scanf("%d", &move_num);
    if (move_num > 3) {
        printf("invalid number of move\n");
        while (move_num > 3) {
            printf("invalid number of move\n");
            scanf("%d", &move_num);
        }
    }
    int i = 0, j = 0;
    for (int x = 0; x < move_num; x++) {
        for (int h = 0; h < 11; h++) {
            for (int k = 0; k < 15; k++) {
                if (map[h][k].block_number == 9) {
                    j = h + 1;
                    i = k + 1;
                }
            }
        }
        move(map[i][j].number);
    }
    //change_token();
}


void action_jw() {
    printf("enter number of move (1 to 3):\n");
    int move_num;
    scanf("%d", &move_num);
    if (move_num > 3) {
        printf("invalid number of move\n");
        action_jw();
    }
    int i = 0, j = 0;
    for (int x = 0; x < move_num; x++) {
        for (int h = 0; h < 11; h++) {
            for (int k = 0; k < 15; k++) {
                if (map[h][k].block_number == 7) {
                    j = h + 1;
                    i = k + 1;
                }
            }
        }
        move(map[i][j].number);
    }
    //turn_on_way();
}

void action_ms() {

}

void action_sg() {

}

void action_js() {
    printf("if you want to move after turn on lamp:enter 1\nbackwards:enter 2");
    int chose;
    scanf("%d", &chose);
    if (chose != 1 && chose != 2) {
        printf("invalid chose\n");
        action_js();
    }
    if (chose == 1) {
        printf("enter number of move (1 to 3):\n");
        int move_num;
        scanf("%d", &move_num);
        if (move_num > 3) {
            printf("invalid number of move\n");
            while (move_num > 3) {
                printf("invalid number of move\n");
                scanf("%d", &move_num);
            }
        }
        int i = 0, j = 0;
        for (int x = 0; x < move_num; x++) {
            for (int h = 0; h < 11; h++) {
                for (int k = 0; k < 15; k++) {
                    if (map[h][k].block_number == 10) {
                        j = h + 1;
                        i = k + 1;
                    }
                }
            }
            move(map[i][j].number);
        }
        //  turn_on_lamp();
    }
    if (chose == 2) {
        //   turn_on_lamp();
        printf("enter number of move (1 to 3):\n");
        int move_num;
        scanf("%d", &move_num);
        if (move_num > 3) {
            printf("invalid number of move\n");
            while (move_num > 3) {
                printf("invalid number of move\n");
                scanf("%d", &move_num);
            }
        }
        int i = 0, j = 0;
        for (int x = 0; x < move_num; x++) {
            for (int h = 0; h < 11; h++) {
                for (int k = 0; k < 15; k++) {
                    if (map[h][k].block_number == 10) {
                        j = h + 1;
                        i = k + 1;
                    }
                }
            }
            move(map[i][j].number);
        }
    }
}


void action(int n) {
    if (n == 1)
        action_sh;
    if (n == 2)
        action_jb;
    if (n == 3)
        action_wg;
    if (n == 4)
        action_il;
    if (n == 5)
        action_jw;
    if (n == 6)
        action_ms;
    if (n == 7)
        action_sg;
    if (n == 8)
        action_js;
}

void print_game_page();

void handle_odd_round(struct node *list) {
    print_list_with_char(list);
    for (int i = 0; i < 4; i++) {
        if (i == 0 || i == 3) {
            int flag = 0;
            while (flag == 0) {
                printf("sleuth enter the number of character\n");
                int num;
                scanf("%d", &num);
                struct node *curr;
                for (curr = list->next; curr != NULL;) {
                    if (num == curr->info)
                        flag = 1;
                    curr = curr->next;
                }
                if (flag == 0) {
                    printf("invalid input\n");
                } else {
                    action(num);
                    delete(&list, num);

                }
            }
        } else {
            int flag = 0;
            while (flag == 0) {
                printf("mr_jack enter the number of character\n");
                int num;
                scanf("%d", &num);
                struct node *curr;
                for (curr = list->next; curr != NULL;) {
                    if (num == curr->info)
                        flag = 1;
                    curr = curr->next;
                }
                if (flag == 0) {
                    printf("invalid input\n");
                } else {
                    action(num);
                    delete(&list, num);

                }
            }
        }
    }
}

void handle_even_round(struct node *list) {
    print_list_with_char(list);
    for (int i = 0; i < 4; i++) {
        if (i == 0 || i == 3) {
            int flag = 0;
            while (flag == 0) {
                printf("mr_jack enter the number of character\n");
                int num;
                scanf("%d", &num);
                struct node *curr;
                for (curr = list->next; curr != NULL;) {
                    if (num == curr->info)
                        flag = 1;
                    curr = curr->next;
                }
                if (flag == 0) {
                    printf("invalid input\n");
                } else {
                    action(num);
                    delete(&list, num);

                }
            }
        } else {
            int flag = 0;
            while (flag == 0) {
                printf("sleuth enter the number of character\n");
                int num;
                scanf("%d", &num);
                struct node *curr;
                for (curr = list->next; curr != NULL;) {
                    if (num == curr->info)
                        flag = 1;
                    curr = curr->next;
                }
                if (flag == 0) {
                    printf("invalid input\n");
                } else {
                    action(num);
                    delete(&list, num);

                }
            }
        }
    }

}

void print_in_mid(char a[5], int x) {
    int leni = 0;
    int temp = x;
    while (temp > 0) {
        temp /= 10;
        leni++;
    }
    if (leni == 3) {
        int len = strlen(a);
        int space1 = (4 - len) / 2;
        printf("%d", x);
        for (int i = 0; i < space1; i++) {
            printf(" ");
        }
        printf("%s", a);
        for (int i = 0; i < (4 - space1 - len); ++i) {
            printf(" ");
        }
    }
    if (leni == 2) {
        int len = strlen(a);
        int space1 = (5 - len) / 2;
        printf("%d", x);
        for (int i = 0; i < space1; i++) {
            printf(" ");
        }
        printf("%s", a);
        for (int i = 0; i < (5 - space1 - len); ++i) {
            printf(" ");
        }
    }
    if (leni == 1) {
        int len = strlen(a);
        int space1 = (6 - len) / 2;
        printf("%d", x);
        for (int i = 0; i < space1; i++) {
            printf(" ");
        }
        printf("%s", a);
        for (int i = 0; i < (6 - space1 - len); ++i) {
            printf(" ");
        }
    }
}

void print_map() {
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
                    printf("\\");
                    print_in_mid(convert(map[flag1 - flag2][(2 * j)].block_number), map[flag1 - flag2][(2 * j)].number);
                    printf("/     ");
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
                    printf("/     \\");
                    print_in_mid(convert(map[flag3 - flag4][(2 * j) + 1].block_number),
                                 map[flag3 - flag4][(2 * j) + 1].number);
                    printf("");
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
    int flag = 1;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            map[i][j].number = flag;
            flag++;
        }
    }
    /* start_game();
     print_map();
     printf("\n");
     int round = 1;
     while ((round) < 9) {
         print_map();
         printf("\n");
         struct node *list = random1();
         struct node *list1 = print_first_half_list(list);
         struct node *list2 = print_second_half_list(list);
         printf("round is %d\n", round);
         if (round % 2 == 1) {
             handle_odd_round(list1);
         } else {
             handle_even_round(list2);
         }
         round++;
     }*/
    return 0;
}