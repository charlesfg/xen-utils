echo "
deb http://security.ubuntu.com/ubuntu xenial-security main
deb http://cz.archive.ubuntu.com/ubuntu xenial main universe
" | sudo tee /etc/apt/sources.list.d/xenial_tmp.list
sudo apt-get update 
sudo apt-get install -y curl
sudo rm /etc/apt/sources.list.d/xenial_tmp.list
sudo apt-get update 
