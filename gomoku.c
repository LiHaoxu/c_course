/* gomoku.c - 简洁终端五子棋
 * 编译:
 *   Linux/macOS:  gcc gomoku.c -o gomoku
 *   Windows(MinGW): gcc gomoku.c -o gomoku.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 15
#define EMPTY 0
#define BLACK 1
#define WHITE 2

typedef struct { int r, c; int player; } Move;

static int board[SIZE][SIZE];
static Move history[SIZE*SIZE];
static int move_count = 0;

void clear_board() {
    for (int i=0;i<SIZE;i++)
        for (int j=0;j<SIZE;j++)
            board[i][j]=EMPTY;
    move_count = 0;
}

void print_board() {
    // 列标题
    printf("\n    ");
    for (int c=0;c<SIZE;c++) {
        // A..O
        char ch = 'A' + c;
        printf("%2c ", ch);
    }
    printf("\n");

    for (int r=0;r<SIZE;r++) {
        // 行号(1..15)
        printf("%3d ", r+1);
        for (int c=0;c<SIZE;c++) {
            char cellChar = '.';
            if (board[r][c]==BLACK) cellChar='X';  // 黑子
            else if (board[r][c]==WHITE) cellChar='O'; // 白子
            printf(" %c ", cellChar);
        }
        printf(" %d\n", r+1);
    }
    // 再打一遍列标题
    printf("    ");
    for (int c=0;c<SIZE;c++) {
        char ch = 'A' + c;
        printf("%2c ", ch);
    }
    printf("\n\n");
}

int in_bounds(int r, int c) {
    return r>=0 && r<SIZE && c>=0 && c<SIZE;
}

// 检查最后一步(r,c)是否连五
int check_win_from(int r, int c) {
    int player = board[r][c];
    if (player==EMPTY) return 0;

    int dirs[4][2] = {
        {1,0},  // 垂直
        {0,1},  // 水平
        {1,1},  // 斜下右
        {1,-1}  // 斜下左
    };

    for (int d=0; d<4; d++) {
        int dr=dirs[d][0], dc=dirs[d][1];
        int count = 1;

        // 正向
        for (int k=1;;k++){
            int nr=r+dr*k, nc=c+dc*k;
            if (!in_bounds(nr,nc) || board[nr][nc]!=player) break;
            count++;
        }
        // 反向
        for (int k=1;;k++){
            int nr=r-dr*k, nc=c-dc*k;
            if (!in_bounds(nr,nc) || board[nr][nc]!=player) break;
            count++;
        }

        if (count>=5) return 1;
    }
    return 0;
}

int is_draw() {
    return move_count >= SIZE*SIZE;
}

int place_stone(int r, int c, int player) {
    if (!in_bounds(r,c)) return 0;
    if (board[r][c]!=EMPTY) return 0;
    board[r][c] = player;
    history[move_count].r = r;
    history[move_count].c = c;
    history[move_count].player = player;
    move_count++;
    return 1;
}

int undo_move() {
    if (move_count<=0) return 0;
    move_count--;
    int r = history[move_count].r;
    int c = history[move_count].c;
    board[r][c]=EMPTY;
    return 1;
}

void flush_stdin() {
    int ch;
    while ((ch=getchar())!='\n' && ch!=EOF) {}
}

// 解析输入：支持 "row col"（1..15），或 "ColRow"（如 H8 / h8）
// 返回1表示解析成功；输出为0-based的(r,c)
int parse_input(const char* s, int* out_r, int* out_c) {
    // 去首尾空白
    char buf[64];
    int len = 0;
    for (int i=0; s[i] && i<(int)sizeof(buf)-1; i++) {
        if (s[i]!='\r' && s[i]!='\n') buf[len++]=s[i];
    }
    buf[len]='\0';
    // 跳过前后空格
    int start=0, end=len-1;
    while (start<=end && isspace((unsigned char)buf[start])) start++;
    while (end>=start && isspace((unsigned char)buf[end])) end--;
    if (start>end) return 0;

    // 尝试 "row col"
    int r=0, c=0;
    {
        int rr=0, cc=0;
        // 允许多个空格/逗号
        char tmp[64];
        int ti=0;
        for (int i=start;i<=end && ti<(int)sizeof(tmp)-1;i++) {
            char ch = buf[i];
            if (ch==',' ) ch=' ';
            tmp[ti++]=ch;
        }
        tmp[ti]='\0';

        if (sscanf(tmp, "%d %d", &rr, &cc)==2) {
            if (rr>=1 && rr<=SIZE && cc>=1 && cc<=SIZE) {
                *out_r = rr-1;
                *out_c = cc-1;
                return 1;
            }
        }
    }

    // 尝试 "ColRow"：字母+数字（如 H8 或 h8；也支持 A10、O15）
    {
        char colChar = 0;
        int rowNum = -1;
        // 找到第一个字母作为列
        int i = start;
        while (i<=end && !isalpha((unsigned char)buf[i])) i++;
        if (i<=end && isalpha((unsigned char)buf[i])) {
            colChar = toupper((unsigned char)buf[i]);
            i++;
            // 后续应是数字
            if (i<=end && isdigit((unsigned char)buf[i])) {
                rowNum = atoi(&buf[i]);
            }
        }
        if (colChar>='A' && colChar<='A'+SIZE-1 && rowNum>=1 && rowNum<=SIZE) {
            *out_r = rowNum - 1;
            *out_c = (colChar - 'A');
            return 1;
        }
    }

    return 0;
}

void print_help() {
    printf("指令说明：\n");
    printf("  下子坐标： 采用“行 列”或“字母数字”\n");
    printf("    例：8 8    或   H8\n");
    printf("  u  : 悔棋一步\n");
    printf("  r  : 重开新局\n");
    printf("  q  : 退出游戏\n");
    printf("\n");
}

int main(void) {
    printf("=== 终端五子棋（C语言）===\n");
    printf("棋子: 黑(X) 先手，白(O) 后手；连五即胜。\n");
    print_help();

    clear_board();
    int current = BLACK;

    while (1) {
        print_board();
        printf("轮到%s，请输入坐标或指令(u悔棋/r重开/q退出)：",
               (current==BLACK ? "黑棋(X)" : "白棋(O)"));
        char line[128];
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n输入结束，退出。\n");
            break;
        }

        // 去掉首尾空白，小写化第一个非空字符判断命令
        int i=0; while (line[i] && isspace((unsigned char)line[i])) i++;
        char cmd = tolower((unsigned char)line[i]);

        if (cmd=='q') {
            printf("已退出游戏，再见！\n");
            break;
        } else if (cmd=='r') {
            clear_board();
            current = BLACK;
            printf("已重开新局，黑棋先行。\n");
            continue;
        } else if (cmd=='u') {
            if (undo_move()) {
                // 悔棋后轮到刚刚下子的玩家
                current = (current==BLACK ? WHITE : BLACK);
                printf("已悔棋一步。\n");
            } else {
                printf("没有可悔的棋。\n");
            }
            continue;
        } else {
            int r, c;
            if (!parse_input(line, &r, &c)) {
                printf("坐标解析失败。示例：8 8 或 H8。输入 u/r/q 可悔棋/重开/退出。\n");
                continue;
            }
            if (!place_stone(r, c, current)) {
                printf("该位置不可下（越界或已占）。请重新输入。\n");
                continue;
            }

            if (check_win_from(r, c)) {
                print_board();
                printf("恭喜！%s 获胜！\n", (current==BLACK ? "黑棋(X)" : "白棋(O)"));
                printf("输入 r 重开新局，或 q 退出。\n");
                // 等待下一步指令循环
            } else if (is_draw()) {
                print_board();
                printf("和棋！棋盘已满。\n");
                printf("输入 r 重开新局，或 q 退出。\n");
            } else {
                // 轮转
                current = (current==BLACK ? WHITE : BLACK);
            }
        }
    }

    return 0;
}
