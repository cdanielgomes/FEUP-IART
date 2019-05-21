import java.util.ArrayList;
import java.util.Collections;

class Board implements Cloneable {
    private static final int ROWS = 2;
    private static final int COLUMNS = 7;
    private static final int INITIAL_BEANS = 4;
    private static final int[][] initialBoard = {{0, 4, 4, 4, 4, 4, 4},
            {4, 4, 4, 4, 4, 4, 4}};
    boolean turn = false, eat = false, point = false;
    private int[][] board;

    Board() {
        board = new int[ROWS][COLUMNS];

        initBoard();
    }

    Board(int[][] board) {
        this.board = board;
    }

    private void initBoard() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if ((i == 0 && j == 0) || (i == ROWS - 1 && j == COLUMNS - 1)) {
                    continue;
                }
                board[i][j] = INITIAL_BEANS;
            }
        }
    }

    static int[][] getInitialBoard() {
        return initialBoard;
    }

    @Override
    public Object clone() throws
            CloneNotSupportedException {
        Board a = (Board) super.clone();

        a.board = new int[ROWS][COLUMNS];

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                a.board[i][j] = this.board[i][j];
            }
        }

        a.point = false;
        a.eat = false;
        a.turn = false;

        return a;
    }


    private boolean removeBean(int row, int column) {
        // if there are beans in the hole
        if (board[row][column] > 0) {
            board[row][column]--;
            return true;
        }

        return false;
    }

    private void addBean(int row, int column) {
        board[row][column]++;
    }


    /**
     * @param player
     * @param finishedRow
     * @param finishedColumn
     * @return
     */

    private int verifyLanding(int player, int finishedRow, int finishedColumn) {
        switch (player) {
            case 1:
                if (finishedRow == 0) {
                    if (finishedColumn == 0) {
                        turn = true;
                        //    System.out.println("Free turn!");
                        return 1;
                    } else if (board[finishedRow][finishedColumn] == 1) {
                        eat = true;
                        //  System.out.println("Capture!");
                        return 2;
                    }
                }
                break;
            case 2:
                if (finishedRow == 1) {
                    if (finishedColumn == COLUMNS - 1) {
                        turn = true;
                        //System.out.println("Free turn!");
                        return 3;
                    } else if (board[finishedRow][finishedColumn] == 1) {
                        eat = true;
                        //System.out.println("Capture!");
                        // TODO capture function
                        return 4;
                    }
                }
        }

        return -1;
    }

    // player = 1 OR player = 2

    /***
     *  Make the move and return special code if
     *  the move capture pieces or extra turns
     *
     * @param player
     * @param holeNumber
     * @return
     */
    int emptyHole(int player, int holeNumber) {
        int row = player - 1, column = ((player == 1) ? holeNumber : holeNumber - 1);
        int numberOfBeans = board[row][column];
        int points = 0;

        if (player == 1)
            points = board[player - 1][0];
        else
            points = board[player - 1][COLUMNS - 1];

        if (numberOfBeans == 0) {
            System.out.println("You have to choose a non-empty hole!");
            return -1;
        }

        Integer finishedRow = null, finishedColumn = null;
        int i = row, j = ((row == 0) ? column - 1 : column + 1);
        while (numberOfBeans > 0) {
            if (j < COLUMNS && j >= 0) {
                if (removeBean(row, column)) {
                    numberOfBeans--;
                    addBean(i, j);
                    finishedRow = i;
                    finishedColumn = j;
                    j = ((i == 0) ? j - 1 : j + 1);
                }
            } else {
                if (i == 0) {
                    i = 1;
                    j = 0;
                } else {
                    i = 0;
                    j = COLUMNS - 1;
                }
            }
        }

        if (player == 1)
            point = points < board[player - 1][0];
        else
            point = points < board[player - 1][COLUMNS - 1];


        return verifyLanding(player, finishedRow, finishedColumn);

    }

    public boolean isEat() {
        return eat;
    }

    public boolean isTurn() {
        return turn;
    }

    public boolean isPoint() {
        return point;
    }

    public ArrayList<Integer> plays(int player) {

        ArrayList<Integer> boards = new ArrayList<>();
        int def = (player == 1) ? 0 : 1;
        int row = (player == 1) ? 1 : 0;
        int maxCol = (player == 1) ? COLUMNS : COLUMNS - 1;
        for (int i = row; i < maxCol; i++) {
            if (board[player - 1][i] != 0) boards.add(i + def);
        }

        return boards;
    }


    public int gameOver() {

        for (int i = 0; i < ROWS; i++) {
            int j = (i == 0) ? 1 : 0;
            int col = (i == 0) ? COLUMNS : COLUMNS - 1;
            for (; j < col; j++) {
                if (board[i][j] != 0) break;
            }

            if (j == col) return i + 1;

        }

        return -1;
    }


    public int whoWon() {
        int plays = gameOver(), p1Pieces, p2Pieces;

        if (plays == -1) {
            return -1;
        } else if (plays == 2) {
            p1Pieces = countPieces(1);
            p2Pieces = board[1][COLUMNS - 1];
        } else {
            p1Pieces = board[0][0];
            p2Pieces = countPieces(2);
        }

        return p1Pieces < p2Pieces ? 2 : 1;
    }


    public int countPieces(int player) {
        int sum = 0;

        for (int a = 0; a < COLUMNS; a++) {
            sum += board[player - 1][a];
        }
        return sum;
    }

    public int playedPieces(int player) {

        int sum = 0;
        int col = player == 1 ? COLUMNS : COLUMNS - 1;
        int a = player == 1 ? 1 : 0;

        for (; a < col; a++) {
            sum += board[player - 1][a];
        }

        return sum;
    }

    int getPot1() {
        return board[0][0];
    }

    int getPot2() {
        return board[ROWS - 1][COLUMNS - 1];
    }


    void draw() {
        System.out.println(" Pot 1                       Pot 2\n");
        System.out.print(" | " + getPot1() + " | ");

        for (int i = 0; i < ROWS; i++) {
            if (i == ROWS - 1) {
                System.out.print(" |   | ");
            }
            for (int j = 0; j < COLUMNS; j++) {
                if ((i == 0 && j == 0) || (i == ROWS - 1 && j == COLUMNS - 1)) {
                    continue;
                }
                System.out.print(board[i][j] + " | ");
            }

            if (i == 0) {
                System.out.print("  |\n");
            }
            if (i == ROWS - 1) {
                System.out.print(getPot2() + " |\n");
            }

        }

        System.out.println();
    }

    public void setPiece(int row, int col, int nPieces) {

        board[row][col] = nPieces;
    }

    public int[][] getBoard() {
        return board;
    }
}


