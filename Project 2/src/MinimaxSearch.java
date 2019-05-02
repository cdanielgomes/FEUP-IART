/*
 * @param <S> Type which is used for states in the game.
 * @param <A> Type which is used for actions in the game.
 * @param <P> Type which is used for players in the game.
 * @author Ruediger Lunde
 */
public class MinimaxSearch<S, A, P>  {

    //private Game<S, A, P> game;

    /*
    public static <S, A, P> MinimaxSearch<S, A, P> createFor(Game<S, A, P> game) {
        return new MinimaxSearch<>(game);
    }

    public MinimaxSearch(Game<S, A, P> game) {
        this.game = game;
    }

    public A makeDecision(S state) {
        A result = null;
        double resultValue = Double.NEGATIVE_INFINITY;
        P player = game.getPlayer(state);
        for (A action : game.getActions(state)) {
            double value = minValue(game.getResult(state, action), player);
            if (value > resultValue) {
                result = action;
                resultValue = value;
            }
        }
        return result;
    }

    public double maxValue(S state, P player) { // returns an utility
        if (game.isTerminal(state))
            return game.getUtility(state, player);
        double value = Double.NEGATIVE_INFINITY;
        for (A action : game.getActions(state))
            value = Math.max(value,
                    minValue(game.getResult(state, action), player));
        return value;
    }

    public double minValue(S state, P player) { // returns an utility
        if (game.isTerminal(state))
            return game.getUtility(state, player);
        double value = Double.POSITIVE_INFINITY;
        for (A action : game.getActions(state))
            value = Math.min(value,
                    maxValue(game.getResult(state, action), player));
        return value;
    }

     */

}
