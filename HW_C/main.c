#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y 2
#define DELAY 0.1

const char usage[] = "Use arrows for control. Press 'F10' for EXIT";

enum
{
    LEFT = 1,
    UP,
    RIGHT,
    DOWN,
    STOP_GAME = KEY_F(10)
};
enum
{
    MAX_TAIL_SIZE = 100,
    START_TAIL_SIZE = 15,
    MAX_FOOD_SIZE = 20,
    FOOD_EXPIRE_SECONDS = 10
};

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; i++)
    {
        t[i] = init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t *tail = (tail_t *)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);

    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size + 1;
    head->controls = default_controls;
}

/*
 Движение головы с учетом текущего направления движения
 Реализовано циклическое движение во всех направлениях
 Перенесена отрисовка головы в goTail(), происходит так как затирается голова при "гонке за хвостом"
 и уменьшается размер кода
 */
void go(struct snake_t *head)
{
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    switch (head->direction)
    {
    case LEFT:
        if (head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
            head->x = max_x;
        else
            --(head->x);
        break;
    case RIGHT:
        if (head->x >= max_x)
            head->x = 0;
        else
            ++(head->x);
        break;
    case UP:
        if (head->y <= MIN_Y)
            head->y = max_y;
        else
            --(head->y);
        break;
    case DOWN:
        if (head->y >= max_y)
            head->y = MIN_Y;
        else
            ++(head->y);
        break;
    default:
        break;
    }
}
/*
Функция изменения направления движения.
Реализовано блокирование возможности движения в рекопротивоположном направлении
*/
void changeDirection(struct snake_t *snake, const int32_t key)
{

    if (key == snake->controls.down)
    {
        if (snake->direction != UP)
            snake->direction = DOWN;
    }
    else if (key == snake->controls.up)
    {
        if (snake->direction != DOWN)
            snake->direction = UP;
    }
    else if (key == snake->controls.right)
    {
        if (snake->direction != LEFT)
            snake->direction = RIGHT;
    }
    else if (key == snake->controls.left)
    {
        if (snake->direction != RIGHT)
            snake->direction = LEFT;
    }
}

/*
 Движение хвоста с учетом движения головы
 дополнена отрисовкой головы
 */
void goTail(struct snake_t *head)
{
    char tail_ch = '*';

    mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");
    for (size_t i = head->tsize - 1; i > 0; i--)
    {
        head->tail[i] = head->tail[i - 1];
        if (head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", tail_ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
    mvprintw(head->tail[0].y, head->tail[0].x, "%c", '@');
    refresh();
}
/*
Проверка столкновения с хвостом
*/
int checkCollisions(struct snake_t *snake)
{
    for (size_t i = 1; i <= snake->tsize; i++)
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
            return -1;
    return 0;
}

int main()
{
    snake_t *snake = (snake_t *)malloc(sizeof(snake_t));
    clock_t begin;
    initSnake(snake, START_TAIL_SIZE, 10, 10);
    initscr();

    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();             // Отключаем echo() режим при вызове getch
    curs_set(FALSE);      // Отключаем курсор
    mvprintw(0, 1, usage);
    refresh();
    timeout(0); // Отключаем таймаут после нажатия клавиши в цикле

    int key_pressed = snake->direction;
    while (key_pressed != STOP_GAME)
    {
        begin = clock();
        key_pressed = getch(); // Считываем клавишу
        go(snake);
        goTail(snake);
        // обработка столкновения с хвостом
        if (checkCollisions(snake) == -1)
        {
            mvprintw(0, strlen(usage) + 10, "WASTED");
            while (getch() != STOP_GAME)
            {
            }
            break;
        }
        changeDirection(snake, key_pressed);
        // Задержка при отрисовке
        while ((double)(clock() - begin) / CLOCKS_PER_SEC < DELAY) 
        {
        }
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}