import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Shapes 1.14

DropArea {
    id: root

    property bool lighten: false
    property bool busy: false
    property bool inLastMove: false

    // property 'modelData' is read from the caller
    readonly property int index: modelData

    readonly property int row: (63 - index) / 8
    readonly property int column: index % 8

    Rectangle {
        id: tile

        anchors.fill: parent
        color: (row + column) % 2 === 0 ? "red" : "green"

        states: [
            State {
                when: root.containsDrag
                PropertyChanges {
                    target: tile
                    color: "grey"
                }
            }
        ]

        Rectangle {
            id: lightenTile

            width: tile.width / 4
            height: tile.height / 4

            anchors.centerIn: parent

            visible: root.lighten
            color: "lightgrey"
            radius: 16
        }

        Rectangle {
            id: busyTile

            width: tile.width / 4
            height: tile.height / 4

            anchors.left: parent.left
            anchors.top: parent.top

            visible: root.busy
            color: "lightgrey"
        }

        Rectangle {
            id: lastTile

            anchors.fill: parent

            visible: root.inLastMove
            color: "yellow"
            opacity: .5
        }

        // Label {
        //     anchors.centerIn: parent
        //     text: root.row + ", " + root.column
        // }
    }
}
