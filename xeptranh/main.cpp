#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;
int  N;
int **A, x, y, countt=0;
char ct;
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void oouutt()
{
    cout << "\n    GAME FOR TRI   \n";
    cout <<endl<<endl<< "                        "<< countt << endl<< endl;
    for (int i=0; i<N; i++)
    {
        cout << "               ";
        SetColor(4);
        cout << '.'; for (int z=1; z<=N; z++) cout << " __  ."; cout << endl;
        cout << ' '; for (int z=1; z<=N; z++)     cout << "    "; cout << endl;
        cout << "               ";cout << "|";

        for (int j=0; j<N; j++)
        {
            cout << ' ';
            SetColor(2);
            if (!A[i][j])
            {
                SetBGColor(4);
                cout << "  ";
                SetBGColor(0);
            }
            else
                cout << setw(2) << A[i][j];
            SetColor(4);
            cout << "  |";
        }
        cout << endl;
    }
    cout << "               ";
    cout << '.'; for (int z=1; z<=N; z++) cout << " __  ."; cout << endl;
    SetColor(6);
}

void khoi_tao()
{
    int r=0;
    A=new int*[N];
    for (int i=0; i<N; i++)
    {
        A[i]=new int[N];
        for (int j=0; j<N; j++)
            A[i][j]=r++;
    }
    x=0; y=0;
}

void dichuyen(int &x, int &y, int h)
{
    countt++;
    if (h==1)
    {
        if (x>0)
        {
            swap(A[x-1][y],A[x][y]);
            x--;
        }
    }
    else if (h==2)
    {
        if (y<N-1)
        {
            swap(A[x][y+1],A[x][y]);
            y++;
        }
    }
    else if (h==3)
    {
        if (x<N-1)
        {
            swap(A[x+1][y],A[x][y]);
            x++;
        }
    }
    else if (h==4)
    {
        if (y>0)
        {
            swap(A[x][y-1],A[x][y]);
            y--;
        }
    }
}

void makerand(int n)
{
    for (int i=0; i<n; i++)
    {
        int e=rand()%4+1;
        dichuyen(x,y,e);
        oouutt();
        Sleep(3);
        system("cls");
    }
    countt=0;
}

bool check_end()
{
    int t=0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (A[i][j]!=t) return false;
            t++;
        }
    }
    return true;
}
void control()
{
    while (1)
    {
        ct=getch();
        if (ct==-32)
            ct=getch();
        if (ct==72)
            dichuyen(x,y,1);
        else if (ct==77)
            dichuyen(x,y,2);
        else if (ct==80)
            dichuyen(x,y,3);
        else if (ct==75)
            dichuyen(x,y,4);
        else continue;
        if (check_end())
        {
            cout << "\a\a";
            return;
        }
        system("cls");
        oouutt();
    }
}
void menu()
{
    oouutt();
    cout << "\n\n\n          nhan phim bat ki de bat dau choi....";
    char a;
    a=getch();
    makerand(abs((int)a));
}
int main()
{
    system("color 6");
    cout << "ENTER LEVEL: ";
    cin >> N;
    khoi_tao();
    menu();
    oouutt();
    control();
    system("cls");
    oouutt();
    cout << "\n\nBan da chien thang, chuc mung\n";
    getch();
    return 0;
}
