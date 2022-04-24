import QtQuick 2.14

Rectangle {
    id: root

    // width: 32
    // height: 32

    Component.onCompleted: console.log("ctorrr")
    Component.onDestruction: console.log("dtorrr")

    property var target: null

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

    color: "green"

    Drag.active: dragArea.drag.active
    Drag.hotSpot.x: width / 2
    Drag.hotSpot.y: height / 2

    states: [
        State {
            when: dragArea.drag.active
            AnchorChanges {
                target: root
                anchors.verticalCenter: undefined
                anchors.horizontalCenter: undefined
            }
        }
    ]

    MouseArea {
        id: dragArea

        anchors.fill: parent

        drag.target: parent
        drag.smoothed: false

        // enabled: root.
        // onPressed: root.lifted = true
        onReleased: root.parent = (root.Drag.target !== null ? root.Drag.target : view)
    }
}

// Rectangle {
//     id: root
//
//     width: 32
//     height: 32
//
//     Drag.active: dragArea.drag.active
//
//     MouseArea {
//         id: dragArea
//         anchors.fill: parent
//
//         drag.target: parent
//         drag.smoothed: true
//     }
// }
