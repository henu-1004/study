#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

typedef struct DNode {
    char* str;
    struct DNode* up;
    struct DNode* down;
} node;

node* head = NULL; // 맨 위의 노드를 가리키는 포인터
node* curNode = NULL; // 현재 위치한 노드를 가리키는 포인터
node* tail = NULL;

node* getN() {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->str = NULL;
    newnode->up = NULL;
    newnode->down = NULL;
    return newnode;
}

void insertNode(char* str) {
    node* newNode = getN();
    newNode->str = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(newNode->str, str);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->down = newNode;
        newNode->up = tail;
        tail = newNode;
    }
    curNode = newNode;
}

int main() {
    initscr();
    cbreak();
    noecho();
    raw();
    keypad(stdscr, TRUE);

    char* inputStr = NULL;
    int strSize = 0;
    int ch;
    int x = 0, y = 0;

    while (1) {
        ch = getch();
        if (ch == 13) {
            y++;
            insertNode(inputStr);
            free(inputStr);
            inputStr = NULL;
            strSize = 0;
        }
        if (ch == KEY_F(2)) {
            break;
        }
        strSize++;

        inputStr = (char*)realloc(inputStr, (strSize + 1) * sizeof(char));
        if (inputStr == NULL) {
            printf("메모리 할당 실패");
            return 1;
        }

        inputStr[strSize - 1] = ch;
        inputStr[strSize] = '\0';
        mvprintw(y, 0, "%s", inputStr);
        refresh();
    }

    // 나머지 문자열 및 노드를 해제합니다.
    free(inputStr);
    while (head != NULL) {
        node* temp = head;
        head = head->down;
        free(temp->str);
        free(temp);
    }

    endwin();
    return 0;
}
