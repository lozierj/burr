#pragma once

#include <array>

#include "Piece.h"
#include "Position.h"
#include "Translate.h"

bool TestFit(Piece, Position,
    Piece, Position,
    Translate offset = Translate(0, 0, 0));

bool TestFit(const std::array<Piece, 6>&);
