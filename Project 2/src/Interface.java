import java.util.Scanner;
import java.util.ArrayList;

class Interface {

    public static enum PLAYS {
        PLAYER, AI
    };

    int[] depth = new int[2];

    Boolean q = true;

    ArrayList<Long> playTimes = new ArrayList<Long>();

    public void timeCalculations() {

        do {
            long init = System.currentTimeMillis();

            display();

            long fin = System.currentTimeMillis();
            if (q)
                System.out.println("\n\n --------------------------------------\nThe game took " + (fin - init)
                        + " miliseconds\n\n----------------------------------");
        } while (q);

    }

    public void display() {
        System.out.println("Menu: ");
        System.out.println("1 : Player vs Player");
        System.out.println("2 : Computer vs Player");
        System.out.println("3 : Computer vs Computer");
        System.out.println("q : Quit");
        Scanner scan = new Scanner(System.in);
        String choice = scan.nextLine();

        switch (choice) {
        case "1":
            System.out.println("\n");

            startGame(PLAYS.PLAYER, PLAYS.PLAYER);
            // playGamePP(player1, player2);
            System.out.println("\n");
            break;
        case "2":
            System.out.println("\n");
            level();
            startGame(PLAYS.AI, PLAYS.PLAYER);
            // playGamePC(player5, player6);
            System.out.println("\n");

            break;
        case "3":
            System.out.println("\n");
            depth[0] = chooseDepth(1);
            depth[1] = chooseDepth(2);
            startGame(PLAYS.AI, PLAYS.AI);

            // playGameCC(player3, player4);
            System.out.println("\n");
            break;
        case "q":
            q = false;
            System.out.println("Goodbye");
            break;

        }

    }

    private void level() {
        Scanner scan = new Scanner(System.in);

        Integer lv;
        do {
            System.out.println("1 - easy ");
            System.out.println("2 - medium ");
            System.out.println("3 - hard ");

            System.out.print("\n\n Choose level: ");

            lv = scan.nextInt();
            if (lv == 1)
                break;
            else if (lv == 2)
                break;
            else if (lv == 3)
                break;

        } while (true);
        switch (lv) {
        case 1:
            depth[0] = 2;
            break;
        case 2:
            depth[0] = 7;
            break;
        case 3:
            depth[0] = 10;
            break;
        }

    }

    private void startGame(PLAYS player1, PLAYS player2) {
        PLAYS[] players = new PLAYS[] { player1, player2 };
        int first = whoStarts();

        Board board = new Board();
        State state = new State(board, first);
        Mancala game = new Mancala(state);
        int move = 0;

        MinimaxSearch min = new MinimaxSearch(game);

        AlphaBetaSearch ab = new AlphaBetaSearch(game);

        while (!game.isTerminal(state)) {

            state.getBoard().draw();

            switch (players[state.getPlayer() - 1]) {
            case PLAYER:
                state.makePlayerMove(askMove(state, ab));
                break;
            case AI:
                long init = System.currentTimeMillis();
                game = new Mancala(state);
                ab = new AlphaBetaSearch(game);
                board = ab.makeDecision(state, depth[state.getPlayer() - 1]);
                if (board == null)
                    System.out.println("É AQUI!");
                System.out.println("Player " + state.getPlayer() + " played in hole number = " + board.getPlay());
                if (!board.isTurn())
                    state.changePlayer();
                state = new State(board, state.getPlayer());

                long fin = System.currentTimeMillis();

                System.out.println("Play calculated in " + (fin - init) + " milisseconds");
                break;
            }
        }

        System.out.println("Player " + state.getBoard().whoWon() + " won! ");

    }

    public Integer askMove(State state, AlphaBetaSearch l) {
        Scanner scan = new Scanner(System.in);
        boolean loop = true;
        Integer move = null;

        do {
            System.out.println("For a hint write \"hint\"\n");
            System.out.print("Choose a play player " + state.getPlayer() + ": ");
            String line = scan.nextLine();

            if ("hint".equals(line)) {
                try {
                    State n = (State) state.clone();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                move = hint(state, l);
                loop = false;
            }

            else {
                try {
                    move = Integer.parseInt(line);
                    if (!(move < 1 || move > 7))
                        loop = false;
                    else
                        System.out.println("Pick a valid hole\n");
                } catch (Exception e) {
                    System.out.println("Write \"hint\" for an hint or a valid play");
                }

            }

        } while (loop);

        System.out.println("\n");
        return move;
    }

    public int chooseDepth(int p) {
        Scanner scan = new Scanner(System.in);
        Integer depth = null;
        System.out.print("Choose the depth for the AI player " + p + ": ");
        do {
            depth = scan.nextInt();
        } while (depth == null);

        return depth;
    }

    public int hint(State state, AlphaBetaSearch l) {
        int hole = l.makeDecision(state, 5).getPlay();
        System.out.println("Your best play this moment is in the hole: " + hole + "\n");
        return hole;
    }

    private int whoStarts() {
        System.out.println("WHO STARTS PLAYING?");
        System.out.print("Player 1 or Player 2: ");
        int choose;
        Scanner scan = new Scanner(System.in);

        do {

            choose = scan.nextInt();

            if (choose == 1 || choose == 2)
                break;

        } while (true);

        return choose;

    }

    /*
     * 
     * public void playGamePP(Integer player1, Integer player2) { Board b = new
     * Board(); State state = new State(b, player1); Mancala game = new
     * Mancala(state); do { b.draw(); System.out.println("What's your move?");
     * Scanner scan = new Scanner(System.in); int move = scan.nextInt();
     * b.emptyHole(player1, move); state.changePlayer();
     * 
     * }while (state.won(player1) == false && state.won(player2) == false);
     * if(b.whoWon() == 0){ System.out.println("Player 1 has won"); }else{
     * System.out.println("Player 2 has won"); } }
     * 
     * public void playGameCC(Integer player1, Integer player2) { Board b = new
     * Board(); State state = new State(b, player1); Mancala game = new
     * Mancala(state); MinimaxSearch ai = new MinimaxSearch(game); do {
     * state.changePlayer(); ai.makeDecision(state);
     * System.out.println("dicision made"); b.draw(); } while (!game.end());
     * 
     * if(b.whoWon() == 0){ System.out.println("Player 1 has won"); }else
     * if(b.whoWon() == 1){ System.out.println("Player 2 has won"); }else{
     * System.out.println("DEU MERDA");
     * 
     * } }
     * 
     * public void playGamePC(Integer player1, Integer player2){ Board b = new
     * Board(); State state = new State(b,player1); State state2 = new
     * State(b,player2); Mancala game = new Mancala(state); MinimaxSearch ai = new
     * MinimaxSearch(game);
     * 
     * do{ b.draw(); System.out.println("What's your move?"); Scanner scan = new
     * Scanner(System.in); int move = scan.nextInt(); b.emptyHole(player1, move);
     * ai.makeDecision(state2); state2.changePlayer();
     * 
     * }while (state2.won(player2) == false && state2.won(player2) == false);
     * if(b.whoWon() == 0){ System.out.println("Player 1 has won"); }else{
     * System.out.println("Player 2 has won"); } }
     */

}
