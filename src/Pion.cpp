#include "Pion.hpp"

Pion::Pion() {
    #ifndef DEBUG
    std::cout << "création d'un stack de Pion" << std::endl;
    #endif // DEBUG
}

void Pion::ajouter_meeple(Meeple * meeple) {
    if(meeple == NULL) {
        #ifndef DEBUG
        std::cout << "essaie d'inserer un meeple null dans la pile" << std::endl;
        #endif // DEBUG
    }
    this->stackMeeple.push_front(meeple);
}

void Pion::supprimer_meeple(Meeple * meeple) {

}

const std::list<Meeple *> Pion::get_stack_meeple(){
    return this->stackMeeple;
}
