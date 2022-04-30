/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "carcassonne.hpp"

void register_carcasonne_types() {
    ClassDB::register_class<Carcassonne>();
}

void unregister_carcasonne_types() {
   // Nothing to do here in this example.
}
