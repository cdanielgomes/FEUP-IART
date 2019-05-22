import java.util.ArrayList;

public class State implements Cloneable {

    private Board board;
    private Integer playerHasMove;
    double value = 0;


    State(Board board, int playerHasMove) {


        this.board = board;

        this.playerHasMove = playerHasMove;
    }

    public void changePlayer() {
        this.playerHasMove = this.playerHasMove == 1 ? 2 : 1;
    }

    public void setX(int x) {
        this.value = x;
    }

    public void makePlayerMove(int move) {
        this.board.emptyHole(playerHasMove, move);
        changePlayer();
    }

    public Integer getPlayer() {
        return this.playerHasMove;
    }

    public Board getBoard() {
        return board;
    }

    public ArrayList<Board> getActions() {
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


    public boolean end() {
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


    public void setBoard(Board board) {
        this.board = board;
    }

    public boolean extraTurn(Integer player) {
        return playerHasMove == player && this.board.isTurn();
    }

    public boolean eatOpponent(Integer player) {
        return this.board.isEat() && playerHasMove != player;
    }

    public int diffPieces(int p1, int p2) {

        return this.board.playedPieces(p1) - this.board.playedPieces(p2);
    }

    public boolean plus(Integer player) {
        return this.board.isPoint();
    }


    public boolean won(Integer player) {
        return this.board.whoWon() + 1 == player;
    }


}
