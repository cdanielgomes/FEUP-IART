//
// Created by daniel on 02-04-2019.
//

#ifndef FEUP_IART_COMMON_H
#define FEUP_IART_COMMON_H


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
            return obj->equal(obj2);
        }
    };
}


#endif //FEUP_IART_COMMON_H
