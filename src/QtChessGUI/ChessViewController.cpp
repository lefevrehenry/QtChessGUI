#include "ChessViewController.h"

//Qt
#include <QDebug>

ChessViewController::ChessViewController(QObject* parent) : QObject(parent),
    m_lightenTiles(),
    m_busyTiles(),
    m_lastMovedTiles()
{
    // m_lightenTiles << 2 << 4;
    // m_busyTiles << 8 << 10;
    // m_lastMovedTiles << 24 << 59;
}
