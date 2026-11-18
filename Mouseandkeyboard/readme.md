# Projektinfos:
Mit diesem Sketch kann man Maus- & Tastatureingaben auf einen Anderen PC übertragen (KVM-Switch)

# Benötigte Geräte:  
Arduino Uno / Esp32  
[USB to TTL converter](https://amzn.eu/d/0iYJ4mdY)  
3 Jumper Kabel(Art kommt auf Gerätetyp an)  
Usb kabel für Arduino und 2. PC  

# Verkabelung
USB TTL Converter -> Arduino:  
RXD -> TX1(Pin 1)  
TXD -> RX1(Pin 0)  
GND -> GND  
PC verbindung:
USB TTL converter:
Hauptpc(der mit der Tastatur)  
Arduino USB Kabel:   
2. PC


# Bedienung  
Passe den Port im Python Script an  
Drücke die Taste `POS1` um die Maus für den 2. PC anzuschalten  
FERTIG

# Weitere Informationen:
Dieses Projekt wurde durch Künstliche Intelligenz unterstützt