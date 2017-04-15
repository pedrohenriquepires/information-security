#include "stdbool.h"
#include "occupant.struct.h"

typedef struct Chair {
	bool reserved;
	Occupant occupant;
} Chair;
