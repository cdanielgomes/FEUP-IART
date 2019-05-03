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
                    j=((i==0) ? j - 1 : j + 1);
                    finishedRow=i; finishedColumn=j;
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

        return true;
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

}
