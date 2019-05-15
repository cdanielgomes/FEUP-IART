import java.util.List;

public class Malanca implements Game<State, Board, Integer> {

    private State initialState;
    private State currentState;
    Integer player1 = 1 , player2 = 2;

    int currentPlaying;

    Malanca(State state){

        this.initialState = state;
        this.currentState = state;
        this.currentPlaying = state.getPlayer();
    }


    @Override
    public State getInitialState() {
        return initialState;
    }

    @Override
    public Integer[] getPlayers() {
      Integer[] k = new Integer[2];
      k[0] = player1;
      k[1] = player2;
        return k;
    }

    @Override
    public Integer getPlayer(State state) {

        return state.getPlayer();
    }

    @Override
    public List<Board> getActions(State state) {
        return state.getActions();
    }

    @Override
    public State getResult(State state, Board action) {
        State nState;
        try {
            nState = (State) state.clone();
            nState.setBoard(action);
            nState.changePlayer();

            return nState;
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        return null;

    }

    @Override
    public boolean isTerminal(State state) {
        return state.end();
    }

    @Override
    public double getUtility(State state, Integer player) {
        return 0;
    }



}
