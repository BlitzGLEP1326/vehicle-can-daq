import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

// Animation for Fuel Gauge.
Timer {
    running: true
    repeat: true
    interval: 4500
    onTriggered: fuelGauge.value = fuelGauge.value == fuelGauge.maximumValue ? 0 : fuelGauge.maximumValue
}
/*
Gauge {
    id: fuelGauge
    style: FuelGaugeStyle {}
    height: 120
    minimumValue: 0
    maximumValue: 100
    tickmarkStepSize: 25
    value: 0
    orientation: Qt.Vertical
    anchors.verticalCenter: parent.verticalCenter

    formatValue: function(value) {
        return value + "%";
    }

    Behavior on value {
        NumberAnimation {
            duration: 4000
        }
    }
}*/
