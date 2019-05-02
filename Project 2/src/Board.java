import java.util.ArrayList;

class Board {
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

    // player = 1 OR player = 2
    void emptyHole(int player, int holeNumber) {

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
    }

}
