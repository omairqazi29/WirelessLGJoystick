import socket
import keyboard

#CHNAGE THE FOLLOWING
UDP_IP = "192.168.31.236"

UDP_PORT = 8085

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

#RECEIVING UDP MESSAGES
while True:
    data, addr = sock.recvfrom(2)
    msg=data.decode().strip()
    print(msg)
    if msg=="RT":
        keyboard.press('right')
    elif msg=="UR":
        keyboard.press('up+right')
    elif msg=="UP":
        keyboard.press('up')
    elif msg=="UL":
        keyboard.press('up+left')
    elif msg=="LT":
        keyboard.press('left')
    elif msg=="DR":
        keyboard.press('down+right')
    elif msg=="DW":
        keyboard.press('down')
    elif msg=="DL":
        keyboard.press('down+left')
    elif msg=="ZI":
        keyboard.press('page up')
    elif msg=="ZO":
        keyboard.press('page down')
    elif msg=="ST":
        keyboard.press_and_release('spacebar')
