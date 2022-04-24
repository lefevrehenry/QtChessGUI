import QtQuick 2.14
// import QtQuick.Layouts 1.14

import QtChessGUI.Controls 1.0

Item {
    id: root

    property var controller: ChessViewController {
        id: controller
    }

    Grid {
        id: grid

        columns: 8
        anchors.fill: parent

        readonly property int cw: width / 8
        readonly property int ch: height / 8

        Repeater {
            model: 64

            DropTile {
                width: grid.cw
                height: grid.ch

                lighten: controller.lightenTiles.includes(index)
                busy: controller.busyTiles.includes(index)
                inLastMove: controller.lastMovedTiles.includes(index)
            }
        }
    }

    Timer {
        interval: 1000
        running: true
        repeat: false
        onTriggered: { console.log("trigger"); controller.pieceAdded() }
    }

    property Component piece: DragIcon {
        id: piece

        // property int index: -1
        width: 32
        height: 32
    }

    Connections {
        target: controller
        function onPieceAdded() {
            // create DragIcon
            console.log("1")
            let newPiece = piece.createObject(root, {target: root})
            console.log("2")

            newPiece.destroy()
            newPiece = null
            console.log("3")
        }
    }

    // Repeater {
    //     id: pieces
    //
    //     model: root.pieces
    //
    //     delegate: DragIcon {
    //         // n: index
    //         // property var piece: modelData
    //     }
    // }
}
