# DW.CLOUD firmware support.
This repository is official DW.CLOUD firmware supported by Deaware System. We will update new feature and bug fixed. If there are any bug, please create new issue to report us.

## How to install DW.CLOUD firmware to Arduino IDE (version >= 1.6.4)

#### 1) Add Board Manager URLs
* In **Arduino IDE (version >= 1.6.4)** goto **File > Preference**
* Insert **"Addition Board Manager URLs"** with the link following below.

```
http://github.com/deaware/dwcloud_firmware_support/raw/master/package_deaware_index.json
```

![](http://github.com/deaware/dwcloud_firmware_support/raw/master/tutorial_images/insert_board_man_url.png)

* Open **"Boards Manager"** by goto **Tools > Board > Boards Manager...**
![](http://github.com/deaware/dwcloud_firmware_support/raw/master/tutorial_images/select_boards_manager.png)

* Select **DW.CLOUD** and press **"Install"**
![](http://github.com/deaware/dwcloud_firmware_support/raw/master/tutorial_images/instsall_dwcloud.png)

* Check the DW.CLOUD is ready to used by goto **Tools > Board** and you will see **"DW.CLOUD"** like a picture following below.
![](http://github.com/deaware/dwcloud_firmware_support/raw/master/tutorial_images/dwcloud_shown.png)
