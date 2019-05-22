public class ABSearch {

    Mancala game;

    ABSearch(Mancala game) {

        this.game = game;
    }

    public Board makeDecision(State state, int player) {

        double v = Double.NEGATIVE_INFINITY;
        double tmp;
        Board o = null;
        for (Board board : state.getActions()) {

            tmp = maxValue(state, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY, player);

            if (tmp > v) {
                v = tmp;
                o = board;
            }
        }
        return o;
    }

    public double maxValue(State state, double alpha, double beta, int player) {

        if (game.isTerminal(state))
            return game.getUtility(state, player);

        double v = Double.NEGATIVE_INFINITY;

        for (Board a : game.getActions(state)) {
            v = a.isTurn() ? Math.max(v, maxValue(game.getResult(state, a), alpha, beta, player))
                    : Math.max(v, minValue(game.getResult(state, a), alpha, beta, player));
            if (v >= beta)
                return v;

            alpha = Math.max(alpha, v);
        }
        return v;
    }

    public double minValue(State state, double alpha, double beta, int player) {
        if (game.isTerminal(state))
            return game.getUtility(state, player);

        double v = Double.POSITIVE_INFINITY;
        for (Board a : game.getActions(state)) {
            v = a.isTurn() ? Math.max(v, minValue(game.getResult(state, a), alpha, beta, player))
                    : Math.min(v, maxValue(game.getResult(state, a), alpha, beta, player));

            if (v <= beta)
                return v;

            beta = Math.min(beta, v);
        }

        return v;
    }
}