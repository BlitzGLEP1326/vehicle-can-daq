#include "candataobject.h"

CanDataObject::CanDataObject()
{

}

unsigned short CanDataObject::getEngineRpm() const
{
    return 0;
}

void CanDataObject::setEngineRpm(const unsigned short &val)
{
    engine_rpm_ = val;
}

unsigned short CanDataObject::getVehicleSpeed() const
{
    return 0;
}

void CanDataObject::setVehicleSpeed(const unsigned short &val)
{
    vehicle_speed_ = val;
}

unsigned short CanDataObject::getFuelLevel() const
{
    return 0;
}

void CanDataObject::setFuelLevel(const unsigned short &val)
{
    fuel_level_ = val;
}

short CanDataObject::getCoolantTempC() const
{
    return 0;
}

void CanDataObject::setCoolantTempC(const short &val)
{
    coolant_temp_c_ = val;
}

short CanDataObject::getCoolantTempF() const
{
    return 0;
}

void CanDataObject::setCoolantTempF(const short &val)
{
    coolant_temp_f_ = val;
}

short CanDataObject::getOilTempC() const
{
    return 0;
}

void CanDataObject::setOilTempC(const short &val)
{
    oil_temp_c_ = val;
}

short CanDataObject::getOilTempF() const
{
    return 0;
}

void CanDataObject::setOilTempF(const short &val)
{
    oil_temp_f_ = val;
}

unsigned short CanDataObject::decodeEngineRpm(const QByteArray &payload) const
{
    /*
    Unit: RPM
    CAN Id: 0x316 (790)
    Connversion: ((B4 * 256) + B3) / 6.4
    */

    QByteArray data = payload;
    return 0;
}

unsigned short CanDataObject::decodeVehicleSpeed(const QByteArray &payload) const
{
    /*
    Unit: ?
    CAN Id: ?
    Connversion: ?
    */

    QByteArray data = payload;
    return 0;
}

unsigned short CanDataObject::decodeFuelLevel(const QByteArray &payload) const
{
    /*
    Unit: Hex
    CAN Id: 0x613 (1555)
    Connversion: B2
    Note: B2 is fuel level. Full being hex 39. Fuel light comes on at hex 8. Then values jump to hex 87 (or so) and then go down to hex 80 being empty.
    */

    QByteArray data = payload;
    return 0;
}

short CanDataObject::decodeCoolantTempC(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x329 (809)
    Connversion: (B2 * 0.75) - 48.373
    */

    QByteArray data = payload;
    return 0;
}

short CanDataObject::decodeCoolantTempF(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x329 (809)
    Connversion: (decodeCoolantTempC * 1.8) + 32
    */

    QByteArray data = payload;
    return 0;
}

short CanDataObject::decodeOilTempC(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x545 (1349)
    Connversion: B5 - 48.373
    */

    QByteArray data = payload;
    return 0;
}

short CanDataObject::decodeOilTempF(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x545 (1349)
    Connversion: (decodeOilTempC * 1.8) + 32
    */

    QByteArray data = payload;
    return 0;
}
