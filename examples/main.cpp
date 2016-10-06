#include <iostream>
#include <cstring>
using namespace std;
 
void show_cells();
void make_move(int num);
void result();
char check();
 
char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
char PlayerName1[80],
    PlayerName2[80];
char win='-';
int main () {
    cout << "Enter the name of the 1st player: ";
    gets(PlayerName1);
    cout << "Enter the name of the 2st player: ";
    gets(PlayerName2);
    cout << "\n";
 
    show_cells();
 
    for (int move = 1; move <= 9; move++) {
        if (move % 2) make_move(1);
        else make_move(2);
        show_cells();
        if (move >= 5) 
        {
            win=check();
            if(win!='-')
                break;
        }
    }
    result();
    system ("pause");
    return 0;
}
 
void show_cells() {
    cout << "------------" << "\n" << endl;
    cout << "Numbers of cells:" << endl;
    cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << " |" << endl;
    cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << " |" <<  endl;
    cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << " |" << "\n" << endl;
 
    cout << "Current situation (--- is empty):" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |" <<  endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |" <<  endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" <<  "\n" << endl;
    cout << "------------\n" << endl;
}
 
void make_move(int num) {
    if (num == 1) cout << PlayerName1;
    else cout << PlayerName2;
    cout << ", enter a cell's number to make move: ";
    int cell;
    cin >> cell;
    cout << "\n";
    while (cell > 9 || cell < 1 || cells[cell-1] == 'O' || cells[cell-1] == 'X') {
        cout << "Enter a CORRECT (1-9) or EMPTY (---) cell's number to make move: ";
        cin >> cell;
        cout << "\n";
    }
 
    if (num == 1)
        cells[cell-1] = 'X';
    else cells[cell-1] = 'O';
}
 
void result() {
    if (win=='X') cout << PlayerName1 << " win! Congratulations! " << PlayerName2 << " is looser! Bugoga..." << endl;
    else if (win=='O') cout << PlayerName2 << " win! Congratulations! " << PlayerName1 << " is looser! Bugoga..." << endl;
    else cout << "Draw!!!" << endl;
}
 
char check()
{
    int i;
    for(i = 0; i < 3; i++)
        if(cells[i*3+0] == cells[i*3+1] && cells[i*3+1] == cells[i*3+2] && cells[i*3+2] != '-')
            return cells[i*3+1];
        else if(cells[i] == cells[3+i] && cells[3+i] == cells[6+i] && cells[6+i] != '-')
            return cells[3+i];
    if((cells[0] == cells[4] && cells[4] == cells[8] ||
        cells[2] == cells[4] && cells[4] == cells[6]) &&
        cells[4] != '-')
        return cells[4];
    return '-';
}
