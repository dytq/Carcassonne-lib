#include "Pion.hpp"

Pion::Pion() {
    #ifndef DEBUG
    std::cout << "création d'un stack de Pion" << std::endl;
    #endif // DEBUG
}

void Pion::ajouter_meeple(Meeple * meeple) {

}
void Pion::supprimer_meeple(Meeple * meeple) {

}

const std::list<Meeple *> Pion::get_stack_meeple(){
    return this->stackMeeple;
}
