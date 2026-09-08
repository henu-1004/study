#include <curses.h>

int main() {
    // PDCurses 초기화
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int x = 0, y = 0;
    int ch;

    while (1) {
        

        // 키 입력 받기
        ch = getch();
        // 이전 위치에 공백 문자 출력으로 'X' 지우기
        
        refresh();
        // 화살표 키 처리
        switch (ch) {
        case KEY_UP:
            y--;
            move(y, x);
            break;
        case KEY_DOWN:
            y++;
            move(y, x);
            break;
        case KEY_LEFT:
            x--;
            move(y, x);
            break;
        case KEY_RIGHT:
            x++;
            move(y, x);
            break;
        }

        // 화면 갱신
        refresh();

        // F2 키를 누르면 루프 종료
        if (ch == KEY_F(2)) {
            break;
        }
    }

    // PDCurses 종료
    endwin();

    return 0;
}
