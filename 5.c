#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
    1= barrage//2= house//3=off lamp//4=on lamp//5=open hole//6=escape//7=jw//8=wg//9=il//10=js//11=sh//12=jb//13=ms//14=sg
    //15=empty//16= close hole*/
typedef struct {
    int block_number;
    char name[20];
    char symbol[5];
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
{3,"off lamp",'off_L'}
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
                             {13, "MS",    "MS"},
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
                             {3,  "off lamp",  "off_L"},
                             {15, "empty", ' '},
                             {2,  "house", 'H'},
                             {4,  "on lamp", "on_L"},
                             {15, "empty",      ' '},
                             {2,  "house",     'H'},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {15, "empty",     ' '},
                             {4,  "on lamp", "on_L"},
                             {15, "empty",      ' '},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {11, "SH",    "SH"},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {15, "empty",   ' '},
                             {15, "empty",      ' '},
                             {15, "empty",     ' '},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {7,  "JW",        "JW"},
                             {15, "empty",   ' '},
                             {15, "empty",      ' '},
                             {2,  "house", 'H'},
                             {9,  "IL",    "IL"},
                             {4,  "on lamp",   "on_L"},
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
                             {12, "JB",    "JB"},
                             {15, "empty", ' '},
                             {15, "empty",   ' '},
                             {2,  "house",      'H'},
                             {14, "Sg",        "SG"},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {5,  "open hole", 'O'},
                             {2,  "house",   'H'},
                             {15, "empty",      ' '},
                             {2,  "house", 'H'},
                             {15, "empty", ' '},
                             {5,  "open hole", 'O'},
                             {10, "JS",    "JS"},
                             {4,  "on lamp",   "on_L"},
                             {15, "empty", ' '},
                             {2,  "house", 'H'},
                             {15, "empty",   ' '},
                             {15, "empty",      ' '},
                             {15, "empty",     ' '},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {15, "empty",   ' '},
                             {4,  "on lamp",    "on_L"},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {2,  "house",     'H'},
                             {15, "empty", ' '},
                             {15, "empty", ' '},
                             {15, "empty",   ' '},
                             {4,  "on lamp",    "on_L"},
                             {15, "empty",     ' '},
                             {2, "house", 'H'}},

                     {{2, "house", 'H'},
                             {2,  "house",     'H'},
                             {15, "empty",   ' '},
                             {2,  "house",      'H'},
                             {2,  "house", 'H'},
                             {8,  "WG",    "WG"},
                             {3,  "off lamp",  "off_L"},
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

void print_list(struct node *list) {
    struct node *current = list->next;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}


void print_first_half_list(struct node *list) {
    int flag = 1;
    struct node *current = list->next;
    while (current != NULL && flag <= 4) {
        printf("%d ", current->info);
        current = current->next;
        flag++;
    }
    printf("\n");
}

void print_second_half_list(struct node *list) {
    int flag = 1;
    struct node *current = list->next;
    while (current != NULL) {
        if (flag > 4) {
            printf("%d ", current->info);
            current = current->next;
            flag++;
        } else {
            current = current->next;
            flag++;
        }
    }
    printf("\n");
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


void start_game() {
    printf("enter your selection:\n1) player1:mr_jack  player2:sleuth\n2) player1:sleuth  player2:mr_jack\n");
    int select;
    scanf("%d", &select);
    if (select != 1 && select != 2) {
        printf("selection is invalid");
        start_game();
    }
}

void set_map();

int get_choice();

void game_menu();

void start_menu();

void action();

void print_game_page();

void handle_odd_round(struct node *list) {
    print_first_half_list(list);
    int input;
    scanf("%d", &input);
}


void handle_even_round(struct node *list) {
    print_second_half_list(list);
    int input;
    scanf("%d", &input);
}

void print_in_mid(char a[5]) {
    int len = strlen(a);
    int space1 = (7 - len) / 2;
    for (int i = 0; i < space1; i++) {
        printf(" ");
    }
    printf("%s", a);
    for (int i = 0; i < (7 - space1 - len); ++i) {
        printf(" ");
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
                    print_in_mid(map[flag1 - flag2][(2 * j)].symbol);
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
                    print_in_mid(map[flag3 - flag4][(2 * j) + 1].symbol);
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
    start_game();
    int round = 1;
    while ((round) > 0) {
        print_map();
        printf("\n");
        struct node *list = random1();
        print_list(list);
        print_first_half_list(list);
        print_second_half_list(list);
        printf("\n");
        if (round % 2) {
            handle_odd_round(list);
        } else {
            handle_even_round(list);
        }
        round--;
    }
    return 0;
}