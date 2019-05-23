import java.util.ArrayList;

public class State implements Cloneable {

    private Board board;
    private Integer playerHasMove;
    private double value = 0;

    State(int playerHasMove) {
        this.playerHasMove = playerHasMove;
        board = new Board();
    }

    State(Board board, int playerHasMove) {
        this.board = board;
        this.playerHasMove = playerHasMove;
    }

    void changePlayer() {
        this.playerHasMove = this.playerHasMove == 1 ? 2 : 1;
    }

    void setX(int x) {
        this.value = x;
    }

    void makePlayerMove(int move) {
        this.board.emptyHole(playerHasMove, move);
        changePlayer();
    }

    Integer getPlayer() {
        return this.playerHasMove;
    }

    Board getBoard() {
        return board;
    }

    ArrayList<Board> getActions() {
        ArrayList<Board> boardsPlayed = new ArrayList<>();
        ArrayList<Integer> plays = board.plays(playerHasMove);


        try {

            for (Integer play : plays) {

                Board newB = (Board) this.board.clone();
                int special = newB.emptyHole(playerHasMove, play);
                newB.draw();
                boardsPlayed.add(newB);
/*
                try {
                    Thread.sleep(3000);
                } catch (Exception e) {
                    e.printStackTrace();
                }*/
            }

        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return boardsPlayed;
    }


    boolean end() {
        return this.board.gameOver() != -1;
    }

    @Override
    public Object clone() throws
            CloneNotSupportedException {
        State a = (State) super.clone();

        a.board = (Board) this.board.clone();

        a.value = this.value;
        a.playerHasMove = this.playerHasMove;
        return a;
    }


    void setBoard(Board board) {
        this.board = board;
    }

    boolean extraTurn(Integer player) {
        return playerHasMove.equals(player) && this.board.isTurn();
    }

    boolean eatOpponent(Integer player) {
        return this.board.isEat() && playerHasMove.equals(player);
    }

    int diffPieces(int p1, int p2) {

        return this.board.playedPieces(p1) - this.board.playedPieces(p2);
    }

    boolean plus(Integer player) {
        return this.board.isPoint();
    }


    boolean won(Integer player) {
        return this.board.whoWon() + 1 == player;
    }


}
