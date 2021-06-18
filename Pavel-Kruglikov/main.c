// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

struct contact
{
    char name[20];
    char surname[20];
    char work_place[30];
    unsigned long long phone_number;
    struct date birthday;
    struct event* ev;
    struct contact* next;
};
struct event
{
    char title[30];
    unsigned long long duration_hour;
    unsigned long long duration_min;
    char place[30];
    struct date dt;
    char note[100];
    struct event* next;
};

struct date
{
    int day;
    int mon;
    int year;
};

int DateCompare(const struct date first, const struct date second);
void GetTodayDate(struct date* date);
void PrintDate(const struct date date);
struct event* GetEventNode(struct event* event, int index);
void ChangeEvent(struct event** event);
void SortEvent(struct event* event);
void PrintEvents(struct event** event);
void AddEvent(struct event** event);
void DeleteEvent(struct event** event);
void DisplayEventMenu(struct event** event);
struct contact* GetContactNode(struct contact* user, int index);
void ChangeUser(struct contact** user);
void PrintUsers(struct contact** user);
void AddUser(struct contact** user);
void DeleteUser(struct contact** contact);
void DisplayUsersMenu(struct contact** contact);
void FreeMemoryEvents(struct event* event);
void FreeMemoryUsers(struct contact* user);
void DisplayNotifications(struct contact* user);
void WriteToFile(struct contact** user, FILE* fptr);
unsigned long long InputCheck(const unsigned long long min, const unsigned long long max);

int main(void)
{
    struct contact* cont = NULL;
    FILE* file;
    while (1)
    {
        struct date dt;
        system("cls");
        GetTodayDate(&dt);
        PrintDate(dt);
        printf("1.Users\n");
        printf("2.Notifications\n");
        printf("3.Exit\n");

        char c;
        c = _getch();
        switch (c)
        {
        case '1':
            DisplayUsersMenu(&cont);
            break;
        case '2':
            DisplayNotifications(cont);
            break;
        case '3':
            file = fopen("D:\\Users.txt", "w");
            while (cont)
            {
                WriteToFile(&cont, file);
                cont = (cont)->next;
            }
            fclose(file);
            FreeMemoryUsers(cont);
            return 0;
        default:
            continue;
        }
    }
}

int DateCompare(const struct date first, const struct date second)
{
    if (first.year == second.year)
    {
        if (first.mon == second.mon)
        {
            return first.day - second.day;
        }
        else
        {
            return first.mon - second.mon;
        }
    }
    else
    {
        return first.year - second.year;
    }
}

void GetTodayDate(struct date* date)
{
    time_t timer = time(NULL);
    struct tm* current_date = localtime(&timer);
    date->year = current_date->tm_year + 1900;
    date->mon = current_date->tm_mon + 1;
    date->day = current_date->tm_mday;
}

unsigned long long InputCheck(const unsigned long long min, const unsigned long long max)
{
    int temp = 0;
    unsigned long long res;
    do
    {
        temp = scanf_s("%llu", &res);

        if (temp != 1)
        {
            temp = 0;
            printf("Input error\n");
            while (getchar() != '\n');
        }
        else
        {
            if (res >= min && res <= max)
            {
                break;
            }
            else
            {
                printf("Input error\n");
                temp = 0;
                continue;
            }
        }
    } while (temp != 1);
    return res;
}

void PrintDate(const struct date date)
{
    printf("Date: %d.%d.%d\n", date.day, date.mon, date.year);
}

struct event* GetEventNode(struct event* event, int index)
{
    if (!event)
    {
        return NULL;
    }
    struct event* temp = event;

    int i;
    for (i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

void ChangeEvent(struct event** event)
{
    char temp[20];
    while (1)
    {
        struct date dt;
        system("cls");
        printf("Title: %s\n", (*event)->title);
        printf("What do you want to record?:\n");
        printf("1.Time\n");
        printf("2.Place\n");
        printf("3.Date\n");
        printf("4.Note\n");
        printf("5.Title\n");
        printf("6.Go back\n");

        char c;
        c = _getch();

        switch (c)
        {
        case '1':
            system("cls");
            printf("Duration(hour): ");
            scanf_s("%llu", &((*event)->duration_hour));
            printf("Duration(min): ");
            scanf_s("%llu", &((*event)->duration_min));
            break;
        case '2':
            system("cls");
            printf("Place: ");
            fgets(temp, 30, stdin);
            fgets((*event)->place, 30, stdin);
            break;
        case '3':
            system("cls");

            printf("Day: ");
            (*event)->dt.day = InputCheck(1, 31);

            printf("Month: ");
            (*event)->dt.mon = InputCheck(1, 12);

            printf("Year: ");
            (*event)->dt.year = InputCheck(2020, 3020);
            break;
        case '4':
            system("cls");
            printf("Note: ");
            fgets(temp, 30, stdin);
            fgets((*event)->note, 100, stdin);
            break;
        case '5':
            system("cls");
            printf("New title: ");
            fgets((*event)->title, 30, stdin);
            break;
        case '6':
            GetTodayDate(&dt);
            if (DateCompare(dt, (*event)->dt) > 0)
            {
                printf("Date assignment is onle possible for the future or present\n");
                printf("Press any key to continue with current time\n");
                _getch();
                GetTodayDate(&((*event))->dt);
            }
            return;
        }
    }
}

void SortEvent(struct event* event)
{
    struct event* first = event;
    struct event* second = event->next;

    while (first->next)
    {
        while (second)
        {
            if (DateCompare(first->dt, second->dt) > 0)
            {
                struct event* temp = first;
                first = second;
                second = temp;
            }
            second = second->next;
        }
        first = first->next;
        second = first->next;
    }
}

void PrintEvents(struct event** event)
{
    if (!(*event))
    {
        printf("List is empty\nPress any key to continue");
        _getch();
        return;
    }
    SortEvent(*event);

    while (1)
    {
        system("cls");
        printf("Select event:\n");
        int leng = 1;
        struct event* temp = (*event);

        while (temp)
        {
            printf("%d.%s", leng++, temp->title);
            temp = temp->next;
        }
        printf("%d.Go back\n", leng);
        int id = InputCheck(1, leng);

        if (id == leng)
        {
            return;
        }
        if (id > 0 && id < leng)
        {
            system("cls");
            id--;
            struct event* p = GetEventNode((*event), id);
            printf("Title: %s", p->title);
            if (p->duration_min != 0 && p->duration_hour != 0)
            {
                printf("Time: %llu:%llu\n", p->duration_hour, p->duration_min);
            }
            else
            {
                printf("Time: \n");
            }
            printf("Place: %s\n", p->place);
            PrintDate(p->dt);
            printf("Note: %s", p->note);
            printf("\nDo you want to change something? (y- yes, n - no)\n");

            while (1)
            {
                char c;
                c = _getch();
                switch (c)
                {
                case 'y':
                    ChangeEvent(&p);
                    break;
                case 'n':
                    break;
                default:
                    printf("Input error\n");
                    continue;
                }
                break;
            }
        }
        else
        {
            printf("Input error");
        }
    }
}

void AddEvent(struct event** event)
{
    struct event* temp = NULL;

    if (!(temp = (struct event*)malloc(sizeof(struct event))))
    {
        printf("Not enough memory");
        _getch();
        exit(1);
    }
    printf("Title: ");
    fgets(temp->title, 30, stdin);
    GetTodayDate(&temp->dt);
    temp->place[0] = '\0';
    temp->note[0] = '\0';
    temp->next = NULL;
    temp->duration_min = 0;
    ChangeEvent(&temp);

    if (!(*event))
    {
        (*event) = temp;
    }
    else
    {
        temp->next = (*event);
        (*event) = temp;
    }
}

void DeleteEvent(struct event** event)
{
    if (!(*event))
    {
        printf("Is empty\nPress any key to continue");
        _getch();
        return;
    }
    while (1)
    {
        system("cls");
        printf("Select event:\n");
        int leng = 1;
        struct event* temp = (*event);

        while (temp)
        {
            printf("%d.%s", leng++, temp->title);
            temp = temp->next;
        }
        printf("%d.Go back\n", leng);
        int id = InputCheck(1, leng);

        if (id == leng)
        {
            return;
        }
        if (id > 0 && id < leng)
        {
            printf("Are you sure?(y - yes, n - no)\n");

            while (1)
            {
                struct event* p = NULL;

                char c;
                c = _getch();
                switch (c)
                {
                case 'y':
                    if (id == 1)
                    {
                        p = *event;
                        *event = (*event)->next;
                        free(p);
                    }
                    else
                    {
                        p = GetEventNode(*event, id - 2);
                        struct event* pn = p->next;
                        p->next = p->next->next;
                        free(pn);
                    }
                    break;
                case 'n':
                    break;;
                default:
                    printf("Input error");
                    continue;
                }
                break;
            }
        }
    }
}

void DisplayEventMenu(struct event** event)
{
    while (1)
    {
        system("cls");
        printf("1.Show events\n");
        printf("2.Add event\n");
        printf("3.Delete event\n");
        printf("4.Go back\n");

        char c;
        c = _getch();
        switch (c)
        {
        case '1':
            PrintEvents(event);
            break;
        case '2':
            AddEvent(event);
            break;
        case '3':
            DeleteEvent(event);
            break;
        case '4':
            return;
        default:
            break;
        }
    }
}

struct contact* GetContactNode(struct contact* user, int index)
{
    if (!user)
    {
        return NULL;
    }
    struct contact* temp = user;

    int i;
    for (i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

void ChangeUser(struct contact** user)
{
    while (1)
    {
        system("cls");
        printf("%s%s\n", (*user)->surname, (*user)->name);
        printf("Select what to change\n");
        printf("1.Surname and first name\n");
        printf("2.Phone number\n");
        printf("3.Work place\n");
        printf("4.Birthday\n");
        printf("5.Events\n");
        printf("6.Go back\n");

        char temp[30];
        char c;
        c = _getch();
        switch (c)
        {
        case '1':
            system("cls");
            printf("Surname: ");
            fgets(temp, 30, stdin);
            fgets((*user)->surname, 20, stdin);
            printf("\nFirst name: ");
            fgets((*user)->name, 20, stdin);
            break;
        case '2':
            system("cls");
            printf("Phone number: ");
            scanf_s("%llu", &((*user)->phone_number));
            break;
        case '3':
            system("cls");
            printf("Work place: ");
            fgets(temp, 30, stdin);
            fgets((*user)->work_place, 30, stdin);
            break;
        case '4':
            system("cls");
            printf("Day: ");
            (*user)->birthday.day = InputCheck(1, 31);

            printf("Month: ");
            (*user)->birthday.mon = InputCheck(1, 12);

            printf("Year: ");
            (*user)->birthday.year = InputCheck(1, 2020);
            break;
        case '5':
            DisplayEventMenu(&(*user)->ev);
            break;
        case '6':
            return;
        default:
            break;
        }
    }
}

void PrintUsers(struct contact** user)
{
    if (!(*user))
    {
        printf("List is empty");
        Sleep(500);
        return;
    }

    while (1)
    {
        system("cls");
        printf("Select user:\n");
        int leng = 1;
        struct contact* temp = (*user);

        while (temp)
        {
            printf("%d.%s  %s", leng++, temp->surname, temp->name);
            temp = temp->next;
        }

        printf("%d.Go back\n", leng);
        int id = InputCheck(1, leng);

        if (id == leng)
        {
            return;
        }
        else if (id > 0 && id < leng)
        {
            system("cls");
            id--;
            struct contact* p = GetContactNode((*user), id);
            printf("Surname: %s", p->surname);
            printf("First name: %s", p->name);
            printf("Work place: %s\n", p->work_place);
            PrintDate(p->birthday);
            printf("Phone number: %llu\n", p->phone_number);
            printf("Events:\n");

            struct event* tempev = (*user)->ev;

            while (tempev)
            {
                printf("%s", tempev->title);
                if (tempev->next == NULL)
                {
                    break;
                }
                else tempev = tempev->next;
            }
            printf("\n\nApply changes? (y- yes, n - no)\n");

            while (1)
            {
                char c;
                c = _getch();
                switch (c)
                {
                case 'y':
                    ChangeUser(&p);
                    break;
                case 'n':
                    break;
                default:
                    printf("Input error\n");
                    continue;
                }
                break;
            }
        }
        else
        {
            printf("Input error");
        }
    }
}

void AddUser(struct contact** user)
{
    struct contact* temp = NULL;
    char tempget[20];
    if (!(temp = (struct contact*)malloc(sizeof(struct contact))))
    {
        printf("Not enough memory. Goodbye");
        _getch();
        exit(1);
    }
    printf("Surname: ");
    fgets(temp->surname, 30, stdin);
    printf("First name: ");
    fgets(temp->name, 30, stdin);
    GetTodayDate(&temp->birthday);
    temp->work_place[0] = '\0';
    temp->phone_number = 0;
    temp->ev = NULL;
    temp->next = NULL;
    ChangeUser(&temp);

    if (!(*user))
    {
        (*user) = temp;
    }
    else
    {
        temp->next = (*user);
        (*user) = temp;
    }
}

void DeleteUser(struct contact** user)
{
    if (!(*user))
    {
        printf("List is empty\nPress any key to continue");
        _getch();
        return;
    }
    while (1)
    {
        system("cls");
        printf("Select user:\n");
        int leng = 1;
        struct contact* temp = *user;

        while (temp)
        {
            printf("%d.%s  %s", leng++, temp->surname, temp->name);
            temp = temp->next;
        }
        printf("%d.Go back\n", leng);
        int id = InputCheck(1, leng);

        if (id == leng)
        {
            return;
        }
        else
        {
            printf("Are you sure?(y - yes, n - no)\n");

            while (1)
            {
                struct contact* p = NULL;

                char c;
                c = _getch();
                switch (c)
                {
                case 'y':
                    if (id == 1)
                    {
                        p = *user;
                        *user = (*user)->next;
                        free(p);
                    }
                    else
                    {
                        p = GetContactNode(*user, id - 2);
                        struct contact* pn = p->next;
                        p->next = p->next->next;
                        free(pn);
                    }
                    break;
                case 'n':
                    break;;
                default:
                    printf("Input error");
                    continue;
                }
                break;
            }
        }
    }
}

void DisplayUsersMenu(struct contact** user)
{
    while (1)
    {
        system("cls");
        printf("1.Show users\n");
        printf("2.Add user\n");
        printf("3.Delete user\n");
        printf("4.Go back\n");

        fflush(stdin);//clearing the input buffer
        char c;
        c = _getch();
        switch (c)
        {
        case '1':
            PrintUsers(user);
            break;
        case '2':
            AddUser(user);
            break;
        case '3':
            DeleteUser(user);
            break;
        case '4':
            return;
        default:
            continue;
        }
    }
}

void FreeMemoryEvents(struct event* event)
{
    while (event)
    {
        struct event* temp = event;
        event = event->next;
        free(temp);
    }
}

void FreeMemoryUsers(struct contact* user)
{
    while (user)
    {
        FreeMemoryEvents(user->ev);
        struct contact* temp = user;
        user = user->next;
        free(temp);
    }
}

void DisplayNotifications(struct contact* user)
{
    struct date dt;
    GetTodayDate(&dt);
    struct contact* temp = user;
    printf("Coming soon:\n");

    while (temp)
    {
        struct event* p = temp->ev;

        while (p)
        {
            if (p->dt.year == dt.year &&
                p->dt.mon == dt.mon &&
                p->dt.day - dt.day < 5 &&
                p->dt.day - dt.day >= 0)
            {
                printf("%s", p->title);
                PrintDate(p->dt);
            }
            p = p->next;
        }
        temp = temp->next;
    }
    printf("Birthday:\n");
    temp = user;

    while (temp)
    {
        if (temp->birthday.mon == dt.mon &&
            temp->birthday.day - dt.day < 5 &&
            temp->birthday.day - dt.day >= 0)
        {
            printf("%s%s", temp->surname, temp->name);
            PrintDate(temp->birthday);
        }
        temp = temp->next;
    }
    printf("\nPress any key to continue\n");
    _getch();
    return;
}

void WriteToFile(struct contact** user, FILE* fptr)
{
    struct contact* temp = (*user);

    while (temp != NULL)
    {
        fprintf(fptr, "%s\n", temp->name);
        fprintf(fptr, "%s\n", temp->surname);
        if (temp->work_place)
        {
            fprintf(fptr, "%s\n", temp->work_place);
        }
        if (temp->phone_number)
        {
            fprintf(fptr, "%llu\n", temp->phone_number);
        }
        if (temp->birthday.day && temp->birthday.mon && temp->birthday.year)
        {
            fprintf(fptr, "%d.%d.%d\n", temp->birthday.day, temp->birthday.mon, temp->birthday.year);
        }
        if (temp->ev)
        {
            if (temp->ev->title)
            {
                fprintf(fptr, "%s\n", temp->ev->title);
            }
            if (temp->ev->duration_min)
            {
                fprintf(fptr, "%llu\n", temp->ev->duration_min);
            }
            if (temp->ev->place)
            {
                fprintf(fptr, "%s\n", temp->ev->place);
            }
            if (temp->ev->dt.day && temp->ev->dt.mon && temp->ev->dt.year)
            {
                fprintf(fptr, "%d.%d.%d\n", temp->ev->dt.day, temp->ev->dt.mon, temp->ev->dt.year);
            }
            if (temp->ev->note)
            {
                fprintf(fptr, "%s", temp->ev->note);
            }
        }
        if (temp == NULL)
            fprintf(fptr, "\n");
        fputs("==================\n", fptr);

        temp = temp->next;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
