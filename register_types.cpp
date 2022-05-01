/* register_types.cpp */

#include "register_types.h"

#include "carcassonne.hpp"
#include "core/class_db.h"

void register_carcassonne_types() {
	ClassDB::register_class<Carcassonne>();
}

void unregister_carcassonne_types() {
	// Nothing to do here in this example.
}
