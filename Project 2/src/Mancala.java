import java.util.List;

public class Mancala implements Game<State, Board, Integer> {


    private State initialState;
    private State currentState;
    Integer player1 = 1, player2 = 2;

    int currentPlaying;

    Mancala(State state) {

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
            if (!action.isTurn())
                nState.changePlayer();

            return nState;
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        return null;

    }

    @Override
    public boolean isTerminal(State state) {
        boolean bol = state.end();
        return bol;
    }


    /***
     *
     *  Permite ganhar vale 100 pontos
     *  permite turno extra 5 pontos
     *  comer peças 10
     *  permite adicionar uma peça 2 pontos
     *  diferença de peças entre openentes
     *
     * @param state
     * @param player
     * @return
     */
    @Override
    public double getUtility(State state, Integer player) {

        int adv = player == 1 ? 2 : 1;
        int diffP = state.diffPieces(player, adv);
        int eat = state.eatOpponent(player) ? 10 : 0;
        int turn = state.extraTurn(player) ? 5 : 0;
        int point = state.plus(player) ? 2 : 0;
        int won = state.won(player) ? 100 : 0;

        System.out.println(adv + diffP + eat + turn + point + won);
        return adv + diffP + eat + turn + point + won;
    }


}
