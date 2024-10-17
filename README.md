# heartbreaker
Exploration in impersonnate with osmocom

##############
on host (not on docker !) Launch 1st
##############
````bash
sudo docker run -it --ip 172.17.0.2 --privileged --user root --cap-add ALL  -v /dev/bus/usb:/dev/bus/usb ideolab/evil-ms-copy:updated
````
##############
Launch 2nd
##############
````bash
sudo docker run -it --ip 172.17.0.3 --privileged --user root --cap-add ALL  -v /dev/bus/usb:/dev/bus/usb ideolab/evil-bts-copy:updated
````

In this order cause need ip 172.17.0.2 for ms and 172.17.0.3 for bts (socket are made to work with theses addresses)

in bts:
````bash
tmux
cd /
service pcscd start
./evil-bts.sh
````
then in ms:
````bash
tmux
cd /
bash trx.sh
ctrl-b c 
./evil-ms.sh
````
