#!/usr/bin/env python

from pexpect import pxssh

a = pxssh.pxssh()
if not a.login ('server', 'username', 'password'):
    print "SSH session failed on login."
    print str(a)
else:
    print "SSH session login successful" 
    a.sendline ('roslaunch turtlebot_teleop keyboard_teleop.launch')
    a.interact()        # Hands control to the user
