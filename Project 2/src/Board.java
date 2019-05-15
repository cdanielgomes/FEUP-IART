import java.util.ArrayList;
import java.util.Collections;

class Board implements Cloneable {
    private static final int ROWS = 2;
    private static final int COLUMNS = 7;
    private static final int INITIAL_BEANS = 4;

    private int[][] board;

    Board() {
        board = new int[ROWS][COLUMNS];

        initBoard();
    }

    private void initBoard() {
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLUMNS; j++) {
                if((i==0 && j==0) || (i==ROWS-1 && j==COLUMNS-1)) {
                    continue;
                }
                board[i][j] = INITIAL_BEANS;
            }
        }
    }


    @Override

    public Object clone() throws
            CloneNotSupportedException
    {
        Board a = (Board) super.clone();

        a.board = new int[ROWS][COLUMNS];

        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLUMNS; j++){
                a.board[i][j] = this.board[i][j];
            }
        }

        return a;
    }


    private boolean removeBean(int row, int column) {
        // if there are beans in the hole
        if(board[row][column] > 0) {
            board[row][column]--;
            return true;
        }

        return false;
    }

    private void addBean(int row, int column) {
        board[row][column]++;
    }

    private void verifyLanding(int player, int finishedRow, int finishedColumn) {
        switch(player) {
            case 1:
                if(finishedRow == 0) {
                    if(finishedColumn == 0) {
                        System.out.println("Free turn!");
                    }
                    else if(board[finishedRow][finishedColumn] == 1) {
                        System.out.println("Capture!");
                    }
                }
                break;
            case 2:
                if(finishedRow == 1) {
                    if(finishedColumn == COLUMNS - 1) {
                        System.out.println("Free turn!");
                    }
                    else if(board[finishedRow][finishedColumn] == 1) {
                        System.out.println("Capture!");
                    }
                }
        }
    }

    // player = 1 OR player = 2
    boolean emptyHole(int player, int holeNumber) {
        int row = player-1, column = ((player == 1) ? holeNumber : holeNumber - 1);
        int numberOfBeans = board[row][column];

        if(numberOfBeans == 0) {
            System.out.println("You have to choose a non-empty hole!");
            return false;
        }

        Integer finishedRow = null, finishedColumn = null;
        int i=row, j=((row==0) ? column-1 : column+1);
        while(numberOfBeans > 0) {
            if(j<COLUMNS && j >= 0) {
                if(removeBean(row, column)) {
                    numberOfBeans--;
                    addBean(i,j);
                    finishedRow=i; finishedColumn=j;
                    j=((i==0) ? j - 1 : j + 1);
                }
            }
            else {
                if(i==0) {
                    i=1; j=0;
                }
                else {
                    i=0; j=COLUMNS-1;
                }
            }
        }

        verifyLanding(player, finishedRow, finishedColumn);

        return true;
    }

    public ArrayList<Integer> plays(int player){

        ArrayList<Integer> boards = new ArrayList<>();
        int row = (player == 1) ? 0 : 1;

        for(int i = row; i < COLUMNS; i++){
            if(board[row][i] != 0) boards.add(i);
        }

        return boards;
    }


    public int gameOver(){

        for (int i = 0; i < ROWS; i++){
            int j = (i == 0) ? 1 : 0 ;
            for(; j < COLUMNS; j++){
                if(board[i][j] != 0) break;
            }

            if(j == 6) return i;
        }

        return -1;
    }


    public int whoWon(){
        int plays = gameOver(), p1Pieces, p2Pieces;

        if (plays == -1){
            return -1;
        } else if (plays == 1){
           p1Pieces = countPieces(0) + board[0][0];
           p2Pieces = board[1][COLUMNS - 1];
        } else {
            p1Pieces = board[0][0];
            p2Pieces = countPieces(1) + board[1][COLUMNS - 1];
        }

        return p1Pieces < p2Pieces ? 1 : 0;
    }


    public int countPieces(int player){
        int sum = 0;
        int a = player == 0 ? 1 : 0;

        for(; a < COLUMNS; a++){
            sum += board[player][player];
        }
        return sum;
    }

    int getPot1() {
        return board[0][0];
    }

    int getPot2() {
        return board[ROWS-1][COLUMNS-1];
    }


    void draw() {
        System.out.print(" | " + getPot1() + " | ");

        for(int i=0; i<ROWS; i++) {
            if(i==ROWS-1) {
                System.out.print(" |   | ");
            }
            for(int j=0; j<COLUMNS; j++) {
                if((i==0 && j==0) || (i==ROWS-1 && j==COLUMNS-1)) {
                    continue;
                }
                System.out.print(board[i][j] + " | ");
            }

            if(i==0) {
                System.out.print(getPot2() + " |\n");
            }
            if(i==ROWS-1) {
                System.out.print("  |\n");
            }

        }

        System.out.println();
    }

    public void setPiece(int row, int col, int nPieces){

        board[row][col] = nPieces;
    }

    public int[][] getBoard() {
        return board;
    }
}


