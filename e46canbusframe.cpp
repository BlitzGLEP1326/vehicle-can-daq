#include "e46canbusframe.h"

E46CanBusFrame::E46CanBusFrame()
{

}

E46CanBusFrame::E46CanBusFrame(FrameType type = DataFrame)
:
    QCanBusFrame(type)
{}

E46CanBusFrame::E46CanBusFrame(quint32 identifier, const QByteArray &data)
:
    QCanBusFrame(identifier, data)
{}

unsigned short E46CanBusFrame::decodeEngineRpm(const QByteArray &payload) const
{
    /*
    Unit: RPM
    CAN Id: 0x316 (790)
    Conversion: ((B4 * 256) + B3) / 6.4
    */

    if(frameId() != engine_rpm_id_)
        return 0;

    unsigned short b3, b4;

    b3 = payload[2];
    b4 = payload[3];

    return ((b4 * 256) + b3) / 6.4;
}

unsigned short E46CanBusFrame::decodeVehicleSpeed(const QByteArray &payload) const
{
    /*
    Unit: ?
    CAN Id: ?
    Conversion: ?
    */

    if(frameId() != vehicle_speed_id_)
        return 0;

    QByteArray data = payload;
    return 0;
}

unsigned short E46CanBusFrame::decodeFuelLevel(const QByteArray &payload) const
{
    /*
    Unit: Liters
    CAN Id: 0x613 (1555)
    Conversion: B2
    Note: B2 is fuel level. Full being hex 39. Fuel light comes on at hex 8.
    */

    if(frameId() != fuel_level_id_)
        return 0;

    unsigned short b2;

    b2 = payload[1];

    return b2;
}

short E46CanBusFrame::decodeCoolantTempC(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x329 (809)
    Conversion: (B2 * 0.75) - 48.373
    */

    if(frameId() != coolant_temp_c_id_)
        return 0;

    unsigned short b2;

    b2 = payload[1];

    return (b2 * 0.75) - 48.373;
}

short E46CanBusFrame::decodeCoolantTempF(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x329 (809)
    Conversion: (decodeCoolantTempC * 1.8) + 32
    */

    return decodeCoolantTempC(payload) * 1.8 + 32;
}

short E46CanBusFrame::decodeOilTempC(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x545 (1349)
    Conversion: B5 - 48.373
    */

    if(frameId() != oil_temp_c_id_)
        return 0;

    unsigned short b5;

    b5 = payload[4];

    return b5 - 48.373;
}

short E46CanBusFrame::decodeOilTempF(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x545 (1349)
    Conversion: (decodeOilTempC * 1.8) + 32
    */

    return decodeOilTempC(payload) * 1.8 + 32;
}
