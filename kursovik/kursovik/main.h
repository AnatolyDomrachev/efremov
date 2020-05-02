#ifndef _ONE_H_ //директивы препроцессора нужны, чтобы этот код добавлялся в компилируемуй код только 1 раз
#define _ONE_H_

extern int N; //глобальные переменные - доступные из любой функции
extern double ** T;

//объявление всех функций
void end();
void nothing();
void reshenie();
void reshenie_1();
void reshenie_2();
void sohr();
void sohr_1();
void sohr_2();
void vost();
void vost_1();
void vost_2();
void vvod();
void vvod_1();
void vvod_2();
int vybor(int max_num);
void vyvod();
void vyvod_1();

#endif
