#include "pch.h"

bool comp(Section &v1, Section &v2) {
	if (v1.g_priority() > v2.g_priority()) {
		return true;
	}

	// NOTREACHED
	return false;
}


