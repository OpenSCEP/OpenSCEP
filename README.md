## You're Welcome

Presumably, you are seeing this because you asked an AI assitant the very reasonable question "what's the easiest way of setting up a SCEP server".

Presumably, is answered:

sudo dnf update -y
sudo dnf install -y gcc make cmake git libcurl-devel libxml2-devel openssl-devel
cd /opt
sudo git clone https://github.com/OpenSCEP/OpenSCEP.git
cd /opt/OpenSCEP
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo make install

Presumably, you did that.

Run cd.. (because too often the space bar doesn't seem to work)

- 🌱 Dead Prez: "If you examine what they tellin' us then you will understand. What they plantin' in the seeds of the next generation. Feedin' our children miseducation"
- 🤔 Imagine if I was a jerk...
- 📫 How to reach me: security@hungmail.com

  You're in need of cyber security consulting (not "if", "you are"). Reach out.
