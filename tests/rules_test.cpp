#define main original_game_main
#include "../Sequence.cpp"
#undef main
#include <cassert>
int main() {
    int board[10][10]={};
    assert(!check_Win(board,1));
    for(int i=0;i<5;++i) board[0][i]=1000;
    assert(check_Win(board,1));
    assert(!check_Win(board,2));
    int vertical[10][10]={};
    for(int i=5;i<10;++i) vertical[i][9]=2000;
    assert(check_Win(vertical,2));
    int diagonal[10][10]={};
    for(int i=0;i<5;++i) diagonal[i+5][9-i]=1000;
    assert(check_Win(diagonal,1));
    int deck[104]={}, first[7]={}, second[7]={};
    playturn(board,deck,first,second,104); // Exhaustion exits before reading another card.
}
