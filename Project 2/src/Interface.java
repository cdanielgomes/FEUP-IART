import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public interface Interface {
    void display();
}

class testClass implements Interface {

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
            playGamePP(player1, player2);
            System.out.println("\n");
            break;
        case "2":
            System.out.println("\n");
            Integer player5 = 0;
            Integer player6 = 1;
            playGamePC(player5, player6);
            System.out.println("\n");

            break;
        case "3":
            System.out.println("\n");
            Integer player3 = 0;
            Integer player4 = 1;
            playGameCC(player3, player4);
            System.out.println("\n");
            break;
        case "q":
            System.out.println("Goodbye");
            break;

        }

    }

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
            b.draw();
        } while (state.won(player1) == false && state.won(player2) == false);
        if(b.whoWon() == 0){
            System.out.println("Player 1 has won");
        }else{
            System.out.println("Player 2 has won");
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
    }

}
