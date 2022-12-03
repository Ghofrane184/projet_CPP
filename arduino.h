#ifndef ARDUINO_H
#define ARDUINO_H


#include <QSerialPort>
#include<QString>
class Arduino {

public:

    Arduino();
    bool checkArduino();
    bool getConnected();
    void set_arduino_uno_vendor_id(quint16);
    void set_arduino_uno_product_id(quint16);
    void set_arduino_port_name(QString);
    bool checkAccessRFID(QString);
    bool closeArduino();
    QSerialPort *arduino ;


private:

    quint16 arduino_uno_vendor_id;
    quint16 arduino_uno_product_id;
    QString arduino_port_name;
    bool arduino_is_available;

};
#endif // ARDUINO_H

