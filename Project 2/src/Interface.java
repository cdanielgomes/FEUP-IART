import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public interface Interface {
    void display();
}

class testClass implements Interface {

    public static enum PLAYS { PLAYER, AI};

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
                Integer player1 = 0;
                Integer player2 = 1;
                startGame(PLAYS.PLAYER, PLAYS.PLAYER);
                // playGamePP(player1, player2);
                System.out.println("\n");
                break;
            case "2":
                System.out.println("\n");
                Integer player5 = 0;
                Integer player6 = 1;
                startGame(PLAYS.AI, PLAYS.PLAYER);

                //playGamePC(player5, player6);
                System.out.println("\n");

                break;
            case "3":
                System.out.println("\n");
                Integer player3 = 0;
                Integer player4 = 1;
                startGame(PLAYS.AI, PLAYS.AI);
                //playGameCC(player3, player4);
                System.out.println("\n");
                break;
            case "q":
                System.out.println("Goodbye");
                break;

        }

    }


    private void startGame(PLAYS player1, PLAYS player2) {
        PLAYS[] players = new PLAYS[]{player1, player2};
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
                    state.makePlayerMove(askMove(state.getPlayer()));
                    break;
                case AI:
                    game = new Mancala(state);
                    ab = new AlphaBetaSearch(game);
                    board = ab.makeDecision(state);
                    if(board == null) System.out.println("É AQUI!");
                    state = new State(board, state.getPlayer());
                    break;
            }

            System.out.println("chegamos a solução");
           
           try{ 
            Thread.sleep(3000);
           }catch(Exception e){
               e.printStackTrace();
           }

        }

    }



    public int askMove(int player){
        Scanner scan = new Scanner(System.in);

        System.out.print("Choose a play player " + player + ": ");
        return scan.nextInt();
    }

    private int whoStarts() {
        System.out.println("WHO STARTS PLAYING?");
        System.out.println("Player 1 or Player 2");
        int choose;
        Scanner scan = new Scanner(System.in);

        do {

            choose = scan.nextInt();

            if(choose == 1 || choose == 2)
                break;

        } while (true);

        return choose;

    }


    /*

    public void playGamePP(Integer player1, Integer player2) {
        Board b = new Board();
        State state = new State(b, player1);
        Mancala game = new Mancala(state);
        do {
            b.draw();
            System.out.println("What's your move?");
            Scanner scan = new Scanner(System.in);
            int move = scan.nextInt();
            b.emptyHole(player1, move);
            state.changePlayer();

        }while (state.won(player1) == false && state.won(player2) == false);
        if(b.whoWon() == 0){
            System.out.println("Player 1 has won");
        }else{
            System.out.println("Player 2 has won");
        }
    }

    public void playGameCC(Integer player1, Integer player2) {
        Board b = new Board();
        State state = new State(b, player1);
        Mancala game = new Mancala(state);
        MinimaxSearch ai = new MinimaxSearch(game);
        do {
            state.changePlayer();
            ai.makeDecision(state);
            System.out.println("dicision made");
            b.draw();
        } while (!game.end());

        if(b.whoWon() == 0){
            System.out.println("Player 1 has won");
        }else if(b.whoWon() == 1){
            System.out.println("Player 2 has won");
        }else{
            System.out.println("DEU MERDA");

        }
    }

    public void playGamePC(Integer player1, Integer player2){
        Board b = new Board();
        State state = new State(b,player1);
        State state2 = new State(b,player2);
        Mancala game = new Mancala(state);
        MinimaxSearch ai = new MinimaxSearch(game);

        do{
            b.draw();
            System.out.println("What's your move?");
            Scanner scan = new Scanner(System.in);
            int move = scan.nextInt();
            b.emptyHole(player1, move);
            ai.makeDecision(state2);
            state2.changePlayer();

        }while (state2.won(player2) == false && state2.won(player2) == false);
        if(b.whoWon() == 0){
            System.out.println("Player 1 has won");
        }else{
            System.out.println("Player 2 has won");
        }
    }*/

}
