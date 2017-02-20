import QtQuick 2.5
import QtQuick.Controls.Styles 1.4

CircularGaugeStyle {
    tickmarkStepSize: 1
    minorTickmarkCount: 1
    labelStepSize: 1

    tickmark: Rectangle {
        visible: true
        implicitWidth: outerRadius * 0.03
        implicitHeight: outerRadius * 0.08
        color: styleData.value >= 7 ? "#ff0000" : "#fff"
        antialiasing: true
    }
    minorTickmark: Rectangle {
        visible: true
        implicitWidth: outerRadius * 0.01
        implicitHeight: outerRadius * 0.08
        color: styleData.value >= 7 ? "#ff0000" : "#fff"
        antialiasing: true
    }
    tickmarkLabel: Text {
        font.pixelSize: Math.max(25, outerRadius * 0.1)
        text: styleData.value
        color: styleData.value >= 7 ? "#ff0000" : "#fff"
        antialiasing: true
    }
    needle: Rectangle {
        y: outerRadius * 0.15
        implicitWidth: outerRadius * 0.03
        implicitHeight: outerRadius
        color: "#FF0000"
        antialiasing: true
    }
    foreground: Item {
        Rectangle {
            width: outerRadius * 0.28
            height: width
            radius: width / 2
            color: "#161616"
            anchors.centerIn: parent
        }
    }
}
