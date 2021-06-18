#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

const int ROW = 3;
const int COL = 3;

void initBrd (char box[][COL], int board[][COL]);
void game(char, char, char [][COL], int [][COL]);
char menu();
void printBoard(char[][COL]);
void printBoard(int[][COL]);
bool spotTaken (char [][COL], int);
void turnPlayer (char [][COL], char);
void turnCPU (char [][COL], char);
bool checkTie(char [][COL]);
bool checkWin(char [][COL], char);



int main () {
    srand(static_cast<unsigned int>(time(NULL)));
    //board is for the 1 2 3
    //                 4 5 6
    //                 7 8 9
    int board[ROW][COL];
    char box[ROW][COL];
    //box is a parallel array
    //of the board but will 
    //contain the characters 'O' & 'X'
    int player;
    char CPUShape, 
         playerShape;

    playerShape = menu();

    if (playerShape == 'X') { 
        CPUShape = 'O';
    }
    else if (playerShape == 'O') {
        CPUShape = 'X';
    }
    else {
        std::cout << "Error";
    }
    
    initBrd(box,board);
    game(playerShape, CPUShape, box, board);





    return 0;
}



void initBrd(char box[][COL], int board[][COL]) {
    //initializing box
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            box[i][j] = ' ';   
        }
    }

    //box is being used here to print the visual board
    for (int i = 0; i < ROW; i++) {
        std::cout<<std::setw(6) << "|" << std::setw(6) <<  "|" << std::setw(6) << "|" << '\n'; 
        
        for (int j = 0; j < COL; j++) {
             std::cout << std::setw(3) << box[i][j] << std::setw(3) << "|";
            
        }
        //std::cout << '\n' << "______________" << '\n';
        std::cout << '\n';
        std::cout << "_____|_____|_____|";
        std::cout << '\n';
    }

    int count = 1;
    //parallel array to box but is to actually be 
    //used in the code as the game 
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = count;
            count++; 
        }
    }
    for (int i = 0; i < ROW; i++) {
        std::cout<<std::setw(6) << "|" << std::setw(6) <<  "|" << std::setw(6) << "|" << '\n'; 
        
        for (int j = 0; j < COL; j++) {
             std::cout << std::setw(3) << board[i][j] << std::setw(3) << "|";
            
        }
        //std::cout << '\n' << "______________" << '\n';
        std::cout << '\n';
        std::cout << "_____|_____|_____|";
        std::cout << '\n';
    }
 
}
void game (char playerShape, char CPUShape, char box[][COL], int board[][COL]) {
    bool playWin, cpuWin, tie;
    do {
        turnPlayer(box, playerShape);
        printBoard(board);
        std::cout << "\n\n\n";
        printBoard(box);
        if (checkWin(box,playerShape) == true) {
            std::cout << "Player wins" << '\n';
            return;
        }
        if (checkTie(box) == true) {
            std::cout << "Tie" << '\n';
            return;
        }
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
        turnCPU(box,CPUShape);
        printBoard(board);
        std::cout << "\n\n\n";
        printBoard(box);
        if (checkWin(box,CPUShape) == true) {
            std::cout << "CPU wins" << '\n';
            return;
        }
        if (checkTie(box) == true) {
            std::cout << "Tie" << '\n';
            return;
        }
        playWin = checkWin(box,playerShape);
        cpuWin = checkWin(box,CPUShape);
        tie = checkTie(box);
    }while (tie == false && cpuWin == false && playWin == false);

    if (playWin) std::cout  << "Player wins" << '\n';
    if (cpuWin) std::cout << "CPU wins" << '\n';
    if (tie) std::cout << "Tie"  << '\n';
}

char menu () {
    unsigned short shapeChoice;
    std::cout << "The shape 'X' will go first. The shape 'O' will go second. << '\n'";
        
    std::cout << "Press 1 to be 'X'\nPress 2 to be 'O'\n";
    
    std::cin >> shapeChoice;

    if (shapeChoice == 1) {
        return 'X';
    }
    else if (shapeChoice == 2) {
        return 'O';   
    }
    else {
        std::cout << "Pick an actual fucking choice please :)\n";
        menu();
    }
}

void printBoard (char box [][COL]) {
     for (int i = 0; i < ROW; i++) {
        std::cout<<std::setw(6) << "|" << std::setw(6) <<  "|" << std::setw(6) << "|" << '\n'; 
        
        for (int j = 0; j < COL; j++) {
             std::cout << std::setw(3) << box[i][j] << std::setw(3) << "|";
            
        }
        //std::cout << '\n' << "______________" << '\n';
        std::cout << '\n';
        std::cout << "_____|_____|_____|";
        std::cout << '\n';
    }
   
}

void printBoard (int board[][COL]) {
     for (int i = 0; i < ROW; i++) {
        std::cout<<std::setw(6) << "|" << std::setw(6) <<  "|" << std::setw(6) << "|" << '\n'; 
        
        for (int j = 0; j < COL; j++) {
             std::cout << std::setw(3) << board[i][j] << std::setw(3) << "|";
            
        }
        //std::cout << '\n' << "______________" << '\n';
        std::cout << '\n';
        std::cout << "_____|_____|_____|";
        std::cout << '\n';
    }
   

}

bool spotTaken (char box[][COL], int spot) {
    if (spot <= 3) {
        if (box[0][spot - 1] ==' ') {
            return false;
        }
        else return true;
    }
    else if (spot <= 6 && spot > 3) {
        if (box[1][spot - 4 ] == ' ') {
            return false;
        } 
        else return true;
    }
    else {
        if (box[2][spot - 7] == ' ') {
            return false;
        }
        else return true;
    }
}

void turnPlayer (char box[][COL], char playerShape) {
    int player;
    std::cout << "Your Turn" << '\n';
    std::cin >> player;
    if (player > 9) std::cout<< "WRONG INPUT"; exit(EXIT_FAILURE);
    if (player <= 3) {
        if (spotTaken(box,player) == true) {
            std::cout << "Spot taken" << '\n';
            turnPlayer(box,playerShape);
        }
        else {
            box[0][player - 1] = playerShape;
        }
    }
    else if (player <= 6 && player > 3) {
        if (spotTaken(box,player)== true) {
            std::cout << "Spot taken" << '\n';
            turnPlayer(box,playerShape);
        }
        else {
            box[1][player - 4 ] = playerShape;
        }
    }
    else {
        if (spotTaken(box,player)== true) {
            std::cout << "Spot taken" << '\n';
            turnPlayer(box,playerShape);
        }
        else {
            box[2][player - 7] = playerShape;
        }
    }
}

void turnCPU (char box[][COL], char CPUShape) {
    int randomSpot = rand()% 8 + 1;
    int CPU = randomSpot;
    if (CPU <= 3) {
        if (spotTaken(box,CPU)== true) {
            std::cout << "Spot taken" << '\n';
            turnCPU(box,CPUShape);
        }
        else {
            box[0][CPU - 1] = CPUShape;
        }
    }
    else if (CPU <= 6 && CPU > 3) {
        if (spotTaken(box,CPU)== true) {
            std::cout << "Spot taken" << '\n';
            turnCPU(box,CPUShape);
        }
        else {
            box[1][CPU - 4 ] = CPUShape;
        }
    }
    else {
        if (spotTaken(box,CPU)== true) {
            std::cout << "Spot taken" << '\n';
            turnCPU(box,CPUShape);
        }
        else {
            box[2][CPU - 7] = CPUShape;
        }
    }
}

bool checkTie (char box[][COL]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (box[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) return true;
    return false;
}

bool checkWin (char box[][COL], char shape) {
    for (int i = 0; i < 3; i++) {
        int countRow = 0;
        int countCol = 0;
        for (int j = 0; j < 3; j++) {
            if (box[i][j] == shape) countRow++;
            if (box[j][i] == shape) countCol++;
        }
        if (countRow == 3) return true;
        if (countCol == 3) return true;
    }
    
    if (box[0][0] == shape && box[1][1] == shape && box[2][2] == shape) {
        return true;
    }
    else if (box[0][2] == shape && box[1][1] == shape && box[2][0] == shape) {
        return true;
    }
    
    return false;

}
