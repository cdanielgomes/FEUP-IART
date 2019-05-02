import java.util.ArrayDeque;

class Search {
    private static final long KILOBYTE = 1024L;

    static long memory;
    static long elapsedTime;

    static long getMemory() { // bytes
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        return runtime.totalMemory() - runtime.freeMemory();
    }

    private static long bytesToKilobytes(long bytes) {
        return bytes / KILOBYTE;
    }

    static void printSolution(Node goal, int exploredNodes) {
        if(goal == null) {
            System.out.println("Couldn't find a solution...\n");
            return;
        }

        Node node = goal;
        ArrayDeque<Node> solution = new ArrayDeque<>();

        while(node != null) {
            solution.addFirst(node);
            node = node.getParentNode();
        }

        while(!solution.isEmpty()) {
            node = solution.removeFirst();

            Node.Operator op = node.getOperator();
            if(op != null) {
                System.out.println("Move blank space " + op + ":\n");
            }
            node.printState();
        }

        System.out.println("Explored nodes: " + exploredNodes);
        System.out.println("Solution depth: " + goal.getDepth());
        System.out.println("Solution path cost: " + goal.getPathCost() + "\n");

        System.out.println("Execution time: " + elapsedTime + "ms");
        System.out.println("Memory usage: " + bytesToKilobytes(memory) + "KB\n");
    }
}
