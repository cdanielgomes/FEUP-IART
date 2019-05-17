import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

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

interface Interface 
{ 
    void display(); 
} 
  
class testClass implements Interface 
{ 
    
    public void display() 
    { 
        System.out.println("\n\n"); 
        System.out.println("\n\n"); 
        System.out.println("\n\n"); 
        System.out.println("MMMMMMMM               MMMMMMMM              AAA              NNNNNNNN        NNNNNNNN       CCCCCCCCCCCCC              AAA              LLLLLLLLLLL                           AAA            "); 
        System.out.println("M:::::::M             M:::::::M             A:::A             N:::::::N       N::::::N    CCC::::::::::::C             A:::A             L:::::::::L                          A:::A   "); 
        System.out.println("M::::::::M           M::::::::M            A:::::A            N::::::::N      N::::::N  CC:::::::::::::::C            A:::::A            L:::::::::L                         A:::::A             "); 
        System.out.println("M:::::::::M         M:::::::::M           A:::::::A           N:::::::::N     N::::::N C:::::CCCCCCCC::::C           A:::::::A           LL:::::::LL                        A:::::::A            "); 
        System.out.println("M::::::::::M       M::::::::::M          A:::::::::A          N::::::::::N    N::::::NC:::::C       CCCCCC          A:::::::::A            L:::::L                         A:::::::::A                   "); 
        System.out.println("M:::::::::::M     M:::::::::::M         A:::::A:::::A         N:::::::::::N   N::::::C:::::C                       A:::::A:::::A           L:::::L                        A:::::A:::::A                  "); 
        System.out.println("M:::::::M::::M   M::::M:::::::M        A:::::A A:::::A        N:::::::N::::N  N::::::C:::::C                      A:::::A A:::::A          L:::::L                       A:::::A A:::::A                 "); 
        System.out.println("M::::::M M::::M M::::M M::::::M       A:::::A   A:::::A       N::::::N N::::N N::::::C:::::C                     A:::::A   A:::::A         L:::::L                      A:::::A   A:::::A                "); 
        System.out.println("M::::::M  M::::M::::M  M::::::M      A:::::A     A:::::A      N::::::N  N::::N:::::::C:::::C                    A:::::A     A:::::A        L:::::L                     A:::::A     A:::::A               "); 
        System.out.println("M::::::M   M:::::::M   M::::::M     A:::::AAAAAAAAA:::::A     N::::::N   N:::::::::::C:::::C                   A:::::AAAAAAAAA:::::A       L:::::L                    A:::::AAAAAAAAA:::::A              "); 
        System.out.println("M::::::M    M:::::M    M::::::M    A:::::::::::::::::::::A    N::::::N    N::::::::::C:::::C                  A:::::::::::::::::::::A      L:::::L                   A:::::::::::::::::::::A             "); 
        System.out.println("M::::::M     MMMMM     M::::::M   A:::::AAAAAAAAAAAAA:::::A   N::::::N     N:::::::::NC:::::C       CCCCCC   A:::::AAAAAAAAAAAAA:::::A     L:::::L         LLLLLL   A:::::AAAAAAAAAAAAA:::::A            "); 
        System.out.println("M::::::M               M::::::M  A:::::A             A:::::A  N::::::N      N::::::::N C:::::CCCCCCCC::::C  A:::::A             A:::::A  LL:::::::LLLLLLLLL:::::L  A:::::A             A:::::A           "); 
        System.out.println("M::::::M               M::::::M A:::::A               A:::::A N::::::N       N:::::::N  CC:::::::::::::::C A:::::A               A:::::A L::::::::::::::::::::::L A:::::A               A:::::A          "); 
        System.out.println("M::::::M               M::::::MA:::::A                 A:::::AN::::::N        N::::::N    CCC::::::::::::CA:::::A                 A:::::AL::::::::::::::::::::::LA:::::A                 A:::::A         "); 
        System.out.println("MMMMMMMM               MMMMMMMAAAAAAA                   AAAAAANNNNNNNN         NNNNNNN       CCCCCCCCCCCCAAAAAAA                   AAAAAALLLLLLLLLLLLLLLLLLLLLLLAAAAAAA                   AAAAAAA        "); 
        System.out.println("\n\n"); 
        System.out.println("\n\n"); 
        System.out.println("\n\n"); 
        System.out.println("\n\n"); 
        System.out.println("\n\n"); 

        ArrayList<ArrayList<Integer>> board = readPuzzle();

        if(board != null) {
            return;
        }else{
            //runAlgorithm(root, scan.nextInt());
            System.out.println("Done!\n");
            System.out.println("\n\n");  
        }

    } 

} 

    public static void main(String[] args) throws CloneNotSupportedException {

        Main m;
        m = new Main();
        testClass t = m.new testClass(); 
        t.display();

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
