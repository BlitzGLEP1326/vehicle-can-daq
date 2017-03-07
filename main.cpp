#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QCanBus>
#include <QCanBusDevice>
#include "e46canbusframe.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Load gauge UI.
    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *object = component.create();
    //delete object;

    // Create CAN bus device and connect to can0 via SocketCAN plugin.
    QCanBusDevice *device;

    if(QCanBus::instance()->plugins().contains("socketcan"))
    {
        device = QCanBus::instance()->createDevice("socketcan", "can0");
        device->connectDevice();
    }

    // Set filters for needed data frames from the CAN bus device.
    if(device->state() == QCanBusDevice::ConnectedState)
    {
        const unsigned short ENGINE_RPM = 0x316u;
        // const unsigned short VEHICLE_SPEED = ?;
        const unsigned short FUEL_LEVEL = 0x613u;
        const unsigned short COOLANT_TEMP = 0x329u;
        const unsigned short OIL_TEMP = 0x545u;

        QCanBusDevice::Filter filter;
        QList<QCanBusDevice::Filter> filterList;

        // Filter engine rpm.
        filter.frameId = ENGINE_RPM;
        filter.frameIdMask = 0x7FFu; // Compare against all 11-bits of frame id.
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Filter vehicle speed

        // Filter fuel level
        filter.frameId = FUEL_LEVEL;
        filter.frameIdMask = 0x7FFu; // Compare against all 11-bits of frame id.
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Filter coolant temp
        filter.frameId = COOLANT_TEMP;
        filter.frameIdMask = 0x7FFu; // Compare against all 11-bits of frame id.
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Filter oil temp
        filter.frameId = OIL_TEMP;
        filter.frameIdMask = 0x7FFu; // Compare against all 11-bits of frame id.
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Apply filter to CAN Bus device.
        device->setConfigurationParameter(QCanBusDevice::RawFilterKey, QVariant::fromValue(filterList));

        // Read frames and push decoded data to appropriate gauge for display.
        while(device->framesAvailable() > 0 && device->state() == QCanBusDevice::ConnectedState)
        {
            E46CanBusFrame canFrame(device->readFrame().frameId(), device->readFrame().payload());

            switch(canFrame.frameId())
            {
            case ENGINE_RPM:
                object->setProperty("rpmValue", canFrame.decodeEngineRpm(canFrame.payload()));
                break;
            /*case VEHICLE_SPEED:
                object->setProperty("speedValue", canFrame.decodeVehicleSpeed(canFrame.payload()));
                break;*/
            case FUEL_LEVEL:
                object->setProperty("fuelValue", canFrame.decodeFuelLevel(canFrame.payload()));
                break;
            case COOLANT_TEMP:
                object->setProperty("coolantValue", canFrame.decodeCoolantTempC(canFrame.payload()));
                break;
            case OIL_TEMP:
                object->setProperty("oilValue", canFrame.decodeOilTempC(canFrame.payload()));
                break;
            default:
                break;
            }
        }

        delete device;
    }

    return app.exec();
}
