#ifndef QTCHESSGUI_CHESSVIEWCONTROLLER_H
#define QTCHESSGUI_CHESSVIEWCONTROLLER_H

//Qt
#include <QObject>
#include <QList>

class ChessViewController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<int> whitePieces READ whitePieces WRITE setWhitePieces NOTIFY whitePiecesChanged)
    Q_PROPERTY(QList<int> blackPieces READ blackPieces WRITE setBlackPieces NOTIFY blackPiecesChanged)
    Q_PROPERTY(QList<int> lightenTiles READ lightenTiles WRITE setLightenTiles NOTIFY lightenTilesChanged)
    Q_PROPERTY(QList<int> busyTiles READ busyTiles WRITE setBusyTiles NOTIFY busyTilesChanged)
    Q_PROPERTY(QList<int> lastMovedTiles READ lastMovedTiles WRITE setLastMovedTiles NOTIFY lastMovedTilesChanged)

    using Tiles = QList<int>;
    using Pieces = QList<int>;

public:
    ChessViewController(QObject* parent = nullptr);

public:
    Pieces whitePieces() const { return m_whitePieces; }
    Q_SLOT void setWhitePieces(const Pieces& newPieces) { if(m_whitePieces == newPieces) return; m_whitePieces = newPieces; emit whitePiecesChanged(newPieces); }
    Q_SIGNAL void whitePiecesChanged(Pieces newPieces);

    Pieces blackPieces() const { return m_blackPieces; }
    Q_SLOT void setBlackPieces(const Pieces& newPieces) { if(m_blackPieces == newPieces) return; m_blackPieces = newPieces; emit blackPiecesChanged(newPieces); }
    Q_SIGNAL void blackPiecesChanged(Pieces newPieces);

    Tiles lightenTiles() const { return m_lightenTiles; }
    Q_SLOT void setLightenTiles(const Tiles& newTiles) { if(m_lightenTiles == newTiles) return; m_lightenTiles = newTiles; emit lightenTilesChanged(newTiles); }
    Q_SIGNAL void lightenTilesChanged(Tiles newTiles);

    Tiles busyTiles() const { return m_busyTiles; }
    Q_SLOT void setBusyTiles(const Tiles& newTiles) { if(m_busyTiles == newTiles) return; m_busyTiles = newTiles; emit busyTilesChanged(newTiles); }
    Q_SIGNAL void busyTilesChanged(Tiles newTiles);

    Tiles lastMovedTiles() const { return m_lastMovedTiles; }
    Q_SLOT void setLastMovedTiles(const Tiles& newTiles) { if(m_lastMovedTiles == newTiles) return; m_lastMovedTiles = newTiles; emit lastMovedTilesChanged(newTiles); }
    Q_SIGNAL void lastMovedTilesChanged(Tiles newTiles);

public:
    Q_SIGNAL void pieceAdded();
    Q_SIGNAL void pieceRemoved();

private:
    Pieces m_whitePieces;
    Pieces m_blackPieces;

    Tiles m_lightenTiles;
    Tiles m_busyTiles;
    Tiles m_lastMovedTiles;

//     ChessBoard* chessBoard;

};

#endif // QTCHESSGUI_CHESSVIEWCONTROLLER_H
