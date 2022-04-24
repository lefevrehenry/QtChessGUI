import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
// import QtQuick.Window 2.14
// import QtQml 2.14

import QtChessGUI.Widgets 1.0

ColumnLayout {
    id: root

    // ChessBoardProxy {
    //     id: chessBoardProxy
    // }

    ChessView {
        id: chessView

        Layout.preferredWidth: 640
        Layout.preferredHeight: 640
    }

    Item {
        id: view

        Layout.preferredWidth: 640
        Layout.preferredHeight: 64

        DragIcon {
            width: 80
            height: 80
        }
    }

    // Rectangle {
    //     // Layout.alignment: Qt.AlignHCenter
    //     Layout.preferredWidth: 320
    //     Layout.preferredHeight: 32
    //
    //     color: "red"
    // }
}

// ApplicationWindow {
//     id: root
//
//     width: 640
//     height: 480
//
//     Component.onCompleted: showNormal()
//
//     Rectangle {
//         anchors.fill: parent
//
//         color: "green"
//     }
// }
