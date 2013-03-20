/***************************************************************************
 * Коварная бомба Доктора Зло, Версия 1.1
 * Копирайт 2011, ЗАО "Доктор Зло". Все права защищены.
 *
 * ЛИЦЕНЗИЯ:
 *
 * ЗАО "Доктор Зло" (далее ЗЛОУМЫШЛЕННИК) даёт вам (далее ЖЕРТВЕ) явное
 * разрешение на пользование этой бомбой (далее БОМБОЙ). Эта лицензия
 * ограничена во времени и заканчивается со смертью ЖЕРТВЫ.
 * ЗЛОУМЫШЛЕННИК не несёт ответственности за повреждения, расстройство,
 * безумие, красногласие, синдром запястного канала, потерю сна или
 * другой вред, причинённый ЖЕРТВЕ. Это, конечно, если он не захочет
 * взять всё это на себя. ЖЕРТВА не может передавать исходный
 * код этой бомбы противникам ЗЛОУМЫШЛЕННИКА. Никакая ЖЕРТВА не может
 * отлаживать, декомпилировать, дешифровать, запускать программу "strings",
 * прибегать к обратной разработке, или вообще каким-нибудь образом
 * узнавать что-то о БОМБЕ. Для использования этой программы
 * не требуется специальной бомбозащитной одежды. ЗЛОУМЫШЛЕННИК не
 * собирается извиняться за своё чувство юмора. Эта лицензия
 * не распространяется на места, где БОМБА запрещена законом.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/* 
 * Не забыть стереть этот файл, чтобы мои жертвы не догадались, что
 * происходит, тогда их ошмётки разлетятся красивее всего.
 * -- Доктор Зло
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* Кстати, надо не забыть портировать эту бомбу на Windows
     * и забабахать красивенький интерфейс к ней. */

    /* При запуске без аргументов бомба читает данные из стандартного
     * потока ввода. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* При запуске с одним аргументом <файл> бомба читает данные из <файла>,
     * пока не достигнет EOF, а затем переключается на стандартный поток
     * ввода. Так что, решив очередную фазу, вы можете добавить строку с решением
     * в <файл>, чтобы каждый раз не набирать её заново. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Ошибка: не удалось открыть %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* Нельзя запускать бомбу более чем с одним аргументом командной строки. */
    else {
	printf("Использование: %s [<входной_файл>]\n", argv[0]);
	exit(8);
    }

    /* Сделаем всякие секретные штуки, чтобы бомбу было сложнее разрядить. */
    initialize_bomb();

    printf("Добро пожаловать в мою злодейскую бомбочку. У вас есть целых 6 фаз,\n");
    printf("на которых можно подорваться. Хорошего дня!\n");

    /* Хмм... Шесть фаз, должно быть, надёжнее, чем одна! */
    input = read_line();             /* Прочитать вход */
    phase_1(input);                  /* Запустить фазу */
    phase_defused();                 /* Чёрт! Они догадались!
				      * Интересно, как это у них получилось? */
    printf("Фаза 1 обезврежена. Как насчёт следующей?\n");

    /* Вторая фаза сложнее. Никто никогда не догадается, как её пройти... */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("Это номер 2. Продолжайте!\n");

    /* Пожалуй, пока что слишком просто. Немного кода посложнее, чтобы всех запутать. */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Уже на полупути!\n");

    /* Да ладно?! А с математикой у вас как? Вот такая есть задачка: */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("И эту обезвредили. А давайте теперь вот эту.\n");
    
    /* Идём-идём потихонечку в память. Когда остановимся, тогда и взрыв! */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Хорошо!  Следующая...\n");

    /* Эта фаза никогда не будет использована, так как никто никогда не пройдёт предыдущие.
     * Но сделаем её посложнее. Просто на всякий случай. */
    input = read_line();
    phase_6(input);
    phase_defused();

    /* Ого, у них получилось! Но ведь чего-то... не хватает? Может быть, 
       они где-то не доглядели? */
    
    return 0;
}
