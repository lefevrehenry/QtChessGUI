#ifndef QTCHESSGUI_CHESSBOARD_H
#define QTCHESSGUI_CHESSBOARD_H

#include <map>
#include <vector>

// enum Number
// {
//     0,
//     1,
//     2,
//     3,
//     4,
//     5,
//     6,
//     7
// };

enum class Id
{
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

struct Position
{
    int line;
    int column;
};

struct Piece
{
    Id id;
    Position position;
};

struct Move
{
    Position src;
    Position dst;
};

using Positions = std::vector<Position>;
using Pieces = std::vector<Piece>;
using Moves = std::vector<Move>;

struct ChessControler
{
public:
    // void play_move(ChessBoard& board, const Move& move)
    // {
    //     const Position& startpos = move.src;
    //     const Position& endpos = move.dst;
    //
    //     Piece* ally_piece = board.get(startpos);
    //     Piece* capturing_piece = board.get(endpos);
    //
    //     if(capturing_piece)
    //     {
    //     }
    //
    //     piece->position = endpos;
    // }

    // void reverse_move(ChessBoard& board, const Move& move)
    // {
    //
    // }
};

class ChessBoard
{
    // Pour chaque joueur
    // Liste les pieces + leurs positions

    // Pieces m_white_pieces;
    // Pieces m_black_pieces;
};

class MetaInfo
{
    // l'info de la prise en passant
    // le rock des rois dispo ou pas
    // promotion qui vient d'avoir lieu
    // a qui le tour
    // le nombre de tour sans prise (> 50) = pat
    // 3 répétations = pat
};

class ChessHistoric
{
    ChessBoard startpos;
    Moves moves;
};

class ChessController
{
    // un Board
    // ses MetaInfo
    // son Historic

    // move
    // move-back
};

#endif // QTCHESSGUI_CHESSBOARD_H
