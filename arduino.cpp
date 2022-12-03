#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QIODevice>
#include <QDebug>
#include<QTextCodec>
Arduino::Arduino(){}



/*bool Arduino::checkArduino(){
    try {

        QList<QSerialPortInfo> availableSerialPorts = QSerialPortInfo::availablePorts();
        if(availableSerialPorts.length() == 0){
            return false;
        }else if(availableSerialPorts.length() >=  1){
            if(availableSerialPorts[0].hasVendorIdentifier() && availableSerialPorts[0].hasProductIdentifier()){
            this->arduino_uno_vendor_id = availableSerialPorts[0].vendorIdentifier();
            this->arduino_uno_product_id = availableSerialPorts[0].productIdentifier();
            this->arduino_port_name = availableSerialPorts[0].portName();
            qDebug() << this->arduino_uno_vendor_id <<"vendor  id \n" << this->arduino_uno_product_id << "product id \n " <<availableSerialPorts.length() <<"Length arduino data" ;
            qDebug() << "\n port name" << this->arduino_port_name;
            return true;
            }
        }

    } catch (std::exception &e) {
        qFatal("Error %s",
        e.what());
        return false;
    }
}
*/
/*bool Arduino::getConnected(){
    try{
        this->arduino_is_available = this->checkArduino();
        qDebug() << "avaialible " << arduino_is_available;
        if(this->arduino_is_available){
            this->arduino = new QSerialPort;
            this->arduino->setPortName(arduino_port_name);
            this->arduino->open(QSerialPort::ReadWrite);
            this->arduino->setBaudRate(QSerialPort::Baud9600);
            this->arduino->setDataBits(QSerialPort::Data8);
            this->arduino->setParity(QSerialPort::NoParity);
            this->arduino->setStopBits(QSerialPort::OneStop);
            this->arduino->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << this->arduino->isOpen() << "\n check isOpen";
            return this->arduino->isOpen();

        }else {
            this->arduino->close();
            return false;
        }
    }catch(std::exception &e){
        qFatal("Error %s ",
              e.what());
        return false;
    }

}*/
bool Arduino::closeArduino(){
    try {
        if(this->arduino->isOpen()){
            this->arduino->close();
            return true;
        }
        return false;
    }catch (std::exception &e) {
        qFatal("Error %s",e.what());
        return false;
    }
}
bool Arduino::checkAccessRFID(QString _uid){

    try{
        if(this->arduino->isWritable()){ //ready bech tabda ta9ra

            QByteArray data = this->arduino->readAll();//bech ya9ra tous les info ili f wost l carte
            QString DataString = data.toLower();// data mel carta //lower :data ili bech ya9raha mel carta bech ikoun fiha des caractere majus lower isa9er l alphabet l kol irodha minus
            DataString = DataString.section(": ",-1);//bech iselectioni mel id :
            qDebug() << "data bytes " <<DataString;
            bool result;
            result = (DataString == _uid.toLower())?  true:  false; // bech yab9a ijarib yo5roj wa9t t3adilou carte ma tete9rach
            return result;
        }
        return false;
    }catch(std::exception &e){
        qFatal("Error %s",
               e.what());
       return false;
    }
 }
