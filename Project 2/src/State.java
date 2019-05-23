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

    public boolean makePlayerMove(int move) {
        if(!this.board.emptyHole(playerHasMove, move)) return false;
        if(!this.board.isTurn()) changePlayer();
        try{
            this.board = (Board) this.board.clone();
        } catch(Exception e){
            e.printStackTrace();
        }

        return true;
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
                newB.emptyHole(playerHasMove, play);
             //   newB.draw();
                boardsPlayed.add(newB);
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

    public int diffPieces(int p1) {

        int adv = p1 == 1 ? 2 : 1;

        return this.board.playedPieces(p1) - this.board.playedPieces(adv);
    }

    boolean plus(Integer player) {
        return this.board.isPoint();
    }


    public boolean won(Integer player) {
        return this.board.whoWon() == player;
    }


}
