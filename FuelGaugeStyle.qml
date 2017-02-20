import QtQuick 2.0
import QtQuick.Controls.Styles 1.4

GaugeStyle {
    valueBar: Rectangle {
        implicitWidth: 31
        color: fuelGauge.value <= 20 ? "#ff0000" : "#fff"
    }

    background: Rectangle {
        implicitWidth: 31
        color: "#262626"
    }

    foreground: null
    minorTickmark: null
    tickmarkLabel: null
    tickmark: null
}
