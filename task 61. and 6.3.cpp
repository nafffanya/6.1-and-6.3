// task 61. and 6.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Date//наша структура, мини-класс
{
    unsigned short day, month, year;//наши поля

public:

    int how_many_days_have_passed(unsigned short day, unsigned short month, unsigned short year) {//кол-во дней с первого января первого года (учитываются только весокосные года, другие редчайшие случаи, сдвигающие дату (или добавляющие n дней), которые, как оказалось, были в нашей истории, не учитываются)

        int result = 0;//сюда будет складывать дни

        for (int i = 1; i < year; i++) { //учитываем тот факт, что при дате 01.01.0002 прошло не 2, а  1 год! Тоже самое и с 2003, например. Прошло 2002 года

            if (i % 4 == 0) {//если год високосный

                result += 366;

            }

            else {

                result += 365;

            }
        }

        for (int i = 1; i < month; i++) {//складываем дни прошедших месяцов с 1 (то есть это январь) до данного месяца, не включая


            result += determine_the_amount_of_days(i, year);


        }

        result += day - 1; //ну и складываем дни. -1 тут т.к. считаем данный день ещё не законченным

        return result;

    }

    int  determine_the_amount_of_days(unsigned short month, unsigned short year) {//наш метод

        switch (month) { //проверям месяц

        case 1://если январь, то...

            return 31;//31 день

            break;

        case 2://тут февраль и нужна ещё проверка на весокосный год

            if (year % 4 == 0) return 29;

            return 28;

            break;

        case 3://март

            return 31;

            break;

        case 4://апрель

            return 30;

            break;

        case 5://май

            return 31;

            break;

        case 6://июнь

            return 30;

            break;

        case 7://июль

            return 31;

            break;

        case 8://август

            return 31;

            break;

        case 9://сентябрь

            return 30;

            break;

        case 10://октябрь

            return 31;

            break;

        case 11://ноябрь

            return 30;

            break;

        case 12://декабрь

            return 31;

            break;

        default:

            return 0;//если неправильный месяц, пусть будет 0 дней. Но по факту тут может быть что угодно (например обработка ошибки: вызов исключения)

            break;

        }
    }
};

enum DayOfWeek { mn, td, wd, thd, fd, strd, sd }; //в данной проге это не нужно

using namespace std;

int main() {

    Date date; //создаём объект типа Дата

    cout << "Enter day: "; //вводим данные

    cin >> date.day;

    cout << "Enter month: ";

    cin >> date.month;

    cout << "Enter year: ";

    cin >> date.year;

    cout << "Your date: ";

    if (date.day <= 9) { cout << "0"; } //это для красивого вывода даты

    cout << date.day << ".";

    if (date.month <= 9) { cout << "0"; }  //и это. Чтобы вместо 9.9.2003 было 09.09.2003

    cout << date.month << ".";

    if (date.year <= 9) { cout << "0"; }

    if (date.year <= 99) { cout << "0"; }

    if (date.year <= 999) { cout << "0"; }

    cout << date.year << std::endl;

    cout << "There are " << date.determine_the_amount_of_days(date.month, date.year) << " days in this month" << endl;  //вызываем наш метод, определяющий кол-во дней в нашем месяце

    cout << date.how_many_days_have_passed(date.day, date.month, date.year) << " days have passed from January 1st of the first year to this date" << endl;

}