#include "Factory.h"

Event *EnemyFactory::makeItem(int choice) {
    return e_prototypes[choice]->clone();
}

Event *PropertyFactory::makeItem(int choice) {
    return p_prototypes[choice]->clone();
}

Event *UtilFactory::makeItem(int choice) {
    return u_prototypes[choice]->clone();
}
