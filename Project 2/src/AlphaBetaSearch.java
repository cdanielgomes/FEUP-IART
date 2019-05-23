/**
 * Artificial Intelligence A Modern Approach (3rd Ed.): Page 173.<br>
 * <p>
 * 
 * <pre>
 * <code>
 * function ALPHA-BETA-SEARCH(state) returns an action
 *   v = MAX-VALUE(state, -infinity, +infinity)
 *   return the action in ACTIONS(state) with value v
 *
 * function MAX-VALUE(state, alpha, beta) returns a utility value
 *   if TERMINAL-TEST(state) then return UTILITY(state)
 *   v = -infinity
 *   for each a in ACTIONS(state) do
 *     v = MAX(v, MIN-VALUE(RESULT(s, a), alpha, beta))
 *     if v >= beta then return v
 *     alpha = MAX(alpha, v)
 *   return v
 *
 * function MIN-VALUE(state, alpha, beta) returns a utility value
 *   if TERMINAL-TEST(state) then return UTILITY(state)
 *   v = infinity
 *   for each a in ACTIONS(state) do
 *     v = MIN(v, MAX-VALUE(RESULT(s,a), alpha, beta))
 *     if v <= alpha then return v
 *     beta = MIN(beta, v)
 *   return v
 * </code>
 * </pre>
 * <p>
 * Figure 5.7 The alpha-beta search algorithm. Notice that these routines are
 * the same as the MINIMAX functions in Figure 5.3, except for the two lines in
 * each of MIN-VALUE and MAX-VALUE that maintain alpha and beta (and the
 * bookkeeping to pass these parameters along).
 *
 * @param <S> Type which is used for states in the game.
 * @param <A> Type which is used for actions in the game.
 * @param <P> Type which is used for players in the game.
 * @author Ruediger Lunde
 */
public class AlphaBetaSearch {
    Mancala game;

    /**
     * Creates a new search object for a given game.
     */
    public static AlphaBetaSearch createFor(Mancala game) {
        return new AlphaBetaSearch(game);
    }

    public AlphaBetaSearch(Mancala game) {
        this.game = game;
    }

    public Board makeDecision(State state, int depth) {

        Board result = null;
        double resultValue = Double.NEGATIVE_INFINITY;
        Integer player = game.getPlayer(state);
        for (Board action : game.getActions(state)) {
            double value = action.isTurn()
                    ? maxValue(game.getResult(state, action), player, Double.NEGATIVE_INFINITY,
                            Double.POSITIVE_INFINITY, depth)
                    : minValue(game.getResult(state, action), player, Double.NEGATIVE_INFINITY,
                            Double.POSITIVE_INFINITY, depth);
            if (value > resultValue) {
                result = action;
                resultValue = value;
            }
       // pause();
        }
        return result;
    }

    public double maxValue(State state, Integer player, double alpha, double beta, int depth) {

        if (game.isTerminal(state) || depth == 0) {
            // pause();
            double x = game.getUtility(state, player);
         //   System.out.println("UTILITY = " + x);
            return x;
        }
        double value = Double.NEGATIVE_INFINITY;
        for (Board action : game.getActions(state)) {
            value = action.isTurn() ? Math.min(value, maxValue(game.getResult(state, action), player, alpha, beta, depth - 1))
                    : Math.max(value, minValue(game.getResult(state, action), player, alpha, beta, depth -1));

           // System.out.println("VALUE on maxValue = " + value);

            if (value >= beta)
                return value;
            alpha = Math.max(alpha, value);
        }

        //System.out.println("RETURNED VALUE ON maxValue = " + value + "\n\n\n");
       // pause();
        return value;
    }

    public double minValue(State state, Integer player, double alpha, double beta, int depth) {
        if (game.isTerminal(state) || depth == 0) {
            // pause();
            double x = game.getUtility(state, player);
          //  System.out.println("UTILITY = " + x);
            return x;
        }
        double value = Double.POSITIVE_INFINITY;
        for (Board action : game.getActions(state)) {
            value = action.isTurn() ? Math.max(value, minValue(game.getResult(state, action), player, alpha, beta, depth-1))
                    : Math.min(value, maxValue(game.getResult(state, action), player, alpha, beta, depth-1));

//            System.out.println("VALUE on minValue = " + value);

            if (value <= alpha)
                return value;
            beta = Math.min(beta, value);
        }

  //      System.out.println("RETURNED VALUE ON minValue = " + value + "\n\n\n");
       // pause();
        return value;
    }

    public void pause() {
        try {
            Thread.sleep(3000);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}