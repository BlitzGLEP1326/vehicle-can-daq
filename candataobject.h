#ifndef CANDATAOBJECT_H
#define CANDATAOBJECT_H

#include <QByteArray>

class CanDataObject
{
public:
    CanDataObject();
    CanDataObject(const unsigned short&, const unsigned short&, const unsigned short&, const short&, const short&, const short&, const short&);
    CanDataObject(const CanDataObject&);
    unsigned short getEngineRpm() const;
    unsigned short getVehicleSpeed() const;
    unsigned short getFuelLevel() const;
    short getCoolantTempC() const;
    short getCoolantTempF() const;
    short getOilTempC() const;
    short getOilTempF() const;
    void setEngineRpm(const unsigned short&);
    void setVehicleSpeed(const unsigned short&);
    void setFuelLevel(const unsigned short&);
    void setCoolantTempC(const short&);
    void setCoolantTempF(const short&);
    void setOilTempC(const short&);
    void setOilTempF(const short&);
    unsigned short decodeEngineRpm(const QByteArray&) const;
    unsigned short decodeVehicleSpeed(const QByteArray&) const;
    unsigned short decodeFuelLevel(const QByteArray&) const;
    short decodeCoolantTempC(const QByteArray&) const;
    short decodeCoolantTempF(const QByteArray&) const;
    short decodeOilTempC(const QByteArray&) const;
    short decodeOilTempF(const QByteArray&) const;
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
