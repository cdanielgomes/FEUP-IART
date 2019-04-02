#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"
#include <queue>
#include <deque>
#include <unistd.h>
#include <unordered_set>

namespace std {
    template<>
    struct hash<Node *> {
        size_t
        operator()(Node *obj) const {
            return hash<string>()(obj->toString());
        }
    };
}


namespace std {
    template<>
    struct equal_to<Node *> {
        bool
        operator()(Node *obj, Node *obj2) const {
            return obj->equal(*obj2);
        }
    };
}


class Search {
private:

    std::queue<Node *> frontier;
    std::unordered_set<Node *, std::hash<Node *>, std::equal_to<Node *>> explored;
public:
    Search();

    bool addToQueue(Node *node);

    Node *search();

    bool isGoalState(Node *node);

    bool expand(Node *node, Node *ancestor);

    bool find(Node *h);
};

#endif /* SEARCH_H */