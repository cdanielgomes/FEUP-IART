import java.util.ArrayList;

class Node {
    enum Operator {UP, DOWN, LEFT, RIGHT}

    protected static int dimensions;
    //private static ArrayList<ArrayList<Integer>> goalState;

    protected ArrayList<ArrayList<Integer>> state; // board
    protected Node parentNode;
    protected int depth;
    protected int pathCost;
    protected Operator operator;
    protected ArrayList<Node> children = new ArrayList<>();

    Node() {
        this.state = state;
        this.parentNode = null;
        this.depth = 0;
        this.pathCost = 0;
        this.operator = null;
    }

    // root
    Node(ArrayList<ArrayList<Integer>> state) {
        dimensions = state.size();

        this.state = state;
        this.parentNode = null;
        this.depth = 0;
        this.pathCost = 0;
        this.operator = null;
    }

    private Node(ArrayList<ArrayList<Integer>> nextState, Node parentNode, int depth, int pathCost, Operator op) {
        this.state = nextState;
        this.parentNode = parentNode;
        this.depth = depth;
        this.pathCost = pathCost;
        this.operator = op;
    }

    /*
    private boolean verifyDimensions() {
    }
    */

    private void addChild(Node child) {
        if(child != null){
            this.children.add(child);
        }
    }

    ArrayList<Node> calculateChildren() {
        // TO DO
        return this.children;
    }

    private ArrayList<ArrayList<Integer>> cloneState() {
        ArrayList<ArrayList<Integer>> clone = new ArrayList<>();

        for(ArrayList<Integer> line : this.state) {
            clone.add((ArrayList<Integer>)line.clone());
        }

        return clone;
    }

    boolean isGoalState() {
        // TO DO

        return true;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Node) {
            Node node;
            try {
                node = (Node) obj;
            } catch (ClassCastException e) {
                e.printStackTrace();
                return false;
            }
            // TO DO
        }
        else {
            return false;
        }

        return true;
    }

    boolean repeats(Node node) {
        if(equals(node)) {
            return true;
        }

        if(this.parentNode == null) {
            return false;
        }

        return this.parentNode.repeats(node);
    }

    int getDepth() {
        return this.depth;
    }

    Node getParentNode() {
        return this.parentNode;
    }

    Operator getOperator() {
        return this.operator;
    }

    int getPathCost() {
        return this.pathCost;
    }

    void printState() {
        for(ArrayList<Integer> line : this.state) {
            for(int n : line) {
                System.out.format("%2d ", n);
            }
            System.out.println();
        }

        System.out.println("\n");
    }
}
