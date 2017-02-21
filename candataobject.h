#ifndef CANDATAOBJECT_H
#define CANDATAOBJECT_H

#include <QByteArray>

class CanDataObject
{
public:
    CanDataObject();
    unsigned short getEngineRpm() const;
    unsigned short getVehicleSpeed() const;
    unsigned short getFuelLevel() const;
    short getCoolantTempC() const;
    short getCoolantTempF() const;
    short getOilTempC() const;
    short getOilTempF() const;
    void setEngineRpm(unsigned short);
    void setVehicelSpeed(unsigned short);
    void setFuelLevel(short);
    void setCoolantTempC(short);
    void setCoolantTempF(short);
    void setOilTempC(short);
    void setOilTempF(short);
    unsigned short decodeEngineRpm(QByteArray) const;
    unsigned short decodeVehicleSpeed(QByteArray) const;
    unsigned short decodeFuelLevel(QByteArray) const;
    short decodeCoolantTempC(QByteArray) const;
    short decodeCoolantTempF(QByteArray) const;
    short decodeOilTempC(QByteArray) const;
    short decodeOilTempF(QByteArray) const;
private:
    unsigned short engine_rpm_;
    unsigned short vehicle_speed_;
    unsigned short fuel_level_;
    short coolant_temp_c_;
    short coolant_temp_f_;
    short oil_temp_c_;
    short oil_temp_f_;
};

#endif // CANDATAOBJECT_H
