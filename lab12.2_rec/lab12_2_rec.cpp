#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct L
{
    L* link;
    int info;
};

void CreateList(L*& first, L*& last, int N, int Low, int High, int k);
void Print(L* first);
void AddList(L*& first, L*& last, int value);
int DeleteList(L*& first, L*& last);
void DivideList(L*& first, L*& last, L*& first1, L*& last1, L*& first2, L*& last2, int value);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));
    L* first = NULL,
        * last = NULL;
    L* first1 = NULL,
        * last1 = NULL;
    L* first2 = NULL,
        * last2 = NULL;

    int N, Low, High;
    cout << "Введіть к-сть елементів списку: "; cin >> N;
    cout << "Введіть мінімальне значення: "; cin >> Low;
    cout << "Введіть максимальне значення: "; cin >> High;
    cout << endl;
    CreateList(first, last, N, Low, High, 0);
    cout << "Друкую список..." << endl << endl;
    Print(first);
    cout << endl;
    cout << "Створюю два окремих списки та виводжу їх на екран... " << endl;
    DivideList(first, last, first1, last1, first2, last2, 0);
    cout << endl;
    cout << "Список L1:" << endl;
    Print(first1);
    cout << endl;
    cout << "Список L2:" << endl;
    Print(first2);
    cout << endl;

    return 0;
}

void CreateList(L*& first, L*& last, int N, int Low, int High, int k)
{
    if (k < N)
    {
        int v = Low + rand() % (High - Low + 1);
        AddList(first, last, v);
        CreateList(first, last, N, Low, High, k + 1);
    }
}

void Print(L* first)
{
    if (first != NULL)
    {
        cout << first->info << "  ";
        Print(first->link);
    }
}

void AddList(L*& first, L*& last, int value)
{
    L* tmp = new L;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

int DeleteList(L*& first, L*& last)
{
    L* tmp = first->link;
    int value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

void DivideList(L*& first, L*& last, L*& first1, L*& last1, L*& first2, L*& last2, int value)
{
    if (first != NULL)
    {
        if (first->info > 0)
        {
            value = DeleteList(first, last);
            AddList(first1, last1, value);
            DivideList(first, last, first1, last1, first2, last2, value);
        }
        else if (first->info < 0)
        {
            value = DeleteList(first, last);
            AddList(first2, last2, value);
            DivideList(first, last, first1, last1, first2, last2, value);
        }
        else
            DivideList(first->link, last, first1, last1, first2, last2, value);
    }
}