import java.util.ArrayList;

public class State implements Cloneable {


    private Board board;
    Integer playerHasMove;
    double value = 0;

    State(Board board, int playerHasMove){

        this.board = board;
        this.playerHasMove = playerHasMove;
    }

    public void changePlayer(){
        this.playerHasMove = this.playerHasMove == 1 ? 2 : 1;
    }

    public void setX(int x) {
        this.value = x;
    }


    public Integer getPlayer() {
        return this.playerHasMove;
    }

    public Board getBoard() {
        return board;
    }

    public ArrayList<Board> getActions() {
        ArrayList<Board> boardsPlayed = new ArrayList<>();
        ArrayList<Integer> plays =  board.plays(playerHasMove);


        for(Integer play : plays){

            this.board.emptyHole(playerHasMove, play);

        }

        return boardsPlayed;
    }


    public boolean end(){
        return board.gameOver() != -1;
    }

    @Override

    public Object clone() throws
            CloneNotSupportedException
    {
        State a = (State) super.clone();

        a.board = (Board) this.board.clone();

        a.value = this.value;
        a.playerHasMove = this.playerHasMove;
        return a;
    }


    public void setBoard(Board board) {
        this.board = board;
    }

    public boolean extraTurn(Integer player){



    }

    public boolean won(Integer player){
        return this.board.whoWon() + 1 == player;
    }
}
