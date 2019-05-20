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
            playGame();
            System.out.println("\n");
            break;
        case "2":
            System.out.println("\n");
            playGame();
            System.out.println("\n");

            break;
        case "3":
            System.out.println("\n");
            playGame();
            System.out.println("\n");
            break;
        case "q":
            System.out.println("Goodbye");
            break;

        }

    }

    public void playGame() {
        Board b = new Board();
        int p = 0;
        State state = new State(b, p);
        Mancala game = new Mancala(state);
        int player = game.getPlayer(state);
        do {
            b.draw();
            // player = m.getPlayers();
            System.out.println("What's your move?");
            Scanner scan = new Scanner(System.in);
            int move = scan.nextInt();
            b.emptyHole(player, move);
            state.changePlayer();

        } while (state.won(player) == false);
    }

}
