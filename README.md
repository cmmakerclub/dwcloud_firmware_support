# DW.CLOUD firmware support.
This repository is official DW.CLOUD firmware supported by Deaware System. We will update new feature and bug fixed. If there are any bug, please create new issue to report us.

## How to install DW.CLOUD firmware to Arduino IDE (version >= 1.6.4)

#### 1) Add Board Manager URLs
* In **Arduino IDE (version >= 1.6.4)** goto **File > Preference**
* Insert **"Addition Board Manager URLs"** with the link following below.

```
http://github.com/deaware/dwcloud_firmware_support/raw/master/package_deaware_index.json
```

![](http://128.199.203.210/dwcloud_support/images/insert_board_man_url.png)

#### 2) Install **DW.CLOUD**
* Open **"Boards Manager"** by goto **Tools > Board > Boards Manager...**

![](http://128.199.203.210/dwcloud_support/images/select_boards_manager.png)

* Select **DW.CLOUD** and press **"Install"**

![](http://128.199.203.210/dwcloud_support/images/instsall_dwcloud.png)

* Check the DW.CLOUD is ready to used by goto **Tools > Board** and you will see **"DW.CLOUD"** like a picture following below.

![](http://128.199.203.210/dwcloud_support/images/dwcloud_shown.png)

## How to upload firmware to ESP8266.
###Windows User
#### 1) Download tools (ESP8266Flasher) from this [link](http://128.199.203.210/dwcloud_support/downloads/ESP8266Flasher.zip).

#### 2) Extract zip and open up ESP8266Flasher.
![](http://128.199.203.210/dwcloud_support/images/open_esp8266.png)

#### 3) Select COM Port that connected to DW.CLOUD.
![](http://128.199.203.210/dwcloud_support/images/select_port.png)

#### 4) Select binairy files of your firmware and set the address for each binary files.
![](http://128.199.203.210/dwcloud_support/images/select_bin.png)

#### 5) Select the BAUDRATE for uploading to 115200.
![](http://128.199.203.210/dwcloud_support/images/select_baud.png)

#### 6) Hold the "Flash Switch" in follow in picthre below and press flash in ESP8266Flasher.
![](http://128.199.203.210/dwcloud_support/images/hold_button.png)
![](http://128.199.203.210/dwcloud_support/images/click_flash.png)

#### 7) After flashing is started (by see the progress bar counting), your can release the switch on DW.CLOUD.

### For Mac & Linux User.
#### 1) Download tools (esptool) from this [link](esptool-master.zip).

#### 2) Extract the "esptool-master.zip".

#### 3) Open "Terminal" for installing and flashing.

#### 4) Move current directory to esptool-master that has been extracted from esptool-master.zip.

#### 5) Install "esptool" by using the command following below.
```SHELL
sudo python setup.py install
```

#### 6) Move current directory to the directory that contain the binary files of your firmware.

#### 7) Upload your firmware by holding the "Flash Switch" and write down the command following below.
![](http://128.199.203.210/dwcloud_support/images/hold_button.png)

and

```SHELL
esptool.py --port <port> --baud 115200 write_flash <address> <binary file>
```
* **port** is a path to your tty port. (eg. **/dev/ttyUSB0**)
* **address** is address the target that you want to write the binary file to. (eg. **0x01000**)
* **binary file** is the name of your binary file. (eg. **boot_v1.1.bin**)
