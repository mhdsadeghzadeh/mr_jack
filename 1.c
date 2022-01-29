#include <stdio.h>
#include <stdlib.h>

typedef struct {
    /*
     1= barrage//2= house//3=off lamp//4=on lamp//5=open hole//6=escape//7=jw//8=wg//9=il//10=js//11=sh//12=jb//13=ms//14=sg
     //15=empty//16= close hole*/
    int state;

} map;

void init() {
    map initial[11][15];
    initial[0][0].state = 2;
    initial[0][1].state = 2;
    initial[0][2].state = 2;
    initial[0][3].state = 2;
    initial[0][4].state = 2;
    initial[0][5].state = 2;
    initial[0][6].state = 2;
    initial[0][7].state = 2;
    initial[0][8].state = 2;
    initial[0][9].state = 2;
    initial[0][10].state = 2;
    initial[0][11].state = 2;
    initial[0][12].state = 2;
    initial[0][13].state = 2;
    initial[0][14].state = 2;

    initial[1][0].state = 2;
    initial[1][1].state = 2;
    initial[1][2].state = 1;
    initial[1][3].state = 2;
    initial[1][4].state = 2;
    initial[1][5].state = 2;
    initial[1][6].state = 2;
    initial[1][7].state = 15;
    initial[1][8].state = 5;
    initial[1][9].state = 13;
    initial[1][10].state = 2;
    initial[1][11].state = 2;
    initial[1][12].state = 6;
    initial[1][13].state = 2;
    initial[1][14].state = 2;

    initial[2][0].state = 2;
    initial[2][1].state = 15;
    initial[2][2].state = 15;
    initial[2][3].state = 16;
    initial[2][4].state = 2;
    initial[2][5].state = 15;
    initial[2][6].state = 15;
    initial[2][7].state = 15;
    initial[2][8].state = 3;
    initial[2][9].state = 15;
    initial[2][10].state = 2;
    initial[2][11].state = 4;
    initial[2][12].state = 15;
    initial[2][13].state = 2;
    initial[2][14].state = 2;

    initial[3][0].state = 2;
    initial[3][1].state = 15;
    initial[3][2].state = 4;
    initial[3][3].state = 15;
    initial[3][4].state = 15;
    initial[3][5].state = 15;
    initial[3][6].state = 2;
    initial[3][7].state = 11;
    initial[3][8].state = 2;
    initial[3][9].state = 15;
    initial[3][10].state = 15;
    initial[3][11].state = 15;
    initial[3][12].state = 15;
    initial[3][13].state = 15;
    initial[3][14].state = 2;

    initial[4][0].state = 2;
    initial[4][1].state = 7;
    initial[4][2].state = 15;
    initial[4][3].state = 15;
    initial[4][4].state = 2;
    initial[4][5].state = 9;
    initial[4][6].state = 4;
    initial[4][7].state = 15;
    initial[4][8].state = 5;
    initial[4][9].state = 15;
    initial[4][10].state = 2;
    initial[4][11].state = 2;
    initial[4][12].state = 2;
    initial[4][13].state = 5;
    initial[4][14].state = 2;

    initial[5][0].state = 2;
    initial[5][1].state = 15;
    initial[5][2].state = 2;
    initial[5][3].state = 2;
    initial[5][4].state = 15;
    initial[5][5].state = 15;
    initial[5][6].state = 2;
    initial[5][7].state = 15;
    initial[5][8].state = 2;
    initial[5][9].state = 12;
    initial[5][10].state = 15;
    initial[5][11].state = 15;
    initial[5][12].state = 2;
    initial[5][13].state = 14;
    initial[5][14].state = 2;

    initial[6][0].state = 2;
    initial[6][1].state = 5;
    initial[6][2].state = 2;
    initial[6][3].state = 15;
    initial[6][4].state = 2;
    initial[6][5].state = 15;
    initial[6][6].state = 5;
    initial[6][7].state = 10;
    initial[6][8].state = 4;
    initial[6][9].state = 15;
    initial[6][10].state = 2;
    initial[6][11].state = 15;
    initial[6][12].state = 15;
    initial[6][13].state = 15;
    initial[6][14].state = 2;

    initial[7][0].state = 2;
    initial[7][1].state = 2;
    initial[7][2].state = 15;
    initial[7][3].state = 4;
    initial[7][4].state = 15;
    initial[7][5].state = 15;
    initial[7][6].state = 2;
    initial[7][7].state = 15;
    initial[7][8].state = 2;
    initial[7][9].state = 15;
    initial[7][10].state = 15;
    initial[7][11].state = 15;
    initial[7][12].state = 4;
    initial[7][13].state = 15;
    initial[7][14].state = 2;

    initial[8][0].state = 2;
    initial[8][1].state = 2;
    initial[8][2].state = 15;
    initial[8][3].state = 2;
    initial[8][4].state = 2;
    initial[8][5].state = 8;
    initial[8][6].state = 3;
    initial[8][7].state = 15;
    initial[8][8].state = 15;
    initial[8][9].state = 2;
    initial[8][10].state = 2;
    initial[8][11].state = 2;
    initial[8][12].state = 16;
    initial[8][13].state = 2;
    initial[8][14].state = 2;

    initial[9][0].state = 2;
    initial[9][1].state = 2;
    initial[9][2].state = 6;
    initial[9][3].state = 2;
    initial[9][4].state = 2;
    initial[9][5].state = 2;
    initial[9][6].state = 5;
    initial[9][7].state = 2;
    initial[9][8].state = 2;
    initial[9][9].state = 2;
    initial[9][10].state = 2;
    initial[9][11].state = 2;
    initial[9][12].state = 1;
    initial[9][13].state = 2;
    initial[9][14].state = 2;

    initial[10][0].state = 2;
    initial[10][1].state = 2;
    initial[10][2].state = 2;
    initial[10][3].state = 2;
    initial[10][4].state = 2;
    initial[10][5].state = 2;
    initial[10][6].state = 2;
    initial[10][7].state = 2;
    initial[10][8].state = 2;
    initial[10][9].state = 2;
    initial[10][10].state = 2;
    initial[10][11].state = 2;
    initial[10][12].state = 2;
    initial[10][13].state = 2;
    initial[10][14].state = 2;

    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 15; j++) {
            switch (initial[i][j].state) {
                case 1:
                    printf("%10s","close escape");
                    break;
                case 2:
                    printf("%10s","house");
                    break;
                case 3:
                    printf("%10s","off lamp");
                    break;
                case 4:
                    printf("%10s","on lamp");
                    break;
                case 5:
                    printf("%10s","open hole");
                    break;
                case 6:
                    printf("%10s","open escape");
                    break;
                case 7:
                    printf("%10s","JW");
                    break;
                case 8:
                    printf("%10s","WG");
                    break;
                case 9:
                    printf("%10s","IL");
                    break;
                case 10:
                    printf("%10s","JS");
                    break;
                case 11:
                    printf("%10s","SH");
                    break;
                case 12:
                    printf("%10s","JB");
                    break;
                case 13:
                    printf("%10s","MS");
                    break;
                case 14:
                    printf("%10s","SG");
                    break;
                case 15:
                    printf("%10s","empty");
                    break;
                case 16:
                    printf("%10s","close hole");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    printf("welcome to mr.jack game\nenter mode of player\n1) player 1: mr.jack & player 2: sleuth\n2) player 1: sleuth & player 2: mr.jack\n");
    int chose;
    scanf("%d", &chose);
    init();
    return 0;
}