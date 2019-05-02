import java.util.ArrayDeque;
import java.util.ArrayList;

class BFS extends Search {
    private static ArrayDeque<Node> frontier = new ArrayDeque<>();
    private static int exploredNodes = 0;


    static void go(Node root) {
        frontier.add(root);

        long startTime = System.currentTimeMillis();

        while(!frontier.isEmpty()) {
            Node node = frontier.removeFirst();
            exploredNodes++;

            if(node.isGoalState()) {
                memory = getMemory();
                elapsedTime = System.currentTimeMillis() - startTime;
                printSolution(node, exploredNodes);
                return;
            }

            ArrayList<Node> children = node.calculateChildren();
            for(Node child : children) {
                if(!node.repeats(child)) {
                    frontier.addLast(child);
                }
            }
        }

        memory = getMemory();
        elapsedTime = System.currentTimeMillis() - startTime;
        printSolution(null, exploredNodes);
    }
}
