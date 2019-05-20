import java.io.File;
import java.io.FileNotFoundException;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Scanner;


public class Main{

    private static ArrayList<ArrayList<Integer>> readPuzzle() {
        Scanner input;
        try {
            input = new Scanner(new File("../res/puzzle.txt"));
        } catch (FileNotFoundException e) {
            System.out.println("\n\nCan't find res/puzzle.txt. Please make sure your puzzles are there!");
            System.out.println("\n\n"); 
            System.out.println("\n\n"); 
            System.out.println("\n\n");
            return null;
        }

        ArrayList<ArrayList<Integer>> board = new ArrayList<>();

        while(input.hasNextLine()) {
            String fileLine = input.nextLine();
            if(fileLine.length() == 0) {
                continue;
            }
            Scanner lineReader = new Scanner(fileLine);
            ArrayList<Integer> line = new ArrayList<>();
            while(lineReader.hasNextInt()) {
                line.add(lineReader.nextInt());
            }
            board.add(line);
            lineReader.close();
        }

        input.close();
        return board;
    }


    private static void runAlgorithm(Node root, int alg) {
    }

    public static void main(String[] args) {
        testClass t = new testClass(); 
        t.display();

        System.out.println("\nDrawing initial board: \n");
        Board initialBoard = State.getInitialBoard();
        initialBoard.draw();
    }

  

    public static void promptMenu() throws CloneNotSupportedException {

/*        System.out.println("\n\nHello! Welcome to the N-Puzzle Solver.\n\nWe're reading your puzzle under res/puzzle.txt...");
        ArrayList<ArrayList<Integer>> board = readPuzzle();
        if(board == null) {
            return;
        }
        System.out.println("Done!\n");*/


/*        Scanner scan = new Scanner(System.in);
        System.out.println("What algorithm would you like me to run?");
        System.out.println("1 - Breadth First Search");
        System.out.println("2 - Greedy");
        System.out.println("3 - A*");

        runAlgorithm(root, scan.nextInt());*/
    }

}
