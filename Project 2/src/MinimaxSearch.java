/*
 * @param <S> Type which is used for states in the game.
 * @param <A> Type which is used for actions in the game.
 * @param <P> Type which is used for players in the game.
 * @author Ruediger Lunde
 */
public class MinimaxSearch  {

    private Malanca game;


    public static  MinimaxSearch createFor(Malanca game) {
        return new MinimaxSearch(game);
    }

    public MinimaxSearch(Malanca game) {
        this.game = game;
    }

    public Board makeDecision(State state) {
        Board result = null;
        double resultValue = Double.NEGATIVE_INFINITY;
        int player = game.getPlayer(state);
        for (Board action : game.getActions(state)) {
            double value = minValue(game.getResult(state, action), player);
            if (value > resultValue) {
                result = action;
                resultValue = value;
            }
        }
        return result;
    }

    public double maxValue(State state, int player) { // returns an utility
        if (game.isTerminal(state))
            return game.getUtility(state, player);
        double value = Double.NEGATIVE_INFINITY;
        for (Board action : game.getActions(state))
            value = Math.max(value,
                    minValue(game.getResult(state, action), player));
        return value;
    }

    public double minValue(State state, int player) { // returns an utility
        if (game.isTerminal(state))
            return game.getUtility(state, player);
        double value = Double.POSITIVE_INFINITY;
        for (Board action : game.getActions(state))
            value = Math.min(value,
                    maxValue(game.getResult(state, action), player));
        return value;
    }





}
