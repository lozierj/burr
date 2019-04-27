#pragma once

#include <vector>

#include "Piece.h"
#include "Reflect.h"

bool TestReflect(Piece, Piece, Reflect);
Piece FindReflect(Piece, Reflect, const std::vector<Piece>&);
